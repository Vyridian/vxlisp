#include <map>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/collection.hpp"
#include "../../vx/type.hpp"
#include "../../vx/data/textblock.hpp"
#include "csv.hpp"

namespace vx_data_csv {


  // (type csv)
  // class Class_csv {
    Abstract_csv::~Abstract_csv() {}

    Class_csv::Class_csv() : Abstract_csv::Abstract_csv() {
      vx_core::refcount += 1;
    }

    Class_csv::~Class_csv() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_headers,
        this->vx_p_rows
      });
    }

    // headers()
    vx_core::Type_stringlist Class_csv::headers() const {
      vx_core::Type_stringlist output = this->vx_p_headers;
      if (!output) {
        output = vx_core::e_stringlist;
      }
      return output;
    }

    // rows()
    vx_data_csv::Type_csvrows Class_csv::rows() const {
      vx_data_csv::Type_csvrows output = this->vx_p_rows;
      if (!output) {
        output = vx_data_csv::e_csvrows;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_csv::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":headers") {
        output = this->headers();
      } else if (skey == ":rows") {
        output = this->rows();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_csv::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":headers"] = this->headers();
      output[":rows"] = this->rows();
      return output;
    }

    vx_core::Type_any Class_csv::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_csv::e_csv, vals);
    }

    vx_core::Type_any Class_csv::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_csv::Type_csv output = vx_data_csv::e_csv;
      bool ischanged = false;
      if (copyval->vx_p_constname != "") {
        ischanged = true;
      }
      vx_data_csv::Type_csv val = vx_core::vx_any_from_any(vx_data_csv::t_csv, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_stringlist vx_p_headers = val->headers();
      vx_data_csv::Type_csvrows vx_p_rows = val->rows();
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
          } else if (testkey == ":headers") {
            key = testkey;
          } else if (testkey == ":rows") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new csv) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":headers") {
            if (vx_p_headers == valsub) {
            } else if (valsubtype == vx_core::t_stringlist) {
              ischanged = true;
              vx_p_headers = vx_core::vx_any_from_any(vx_core::t_stringlist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new csv :headers " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":rows") {
            if (vx_p_rows == valsub) {
            } else if (valsubtype == vx_data_csv::t_csvrows) {
              ischanged = true;
              vx_p_rows = vx_core::vx_any_from_any(vx_data_csv::t_csvrows, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new csv :rows " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new csv) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_csv::Class_csv();
        if (output->vx_p_headers != vx_p_headers) {
          if (output->vx_p_headers) {
            vx_core::vx_release_one(output->vx_p_headers);
          }
          output->vx_p_headers = vx_p_headers;
          vx_core::vx_reserve(vx_p_headers);
        }
        if (output->vx_p_rows != vx_p_rows) {
          if (output->vx_p_rows) {
            vx_core::vx_release_one(output->vx_p_rows);
          }
          output->vx_p_rows = vx_p_rows;
          vx_core::vx_reserve(vx_p_rows);
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

    vx_core::Type_msgblock Class_csv::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_csv::Class_csv::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_csv::vx_empty() const {return vx_data_csv::e_csv;}
    vx_core::Type_any Class_csv::vx_type() const {return vx_data_csv::t_csv;}

    vx_core::Type_typedef Class_csv::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/csv", // pkgname
        "csv", // name
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
            "headers", // name
            vx_core::t_stringlist // type
          ),
          vx_core::vx_new_arg(
            "rows", // name
            vx_data_csv::t_csvrows // type
          )
        }) // properties
      );
      return output;
    }

  //}

  // (type csvrows)
  // class Class_csvrows {
    Abstract_csvrows::~Abstract_csvrows() {}

    Class_csvrows::Class_csvrows() : Abstract_csvrows::Abstract_csvrows() {
      vx_core::refcount += 1;
    }

    Class_csvrows::~Class_csvrows() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_csvrows::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_core::Type_stringlist Class_csvrows::vx_get_stringlist(vx_core::Type_int index) const {
      vx_core::Type_stringlist output = vx_core::e_stringlist;
      long iindex = index->vx_int();
      std::vector<vx_core::Type_stringlist> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_core::Type_stringlist> Class_csvrows::vx_liststringlist() const {return vx_p_list;}

    vx_core::Type_any vx_data_csv::Class_csvrows::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_stringlist(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_csvrows::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_data_csv::Type_csvrows output = vx_data_csv::e_csvrows;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_core::Type_stringlist> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_core::t_stringlist) {
          vx_core::Type_stringlist castval = vx_core::vx_any_from_any(vx_core::t_stringlist, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_core::t_stringlist)) {
          vx_core::Type_stringlist castval = vx_core::vx_any_from_any(vx_core::t_stringlist, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(csvrows) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_csv::Class_csvrows();
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

    vx_core::Type_any Class_csvrows::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_csv::e_csvrows, vals);
    }

    vx_core::Type_any Class_csvrows::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_csv::Type_csvrows output = vx_data_csv::e_csvrows;
      bool ischanged = false;
      if (copyval->vx_p_constname != "") {
        ischanged = true;
      }
      vx_data_csv::Type_csvrows val = vx_core::vx_any_from_any(vx_data_csv::t_csvrows, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_core::Type_stringlist> listval = val->vx_liststringlist();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_stringlist) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_stringlist, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_core::t_stringlist)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_stringlist, valsub));
        } else if (valsubtype == vx_data_csv::t_csvrows) {
          ischanged = true;
          vx_data_csv::Type_csvrows multi = vx_core::vx_any_from_any(vx_data_csv::t_csvrows, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_liststringlist());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new csvrows) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_csv::Class_csvrows();
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

    vx_core::Type_msgblock Class_csvrows::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_csv::Class_csvrows::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_csvrows::vx_empty() const {return vx_data_csv::e_csvrows;}
    vx_core::Type_any Class_csvrows::vx_type() const {return vx_data_csv::t_csvrows;}

    vx_core::Type_typedef Class_csvrows::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/csv", // pkgname
        "csvrows", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_core::t_stringlist}), // allowtypes
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

  // (const delimcsv)
  // class Class_delimcsv {

    // vx_constdef()
    vx_core::Type_constdef vx_data_csv::Class_delimcsv::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/csv", // pkgname
        "delimcsv", // name
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
            "pos", // name
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

    // vx_const_new()
    void vx_data_csv::Class_delimcsv::vx_const_new(vx_data_csv::Const_delimcsv output) {
      output->vx_p_constname = "vx/data/csv/delimcsv";
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimcsv"),
          vx_core::vx_new_string(":delimlist"),
          vx_core::f_new(
            vx_data_textblock::t_delimlist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_data_textblock::c_delimline,
              vx_data_textblock::c_delimquote,
              vx_data_textblock::c_delimcomma
            })
          )
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

  // (func csv<-textblock)
  vx_data_csv::Type_csv f_csv_from_textblock(vx_data_textblock::Type_textblock textblock) {
    vx_data_csv::Type_csv output = vx_data_csv::e_csv;
    vx_core::vx_reserve(textblock);
    output = vx_core::f_let(
      vx_data_csv::t_csv,
      vx_core::t_any_from_func->vx_fn_new({textblock}, [textblock]() {
        vx_data_csv::Type_csvrows allrows = vx_data_csv::f_csvrows_from_textblock(textblock);
        vx_core::vx_ref_plus(allrows);
        vx_core::Type_stringlist headers = vx_core::f_any_from_list(vx_core::t_stringlist, allrows, vx_core::vx_new_int(1));
        vx_core::vx_ref_plus(headers);
        vx_data_csv::Type_csvrows rows = vx_collection::f_list_from_list_end(vx_data_csv::t_csvrows, allrows, vx_core::vx_new_int(2));
        vx_core::vx_ref_plus(rows);
        vx_data_csv::Type_csv output_1 = vx_core::f_new(
          vx_data_csv::t_csv,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":headers"),
            headers,
            vx_core::vx_new_string(":rows"),
            rows
          })
        );
        vx_core::vx_release_one_except({allrows, headers, rows}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(textblock, output);
    return output;
  }

  // (func csv<-textblock)
  // class Class_csv_from_textblock {
    Abstract_csv_from_textblock::~Abstract_csv_from_textblock() {}

    Class_csv_from_textblock::Class_csv_from_textblock() : Abstract_csv_from_textblock::Abstract_csv_from_textblock() {
      vx_core::refcount += 1;
    }

    Class_csv_from_textblock::~Class_csv_from_textblock() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_csv_from_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_csv::Func_csv_from_textblock output = vx_data_csv::e_csv_from_textblock;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_csv_from_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_csv::Func_csv_from_textblock output = vx_data_csv::e_csv_from_textblock;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_csv_from_textblock::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/csv", // pkgname
        "csv<-textblock", // name
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

    vx_core::Type_funcdef Class_csv_from_textblock::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/csv", // pkgname
        "csv<-textblock", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_csv_from_textblock::vx_empty() const {return vx_data_csv::e_csv_from_textblock;}
    vx_core::Type_any Class_csv_from_textblock::vx_type() const {return vx_data_csv::t_csv_from_textblock;}
    vx_core::Type_msgblock Class_csv_from_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_csv_from_textblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_csv_from_textblock::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_csv_from_textblock::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock inputval = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, val);
      output = vx_data_csv::f_csv_from_textblock(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_csv_from_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblock = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_csv::f_csv_from_textblock(textblock);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func csvrows<-textblock)
  vx_data_csv::Type_csvrows f_csvrows_from_textblock(vx_data_textblock::Type_textblock textblock) {
    vx_data_csv::Type_csvrows output = vx_data_csv::e_csvrows;
    vx_core::vx_reserve(textblock);
    output = vx_core::f_let(
      vx_data_csv::t_csvrows,
      vx_core::t_any_from_func->vx_fn_new({textblock}, [textblock]() {
        vx_data_textblock::Type_textblock parsedtb = vx_data_textblock::f_textblock_from_textblock_delim(
          textblock,
          vx_data_csv::c_delimcsv
        );
        vx_core::vx_ref_plus(parsedtb);
        vx_data_textblock::Type_textblocklist children = vx_data_textblock::f_children_from_textblock(parsedtb);
        vx_core::vx_ref_plus(children);
        vx_core::Type_stringlist strings = vx_data_textblock::f_stringlist_from_textblocklist(children);
        vx_core::vx_ref_plus(strings);
        vx_data_csv::Type_csvrows output_1 = vx_core::f_new(
          vx_data_csv::t_csvrows,
          vx_core::vx_new(vx_core::t_anylist, {
            strings
          })
        );
        vx_core::vx_release_one_except({parsedtb, children, strings}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(textblock, output);
    return output;
  }

  // (func csvrows<-textblock)
  // class Class_csvrows_from_textblock {
    Abstract_csvrows_from_textblock::~Abstract_csvrows_from_textblock() {}

    Class_csvrows_from_textblock::Class_csvrows_from_textblock() : Abstract_csvrows_from_textblock::Abstract_csvrows_from_textblock() {
      vx_core::refcount += 1;
    }

    Class_csvrows_from_textblock::~Class_csvrows_from_textblock() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_csvrows_from_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_csv::Func_csvrows_from_textblock output = vx_data_csv::e_csvrows_from_textblock;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_csvrows_from_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_csv::Func_csvrows_from_textblock output = vx_data_csv::e_csvrows_from_textblock;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_csvrows_from_textblock::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/csv", // pkgname
        "csvrows<-textblock", // name
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

    vx_core::Type_funcdef Class_csvrows_from_textblock::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/csv", // pkgname
        "csvrows<-textblock", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_csvrows_from_textblock::vx_empty() const {return vx_data_csv::e_csvrows_from_textblock;}
    vx_core::Type_any Class_csvrows_from_textblock::vx_type() const {return vx_data_csv::t_csvrows_from_textblock;}
    vx_core::Type_msgblock Class_csvrows_from_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_csvrows_from_textblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_csvrows_from_textblock::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_csvrows_from_textblock::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock inputval = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, val);
      output = vx_data_csv::f_csvrows_from_textblock(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_csvrows_from_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblock = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_csv::f_csvrows_from_textblock(textblock);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock-csv<-string)
  vx_data_textblock::Type_textblock f_textblock_csv_from_string(vx_core::Type_string text) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve(text);
    output = vx_data_textblock::f_textblock_parse_from_string_delim(
      text,
      vx_data_csv::c_delimcsv
    );
    vx_core::vx_release_one_except(text, output);
    return output;
  }

  // (func textblock-csv<-string)
  // class Class_textblock_csv_from_string {
    Abstract_textblock_csv_from_string::~Abstract_textblock_csv_from_string() {}

    Class_textblock_csv_from_string::Class_textblock_csv_from_string() : Abstract_textblock_csv_from_string::Abstract_textblock_csv_from_string() {
      vx_core::refcount += 1;
    }

    Class_textblock_csv_from_string::~Class_textblock_csv_from_string() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_csv_from_string::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_csv::Func_textblock_csv_from_string output = vx_data_csv::e_textblock_csv_from_string;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_csv_from_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_csv::Func_textblock_csv_from_string output = vx_data_csv::e_textblock_csv_from_string;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_csv_from_string::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/csv", // pkgname
        "textblock-csv<-string", // name
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

    vx_core::Type_funcdef Class_textblock_csv_from_string::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/csv", // pkgname
        "textblock-csv<-string", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_csv_from_string::vx_empty() const {return vx_data_csv::e_textblock_csv_from_string;}
    vx_core::Type_any Class_textblock_csv_from_string::vx_type() const {return vx_data_csv::t_textblock_csv_from_string;}
    vx_core::Type_msgblock Class_textblock_csv_from_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_csv_from_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_textblock_csv_from_string::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_textblock_csv_from_string::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_data_csv::f_textblock_csv_from_string(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_textblock_csv_from_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_csv::f_textblock_csv_from_string(text);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_data_csv::Type_csv e_csv = NULL;
  vx_data_csv::Type_csv t_csv = NULL;
  vx_data_csv::Type_csvrows e_csvrows = NULL;
  vx_data_csv::Type_csvrows t_csvrows = NULL;
  vx_data_csv::Const_delimcsv c_delimcsv = NULL;
  vx_data_csv::Func_csv_from_textblock e_csv_from_textblock = NULL;
  vx_data_csv::Func_csv_from_textblock t_csv_from_textblock = NULL;
  vx_data_csv::Func_csvrows_from_textblock e_csvrows_from_textblock = NULL;
  vx_data_csv::Func_csvrows_from_textblock t_csvrows_from_textblock = NULL;
  vx_data_csv::Func_textblock_csv_from_string e_textblock_csv_from_string = NULL;
  vx_data_csv::Func_textblock_csv_from_string t_textblock_csv_from_string = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_data_csv::c_delimcsv = new vx_data_csv::Class_delimcsv();
      vx_data_csv::e_csv = new Class_csv();
      vx_core::vx_reserve_empty(vx_data_csv::e_csv);
      vx_data_csv::t_csv = new Class_csv();
      vx_core::vx_reserve_type(vx_data_csv::t_csv);
      vx_data_csv::e_csvrows = new Class_csvrows();
      vx_core::vx_reserve_empty(vx_data_csv::e_csvrows);
      vx_data_csv::t_csvrows = new Class_csvrows();
      vx_core::vx_reserve_type(vx_data_csv::t_csvrows);
      vx_data_csv::e_csv_from_textblock = new vx_data_csv::Class_csv_from_textblock();
      vx_core::vx_reserve_empty(vx_data_csv::e_csv_from_textblock);
      vx_data_csv::t_csv_from_textblock = new vx_data_csv::Class_csv_from_textblock();
      vx_core::vx_reserve_type(vx_data_csv::t_csv_from_textblock);
      vx_data_csv::e_csvrows_from_textblock = new vx_data_csv::Class_csvrows_from_textblock();
      vx_core::vx_reserve_empty(vx_data_csv::e_csvrows_from_textblock);
      vx_data_csv::t_csvrows_from_textblock = new vx_data_csv::Class_csvrows_from_textblock();
      vx_core::vx_reserve_type(vx_data_csv::t_csvrows_from_textblock);
      vx_data_csv::e_textblock_csv_from_string = new vx_data_csv::Class_textblock_csv_from_string();
      vx_core::vx_reserve_empty(vx_data_csv::e_textblock_csv_from_string);
      vx_data_csv::t_textblock_csv_from_string = new vx_data_csv::Class_textblock_csv_from_string();
      vx_core::vx_reserve_type(vx_data_csv::t_textblock_csv_from_string);
      vx_data_csv::Class_delimcsv::vx_const_new(vx_data_csv::c_delimcsv);
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
