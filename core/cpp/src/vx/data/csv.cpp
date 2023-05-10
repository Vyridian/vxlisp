#include <any>
#include <map>
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
    vx_core::Type_stringlist* vx_data_csv::Type_csv::headers() {
      vx_core::Type_stringlist* output = this->vx_p_headers;
      if (output == NULL) {
        output = vx_core::t_stringlist;
      }
    }

    // rows()
    vx_data_csv::Type_csvrows* vx_data_csv::Type_csv::rows() {
      vx_data_csv::Type_csvrows* output = this->vx_p_rows;
      if (output == NULL) {
        output = vx_data_csv::t_csvrows;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_data_csv::Type_csv::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
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
    std::map<std::string, vx_core::Type_any*> vx_data_csv::Type_csv::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":headers"] = this->headers();
      output[":rows"] = this->rows();
      return output;
    }

    template<typename... Args> vx_data_csv::Type_csv* vx_data_csv::Type_csv::vx_new(Args*... args) {return vx_data_csv::e_csv->vx_copy(args...);}
    template<typename... Args> vx_data_csv::Type_csv* vx_data_csv::Type_csv::vx_copy(Args*... args) {
      vx_data_csv::Type_csv* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_csv* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_headers = val->headers();
      output->vx_p_rows = val->rows();
      std::set<std::string> validkeys;
      validkeys.insert(":headers");
      validkeys.insert(":rows");
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
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new csv) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":headers") {
            if (valsubtype == vx_core::t_stringlist) {
              output->vx_p_headers = vx_core::any_from_any(vx_core::t_stringlist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new csv :headers " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":rows") {
            if (valsubtype == vx_data_csv::t_csvrows) {
              output->vx_p_rows = vx_core::any_from_any(vx_data_csv::t_csvrows, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new csv :rows " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new csv) - Invalid Key: " + key);
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

    vx_data_csv::Type_csv* vx_data_csv::Type_csv::vx_empty() {return vx_data_csv::e_csv;}
    vx_data_csv::Type_csv* vx_data_csv::Type_csv::vx_type() {return vx_data_csv::t_csv;}

    vx_core::Type_typedef* vx_data_csv::Type_csv::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
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

  //}

  /**
   * type: csvrows
   * (type csvrows)
   */
  //class Type_csvrows {
    std::vector<vx_core::Type_any*> vx_data_csv::Type_csvrows::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_core::Type_stringlist* vx_data_csv::Type_csvrows::vx_stringlist(vx_core::Type_int* index) {
      vx_core::Type_stringlist* output = vx_core::e_stringlist;
      vx_data_csv::Type_csvrows* list = this;
      int iindex = index->vx_int();
      std::vector<vx_core::Type_stringlist*> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_stringlist*> vx_data_csv::Type_csvrows::vx_liststringlist() {return vx_p_list;}

    vx_core::Type_any* vx_data_csv::Type_csvrows::vx_any(vx_core::Type_int* index) {
      return this->vx_stringlist(index);
    }

    template<typename... Args> vx_data_csv::Type_csvrows* vx_data_csv::Type_csvrows::vx_new(Args*... args) {return vx_data_csv::e_csvrows->vx_copy(args...);}
    template<typename... Args> vx_data_csv::Type_csvrows* vx_data_csv::Type_csvrows::vx_copy(Args*... args) {
      vx_data_csv::Type_csvrows* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_data_csv::Type_csvrows* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_core::Type_stringlist*> listval = val->vx_liststringlist();
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_stringlist) {
          listval.push_back(vx_core::any_from_any(vx_core::t_stringlist, valsub));
        } else if (valsubtype == vx_data_csv::t_csvrows) {
          vx_data_csv::Type_csvrows* multi = vx_core::any_from_any(vx_data_csv::t_csvrows, valsub);
          listval = vx_core::listaddall(listval, multi->vx_liststringlist());
        } else if (valsubtype == vx_core::t_nativelist) {
          std::vector<std::any*> listunknown = vx_core::any_from_any(std::vector<vx_core::Type_any*>, valsub);
          for (std::any* item : listunknown) {
            vx_core::Type_any* itemtype = vx_core::t_any->vx_type_from_any(item);
            if (itemtype == vx_core::t_stringlist) {
              vx_core::Type_stringlist* valitem = vx_core::any_from_any(vx_core::t_stringlist, item);
              listval.push_back(valitem);
            }
          }
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new csvrows) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(msg);
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_data_csv::Type_csvrows* vx_data_csv::Type_csvrows::vx_empty() {return vx_data_csv::e_csvrows;}
    vx_data_csv::Type_csvrows* vx_data_csv::Type_csvrows::vx_type() {return vx_data_csv::t_csvrows;}

    vx_core::Type_typedef* vx_data_csv::Type_csvrows::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/data/csv", // pkgname
        "csvrows", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_stringlist), // allowtypes
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
   * Constant: delims
   * {delimset}
   */
  //class Const_delims {

    // vx_constdef()
    vx_core::Type_constdef* vx_data_csv::Const_delims::vx_constdef() {
      return vx_core::Type_constdef::vx_constdef_new(
        "vx/data/csv", // pkgname
        "delims", // name
        vx_core::Type_typedef::vx_typedef_new(
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
    vx_data_csv::Const_delims* vx_data_csv::Const_delims::vx_const_new() {
      vx_data_csv::Const_delims* output = new vx_data_csv::Const_delims();
      vx_data_textblock::Type_delimset* val = vx_core::f_new(
        vx_data_textblock::t_delimset,
        vx_core::t_anylist->vx_new(
          vx_core::t_string->vx_new_from_string(":split"),
          vx_core::f_new(
            vx_core::t_stringlist,
            vx_core::t_anylist->vx_new(
              vx_core::t_string->vx_new_from_string("\n")
            )
          ),
          vx_core::t_string->vx_new_from_string(":subset"),
          vx_core::f_new(
            vx_data_textblock::t_delimset,
            vx_core::t_anylist->vx_new(
              vx_core::t_string->vx_new_from_string(":split"),
              vx_core::f_new(
                vx_core::t_stringlist,
                vx_core::t_anylist->vx_new(
                  vx_core::t_string->vx_new_from_string(",")
                )
              ),
              vx_core::t_string->vx_new_from_string(":subset"),
              vx_core::f_new(
                vx_data_textblock::t_delimset,
                vx_core::t_anylist->vx_new(
                  vx_core::t_string->vx_new_from_string(":start"),
                  vx_core::f_new(
                    vx_core::t_stringlist,
                    vx_core::t_anylist->vx_new(
                      vx_core::t_string->vx_new_from_string("\"")
                    )
                  ),
                  vx_core::t_string->vx_new_from_string(":end"),
                  vx_core::f_new(
                    vx_core::t_stringlist,
                    vx_core::t_anylist->vx_new(
                      vx_core::t_string->vx_new_from_string("\"")
                    )
                  )
                )
              )
            )
          )
        )
      );
      output->vx_p_start = val->start();
      output->vx_p_end = val->end();
      output->vx_p_split = val->split();
      output->vx_p_subset = val->subset();
      return output;
    }


  //}

  vx_data_csv::Const_delims* vx_data_csv::c_delims = vx_data_csv::Const_delims::vx_const_new();

  /**
   * @function csv_from_textblock
   * @param  {textblock} textblock
   * @return {csv}
   * (func csv<-textblock)
   */
  //class Func_csv_from_textblock {

    template<class... Args> vx_data_csv::Func_csv_from_textblock* vx_data_csv::Func_csv_from_textblock::vx_new(Args*... args) {
      vx_data_csv::Func_csv_from_textblock* output;
      return output;
    }

    template<class... Args> vx_data_csv::Func_csv_from_textblock* vx_data_csv::Func_csv_from_textblock::vx_copy(Args*... args) {
      vx_data_csv::Func_csv_from_textblock* output;
      return output;
    }

    vx_core::Type_typedef* vx_data_csv::Func_csv_from_textblock::vx_typedef() {return vx_data_csv::t_csv_from_textblock->vx_typedef();}

    vx_core::Type_funcdef* vx_data_csv::Func_csv_from_textblock::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/data/csv", // pkgname
        "csv<-textblock", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
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

    vx_data_csv::Func_csv_from_textblock* vx_data_csv::Func_csv_from_textblock::vx_empty() {return vx_data_csv::e_csv_from_textblock;}
    vx_data_csv::Func_csv_from_textblock* vx_data_csv::Func_csv_from_textblock::vx_type() {return vx_data_csv::t_csv_from_textblock;}

    vx_core::Func_any_from_any* vx_data_csv::Func_csv_from_textblock::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_data_csv::Func_csv_from_textblock::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_data_textblock::Type_textblock* inputval = (vx_data_textblock::Type_textblock)value;
      vx_core::Type_any* outputval = vx_data_csv::f_csv_from_textblock(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_data_csv::Func_csv_from_textblock::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_data_textblock::Type_textblock* textblock = vx_core::f_any_from_any(vx_data_textblock::t_textblock, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_data_csv::f_csv_from_textblock(textblock);
      return output;
    }

    vx_data_csv::Type_csv* vx_data_csv::Func_csv_from_textblock::vx_csv_from_textblock(vx_data_textblock::Type_textblock* textblock) {
      return vx_data_csv::f_csv_from_textblock(textblock);
    }

  //}

  vx_data_csv::Func_csv_from_textblock* vx_data_csv::e_csv_from_textblock = new vx_data_csv::Func_csv_from_textblock();
  vx_data_csv::Func_csv_from_textblock* vx_data_csv::t_csv_from_textblock = new vx_data_csv::Func_csv_from_textblock();

  vx_data_csv::Type_csv* vx_data_csv::f_csv_from_textblock(vx_data_textblock::Type_textblock* textblock) {
    vx_data_csv::Type_csv* output = vx_data_csv::e_csv;
    output = vx_core::f_let(
      vx_data_csv::t_csv,
      vx_core::t_any_from_func->fn_new([textblock]() {
        vx_data_csv::Type_csvrows* allrows = vx_data_csv::f_csvrows_from_textblock(textblock);
        vx_core::Type_stringlist* headers = vx_core::f_any_from_list(vx_core::t_stringlist, allrows, vx_core::t_int->vx_new_from_int(0));
        vx_data_csv::Type_csvrows* rows = vx_collection::f_list_from_list_end(vx_data_csv::t_csvrows, allrows, vx_core::t_int->vx_new_from_int(1));
        return vx_core::f_new(
          vx_data_csv::t_csv,
          vx_core::t_anylist->vx_new(
            vx_core::t_string->vx_new_from_string(":headers"),
            headers,
            vx_core::t_string->vx_new_from_string(":rows"),
            rows
          )
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

    template<class... Args> vx_data_csv::Func_csvrows_from_textblock* vx_data_csv::Func_csvrows_from_textblock::vx_new(Args*... args) {
      vx_data_csv::Func_csvrows_from_textblock* output;
      return output;
    }

    template<class... Args> vx_data_csv::Func_csvrows_from_textblock* vx_data_csv::Func_csvrows_from_textblock::vx_copy(Args*... args) {
      vx_data_csv::Func_csvrows_from_textblock* output;
      return output;
    }

    vx_core::Type_typedef* vx_data_csv::Func_csvrows_from_textblock::vx_typedef() {return vx_data_csv::t_csvrows_from_textblock->vx_typedef();}

    vx_core::Type_funcdef* vx_data_csv::Func_csvrows_from_textblock::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/data/csv", // pkgname
        "csvrows<-textblock", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/data/csv", // pkgname
          "csvrows", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_stringlist), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_data_csv::Func_csvrows_from_textblock* vx_data_csv::Func_csvrows_from_textblock::vx_empty() {return vx_data_csv::e_csvrows_from_textblock;}
    vx_data_csv::Func_csvrows_from_textblock* vx_data_csv::Func_csvrows_from_textblock::vx_type() {return vx_data_csv::t_csvrows_from_textblock;}

    vx_core::Func_any_from_any* vx_data_csv::Func_csvrows_from_textblock::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_data_csv::Func_csvrows_from_textblock::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_data_textblock::Type_textblock* inputval = (vx_data_textblock::Type_textblock)value;
      vx_core::Type_any* outputval = vx_data_csv::f_csvrows_from_textblock(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_data_csv::Func_csvrows_from_textblock::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_data_textblock::Type_textblock* textblock = vx_core::f_any_from_any(vx_data_textblock::t_textblock, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_data_csv::f_csvrows_from_textblock(textblock);
      return output;
    }

    vx_data_csv::Type_csvrows* vx_data_csv::Func_csvrows_from_textblock::vx_csvrows_from_textblock(vx_data_textblock::Type_textblock* textblock) {
      return vx_data_csv::f_csvrows_from_textblock(textblock);
    }

  //}

  vx_data_csv::Func_csvrows_from_textblock* vx_data_csv::e_csvrows_from_textblock = new vx_data_csv::Func_csvrows_from_textblock();
  vx_data_csv::Func_csvrows_from_textblock* vx_data_csv::t_csvrows_from_textblock = new vx_data_csv::Func_csvrows_from_textblock();

  vx_data_csv::Type_csvrows* vx_data_csv::f_csvrows_from_textblock(vx_data_textblock::Type_textblock* textblock) {
    vx_data_csv::Type_csvrows* output = vx_data_csv::e_csvrows;
    output = vx_core::f_let(
      vx_data_csv::t_csvrows,
      vx_core::t_any_from_func->fn_new([textblock]() {
        vx_data_textblock::Type_textblock* parsedtb = vx_data_textblock::f_parse(
          textblock,
          vx_data_csv::c_delims
        );
        vx_data_textblock::Type_textblocklist* childtbs = vx_data_textblock::f_textblocks_from_textblock(parsedtb);
        vx_core::Type_stringlist* strings = vx_data_textblock::f_stringlist_from_textblocklist(childtbs);
        return vx_core::f_new(
          vx_data_csv::t_csvrows,
          vx_core::t_anylist->vx_new(
            strings
          )
        );
      })
    );
    return output;
  }


//}
