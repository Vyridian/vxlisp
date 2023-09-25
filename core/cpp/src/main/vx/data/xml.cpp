#include <map>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/data/textblock.hpp"
#include "xml.hpp"

namespace vx_data_xml {


  // (type xml)
  // class Class_xml {
    Abstract_xml::~Abstract_xml() {}

    Class_xml::Class_xml() : Abstract_xml::Abstract_xml() {
      vx_core::refcount += 1;
    }

    Class_xml::~Class_xml() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_nodes
      });
    }

    // nodes()
    vx_data_xml::Type_xmlnodelist Class_xml::nodes() const {
      vx_data_xml::Type_xmlnodelist output = this->vx_p_nodes;
      if (!output) {
        output = vx_data_xml::e_xmlnodelist;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_xml::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":nodes") {
        output = this->nodes();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_xml::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":nodes"] = this->nodes();
      return output;
    }

    vx_core::Type_any Class_xml::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_xml::e_xml, vals);
    }

    vx_core::Type_any Class_xml::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_xml::Type_xml output = vx_data_xml::e_xml;
      vx_data_xml::Type_xml val = vx_core::vx_any_from_any(vx_data_xml::t_xml, copyval);
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_data_xml::Type_xmlnodelist vx_p_nodes = val->nodes();
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
          } else if (testkey == ":nodes") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new xml) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":nodes") {
            if (valsubtype == vx_data_xml::t_xmlnodelist) {
              vx_p_nodes = vx_core::vx_any_from_any(vx_data_xml::t_xmlnodelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new xml :nodes " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new xml) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_data_xml::Class_xml();
      if (output->vx_p_nodes != vx_p_nodes) {
        if (output->vx_p_nodes) {
          vx_core::vx_release_one(output->vx_p_nodes);
        }
        output->vx_p_nodes = vx_p_nodes;
        vx_core::vx_reserve(vx_p_nodes);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_xml::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_xml::Class_xml::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_xml::vx_empty() const {return vx_data_xml::e_xml;}
    vx_core::Type_any Class_xml::vx_type() const {return vx_data_xml::t_xml;}

    vx_core::Type_typedef Class_xml::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "nodes", // name
            vx_data_xml::t_xmlnodelist // type
          )
        }) // properties
      );
      return output;
    }

  //}

  // (type xmlnode)
  // class Class_xmlnode {
    Abstract_xmlnode::~Abstract_xmlnode() {}

    Class_xmlnode::Class_xmlnode() : Abstract_xmlnode::Abstract_xmlnode() {
      vx_core::refcount += 1;
    }

    Class_xmlnode::~Class_xmlnode() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_nodes,
        this->vx_p_props,
        this->vx_p_tag,
        this->vx_p_text
      });
    }

    // nodes()
    vx_data_xml::Type_xmlnode Class_xmlnode::nodes() const {
      vx_data_xml::Type_xmlnode output = this->vx_p_nodes;
      if (!output) {
        output = vx_data_xml::e_xmlnode;
      }
      return output;
    }

    // props()
    vx_data_xml::Type_xmlpropmap Class_xmlnode::props() const {
      vx_data_xml::Type_xmlpropmap output = this->vx_p_props;
      if (!output) {
        output = vx_data_xml::e_xmlpropmap;
      }
      return output;
    }

    // tag()
    vx_core::Type_string Class_xmlnode::tag() const {
      vx_core::Type_string output = this->vx_p_tag;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // text()
    vx_core::Type_string Class_xmlnode::text() const {
      vx_core::Type_string output = this->vx_p_text;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_xmlnode::vx_get_any(vx_core::Type_string key) const {
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
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_xmlnode::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":nodes"] = this->nodes();
      output[":props"] = this->props();
      output[":tag"] = this->tag();
      output[":text"] = this->text();
      return output;
    }

    vx_core::Type_any Class_xmlnode::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_xml::e_xmlnode, vals);
    }

    vx_core::Type_any Class_xmlnode::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_xml::Type_xmlnode output = vx_data_xml::e_xmlnode;
      vx_data_xml::Type_xmlnode val = vx_core::vx_any_from_any(vx_data_xml::t_xmlnode, copyval);
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_data_xml::Type_xmlnode vx_p_nodes = val->nodes();
      vx_data_xml::Type_xmlpropmap vx_p_props = val->props();
      vx_core::Type_string vx_p_tag = val->tag();
      vx_core::Type_string vx_p_text = val->text();
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
          } else if (testkey == ":nodes") {
            key = testkey;
          } else if (testkey == ":props") {
            key = testkey;
          } else if (testkey == ":tag") {
            key = testkey;
          } else if (testkey == ":text") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new xmlnode) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":nodes") {
            if (valsubtype == vx_data_xml::t_xmlnode) {
              vx_p_nodes = vx_core::vx_any_from_any(vx_data_xml::t_xmlnode, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new xmlnode :nodes " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":props") {
            if (valsubtype == vx_data_xml::t_xmlpropmap) {
              vx_p_props = vx_core::vx_any_from_any(vx_data_xml::t_xmlpropmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new xmlnode :props " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":tag") {
            if (valsubtype == vx_core::t_string) {
              vx_p_tag = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new xmlnode :tag " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":text") {
            if (valsubtype == vx_core::t_string) {
              vx_p_text = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new xmlnode :text " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new xmlnode) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_data_xml::Class_xmlnode();
      if (output->vx_p_nodes != vx_p_nodes) {
        if (output->vx_p_nodes) {
          vx_core::vx_release_one(output->vx_p_nodes);
        }
        output->vx_p_nodes = vx_p_nodes;
        vx_core::vx_reserve(vx_p_nodes);
      }
      if (output->vx_p_props != vx_p_props) {
        if (output->vx_p_props) {
          vx_core::vx_release_one(output->vx_p_props);
        }
        output->vx_p_props = vx_p_props;
        vx_core::vx_reserve(vx_p_props);
      }
      if (output->vx_p_tag != vx_p_tag) {
        if (output->vx_p_tag) {
          vx_core::vx_release_one(output->vx_p_tag);
        }
        output->vx_p_tag = vx_p_tag;
        vx_core::vx_reserve(vx_p_tag);
      }
      if (output->vx_p_text != vx_p_text) {
        if (output->vx_p_text) {
          vx_core::vx_release_one(output->vx_p_text);
        }
        output->vx_p_text = vx_p_text;
        vx_core::vx_reserve(vx_p_text);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_xmlnode::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_xml::Class_xmlnode::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_xmlnode::vx_empty() const {return vx_data_xml::e_xmlnode;}
    vx_core::Type_any Class_xmlnode::vx_type() const {return vx_data_xml::t_xmlnode;}

    vx_core::Type_typedef Class_xmlnode::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "nodes", // name
            vx_data_xml::t_xmlnode // type
          ),
          vx_core::vx_new_arg(
            "props", // name
            vx_data_xml::t_xmlpropmap // type
          ),
          vx_core::vx_new_arg(
            "tag", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "text", // name
            vx_core::t_string // type
          )
        }) // properties
      );
      return output;
    }

  //}

  // (type xmlnodelist)
  // class Class_xmlnodelist {
    Abstract_xmlnodelist::~Abstract_xmlnodelist() {}

    Class_xmlnodelist::Class_xmlnodelist() : Abstract_xmlnodelist::Abstract_xmlnodelist() {
      vx_core::refcount += 1;
    }

    Class_xmlnodelist::~Class_xmlnodelist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_xmlnodelist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_data_xml::Type_xmlnode Class_xmlnodelist::vx_get_xmlnode(vx_core::Type_int index) const {
      vx_data_xml::Type_xmlnode output = vx_data_xml::e_xmlnode;
      long iindex = index->vx_int();
      std::vector<vx_data_xml::Type_xmlnode> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_data_xml::Type_xmlnode> Class_xmlnodelist::vx_listxmlnode() const {return vx_p_list;}

    vx_core::Type_any vx_data_xml::Class_xmlnodelist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_xmlnode(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_xmlnodelist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_data_xml::Type_xmlnodelist output = vx_data_xml::e_xmlnodelist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_data_xml::Type_xmlnode> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_data_xml::t_xmlnode) {
          vx_data_xml::Type_xmlnode castval = vx_core::vx_any_from_any(vx_data_xml::t_xmlnode, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_data_xml::t_xmlnode)) {
          vx_data_xml::Type_xmlnode castval = vx_core::vx_any_from_any(vx_data_xml::t_xmlnode, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(xmlnodelist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_data_xml::Class_xmlnodelist();
      output->vx_p_list = list;
      for (vx_core::Type_any valadd : list) {
        vx_core::vx_reserve(valadd);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(listval, output);
      return output;
    }

    vx_core::Type_any Class_xmlnodelist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_xml::e_xmlnodelist, vals);
    }

    vx_core::Type_any Class_xmlnodelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_xml::Type_xmlnodelist output = vx_data_xml::e_xmlnodelist;
      vx_data_xml::Type_xmlnodelist val = vx_core::vx_any_from_any(vx_data_xml::t_xmlnodelist, copyval);
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_data_xml::Type_xmlnode> listval = val->vx_listxmlnode();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_data_xml::t_xmlnode) {
          listval.push_back(vx_core::vx_any_from_any(vx_data_xml::t_xmlnode, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_data_xml::t_xmlnode)) {
          listval.push_back(vx_core::vx_any_from_any(vx_data_xml::t_xmlnode, valsub));
        } else if (valsubtype == vx_data_xml::t_xmlnodelist) {
          vx_data_xml::Type_xmlnodelist multi = vx_core::vx_any_from_any(vx_data_xml::t_xmlnodelist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listxmlnode());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new xmlnodelist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_data_xml::Class_xmlnodelist();
      output->vx_p_list = listval;
      for (vx_core::Type_any valadd : listval) {
        vx_core::vx_reserve(valadd);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_xmlnodelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_xml::Class_xmlnodelist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_xmlnodelist::vx_empty() const {return vx_data_xml::e_xmlnodelist;}
    vx_core::Type_any Class_xmlnodelist::vx_type() const {return vx_data_xml::t_xmlnodelist;}

    vx_core::Type_typedef Class_xmlnodelist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/xml", // pkgname
        "xmlnodelist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_data_xml::t_xmlnode}), // allowtypes
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

  // (type xmlpropmap)
  // class Class_xmlpropmap {
    Abstract_xmlpropmap::~Abstract_xmlpropmap() {}

    Class_xmlpropmap::Class_xmlpropmap() : Abstract_xmlpropmap::Abstract_xmlpropmap() {
      vx_core::refcount += 1;
    }

    Class_xmlpropmap::~Class_xmlpropmap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (auto const& [key, val] : this->vx_p_map) {
        vx_core::vx_release_one(val);
      }
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_xmlpropmap::vx_map() const {
      vx_core::vx_Type_mapany output = vx_core::vx_map_from_map(vx_core::t_any, this->vx_p_map);
      return output;
    }

    // vx_get_string(key)
    vx_core::Type_string Class_xmlpropmap::vx_get_string(vx_core::Type_string key) const {
      vx_core::Type_string output = vx_core::e_string;
      const vx_data_xml::Class_xmlpropmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_string> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_core::e_string);
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_xmlpropmap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_string(key);
    }

    // vx_mapstring()
    std::map<std::string, vx_core::Type_string> Class_xmlpropmap::vx_mapstring() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_xmlpropmap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_data_xml::Type_xmlpropmap output = vx_data_xml::e_xmlpropmap;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_core::Type_string> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_string) {
          vx_core::Type_string castval = vx_core::vx_any_from_any(vx_core::t_string, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(xmlpropmap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_data_xml::Class_xmlpropmap();
      output->vx_p_map = map;
      for (auto const& [key, val] : map) {
        vx_core::vx_reserve(val);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      for (auto const& [key, val] : mapval) {
        vx_core::vx_release_except(val, output);
      }
      return output;
    }

    vx_core::Type_any Class_xmlpropmap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_xml::e_xmlpropmap, vals);
    }

    vx_core::Type_any Class_xmlpropmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_xml::Type_xmlpropmap output = vx_data_xml::e_xmlpropmap;
      vx_data_xml::Type_xmlpropmap valmap = vx_core::vx_any_from_any(vx_data_xml::t_xmlpropmap, copyval);
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::vector<std::string> keys;
      std::map<std::string, vx_core::Type_string> mapval;
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstring = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            key = valstring->vx_string();
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("Key Expected: " + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          vx_core::Type_string valany = NULL;
          if (valsubtype == vx_core::t_string) {
            valany = vx_core::vx_any_from_any(vx_core::t_string, valsub);
          } else if (valsubtype == vx_core::t_string) {
            valany = vx_core::vx_any_from_any(vx_core::t_string, valsub);
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("Invalid Key/Value: " + key + " "  + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          if (valany) {
            mapval[key] = valany;
            keys.push_back(key);
            key = "";
          }
        }
      }
      output = new vx_data_xml::Class_xmlpropmap();
      output->vx_p_keys = keys;
      output->vx_p_map = mapval;
      for (auto const& [key, val] : mapval) {
        vx_core::vx_reserve(val);
      }
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_xmlpropmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_xml::Class_xmlpropmap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_xmlpropmap::vx_empty() const {return vx_data_xml::e_xmlpropmap;}
    vx_core::Type_any Class_xmlpropmap::vx_type() const {return vx_data_xml::t_xmlpropmap;}

    vx_core::Type_typedef Class_xmlpropmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/xml", // pkgname
        "xmlpropmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_core::t_string}), // allowtypes
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

  // (func xml<-textblock)
  vx_data_xml::Type_xml f_xml_from_textblock(vx_data_textblock::Type_textblock textblock) {
    vx_data_xml::Type_xml output = vx_data_xml::e_xml;
    vx_core::vx_reserve(textblock);
    output = vx_core::f_empty(
      vx_data_xml::t_xml
    );
    vx_core::vx_release_one_except(textblock, output);
    return output;
  }

  // (func xml<-textblock)
  // class Class_xml_from_textblock {
    Abstract_xml_from_textblock::~Abstract_xml_from_textblock() {}

    Class_xml_from_textblock::Class_xml_from_textblock() : Abstract_xml_from_textblock::Abstract_xml_from_textblock() {
      vx_core::refcount += 1;
    }

    Class_xml_from_textblock::~Class_xml_from_textblock() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_xml_from_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_xml_from_textblock output = vx_data_xml::e_xml_from_textblock;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_xml_from_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_xml_from_textblock output = vx_data_xml::e_xml_from_textblock;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_xml_from_textblock::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/xml", // pkgname
        "xml<-textblock", // name
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

    vx_core::Type_funcdef Class_xml_from_textblock::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/xml", // pkgname
        "xml<-textblock", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_xml_from_textblock::vx_empty() const {return vx_data_xml::e_xml_from_textblock;}
    vx_core::Type_any Class_xml_from_textblock::vx_type() const {return vx_data_xml::t_xml_from_textblock;}
    vx_core::Type_msgblock Class_xml_from_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_xml_from_textblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_xml_from_textblock::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_xml_from_textblock::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock inputval = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, val);
      output = vx_data_xml::f_xml_from_textblock(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_xml_from_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblock = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_xml::f_xml_from_textblock(textblock);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_data_xml::Type_xml e_xml = NULL;
  vx_data_xml::Type_xml t_xml = NULL;
  vx_data_xml::Type_xmlnode e_xmlnode = NULL;
  vx_data_xml::Type_xmlnode t_xmlnode = NULL;
  vx_data_xml::Type_xmlnodelist e_xmlnodelist = NULL;
  vx_data_xml::Type_xmlnodelist t_xmlnodelist = NULL;
  vx_data_xml::Type_xmlpropmap e_xmlpropmap = NULL;
  vx_data_xml::Type_xmlpropmap t_xmlpropmap = NULL;
  vx_data_xml::Func_xml_from_textblock e_xml_from_textblock = NULL;
  vx_data_xml::Func_xml_from_textblock t_xml_from_textblock = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_data_xml::e_xml = new Class_xml();
      vx_core::vx_reserve_empty(vx_data_xml::e_xml);
      vx_data_xml::t_xml = new Class_xml();
      vx_core::vx_reserve_type(vx_data_xml::t_xml);
      vx_data_xml::e_xmlnode = new Class_xmlnode();
      vx_core::vx_reserve_empty(vx_data_xml::e_xmlnode);
      vx_data_xml::t_xmlnode = new Class_xmlnode();
      vx_core::vx_reserve_type(vx_data_xml::t_xmlnode);
      vx_data_xml::e_xmlnodelist = new Class_xmlnodelist();
      vx_core::vx_reserve_empty(vx_data_xml::e_xmlnodelist);
      vx_data_xml::t_xmlnodelist = new Class_xmlnodelist();
      vx_core::vx_reserve_type(vx_data_xml::t_xmlnodelist);
      vx_data_xml::e_xmlpropmap = new Class_xmlpropmap();
      vx_core::vx_reserve_empty(vx_data_xml::e_xmlpropmap);
      vx_data_xml::t_xmlpropmap = new Class_xmlpropmap();
      vx_core::vx_reserve_type(vx_data_xml::t_xmlpropmap);
      vx_data_xml::e_xml_from_textblock = new vx_data_xml::Class_xml_from_textblock();
      vx_core::vx_reserve_empty(vx_data_xml::e_xml_from_textblock);
      vx_data_xml::t_xml_from_textblock = new vx_data_xml::Class_xml_from_textblock();
      vx_core::vx_reserve_type(vx_data_xml::t_xml_from_textblock);
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
