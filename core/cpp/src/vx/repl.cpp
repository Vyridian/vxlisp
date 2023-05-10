#include <any>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "../vx/core.hpp"
#include "../vx/data/textblock.hpp"
#include "vx/repl.hpp"

//namespace vx_repl {

  /**
   * type: liblist
   * List of library names
   * (type liblist)
   */
  //class Type_liblist {
    std::vector<vx_core::Type_any*> vx_repl::Type_liblist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_core::Type_string* vx_repl::Type_liblist::vx_string(vx_core::Type_int* index) {
      vx_core::Type_string* output = vx_core::e_string;
      vx_repl::Type_liblist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_core::Type_string*> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_string*> vx_repl::Type_liblist::vx_liststring() {return vx_p_list;}

    vx_core::Type_any* vx_repl::Type_liblist::vx_any(vx_core::Type_int* index) {
      return this->vx_string(index);
    }

    template<typename... Args> vx_repl::Type_liblist* vx_repl::Type_liblist::vx_new(Args*... args) {return vx_repl::e_liblist->vx_copy(args...);}
    template<typename... Args> vx_repl::Type_liblist* vx_repl::Type_liblist::vx_copy(Args*... args) {
      vx_repl::Type_liblist* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_repl::Type_liblist* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_core::Type_string*> listval = val->vx_liststring();
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_nativestring) {
          listval.push_back(vx_core::t_string->vx_new(valsub));
        } else if (valsubtype == vx_repl::t_liblist) {
          vx_repl::Type_liblist* multi = vx_core::any_from_any(vx_repl::t_liblist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_liststring());
        } else if (valsubtype == vx_core::t_nativelist) {
          std::vector<std::any*> listunknown = vx_core::any_from_any(std::vector<vx_core::Type_any*>, valsub);
          for (std::any* item : listunknown) {
            vx_core::Type_any* itemtype = vx_core::t_any->vx_type_from_any(item);
            if (itemtype == vx_core::t_string) {
              vx_core::Type_string* valitem = vx_core::any_from_any(vx_core::t_string, item);
              listval.push_back(valitem);
            }
          }
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new liblist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(msg);
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_repl::Type_liblist* vx_repl::Type_liblist::vx_empty() {return vx_repl::e_liblist;}
    vx_repl::Type_liblist* vx_repl::Type_liblist::vx_type() {return vx_repl::t_liblist;}

    vx_core::Type_typedef* vx_repl::Type_liblist::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "liblist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_string), // allowtypes
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
   * type: repl
   * Repl structure
   * (type repl)
   */
  //class Type_repl {
    // type()
    vx_core::Type_any* vx_repl::Type_repl::type() {
      vx_core::Type_any* output = this->vx_p_type;
      if (output == NULL) {
        output = vx_core::t_any;
      }
    }

    // repllist()
    vx_repl::Type_repllist* vx_repl::Type_repl::repllist() {
      vx_repl::Type_repllist* output = this->vx_p_repllist;
      if (output == NULL) {
        output = vx_repl::t_repllist;
      }
    }

    // async()
    vx_core::Type_boolean* vx_repl::Type_repl::async() {
      vx_core::Type_boolean* output = this->vx_p_async;
      if (output == NULL) {
        output = vx_core::t_boolean;
      }
    }

    // val()
    vx_core::Type_any* vx_repl::Type_repl::val() {
      vx_core::Type_any* output = this->vx_p_val;
      if (output == NULL) {
        output = vx_core::t_any;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_repl::Type_repl::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":type") {
        output = this->type();
      } else if (skey == ":repllist") {
        output = this->repllist();
      } else if (skey == ":async") {
        output = this->async();
      } else if (skey == ":val") {
        output = this->val();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_repl::Type_repl::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":type"] = this->type();
      output[":repllist"] = this->repllist();
      output[":async"] = this->async();
      output[":val"] = this->val();
      return output;
    }

    template<typename... Args> vx_repl::Type_repl* vx_repl::Type_repl::vx_new(Args*... args) {return vx_repl::e_repl->vx_copy(args...);}
    template<typename... Args> vx_repl::Type_repl* vx_repl::Type_repl::vx_copy(Args*... args) {
      vx_repl::Type_repl* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_repl* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_type = val->type();
      output->vx_p_repllist = val->repllist();
      output->vx_p_async = val->async();
      output->vx_p_val = val->val();
      std::set<std::string> validkeys;
      validkeys.insert(":type");
      validkeys.insert(":repllist");
      validkeys.insert(":async");
      validkeys.insert(":val");
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
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new repl) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":type") {
            if (valsubtype == vx_core::t_any) {
              output->vx_p_type = vx_core::any_from_any(vx_core::t_any, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new repl :type " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":repllist") {
            if (valsubtype == vx_repl::t_repllist) {
              output->vx_p_repllist = vx_core::any_from_any(vx_repl::t_repllist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new repl :repllist " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":async") {
            if (valsubtype == vx_core::t_boolean) {
              output->vx_p_async = vx_core::any_from_any(vx_core::t_boolean, valsub);
            } else if (valsubtype == vx_core::t_nativeboolean) {
              output->vx_p_async = vx_core::t_boolean->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new repl :async " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":val") {
            if (valsubtype == vx_core::t_any) {
              output->vx_p_val = vx_core::any_from_any(vx_core::t_any, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new repl :val " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new repl) - Invalid Key: " + key);
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

    vx_repl::Type_repl* vx_repl::Type_repl::vx_empty() {return vx_repl::e_repl;}
    vx_repl::Type_repl* vx_repl::Type_repl::vx_type() {return vx_repl::t_repl;}

    vx_core::Type_typedef* vx_repl::Type_repl::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "repl", // name
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
   * type: repllist
   * List of repl
   * (type repllist)
   */
  //class Type_repllist {
    std::vector<vx_core::Type_any*> vx_repl::Type_repllist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_repl::Type_repl* vx_repl::Type_repllist::vx_repl(vx_core::Type_int* index) {
      vx_repl::Type_repl* output = vx_repl::e_repl;
      vx_repl::Type_repllist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_repl::Type_repl*> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_repl::Type_repl*> vx_repl::Type_repllist::vx_listrepl() {return vx_p_list;}

    vx_core::Type_any* vx_repl::Type_repllist::vx_any(vx_core::Type_int* index) {
      return this->vx_repl(index);
    }

    template<typename... Args> vx_repl::Type_repllist* vx_repl::Type_repllist::vx_new(Args*... args) {return vx_repl::e_repllist->vx_copy(args...);}
    template<typename... Args> vx_repl::Type_repllist* vx_repl::Type_repllist::vx_copy(Args*... args) {
      vx_repl::Type_repllist* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_repl::Type_repllist* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_repl::Type_repl*> listval = val->vx_listrepl();
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_repl::t_repl) {
          listval.push_back(vx_core::any_from_any(vx_repl::t_repl, valsub));
        } else if (valsubtype == vx_repl::t_repllist) {
          vx_repl::Type_repllist* multi = vx_core::any_from_any(vx_repl::t_repllist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listrepl());
        } else if (valsubtype == vx_core::t_nativelist) {
          std::vector<std::any*> listunknown = vx_core::any_from_any(std::vector<vx_core::Type_any*>, valsub);
          for (std::any* item : listunknown) {
            vx_core::Type_any* itemtype = vx_core::t_any->vx_type_from_any(item);
            if (itemtype == vx_repl::t_repl) {
              vx_repl::Type_repl* valitem = vx_core::any_from_any(vx_repl::t_repl, item);
              listval.push_back(valitem);
            }
          }
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new repllist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(msg);
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_repl::Type_repllist* vx_repl::Type_repllist::vx_empty() {return vx_repl::e_repllist;}
    vx_repl::Type_repllist* vx_repl::Type_repllist::vx_type() {return vx_repl::t_repllist;}

    vx_core::Type_typedef* vx_repl::Type_repllist::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/repl", // pkgname
        "repllist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_repl::t_repl), // allowtypes
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
   * @function any_repl_from_functype_args
   * Returns any from a repl func and args.
   * @param  {any} type
   * @param  {anylist} args
   * @return {any}
   * (func any-repl<-functype-args)
   */
  //class Func_any_repl_from_functype_args {

    template<class... Args> vx_repl::Func_any_repl_from_functype_args* vx_repl::Func_any_repl_from_functype_args::vx_new(Args*... args) {
      vx_repl::Func_any_repl_from_functype_args* output;
      return output;
    }

    template<class... Args> vx_repl::Func_any_repl_from_functype_args* vx_repl::Func_any_repl_from_functype_args::vx_copy(Args*... args) {
      vx_repl::Func_any_repl_from_functype_args* output;
      return output;
    }

    vx_core::Type_typedef* vx_repl::Func_any_repl_from_functype_args::vx_typedef() {return vx_repl::t_any_repl_from_functype_args->vx_typedef();}

    vx_core::Type_funcdef* vx_repl::Func_any_repl_from_functype_args::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "any-repl<-functype-args", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any", // name
          "", // extends
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

    vx_repl::Func_any_repl_from_functype_args* vx_repl::Func_any_repl_from_functype_args::vx_empty() {return vx_repl::e_any_repl_from_functype_args;}
    vx_repl::Func_any_repl_from_functype_args* vx_repl::Func_any_repl_from_functype_args::vx_type() {return vx_repl::t_any_repl_from_functype_args;}

    vx_core::Type_any* vx_repl::Func_any_repl_from_functype_args::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_any* type = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_anylist* args = vx_core::f_any_from_any(vx_core::t_anylist, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_repl::f_any_repl_from_functype_args(type, args);
      return output;
    }

    vx_core::Type_any* vx_repl::Func_any_repl_from_functype_args::vx_any_repl_from_functype_args(vx_core::Type_any* type, vx_core::Type_anylist* args) {
      return vx_repl::f_any_repl_from_functype_args(type, args);
    }

  //}

  vx_repl::Func_any_repl_from_functype_args* vx_repl::e_any_repl_from_functype_args = new vx_repl::Func_any_repl_from_functype_args();
  vx_repl::Func_any_repl_from_functype_args* vx_repl::t_any_repl_from_functype_args = new vx_repl::Func_any_repl_from_functype_args();

  vx_core::Type_any* vx_repl::f_any_repl_from_functype_args(vx_core::Type_any* type, vx_core::Type_anylist* args) {
    vx_core::Type_any* output = vx_core::e_any;
    return output;
  }

  /**
   * @function any_from_liblist_string
   * Run an arbitrary program in the REPL.
   * @param  {liblist} liblist
   * @param  {string} text Program to run
   * @return {any}
   * (func any<-liblist-string)
   */
  //class Func_any_from_liblist_string {

    template<class... Args> vx_repl::Func_any_from_liblist_string* vx_repl::Func_any_from_liblist_string::vx_new(Args*... args) {
      vx_repl::Func_any_from_liblist_string* output;
      return output;
    }

    template<class... Args> vx_repl::Func_any_from_liblist_string* vx_repl::Func_any_from_liblist_string::vx_copy(Args*... args) {
      vx_repl::Func_any_from_liblist_string* output;
      return output;
    }

    vx_core::Type_typedef* vx_repl::Func_any_from_liblist_string::vx_typedef() {return vx_repl::t_any_from_liblist_string->vx_typedef();}

    vx_core::Type_funcdef* vx_repl::Func_any_from_liblist_string::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "any<-liblist-string", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any", // name
          "", // extends
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

    vx_repl::Func_any_from_liblist_string* vx_repl::Func_any_from_liblist_string::vx_empty() {return vx_repl::e_any_from_liblist_string;}
    vx_repl::Func_any_from_liblist_string* vx_repl::Func_any_from_liblist_string::vx_type() {return vx_repl::t_any_from_liblist_string;}

    vx_core::Type_any* vx_repl::Func_any_from_liblist_string::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_repl::Type_liblist* liblist = vx_core::f_any_from_any(vx_repl::t_liblist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_string* text = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Type_context* context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(2)));
      output = vx_repl::f_any_from_liblist_string(liblist, text, context);
      return output;
    }

    vx_core::Type_any* vx_repl::Func_any_from_liblist_string::vx_any_from_liblist_string(vx_repl::Type_liblist* liblist, vx_core::Type_string* text, vx_core::Type_context* context) {
      return vx_repl::f_any_from_liblist_string(liblist, text, context);
    }

  //}

  vx_repl::Func_any_from_liblist_string* vx_repl::e_any_from_liblist_string = new vx_repl::Func_any_from_liblist_string();
  vx_repl::Func_any_from_liblist_string* vx_repl::t_any_from_liblist_string = new vx_repl::Func_any_from_liblist_string();

  vx_core::Type_any* vx_repl::f_any_from_liblist_string(vx_repl::Type_liblist* liblist, vx_core::Type_string* text, vx_core::Type_context* context) {
    vx_core::Type_any* output = vx_core::e_any;
    output = vx_core::f_let(
      vx_core::t_any,
      vx_core::t_any_from_func->fn_new([liblist, text, context]() {
        vx_repl::Type_repl* repl = vx_repl::f_repl_from_liblist_string(liblist, text);
        return vx_repl::f_any_from_repl(repl, context);
      })
    );
    return output;
  }

  /**
   * 
   * @async
   * @function any_from_liblist_string_async
   * Run an arbitrary program in the REPL asynchrously.
   * @param  {liblist} liblist
   * @param  {string} text Program to run
   * @return {any}
   * (func any<-liblist-string-async)
   */
  //class Func_any_from_liblist_string_async {

    template<class... Args> vx_repl::Func_any_from_liblist_string_async* vx_repl::Func_any_from_liblist_string_async::vx_new(Args*... args) {
      vx_repl::Func_any_from_liblist_string_async* output;
      return output;
    }

    template<class... Args> vx_repl::Func_any_from_liblist_string_async* vx_repl::Func_any_from_liblist_string_async::vx_copy(Args*... args) {
      vx_repl::Func_any_from_liblist_string_async* output;
      return output;
    }

    vx_core::Type_typedef* vx_repl::Func_any_from_liblist_string_async::vx_typedef() {return vx_repl::t_any_from_liblist_string_async->vx_typedef();}

    vx_core::Type_funcdef* vx_repl::Func_any_from_liblist_string_async::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "any<-liblist-string-async", // name
        0, // idx
        true, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any", // name
          "", // extends
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

    vx_repl::Func_any_from_liblist_string_async* vx_repl::Func_any_from_liblist_string_async::vx_empty() {return vx_repl::e_any_from_liblist_string_async;}
    vx_repl::Func_any_from_liblist_string_async* vx_repl::Func_any_from_liblist_string_async::vx_type() {return vx_repl::t_any_from_liblist_string_async;}

    vx_core::Async<vx_core::Type_any*>* vx_repl::Func_any_from_liblist_string_async::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Async<vx_core::Type_any*>* output = vx_core::async_new_from_val((vx_core::e_any);
      vx_repl::Type_liblist* liblist = vx_core::f_any_from_any(vx_repl::t_liblist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_string* text = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Type_context* context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(2)));
      vx_core::Async<vx_core::Type_any*>* future = vx_repl::f_any_from_liblist_string_async(liblist, text, context);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    vx_core::Async<vx_core::Type_any*>* vx_repl::Func_any_from_liblist_string_async::vx_any_from_liblist_string_async(vx_repl::Type_liblist* liblist, vx_core::Type_string* text, vx_core::Type_context* context) {
      return vx_repl::f_any_from_liblist_string_async(liblist, text, context);
    }

  //}

  vx_repl::Func_any_from_liblist_string_async* vx_repl::e_any_from_liblist_string_async = new vx_repl::Func_any_from_liblist_string_async();
  vx_repl::Func_any_from_liblist_string_async* vx_repl::t_any_from_liblist_string_async = new vx_repl::Func_any_from_liblist_string_async();

  vx_core::Async<vx_core::Type_any*>* vx_repl::f_any_from_liblist_string_async(vx_repl::Type_liblist* liblist, vx_core::Type_string* text, vx_core::Type_context* context) {
    vx_core::Async<vx_core::Type_any*>* output = vx_core::async_new_from_val(vx_core::e_any);
    vx_core::f_let_async(
      vx_core::t_any,
      vx_core::t_any_from_func_async->fn_new([liblist, text, context]() {
        vx_repl::Type_repl* repl = vx_repl::f_repl_from_liblist_string(liblist, text);
        vx_core::Async<vx_core::Type_any*>* future_val = vx_repl::f_any_from_repl_async(repl, context);
        vx_core::Async<vx_core::Type_any*>* output = vx_core::Async<vx_core::Type_any*>::map<vx_core::Type_any*, vx_core::Type_any*>(vx_core::t_any, future_val, [](vx_core::Type_any* val) {
          return val;
        });
        return output;
      })
    );
    return output;
  }

  /**
   * @function any_from_repl
   * Run an arbitrary program in the REPL.
   * @param  {repl} repl
   * @return {any}
   * (func any<-repl)
   */
  //class Func_any_from_repl {

    template<class... Args> vx_repl::Func_any_from_repl* vx_repl::Func_any_from_repl::vx_new(Args*... args) {
      vx_repl::Func_any_from_repl* output;
      return output;
    }

    template<class... Args> vx_repl::Func_any_from_repl* vx_repl::Func_any_from_repl::vx_copy(Args*... args) {
      vx_repl::Func_any_from_repl* output;
      return output;
    }

    vx_core::Type_typedef* vx_repl::Func_any_from_repl::vx_typedef() {return vx_repl::t_any_from_repl->vx_typedef();}

    vx_core::Type_funcdef* vx_repl::Func_any_from_repl::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "any<-repl", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any", // name
          "", // extends
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

    vx_repl::Func_any_from_repl* vx_repl::Func_any_from_repl::vx_empty() {return vx_repl::e_any_from_repl;}
    vx_repl::Func_any_from_repl* vx_repl::Func_any_from_repl::vx_type() {return vx_repl::t_any_from_repl;}

    vx_core::Func_any_from_any_context* vx_repl::Func_any_from_repl::fn_new(vx_core::Func_any_from_any_context::IFn fn) {return vx_core::e_any_from_any_context;}

    template <class T, class U> T* vx_repl::Func_any_from_repl::f_any_from_any_context(T* generic_any_1, U* value, vx_core::Type_context* context) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_repl::Type_repl* inputval = (vx_repl::Type_repl)value;
      vx_core::Type_any* outputval = vx_repl::f_any_from_repl(inputval, context);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_repl::Func_any_from_repl::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_repl::Type_repl* repl = vx_core::f_any_from_any(vx_repl::t_repl, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_context* context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_repl::f_any_from_repl(repl, context);
      return output;
    }

    vx_core::Type_any* vx_repl::Func_any_from_repl::vx_any_from_repl(vx_repl::Type_repl* repl, vx_core::Type_context* context) {
      return vx_repl::f_any_from_repl(repl, context);
    }

  //}

  vx_repl::Func_any_from_repl* vx_repl::e_any_from_repl = new vx_repl::Func_any_from_repl();
  vx_repl::Func_any_from_repl* vx_repl::t_any_from_repl = new vx_repl::Func_any_from_repl();

  vx_core::Type_any* vx_repl::f_any_from_repl(vx_repl::Type_repl* repl, vx_core::Type_context* context) {
    vx_core::Type_any* output = vx_core::e_any;
    output = vx_core::f_let(
      vx_core::t_any,
      vx_core::t_any_from_func->fn_new([repl, context]() {
        vx_core::Type_any* val = repl->val();
        vx_core::Type_any* repltype = repl->type();
        vx_repl::Type_repllist* repllist = repl->repllist();
        vx_core::Type_anylist* args = vx_repl::f_anylist_from_repllist(repllist, context);
        return vx_core::f_if_2(
          vx_core::t_any,
          vx_core::t_thenelselist->vx_new(
            vx_core::f_then(
              vx_core::t_boolean_from_func->fn_new([val]() {
                return vx_core::f_notempty_1(val);
              }),
              vx_core::t_any_from_func->fn_new([val]() {
                return val;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->fn_new([repltype]() {
                return vx_core::f_is_func(repltype);
              }),
              vx_core::t_any_from_func->fn_new([repltype, args]() {
                return vx_repl::f_any_repl_from_functype_args(repltype, args);
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->fn_new([repltype, args]() {
                return vx_core::f_new(repltype, args);
              })
            )
          )
        );
      })
    );
    return output;
  }

  /**
   * 
   * @async
   * @function any_from_repl_async
   * Run an arbitrary program in the REPL.
   * @param  {repl} repl
   * @return {any}
   * (func any<-repl-async)
   */
  //class Func_any_from_repl_async {

    template<class... Args> vx_repl::Func_any_from_repl_async* vx_repl::Func_any_from_repl_async::vx_new(Args*... args) {
      vx_repl::Func_any_from_repl_async* output;
      return output;
    }

    template<class... Args> vx_repl::Func_any_from_repl_async* vx_repl::Func_any_from_repl_async::vx_copy(Args*... args) {
      vx_repl::Func_any_from_repl_async* output;
      return output;
    }

    vx_core::Type_typedef* vx_repl::Func_any_from_repl_async::vx_typedef() {return vx_repl::t_any_from_repl_async->vx_typedef();}

    vx_core::Type_funcdef* vx_repl::Func_any_from_repl_async::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "any<-repl-async", // name
        0, // idx
        true, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "any", // name
          "", // extends
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

    vx_repl::Func_any_from_repl_async* vx_repl::Func_any_from_repl_async::vx_empty() {return vx_repl::e_any_from_repl_async;}
    vx_repl::Func_any_from_repl_async* vx_repl::Func_any_from_repl_async::vx_type() {return vx_repl::t_any_from_repl_async;}

    vx_core::Func_any_from_any_context_async* vx_repl::Func_any_from_repl_async::fn_new(vx_core::Func_any_from_any_context_async::IFn fn) {return vx_core::e_any_from_any_context_async;}

    template <class T, class U> vx_core::Async<T*>* vx_repl::Func_any_from_repl_async::f_any_from_any_context_async(T* generic_any_1, U* value, vx_core::Type_context* context) {
      vx_repl::Type_repl* inputval = vx_core::f_any_from_any(vx_repl::t_repl, value);
      vx_core::Async<vx_core::Type_any*>* future = vx_repl::f_any_from_repl_async(inputval, context);
      vx_core::Async<T*>* output = (vx_core::Async<T*>)future;
      return output;
    }

    vx_core::Async<vx_core::Type_any*>* vx_repl::Func_any_from_repl_async::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Async<vx_core::Type_any*>* output = vx_core::async_new_from_val((vx_core::e_any);
      vx_repl::Type_repl* repl = vx_core::f_any_from_any(vx_repl::t_repl, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_context* context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Async<vx_core::Type_any*>* future = vx_repl::f_any_from_repl_async(repl, context);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    vx_core::Async<vx_core::Type_any*>* vx_repl::Func_any_from_repl_async::vx_any_from_repl_async(vx_repl::Type_repl* repl, vx_core::Type_context* context) {
      return vx_repl::f_any_from_repl_async(repl, context);
    }

  //}

  vx_repl::Func_any_from_repl_async* vx_repl::e_any_from_repl_async = new vx_repl::Func_any_from_repl_async();
  vx_repl::Func_any_from_repl_async* vx_repl::t_any_from_repl_async = new vx_repl::Func_any_from_repl_async();

  vx_core::Async<vx_core::Type_any*>* vx_repl::f_any_from_repl_async(vx_repl::Type_repl* repl, vx_core::Type_context* context) {
    vx_core::Async<vx_core::Type_any*>* output = vx_core::async_new_from_val(vx_core::e_any);
    return output;
  }

  /**
   * @function anylist_from_repllist
   * Run an arbitrary program in the REPL.
   * @param  {repllist} repllist
   * @return {anylist}
   * (func anylist<-repllist)
   */
  //class Func_anylist_from_repllist {

    template<class... Args> vx_repl::Func_anylist_from_repllist* vx_repl::Func_anylist_from_repllist::vx_new(Args*... args) {
      vx_repl::Func_anylist_from_repllist* output;
      return output;
    }

    template<class... Args> vx_repl::Func_anylist_from_repllist* vx_repl::Func_anylist_from_repllist::vx_copy(Args*... args) {
      vx_repl::Func_anylist_from_repllist* output;
      return output;
    }

    vx_core::Type_typedef* vx_repl::Func_anylist_from_repllist::vx_typedef() {return vx_repl::t_anylist_from_repllist->vx_typedef();}

    vx_core::Type_funcdef* vx_repl::Func_anylist_from_repllist::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "anylist<-repllist", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "anylist", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_core::t_any), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_repl::Func_anylist_from_repllist* vx_repl::Func_anylist_from_repllist::vx_empty() {return vx_repl::e_anylist_from_repllist;}
    vx_repl::Func_anylist_from_repllist* vx_repl::Func_anylist_from_repllist::vx_type() {return vx_repl::t_anylist_from_repllist;}

    vx_core::Func_any_from_any_context* vx_repl::Func_anylist_from_repllist::fn_new(vx_core::Func_any_from_any_context::IFn fn) {return vx_core::e_any_from_any_context;}

    template <class T, class U> T* vx_repl::Func_anylist_from_repllist::f_any_from_any_context(T* generic_any_1, U* value, vx_core::Type_context* context) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_repl::Type_repllist* inputval = (vx_repl::Type_repllist)value;
      vx_core::Type_any* outputval = vx_repl::f_anylist_from_repllist(inputval, context);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_repl::Func_anylist_from_repllist::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_repl::Type_repllist* repllist = vx_core::f_any_from_any(vx_repl::t_repllist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_context* context = vx_core::f_any_from_any(vx_core::t_context, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_repl::f_anylist_from_repllist(repllist, context);
      return output;
    }

    vx_core::Type_anylist* vx_repl::Func_anylist_from_repllist::vx_anylist_from_repllist(vx_repl::Type_repllist* repllist, vx_core::Type_context* context) {
      return vx_repl::f_anylist_from_repllist(repllist, context);
    }

  //}

  vx_repl::Func_anylist_from_repllist* vx_repl::e_anylist_from_repllist = new vx_repl::Func_anylist_from_repllist();
  vx_repl::Func_anylist_from_repllist* vx_repl::t_anylist_from_repllist = new vx_repl::Func_anylist_from_repllist();

  vx_core::Type_anylist* vx_repl::f_anylist_from_repllist(vx_repl::Type_repllist* repllist, vx_core::Type_context* context) {
    vx_core::Type_anylist* output = vx_core::e_anylist;
    output = vx_core::f_list_from_list(
      vx_core::t_anylist,
      repllist,
      vx_core::t_any_from_any->fn_new([context](vx_core::Type_any* repl_any) {
        vx_repl::Type_repl* repl = vx_core::f_any_from_any(vx_repl::t_repl, repl_any);
        return 
          vx_repl::f_any_from_repl(repl, context);
      })
    );
    return output;
  }

  /**
   * @function repl_from_liblist_string
   * Returns a repl from the given text.
   * @param  {liblist} liblist
   * @param  {string} text Program to run
   * @return {repl}
   * (func repl<-liblist-string)
   */
  //class Func_repl_from_liblist_string {

    template<class... Args> vx_repl::Func_repl_from_liblist_string* vx_repl::Func_repl_from_liblist_string::vx_new(Args*... args) {
      vx_repl::Func_repl_from_liblist_string* output;
      return output;
    }

    template<class... Args> vx_repl::Func_repl_from_liblist_string* vx_repl::Func_repl_from_liblist_string::vx_copy(Args*... args) {
      vx_repl::Func_repl_from_liblist_string* output;
      return output;
    }

    vx_core::Type_typedef* vx_repl::Func_repl_from_liblist_string::vx_typedef() {return vx_repl::t_repl_from_liblist_string->vx_typedef();}

    vx_core::Type_funcdef* vx_repl::Func_repl_from_liblist_string::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/repl", // pkgname
        "repl<-liblist-string", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/repl", // pkgname
          "repl", // name
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

    vx_repl::Func_repl_from_liblist_string* vx_repl::Func_repl_from_liblist_string::vx_empty() {return vx_repl::e_repl_from_liblist_string;}
    vx_repl::Func_repl_from_liblist_string* vx_repl::Func_repl_from_liblist_string::vx_type() {return vx_repl::t_repl_from_liblist_string;}

    vx_core::Type_any* vx_repl::Func_repl_from_liblist_string::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_repl::Type_liblist* liblist = vx_core::f_any_from_any(vx_repl::t_liblist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_string* text = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_repl::f_repl_from_liblist_string(liblist, text);
      return output;
    }

    vx_repl::Type_repl* vx_repl::Func_repl_from_liblist_string::vx_repl_from_liblist_string(vx_repl::Type_liblist* liblist, vx_core::Type_string* text) {
      return vx_repl::f_repl_from_liblist_string(liblist, text);
    }

  //}

  vx_repl::Func_repl_from_liblist_string* vx_repl::e_repl_from_liblist_string = new vx_repl::Func_repl_from_liblist_string();
  vx_repl::Func_repl_from_liblist_string* vx_repl::t_repl_from_liblist_string = new vx_repl::Func_repl_from_liblist_string();

  vx_repl::Type_repl* vx_repl::f_repl_from_liblist_string(vx_repl::Type_liblist* liblist, vx_core::Type_string* text) {
    vx_repl::Type_repl* output = vx_repl::e_repl;
    return output;
  }


//}
