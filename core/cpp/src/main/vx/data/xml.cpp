#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/data/textblock.hpp"
#include "vx/data/xml.hpp"

//namespace vx_data_xml {

  /**
   * type: xml
   * (type xml)
   */
  //class Type_xml {
    // nodes()
    vx_data_xml::Type_xmlnodelist vx_data_xml::Class_xml::nodes() {
      vx_data_xml::Type_xmlnodelist output = this->vx_p_nodes;
      if (output == NULL) {
        output = vx_data_xml::t_xmlnodelist;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any vx_data_xml::Class_xml::vx_get_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":nodes") {
        output = this->nodes();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_data_xml::Class_xml::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":nodes"] = this->nodes();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_xml::Class_xml::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_xml::e_xml->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_xml::Class_xml::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_xml::Type_xml output;
      vx_data_xml::Class_xml* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val->vx_msgblock(), vals);
      output->vx_p_nodes = val->nodes();
      std::set<std::string> validkeys;
      validkeys.insert(":nodes");
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new xml) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":nodes") {
            if (valsubtype == vx_data_xml::t_xmlnodelist) {
              output->vx_p_nodes = vx_core::any_from_any(vx_data_xml::t_xmlnodelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new xml :nodes " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new xml) - Invalid Key: " + key);
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

    template <class T> std::shared_ptr<T> vx_data_xml::Class_xml::vx_empty(std::shared_ptr<T> val) {return vx_data_xml::e_xml;}
    template <class T> std::shared_ptr<T> vx_data_xml::Class_xml::vx_type(std::shared_ptr<T> val) {return vx_data_xml::t_xml;}

    vx_core::Type_typedef vx_data_xml::Class_xml::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/xml", // pkgname
        "xml", // name
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

    vx_data_xml::Type_xml vx_data_xml::e_xml = std::make_shared<vx_data_xml::Class_xml>();
    vx_data_xml::Type_xml vx_data_xml::t_xml = std::make_shared<vx_data_xml::Class_xml>();
  //}

  /**
   * type: xmlnode
   * (type xmlnode)
   */
  //class Type_xmlnode {
    // nodes()
    vx_data_xml::Type_xmlnode vx_data_xml::Class_xmlnode::nodes() {
      vx_data_xml::Type_xmlnode output = this->vx_p_nodes;
      if (output == NULL) {
        output = vx_data_xml::t_xmlnode;
      }
      return output;
    }

    // props()
    vx_data_xml::Type_xmlpropmap vx_data_xml::Class_xmlnode::props() {
      vx_data_xml::Type_xmlpropmap output = this->vx_p_props;
      if (output == NULL) {
        output = vx_data_xml::t_xmlpropmap;
      }
      return output;
    }

    // tag()
    vx_core::Type_string vx_data_xml::Class_xmlnode::tag() {
      vx_core::Type_string output = this->vx_p_tag;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // text()
    vx_core::Type_string vx_data_xml::Class_xmlnode::text() {
      vx_core::Type_string output = this->vx_p_text;
      if (output == NULL) {
        output = vx_core::t_string;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any vx_data_xml::Class_xmlnode::vx_get_any(vx_core::Type_string key) {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":nodes") {
        output = this->nodes();
      } else if (skey == ":props") {
        output = this->props();
      } else if (skey == ":tag") {
        output = this->tag();
      } else if (skey == ":text") {
        output = this->text();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany vx_data_xml::Class_xmlnode::vx_map() {
      vx_core::vx_Type_mapany output;
      output[":nodes"] = this->nodes();
      output[":props"] = this->props();
      output[":tag"] = this->tag();
      output[":text"] = this->text();
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_xml::Class_xmlnode::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_xml::e_xmlnode->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_xml::Class_xmlnode::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_xml::Type_xmlnode output;
      vx_data_xml::Class_xmlnode* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val->vx_msgblock(), vals);
      output->vx_p_nodes = val->nodes();
      output->vx_p_props = val->props();
      output->vx_p_tag = val->tag();
      output->vx_p_text = val->text();
      std::set<std::string> validkeys;
      validkeys.insert(":nodes");
      validkeys.insert(":props");
      validkeys.insert(":tag");
      validkeys.insert(":text");
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
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new xmlnode) - Invalid Key Type: " + vx_core::string_from_any(valsub));
            msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":nodes") {
            if (valsubtype == vx_data_xml::t_xmlnode) {
              output->vx_p_nodes = vx_core::any_from_any(vx_data_xml::t_xmlnode, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new xmlnode :nodes " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":props") {
            if (valsubtype == vx_data_xml::t_xmlpropmap) {
              output->vx_p_props = vx_core::any_from_any(vx_data_xml::t_xmlpropmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new xmlnode :props " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":tag") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_tag = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new xmlnode :tag " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else if (key == ":text") {
            if (valsubtype == vx_core::t_string) {
              output->vx_p_text = vx_core::any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new xmlnode :text " + vx_core::string_from_any(valsub) + ") - Invalid Value");
              msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new xmlnode) - Invalid Key: " + key);
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

    template <class T> std::shared_ptr<T> vx_data_xml::Class_xmlnode::vx_empty(std::shared_ptr<T> val) {return vx_data_xml::e_xmlnode;}
    template <class T> std::shared_ptr<T> vx_data_xml::Class_xmlnode::vx_type(std::shared_ptr<T> val) {return vx_data_xml::t_xmlnode;}

    vx_core::Type_typedef vx_data_xml::Class_xmlnode::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/xml", // pkgname
        "xmlnode", // name
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

    vx_data_xml::Type_xmlnode vx_data_xml::e_xmlnode = std::make_shared<vx_data_xml::Class_xmlnode>();
    vx_data_xml::Type_xmlnode vx_data_xml::t_xmlnode = std::make_shared<vx_data_xml::Class_xmlnode>();
  //}

  /**
   * type: xmlnodelist
   * (type xmlnodelist)
   */
  //class Type_xmlnodelist {
    vx_core::vx_Type_listany vx_data_xml::Class_xmlnodelist::vx_list() {
      return vx_core::list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_data_xml::Type_xmlnode vx_data_xml::Class_xmlnodelist::vx_get_xmlnode(vx_core::Type_int index) {
      vx_data_xml::Type_xmlnode output = vx_data_xml::e_xmlnode;
      vx_data_xml::Class_xmlnodelist* list = this;
      int iindex = index->vx_int();
      std::vector<vx_data_xml::Type_xmlnode> listval = list->vx_p_list;
      if (iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_data_xml::Type_xmlnode> vx_data_xml::Class_xmlnodelist::vx_listxmlnode() {return vx_p_list;}

    vx_core::Type_any vx_data_xml::Class_xmlnodelist::vx_get_any(vx_core::Type_int index) {
      return this->vx_get_xmlnode(index);
    }

    template <class T> std::shared_ptr<T> vx_data_xml::Class_xmlnodelist::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_xml::e_xmlnodelist->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_xml::Class_xmlnodelist::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_xml::Type_xmlnodelist output;
      vx_data_xml::Class_xmlnodelist* val = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(val->vx_msgblock(), vals);
      std::vector<vx_data_xml::Type_xmlnode> listval = val->vx_listxmlnode();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {valsub});
        } else if (valsubtype == vx_data_xml::t_xmlnode) {
          listval.push_back(vx_core::any_from_any(vx_data_xml::t_xmlnode, valsub));
        } else if (valsubtype == vx_data_xml::t_xmlnodelist) {
          vx_data_xml::Type_xmlnodelist multi = vx_core::any_from_any(vx_data_xml::t_xmlnodelist, valsub);
          listval = vx_core::listaddall(listval, multi->vx_listxmlnode());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(new xmlnodelist) - Invalid Type: " + vx_core::string_from_any(valsub));
          msgblock = msgblock->vx_copy(vx_core::t_msgblock, {msg});
        }
      }
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_xml::Class_xmlnodelist::vx_empty(std::shared_ptr<T> val) {return vx_data_xml::e_xmlnodelist;}
    template <class T> std::shared_ptr<T> vx_data_xml::Class_xmlnodelist::vx_type(std::shared_ptr<T> val) {return vx_data_xml::t_xmlnodelist;}

    vx_core::Type_typedef vx_data_xml::Class_xmlnodelist::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/xml", // pkgname
        "xmlnodelist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_data_xml::t_xmlnode}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_data_xml::Type_xmlnodelist vx_data_xml::e_xmlnodelist = std::make_shared<vx_data_xml::Class_xmlnodelist>();
    vx_data_xml::Type_xmlnodelist vx_data_xml::t_xmlnodelist = std::make_shared<vx_data_xml::Class_xmlnodelist>();
  //}

  /**
   * type: xmlpropmap
   * (type xmlpropmap)
   */
  //class Type_xmlpropmap {
    // vx_map()
    vx_core::vx_Type_mapany vx_data_xml::Class_xmlpropmap::vx_map() {
      return vx_core::map_from_map(vx_core::t_any, this->vx_p_map);
    }

    // vx_get_string(key)
    vx_core::Type_string vx_data_xml::Class_xmlpropmap::vx_get_string(vx_core::Type_string key) {
      vx_core::Type_string output = vx_core::e_string;
      vx_data_xml::Class_xmlpropmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_string> mapval = map->vx_p_map;
      output = vx_core::any_from_map(mapval, skey, vx_core::e_string);
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any vx_data_xml::Class_xmlpropmap::vx_get_any(vx_core::Type_string key) {
      return this->vx_get_string(key);
    }

    // vx_mapstring()
    std::map<std::string, vx_core::Type_string> vx_data_xml::Class_xmlpropmap::vx_mapstring() {return vx_p_map;}

    // vx_new_from_map(mapval)
    template <class T> std::shared_ptr<T>  vx_data_xml::Class_xmlpropmap::vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval) {
      vx_data_xml::Type_xmlpropmap output;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_core::Type_string> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = vx_core::t_any->vx_type_from_any(val);
        if (valtype == vx_core::t_string) {
          vx_core::Type_string castval = vx_core::any_from_any(vx_core::t_string, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("(xmlpropmap) Invalid Value: " + vx_core::string_from_any(val) + "");
          msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, msg});
        }
      }
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_xml::Class_xmlpropmap::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {return vx_data_xml::e_xmlpropmap->vx_copy(generic_any_1, vals);}
    template <class T> std::shared_ptr<T> vx_data_xml::Class_xmlpropmap::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_xml::Type_xmlpropmap output;
      vx_data_xml::Class_xmlpropmap* valmap = this;
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock->vx_msgblock_from_copy_arrayval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_core::Type_string> mapval;
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = vx_core::t_any->vx_type_from_any(valsub);
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, valsub});
        } else if (key == "") {
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstring = vx_core::any_from_any(vx_core::t_string, valsub);
            key = valstring->vx_string();
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("Key Expected: " + vx_core::string_from_any(valsub) + "");
            msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, msg});
          }
        } else {
          vx_core::Type_string valany;
          if (valsubtype == vx_core::t_string) {
            valany = vx_core::any_from_any(vx_core::t_string, valsub);
          } else if (valsubtype == vx_core::t_string) {
            valany = vx_core::any_from_any(vx_core::t_string, valsub);
          } else {
            vx_core::Type_msg msg = vx_core::t_msg->vx_new_error("Invalid Key/Value: " + key + " "  + vx_core::string_from_any(valsub) + "");
            msgblock = vx_core::t_msgblock->vx_copy(vx_core::t_msgblock, {msgblock, msg});
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

    template <class T> std::shared_ptr<T> vx_data_xml::Class_xmlpropmap::vx_empty(std::shared_ptr<T> val) {return vx_data_xml::e_xmlpropmap;}
    template <class T> std::shared_ptr<T> vx_data_xml::Class_xmlpropmap::vx_type(std::shared_ptr<T> val) {return vx_data_xml::t_xmlpropmap;}

    vx_core::Type_typedef vx_data_xml::Class_xmlpropmap::vx_typedef() {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/data/xml", // pkgname
        "xmlpropmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::t_typelist->vx_new(vx_core::t_typelist, {vx_core::t_string}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
    }

    vx_data_xml::Type_xmlpropmap vx_data_xml::e_xmlpropmap = std::make_shared<vx_data_xml::Class_xmlpropmap>();
    vx_data_xml::Type_xmlpropmap vx_data_xml::t_xmlpropmap = std::make_shared<vx_data_xml::Class_xmlpropmap>();
  //}
  /**
   * @function xml_from_textblock
   * @param  {textblock} textblock
   * @return {xml}
   * (func xml<-textblock)
   */
  //class Func_xml_from_textblock {

    template <class T> std::shared_ptr<T> vx_data_xml::Class_xml_from_textblock::vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_xml::Func_xml_from_textblock output;
      return output;
    }

    template <class T> std::shared_ptr<T> vx_data_xml::Class_xml_from_textblock::vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals) {
      vx_data_xml::Func_xml_from_textblock output;
      return output;
    }

    vx_core::Type_typedef vx_data_xml::Class_xml_from_textblock::vx_typedef() {return vx_data_xml::t_xml_from_textblock->vx_typedef();}

    vx_core::Type_funcdef vx_data_xml::Class_xml_from_textblock::vx_funcdef() {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/xml", // pkgname
        "xml<-textblock", // name
        0, // idx
        false, // async
        vx_core::Class_typedef::vx_typedef_new(
          "vx/data/xml", // pkgname
          "xml", // name
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

    template <class T> std::shared_ptr<T> vx_data_xml::Class_xml_from_textblock::vx_empty(std::shared_ptr<T> val) {return vx_data_xml::e_xml_from_textblock;}
    template <class T> std::shared_ptr<T> vx_data_xml::Class_xml_from_textblock::vx_type(std::shared_ptr<T> val) {return vx_data_xml::t_xml_from_textblock;}

    vx_core::Func_any_from_any vx_data_xml::Class_xml_from_textblock::fn_new(vx_core::Class_any_from_any::IFn fn) {return vx_core::e_any_from_any;}

    template <class T, class U> std::shared_ptr<T> vx_data_xml::Class_xml_from_textblock::f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value) {
      std::shared_ptr<T> output = vx_core::f_empty(generic_any_1);
      vx_data_textblock::Type_textblock inputval = (vx_data_textblock::Type_textblock)value;
      vx_core::Type_any outputval = vx_data_xml::f_xml_from_textblock(inputval);
      output = vx_core::f_any_from_any(generic_any_1, outputval);
      return output;
    }

    vx_core::Type_any vx_data_xml::Class_xml_from_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblock = vx_core::f_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::t_int->vx_new_from_int(0)));
      output = vx_data_xml::f_xml_from_textblock(textblock);
      return output;
    }

    vx_data_xml::Type_xml vx_data_xml::Class_xml_from_textblock::vx_f_xml_from_textblock(vx_data_textblock::Type_textblock textblock) {
      return vx_data_xml::f_xml_from_textblock(textblock);
    }

  //}

  vx_data_xml::Func_xml_from_textblock vx_data_xml::e_xml_from_textblock = std::make_shared<vx_data_xml::Class_xml_from_textblock>();
  vx_data_xml::Func_xml_from_textblock vx_data_xml::t_xml_from_textblock = std::make_shared<vx_data_xml::Class_xml_from_textblock>();

  vx_data_xml::Type_xml vx_data_xml::f_xml_from_textblock(vx_data_textblock::Type_textblock textblock) {
    vx_data_xml::Type_xml output = vx_data_xml::e_xml;
    output = vx_core::f_empty(
      vx_data_xml::t_xml
    );
    return output;
  }


//}
