#include <memory>
#include <set>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/collection.hpp"
#include "../../vx/type.hpp"
#include "../../vx/data/textblock.hpp"
#include "vx/data/csv.hpp"

//namespace vx_data_csv {

  /**
   * type: csv
   * (type csv)
   */
  //class Type_csv {
    // headers()
    vx_core::Type_stringlist vx_data_csv::Class_csv::headers() {
      vx_core::Type_stringlist output = this->vx_p_headers;
      if (output == NULL) {
        output = vx_core::t_stringlist;
      }
      return output;
    }

    // rows()
    vx_data_csv::Type_csvrows vx_data_csv::Class_csv::rows() {
      vx_data_csv::Type_csvrows output = this->vx_p_rows;
      if (output == NULL) {
        output = vx_data_csv::t_csvrows;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any vx_data_csv::Class_csv::vx_get_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":headers") {
        output = this->headers();
      } else if (skey == ":rows") {
        output = this->rows();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_data_csv::Class_csv::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":headers"] = this->headers();
      output[":rows"] = this->rows();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_csv::Class_csv::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_csv::e_csv->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_csv::Class_csv::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_csv::Type_csv output;
      vx_data_csv::Class_csv* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val->vx_msgblock(), vals);
      output->vx_p_headers = val->headers();
      output->vx_p_rows = val->rows();
      std::set<std::string> validkeys;
      validkeys.insert(":headers");
      validkeys.insert(":rows");
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new csv) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":headers") {
            if (valsubtype == vx_core::t_stringlist) {
              output->vx_p_headers = vx_core::any_from_any(vx_core::t_stringlist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new csv :headers " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":rows") {
            if (valsubtype == vx_data_csv::t_csvrows) {
              output->vx_p_rows = vx_core::any_from_any(vx_data_csv::t_csvrows, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new csv :rows " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new csv) - Invalid Key: " + key);
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

    template <class T> std::shared_ptr<T> vx_data_csv::Class_csv::vx_empty(std::shared_ptr<T> val) {return vx_data_csv::e_csv;}
    template <class T> std::shared_ptr<T> vx_data_csv::Class_csv::vx_type(std::shared_ptr<T> val) {return vx_data_csv::t_csv;}

    vx_core::Type_typedef vx_data_csv::Class_csv::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::e_argmap // properties
      );
    }

    vx_data_csv::Type_csv vx_data_csv::e_csv = std::make_shared<vx_data_csv::Class_csv>();
    vx_data_csv::Type_csv vx_data_csv::t_csv = std::make_shared<vx_data_csv::Class_csv>();
  //}

  /**
   * type: csvrows
   * (type csvrows)
   */
  //class Type_csvrows {
    vx_core::vx_Type_listany vx_data_csv::Class_csvrows::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_core::Type_stringlist vx_data_csv::Class_csvrows::vx_get_stringlist(vx_core::Type_int index) {
      vx_core::Type_stringlist output = vx_core::e_stringlist;
      vx_data_csv::Class_csvrows* list = this;
      int iindex = index->vx_int();
      std::vector<vx_core::Type_stringlist> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_stringlist> vx_data_csv::Class_csvrows::vx_liststringlist() {return vx_p_list;}

    vx_core::Type_any vx_data_csv::Class_csvrows::vx_get_any(vx_core::Type_int index) {
      return this->vx_get_stringlist(index);
    }

    template <class T> std::shared_ptr<T> vx_data_csv::Class_csvrows::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_csv::e_csvrows->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_csv::Class_csvrows::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_csv::Type_csvrows output;
      vx_data_csv::Class_csvrows* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val->vx_msgblock(), vals);
      std::vector<vx_core::Type_stringlist> listval = val->vx_liststringlist();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_stringlist) {
          listval.push_back(vx_core::any_from_any(vx_core::t_stringlist, valsub));
        } else if (valsubtype == vx_data_csv::t_csvrows) {
          vx_data_csv::Type_csvrows multi = vx_core::any_from_any(vx_data_csv::t_csvrows, valsub);
          listval = vx_core::listaddall(listval, multi->vx_liststringlist());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new csvrows) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_csv::Class_csvrows::vx_empty(std::shared_ptr<T> val) {return vx_data_csv::e_csvrows;}
    template <class T> std::shared_ptr<T> vx_data_csv::Class_csvrows::vx_type(std::shared_ptr<T> val) {return vx_data_csv::t_csvrows;}

    vx_core::Type_typedef vx_data_csv::Class_csvrows::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/csv", // pkgname
        "csvrows", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_stringlist}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_data_csv::Type_csvrows vx_data_csv::e_csvrows = std::make_shared<vx_data_csv::Class_csvrows>();
    vx_data_csv::Type_csvrows vx_data_csv::t_csvrows = std::make_shared<vx_data_csv::Class_csvrows>();
  //}

  /**
   * Constant: delims
   * {delimset}
   */
  //class Class_delims {

    // vx_constdef()
    vx_core::Type_constdef vx_data_csv::Class_delims::vx_constdef() {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/data/csv", // pkgname
        "delims", // name
        vx_core::Class_typedef::vx_typedef_new(
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
        )
      );
    }

    // vx_const_new()
    vx_data_csv::Const_delims vx_data_csv::Class_delims::vx_const_new() {
      vx_data_csv::Const_delims output = std::shared_ptr<vx_data_csv::Class_delims>();
      vx_data_textblock::Type_delimset val = vx_core::f_new(
        vx_data_textblock::t_delimset,
        vx_core::t_anylist->vx_new(vx_core::t_anylist, {
          vx_core::t_string->vx_new_from_string(":split"),
          vx_core::f_new(
            vx_core::t_stringlist,
            vx_core::t_anylist->vx_new(vx_core::t_anylist, {
              vx_core::t_string->vx_new_from_string("\n")
            })
          ),
          vx_core::t_string->vx_new_from_string(":subset"),
          vx_core::f_new(
            vx_data_textblock::t_delimset,
            vx_core::t_anylist->vx_new(vx_core::t_anylist, {
              vx_core::t_string->vx_new_from_string(":split"),
              vx_core::f_new(
                vx_core::t_stringlist,
                vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                  vx_core::t_string->vx_new_from_string(",")
                })
              ),
              vx_core::t_string->vx_new_from_string(":subset"),
              vx_core::f_new(
                vx_data_textblock::t_delimset,
                vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                  vx_core::t_string->vx_new_from_string(":start"),
                  vx_core::f_new(
                    vx_core::t_stringlist,
                    vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                      vx_core::t_string->vx_new_from_string("\"")
                    })
                  ),
                  vx_core::t_string->vx_new_from_string(":end"),
                  vx_core::f_new(
                    vx_core::t_stringlist,
                    vx_core::t_anylist->vx_new(vx_core::t_anylist, {
                      vx_core::t_string->vx_new_from_string("\"")
                    })
                  )
                })
              )
            })
          )
        })
      );
      output->vx_p_start = val->start();
      output->vx_p_end = val->end();
      output->vx_p_split = val->split();
      output->vx_p_subset = val->subset();
      return output;
    }


  //}

  vx_data_csv::Const_delims vx_data_csv::c_delims = vx_data_csv::Class_delims::vx_const_new();

  /**
   * @function csv_from_textblock
   * @param  {textblock} textblock
   * @return {csv}
   * (func csv<-textblock)
   */
  //class Func_csv_from_textblock {

    template <class T> std::shared_ptr<T> vx_data_csv::Class_csv_from_textblock::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_csv::Func_csv_from_textblock output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_csv::Class_csv_from_textblock::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_csv::Func_csv_from_textblock output;
      return output;
    }

    vx_core::Type_typedef vx_data_csv::Class_csv_from_textblock::vx_typedef() {return vx_data_csv::t_csv_from_textblock->vx_typedef();}

    vx_core::Type_funcdef vx_data_csv::Class_csv_from_textblock::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/csv", // pkgname
        "csv<-textblock", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
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
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_data_csv::Class_csv_from_textblock::vx_empty(std::shared_ptr<T> val) {return vx_data_csv::e_csv_from_textblock;}
    template <class T> std::shared_ptr<T> vx_data_csv::Class_csv_from_textblock::vx_type(std::shared_ptr<T> val) {return vx_data_csv::t_csv_from_textblock;}

    vx_core::Func_any_from_any vx_data_csv::Class_csv_from_textblock::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_data_csv::Class_csv_from_textblock::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_data_textblock::Type_textblock inputval = (vx_data_textblock::Type_textblock)value;
      vx_core::Type_any outputval = vx_data_csv::f_csv_from_textblock(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_data_csv::Class_csv_from_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblock = vx_core::f_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_data_csv::f_csv_from_textblock(textblock);
      return output;
    }

    vx_data_csv::Type_csv vx_data_csv::Class_csv_from_textblock::vx_f_csv_from_textblock(vx_data_textblock::Type_textblock textblock) {
      return vx_data_csv::f_csv_from_textblock(textblock);
    }

  //}

  vx_data_csv::Func_csv_from_textblock vx_data_csv::e_csv_from_textblock = std::make_shared<vx_data_csv::Class_csv_from_textblock>();
  vx_data_csv::Func_csv_from_textblock vx_data_csv::t_csv_from_textblock = std::make_shared<vx_data_csv::Class_csv_from_textblock>();

  vx_data_csv::Type_csv vx_data_csv::f_csv_from_textblock(vx_data_textblock::Type_textblock textblock) {
    vx_data_csv::Type_csv output = vx_data_csv::e_csv;
    output = vx_core::f_let(
      vx_data_csv::t_csv,
      vx_core::t_any_from_func->fn_new([textblock]() {
        vx_data_csv::Type_csvrows allrows = vx_data_csv::f_csvrows_from_textblock(textblock);
        vx_core::Type_stringlist headers = vx_core::f_any_from_list(vx_core::t_stringlist, allrows, vx_core::t_int->vx_new_from_int(0));
        vx_data_csv::Type_csvrows rows = vx_collection::f_list_from_list_end(vx_data_csv::t_csvrows, allrows, vx_core::t_int->vx_new_from_int(1));
        return vx_core::f_new(
          vx_data_csv::t_csv,
          vx_core::t_anylist->vx_new(vx_core::t_anylist, {
            vx_core::t_string->vx_new_from_string(":headers"),
            headers,
            vx_core::t_string->vx_new_from_string(":rows"),
            rows
          })
        );
      })
    );
    return output;
  }

  /**
   * @function csvrows_from_textblock
   * @param  {textblock} textblock
   * @return {csvrows}
   * (func csvrows<-textblock)
   */
  //class Func_csvrows_from_textblock {

    template <class T> std::shared_ptr<T> vx_data_csv::Class_csvrows_from_textblock::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_csv::Func_csvrows_from_textblock output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_csv::Class_csvrows_from_textblock::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_csv::Func_csvrows_from_textblock output;
      return output;
    }

    vx_core::Type_typedef vx_data_csv::Class_csvrows_from_textblock::vx_typedef() {return vx_data_csv::t_csvrows_from_textblock->vx_typedef();}

    vx_core::Type_funcdef vx_data_csv::Class_csvrows_from_textblock::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/csv", // pkgname
        "csvrows<-textblock", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/data/csv", // pkgname
          "csvrows", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_stringlist}), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    template <class T> std::shared_ptr<T> vx_data_csv::Class_csvrows_from_textblock::vx_empty(std::shared_ptr<T> val) {return vx_data_csv::e_csvrows_from_textblock;}
    template <class T> std::shared_ptr<T> vx_data_csv::Class_csvrows_from_textblock::vx_type(std::shared_ptr<T> val) {return vx_data_csv::t_csvrows_from_textblock;}

    vx_core::Func_any_from_any vx_data_csv::Class_csvrows_from_textblock::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_data_csv::Class_csvrows_from_textblock::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_data_textblock::Type_textblock inputval = (vx_data_textblock::Type_textblock)value;
      vx_core::Type_any outputval = vx_data_csv::f_csvrows_from_textblock(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_data_csv::Class_csvrows_from_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblock = vx_core::f_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_data_csv::f_csvrows_from_textblock(textblock);
      return output;
    }

    vx_data_csv::Type_csvrows vx_data_csv::Class_csvrows_from_textblock::vx_f_csvrows_from_textblock(vx_data_textblock::Type_textblock textblock) {
      return vx_data_csv::f_csvrows_from_textblock(textblock);
    }

  //}

  vx_data_csv::Func_csvrows_from_textblock vx_data_csv::e_csvrows_from_textblock = std::make_shared<vx_data_csv::Class_csvrows_from_textblock>();
  vx_data_csv::Func_csvrows_from_textblock vx_data_csv::t_csvrows_from_textblock = std::make_shared<vx_data_csv::Class_csvrows_from_textblock>();

  vx_data_csv::Type_csvrows vx_data_csv::f_csvrows_from_textblock(vx_data_textblock::Type_textblock textblock) {
    vx_data_csv::Type_csvrows output = vx_data_csv::e_csvrows;
    output = vx_core::f_let(
      vx_data_csv::t_csvrows,
      vx_core::t_any_from_func->fn_new([textblock]() {
        vx_data_textblock::Type_textblock parsedtb = vx_data_textblock::f_parse(
          textblock,
          vx_data_csv::c_delims
        );
        vx_data_textblock::Type_textblocklist childtbs = vx_data_textblock::f_textblocks_from_textblock(parsedtb);
        vx_core::Type_stringlist strings = vx_data_textblock::f_stringlist_from_textblocklist(childtbs);
        return vx_core::f_new(
          vx_data_csv::t_csvrows,
          vx_core::t_anylist->vx_new(vx_core::t_anylist, {
            strings
          })
        );
      })
    );
    return output;
  }


//}
