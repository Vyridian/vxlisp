#include <any>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/type.hpp"
#include "vx/web/html.hpp"

//namespace vx_web_html {

  /**
   * type: body
   * Body Tag
   * (type body)
   */
  //class Type_body {
    // nodes()
    vx_web_html::Type_divchildlist* vx_web_html::Type_body::nodes() {
      vx_web_html::Type_divchildlist* output = this->vx_p_nodes;
      if (output == NULL) {
        output = vx_web_html::t_divchildlist;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_body::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":nodes") {
        output = this->nodes();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_body::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":nodes"] = this->nodes();
      return output;
    }

    template<typename... Args> vx_web_html::Type_body* vx_web_html::Type_body::vx_new(Args*... args) {return vx_web_html::e_body->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_body* vx_web_html::Type_body::vx_copy(Args*... args) {
      vx_web_html::Type_body* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_body* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_nodes = val->nodes();
      std::set<std::string> validkeys;
      validkeys.insert(":nodes");
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
          } else if (valsubtype == vx_web_html::t_divchildlist) { // default property
            output->vx_p_nodes = vx_core::any_from_any(vx_web_html::t_divchildlist, valsub);
          } else if (valsubtype == vx_web_html::t_divchild) { // default property
            vx_web_html::Type_divchild* valdefault = vx_core::any_from_any(vx_web_html::t_divchild, valsub);
            vx_web_html::Type_divchildlist* vallist = output->vx_p_nodes;
            if (vallist == null) {
              vallist = vx_web_html::t_divchildlist->vx_new(valdefault);
            } else {
              vallist = vallist->vx_copy(valdefault);
            }
            output->vx_p_nodes = vallist;
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new body) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":nodes") {
            if (valsubtype == vx_web_html::t_divchildlist) {
              output->vx_p_nodes = vx_core::any_from_any(vx_web_html::t_divchildlist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new body :nodes " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new body) - Invalid Key: " + key);
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

    vx_web_html::Type_body* vx_web_html::Type_body::vx_empty() {return vx_web_html::e_body;}
    vx_web_html::Type_body* vx_web_html::Type_body::vx_type() {return vx_web_html::t_body;}

    vx_core::Type_typedef* vx_web_html::Type_body::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "body", // name
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
   * type: details
   * Details Tag
   * (type details)
   */
  //class Type_details {
    // id()
    vx_core::Type_string* vx_web_html::Type_details::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // style()
    vx_web_html::Type_style* vx_web_html::Type_details::style() {
      vx_web_html::Type_style* output = this->vx_p_style;
      if (output == NULL) {
        output = vx_web_html::t_style;
      }
    }

    // summary()
    vx_web_html::Type_divchildlist* vx_web_html::Type_details::summary() {
      vx_web_html::Type_divchildlist* output = this->vx_p_summary;
      if (output == NULL) {
        output = vx_web_html::t_divchildlist;
      }
    }

    // nodes()
    vx_web_html::Type_divchildlist* vx_web_html::Type_details::nodes() {
      vx_web_html::Type_divchildlist* output = this->vx_p_nodes;
      if (output == NULL) {
        output = vx_web_html::t_divchildlist;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_details::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":summary") {
        output = this->summary();
      } else if (skey == ":nodes") {
        output = this->nodes();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_details::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":style"] = this->style();
      output[":summary"] = this->summary();
      output[":nodes"] = this->nodes();
      return output;
    }

    template<typename... Args> vx_web_html::Type_details* vx_web_html::Type_details::vx_new(Args*... args) {return vx_web_html::e_details->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_details* vx_web_html::Type_details::vx_copy(Args*... args) {
      vx_web_html::Type_details* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_details* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_style = val->style();
      output->vx_p_summary = val->summary();
      output->vx_p_nodes = val->nodes();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":style");
      validkeys.insert(":summary");
      validkeys.insert(":nodes");
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
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new details) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_id = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_id = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new details :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style) {
              output->vx_p_style = vx_core::any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new details :style " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":summary") {
            if (valsubtype == vx_web_html::t_divchildlist) {
              output->vx_p_summary = vx_core::any_from_any(vx_web_html::t_divchildlist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new details :summary " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":nodes") {
            if (valsubtype == vx_web_html::t_divchildlist) {
              output->vx_p_nodes = vx_core::any_from_any(vx_web_html::t_divchildlist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new details :nodes " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new details) - Invalid Key: " + key);
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

    vx_web_html::Type_details* vx_web_html::Type_details::vx_empty() {return vx_web_html::e_details;}
    vx_web_html::Type_details* vx_web_html::Type_details::vx_type() {return vx_web_html::t_details;}

    vx_core::Type_typedef* vx_web_html::Type_details::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "details", // name
        ":struct", // extends
        vx_core::t_typelist->vx_new(vx_web_html::t_node, vx_web_html::t_divchild), // traits
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
   * type: div
   * Div Tag
   * (type div)
   */
  //class Type_div {
    // id()
    vx_core::Type_string* vx_web_html::Type_div::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // style()
    vx_web_html::Type_style* vx_web_html::Type_div::style() {
      vx_web_html::Type_style* output = this->vx_p_style;
      if (output == NULL) {
        output = vx_web_html::t_style;
      }
    }

    // nodes()
    vx_web_html::Type_divchildlist* vx_web_html::Type_div::nodes() {
      vx_web_html::Type_divchildlist* output = this->vx_p_nodes;
      if (output == NULL) {
        output = vx_web_html::t_divchildlist;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_div::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":nodes") {
        output = this->nodes();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_div::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":style"] = this->style();
      output[":nodes"] = this->nodes();
      return output;
    }

    template<typename... Args> vx_web_html::Type_div* vx_web_html::Type_div::vx_new(Args*... args) {return vx_web_html::e_div->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_div* vx_web_html::Type_div::vx_copy(Args*... args) {
      vx_web_html::Type_div* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_div* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_style = val->style();
      output->vx_p_nodes = val->nodes();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":style");
      validkeys.insert(":nodes");
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
          } else if (valsubtype == vx_web_html::t_divchildlist) { // default property
            output->vx_p_nodes = vx_core::any_from_any(vx_web_html::t_divchildlist, valsub);
          } else if (valsubtype == vx_web_html::t_divchild) { // default property
            vx_web_html::Type_divchild* valdefault = vx_core::any_from_any(vx_web_html::t_divchild, valsub);
            vx_web_html::Type_divchildlist* vallist = output->vx_p_nodes;
            if (vallist == null) {
              vallist = vx_web_html::t_divchildlist->vx_new(valdefault);
            } else {
              vallist = vallist->vx_copy(valdefault);
            }
            output->vx_p_nodes = vallist;
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new div) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_id = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_id = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new div :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style) {
              output->vx_p_style = vx_core::any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new div :style " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":nodes") {
            if (valsubtype == vx_web_html::t_divchildlist) {
              output->vx_p_nodes = vx_core::any_from_any(vx_web_html::t_divchildlist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new div :nodes " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new div) - Invalid Key: " + key);
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

    vx_web_html::Type_div* vx_web_html::Type_div::vx_empty() {return vx_web_html::e_div;}
    vx_web_html::Type_div* vx_web_html::Type_div::vx_type() {return vx_web_html::t_div;}

    vx_core::Type_typedef* vx_web_html::Type_div::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "div", // name
        ":struct", // extends
        vx_core::t_typelist->vx_new(vx_web_html::t_node, vx_web_html::t_divchild), // traits
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
   * type: divchild
   * Div Child Trait
   * (type divchild)
   */
  //class Type_divchild {
    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_divchild::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_divchild::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      return output;
    }

    template<typename... Args> vx_web_html::Type_divchild* vx_web_html::Type_divchild::vx_new(Args*... args) {return vx_web_html::e_divchild->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_divchild* vx_web_html::Type_divchild::vx_copy(Args*... args) {
      vx_web_html::Type_divchild* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_divchild* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_web_html::Type_divchild* vx_web_html::Type_divchild::vx_empty() {return vx_web_html::e_divchild;}
    vx_web_html::Type_divchild* vx_web_html::Type_divchild::vx_type() {return vx_web_html::t_divchild;}

    vx_core::Type_typedef* vx_web_html::Type_divchild::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "divchild", // name
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
   * type: divchildlist
   * List of divchild
   * (type divchildlist)
   */
  //class Type_divchildlist {
    std::vector<vx_core::Type_any*> vx_web_html::Type_divchildlist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_web_html::Type_divchild* vx_web_html::Type_divchildlist::vx_divchild(vx_core::Type_int* index) {
      vx_web_html::Type_divchild* output = vx_web_html::e_divchild;
      vx_web_html::Type_divchildlist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_web_html::Type_divchild*> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_web_html::Type_divchild*> vx_web_html::Type_divchildlist::vx_listdivchild() {return vx_p_list;}

    vx_core::Type_any* vx_web_html::Type_divchildlist::vx_any(vx_core::Type_int* index) {
      return this->vx_divchild(index);
    }

    template<typename... Args> vx_web_html::Type_divchildlist* vx_web_html::Type_divchildlist::vx_new(Args*... args) {return vx_web_html::e_divchildlist->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_divchildlist* vx_web_html::Type_divchildlist::vx_copy(Args*... args) {
      vx_web_html::Type_divchildlist* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_web_html::Type_divchildlist* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_web_html::Type_divchild*> listval = val->vx_listdivchild();
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_web_html::t_divchild) {
          listval.push_back(vx_core::any_from_any(vx_web_html::t_divchild, valsub));
        } else if (valsubtype == vx_web_html::t_divchildlist) {
          vx_web_html::Type_divchildlist* multi = vx_core::any_from_any(vx_web_html::t_divchildlist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listdivchild());
        } else if (valsubtype == vx_core::t_nativelist) {
          std::vector<std::any*> listunknown = vx_core::any_from_any(std::vector<vx_core::Type_any*>, valsub);
          for (std::any* item : listunknown) {
            vx_core::Type_any* itemtype = vx_core::t_any->vx_type_from_any(item);
            if (itemtype == vx_web_html::t_divchild) {
              vx_web_html::Type_divchild* valitem = vx_core::any_from_any(vx_web_html::t_divchild, item);
              listval.push_back(valitem);
            }
          }
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new divchildlist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(msg);
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_web_html::Type_divchildlist* vx_web_html::Type_divchildlist::vx_empty() {return vx_web_html::e_divchildlist;}
    vx_web_html::Type_divchildlist* vx_web_html::Type_divchildlist::vx_type() {return vx_web_html::t_divchildlist;}

    vx_core::Type_typedef* vx_web_html::Type_divchildlist::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "divchildlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_web_html::t_divchild), // allowtypes
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
   * type: divlist
   * List of div
   * (type divlist)
   */
  //class Type_divlist {
    std::vector<vx_core::Type_any*> vx_web_html::Type_divlist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_web_html::Type_div* vx_web_html::Type_divlist::vx_div(vx_core::Type_int* index) {
      vx_web_html::Type_div* output = vx_web_html::e_div;
      vx_web_html::Type_divlist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_web_html::Type_div*> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_web_html::Type_div*> vx_web_html::Type_divlist::vx_listdiv() {return vx_p_list;}

    vx_core::Type_any* vx_web_html::Type_divlist::vx_any(vx_core::Type_int* index) {
      return this->vx_div(index);
    }

    template<typename... Args> vx_web_html::Type_divlist* vx_web_html::Type_divlist::vx_new(Args*... args) {return vx_web_html::e_divlist->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_divlist* vx_web_html::Type_divlist::vx_copy(Args*... args) {
      vx_web_html::Type_divlist* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_web_html::Type_divlist* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_web_html::Type_div*> listval = val->vx_listdiv();
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_web_html::t_div) {
          listval.push_back(vx_core::any_from_any(vx_web_html::t_div, valsub));
        } else if (valsubtype == vx_web_html::t_divlist) {
          vx_web_html::Type_divlist* multi = vx_core::any_from_any(vx_web_html::t_divlist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listdiv());
        } else if (valsubtype == vx_core::t_nativelist) {
          std::vector<std::any*> listunknown = vx_core::any_from_any(std::vector<vx_core::Type_any*>, valsub);
          for (std::any* item : listunknown) {
            vx_core::Type_any* itemtype = vx_core::t_any->vx_type_from_any(item);
            if (itemtype == vx_web_html::t_div) {
              vx_web_html::Type_div* valitem = vx_core::any_from_any(vx_web_html::t_div, item);
              listval.push_back(valitem);
            }
          }
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new divlist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(msg);
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_web_html::Type_divlist* vx_web_html::Type_divlist::vx_empty() {return vx_web_html::e_divlist;}
    vx_web_html::Type_divlist* vx_web_html::Type_divlist::vx_type() {return vx_web_html::t_divlist;}

    vx_core::Type_typedef* vx_web_html::Type_divlist::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "divlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_web_html::t_div), // allowtypes
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
   * type: footer
   * Body Tag
   * (type footer)
   */
  //class Type_footer {
    // nodes()
    vx_web_html::Type_divchildlist* vx_web_html::Type_footer::nodes() {
      vx_web_html::Type_divchildlist* output = this->vx_p_nodes;
      if (output == NULL) {
        output = vx_web_html::t_divchildlist;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_footer::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":nodes") {
        output = this->nodes();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_footer::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":nodes"] = this->nodes();
      return output;
    }

    template<typename... Args> vx_web_html::Type_footer* vx_web_html::Type_footer::vx_new(Args*... args) {return vx_web_html::e_footer->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_footer* vx_web_html::Type_footer::vx_copy(Args*... args) {
      vx_web_html::Type_footer* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_footer* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_nodes = val->nodes();
      std::set<std::string> validkeys;
      validkeys.insert(":nodes");
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
          } else if (valsubtype == vx_web_html::t_divchildlist) { // default property
            output->vx_p_nodes = vx_core::any_from_any(vx_web_html::t_divchildlist, valsub);
          } else if (valsubtype == vx_web_html::t_divchild) { // default property
            vx_web_html::Type_divchild* valdefault = vx_core::any_from_any(vx_web_html::t_divchild, valsub);
            vx_web_html::Type_divchildlist* vallist = output->vx_p_nodes;
            if (vallist == null) {
              vallist = vx_web_html::t_divchildlist->vx_new(valdefault);
            } else {
              vallist = vallist->vx_copy(valdefault);
            }
            output->vx_p_nodes = vallist;
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new footer) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":nodes") {
            if (valsubtype == vx_web_html::t_divchildlist) {
              output->vx_p_nodes = vx_core::any_from_any(vx_web_html::t_divchildlist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new footer :nodes " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new footer) - Invalid Key: " + key);
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

    vx_web_html::Type_footer* vx_web_html::Type_footer::vx_empty() {return vx_web_html::e_footer;}
    vx_web_html::Type_footer* vx_web_html::Type_footer::vx_type() {return vx_web_html::t_footer;}

    vx_core::Type_typedef* vx_web_html::Type_footer::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "footer", // name
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
   * type: h1
   * Header 1 Tag
   * (type h1)
   */
  //class Type_h1 {
    // id()
    vx_core::Type_string* vx_web_html::Type_h1::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // style()
    vx_web_html::Type_style* vx_web_html::Type_h1::style() {
      vx_web_html::Type_style* output = this->vx_p_style;
      if (output == NULL) {
        output = vx_web_html::t_style;
      }
    }

    // text()
    vx_core::Type_string* vx_web_html::Type_h1::text() {
      vx_core::Type_string* output = this->vx_p_text;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_h1::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":text") {
        output = this->text();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_h1::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":style"] = this->style();
      output[":text"] = this->text();
      return output;
    }

    template<typename... Args> vx_web_html::Type_h1* vx_web_html::Type_h1::vx_new(Args*... args) {return vx_web_html::e_h1->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_h1* vx_web_html::Type_h1::vx_copy(Args*... args) {
      vx_web_html::Type_h1* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_h1* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_style = val->style();
      output->vx_p_text = val->text();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":style");
      validkeys.insert(":text");
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
          } else if (valsubtype == vx_core::t_string) { // default property
            output->vx_p_text = vx_core::any_from_any(vx_core::t_string, valsub);
          } else if (valsubtype == vx_core::t_nativestring) { // default property
            output->vx_p_text = vx_core::t_string->vx_new(valsub);
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new h1) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_id = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_id = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new h1 :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style) {
              output->vx_p_style = vx_core::any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new h1 :style " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":text") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_text = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_text = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new h1 :text " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new h1) - Invalid Key: " + key);
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

    vx_web_html::Type_h1* vx_web_html::Type_h1::vx_empty() {return vx_web_html::e_h1;}
    vx_web_html::Type_h1* vx_web_html::Type_h1::vx_type() {return vx_web_html::t_h1;}

    vx_core::Type_typedef* vx_web_html::Type_h1::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "h1", // name
        ":struct", // extends
        vx_core::t_typelist->vx_new(vx_web_html::t_node, vx_web_html::t_divchild), // traits
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
   * type: h2
   * Header 2 Tag
   * (type h2)
   */
  //class Type_h2 {
    // id()
    vx_core::Type_string* vx_web_html::Type_h2::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // style()
    vx_web_html::Type_style* vx_web_html::Type_h2::style() {
      vx_web_html::Type_style* output = this->vx_p_style;
      if (output == NULL) {
        output = vx_web_html::t_style;
      }
    }

    // text()
    vx_core::Type_string* vx_web_html::Type_h2::text() {
      vx_core::Type_string* output = this->vx_p_text;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_h2::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":text") {
        output = this->text();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_h2::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":style"] = this->style();
      output[":text"] = this->text();
      return output;
    }

    template<typename... Args> vx_web_html::Type_h2* vx_web_html::Type_h2::vx_new(Args*... args) {return vx_web_html::e_h2->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_h2* vx_web_html::Type_h2::vx_copy(Args*... args) {
      vx_web_html::Type_h2* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_h2* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_style = val->style();
      output->vx_p_text = val->text();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":style");
      validkeys.insert(":text");
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
          } else if (valsubtype == vx_core::t_string) { // default property
            output->vx_p_text = vx_core::any_from_any(vx_core::t_string, valsub);
          } else if (valsubtype == vx_core::t_nativestring) { // default property
            output->vx_p_text = vx_core::t_string->vx_new(valsub);
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new h2) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_id = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_id = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new h2 :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style) {
              output->vx_p_style = vx_core::any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new h2 :style " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":text") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_text = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_text = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new h2 :text " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new h2) - Invalid Key: " + key);
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

    vx_web_html::Type_h2* vx_web_html::Type_h2::vx_empty() {return vx_web_html::e_h2;}
    vx_web_html::Type_h2* vx_web_html::Type_h2::vx_type() {return vx_web_html::t_h2;}

    vx_core::Type_typedef* vx_web_html::Type_h2::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "h2", // name
        ":struct", // extends
        vx_core::t_typelist->vx_new(vx_web_html::t_node, vx_web_html::t_divchild), // traits
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
   * type: h3
   * Header 3 Tag
   * (type h3)
   */
  //class Type_h3 {
    // id()
    vx_core::Type_string* vx_web_html::Type_h3::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // style()
    vx_web_html::Type_style* vx_web_html::Type_h3::style() {
      vx_web_html::Type_style* output = this->vx_p_style;
      if (output == NULL) {
        output = vx_web_html::t_style;
      }
    }

    // text()
    vx_core::Type_string* vx_web_html::Type_h3::text() {
      vx_core::Type_string* output = this->vx_p_text;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_h3::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":text") {
        output = this->text();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_h3::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":style"] = this->style();
      output[":text"] = this->text();
      return output;
    }

    template<typename... Args> vx_web_html::Type_h3* vx_web_html::Type_h3::vx_new(Args*... args) {return vx_web_html::e_h3->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_h3* vx_web_html::Type_h3::vx_copy(Args*... args) {
      vx_web_html::Type_h3* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_h3* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_style = val->style();
      output->vx_p_text = val->text();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":style");
      validkeys.insert(":text");
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
          } else if (valsubtype == vx_core::t_string) { // default property
            output->vx_p_text = vx_core::any_from_any(vx_core::t_string, valsub);
          } else if (valsubtype == vx_core::t_nativestring) { // default property
            output->vx_p_text = vx_core::t_string->vx_new(valsub);
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new h3) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_id = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_id = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new h3 :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style) {
              output->vx_p_style = vx_core::any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new h3 :style " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":text") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_text = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_text = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new h3 :text " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new h3) - Invalid Key: " + key);
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

    vx_web_html::Type_h3* vx_web_html::Type_h3::vx_empty() {return vx_web_html::e_h3;}
    vx_web_html::Type_h3* vx_web_html::Type_h3::vx_type() {return vx_web_html::t_h3;}

    vx_core::Type_typedef* vx_web_html::Type_h3::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "h3", // name
        ":struct", // extends
        vx_core::t_typelist->vx_new(vx_web_html::t_node, vx_web_html::t_divchild), // traits
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
   * type: head
   * Head Tag
   * (type head)
   */
  //class Type_head {
    // nodes()
    vx_web_html::Type_headchildlist* vx_web_html::Type_head::nodes() {
      vx_web_html::Type_headchildlist* output = this->vx_p_nodes;
      if (output == NULL) {
        output = vx_web_html::t_headchildlist;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_head::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":nodes") {
        output = this->nodes();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_head::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":nodes"] = this->nodes();
      return output;
    }

    template<typename... Args> vx_web_html::Type_head* vx_web_html::Type_head::vx_new(Args*... args) {return vx_web_html::e_head->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_head* vx_web_html::Type_head::vx_copy(Args*... args) {
      vx_web_html::Type_head* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_head* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_nodes = val->nodes();
      std::set<std::string> validkeys;
      validkeys.insert(":nodes");
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
          } else if (valsubtype == vx_web_html::t_headchildlist) { // default property
            output->vx_p_nodes = vx_core::any_from_any(vx_web_html::t_headchildlist, valsub);
          } else if (valsubtype == vx_web_html::t_headchild) { // default property
            vx_web_html::Type_headchild* valdefault = vx_core::any_from_any(vx_web_html::t_headchild, valsub);
            vx_web_html::Type_headchildlist* vallist = output->vx_p_nodes;
            if (vallist == null) {
              vallist = vx_web_html::t_headchildlist->vx_new(valdefault);
            } else {
              vallist = vallist->vx_copy(valdefault);
            }
            output->vx_p_nodes = vallist;
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new head) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":nodes") {
            if (valsubtype == vx_web_html::t_headchildlist) {
              output->vx_p_nodes = vx_core::any_from_any(vx_web_html::t_headchildlist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new head :nodes " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new head) - Invalid Key: " + key);
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

    vx_web_html::Type_head* vx_web_html::Type_head::vx_empty() {return vx_web_html::e_head;}
    vx_web_html::Type_head* vx_web_html::Type_head::vx_type() {return vx_web_html::t_head;}

    vx_core::Type_typedef* vx_web_html::Type_head::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "head", // name
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
   * type: headchild
   * Head Child Trait
   * (type headchild)
   */
  //class Type_headchild {
    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_headchild::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_headchild::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      return output;
    }

    template<typename... Args> vx_web_html::Type_headchild* vx_web_html::Type_headchild::vx_new(Args*... args) {return vx_web_html::e_headchild->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_headchild* vx_web_html::Type_headchild::vx_copy(Args*... args) {
      vx_web_html::Type_headchild* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_headchild* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_web_html::Type_headchild* vx_web_html::Type_headchild::vx_empty() {return vx_web_html::e_headchild;}
    vx_web_html::Type_headchild* vx_web_html::Type_headchild::vx_type() {return vx_web_html::t_headchild;}

    vx_core::Type_typedef* vx_web_html::Type_headchild::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "headchild", // name
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
   * type: headchildlist
   * List of headchild
   * (type headchildlist)
   */
  //class Type_headchildlist {
    std::vector<vx_core::Type_any*> vx_web_html::Type_headchildlist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_web_html::Type_headchild* vx_web_html::Type_headchildlist::vx_headchild(vx_core::Type_int* index) {
      vx_web_html::Type_headchild* output = vx_web_html::e_headchild;
      vx_web_html::Type_headchildlist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_web_html::Type_headchild*> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_web_html::Type_headchild*> vx_web_html::Type_headchildlist::vx_listheadchild() {return vx_p_list;}

    vx_core::Type_any* vx_web_html::Type_headchildlist::vx_any(vx_core::Type_int* index) {
      return this->vx_headchild(index);
    }

    template<typename... Args> vx_web_html::Type_headchildlist* vx_web_html::Type_headchildlist::vx_new(Args*... args) {return vx_web_html::e_headchildlist->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_headchildlist* vx_web_html::Type_headchildlist::vx_copy(Args*... args) {
      vx_web_html::Type_headchildlist* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_web_html::Type_headchildlist* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_web_html::Type_headchild*> listval = val->vx_listheadchild();
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_web_html::t_headchild) {
          listval.push_back(vx_core::any_from_any(vx_web_html::t_headchild, valsub));
        } else if (valsubtype == vx_web_html::t_headchildlist) {
          vx_web_html::Type_headchildlist* multi = vx_core::any_from_any(vx_web_html::t_headchildlist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listheadchild());
        } else if (valsubtype == vx_core::t_nativelist) {
          std::vector<std::any*> listunknown = vx_core::any_from_any(std::vector<vx_core::Type_any*>, valsub);
          for (std::any* item : listunknown) {
            vx_core::Type_any* itemtype = vx_core::t_any->vx_type_from_any(item);
            if (itemtype == vx_web_html::t_headchild) {
              vx_web_html::Type_headchild* valitem = vx_core::any_from_any(vx_web_html::t_headchild, item);
              listval.push_back(valitem);
            }
          }
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new headchildlist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(msg);
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_web_html::Type_headchildlist* vx_web_html::Type_headchildlist::vx_empty() {return vx_web_html::e_headchildlist;}
    vx_web_html::Type_headchildlist* vx_web_html::Type_headchildlist::vx_type() {return vx_web_html::t_headchildlist;}

    vx_core::Type_typedef* vx_web_html::Type_headchildlist::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "headchildlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_web_html::t_headchild), // allowtypes
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
   * type: html
   * Html Tag
   * (type html)
   */
  //class Type_html {
    // lang()
    vx_core::Type_string* vx_web_html::Type_html::lang() {
      vx_core::Type_string* output = this->vx_p_lang;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // head()
    vx_web_html::Type_head* vx_web_html::Type_html::head() {
      vx_web_html::Type_head* output = this->vx_p_head;
      if (output == NULL) {
        output = vx_web_html::t_head;
      }
    }

    // body()
    vx_web_html::Type_body* vx_web_html::Type_html::body() {
      vx_web_html::Type_body* output = this->vx_p_body;
      if (output == NULL) {
        output = vx_web_html::t_body;
      }
    }

    // footer()
    vx_web_html::Type_footer* vx_web_html::Type_html::footer() {
      vx_web_html::Type_footer* output = this->vx_p_footer;
      if (output == NULL) {
        output = vx_web_html::t_footer;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_html::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":lang") {
        output = this->lang();
      } else if (skey == ":head") {
        output = this->head();
      } else if (skey == ":body") {
        output = this->body();
      } else if (skey == ":footer") {
        output = this->footer();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_html::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":lang"] = this->lang();
      output[":head"] = this->head();
      output[":body"] = this->body();
      output[":footer"] = this->footer();
      return output;
    }

    template<typename... Args> vx_web_html::Type_html* vx_web_html::Type_html::vx_new(Args*... args) {return vx_web_html::e_html->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_html* vx_web_html::Type_html::vx_copy(Args*... args) {
      vx_web_html::Type_html* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_html* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_lang = val->lang();
      output->vx_p_head = val->head();
      output->vx_p_body = val->body();
      output->vx_p_footer = val->footer();
      std::set<std::string> validkeys;
      validkeys.insert(":lang");
      validkeys.insert(":head");
      validkeys.insert(":body");
      validkeys.insert(":footer");
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
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new html) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":lang") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_lang = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_lang = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new html :lang " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":head") {
            if (valsubtype == vx_web_html::t_head) {
              output->vx_p_head = vx_core::any_from_any(vx_web_html::t_head, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new html :head " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":body") {
            if (valsubtype == vx_web_html::t_body) {
              output->vx_p_body = vx_core::any_from_any(vx_web_html::t_body, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new html :body " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":footer") {
            if (valsubtype == vx_web_html::t_footer) {
              output->vx_p_footer = vx_core::any_from_any(vx_web_html::t_footer, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new html :footer " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new html) - Invalid Key: " + key);
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

    vx_web_html::Type_html* vx_web_html::Type_html::vx_empty() {return vx_web_html::e_html;}
    vx_web_html::Type_html* vx_web_html::Type_html::vx_type() {return vx_web_html::t_html;}

    vx_core::Type_typedef* vx_web_html::Type_html::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "html", // name
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
   * type: meta
   * Meta Tag
   * (type meta)
   */
  //class Type_meta {
    // id()
    vx_core::Type_string* vx_web_html::Type_meta::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // style()
    vx_web_html::Type_style* vx_web_html::Type_meta::style() {
      vx_web_html::Type_style* output = this->vx_p_style;
      if (output == NULL) {
        output = vx_web_html::t_style;
      }
    }

    // charset()
    vx_core::Type_string* vx_web_html::Type_meta::charset() {
      vx_core::Type_string* output = this->vx_p_charset;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_meta::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":charset") {
        output = this->charset();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_meta::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":style"] = this->style();
      output[":charset"] = this->charset();
      return output;
    }

    template<typename... Args> vx_web_html::Type_meta* vx_web_html::Type_meta::vx_new(Args*... args) {return vx_web_html::e_meta->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_meta* vx_web_html::Type_meta::vx_copy(Args*... args) {
      vx_web_html::Type_meta* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_meta* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_style = val->style();
      output->vx_p_charset = val->charset();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":style");
      validkeys.insert(":charset");
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
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new meta) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_id = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_id = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new meta :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style) {
              output->vx_p_style = vx_core::any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new meta :style " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":charset") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_charset = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_charset = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new meta :charset " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new meta) - Invalid Key: " + key);
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

    vx_web_html::Type_meta* vx_web_html::Type_meta::vx_empty() {return vx_web_html::e_meta;}
    vx_web_html::Type_meta* vx_web_html::Type_meta::vx_type() {return vx_web_html::t_meta;}

    vx_core::Type_typedef* vx_web_html::Type_meta::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "meta", // name
        ":struct", // extends
        vx_core::t_typelist->vx_new(vx_web_html::t_node, vx_web_html::t_headchild), // traits
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
   * type: node
   * Common Html Node Trait
   * (type node)
   */
  //class Type_node {
    // id()
    vx_core::Type_string* vx_web_html::Type_node::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // style()
    vx_web_html::Type_style* vx_web_html::Type_node::style() {
      vx_web_html::Type_style* output = this->vx_p_style;
      if (output == NULL) {
        output = vx_web_html::t_style;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_node::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_node::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":style"] = this->style();
      return output;
    }

    template<typename... Args> vx_web_html::Type_node* vx_web_html::Type_node::vx_new(Args*... args) {return vx_web_html::e_node->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_node* vx_web_html::Type_node::vx_copy(Args*... args) {
      vx_web_html::Type_node* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_node* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_style = val->style();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":style");
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
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new node) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_id = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_id = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new node :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style) {
              output->vx_p_style = vx_core::any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new node :style " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new node) - Invalid Key: " + key);
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

    vx_web_html::Type_node* vx_web_html::Type_node::vx_empty() {return vx_web_html::e_node;}
    vx_web_html::Type_node* vx_web_html::Type_node::vx_type() {return vx_web_html::t_node;}

    vx_core::Type_typedef* vx_web_html::Type_node::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "node", // name
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
   * type: nodelist
   * List of node
   * (type nodelist)
   */
  //class Type_nodelist {
    std::vector<vx_core::Type_any*> vx_web_html::Type_nodelist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_web_html::Type_node* vx_web_html::Type_nodelist::vx_node(vx_core::Type_int* index) {
      vx_web_html::Type_node* output = vx_web_html::e_node;
      vx_web_html::Type_nodelist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_web_html::Type_node*> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_web_html::Type_node*> vx_web_html::Type_nodelist::vx_listnode() {return vx_p_list;}

    vx_core::Type_any* vx_web_html::Type_nodelist::vx_any(vx_core::Type_int* index) {
      return this->vx_node(index);
    }

    template<typename... Args> vx_web_html::Type_nodelist* vx_web_html::Type_nodelist::vx_new(Args*... args) {return vx_web_html::e_nodelist->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_nodelist* vx_web_html::Type_nodelist::vx_copy(Args*... args) {
      vx_web_html::Type_nodelist* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_web_html::Type_nodelist* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_web_html::Type_node*> listval = val->vx_listnode();
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_web_html::t_node) {
          listval.push_back(vx_core::any_from_any(vx_web_html::t_node, valsub));
        } else if (valsubtype == vx_web_html::t_nodelist) {
          vx_web_html::Type_nodelist* multi = vx_core::any_from_any(vx_web_html::t_nodelist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listnode());
        } else if (valsubtype == vx_core::t_nativelist) {
          std::vector<std::any*> listunknown = vx_core::any_from_any(std::vector<vx_core::Type_any*>, valsub);
          for (std::any* item : listunknown) {
            vx_core::Type_any* itemtype = vx_core::t_any->vx_type_from_any(item);
            if (itemtype == vx_web_html::t_node) {
              vx_web_html::Type_node* valitem = vx_core::any_from_any(vx_web_html::t_node, item);
              listval.push_back(valitem);
            }
          }
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new nodelist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(msg);
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_web_html::Type_nodelist* vx_web_html::Type_nodelist::vx_empty() {return vx_web_html::e_nodelist;}
    vx_web_html::Type_nodelist* vx_web_html::Type_nodelist::vx_type() {return vx_web_html::t_nodelist;}

    vx_core::Type_typedef* vx_web_html::Type_nodelist::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "nodelist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_web_html::t_node), // allowtypes
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
   * type: p
   * Paragraph Tag
   * (type p)
   */
  //class Type_p {
    // id()
    vx_core::Type_string* vx_web_html::Type_p::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // style()
    vx_web_html::Type_style* vx_web_html::Type_p::style() {
      vx_web_html::Type_style* output = this->vx_p_style;
      if (output == NULL) {
        output = vx_web_html::t_style;
      }
    }

    // text()
    vx_core::Type_string* vx_web_html::Type_p::text() {
      vx_core::Type_string* output = this->vx_p_text;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_p::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":text") {
        output = this->text();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_p::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":style"] = this->style();
      output[":text"] = this->text();
      return output;
    }

    template<typename... Args> vx_web_html::Type_p* vx_web_html::Type_p::vx_new(Args*... args) {return vx_web_html::e_p->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_p* vx_web_html::Type_p::vx_copy(Args*... args) {
      vx_web_html::Type_p* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_p* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_style = val->style();
      output->vx_p_text = val->text();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":style");
      validkeys.insert(":text");
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
          } else if (valsubtype == vx_core::t_string) { // default property
            output->vx_p_text = vx_core::any_from_any(vx_core::t_string, valsub);
          } else if (valsubtype == vx_core::t_nativestring) { // default property
            output->vx_p_text = vx_core::t_string->vx_new(valsub);
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new p) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_id = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_id = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new p :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style) {
              output->vx_p_style = vx_core::any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new p :style " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":text") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_text = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_text = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new p :text " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new p) - Invalid Key: " + key);
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

    vx_web_html::Type_p* vx_web_html::Type_p::vx_empty() {return vx_web_html::e_p;}
    vx_web_html::Type_p* vx_web_html::Type_p::vx_type() {return vx_web_html::t_p;}

    vx_core::Type_typedef* vx_web_html::Type_p::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "p", // name
        ":struct", // extends
        vx_core::t_typelist->vx_new(vx_web_html::t_node, vx_web_html::t_divchild), // traits
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
   * type: propmap
   * Map of props
   * (type propmap)
   */
  //class Type_propmap {
    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_propmap::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_string(key)
    vx_core::Type_string* vx_web_html::Type_propmap::vx_string(vx_core::Type_string* key) {
      vx_core::Type_string* output = vx_core::e_string;
      vx_web_html::Type_propmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_string*> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_core::e_string);
      return output;
    }

    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_propmap::vx_any(vx_core::Type_string* key) {
      return this->vx_string(key);
    }

    // vx_mapstring()
    std::map<std::string, vx_core::Type_string*> vx_web_html::Type_propmap::vx_mapstring() {return vx_p_map;}

    // vx_new_from_map(mapval)
    vx_web_html::Type_propmap* vx_web_html::Type_propmap::vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval) {
      vx_web_html::Type_propmap* output;
      vx_core::Type_msgblock* msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_core::Type_string*> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any* val = iter.second;
        vx_core::Type_any* valtype = vx_core::t_any->vx_type_from_any(val);
        if (valtype == vx_core::t_string) {
          vx_core::Type_string* castval = vx_core::any_from_any(vx_core::t_string, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(propmap) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(msgblock, msg);
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template<typename... Args> vx_web_html::Type_propmap* vx_web_html::Type_propmap::vx_new(Args*... args) {return vx_web_html::e_propmap->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_propmap* vx_web_html::Type_propmap::vx_copy(Args*... args) {
      vx_web_html::Type_propmap* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_web_html::Type_propmap* valmap = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(valmap, vals);
      std::map<std::string, vx_core::Type_string*> mapval;
      std::string key = "";
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::t_msgblock->vx_copy(msgblock, valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::t_msgblock->vx_copy(msgblock, valsub);
        } else if (key == "") {
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string* valstring = vx_core::any_from_any(vx_core::t_string, valsub);
            key = valstring->vx_string();
          } else if (valsubtype == vx_core::t_nativestring) {
            key = vx_core_::any_from_any("", valsub);
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("Key Expected: " + vx_core::string_from_any(valsub) + "");
            msgblock = vx_core::t_msgblock->vx_copy(msgblock, msg);
          }
        } else {
          vx_core::Type_string* valany;
          if (valsubtype == vx_core::t_string) {
            valany = vx_core::any_from_any(vx_core::t_string, valsub);
          } else if (valsubtype == vx_core::t_string) {
            valany = vx_core::any_from_any(vx_core::t_string, valsub);
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("Invalid Key/Value: " + key + " "  + vx_core::string_from_any(valsub) + "");
            msgblock = vx_core::t_msgblock->vx_copy(msgblock, msg);
          }
          if (valany != NULL) {
            mapval[key] = valany;
            key = "";
          }
        }
      }
      output->vx_p_map = mapval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_web_html::Type_propmap* vx_web_html::Type_propmap::vx_empty() {return vx_web_html::e_propmap;}
    vx_web_html::Type_propmap* vx_web_html::Type_propmap::vx_type() {return vx_web_html::t_propmap;}

    vx_core::Type_typedef* vx_web_html::Type_propmap::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "propmap", // name
        ":map", // extends
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
   * type: style
   * Programmable Cascading Style
   * (type style)
   */
  //class Type_style {
    // name()
    vx_core::Type_string* vx_web_html::Type_style::name() {
      vx_core::Type_string* output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // props()
    vx_web_html::Type_propmap* vx_web_html::Type_style::props() {
      vx_web_html::Type_propmap* output = this->vx_p_props;
      if (output == NULL) {
        output = vx_web_html::t_propmap;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_style::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":props") {
        output = this->props();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_style::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":name"] = this->name();
      output[":props"] = this->props();
      return output;
    }

    template<typename... Args> vx_web_html::Type_style* vx_web_html::Type_style::vx_new(Args*... args) {return vx_web_html::e_style->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_style* vx_web_html::Type_style::vx_copy(Args*... args) {
      vx_web_html::Type_style* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_style* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_name = val->name();
      output->vx_p_props = val->props();
      std::set<std::string> validkeys;
      validkeys.insert(":name");
      validkeys.insert(":props");
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
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new style) - Invalid Key Type: " + vx_core::string_from_any(valsub));
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
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new style :name " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":props") {
            if (valsubtype == vx_web_html::t_propmap) {
              output->vx_p_props = vx_core::any_from_any(vx_web_html::t_propmap, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new style :props " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new style) - Invalid Key: " + key);
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

    vx_web_html::Type_style* vx_web_html::Type_style::vx_empty() {return vx_web_html::e_style;}
    vx_web_html::Type_style* vx_web_html::Type_style::vx_type() {return vx_web_html::t_style;}

    vx_core::Type_typedef* vx_web_html::Type_style::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "style", // name
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
   * type: stylelist
   * List of style
   * (type stylelist)
   */
  //class Type_stylelist {
    std::vector<vx_core::Type_any*> vx_web_html::Type_stylelist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_web_html::Type_style* vx_web_html::Type_stylelist::vx_style(vx_core::Type_int* index) {
      vx_web_html::Type_style* output = vx_web_html::e_style;
      vx_web_html::Type_stylelist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_web_html::Type_style*> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_web_html::Type_style*> vx_web_html::Type_stylelist::vx_liststyle() {return vx_p_list;}

    vx_core::Type_any* vx_web_html::Type_stylelist::vx_any(vx_core::Type_int* index) {
      return this->vx_style(index);
    }

    template<typename... Args> vx_web_html::Type_stylelist* vx_web_html::Type_stylelist::vx_new(Args*... args) {return vx_web_html::e_stylelist->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_stylelist* vx_web_html::Type_stylelist::vx_copy(Args*... args) {
      vx_web_html::Type_stylelist* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_web_html::Type_stylelist* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_web_html::Type_style*> listval = val->vx_liststyle();
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_web_html::t_style) {
          listval.push_back(vx_core::any_from_any(vx_web_html::t_style, valsub));
        } else if (valsubtype == vx_web_html::t_stylelist) {
          vx_web_html::Type_stylelist* multi = vx_core::any_from_any(vx_web_html::t_stylelist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_liststyle());
        } else if (valsubtype == vx_core::t_nativelist) {
          std::vector<std::any*> listunknown = vx_core::any_from_any(std::vector<vx_core::Type_any*>, valsub);
          for (std::any* item : listunknown) {
            vx_core::Type_any* itemtype = vx_core::t_any->vx_type_from_any(item);
            if (itemtype == vx_web_html::t_style) {
              vx_web_html::Type_style* valitem = vx_core::any_from_any(vx_web_html::t_style, item);
              listval.push_back(valitem);
            }
          }
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new stylelist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(msg);
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_web_html::Type_stylelist* vx_web_html::Type_stylelist::vx_empty() {return vx_web_html::e_stylelist;}
    vx_web_html::Type_stylelist* vx_web_html::Type_stylelist::vx_type() {return vx_web_html::t_stylelist;}

    vx_core::Type_typedef* vx_web_html::Type_stylelist::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "stylelist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_web_html::t_style), // allowtypes
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
   * type: stylemap
   * Map of style
   * (type stylemap)
   */
  //class Type_stylemap {
    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_stylemap::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_style(key)
    vx_web_html::Type_style* vx_web_html::Type_stylemap::vx_style(vx_core::Type_string* key) {
      vx_web_html::Type_style* output = vx_web_html::e_style;
      vx_web_html::Type_stylemap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_web_html::Type_style*> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_web_html::e_style);
      return output;
    }

    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_stylemap::vx_any(vx_core::Type_string* key) {
      return this->vx_style(key);
    }

    // vx_mapstyle()
    std::map<std::string, vx_web_html::Type_style*> vx_web_html::Type_stylemap::vx_mapstyle() {return vx_p_map;}

    // vx_new_from_map(mapval)
    vx_web_html::Type_stylemap* vx_web_html::Type_stylemap::vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval) {
      vx_web_html::Type_stylemap* output;
      vx_core::Type_msgblock* msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_web_html::Type_style*> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any* val = iter.second;
        vx_core::Type_any* valtype = vx_core::t_any->vx_type_from_any(val);
        if (valtype == vx_web_html::t_style) {
          vx_web_html::Type_style* castval = vx_core::any_from_any(vx_web_html::t_style, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(stylemap) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(msgblock, msg);
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template<typename... Args> vx_web_html::Type_stylemap* vx_web_html::Type_stylemap::vx_new(Args*... args) {return vx_web_html::e_stylemap->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_stylemap* vx_web_html::Type_stylemap::vx_copy(Args*... args) {
      vx_web_html::Type_stylemap* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_web_html::Type_stylemap* valmap = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(valmap, vals);
      std::map<std::string, vx_web_html::Type_style*> mapval;
      std::string key = "";
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::t_msgblock->vx_copy(msgblock, valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::t_msgblock->vx_copy(msgblock, valsub);
        } else if (key == "") {
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string* valstring = vx_core::any_from_any(vx_core::t_string, valsub);
            key = valstring->vx_string();
          } else if (valsubtype == vx_core::t_nativestring) {
            key = vx_core_::any_from_any("", valsub);
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("Key Expected: " + vx_core::string_from_any(valsub) + "");
            msgblock = vx_core::t_msgblock->vx_copy(msgblock, msg);
          }
        } else {
          vx_web_html::Type_style* valany;
          if (valsubtype == vx_web_html::t_style) {
            valany = vx_core::any_from_any(vx_web_html::t_style, valsub);
          } else if (valsubtype == vx_web_html::t_style) {
            valany = vx_core::any_from_any(vx_web_html::t_style, valsub);
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("Invalid Key/Value: " + key + " "  + vx_core::string_from_any(valsub) + "");
            msgblock = vx_core::t_msgblock->vx_copy(msgblock, msg);
          }
          if (valany != NULL) {
            mapval[key] = valany;
            key = "";
          }
        }
      }
      output->vx_p_map = mapval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_web_html::Type_stylemap* vx_web_html::Type_stylemap::vx_empty() {return vx_web_html::e_stylemap;}
    vx_web_html::Type_stylemap* vx_web_html::Type_stylemap::vx_type() {return vx_web_html::t_stylemap;}

    vx_core::Type_typedef* vx_web_html::Type_stylemap::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "stylemap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_web_html::t_style), // allowtypes
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
   * type: stylesheet
   * Programmable Cascading Style Sheet CSS type
   * (type stylesheet)
   */
  //class Type_stylesheet {
    // id()
    vx_core::Type_string* vx_web_html::Type_stylesheet::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // style()
    vx_web_html::Type_style* vx_web_html::Type_stylesheet::style() {
      vx_web_html::Type_style* output = this->vx_p_style;
      if (output == NULL) {
        output = vx_web_html::t_style;
      }
    }

    // name()
    vx_core::Type_string* vx_web_html::Type_stylesheet::name() {
      vx_core::Type_string* output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // styles()
    vx_web_html::Type_stylelist* vx_web_html::Type_stylesheet::styles() {
      vx_web_html::Type_stylelist* output = this->vx_p_styles;
      if (output == NULL) {
        output = vx_web_html::t_stylelist;
      }
    }

    // stylemap()
    vx_web_html::Type_stylemap* vx_web_html::Type_stylesheet::stylemap() {
      vx_web_html::Type_stylemap* output = this->vx_p_stylemap;
      if (output == NULL) {
        output = vx_web_html::t_stylemap;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_stylesheet::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":styles") {
        output = this->styles();
      } else if (skey == ":stylemap") {
        output = this->stylemap();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_stylesheet::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":style"] = this->style();
      output[":name"] = this->name();
      output[":styles"] = this->styles();
      output[":stylemap"] = this->stylemap();
      return output;
    }

    template<typename... Args> vx_web_html::Type_stylesheet* vx_web_html::Type_stylesheet::vx_new(Args*... args) {return vx_web_html::e_stylesheet->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_stylesheet* vx_web_html::Type_stylesheet::vx_copy(Args*... args) {
      vx_web_html::Type_stylesheet* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_stylesheet* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_style = val->style();
      output->vx_p_name = val->name();
      output->vx_p_styles = val->styles();
      output->vx_p_stylemap = val->stylemap();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":style");
      validkeys.insert(":name");
      validkeys.insert(":styles");
      validkeys.insert(":stylemap");
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
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new stylesheet) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_id = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_id = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new stylesheet :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style) {
              output->vx_p_style = vx_core::any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new stylesheet :style " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_name = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_name = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new stylesheet :name " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":styles") {
            if (valsubtype == vx_web_html::t_stylelist) {
              output->vx_p_styles = vx_core::any_from_any(vx_web_html::t_stylelist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new stylesheet :styles " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":stylemap") {
            if (valsubtype == vx_web_html::t_stylemap) {
              output->vx_p_stylemap = vx_core::any_from_any(vx_web_html::t_stylemap, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new stylesheet :stylemap " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new stylesheet) - Invalid Key: " + key);
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

    vx_web_html::Type_stylesheet* vx_web_html::Type_stylesheet::vx_empty() {return vx_web_html::e_stylesheet;}
    vx_web_html::Type_stylesheet* vx_web_html::Type_stylesheet::vx_type() {return vx_web_html::t_stylesheet;}

    vx_core::Type_typedef* vx_web_html::Type_stylesheet::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "stylesheet", // name
        ":struct", // extends
        vx_core::t_typelist->vx_new(vx_web_html::t_node, vx_web_html::t_headchild), // traits
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
   * type: table
   * <table> Tag
   * (type table)
   */
  //class Type_table {
    // id()
    vx_core::Type_string* vx_web_html::Type_table::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // style()
    vx_web_html::Type_style* vx_web_html::Type_table::style() {
      vx_web_html::Type_style* output = this->vx_p_style;
      if (output == NULL) {
        output = vx_web_html::t_style;
      }
    }

    // tbody()
    vx_web_html::Type_tbody* vx_web_html::Type_table::tbody() {
      vx_web_html::Type_tbody* output = this->vx_p_tbody;
      if (output == NULL) {
        output = vx_web_html::t_tbody;
      }
    }

    // thead()
    vx_web_html::Type_thead* vx_web_html::Type_table::thead() {
      vx_web_html::Type_thead* output = this->vx_p_thead;
      if (output == NULL) {
        output = vx_web_html::t_thead;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_table::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":tbody") {
        output = this->tbody();
      } else if (skey == ":thead") {
        output = this->thead();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_table::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":style"] = this->style();
      output[":tbody"] = this->tbody();
      output[":thead"] = this->thead();
      return output;
    }

    template<typename... Args> vx_web_html::Type_table* vx_web_html::Type_table::vx_new(Args*... args) {return vx_web_html::e_table->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_table* vx_web_html::Type_table::vx_copy(Args*... args) {
      vx_web_html::Type_table* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_table* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_style = val->style();
      output->vx_p_tbody = val->tbody();
      output->vx_p_thead = val->thead();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":style");
      validkeys.insert(":tbody");
      validkeys.insert(":thead");
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
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new table) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_id = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_id = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new table :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style) {
              output->vx_p_style = vx_core::any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new table :style " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":tbody") {
            if (valsubtype == vx_web_html::t_tbody) {
              output->vx_p_tbody = vx_core::any_from_any(vx_web_html::t_tbody, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new table :tbody " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":thead") {
            if (valsubtype == vx_web_html::t_thead) {
              output->vx_p_thead = vx_core::any_from_any(vx_web_html::t_thead, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new table :thead " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new table) - Invalid Key: " + key);
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

    vx_web_html::Type_table* vx_web_html::Type_table::vx_empty() {return vx_web_html::e_table;}
    vx_web_html::Type_table* vx_web_html::Type_table::vx_type() {return vx_web_html::t_table;}

    vx_core::Type_typedef* vx_web_html::Type_table::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "table", // name
        ":struct", // extends
        vx_core::t_typelist->vx_new(vx_web_html::t_node, vx_web_html::t_divchild), // traits
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
   * type: tbody
   * <tbody> Tag
   * (type tbody)
   */
  //class Type_tbody {
    // id()
    vx_core::Type_string* vx_web_html::Type_tbody::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // style()
    vx_web_html::Type_style* vx_web_html::Type_tbody::style() {
      vx_web_html::Type_style* output = this->vx_p_style;
      if (output == NULL) {
        output = vx_web_html::t_style;
      }
    }

    // nodes()
    vx_web_html::Type_trlist* vx_web_html::Type_tbody::nodes() {
      vx_web_html::Type_trlist* output = this->vx_p_nodes;
      if (output == NULL) {
        output = vx_web_html::t_trlist;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_tbody::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":nodes") {
        output = this->nodes();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_tbody::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":style"] = this->style();
      output[":nodes"] = this->nodes();
      return output;
    }

    template<typename... Args> vx_web_html::Type_tbody* vx_web_html::Type_tbody::vx_new(Args*... args) {return vx_web_html::e_tbody->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_tbody* vx_web_html::Type_tbody::vx_copy(Args*... args) {
      vx_web_html::Type_tbody* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_tbody* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_style = val->style();
      output->vx_p_nodes = val->nodes();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":style");
      validkeys.insert(":nodes");
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
          } else if (valsubtype == vx_web_html::t_trlist) { // default property
            output->vx_p_nodes = vx_core::any_from_any(vx_web_html::t_trlist, valsub);
          } else if (valsubtype == vx_web_html::t_tr) { // default property
            vx_web_html::Type_tr* valdefault = vx_core::any_from_any(vx_web_html::t_tr, valsub);
            vx_web_html::Type_trlist* vallist = output->vx_p_nodes;
            if (vallist == null) {
              vallist = vx_web_html::t_trlist->vx_new(valdefault);
            } else {
              vallist = vallist->vx_copy(valdefault);
            }
            output->vx_p_nodes = vallist;
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new tbody) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_id = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_id = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new tbody :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style) {
              output->vx_p_style = vx_core::any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new tbody :style " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":nodes") {
            if (valsubtype == vx_web_html::t_trlist) {
              output->vx_p_nodes = vx_core::any_from_any(vx_web_html::t_trlist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new tbody :nodes " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new tbody) - Invalid Key: " + key);
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

    vx_web_html::Type_tbody* vx_web_html::Type_tbody::vx_empty() {return vx_web_html::e_tbody;}
    vx_web_html::Type_tbody* vx_web_html::Type_tbody::vx_type() {return vx_web_html::t_tbody;}

    vx_core::Type_typedef* vx_web_html::Type_tbody::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "tbody", // name
        ":struct", // extends
        vx_core::t_typelist->vx_new(vx_web_html::t_node), // traits
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
   * type: td
   * <tr> Tag
   * (type td)
   */
  //class Type_td {
    // id()
    vx_core::Type_string* vx_web_html::Type_td::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // style()
    vx_web_html::Type_style* vx_web_html::Type_td::style() {
      vx_web_html::Type_style* output = this->vx_p_style;
      if (output == NULL) {
        output = vx_web_html::t_style;
      }
    }

    // nodes()
    vx_web_html::Type_divchildlist* vx_web_html::Type_td::nodes() {
      vx_web_html::Type_divchildlist* output = this->vx_p_nodes;
      if (output == NULL) {
        output = vx_web_html::t_divchildlist;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_td::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":nodes") {
        output = this->nodes();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_td::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":style"] = this->style();
      output[":nodes"] = this->nodes();
      return output;
    }

    template<typename... Args> vx_web_html::Type_td* vx_web_html::Type_td::vx_new(Args*... args) {return vx_web_html::e_td->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_td* vx_web_html::Type_td::vx_copy(Args*... args) {
      vx_web_html::Type_td* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_td* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_style = val->style();
      output->vx_p_nodes = val->nodes();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":style");
      validkeys.insert(":nodes");
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
          } else if (valsubtype == vx_web_html::t_divchildlist) { // default property
            output->vx_p_nodes = vx_core::any_from_any(vx_web_html::t_divchildlist, valsub);
          } else if (valsubtype == vx_web_html::t_divchild) { // default property
            vx_web_html::Type_divchild* valdefault = vx_core::any_from_any(vx_web_html::t_divchild, valsub);
            vx_web_html::Type_divchildlist* vallist = output->vx_p_nodes;
            if (vallist == null) {
              vallist = vx_web_html::t_divchildlist->vx_new(valdefault);
            } else {
              vallist = vallist->vx_copy(valdefault);
            }
            output->vx_p_nodes = vallist;
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new td) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_id = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_id = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new td :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style) {
              output->vx_p_style = vx_core::any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new td :style " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":nodes") {
            if (valsubtype == vx_web_html::t_divchildlist) {
              output->vx_p_nodes = vx_core::any_from_any(vx_web_html::t_divchildlist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new td :nodes " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new td) - Invalid Key: " + key);
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

    vx_web_html::Type_td* vx_web_html::Type_td::vx_empty() {return vx_web_html::e_td;}
    vx_web_html::Type_td* vx_web_html::Type_td::vx_type() {return vx_web_html::t_td;}

    vx_core::Type_typedef* vx_web_html::Type_td::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "td", // name
        ":struct", // extends
        vx_core::t_typelist->vx_new(vx_web_html::t_node), // traits
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
   * type: tdlist
   * List of td
   * (type tdlist)
   */
  //class Type_tdlist {
    std::vector<vx_core::Type_any*> vx_web_html::Type_tdlist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_web_html::Type_td* vx_web_html::Type_tdlist::vx_td(vx_core::Type_int* index) {
      vx_web_html::Type_td* output = vx_web_html::e_td;
      vx_web_html::Type_tdlist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_web_html::Type_td*> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_web_html::Type_td*> vx_web_html::Type_tdlist::vx_listtd() {return vx_p_list;}

    vx_core::Type_any* vx_web_html::Type_tdlist::vx_any(vx_core::Type_int* index) {
      return this->vx_td(index);
    }

    template<typename... Args> vx_web_html::Type_tdlist* vx_web_html::Type_tdlist::vx_new(Args*... args) {return vx_web_html::e_tdlist->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_tdlist* vx_web_html::Type_tdlist::vx_copy(Args*... args) {
      vx_web_html::Type_tdlist* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_web_html::Type_tdlist* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_web_html::Type_td*> listval = val->vx_listtd();
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_web_html::t_td) {
          listval.push_back(vx_core::any_from_any(vx_web_html::t_td, valsub));
        } else if (valsubtype == vx_web_html::t_tdlist) {
          vx_web_html::Type_tdlist* multi = vx_core::any_from_any(vx_web_html::t_tdlist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listtd());
        } else if (valsubtype == vx_core::t_nativelist) {
          std::vector<std::any*> listunknown = vx_core::any_from_any(std::vector<vx_core::Type_any*>, valsub);
          for (std::any* item : listunknown) {
            vx_core::Type_any* itemtype = vx_core::t_any->vx_type_from_any(item);
            if (itemtype == vx_web_html::t_td) {
              vx_web_html::Type_td* valitem = vx_core::any_from_any(vx_web_html::t_td, item);
              listval.push_back(valitem);
            }
          }
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new tdlist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(msg);
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_web_html::Type_tdlist* vx_web_html::Type_tdlist::vx_empty() {return vx_web_html::e_tdlist;}
    vx_web_html::Type_tdlist* vx_web_html::Type_tdlist::vx_type() {return vx_web_html::t_tdlist;}

    vx_core::Type_typedef* vx_web_html::Type_tdlist::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "tdlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_web_html::t_td), // allowtypes
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
   * type: thead
   * <thead> Tag
   * (type thead)
   */
  //class Type_thead {
    // id()
    vx_core::Type_string* vx_web_html::Type_thead::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // style()
    vx_web_html::Type_style* vx_web_html::Type_thead::style() {
      vx_web_html::Type_style* output = this->vx_p_style;
      if (output == NULL) {
        output = vx_web_html::t_style;
      }
    }

    // nodes()
    vx_web_html::Type_trlist* vx_web_html::Type_thead::nodes() {
      vx_web_html::Type_trlist* output = this->vx_p_nodes;
      if (output == NULL) {
        output = vx_web_html::t_trlist;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_thead::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":nodes") {
        output = this->nodes();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_thead::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":style"] = this->style();
      output[":nodes"] = this->nodes();
      return output;
    }

    template<typename... Args> vx_web_html::Type_thead* vx_web_html::Type_thead::vx_new(Args*... args) {return vx_web_html::e_thead->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_thead* vx_web_html::Type_thead::vx_copy(Args*... args) {
      vx_web_html::Type_thead* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_thead* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_style = val->style();
      output->vx_p_nodes = val->nodes();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":style");
      validkeys.insert(":nodes");
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
          } else if (valsubtype == vx_web_html::t_trlist) { // default property
            output->vx_p_nodes = vx_core::any_from_any(vx_web_html::t_trlist, valsub);
          } else if (valsubtype == vx_web_html::t_tr) { // default property
            vx_web_html::Type_tr* valdefault = vx_core::any_from_any(vx_web_html::t_tr, valsub);
            vx_web_html::Type_trlist* vallist = output->vx_p_nodes;
            if (vallist == null) {
              vallist = vx_web_html::t_trlist->vx_new(valdefault);
            } else {
              vallist = vallist->vx_copy(valdefault);
            }
            output->vx_p_nodes = vallist;
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new thead) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_id = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_id = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new thead :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style) {
              output->vx_p_style = vx_core::any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new thead :style " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":nodes") {
            if (valsubtype == vx_web_html::t_trlist) {
              output->vx_p_nodes = vx_core::any_from_any(vx_web_html::t_trlist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new thead :nodes " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new thead) - Invalid Key: " + key);
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

    vx_web_html::Type_thead* vx_web_html::Type_thead::vx_empty() {return vx_web_html::e_thead;}
    vx_web_html::Type_thead* vx_web_html::Type_thead::vx_type() {return vx_web_html::t_thead;}

    vx_core::Type_typedef* vx_web_html::Type_thead::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "thead", // name
        ":struct", // extends
        vx_core::t_typelist->vx_new(vx_web_html::t_node), // traits
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
   * type: title
   * Title Tag
   * (type title)
   */
  //class Type_title {
    // id()
    vx_core::Type_string* vx_web_html::Type_title::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // style()
    vx_web_html::Type_style* vx_web_html::Type_title::style() {
      vx_web_html::Type_style* output = this->vx_p_style;
      if (output == NULL) {
        output = vx_web_html::t_style;
      }
    }

    // text()
    vx_core::Type_string* vx_web_html::Type_title::text() {
      vx_core::Type_string* output = this->vx_p_text;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_title::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":text") {
        output = this->text();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_title::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":style"] = this->style();
      output[":text"] = this->text();
      return output;
    }

    template<typename... Args> vx_web_html::Type_title* vx_web_html::Type_title::vx_new(Args*... args) {return vx_web_html::e_title->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_title* vx_web_html::Type_title::vx_copy(Args*... args) {
      vx_web_html::Type_title* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_title* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_style = val->style();
      output->vx_p_text = val->text();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":style");
      validkeys.insert(":text");
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
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new title) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_id = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_id = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new title :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style) {
              output->vx_p_style = vx_core::any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new title :style " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":text") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_text = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_text = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new title :text " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new title) - Invalid Key: " + key);
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

    vx_web_html::Type_title* vx_web_html::Type_title::vx_empty() {return vx_web_html::e_title;}
    vx_web_html::Type_title* vx_web_html::Type_title::vx_type() {return vx_web_html::t_title;}

    vx_core::Type_typedef* vx_web_html::Type_title::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "title", // name
        ":struct", // extends
        vx_core::t_typelist->vx_new(vx_web_html::t_node, vx_web_html::t_headchild), // traits
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
   * type: tr
   * <tr> Tag
   * (type tr)
   */
  //class Type_tr {
    // id()
    vx_core::Type_string* vx_web_html::Type_tr::id() {
      vx_core::Type_string* output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::t_string;
      }
    }

    // style()
    vx_web_html::Type_style* vx_web_html::Type_tr::style() {
      vx_web_html::Type_style* output = this->vx_p_style;
      if (output == NULL) {
        output = vx_web_html::t_style;
      }
    }

    // nodes()
    vx_web_html::Type_tdlist* vx_web_html::Type_tr::nodes() {
      vx_web_html::Type_tdlist* output = this->vx_p_nodes;
      if (output == NULL) {
        output = vx_web_html::t_tdlist;
      }
    }

    // vx_any(key)
    vx_core::Type_any* vx_web_html::Type_tr::vx_any(vx_core::Type_string* key) {
      vx_core::Type_any* output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":nodes") {
        output = this->nodes();
      }
      return output;
    }

    // vx_map()
    std::map<std::string, vx_core::Type_any*> vx_web_html::Type_tr::vx_map() {
      std::map<std::string, vx_core::Type_any*> output;
      output[":id"] = this->id();
      output[":style"] = this->style();
      output[":nodes"] = this->nodes();
      return output;
    }

    template<typename... Args> vx_web_html::Type_tr* vx_web_html::Type_tr::vx_new(Args*... args) {return vx_web_html::e_tr->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_tr* vx_web_html::Type_tr::vx_copy(Args*... args) {
      vx_web_html::Type_tr* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      Type_tr* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      output->vx_p_id = val->id();
      output->vx_p_style = val->style();
      output->vx_p_nodes = val->nodes();
      std::set<std::string> validkeys;
      validkeys.insert(":id");
      validkeys.insert(":style");
      validkeys.insert(":nodes");
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
          } else if (valsubtype == vx_web_html::t_tdlist) { // default property
            output->vx_p_nodes = vx_core::any_from_any(vx_web_html::t_tdlist, valsub);
          } else if (valsubtype == vx_web_html::t_td) { // default property
            vx_web_html::Type_td* valdefault = vx_core::any_from_any(vx_web_html::t_td, valsub);
            vx_web_html::Type_tdlist* vallist = output->vx_p_nodes;
            if (vallist == null) {
              vallist = vx_web_html::t_tdlist->vx_new(valdefault);
            } else {
              vallist = vallist->vx_copy(valdefault);
            }
            output->vx_p_nodes = vallist;
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new tr) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(msg);
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_id = vx_core::any_from_any(vx_core::t_string, valsub);
            } else if (valsubtype == vx_core::t_nativestring) {
              output->vx_p_id = vx_core::t_string->vx_new(valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new tr :id " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style) {
              output->vx_p_style = vx_core::any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new tr :style " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else if (key == ":nodes") {
            if (valsubtype == vx_web_html::t_tdlist) {
              output->vx_p_nodes = vx_core::any_from_any(vx_web_html::t_tdlist, valsub);
            } else {
              vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new tr :nodes " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(msg);
            }
          } else {
            vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new tr) - Invalid Key: " + key);
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

    vx_web_html::Type_tr* vx_web_html::Type_tr::vx_empty() {return vx_web_html::e_tr;}
    vx_web_html::Type_tr* vx_web_html::Type_tr::vx_type() {return vx_web_html::t_tr;}

    vx_core::Type_typedef* vx_web_html::Type_tr::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "tr", // name
        ":struct", // extends
        vx_core::t_typelist->vx_new(vx_web_html::t_node), // traits
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
   * type: trlist
   * List of tr
   * (type trlist)
   */
  //class Type_trlist {
    std::vector<vx_core::Type_any*> vx_web_html::Type_trlist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_web_html::Type_tr* vx_web_html::Type_trlist::vx_tr(vx_core::Type_int* index) {
      vx_web_html::Type_tr* output = vx_web_html::e_tr;
      vx_web_html::Type_trlist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_web_html::Type_tr*> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_web_html::Type_tr*> vx_web_html::Type_trlist::vx_listtr() {return vx_p_list;}

    vx_core::Type_any* vx_web_html::Type_trlist::vx_any(vx_core::Type_int* index) {
      return this->vx_tr(index);
    }

    template<typename... Args> vx_web_html::Type_trlist* vx_web_html::Type_trlist::vx_new(Args*... args) {return vx_web_html::e_trlist->vx_copy(args...);}
    template<typename... Args> vx_web_html::Type_trlist* vx_web_html::Type_trlist::vx_copy(Args*... args) {
      vx_web_html::Type_trlist* output;
      const int size = sizeof...(args);
      const std::any vals[size];
      vx_web_html::Type_trlist* val = this;
      vx_core::Type_msgblock* msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val, vals);
      std::vector<vx_web_html::Type_tr*> listval = val->vx_listtr();
      for (std::any* valsub : vals) {
        vx_core::Type_any* valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(valsub);
        } else if (valsubtype == vx_web_html::t_tr) {
          listval.push_back(vx_core::any_from_any(vx_web_html::t_tr, valsub));
        } else if (valsubtype == vx_web_html::t_trlist) {
          vx_web_html::Type_trlist* multi = vx_core::any_from_any(vx_web_html::t_trlist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listtr());
        } else if (valsubtype == vx_core::t_nativelist) {
          std::vector<std::any*> listunknown = vx_core::any_from_any(std::vector<vx_core::Type_any*>, valsub);
          for (std::any* item : listunknown) {
            vx_core::Type_any* itemtype = vx_core::t_any->vx_type_from_any(item);
            if (itemtype == vx_web_html::t_tr) {
              vx_web_html::Type_tr* valitem = vx_core::any_from_any(vx_web_html::t_tr, item);
              listval.push_back(valitem);
            }
          }
        } else {
          vx_core::Type_msg* msg = vx_core::t_msg->vx_new_error("(new trlist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(msg);
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_web_html::Type_trlist* vx_web_html::Type_trlist::vx_empty() {return vx_web_html::e_trlist;}
    vx_web_html::Type_trlist* vx_web_html::Type_trlist::vx_type() {return vx_web_html::t_trlist;}

    vx_core::Type_typedef* vx_web_html::Type_trlist::vx_typedef() {
      return vx_core::Type_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "trlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_web_html::t_tr), // allowtypes
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
   * @function boolean_write_from_id_htmltext
   * Writes to an html node with given id and text.
   * @param  {string} id
   * @param  {string} htmltext
   * @return {boolean}
   * (func boolean-write<-id-htmltext)
   */
  //class Func_boolean_write_from_id_htmltext {

    template<typename... Args> vx_web_html::Func_boolean_write_from_id_htmltext* vx_web_html::Func_boolean_write_from_id_htmltext::vx_new(Args*... args) {
      vx_web_html::Func_boolean_write_from_id_htmltext* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_boolean_write_from_id_htmltext* vx_web_html::Func_boolean_write_from_id_htmltext::vx_copy(Args*... args) {
      vx_web_html::Func_boolean_write_from_id_htmltext* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_boolean_write_from_id_htmltext::vx_typedef() {return vx_web_html::t_boolean_write_from_id_htmltext->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_boolean_write_from_id_htmltext::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "boolean-write<-id-htmltext", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "boolean", // name
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

    vx_web_html::Func_boolean_write_from_id_htmltext* vx_web_html::Func_boolean_write_from_id_htmltext::vx_empty() {return vx_web_html::e_boolean_write_from_id_htmltext;}
    vx_web_html::Func_boolean_write_from_id_htmltext* vx_web_html::Func_boolean_write_from_id_htmltext::vx_type() {return vx_web_html::t_boolean_write_from_id_htmltext;}

    vx_core::Type_any* vx_web_html::Func_boolean_write_from_id_htmltext::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_string* id = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_string* htmltext = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_boolean_write_from_id_htmltext(id, htmltext);
      return output;
    }

    vx_core::Type_boolean* vx_web_html::Func_boolean_write_from_id_htmltext::vx_boolean_write_from_id_htmltext(vx_core::Type_string* id, vx_core::Type_string* htmltext) {
      return vx_web_html::f_boolean_write_from_id_htmltext(id, htmltext);
    }

  //}

  vx_web_html::Func_boolean_write_from_id_htmltext* vx_web_html::e_boolean_write_from_id_htmltext = new vx_web_html::Func_boolean_write_from_id_htmltext();
  vx_web_html::Func_boolean_write_from_id_htmltext* vx_web_html::t_boolean_write_from_id_htmltext = new vx_web_html::Func_boolean_write_from_id_htmltext();

  vx_core::Type_boolean* vx_web_html::f_boolean_write_from_id_htmltext(vx_core::Type_string* id, vx_core::Type_string* htmltext) {
    vx_core::Type_boolean* output = vx_core::e_boolean;
    return output;
  }

  /**
   * 
   * @async
   * @function boolean_write_from_stylesheet
   * Writes to an html node with given id and text.
   * @param  {stylesheet} stylesheet
   * @return {boolean}
   * (func boolean-write<-stylesheet)
   */
  //class Func_boolean_write_from_stylesheet {

    template<typename... Args> vx_web_html::Func_boolean_write_from_stylesheet* vx_web_html::Func_boolean_write_from_stylesheet::vx_new(Args*... args) {
      vx_web_html::Func_boolean_write_from_stylesheet* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_boolean_write_from_stylesheet* vx_web_html::Func_boolean_write_from_stylesheet::vx_copy(Args*... args) {
      vx_web_html::Func_boolean_write_from_stylesheet* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_boolean_write_from_stylesheet::vx_typedef() {return vx_web_html::t_boolean_write_from_stylesheet->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_boolean_write_from_stylesheet::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "boolean-write<-stylesheet", // name
        0, // idx
        true, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "boolean", // name
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

    vx_web_html::Func_boolean_write_from_stylesheet* vx_web_html::Func_boolean_write_from_stylesheet::vx_empty() {return vx_web_html::e_boolean_write_from_stylesheet;}
    vx_web_html::Func_boolean_write_from_stylesheet* vx_web_html::Func_boolean_write_from_stylesheet::vx_type() {return vx_web_html::t_boolean_write_from_stylesheet;}

    vx_core::Func_any_from_any_async* vx_web_html::Func_boolean_write_from_stylesheet::fn_new(vx_core::Func_any_from_any_async::IFn fn) {return vx_core::e_any_from_any_async;}

    template <class T, class U> vx_core::Async<T*>* vx_web_html::Func_boolean_write_from_stylesheet::f_any_from_any_async(T* generic_any_1, U* value) {
      vx_web_html::Type_stylesheet* inputval = vx_core::f_any_from_any(vx_web_html::t_stylesheet, value);
      vx_core::Async<vx_core::Type_boolean*>* future = vx_web_html::f_boolean_write_from_stylesheet(inputval);
      vx_core::Async<T*>* output = (vx_core::Async<T*>)future;
      return output;
    }

    vx_core::Async<vx_core::Type_any*>* vx_web_html::Func_boolean_write_from_stylesheet::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Async<vx_core::Type_any*>* output = vx_core::async_new_from_val((vx_core::e_any);
      vx_web_html::Type_stylesheet* stylesheet = vx_core::f_any_from_any(vx_web_html::t_stylesheet, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Async<vx_core::Type_boolean*>* future = vx_web_html::f_boolean_write_from_stylesheet(stylesheet);
      output = vx_core::async_from_async(vx_core::t_any, future);
      return output;
    }

    vx_core::Async<vx_core::Type_boolean*>* vx_web_html::Func_boolean_write_from_stylesheet::vx_boolean_write_from_stylesheet(vx_web_html::Type_stylesheet* stylesheet) {
      return vx_web_html::f_boolean_write_from_stylesheet(stylesheet);
    }

  //}

  vx_web_html::Func_boolean_write_from_stylesheet* vx_web_html::e_boolean_write_from_stylesheet = new vx_web_html::Func_boolean_write_from_stylesheet();
  vx_web_html::Func_boolean_write_from_stylesheet* vx_web_html::t_boolean_write_from_stylesheet = new vx_web_html::Func_boolean_write_from_stylesheet();

  vx_core::Async<vx_core::Type_boolean*>* vx_web_html::f_boolean_write_from_stylesheet(vx_web_html::Type_stylesheet* stylesheet) {
    vx_core::Async<vx_core::Type_boolean*>* output = vx_core::async_new_from_val(vx_core::e_boolean);
    return output;
  }

  /**
   * @function htmlstring_from_string
   * Convert text to HTML string
   * @param  {string} text
   * @return {string}
   * (func htmlstring<-string)
   */
  //class Func_htmlstring_from_string {

    template<typename... Args> vx_web_html::Func_htmlstring_from_string* vx_web_html::Func_htmlstring_from_string::vx_new(Args*... args) {
      vx_web_html::Func_htmlstring_from_string* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_htmlstring_from_string* vx_web_html::Func_htmlstring_from_string::vx_copy(Args*... args) {
      vx_web_html::Func_htmlstring_from_string* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_htmlstring_from_string::vx_typedef() {return vx_web_html::t_htmlstring_from_string->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_htmlstring_from_string::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "htmlstring<-string", // name
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

    vx_web_html::Func_htmlstring_from_string* vx_web_html::Func_htmlstring_from_string::vx_empty() {return vx_web_html::e_htmlstring_from_string;}
    vx_web_html::Func_htmlstring_from_string* vx_web_html::Func_htmlstring_from_string::vx_type() {return vx_web_html::t_htmlstring_from_string;}

    vx_core::Func_any_from_any* vx_web_html::Func_htmlstring_from_string::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_web_html::Func_htmlstring_from_string::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_core::Type_string* inputval = (vx_core::Type_string)value;
      vx_core::Type_any* outputval = vx_web_html::f_htmlstring_from_string(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_web_html::Func_htmlstring_from_string::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_string* text = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_web_html::f_htmlstring_from_string(text);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_htmlstring_from_string::vx_htmlstring_from_string(vx_core::Type_string* text) {
      return vx_web_html::f_htmlstring_from_string(text);
    }

  //}

  vx_web_html::Func_htmlstring_from_string* vx_web_html::e_htmlstring_from_string = new vx_web_html::Func_htmlstring_from_string();
  vx_web_html::Func_htmlstring_from_string* vx_web_html::t_htmlstring_from_string = new vx_web_html::Func_htmlstring_from_string();

  vx_core::Type_string* vx_web_html::f_htmlstring_from_string(vx_core::Type_string* text) {
    vx_core::Type_string* output = vx_core::e_string;
    return output;
  }

  /**
   * @function string_indent
   * @param  {int} indent
   * @return {string}
   * (func string-indent)
   */
  //class Func_string_indent {

    template<typename... Args> vx_web_html::Func_string_indent* vx_web_html::Func_string_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_indent* vx_web_html::Func_string_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_indent::vx_typedef() {return vx_web_html::t_string_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string-indent", // name
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

    vx_web_html::Func_string_indent* vx_web_html::Func_string_indent::vx_empty() {return vx_web_html::e_string_indent;}
    vx_web_html::Func_string_indent* vx_web_html::Func_string_indent::vx_type() {return vx_web_html::t_string_indent;}

    vx_core::Func_any_from_any* vx_web_html::Func_string_indent::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_web_html::Func_string_indent::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_core::Type_int* inputval = (vx_core::Type_int)value;
      vx_core::Type_any* outputval = vx_web_html::f_string_indent(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_web_html::Func_string_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_web_html::f_string_indent(indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_indent::vx_string_indent(vx_core::Type_int* indent) {
      return vx_web_html::f_string_indent(indent);
    }

  //}

  vx_web_html::Func_string_indent* vx_web_html::e_string_indent = new vx_web_html::Func_string_indent();
  vx_web_html::Func_string_indent* vx_web_html::t_string_indent = new vx_web_html::Func_string_indent();

  vx_core::Type_string* vx_web_html::f_string_indent(vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_string_repeat(vx_core::t_string->vx_new_from_string("  "), indent);
    return output;
  }

  /**
   * @function string_from_body_indent
   * Returns string from body
   * @param  {body} body
   * @param  {int} indent
   * @return {string}
   * (func string<-body-indent)
   */
  //class Func_string_from_body_indent {

    template<typename... Args> vx_web_html::Func_string_from_body_indent* vx_web_html::Func_string_from_body_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_body_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_body_indent* vx_web_html::Func_string_from_body_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_body_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_body_indent::vx_typedef() {return vx_web_html::t_string_from_body_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_body_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-body-indent", // name
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

    vx_web_html::Func_string_from_body_indent* vx_web_html::Func_string_from_body_indent::vx_empty() {return vx_web_html::e_string_from_body_indent;}
    vx_web_html::Func_string_from_body_indent* vx_web_html::Func_string_from_body_indent::vx_type() {return vx_web_html::t_string_from_body_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_body_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_body* body = vx_core::f_any_from_any(vx_web_html::t_body, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_body_indent(body, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_body_indent::vx_string_from_body_indent(vx_web_html::Type_body* body, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_body_indent(body, indent);
    }

  //}

  vx_web_html::Func_string_from_body_indent* vx_web_html::e_string_from_body_indent = new vx_web_html::Func_string_from_body_indent();
  vx_web_html::Func_string_from_body_indent* vx_web_html::t_string_from_body_indent = new vx_web_html::Func_string_from_body_indent();

  vx_core::Type_string* vx_web_html::f_string_from_body_indent(vx_web_html::Type_body* body, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([body, indent]() {
        vx_web_html::Type_divchildlist* nodes = body->nodes();
        return vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, vx_core::t_string->vx_new_from_string("body"), vx_core::t_string->vx_new_from_string(""), indent);
      })
    );
    return output;
  }

  /**
   * @function string_from_details_indent
   * Returns string from details
   * @param  {details} details
   * @param  {int} indent
   * @return {string}
   * (func string<-details-indent)
   */
  //class Func_string_from_details_indent {

    template<typename... Args> vx_web_html::Func_string_from_details_indent* vx_web_html::Func_string_from_details_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_details_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_details_indent* vx_web_html::Func_string_from_details_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_details_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_details_indent::vx_typedef() {return vx_web_html::t_string_from_details_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_details_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-details-indent", // name
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

    vx_web_html::Func_string_from_details_indent* vx_web_html::Func_string_from_details_indent::vx_empty() {return vx_web_html::e_string_from_details_indent;}
    vx_web_html::Func_string_from_details_indent* vx_web_html::Func_string_from_details_indent::vx_type() {return vx_web_html::t_string_from_details_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_details_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_details* details = vx_core::f_any_from_any(vx_web_html::t_details, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_details_indent(details, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_details_indent::vx_string_from_details_indent(vx_web_html::Type_details* details, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_details_indent(details, indent);
    }

  //}

  vx_web_html::Func_string_from_details_indent* vx_web_html::e_string_from_details_indent = new vx_web_html::Func_string_from_details_indent();
  vx_web_html::Func_string_from_details_indent* vx_web_html::t_string_from_details_indent = new vx_web_html::Func_string_from_details_indent();

  vx_core::Type_string* vx_web_html::f_string_from_details_indent(vx_web_html::Type_details* details, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([indent, details]() {
        vx_core::Type_string* sindent = vx_web_html::f_string_from_indent(indent);
        vx_web_html::Type_divchildlist* summary = details->summary();
        vx_web_html::Type_divchildlist* nodes = details->nodes();
        vx_core::Type_string* ssummary = vx_web_html::f_string_from_nodelist_indent(
          summary,
          vx_core::f_plus(indent, vx_core::t_int->vx_new_from_int(2))
        );
        vx_core::Type_string* snodes = vx_web_html::f_string_from_nodelist_indent(
          nodes,
          vx_core::f_plus(indent, vx_core::t_int->vx_new_from_int(1))
        );
        return vx_core::f_new(
          vx_core::t_string,
          vx_core::t_anylist->vx_new(
            sindent,
            vx_core::t_string->vx_new_from_string("<details>"),
            sindent,
            vx_core::t_string->vx_new_from_string("  <summary>"),
            ssummary,
            sindent,
            vx_core::t_string->vx_new_from_string("  </summary>"),
            snodes,
            sindent,
            vx_core::t_string->vx_new_from_string("</details>")
          )
        );
      })
    );
    return output;
  }

  /**
   * @function string_from_div_indent
   * Returns string from div
   * @param  {div} div
   * @param  {int} indent
   * @return {string}
   * (func string<-div-indent)
   */
  //class Func_string_from_div_indent {

    template<typename... Args> vx_web_html::Func_string_from_div_indent* vx_web_html::Func_string_from_div_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_div_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_div_indent* vx_web_html::Func_string_from_div_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_div_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_div_indent::vx_typedef() {return vx_web_html::t_string_from_div_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_div_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-div-indent", // name
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

    vx_web_html::Func_string_from_div_indent* vx_web_html::Func_string_from_div_indent::vx_empty() {return vx_web_html::e_string_from_div_indent;}
    vx_web_html::Func_string_from_div_indent* vx_web_html::Func_string_from_div_indent::vx_type() {return vx_web_html::t_string_from_div_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_div_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_div* div = vx_core::f_any_from_any(vx_web_html::t_div, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_div_indent(div, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_div_indent::vx_string_from_div_indent(vx_web_html::Type_div* div, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_div_indent(div, indent);
    }

  //}

  vx_web_html::Func_string_from_div_indent* vx_web_html::e_string_from_div_indent = new vx_web_html::Func_string_from_div_indent();
  vx_web_html::Func_string_from_div_indent* vx_web_html::t_string_from_div_indent = new vx_web_html::Func_string_from_div_indent();

  vx_core::Type_string* vx_web_html::f_string_from_div_indent(vx_web_html::Type_div* div, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([div, indent]() {
        vx_web_html::Type_divchildlist* nodes = div->nodes();
        vx_core::Type_string* sid = vx_web_html::f_string_from_propname_val(
          vx_core::t_string->vx_new_from_string("id"),
          div->id()
        );
        vx_core::Type_string* sstyle = vx_web_html::f_string_from_propstyle(
          div->style()
        );
        return vx_web_html::f_string_from_nodelist_tag_prop_indent(
          nodes,
          vx_core::t_string->vx_new_from_string("div"),
          vx_core::f_new(
            vx_core::t_string,
            vx_core::t_anylist->vx_new(
              sid,
              sstyle
            )
          ),
          indent
        );
      })
    );
    return output;
  }

  /**
   * @function string_from_footer_indent
   * Returns string from footer
   * @param  {footer} footer
   * @param  {int} indent
   * @return {string}
   * (func string<-footer-indent)
   */
  //class Func_string_from_footer_indent {

    template<typename... Args> vx_web_html::Func_string_from_footer_indent* vx_web_html::Func_string_from_footer_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_footer_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_footer_indent* vx_web_html::Func_string_from_footer_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_footer_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_footer_indent::vx_typedef() {return vx_web_html::t_string_from_footer_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_footer_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-footer-indent", // name
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

    vx_web_html::Func_string_from_footer_indent* vx_web_html::Func_string_from_footer_indent::vx_empty() {return vx_web_html::e_string_from_footer_indent;}
    vx_web_html::Func_string_from_footer_indent* vx_web_html::Func_string_from_footer_indent::vx_type() {return vx_web_html::t_string_from_footer_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_footer_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_footer* footer = vx_core::f_any_from_any(vx_web_html::t_footer, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_footer_indent(footer, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_footer_indent::vx_string_from_footer_indent(vx_web_html::Type_footer* footer, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_footer_indent(footer, indent);
    }

  //}

  vx_web_html::Func_string_from_footer_indent* vx_web_html::e_string_from_footer_indent = new vx_web_html::Func_string_from_footer_indent();
  vx_web_html::Func_string_from_footer_indent* vx_web_html::t_string_from_footer_indent = new vx_web_html::Func_string_from_footer_indent();

  vx_core::Type_string* vx_web_html::f_string_from_footer_indent(vx_web_html::Type_footer* footer, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([footer, indent]() {
        vx_web_html::Type_divchildlist* nodes = footer->nodes();
        return vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, vx_core::t_string->vx_new_from_string("footer"), vx_core::t_string->vx_new_from_string(""), indent);
      })
    );
    return output;
  }

  /**
   * @function string_from_h1_indent
   * Returns string from h1
   * @param  {h1} h1
   * @param  {int} indent
   * @return {string}
   * (func string<-h1-indent)
   */
  //class Func_string_from_h1_indent {

    template<typename... Args> vx_web_html::Func_string_from_h1_indent* vx_web_html::Func_string_from_h1_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_h1_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_h1_indent* vx_web_html::Func_string_from_h1_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_h1_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_h1_indent::vx_typedef() {return vx_web_html::t_string_from_h1_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_h1_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-h1-indent", // name
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

    vx_web_html::Func_string_from_h1_indent* vx_web_html::Func_string_from_h1_indent::vx_empty() {return vx_web_html::e_string_from_h1_indent;}
    vx_web_html::Func_string_from_h1_indent* vx_web_html::Func_string_from_h1_indent::vx_type() {return vx_web_html::t_string_from_h1_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_h1_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_h1* h1 = vx_core::f_any_from_any(vx_web_html::t_h1, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_h1_indent(h1, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_h1_indent::vx_string_from_h1_indent(vx_web_html::Type_h1* h1, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_h1_indent(h1, indent);
    }

  //}

  vx_web_html::Func_string_from_h1_indent* vx_web_html::e_string_from_h1_indent = new vx_web_html::Func_string_from_h1_indent();
  vx_web_html::Func_string_from_h1_indent* vx_web_html::t_string_from_h1_indent = new vx_web_html::Func_string_from_h1_indent();

  vx_core::Type_string* vx_web_html::f_string_from_h1_indent(vx_web_html::Type_h1* h1, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([indent, h1]() {
        vx_core::Type_string* sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::Type_string* text = h1->text();
        vx_core::Type_string* sid = vx_web_html::f_string_from_propname_val(
          vx_core::t_string->vx_new_from_string("id"),
          h1->id()
        );
        return vx_core::f_new(
          vx_core::t_string,
          vx_core::t_anylist->vx_new(
            sindent,
            vx_core::t_string->vx_new_from_string("<h1"),
            sid,
            vx_core::t_string->vx_new_from_string(">"),
            text,
            vx_core::t_string->vx_new_from_string("</h1>")
          )
        );
      })
    );
    return output;
  }

  /**
   * @function string_from_h2_indent
   * Returns string from h2
   * @param  {h2} h2
   * @param  {int} indent
   * @return {string}
   * (func string<-h2-indent)
   */
  //class Func_string_from_h2_indent {

    template<typename... Args> vx_web_html::Func_string_from_h2_indent* vx_web_html::Func_string_from_h2_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_h2_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_h2_indent* vx_web_html::Func_string_from_h2_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_h2_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_h2_indent::vx_typedef() {return vx_web_html::t_string_from_h2_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_h2_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-h2-indent", // name
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

    vx_web_html::Func_string_from_h2_indent* vx_web_html::Func_string_from_h2_indent::vx_empty() {return vx_web_html::e_string_from_h2_indent;}
    vx_web_html::Func_string_from_h2_indent* vx_web_html::Func_string_from_h2_indent::vx_type() {return vx_web_html::t_string_from_h2_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_h2_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_h2* h2 = vx_core::f_any_from_any(vx_web_html::t_h2, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_h2_indent(h2, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_h2_indent::vx_string_from_h2_indent(vx_web_html::Type_h2* h2, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_h2_indent(h2, indent);
    }

  //}

  vx_web_html::Func_string_from_h2_indent* vx_web_html::e_string_from_h2_indent = new vx_web_html::Func_string_from_h2_indent();
  vx_web_html::Func_string_from_h2_indent* vx_web_html::t_string_from_h2_indent = new vx_web_html::Func_string_from_h2_indent();

  vx_core::Type_string* vx_web_html::f_string_from_h2_indent(vx_web_html::Type_h2* h2, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([h2, indent]() {
        vx_core::Type_string* text = h2->text();
        vx_core::Type_string* sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::Type_string* sid = vx_web_html::f_string_from_propname_val(
          vx_core::t_string->vx_new_from_string("id"),
          h2->id()
        );
        return vx_core::f_new(
          vx_core::t_string,
          vx_core::t_anylist->vx_new(
            sindent,
            vx_core::t_string->vx_new_from_string("<h2"),
            sid,
            vx_core::t_string->vx_new_from_string(">"),
            text,
            vx_core::t_string->vx_new_from_string("</h2>")
          )
        );
      })
    );
    return output;
  }

  /**
   * @function string_from_h3_indent
   * Returns string from h3
   * @param  {h3} h3
   * @param  {int} indent
   * @return {string}
   * (func string<-h3-indent)
   */
  //class Func_string_from_h3_indent {

    template<typename... Args> vx_web_html::Func_string_from_h3_indent* vx_web_html::Func_string_from_h3_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_h3_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_h3_indent* vx_web_html::Func_string_from_h3_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_h3_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_h3_indent::vx_typedef() {return vx_web_html::t_string_from_h3_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_h3_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-h3-indent", // name
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

    vx_web_html::Func_string_from_h3_indent* vx_web_html::Func_string_from_h3_indent::vx_empty() {return vx_web_html::e_string_from_h3_indent;}
    vx_web_html::Func_string_from_h3_indent* vx_web_html::Func_string_from_h3_indent::vx_type() {return vx_web_html::t_string_from_h3_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_h3_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_h3* h3 = vx_core::f_any_from_any(vx_web_html::t_h3, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_h3_indent(h3, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_h3_indent::vx_string_from_h3_indent(vx_web_html::Type_h3* h3, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_h3_indent(h3, indent);
    }

  //}

  vx_web_html::Func_string_from_h3_indent* vx_web_html::e_string_from_h3_indent = new vx_web_html::Func_string_from_h3_indent();
  vx_web_html::Func_string_from_h3_indent* vx_web_html::t_string_from_h3_indent = new vx_web_html::Func_string_from_h3_indent();

  vx_core::Type_string* vx_web_html::f_string_from_h3_indent(vx_web_html::Type_h3* h3, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([h3, indent]() {
        vx_core::Type_string* text = h3->text();
        vx_core::Type_string* sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::Type_string* sid = vx_web_html::f_string_from_propname_val(
          vx_core::t_string->vx_new_from_string("id"),
          h3->id()
        );
        return vx_core::f_new(
          vx_core::t_string,
          vx_core::t_anylist->vx_new(
            sindent,
            vx_core::t_string->vx_new_from_string("<h3"),
            sid,
            vx_core::t_string->vx_new_from_string(">"),
            text,
            vx_core::t_string->vx_new_from_string("</h3>")
          )
        );
      })
    );
    return output;
  }

  /**
   * @function string_from_head_indent
   * Returns string from head
   * @param  {head} head
   * @param  {int} indent
   * @return {string}
   * (func string<-head-indent)
   */
  //class Func_string_from_head_indent {

    template<typename... Args> vx_web_html::Func_string_from_head_indent* vx_web_html::Func_string_from_head_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_head_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_head_indent* vx_web_html::Func_string_from_head_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_head_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_head_indent::vx_typedef() {return vx_web_html::t_string_from_head_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_head_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-head-indent", // name
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

    vx_web_html::Func_string_from_head_indent* vx_web_html::Func_string_from_head_indent::vx_empty() {return vx_web_html::e_string_from_head_indent;}
    vx_web_html::Func_string_from_head_indent* vx_web_html::Func_string_from_head_indent::vx_type() {return vx_web_html::t_string_from_head_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_head_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_head* head = vx_core::f_any_from_any(vx_web_html::t_head, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_head_indent(head, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_head_indent::vx_string_from_head_indent(vx_web_html::Type_head* head, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_head_indent(head, indent);
    }

  //}

  vx_web_html::Func_string_from_head_indent* vx_web_html::e_string_from_head_indent = new vx_web_html::Func_string_from_head_indent();
  vx_web_html::Func_string_from_head_indent* vx_web_html::t_string_from_head_indent = new vx_web_html::Func_string_from_head_indent();

  vx_core::Type_string* vx_web_html::f_string_from_head_indent(vx_web_html::Type_head* head, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([head, indent]() {
        vx_web_html::Type_headchildlist* nodes = head->nodes();
        return vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, vx_core::t_string->vx_new_from_string("head"), vx_core::t_string->vx_new_from_string(""), indent);
      })
    );
    return output;
  }

  /**
   * @function string_from_html
   * Returns string from html
   * @param  {html} html
   * @return {string}
   * (func string<-html)
   */
  //class Func_string_from_html {

    template<typename... Args> vx_web_html::Func_string_from_html* vx_web_html::Func_string_from_html::vx_new(Args*... args) {
      vx_web_html::Func_string_from_html* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_html* vx_web_html::Func_string_from_html::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_html* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_html::vx_typedef() {return vx_web_html::t_string_from_html->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_html::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-html", // name
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

    vx_web_html::Func_string_from_html* vx_web_html::Func_string_from_html::vx_empty() {return vx_web_html::e_string_from_html;}
    vx_web_html::Func_string_from_html* vx_web_html::Func_string_from_html::vx_type() {return vx_web_html::t_string_from_html;}

    vx_core::Func_any_from_any* vx_web_html::Func_string_from_html::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_web_html::Func_string_from_html::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_web_html::Type_html* inputval = (vx_web_html::Type_html)value;
      vx_core::Type_any* outputval = vx_web_html::f_string_from_html(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_web_html::Func_string_from_html::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_html* html = vx_core::f_any_from_any(vx_web_html::t_html, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_web_html::f_string_from_html(html);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_html::vx_string_from_html(vx_web_html::Type_html* html) {
      return vx_web_html::f_string_from_html(html);
    }

  //}

  vx_web_html::Func_string_from_html* vx_web_html::e_string_from_html = new vx_web_html::Func_string_from_html();
  vx_web_html::Func_string_from_html* vx_web_html::t_string_from_html = new vx_web_html::Func_string_from_html();

  vx_core::Type_string* vx_web_html::f_string_from_html(vx_web_html::Type_html* html) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([html]() {
        vx_core::Type_string* lang = vx_web_html::f_string_from_propname_val(
          vx_core::t_string->vx_new_from_string("lang"),
          html->lang()
        );
        vx_web_html::Type_head* head = html->head();
        vx_web_html::Type_body* body = html->body();
        vx_web_html::Type_footer* footer = html->footer();
        vx_core::Type_string* shead = vx_web_html::f_string_from_head_indent(head, vx_core::t_int->vx_new_from_int(1));
        vx_core::Type_string* sbody = vx_web_html::f_string_from_body_indent(body, vx_core::t_int->vx_new_from_int(1));
        vx_core::Type_string* sfooter = vx_web_html::f_string_from_footer_indent(footer, vx_core::t_int->vx_new_from_int(1));
        return vx_core::f_new(
          vx_core::t_string,
          vx_core::t_anylist->vx_new(
            vx_core::t_string->vx_new_from_string("<!DOCTYPE html>"),
            vx_core::c_newline,
            vx_core::t_string->vx_new_from_string("<html"),
            lang,
            vx_core::t_string->vx_new_from_string(">"),
            shead,
            sbody,
            sfooter,
            vx_core::c_newline,
            vx_core::t_string->vx_new_from_string("</html>")
          )
        );
      })
    );
    return output;
  }

  /**
   * @function string_from_indent
   * Returns a string to do indentation for a given indent count.
   * @param  {int} indent
   * @return {string}
   * (func string<-indent)
   */
  //class Func_string_from_indent {

    template<typename... Args> vx_web_html::Func_string_from_indent* vx_web_html::Func_string_from_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_indent* vx_web_html::Func_string_from_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_indent::vx_typedef() {return vx_web_html::t_string_from_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-indent", // name
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

    vx_web_html::Func_string_from_indent* vx_web_html::Func_string_from_indent::vx_empty() {return vx_web_html::e_string_from_indent;}
    vx_web_html::Func_string_from_indent* vx_web_html::Func_string_from_indent::vx_type() {return vx_web_html::t_string_from_indent;}

    vx_core::Func_any_from_any* vx_web_html::Func_string_from_indent::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_web_html::Func_string_from_indent::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_core::Type_int* inputval = (vx_core::Type_int)value;
      vx_core::Type_any* outputval = vx_web_html::f_string_from_indent(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_web_html::Func_string_from_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_web_html::f_string_from_indent(indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_indent::vx_string_from_indent(vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_indent(indent);
    }

  //}

  vx_web_html::Func_string_from_indent* vx_web_html::e_string_from_indent = new vx_web_html::Func_string_from_indent();
  vx_web_html::Func_string_from_indent* vx_web_html::t_string_from_indent = new vx_web_html::Func_string_from_indent();

  vx_core::Type_string* vx_web_html::f_string_from_indent(vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_if_1(
      vx_core::t_string,
      vx_core::f_eq(indent, vx_core::t_int->vx_new_from_int(0)),
      vx_core::t_string->vx_new_from_string(""),
      vx_core::f_new(
        vx_core::t_string,
        vx_core::t_anylist->vx_new(
          vx_core::c_newline,
          vx_web_html::f_string_indent(indent)
        )
      )
    );
    return output;
  }

  /**
   * @function string_from_meta_indent
   * Returns string from head
   * @param  {meta} meta
   * @param  {int} indent
   * @return {string}
   * (func string<-meta-indent)
   */
  //class Func_string_from_meta_indent {

    template<typename... Args> vx_web_html::Func_string_from_meta_indent* vx_web_html::Func_string_from_meta_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_meta_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_meta_indent* vx_web_html::Func_string_from_meta_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_meta_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_meta_indent::vx_typedef() {return vx_web_html::t_string_from_meta_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_meta_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-meta-indent", // name
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

    vx_web_html::Func_string_from_meta_indent* vx_web_html::Func_string_from_meta_indent::vx_empty() {return vx_web_html::e_string_from_meta_indent;}
    vx_web_html::Func_string_from_meta_indent* vx_web_html::Func_string_from_meta_indent::vx_type() {return vx_web_html::t_string_from_meta_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_meta_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_meta* meta = vx_core::f_any_from_any(vx_web_html::t_meta, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_meta_indent(meta, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_meta_indent::vx_string_from_meta_indent(vx_web_html::Type_meta* meta, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_meta_indent(meta, indent);
    }

  //}

  vx_web_html::Func_string_from_meta_indent* vx_web_html::e_string_from_meta_indent = new vx_web_html::Func_string_from_meta_indent();
  vx_web_html::Func_string_from_meta_indent* vx_web_html::t_string_from_meta_indent = new vx_web_html::Func_string_from_meta_indent();

  vx_core::Type_string* vx_web_html::f_string_from_meta_indent(vx_web_html::Type_meta* meta, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([indent, meta]() {
        vx_core::Type_string* sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::Type_string* charset = vx_web_html::f_string_from_propname_val(
          vx_core::t_string->vx_new_from_string("charset"),
          meta->charset()
        );
        return vx_core::f_new(
          vx_core::t_string,
          vx_core::t_anylist->vx_new(
            sindent,
            vx_core::t_string->vx_new_from_string("<meta"),
            charset,
            vx_core::t_string->vx_new_from_string(" />")
          )
        );
      })
    );
    return output;
  }

  /**
   * @function string_from_node_indent
   * Returns a string from any node
   * @param  {any-1} node
   * @param  {int} indent
   * @return {string}
   * (func string<-node-indent)
   */
  //class Func_string_from_node_indent {

    template<typename... Args> vx_web_html::Func_string_from_node_indent* vx_web_html::Func_string_from_node_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_node_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_node_indent* vx_web_html::Func_string_from_node_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_node_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_node_indent::vx_typedef() {return vx_web_html::t_string_from_node_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_node_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-node-indent", // name
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

    vx_web_html::Func_string_from_node_indent* vx_web_html::Func_string_from_node_indent::vx_empty() {return vx_web_html::e_string_from_node_indent;}
    vx_web_html::Func_string_from_node_indent* vx_web_html::Func_string_from_node_indent::vx_type() {return vx_web_html::t_string_from_node_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_node_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_any* node = vx_core::f_any_from_any(vx_core::t_any, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_node_indent(node, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_node_indent::vx_string_from_node_indent(vx_core::Type_any* node, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_node_indent(node, indent);
    }

  //}

  vx_web_html::Func_string_from_node_indent* vx_web_html::e_string_from_node_indent = new vx_web_html::Func_string_from_node_indent();
  vx_web_html::Func_string_from_node_indent* vx_web_html::t_string_from_node_indent = new vx_web_html::Func_string_from_node_indent();

  vx_core::Type_string* vx_web_html::f_string_from_node_indent(vx_core::Type_any* node, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_switch(
      vx_core::t_string,
      vx_core::f_type_from_any(node),
      vx_core::t_thenelselist->vx_new(
        vx_core::f_case_1(
          vx_web_html::t_body,
          vx_core::t_any_from_func->fn_new([node, indent]() {
            return vx_web_html::f_string_from_body_indent(
              vx_core::f_any_from_any(vx_web_html::t_body, node),
              indent
            );
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_details,
          vx_core::t_any_from_func->fn_new([node, indent]() {
            return vx_web_html::f_string_from_details_indent(
              vx_core::f_any_from_any(vx_web_html::t_details, node),
              indent
            );
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_div,
          vx_core::t_any_from_func->fn_new([node, indent]() {
            return vx_web_html::f_string_from_div_indent(
              vx_core::f_any_from_any(vx_web_html::t_div, node),
              indent
            );
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_h1,
          vx_core::t_any_from_func->fn_new([node, indent]() {
            return vx_web_html::f_string_from_h1_indent(
              vx_core::f_any_from_any(vx_web_html::t_h1, node),
              indent
            );
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_h2,
          vx_core::t_any_from_func->fn_new([node, indent]() {
            return vx_web_html::f_string_from_h2_indent(
              vx_core::f_any_from_any(vx_web_html::t_h2, node),
              indent
            );
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_h3,
          vx_core::t_any_from_func->fn_new([node, indent]() {
            return vx_web_html::f_string_from_h3_indent(
              vx_core::f_any_from_any(vx_web_html::t_h3, node),
              indent
            );
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_head,
          vx_core::t_any_from_func->fn_new([node, indent]() {
            return vx_web_html::f_string_from_head_indent(
              vx_core::f_any_from_any(vx_web_html::t_head, node),
              indent
            );
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_footer,
          vx_core::t_any_from_func->fn_new([node, indent]() {
            return vx_web_html::f_string_from_footer_indent(
              vx_core::f_any_from_any(vx_web_html::t_footer, node),
              indent
            );
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_meta,
          vx_core::t_any_from_func->fn_new([node, indent]() {
            return vx_web_html::f_string_from_meta_indent(
              vx_core::f_any_from_any(vx_web_html::t_meta, node),
              indent
            );
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_p,
          vx_core::t_any_from_func->fn_new([node, indent]() {
            return vx_web_html::f_string_from_p_indent(
              vx_core::f_any_from_any(vx_web_html::t_p, node),
              indent
            );
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_stylesheet,
          vx_core::t_any_from_func->fn_new([node, indent]() {
            return vx_web_html::f_string_from_stylesheet_indent(
              vx_core::f_any_from_any(vx_web_html::t_stylesheet, node),
              indent
            );
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_table,
          vx_core::t_any_from_func->fn_new([node, indent]() {
            return vx_web_html::f_string_from_table_indent(
              vx_core::f_any_from_any(vx_web_html::t_table, node),
              indent
            );
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_title,
          vx_core::t_any_from_func->fn_new([node, indent]() {
            return vx_web_html::f_string_from_title_indent(
              vx_core::f_any_from_any(vx_web_html::t_title, node),
              indent
            );
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_tbody,
          vx_core::t_any_from_func->fn_new([node, indent]() {
            return vx_web_html::f_string_from_tbody_indent(
              vx_core::f_any_from_any(vx_web_html::t_tbody, node),
              indent
            );
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_thead,
          vx_core::t_any_from_func->fn_new([node, indent]() {
            return vx_web_html::f_string_from_thead_indent(
              vx_core::f_any_from_any(vx_web_html::t_thead, node),
              indent
            );
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_td,
          vx_core::t_any_from_func->fn_new([node, indent]() {
            return vx_web_html::f_string_from_td_indent(
              vx_core::f_any_from_any(vx_web_html::t_td, node),
              indent
            );
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_tr,
          vx_core::t_any_from_func->fn_new([node, indent]() {
            return vx_web_html::f_string_from_tr_indent(
              vx_core::f_any_from_any(vx_web_html::t_tr, node),
              indent
            );
          })
        )
      )
    );
    return output;
  }

  /**
   * @function string_from_nodelist_indent
   * Returns a string from any node
   * @param  {list-1} nodelist
   * @param  {int} indent
   * @return {string}
   * (func string<-nodelist-indent)
   */
  //class Func_string_from_nodelist_indent {

    template<typename... Args> vx_web_html::Func_string_from_nodelist_indent* vx_web_html::Func_string_from_nodelist_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_nodelist_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_nodelist_indent* vx_web_html::Func_string_from_nodelist_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_nodelist_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_nodelist_indent::vx_typedef() {return vx_web_html::t_string_from_nodelist_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_nodelist_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-nodelist-indent", // name
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

    vx_web_html::Func_string_from_nodelist_indent* vx_web_html::Func_string_from_nodelist_indent::vx_empty() {return vx_web_html::e_string_from_nodelist_indent;}
    vx_web_html::Func_string_from_nodelist_indent* vx_web_html::Func_string_from_nodelist_indent::vx_type() {return vx_web_html::t_string_from_nodelist_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_nodelist_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_list* nodelist = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_nodelist_indent(nodelist, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_nodelist_indent::vx_string_from_nodelist_indent(vx_core::Type_list* nodelist, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_nodelist_indent(nodelist, indent);
    }

  //}

  vx_web_html::Func_string_from_nodelist_indent* vx_web_html::e_string_from_nodelist_indent = new vx_web_html::Func_string_from_nodelist_indent();
  vx_web_html::Func_string_from_nodelist_indent* vx_web_html::t_string_from_nodelist_indent = new vx_web_html::Func_string_from_nodelist_indent();

  vx_core::Type_string* vx_web_html::f_string_from_nodelist_indent(vx_core::Type_list* nodelist, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([nodelist, indent]() {
        vx_core::Type_stringlist* textlist = vx_core::f_list_from_list(
          vx_core::t_stringlist,
          nodelist,
          vx_core::t_any_from_any->fn_new([indent](vx_core::Type_any* node_any) {
            vx_web_html::Type_node* node = vx_core::f_any_from_any(vx_web_html::t_node, node_any);
            return 
              vx_web_html::f_string_from_node_indent(node, indent);
          })
        );
        return vx_type::f_string_from_stringlist_join(textlist, vx_core::t_string->vx_new_from_string(""));
      })
    );
    return output;
  }

  /**
   * @function string_from_nodelist_tag_prop_indent
   * Returns string from generic nodelist
   * @param  {list-1} nodes
   * @param  {string} tag
   * @param  {string} prop
   * @param  {int} indent
   * @return {string}
   * (func string<-nodelist-tag-prop-indent)
   */
  //class Func_string_from_nodelist_tag_prop_indent {

    template<typename... Args> vx_web_html::Func_string_from_nodelist_tag_prop_indent* vx_web_html::Func_string_from_nodelist_tag_prop_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_nodelist_tag_prop_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_nodelist_tag_prop_indent* vx_web_html::Func_string_from_nodelist_tag_prop_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_nodelist_tag_prop_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_nodelist_tag_prop_indent::vx_typedef() {return vx_web_html::t_string_from_nodelist_tag_prop_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_nodelist_tag_prop_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-nodelist-tag-prop-indent", // name
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

    vx_web_html::Func_string_from_nodelist_tag_prop_indent* vx_web_html::Func_string_from_nodelist_tag_prop_indent::vx_empty() {return vx_web_html::e_string_from_nodelist_tag_prop_indent;}
    vx_web_html::Func_string_from_nodelist_tag_prop_indent* vx_web_html::Func_string_from_nodelist_tag_prop_indent::vx_type() {return vx_web_html::t_string_from_nodelist_tag_prop_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_nodelist_tag_prop_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_list* nodes = vx_core::f_any_from_any(vx_core::t_list, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_string* tag = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      vx_core::Type_string* prop = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(2)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(3)));
      output = vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, tag, prop, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_nodelist_tag_prop_indent::vx_string_from_nodelist_tag_prop_indent(vx_core::Type_list* nodes, vx_core::Type_string* tag, vx_core::Type_string* prop, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, tag, prop, indent);
    }

  //}

  vx_web_html::Func_string_from_nodelist_tag_prop_indent* vx_web_html::e_string_from_nodelist_tag_prop_indent = new vx_web_html::Func_string_from_nodelist_tag_prop_indent();
  vx_web_html::Func_string_from_nodelist_tag_prop_indent* vx_web_html::t_string_from_nodelist_tag_prop_indent = new vx_web_html::Func_string_from_nodelist_tag_prop_indent();

  vx_core::Type_string* vx_web_html::f_string_from_nodelist_tag_prop_indent(vx_core::Type_list* nodes, vx_core::Type_string* tag, vx_core::Type_string* prop, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([nodes, indent, tag, prop]() {
        vx_core::Type_string* text = vx_web_html::f_string_from_nodelist_indent(
          nodes,
          vx_core::f_plus1(indent)
        );
        vx_core::Type_string* sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::Type_string* eindent = vx_core::f_if_2(
          vx_core::t_string,
          vx_core::t_thenelselist->vx_new(
            vx_core::f_then(
              vx_core::t_boolean_from_func->fn_new([text]() {
                return vx_core::f_is_empty(text);
              }),
              vx_core::t_any_from_func->fn_new([]() {
                return vx_core::t_string->vx_new_from_string("");
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->fn_new([sindent]() {
                return vx_core::f_is_empty(sindent);
              }),
              vx_core::t_any_from_func->fn_new([]() {
                return vx_core::c_newline;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->fn_new([sindent]() {
                return sindent;
              })
            )
          )
        );
        return vx_core::f_new(
          vx_core::t_string,
          vx_core::t_anylist->vx_new(
            sindent,
            vx_core::t_string->vx_new_from_string("<"),
            tag,
            prop,
            vx_core::t_string->vx_new_from_string(">"),
            text,
            eindent,
            vx_core::t_string->vx_new_from_string("</"),
            tag,
            vx_core::t_string->vx_new_from_string(">")
          )
        );
      })
    );
    return output;
  }

  /**
   * @function string_from_p_indent
   * Returns string from p
   * @param  {p} p
   * @param  {int} indent
   * @return {string}
   * (func string<-p-indent)
   */
  //class Func_string_from_p_indent {

    template<typename... Args> vx_web_html::Func_string_from_p_indent* vx_web_html::Func_string_from_p_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_p_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_p_indent* vx_web_html::Func_string_from_p_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_p_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_p_indent::vx_typedef() {return vx_web_html::t_string_from_p_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_p_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-p-indent", // name
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

    vx_web_html::Func_string_from_p_indent* vx_web_html::Func_string_from_p_indent::vx_empty() {return vx_web_html::e_string_from_p_indent;}
    vx_web_html::Func_string_from_p_indent* vx_web_html::Func_string_from_p_indent::vx_type() {return vx_web_html::t_string_from_p_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_p_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_p* p = vx_core::f_any_from_any(vx_web_html::t_p, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_p_indent(p, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_p_indent::vx_string_from_p_indent(vx_web_html::Type_p* p, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_p_indent(p, indent);
    }

  //}

  vx_web_html::Func_string_from_p_indent* vx_web_html::e_string_from_p_indent = new vx_web_html::Func_string_from_p_indent();
  vx_web_html::Func_string_from_p_indent* vx_web_html::t_string_from_p_indent = new vx_web_html::Func_string_from_p_indent();

  vx_core::Type_string* vx_web_html::f_string_from_p_indent(vx_web_html::Type_p* p, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([indent, p]() {
        vx_core::Type_string* sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::Type_string* text = vx_web_html::f_htmlstring_from_string(
          p->text()
        );
        vx_core::Type_string* sid = vx_web_html::f_string_from_propname_val(
          vx_core::t_string->vx_new_from_string("id"),
          p->id()
        );
        vx_core::Type_string* sstyle = vx_web_html::f_string_from_propstyle(
          p->style()
        );
        return vx_core::f_new(
          vx_core::t_string,
          vx_core::t_anylist->vx_new(
            sindent,
            vx_core::t_string->vx_new_from_string("<p"),
            sid,
            sstyle,
            vx_core::t_string->vx_new_from_string(">"),
            text,
            vx_core::t_string->vx_new_from_string("</p>")
          )
        );
      })
    );
    return output;
  }

  /**
   * @function string_from_propname_val
   * Returns ' key=\"val\"' if val is not blank.
   * @param  {string} key
   * @param  {string} val
   * @return {string}
   * (func string<-propname-val)
   */
  //class Func_string_from_propname_val {

    template<typename... Args> vx_web_html::Func_string_from_propname_val* vx_web_html::Func_string_from_propname_val::vx_new(Args*... args) {
      vx_web_html::Func_string_from_propname_val* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_propname_val* vx_web_html::Func_string_from_propname_val::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_propname_val* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_propname_val::vx_typedef() {return vx_web_html::t_string_from_propname_val->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_propname_val::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-propname-val", // name
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

    vx_web_html::Func_string_from_propname_val* vx_web_html::Func_string_from_propname_val::vx_empty() {return vx_web_html::e_string_from_propname_val;}
    vx_web_html::Func_string_from_propname_val* vx_web_html::Func_string_from_propname_val::vx_type() {return vx_web_html::t_string_from_propname_val;}

    vx_core::Type_any* vx_web_html::Func_string_from_propname_val::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_string* key = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_string* val = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_propname_val(key, val);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_propname_val::vx_string_from_propname_val(vx_core::Type_string* key, vx_core::Type_string* val) {
      return vx_web_html::f_string_from_propname_val(key, val);
    }

  //}

  vx_web_html::Func_string_from_propname_val* vx_web_html::e_string_from_propname_val = new vx_web_html::Func_string_from_propname_val();
  vx_web_html::Func_string_from_propname_val* vx_web_html::t_string_from_propname_val = new vx_web_html::Func_string_from_propname_val();

  vx_core::Type_string* vx_web_html::f_string_from_propname_val(vx_core::Type_string* key, vx_core::Type_string* val) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_if(
      vx_core::t_string,
      vx_core::f_notempty(val),
      vx_core::f_new(
        vx_core::t_string,
        vx_core::t_anylist->vx_new(
          vx_core::t_string->vx_new_from_string(" "),
          key,
          vx_core::t_string->vx_new_from_string("="),
          vx_core::c_quote,
          val,
          vx_core::c_quote
        )
      )
    );
    return output;
  }

  /**
   * @function string_from_propstyle
   * Returns ' class=\"style.name\"' if style is not empty.
   * @param  {style} style
   * @return {string}
   * (func string<-propstyle)
   */
  //class Func_string_from_propstyle {

    template<typename... Args> vx_web_html::Func_string_from_propstyle* vx_web_html::Func_string_from_propstyle::vx_new(Args*... args) {
      vx_web_html::Func_string_from_propstyle* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_propstyle* vx_web_html::Func_string_from_propstyle::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_propstyle* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_propstyle::vx_typedef() {return vx_web_html::t_string_from_propstyle->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_propstyle::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-propstyle", // name
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

    vx_web_html::Func_string_from_propstyle* vx_web_html::Func_string_from_propstyle::vx_empty() {return vx_web_html::e_string_from_propstyle;}
    vx_web_html::Func_string_from_propstyle* vx_web_html::Func_string_from_propstyle::vx_type() {return vx_web_html::t_string_from_propstyle;}

    vx_core::Func_any_from_any* vx_web_html::Func_string_from_propstyle::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_web_html::Func_string_from_propstyle::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_web_html::Type_style* inputval = (vx_web_html::Type_style)value;
      vx_core::Type_any* outputval = vx_web_html::f_string_from_propstyle(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_web_html::Func_string_from_propstyle::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_style* style = vx_core::f_any_from_any(vx_web_html::t_style, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_web_html::f_string_from_propstyle(style);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_propstyle::vx_string_from_propstyle(vx_web_html::Type_style* style) {
      return vx_web_html::f_string_from_propstyle(style);
    }

  //}

  vx_web_html::Func_string_from_propstyle* vx_web_html::e_string_from_propstyle = new vx_web_html::Func_string_from_propstyle();
  vx_web_html::Func_string_from_propstyle* vx_web_html::t_string_from_propstyle = new vx_web_html::Func_string_from_propstyle();

  vx_core::Type_string* vx_web_html::f_string_from_propstyle(vx_web_html::Type_style* style) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_if(
      vx_core::t_string,
      vx_core::f_notempty_1(style),
      vx_core::f_new(
        vx_core::t_string,
        vx_core::t_anylist->vx_new(
          vx_core::t_string->vx_new_from_string(" class="),
          vx_core::c_quote,
          vx_type::f_string_from_string_start(
            style->name(),
            vx_core::t_int->vx_new_from_int(1)
          ),
          vx_core::c_quote
        )
      )
    );
    return output;
  }

  /**
   * @function string_from_style_indent
   * Returns indent'name {key: val;}' for each style.
   * @param  {style} style
   * @param  {int} indent
   * @return {string}
   * (func string<-style-indent)
   */
  //class Func_string_from_style_indent {

    template<typename... Args> vx_web_html::Func_string_from_style_indent* vx_web_html::Func_string_from_style_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_style_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_style_indent* vx_web_html::Func_string_from_style_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_style_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_style_indent::vx_typedef() {return vx_web_html::t_string_from_style_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_style_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-style-indent", // name
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

    vx_web_html::Func_string_from_style_indent* vx_web_html::Func_string_from_style_indent::vx_empty() {return vx_web_html::e_string_from_style_indent;}
    vx_web_html::Func_string_from_style_indent* vx_web_html::Func_string_from_style_indent::vx_type() {return vx_web_html::t_string_from_style_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_style_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_style* style = vx_core::f_any_from_any(vx_web_html::t_style, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_style_indent(style, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_style_indent::vx_string_from_style_indent(vx_web_html::Type_style* style, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_style_indent(style, indent);
    }

  //}

  vx_web_html::Func_string_from_style_indent* vx_web_html::e_string_from_style_indent = new vx_web_html::Func_string_from_style_indent();
  vx_web_html::Func_string_from_style_indent* vx_web_html::t_string_from_style_indent = new vx_web_html::Func_string_from_style_indent();

  vx_core::Type_string* vx_web_html::f_string_from_style_indent(vx_web_html::Type_style* style, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([indent, style]() {
        vx_core::Type_string* sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::Type_string* name = style->name();
        vx_web_html::Type_propmap* propmap = style->props();
        vx_core::Type_string* stext = vx_web_html::f_string_from_stylepropmap_indent(
          propmap,
          vx_core::f_plus1(indent)
        );
        return vx_core::f_new(
          vx_core::t_string,
          vx_core::t_anylist->vx_new(
            sindent,
            name,
            vx_core::t_string->vx_new_from_string(" {"),
            stext,
            sindent,
            vx_core::t_string->vx_new_from_string("}")
          )
        );
      })
    );
    return output;
  }

  /**
   * @function string_from_stylelist_indent
   * Return a string from a stylelist
   * @param  {stylelist} stylelist
   * @param  {int} indent
   * @return {string}
   * (func string<-stylelist-indent)
   */
  //class Func_string_from_stylelist_indent {

    template<typename... Args> vx_web_html::Func_string_from_stylelist_indent* vx_web_html::Func_string_from_stylelist_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_stylelist_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_stylelist_indent* vx_web_html::Func_string_from_stylelist_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_stylelist_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_stylelist_indent::vx_typedef() {return vx_web_html::t_string_from_stylelist_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_stylelist_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-stylelist-indent", // name
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

    vx_web_html::Func_string_from_stylelist_indent* vx_web_html::Func_string_from_stylelist_indent::vx_empty() {return vx_web_html::e_string_from_stylelist_indent;}
    vx_web_html::Func_string_from_stylelist_indent* vx_web_html::Func_string_from_stylelist_indent::vx_type() {return vx_web_html::t_string_from_stylelist_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_stylelist_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_stylelist* stylelist = vx_core::f_any_from_any(vx_web_html::t_stylelist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_stylelist_indent(stylelist, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_stylelist_indent::vx_string_from_stylelist_indent(vx_web_html::Type_stylelist* stylelist, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_stylelist_indent(stylelist, indent);
    }

  //}

  vx_web_html::Func_string_from_stylelist_indent* vx_web_html::e_string_from_stylelist_indent = new vx_web_html::Func_string_from_stylelist_indent();
  vx_web_html::Func_string_from_stylelist_indent* vx_web_html::t_string_from_stylelist_indent = new vx_web_html::Func_string_from_stylelist_indent();

  vx_core::Type_string* vx_web_html::f_string_from_stylelist_indent(vx_web_html::Type_stylelist* stylelist, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([stylelist, indent]() {
        vx_core::Type_stringlist* sstyles = vx_core::f_list_from_list(
          vx_core::t_stringlist,
          stylelist,
          vx_core::t_any_from_any->fn_new([indent](vx_core::Type_any* substyle_any) {
            vx_web_html::Type_style* substyle = vx_core::f_any_from_any(vx_web_html::t_style, substyle_any);
            return 
              vx_web_html::f_string_from_style_indent(substyle, indent);
          })
        );
        return vx_type::f_string_from_stringlist_join(sstyles, vx_core::t_string->vx_new_from_string(""));
      })
    );
    return output;
  }

  /**
   * @function string_from_stylepropmap_indent
   * Returns indent'key: val;' for each prop.
   * @param  {propmap} propmap
   * @param  {int} indent
   * @return {string}
   * (func string<-stylepropmap-indent)
   */
  //class Func_string_from_stylepropmap_indent {

    template<typename... Args> vx_web_html::Func_string_from_stylepropmap_indent* vx_web_html::Func_string_from_stylepropmap_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_stylepropmap_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_stylepropmap_indent* vx_web_html::Func_string_from_stylepropmap_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_stylepropmap_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_stylepropmap_indent::vx_typedef() {return vx_web_html::t_string_from_stylepropmap_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_stylepropmap_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-stylepropmap-indent", // name
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

    vx_web_html::Func_string_from_stylepropmap_indent* vx_web_html::Func_string_from_stylepropmap_indent::vx_empty() {return vx_web_html::e_string_from_stylepropmap_indent;}
    vx_web_html::Func_string_from_stylepropmap_indent* vx_web_html::Func_string_from_stylepropmap_indent::vx_type() {return vx_web_html::t_string_from_stylepropmap_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_stylepropmap_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_propmap* propmap = vx_core::f_any_from_any(vx_web_html::t_propmap, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_stylepropmap_indent(propmap, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_stylepropmap_indent::vx_string_from_stylepropmap_indent(vx_web_html::Type_propmap* propmap, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_stylepropmap_indent(propmap, indent);
    }

  //}

  vx_web_html::Func_string_from_stylepropmap_indent* vx_web_html::e_string_from_stylepropmap_indent = new vx_web_html::Func_string_from_stylepropmap_indent();
  vx_web_html::Func_string_from_stylepropmap_indent* vx_web_html::t_string_from_stylepropmap_indent = new vx_web_html::Func_string_from_stylepropmap_indent();

  vx_core::Type_string* vx_web_html::f_string_from_stylepropmap_indent(vx_web_html::Type_propmap* propmap, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([indent, propmap]() {
        vx_core::Type_string* sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::Type_stringlist* sprops = vx_core::f_list_from_map(
          vx_core::t_stringlist,
          propmap,
          vx_core::t_any_from_key_value->fn_new([sindent](vx_core::Type_any* key_any, vx_core::Type_any* val_any) {
            vx_core::Type_string* key = vx_core::f_any_from_any(vx_core::t_string, key_any);
            vx_core::Type_string* val = vx_core::f_any_from_any(vx_core::t_string, val_any);
            return 
              vx_core::f_new(
                vx_core::t_string,
                vx_core::t_anylist->vx_new(
                  sindent,
                  key,
                  vx_core::t_string->vx_new_from_string(": "),
                  val,
                  vx_core::t_string->vx_new_from_string(";")
                )
              );
          })
        );
        return vx_type::f_string_from_stringlist_join(sprops, vx_core::t_string->vx_new_from_string(""));
      })
    );
    return output;
  }

  /**
   * @function string_from_stylesheet_indent
   * Returns string representation of given stylesheet.
   * @param  {stylesheet} stylesheet
   * @param  {int} indent
   * @return {string}
   * (func string<-stylesheet-indent)
   */
  //class Func_string_from_stylesheet_indent {

    template<typename... Args> vx_web_html::Func_string_from_stylesheet_indent* vx_web_html::Func_string_from_stylesheet_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_stylesheet_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_stylesheet_indent* vx_web_html::Func_string_from_stylesheet_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_stylesheet_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_stylesheet_indent::vx_typedef() {return vx_web_html::t_string_from_stylesheet_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_stylesheet_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-stylesheet-indent", // name
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

    vx_web_html::Func_string_from_stylesheet_indent* vx_web_html::Func_string_from_stylesheet_indent::vx_empty() {return vx_web_html::e_string_from_stylesheet_indent;}
    vx_web_html::Func_string_from_stylesheet_indent* vx_web_html::Func_string_from_stylesheet_indent::vx_type() {return vx_web_html::t_string_from_stylesheet_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_stylesheet_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_stylesheet* stylesheet = vx_core::f_any_from_any(vx_web_html::t_stylesheet, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_stylesheet_indent(stylesheet, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_stylesheet_indent::vx_string_from_stylesheet_indent(vx_web_html::Type_stylesheet* stylesheet, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_stylesheet_indent(stylesheet, indent);
    }

  //}

  vx_web_html::Func_string_from_stylesheet_indent* vx_web_html::e_string_from_stylesheet_indent = new vx_web_html::Func_string_from_stylesheet_indent();
  vx_web_html::Func_string_from_stylesheet_indent* vx_web_html::t_string_from_stylesheet_indent = new vx_web_html::Func_string_from_stylesheet_indent();

  vx_core::Type_string* vx_web_html::f_string_from_stylesheet_indent(vx_web_html::Type_stylesheet* stylesheet, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([stylesheet, indent]() {
        vx_core::Type_string* text = vx_web_html::f_string_from_stylelist_indent(
          stylesheet->styles(),
          vx_core::f_plus1(indent)
        );
        vx_core::Type_string* sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::Type_string* eindent = vx_core::f_if(
          vx_core::t_string,
          vx_core::f_notempty(text),
          sindent
        );
        return vx_core::f_new(
          vx_core::t_string,
          vx_core::t_anylist->vx_new(
            sindent,
            vx_core::t_string->vx_new_from_string("<style>"),
            text,
            eindent,
            vx_core::t_string->vx_new_from_string("</style>")
          )
        );
      })
    );
    return output;
  }

  /**
   * @function string_from_table_indent
   * Returns string from table
   * @param  {table} table
   * @param  {int} indent
   * @return {string}
   * (func string<-table-indent)
   */
  //class Func_string_from_table_indent {

    template<typename... Args> vx_web_html::Func_string_from_table_indent* vx_web_html::Func_string_from_table_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_table_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_table_indent* vx_web_html::Func_string_from_table_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_table_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_table_indent::vx_typedef() {return vx_web_html::t_string_from_table_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_table_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-table-indent", // name
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

    vx_web_html::Func_string_from_table_indent* vx_web_html::Func_string_from_table_indent::vx_empty() {return vx_web_html::e_string_from_table_indent;}
    vx_web_html::Func_string_from_table_indent* vx_web_html::Func_string_from_table_indent::vx_type() {return vx_web_html::t_string_from_table_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_table_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_table* table = vx_core::f_any_from_any(vx_web_html::t_table, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_table_indent(table, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_table_indent::vx_string_from_table_indent(vx_web_html::Type_table* table, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_table_indent(table, indent);
    }

  //}

  vx_web_html::Func_string_from_table_indent* vx_web_html::e_string_from_table_indent = new vx_web_html::Func_string_from_table_indent();
  vx_web_html::Func_string_from_table_indent* vx_web_html::t_string_from_table_indent = new vx_web_html::Func_string_from_table_indent();

  vx_core::Type_string* vx_web_html::f_string_from_table_indent(vx_web_html::Type_table* table, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([indent, table]() {
        vx_core::Type_string* sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::Type_string* sid = vx_web_html::f_string_from_propname_val(
          vx_core::t_string->vx_new_from_string("id"),
          table->id()
        );
        vx_web_html::Type_thead* thead = table->thead();
        vx_web_html::Type_tbody* tbody = table->tbody();
        vx_core::Type_string* shead = vx_web_html::f_string_from_thead_indent(
          thead,
          vx_core::f_plus1(indent)
        );
        vx_core::Type_string* sbody = vx_web_html::f_string_from_tbody_indent(
          tbody,
          vx_core::f_plus1(indent)
        );
        return vx_core::f_new(
          vx_core::t_string,
          vx_core::t_anylist->vx_new(
            sindent,
            vx_core::t_string->vx_new_from_string("<table"),
            sid,
            vx_core::t_string->vx_new_from_string(">"),
            shead,
            sbody,
            sindent,
            vx_core::t_string->vx_new_from_string("</table>")
          )
        );
      })
    );
    return output;
  }

  /**
   * @function string_from_tbody_indent
   * Returns string from tbody
   * @param  {tbody} tbody
   * @param  {int} indent
   * @return {string}
   * (func string<-tbody-indent)
   */
  //class Func_string_from_tbody_indent {

    template<typename... Args> vx_web_html::Func_string_from_tbody_indent* vx_web_html::Func_string_from_tbody_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_tbody_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_tbody_indent* vx_web_html::Func_string_from_tbody_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_tbody_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_tbody_indent::vx_typedef() {return vx_web_html::t_string_from_tbody_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_tbody_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-tbody-indent", // name
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

    vx_web_html::Func_string_from_tbody_indent* vx_web_html::Func_string_from_tbody_indent::vx_empty() {return vx_web_html::e_string_from_tbody_indent;}
    vx_web_html::Func_string_from_tbody_indent* vx_web_html::Func_string_from_tbody_indent::vx_type() {return vx_web_html::t_string_from_tbody_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_tbody_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_tbody* tbody = vx_core::f_any_from_any(vx_web_html::t_tbody, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_tbody_indent(tbody, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_tbody_indent::vx_string_from_tbody_indent(vx_web_html::Type_tbody* tbody, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_tbody_indent(tbody, indent);
    }

  //}

  vx_web_html::Func_string_from_tbody_indent* vx_web_html::e_string_from_tbody_indent = new vx_web_html::Func_string_from_tbody_indent();
  vx_web_html::Func_string_from_tbody_indent* vx_web_html::t_string_from_tbody_indent = new vx_web_html::Func_string_from_tbody_indent();

  vx_core::Type_string* vx_web_html::f_string_from_tbody_indent(vx_web_html::Type_tbody* tbody, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([tbody, indent]() {
        vx_web_html::Type_trlist* nodes = tbody->nodes();
        return vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, vx_core::t_string->vx_new_from_string("tbody"), vx_core::t_string->vx_new_from_string(""), indent);
      })
    );
    return output;
  }

  /**
   * @function string_from_td_indent
   * Returns string from td
   * @param  {td} td
   * @param  {int} indent
   * @return {string}
   * (func string<-td-indent)
   */
  //class Func_string_from_td_indent {

    template<typename... Args> vx_web_html::Func_string_from_td_indent* vx_web_html::Func_string_from_td_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_td_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_td_indent* vx_web_html::Func_string_from_td_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_td_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_td_indent::vx_typedef() {return vx_web_html::t_string_from_td_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_td_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-td-indent", // name
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

    vx_web_html::Func_string_from_td_indent* vx_web_html::Func_string_from_td_indent::vx_empty() {return vx_web_html::e_string_from_td_indent;}
    vx_web_html::Func_string_from_td_indent* vx_web_html::Func_string_from_td_indent::vx_type() {return vx_web_html::t_string_from_td_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_td_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_td* td = vx_core::f_any_from_any(vx_web_html::t_td, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_td_indent(td, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_td_indent::vx_string_from_td_indent(vx_web_html::Type_td* td, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_td_indent(td, indent);
    }

  //}

  vx_web_html::Func_string_from_td_indent* vx_web_html::e_string_from_td_indent = new vx_web_html::Func_string_from_td_indent();
  vx_web_html::Func_string_from_td_indent* vx_web_html::t_string_from_td_indent = new vx_web_html::Func_string_from_td_indent();

  vx_core::Type_string* vx_web_html::f_string_from_td_indent(vx_web_html::Type_td* td, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([td, indent]() {
        vx_web_html::Type_divchildlist* nodes = td->nodes();
        return vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, vx_core::t_string->vx_new_from_string("td"), vx_core::t_string->vx_new_from_string(""), indent);
      })
    );
    return output;
  }

  /**
   * @function string_from_thead_indent
   * Returns string from thead
   * @param  {thead} thead
   * @param  {int} indent
   * @return {string}
   * (func string<-thead-indent)
   */
  //class Func_string_from_thead_indent {

    template<typename... Args> vx_web_html::Func_string_from_thead_indent* vx_web_html::Func_string_from_thead_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_thead_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_thead_indent* vx_web_html::Func_string_from_thead_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_thead_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_thead_indent::vx_typedef() {return vx_web_html::t_string_from_thead_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_thead_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-thead-indent", // name
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

    vx_web_html::Func_string_from_thead_indent* vx_web_html::Func_string_from_thead_indent::vx_empty() {return vx_web_html::e_string_from_thead_indent;}
    vx_web_html::Func_string_from_thead_indent* vx_web_html::Func_string_from_thead_indent::vx_type() {return vx_web_html::t_string_from_thead_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_thead_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_thead* thead = vx_core::f_any_from_any(vx_web_html::t_thead, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_thead_indent(thead, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_thead_indent::vx_string_from_thead_indent(vx_web_html::Type_thead* thead, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_thead_indent(thead, indent);
    }

  //}

  vx_web_html::Func_string_from_thead_indent* vx_web_html::e_string_from_thead_indent = new vx_web_html::Func_string_from_thead_indent();
  vx_web_html::Func_string_from_thead_indent* vx_web_html::t_string_from_thead_indent = new vx_web_html::Func_string_from_thead_indent();

  vx_core::Type_string* vx_web_html::f_string_from_thead_indent(vx_web_html::Type_thead* thead, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([thead, indent]() {
        vx_web_html::Type_trlist* nodes = thead->nodes();
        return vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, vx_core::t_string->vx_new_from_string("thead"), vx_core::t_string->vx_new_from_string(""), indent);
      })
    );
    return output;
  }

  /**
   * @function string_from_title_indent
   * Returns string from h2
   * @param  {title} title
   * @param  {int} indent
   * @return {string}
   * (func string<-title-indent)
   */
  //class Func_string_from_title_indent {

    template<typename... Args> vx_web_html::Func_string_from_title_indent* vx_web_html::Func_string_from_title_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_title_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_title_indent* vx_web_html::Func_string_from_title_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_title_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_title_indent::vx_typedef() {return vx_web_html::t_string_from_title_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_title_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-title-indent", // name
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

    vx_web_html::Func_string_from_title_indent* vx_web_html::Func_string_from_title_indent::vx_empty() {return vx_web_html::e_string_from_title_indent;}
    vx_web_html::Func_string_from_title_indent* vx_web_html::Func_string_from_title_indent::vx_type() {return vx_web_html::t_string_from_title_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_title_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_title* title = vx_core::f_any_from_any(vx_web_html::t_title, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_title_indent(title, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_title_indent::vx_string_from_title_indent(vx_web_html::Type_title* title, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_title_indent(title, indent);
    }

  //}

  vx_web_html::Func_string_from_title_indent* vx_web_html::e_string_from_title_indent = new vx_web_html::Func_string_from_title_indent();
  vx_web_html::Func_string_from_title_indent* vx_web_html::t_string_from_title_indent = new vx_web_html::Func_string_from_title_indent();

  vx_core::Type_string* vx_web_html::f_string_from_title_indent(vx_web_html::Type_title* title, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([indent, title]() {
        vx_core::Type_string* sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::Type_string* text = title->text();
        return vx_core::f_new(
          vx_core::t_string,
          vx_core::t_anylist->vx_new(
            sindent,
            vx_core::t_string->vx_new_from_string("<title>"),
            text,
            vx_core::t_string->vx_new_from_string("</title>")
          )
        );
      })
    );
    return output;
  }

  /**
   * @function string_from_tr_indent
   * Returns string from tr
   * @param  {tr} tr
   * @param  {int} indent
   * @return {string}
   * (func string<-tr-indent)
   */
  //class Func_string_from_tr_indent {

    template<typename... Args> vx_web_html::Func_string_from_tr_indent* vx_web_html::Func_string_from_tr_indent::vx_new(Args*... args) {
      vx_web_html::Func_string_from_tr_indent* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_tr_indent* vx_web_html::Func_string_from_tr_indent::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_tr_indent* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_tr_indent::vx_typedef() {return vx_web_html::t_string_from_tr_indent->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_tr_indent::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-tr-indent", // name
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

    vx_web_html::Func_string_from_tr_indent* vx_web_html::Func_string_from_tr_indent::vx_empty() {return vx_web_html::e_string_from_tr_indent;}
    vx_web_html::Func_string_from_tr_indent* vx_web_html::Func_string_from_tr_indent::vx_type() {return vx_web_html::t_string_from_tr_indent;}

    vx_core::Type_any* vx_web_html::Func_string_from_tr_indent::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_tr* tr = vx_core::f_any_from_any(vx_web_html::t_tr, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_int* indent = vx_core::f_any_from_any(vx_core::t_int, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_string_from_tr_indent(tr, indent);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_tr_indent::vx_string_from_tr_indent(vx_web_html::Type_tr* tr, vx_core::Type_int* indent) {
      return vx_web_html::f_string_from_tr_indent(tr, indent);
    }

  //}

  vx_web_html::Func_string_from_tr_indent* vx_web_html::e_string_from_tr_indent = new vx_web_html::Func_string_from_tr_indent();
  vx_web_html::Func_string_from_tr_indent* vx_web_html::t_string_from_tr_indent = new vx_web_html::Func_string_from_tr_indent();

  vx_core::Type_string* vx_web_html::f_string_from_tr_indent(vx_web_html::Type_tr* tr, vx_core::Type_int* indent) {
    vx_core::Type_string* output = vx_core::e_string;
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->fn_new([tr, indent]() {
        vx_web_html::Type_tdlist* nodes = tr->nodes();
        return vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, vx_core::t_string->vx_new_from_string("tr"), vx_core::t_string->vx_new_from_string(""), indent);
      })
    );
    return output;
  }

  /**
   * @function string_from_uri
   * Decode a URI string
   * @param  {string} uri
   * @return {string}
   * (func string<-uri)
   */
  //class Func_string_from_uri {

    template<typename... Args> vx_web_html::Func_string_from_uri* vx_web_html::Func_string_from_uri::vx_new(Args*... args) {
      vx_web_html::Func_string_from_uri* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_string_from_uri* vx_web_html::Func_string_from_uri::vx_copy(Args*... args) {
      vx_web_html::Func_string_from_uri* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_string_from_uri::vx_typedef() {return vx_web_html::t_string_from_uri->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_string_from_uri::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-uri", // name
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

    vx_web_html::Func_string_from_uri* vx_web_html::Func_string_from_uri::vx_empty() {return vx_web_html::e_string_from_uri;}
    vx_web_html::Func_string_from_uri* vx_web_html::Func_string_from_uri::vx_type() {return vx_web_html::t_string_from_uri;}

    vx_core::Func_any_from_any* vx_web_html::Func_string_from_uri::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_web_html::Func_string_from_uri::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_core::Type_string* inputval = (vx_core::Type_string)value;
      vx_core::Type_any* outputval = vx_web_html::f_string_from_uri(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_web_html::Func_string_from_uri::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_string* uri = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_web_html::f_string_from_uri(uri);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_string_from_uri::vx_string_from_uri(vx_core::Type_string* uri) {
      return vx_web_html::f_string_from_uri(uri);
    }

  //}

  vx_web_html::Func_string_from_uri* vx_web_html::e_string_from_uri = new vx_web_html::Func_string_from_uri();
  vx_web_html::Func_string_from_uri* vx_web_html::t_string_from_uri = new vx_web_html::Func_string_from_uri();

  vx_core::Type_string* vx_web_html::f_string_from_uri(vx_core::Type_string* uri) {
    vx_core::Type_string* output = vx_core::e_string;
    return output;
  }

  /**
   * @function style_from_stylesheet_name
   * Return style from stylesheet.stylemap
   * @param  {stylesheet} stylesheet
   * @param  {string} name
   * @return {style}
   * (func style<-stylesheet-name)
   */
  //class Func_style_from_stylesheet_name {

    template<typename... Args> vx_web_html::Func_style_from_stylesheet_name* vx_web_html::Func_style_from_stylesheet_name::vx_new(Args*... args) {
      vx_web_html::Func_style_from_stylesheet_name* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_style_from_stylesheet_name* vx_web_html::Func_style_from_stylesheet_name::vx_copy(Args*... args) {
      vx_web_html::Func_style_from_stylesheet_name* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_style_from_stylesheet_name::vx_typedef() {return vx_web_html::t_style_from_stylesheet_name->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_style_from_stylesheet_name::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "style<-stylesheet-name", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/web/html", // pkgname
          "style", // name
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

    vx_web_html::Func_style_from_stylesheet_name* vx_web_html::Func_style_from_stylesheet_name::vx_empty() {return vx_web_html::e_style_from_stylesheet_name;}
    vx_web_html::Func_style_from_stylesheet_name* vx_web_html::Func_style_from_stylesheet_name::vx_type() {return vx_web_html::t_style_from_stylesheet_name;}

    vx_core::Type_any* vx_web_html::Func_style_from_stylesheet_name::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_stylesheet* stylesheet = vx_core::f_any_from_any(vx_web_html::t_stylesheet, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      vx_core::Type_string* name = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(1)));
      output = vx_web_html::f_style_from_stylesheet_name(stylesheet, name);
      return output;
    }

    vx_web_html::Type_style* vx_web_html::Func_style_from_stylesheet_name::vx_style_from_stylesheet_name(vx_web_html::Type_stylesheet* stylesheet, vx_core::Type_string* name) {
      return vx_web_html::f_style_from_stylesheet_name(stylesheet, name);
    }

  //}

  vx_web_html::Func_style_from_stylesheet_name* vx_web_html::e_style_from_stylesheet_name = new vx_web_html::Func_style_from_stylesheet_name();
  vx_web_html::Func_style_from_stylesheet_name* vx_web_html::t_style_from_stylesheet_name = new vx_web_html::Func_style_from_stylesheet_name();

  vx_web_html::Type_style* vx_web_html::f_style_from_stylesheet_name(vx_web_html::Type_stylesheet* stylesheet, vx_core::Type_string* name) {
    vx_web_html::Type_style* output = vx_web_html::e_style;
    output = vx_core::f_any_from_map(
      vx_web_html::t_style,
      vx_web_html::f_stylemap_from_stylesheet(stylesheet),
      name
    );
    return output;
  }

  /**
   * @function stylemap_from_stylelist
   * Returns a stylemap from a given stylelist
   * @param  {stylelist} stylelist
   * @return {stylemap}
   * (func stylemap<-stylelist)
   */
  //class Func_stylemap_from_stylelist {

    template<typename... Args> vx_web_html::Func_stylemap_from_stylelist* vx_web_html::Func_stylemap_from_stylelist::vx_new(Args*... args) {
      vx_web_html::Func_stylemap_from_stylelist* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_stylemap_from_stylelist* vx_web_html::Func_stylemap_from_stylelist::vx_copy(Args*... args) {
      vx_web_html::Func_stylemap_from_stylelist* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_stylemap_from_stylelist::vx_typedef() {return vx_web_html::t_stylemap_from_stylelist->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_stylemap_from_stylelist::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "stylemap<-stylelist", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/web/html", // pkgname
          "stylemap", // name
          ":map", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_web_html::t_style), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_web_html::Func_stylemap_from_stylelist* vx_web_html::Func_stylemap_from_stylelist::vx_empty() {return vx_web_html::e_stylemap_from_stylelist;}
    vx_web_html::Func_stylemap_from_stylelist* vx_web_html::Func_stylemap_from_stylelist::vx_type() {return vx_web_html::t_stylemap_from_stylelist;}

    vx_core::Func_any_from_any* vx_web_html::Func_stylemap_from_stylelist::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_web_html::Func_stylemap_from_stylelist::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_web_html::Type_stylelist* inputval = (vx_web_html::Type_stylelist)value;
      vx_core::Type_any* outputval = vx_web_html::f_stylemap_from_stylelist(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_web_html::Func_stylemap_from_stylelist::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_stylelist* stylelist = vx_core::f_any_from_any(vx_web_html::t_stylelist, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_web_html::f_stylemap_from_stylelist(stylelist);
      return output;
    }

    vx_web_html::Type_stylemap* vx_web_html::Func_stylemap_from_stylelist::vx_stylemap_from_stylelist(vx_web_html::Type_stylelist* stylelist) {
      return vx_web_html::f_stylemap_from_stylelist(stylelist);
    }

  //}

  vx_web_html::Func_stylemap_from_stylelist* vx_web_html::e_stylemap_from_stylelist = new vx_web_html::Func_stylemap_from_stylelist();
  vx_web_html::Func_stylemap_from_stylelist* vx_web_html::t_stylemap_from_stylelist = new vx_web_html::Func_stylemap_from_stylelist();

  vx_web_html::Type_stylemap* vx_web_html::f_stylemap_from_stylelist(vx_web_html::Type_stylelist* stylelist) {
    vx_web_html::Type_stylemap* output = vx_web_html::e_stylemap;
    output = vx_core::f_map_from_list(
      vx_web_html::t_stylemap,
      stylelist,
      vx_core::t_any_from_any->fn_new([](vx_core::Type_any* style_any) {
        vx_web_html::Type_style* style = vx_core::f_any_from_any(vx_web_html::t_style, style_any);
        return 
          style->name();
      })
    );
    return output;
  }

  /**
   * @function stylemap_from_stylesheet
   * Return stylemap from stylesheet
   * @param  {stylesheet} stylesheet
   * @return {stylemap}
   * (func stylemap<-stylesheet)
   */
  //class Func_stylemap_from_stylesheet {

    template<typename... Args> vx_web_html::Func_stylemap_from_stylesheet* vx_web_html::Func_stylemap_from_stylesheet::vx_new(Args*... args) {
      vx_web_html::Func_stylemap_from_stylesheet* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_stylemap_from_stylesheet* vx_web_html::Func_stylemap_from_stylesheet::vx_copy(Args*... args) {
      vx_web_html::Func_stylemap_from_stylesheet* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_stylemap_from_stylesheet::vx_typedef() {return vx_web_html::t_stylemap_from_stylesheet->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_stylemap_from_stylesheet::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "stylemap<-stylesheet", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/web/html", // pkgname
          "stylemap", // name
          ":map", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_web_html::t_style), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_web_html::Func_stylemap_from_stylesheet* vx_web_html::Func_stylemap_from_stylesheet::vx_empty() {return vx_web_html::e_stylemap_from_stylesheet;}
    vx_web_html::Func_stylemap_from_stylesheet* vx_web_html::Func_stylemap_from_stylesheet::vx_type() {return vx_web_html::t_stylemap_from_stylesheet;}

    vx_core::Func_any_from_any* vx_web_html::Func_stylemap_from_stylesheet::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_web_html::Func_stylemap_from_stylesheet::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_web_html::Type_stylesheet* inputval = (vx_web_html::Type_stylesheet)value;
      vx_core::Type_any* outputval = vx_web_html::f_stylemap_from_stylesheet(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_web_html::Func_stylemap_from_stylesheet::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_stylesheet* stylesheet = vx_core::f_any_from_any(vx_web_html::t_stylesheet, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_web_html::f_stylemap_from_stylesheet(stylesheet);
      return output;
    }

    vx_web_html::Type_stylemap* vx_web_html::Func_stylemap_from_stylesheet::vx_stylemap_from_stylesheet(vx_web_html::Type_stylesheet* stylesheet) {
      return vx_web_html::f_stylemap_from_stylesheet(stylesheet);
    }

  //}

  vx_web_html::Func_stylemap_from_stylesheet* vx_web_html::e_stylemap_from_stylesheet = new vx_web_html::Func_stylemap_from_stylesheet();
  vx_web_html::Func_stylemap_from_stylesheet* vx_web_html::t_stylemap_from_stylesheet = new vx_web_html::Func_stylemap_from_stylesheet();

  vx_web_html::Type_stylemap* vx_web_html::f_stylemap_from_stylesheet(vx_web_html::Type_stylesheet* stylesheet) {
    vx_web_html::Type_stylemap* output = vx_web_html::e_stylemap;
    output = stylesheet->stylemap();
    return output;
  }

  /**
   * @function styles_from_stylesheet
   * Return style from stylesheet.stylemap
   * @param  {stylesheet} stylesheet
   * @return {stylelist}
   * (func styles<-stylesheet)
   */
  //class Func_styles_from_stylesheet {

    template<typename... Args> vx_web_html::Func_styles_from_stylesheet* vx_web_html::Func_styles_from_stylesheet::vx_new(Args*... args) {
      vx_web_html::Func_styles_from_stylesheet* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_styles_from_stylesheet* vx_web_html::Func_styles_from_stylesheet::vx_copy(Args*... args) {
      vx_web_html::Func_styles_from_stylesheet* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_styles_from_stylesheet::vx_typedef() {return vx_web_html::t_styles_from_stylesheet->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_styles_from_stylesheet::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "styles<-stylesheet", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/web/html", // pkgname
          "stylelist", // name
          ":list", // extends
          vx_core::e_typelist, // traits
          vx_core::t_typelist->vx_new(vx_web_html::t_style), // allowtypes
          vx_core::e_typelist, // disallowtypes
          vx_core::e_funclist, // allowfuncs
          vx_core::e_funclist, // disallowfuncs
          vx_core::e_anylist, // allowvalues
          vx_core::e_anylist, // disallowvalues
          vx_core::e_argmap // properties
        ) // typedef
      );
    }

    vx_web_html::Func_styles_from_stylesheet* vx_web_html::Func_styles_from_stylesheet::vx_empty() {return vx_web_html::e_styles_from_stylesheet;}
    vx_web_html::Func_styles_from_stylesheet* vx_web_html::Func_styles_from_stylesheet::vx_type() {return vx_web_html::t_styles_from_stylesheet;}

    vx_core::Func_any_from_any* vx_web_html::Func_styles_from_stylesheet::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_web_html::Func_styles_from_stylesheet::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_web_html::Type_stylesheet* inputval = (vx_web_html::Type_stylesheet)value;
      vx_core::Type_any* outputval = vx_web_html::f_styles_from_stylesheet(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_web_html::Func_styles_from_stylesheet::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_stylesheet* stylesheet = vx_core::f_any_from_any(vx_web_html::t_stylesheet, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_web_html::f_styles_from_stylesheet(stylesheet);
      return output;
    }

    vx_web_html::Type_stylelist* vx_web_html::Func_styles_from_stylesheet::vx_styles_from_stylesheet(vx_web_html::Type_stylesheet* stylesheet) {
      return vx_web_html::f_styles_from_stylesheet(stylesheet);
    }

  //}

  vx_web_html::Func_styles_from_stylesheet* vx_web_html::e_styles_from_stylesheet = new vx_web_html::Func_styles_from_stylesheet();
  vx_web_html::Func_styles_from_stylesheet* vx_web_html::t_styles_from_stylesheet = new vx_web_html::Func_styles_from_stylesheet();

  vx_web_html::Type_stylelist* vx_web_html::f_styles_from_stylesheet(vx_web_html::Type_stylesheet* stylesheet) {
    vx_web_html::Type_stylelist* output = vx_web_html::e_stylelist;
    output = stylesheet->styles();
    return output;
  }

  /**
   * @function stylesheet_loadmap
   * Decode a URI string
   * @param  {stylesheet} stylesheet
   * @return {stylesheet}
   * (func stylesheet-loadmap)
   */
  //class Func_stylesheet_loadmap {

    template<typename... Args> vx_web_html::Func_stylesheet_loadmap* vx_web_html::Func_stylesheet_loadmap::vx_new(Args*... args) {
      vx_web_html::Func_stylesheet_loadmap* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_stylesheet_loadmap* vx_web_html::Func_stylesheet_loadmap::vx_copy(Args*... args) {
      vx_web_html::Func_stylesheet_loadmap* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_stylesheet_loadmap::vx_typedef() {return vx_web_html::t_stylesheet_loadmap->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_stylesheet_loadmap::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "stylesheet-loadmap", // name
        0, // idx
        false, // async
        vx_core::Type_typedef::vx_typedef_new(
          "vx/web/html", // pkgname
          "stylesheet", // name
          ":struct", // extends
          vx_core::t_typelist->vx_new(vx_web_html::t_node, vx_web_html::t_headchild), // traits
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

    vx_web_html::Func_stylesheet_loadmap* vx_web_html::Func_stylesheet_loadmap::vx_empty() {return vx_web_html::e_stylesheet_loadmap;}
    vx_web_html::Func_stylesheet_loadmap* vx_web_html::Func_stylesheet_loadmap::vx_type() {return vx_web_html::t_stylesheet_loadmap;}

    vx_core::Func_any_from_any* vx_web_html::Func_stylesheet_loadmap::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_web_html::Func_stylesheet_loadmap::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_web_html::Type_stylesheet* inputval = (vx_web_html::Type_stylesheet)value;
      vx_core::Type_any* outputval = vx_web_html::f_stylesheet_loadmap(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_web_html::Func_stylesheet_loadmap::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_web_html::Type_stylesheet* stylesheet = vx_core::f_any_from_any(vx_web_html::t_stylesheet, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_web_html::f_stylesheet_loadmap(stylesheet);
      return output;
    }

    vx_web_html::Type_stylesheet* vx_web_html::Func_stylesheet_loadmap::vx_stylesheet_loadmap(vx_web_html::Type_stylesheet* stylesheet) {
      return vx_web_html::f_stylesheet_loadmap(stylesheet);
    }

  //}

  vx_web_html::Func_stylesheet_loadmap* vx_web_html::e_stylesheet_loadmap = new vx_web_html::Func_stylesheet_loadmap();
  vx_web_html::Func_stylesheet_loadmap* vx_web_html::t_stylesheet_loadmap = new vx_web_html::Func_stylesheet_loadmap();

  vx_web_html::Type_stylesheet* vx_web_html::f_stylesheet_loadmap(vx_web_html::Type_stylesheet* stylesheet) {
    vx_web_html::Type_stylesheet* output = vx_web_html::e_stylesheet;
    output = vx_core::f_copy(
      stylesheet,
      vx_core::t_anylist->vx_new(
        vx_core::t_string->vx_new_from_string(":stylemap"),
        vx_web_html::f_stylemap_from_stylelist(
          stylesheet->styles()
        )
      )
    );
    return output;
  }

  /**
   * @function uri_from_string
   * Encode a URI string
   * @param  {string} text
   * @return {string}
   * (func uri<-string)
   */
  //class Func_uri_from_string {

    template<typename... Args> vx_web_html::Func_uri_from_string* vx_web_html::Func_uri_from_string::vx_new(Args*... args) {
      vx_web_html::Func_uri_from_string* output;
      return output;
    }

    template<typename... Args> vx_web_html::Func_uri_from_string* vx_web_html::Func_uri_from_string::vx_copy(Args*... args) {
      vx_web_html::Func_uri_from_string* output;
      return output;
    }

    vx_core::Type_typedef* vx_web_html::Func_uri_from_string::vx_typedef() {return vx_web_html::t_uri_from_string->vx_typedef();}

    vx_core::Type_funcdef* vx_web_html::Func_uri_from_string::vx_funcdef() {
      return vx_core::Type_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "uri<-string", // name
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

    vx_web_html::Func_uri_from_string* vx_web_html::Func_uri_from_string::vx_empty() {return vx_web_html::e_uri_from_string;}
    vx_web_html::Func_uri_from_string* vx_web_html::Func_uri_from_string::vx_type() {return vx_web_html::t_uri_from_string;}

    vx_core::Func_any_from_any* vx_web_html::Func_uri_from_string::fn_new(vx_core::Func_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> T* vx_web_html::Func_uri_from_string::f_any_from_any(T* generic_any_1, U* value) {
      T* output = vx_core::f_empty(generic_any_1);
      vx_core::Type_string* inputval = (vx_core::Type_string)value;
      vx_core::Type_any* outputval = vx_web_html::f_uri_from_string(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any* vx_web_html::Func_uri_from_string::vx_repl(vx_core::Type_anylist* arglist) {
      vx_core::Type_any* output = vx_core::e_any;
      vx_core::Type_string* text = vx_core::f_any_from_any(vx_core::t_string, arglist->vx_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_web_html::f_uri_from_string(text);
      return output;
    }

    vx_core::Type_string* vx_web_html::Func_uri_from_string::vx_uri_from_string(vx_core::Type_string* text) {
      return vx_web_html::f_uri_from_string(text);
    }

  //}

  vx_web_html::Func_uri_from_string* vx_web_html::e_uri_from_string = new vx_web_html::Func_uri_from_string();
  vx_web_html::Func_uri_from_string* vx_web_html::t_uri_from_string = new vx_web_html::Func_uri_from_string();

  vx_core::Type_string* vx_web_html::f_uri_from_string(vx_core::Type_string* text) {
    vx_core::Type_string* output = vx_core::e_string;
    return output;
  }


//}
