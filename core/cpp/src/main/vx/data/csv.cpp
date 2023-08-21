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
        output = vx_core::e_stringlist();
      }
      return output;
    }

    // rows()
    vx_data_csv::Type_csvrows Class_csv::rows() const {
      vx_data_csv::Type_csvrows output = this->vx_p_rows;
      if (!output) {
        output = vx_data_csv::e_csvrows();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_csv::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
      return this->vx_copy(vx_data_csv::e_csv(), vals);
    }

    vx_core::Type_any Class_csv::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_csv::Type_csv output = vx_data_csv::e_csv();
      vx_data_csv::Type_csv val = vx_core::vx_any_from_any(vx_data_csv::t_csv(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_stringlist vx_p_headers = val->headers();
      vx_data_csv::Type_csvrows vx_p_rows = val->rows();
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
          } else if (testkey == ":headers") {
            key = testkey;
          } else if (testkey == ":rows") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new csv) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":headers") {
            if (valsubtype == vx_core::t_stringlist()) {
              vx_p_headers = vx_core::vx_any_from_any(vx_core::t_stringlist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new csv :headers " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":rows") {
            if (valsubtype == vx_data_csv::t_csvrows()) {
              vx_p_rows = vx_core::vx_any_from_any(vx_data_csv::t_csvrows(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new csv :rows " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new csv) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
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
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_csv::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_csv::Class_csv::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_csv::vx_empty() const {return vx_data_csv::e_csv();}
    vx_core::Type_any Class_csv::vx_type() const {return vx_data_csv::t_csv();}

    vx_core::Type_typedef Class_csv::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/csv", // pkgname
        "csv", // name
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
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_core::Type_stringlist Class_csvrows::vx_get_stringlist(vx_core::Type_int index) const {
      vx_core::Type_stringlist output = vx_core::e_stringlist();
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
      vx_data_csv::Type_csvrows output = vx_data_csv::e_csvrows();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_core::Type_stringlist> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_core::t_stringlist()) {
          vx_core::Type_stringlist castval = vx_core::vx_any_from_any(vx_core::t_stringlist(), valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(csvrows) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_data_csv::Class_csvrows();
      output->vx_p_list = list;
      for (vx_core::Type_any valadd : list) {
        vx_core::vx_reserve(valadd);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(listval, output);
      return output;
    }

    vx_core::Type_any Class_csvrows::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_csv::e_csvrows(), vals);
    }

    vx_core::Type_any Class_csvrows::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_csv::Type_csvrows output = vx_data_csv::e_csvrows();
      vx_data_csv::Type_csvrows val = vx_core::vx_any_from_any(vx_data_csv::t_csvrows(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_core::Type_stringlist> listval = val->vx_liststringlist();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_stringlist()) {
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_stringlist(), valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_core::t_stringlist())) {
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_stringlist(), valsub));
        } else if (valsubtype == vx_data_csv::t_csvrows()) {
          vx_data_csv::Type_csvrows multi = vx_core::vx_any_from_any(vx_data_csv::t_csvrows(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_liststringlist());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new csvrows) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_data_csv::Class_csvrows();
      output->vx_p_list = listval;
      for (vx_core::Type_any valadd : listval) {
        vx_core::vx_reserve(valadd);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_csvrows::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_csv::Class_csvrows::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_csvrows::vx_empty() const {return vx_data_csv::e_csvrows();}
    vx_core::Type_any Class_csvrows::vx_type() const {return vx_data_csv::t_csvrows();}

    vx_core::Type_typedef Class_csvrows::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/csv", // pkgname
        "csvrows", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_typelist_from_listany({vx_core::t_stringlist()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
      return output;
    }

  //}

  // (const delims)
  // class Class_delims {

    // vx_const_new()
    vx_data_csv::Const_delims vx_data_csv::Class_delims::vx_const_new() {
      vx_data_csv::Const_delims output = new vx_data_csv::Class_delims();
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delimset val = vx_core::f_new(
        vx_data_textblock::t_delimset(),
        vx_core::vx_new(vx_core::t_anylist(), {
          vx_core::vx_new_string(":split"),
          vx_core::f_new(
            vx_core::t_stringlist(),
            vx_core::vx_new(vx_core::t_anylist(), {
              vx_core::vx_new_string("\n")
            })
          ),
          vx_core::vx_new_string(":subset"),
          vx_core::f_new(
            vx_data_textblock::t_delimset(),
            vx_core::vx_new(vx_core::t_anylist(), {
              vx_core::vx_new_string(":split"),
              vx_core::f_new(
                vx_core::t_stringlist(),
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_string(",")
                })
              ),
              vx_core::vx_new_string(":subset"),
              vx_core::f_new(
                vx_data_textblock::t_delimset(),
                vx_core::vx_new(vx_core::t_anylist(), {
                  vx_core::vx_new_string(":start"),
                  vx_core::f_new(
                    vx_core::t_stringlist(),
                    vx_core::vx_new(vx_core::t_anylist(), {
                      vx_core::vx_new_string("\"")
                    })
                  ),
                  vx_core::vx_new_string(":end"),
                  vx_core::f_new(
                    vx_core::t_stringlist(),
                    vx_core::vx_new(vx_core::t_anylist(), {
                      vx_core::vx_new_string("\"")
                    })
                  )
                })
              )
            })
          )
        })
      );
      output->vx_p_start = val->start();
      vx_core::vx_reserve(output->vx_p_start);
      output->vx_p_end = val->end();
      vx_core::vx_reserve(output->vx_p_end);
      output->vx_p_split = val->split();
      vx_core::vx_reserve(output->vx_p_split);
      output->vx_p_subset = val->subset();
      vx_core::vx_reserve(output->vx_p_subset);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
      return output;
    }

    // vx_constdef()
    vx_core::Type_constdef vx_data_csv::Class_delims::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/csv", // pkgname
        "delims", // name
        vx_core::Class_typedef::vx_typedef_new(
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
        )
      );
    }


  //}

  // (func csv<-textblock)
  vx_data_csv::Type_csv f_csv_from_textblock(vx_data_textblock::Type_textblock textblock) {
    vx_data_csv::Type_csv output = vx_data_csv::e_csv();
    vx_core::vx_reserve(textblock);
    output = vx_core::f_let(
      vx_data_csv::t_csv(),
      vx_core::t_any_from_func()->vx_fn_new({textblock}, [textblock]() {
        vx_data_csv::Type_csvrows allrows = vx_data_csv::f_csvrows_from_textblock(textblock);
        vx_core::vx_ref_plus(allrows);
        vx_core::Type_stringlist headers = vx_core::f_any_from_list(vx_core::t_stringlist(), allrows, vx_core::vx_new_int(0));
        vx_core::vx_ref_plus(headers);
        vx_data_csv::Type_csvrows rows = vx_collection::f_list_from_list_end(vx_data_csv::t_csvrows(), allrows, vx_core::vx_new_int(1));
        vx_core::vx_ref_plus(rows);
        vx_data_csv::Type_csv output_1 = vx_core::f_new(
          vx_data_csv::t_csv(),
          vx_core::vx_new(vx_core::t_anylist(), {
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
      vx_data_csv::Func_csv_from_textblock output = vx_data_csv::e_csv_from_textblock();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_csv_from_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_csv::Func_csv_from_textblock output = vx_data_csv::e_csv_from_textblock();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_csv_from_textblock::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/csv", // pkgname
        "csv<-textblock", // name
        ":func", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
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

    vx_core::Type_any Class_csv_from_textblock::vx_empty() const {return vx_data_csv::e_csv_from_textblock();}
    vx_core::Type_any Class_csv_from_textblock::vx_type() const {return vx_data_csv::t_csv_from_textblock();}
    vx_core::Type_msgblock Class_csv_from_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_csv_from_textblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_csv_from_textblock::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_csv_from_textblock::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_textblock::Type_textblock inputval = vx_core::vx_any_from_any(vx_data_textblock::t_textblock(), val);
      output = vx_data_csv::f_csv_from_textblock(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_csv_from_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_textblock::Type_textblock textblock = vx_core::vx_any_from_any(vx_data_textblock::t_textblock(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_csv::f_csv_from_textblock(textblock);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func csvrows<-textblock)
  vx_data_csv::Type_csvrows f_csvrows_from_textblock(vx_data_textblock::Type_textblock textblock) {
    vx_data_csv::Type_csvrows output = vx_data_csv::e_csvrows();
    vx_core::vx_reserve(textblock);
    output = vx_core::f_let(
      vx_data_csv::t_csvrows(),
      vx_core::t_any_from_func()->vx_fn_new({textblock}, [textblock]() {
        vx_data_textblock::Type_textblock parsedtb = vx_data_textblock::f_parse(
          textblock,
          vx_data_csv::c_delims()
        );
        vx_core::vx_ref_plus(parsedtb);
        vx_data_textblock::Type_textblocklist childtbs = vx_data_textblock::f_textblocks_from_textblock(parsedtb);
        vx_core::vx_ref_plus(childtbs);
        vx_core::Type_stringlist strings = vx_data_textblock::f_stringlist_from_textblocklist(childtbs);
        vx_core::vx_ref_plus(strings);
        vx_data_csv::Type_csvrows output_1 = vx_core::f_new(
          vx_data_csv::t_csvrows(),
          vx_core::vx_new(vx_core::t_anylist(), {
            strings
          })
        );
        vx_core::vx_release_one_except({parsedtb, childtbs, strings}, output_1);
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
      vx_data_csv::Func_csvrows_from_textblock output = vx_data_csv::e_csvrows_from_textblock();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_csvrows_from_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_csv::Func_csvrows_from_textblock output = vx_data_csv::e_csvrows_from_textblock();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_csvrows_from_textblock::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/csv", // pkgname
        "csvrows<-textblock", // name
        ":func", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
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

    vx_core::Type_any Class_csvrows_from_textblock::vx_empty() const {return vx_data_csv::e_csvrows_from_textblock();}
    vx_core::Type_any Class_csvrows_from_textblock::vx_type() const {return vx_data_csv::t_csvrows_from_textblock();}
    vx_core::Type_msgblock Class_csvrows_from_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_csvrows_from_textblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_csvrows_from_textblock::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_csvrows_from_textblock::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_textblock::Type_textblock inputval = vx_core::vx_any_from_any(vx_data_textblock::t_textblock(), val);
      output = vx_data_csv::f_csvrows_from_textblock(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_csvrows_from_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_data_textblock::Type_textblock textblock = vx_core::vx_any_from_any(vx_data_textblock::t_textblock(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_csv::f_csvrows_from_textblock(textblock);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_data_csv::vx_Class_package* vx_package = new vx_data_csv::vx_Class_package();

  vx_data_csv::Type_csv e_csv() {
    vx_data_csv::Type_csv output = vx_data_csv::vx_package->e_csv;
    if (!output) {
      output = new Class_csv();
      vx_core::vx_reserve_empty(output);
      vx_data_csv::vx_package->e_csv = output;
    }
    return output;
  }
  vx_data_csv::Type_csv t_csv() {
    vx_data_csv::Type_csv output = vx_data_csv::vx_package->t_csv;
    if (!output) {
      output = new Class_csv();
      vx_core::vx_reserve_type(output);
      vx_data_csv::vx_package->t_csv = output;
    }
    return output;
  }

  vx_data_csv::Type_csvrows e_csvrows() {
    vx_data_csv::Type_csvrows output = vx_data_csv::vx_package->e_csvrows;
    if (!output) {
      output = new Class_csvrows();
      vx_core::vx_reserve_empty(output);
      vx_data_csv::vx_package->e_csvrows = output;
    }
    return output;
  }
  vx_data_csv::Type_csvrows t_csvrows() {
    vx_data_csv::Type_csvrows output = vx_data_csv::vx_package->t_csvrows;
    if (!output) {
      output = new Class_csvrows();
      vx_core::vx_reserve_type(output);
      vx_data_csv::vx_package->t_csvrows = output;
    }
    return output;
  }

  // (const delims)
  vx_data_csv::Const_delims c_delims() {
    vx_data_csv::Const_delims output = vx_data_csv::vx_package->c_delims;
    if (output == NULL) {
      output = vx_data_csv::Class_delims::vx_const_new();
      vx_data_csv::vx_package->c_delims = output;
    }
    return output;
  }

  // (func csv<-textblock)
  vx_data_csv::Func_csv_from_textblock e_csv_from_textblock() {
    vx_data_csv::Func_csv_from_textblock output = vx_data_csv::vx_package->e_csv_from_textblock;
    if (!output) {
      output = new vx_data_csv::Class_csv_from_textblock();
      vx_core::vx_reserve_empty(output);
      vx_data_csv::vx_package->e_csv_from_textblock = output;
    }
    return output;
  }
  vx_data_csv::Func_csv_from_textblock t_csv_from_textblock() {
    vx_data_csv::Func_csv_from_textblock output = vx_data_csv::vx_package->t_csv_from_textblock;
    if (!output) {
      output = new vx_data_csv::Class_csv_from_textblock();
      vx_core::vx_reserve_type(output);
      vx_data_csv::vx_package->t_csv_from_textblock = output;
    }
    return output;
  }

  // (func csvrows<-textblock)
  vx_data_csv::Func_csvrows_from_textblock e_csvrows_from_textblock() {
    vx_data_csv::Func_csvrows_from_textblock output = vx_data_csv::vx_package->e_csvrows_from_textblock;
    if (!output) {
      output = new vx_data_csv::Class_csvrows_from_textblock();
      vx_core::vx_reserve_empty(output);
      vx_data_csv::vx_package->e_csvrows_from_textblock = output;
    }
    return output;
  }
  vx_data_csv::Func_csvrows_from_textblock t_csvrows_from_textblock() {
    vx_data_csv::Func_csvrows_from_textblock output = vx_data_csv::vx_package->t_csvrows_from_textblock;
    if (!output) {
      output = new vx_data_csv::Class_csvrows_from_textblock();
      vx_core::vx_reserve_type(output);
      vx_data_csv::vx_package->t_csvrows_from_textblock = output;
    }
    return output;
  }

}
