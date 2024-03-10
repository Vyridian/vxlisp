#include <map>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/data/file.hpp"
#include "../../vx/data/textblock.hpp"
#include "../../vx/type.hpp"
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
        this->vx_p_tag,
        this->vx_p_text,
        this->vx_p_prop,
        this->vx_p_propmap,
        this->vx_p_children,
        this->vx_p_parent
      });
    }

    // tag()
    vx_core::Type_string Class_xml::tag() const {
      vx_core::Type_string output = this->vx_p_tag;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // text()
    vx_core::Type_string Class_xml::text() const {
      vx_core::Type_string output = this->vx_p_text;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // prop()
    vx_core::Type_string Class_xml::prop() const {
      vx_core::Type_string output = this->vx_p_prop;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // propmap()
    vx_core::Type_stringmap Class_xml::propmap() const {
      vx_core::Type_stringmap output = this->vx_p_propmap;
      if (!output) {
        output = vx_core::e_stringmap;
      }
      return output;
    }

    // children()
    vx_data_xml::Type_xmllist Class_xml::children() const {
      vx_data_xml::Type_xmllist output = this->vx_p_children;
      if (!output) {
        output = vx_data_xml::e_xmllist;
      }
      return output;
    }

    // parent()
    vx_data_xml::Type_xml Class_xml::parent() const {
      vx_data_xml::Type_xml output = this->vx_p_parent;
      if (!output) {
        output = vx_data_xml::e_xml;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_xml::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":tag") {
        output = this->tag();
      } else if (skey == ":text") {
        output = this->text();
      } else if (skey == ":prop") {
        output = this->prop();
      } else if (skey == ":propmap") {
        output = this->propmap();
      } else if (skey == ":children") {
        output = this->children();
      } else if (skey == ":parent") {
        output = this->parent();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_xml::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":tag"] = this->tag();
      output[":text"] = this->text();
      output[":prop"] = this->prop();
      output[":propmap"] = this->propmap();
      output[":children"] = this->children();
      output[":parent"] = this->parent();
      return output;
    }

    vx_core::Type_any Class_xml::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_xml::e_xml, vals);
    }

    vx_core::Type_any Class_xml::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_xml::Type_xml output = vx_data_xml::e_xml;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_xml::Type_xml val = vx_core::vx_any_from_any(vx_data_xml::t_xml, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_tag = val->tag();
      vx_core::Type_string vx_p_text = val->text();
      vx_core::Type_string vx_p_prop = val->prop();
      vx_core::Type_stringmap vx_p_propmap = val->propmap();
      vx_data_xml::Type_xmllist vx_p_children = val->children();
      vx_data_xml::Type_xml vx_p_parent = val->parent();
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
          } else if (testkey == ":tag") {
            key = testkey;
          } else if (testkey == ":text") {
            key = testkey;
          } else if (testkey == ":prop") {
            key = testkey;
          } else if (testkey == ":propmap") {
            key = testkey;
          } else if (testkey == ":children") {
            key = testkey;
          } else if (testkey == ":parent") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new xml) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":tag") {
            if (vx_p_tag == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_tag = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new xml :tag " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":text") {
            if (vx_p_text == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_text = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new xml :text " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":prop") {
            if (vx_p_prop == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_prop = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new xml :prop " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":propmap") {
            if (vx_p_propmap == valsub) {
            } else if (valsubtype == vx_core::t_stringmap) {
              ischanged = true;
              vx_p_propmap = vx_core::vx_any_from_any(vx_core::t_stringmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new xml :propmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":children") {
            if (vx_p_children == valsub) {
            } else if (valsubtype == vx_data_xml::t_xmllist) {
              ischanged = true;
              vx_p_children = vx_core::vx_any_from_any(vx_data_xml::t_xmllist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new xml :children " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":parent") {
            if (vx_p_parent == valsub) {
            } else if (valsubtype == vx_data_xml::t_xml) {
              ischanged = true;
              vx_p_parent = vx_core::vx_any_from_any(vx_data_xml::t_xml, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new xml :parent " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new xml) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_xml::Class_xml();
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
        if (output->vx_p_prop != vx_p_prop) {
          if (output->vx_p_prop) {
            vx_core::vx_release_one(output->vx_p_prop);
          }
          output->vx_p_prop = vx_p_prop;
          vx_core::vx_reserve(vx_p_prop);
        }
        if (output->vx_p_propmap != vx_p_propmap) {
          if (output->vx_p_propmap) {
            vx_core::vx_release_one(output->vx_p_propmap);
          }
          output->vx_p_propmap = vx_p_propmap;
          vx_core::vx_reserve(vx_p_propmap);
        }
        if (output->vx_p_children != vx_p_children) {
          if (output->vx_p_children) {
            vx_core::vx_release_one(output->vx_p_children);
          }
          output->vx_p_children = vx_p_children;
          vx_core::vx_reserve(vx_p_children);
        }
        if (output->vx_p_parent != vx_p_parent) {
          if (output->vx_p_parent) {
            vx_core::vx_release_one(output->vx_p_parent);
          }
          output->vx_p_parent = vx_p_parent;
          vx_core::vx_reserve(vx_p_parent);
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
            "tag", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "text", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "prop", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "propmap", // name
            vx_core::t_stringmap // type
          ),
          vx_core::vx_new_arg(
            "children", // name
            vx_data_xml::t_xmllist // type
          ),
          vx_core::vx_new_arg(
            "parent", // name
            vx_data_xml::t_xml // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_xml::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type xmllist)
  // class Class_xmllist {
    Abstract_xmllist::~Abstract_xmllist() {}

    Class_xmllist::Class_xmllist() : Abstract_xmllist::Abstract_xmllist() {
      vx_core::refcount += 1;
    }

    Class_xmllist::~Class_xmllist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_xmllist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_data_xml::Type_xml Class_xmllist::vx_get_xml(vx_core::Type_int index) const {
      vx_data_xml::Type_xml output = vx_data_xml::e_xml;
      long iindex = index->vx_int();
      std::vector<vx_data_xml::Type_xml> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_data_xml::Type_xml> Class_xmllist::vx_listxml() const {return vx_p_list;}

    vx_core::Type_any vx_data_xml::Class_xmllist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_xml(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_xmllist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_data_xml::Type_xmllist output = vx_data_xml::e_xmllist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_data_xml::Type_xml> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_data_xml::t_xml) {
          vx_data_xml::Type_xml castval = vx_core::vx_any_from_any(vx_data_xml::t_xml, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_data_xml::t_xml)) {
          vx_data_xml::Type_xml castval = vx_core::vx_any_from_any(vx_data_xml::t_xml, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(xmllist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_xml::Class_xmllist();
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

    vx_core::Type_any Class_xmllist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_xml::e_xmllist, vals);
    }

    vx_core::Type_any Class_xmllist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_xml::Type_xmllist output = vx_data_xml::e_xmllist;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_xml::Type_xmllist val = vx_core::vx_any_from_any(vx_data_xml::t_xmllist, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_data_xml::Type_xml> listval = val->vx_listxml();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_data_xml::t_xml) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_data_xml::t_xml, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_data_xml::t_xml)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_data_xml::t_xml, valsub));
        } else if (valsubtype == vx_data_xml::t_xmllist) {
          ischanged = true;
          vx_data_xml::Type_xmllist multi = vx_core::vx_any_from_any(vx_data_xml::t_xmllist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listxml());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new xmllist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_xml::Class_xmllist();
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

    vx_core::Type_msgblock Class_xmllist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_xml::Class_xmllist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_xmllist::vx_empty() const {return vx_data_xml::e_xmllist;}
    vx_core::Type_any Class_xmllist::vx_type() const {return vx_data_xml::t_xmllist;}

    vx_core::Type_typedef Class_xmllist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/xml", // pkgname
        "xmllist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_data_xml::t_xml}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_xmllist::vx_constdef() const {return this->vx_p_constdef;}


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
      if (vx_core::vx_boolean_from_string_starts(skey, ":")) {
        skey = vx_core::vx_string_from_string_start(skey, 2);
      }
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
      if ((map.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_xml::Class_xmlpropmap();
        output->vx_p_map = map;
        for (auto const& [key, val] : map) {
          vx_core::vx_reserve(val);
        }
        if (msgblock != vx_core::e_msgblock) {
          output->vx_p_msgblock = msgblock;
          vx_core::vx_reserve(msgblock);
        }
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
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_xml::Type_xmlpropmap valmap = vx_core::vx_any_from_any(vx_data_xml::t_xmlpropmap, copyval);
      output = valmap;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_core::Type_string> mapval = valmap->vx_mapstring();
      std::vector<std::string> keys = valmap->vx_p_keys;
      std::string skey = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (skey == "") {
          if (valsubtype == vx_core::t_string) {
            vx_core::Type_string valstring = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            skey = valstring->vx_string();
            if (vx_core::vx_boolean_from_string_starts(skey, ":")) {
              skey = vx_core::vx_string_from_string_start(skey, 2);
            }
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
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("Invalid Key/Value: " + skey + " "  + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          if (valany) {
            ischanged = true;
            mapval[skey] = valany;
            if (!vx_core::vx_boolean_from_list_find(keys, skey)) {
          	 		keys.push_back(skey);
            }
            skey = "";
          }
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
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

    vx_core::Type_constdef Class_xmlpropmap::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (const delimxml)
  // class Class_delimxml {
    // vx_const_new()
    void vx_data_xml::Class_delimxml::vx_const_new(vx_data_xml::Const_delimxml output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/xml", "delimxml");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":delimlist"),
          vx_core::f_new(
            vx_data_textblock::t_delimlist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_data_xml::c_delimxmlcomment,
              vx_data_xml::c_delimxmlcdata,
              vx_core::f_copy(
                vx_data_textblock::t_delim,
                vx_data_textblock::c_delimbracketangle,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string(":delimlist"),
                  vx_core::f_new(
                    vx_data_textblock::t_delimlist,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_data_xml::c_delimxmlequal,
                      vx_data_textblock::c_delimwhitespace,
                      vx_data_textblock::c_delimquote
                    })
                  )
                })
              )
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

  // (const delimxmlcdata)
  // class Class_delimxmlcdata {
    // vx_const_new()
    void vx_data_xml::Class_delimxmlcdata::vx_const_new(vx_data_xml::Const_delimxmlcdata output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/xml", "delimxmlcdata");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimxmlcomment"),
          vx_core::vx_new_string(":starttext"),
          vx_core::vx_new_string("<![CDATA["),
          vx_core::vx_new_string(":endtext"),
          vx_core::vx_new_string("]]>")
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

  // (const delimxmlcomment)
  // class Class_delimxmlcomment {
    // vx_const_new()
    void vx_data_xml::Class_delimxmlcomment::vx_const_new(vx_data_xml::Const_delimxmlcomment output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/xml", "delimxmlcomment");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimxmlcomment"),
          vx_core::vx_new_string(":starttext"),
          vx_core::vx_new_string("<!--"),
          vx_core::vx_new_string(":endtext"),
          vx_core::vx_new_string("-->")
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

  // (const delimxmlequal)
  // class Class_delimxmlequal {
    // vx_const_new()
    void vx_data_xml::Class_delimxmlequal::vx_const_new(vx_data_xml::Const_delimxmlequal output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/xml", "delimxmlequal");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimxmlequal"),
          vx_core::vx_new_string(":starttext"),
          vx_core::vx_new_string("=")
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

  // (func string-decodexml<-string)
  vx_core::Type_string f_string_decodexml_from_string(vx_core::Type_string text) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(text);
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({text}, [text]() {
        vx_core::Type_string lt = vx_core::f_string_from_string_find_replace(text, vx_core::vx_new_string("&lt;"), vx_core::vx_new_string("<"));
        vx_core::vx_ref_plus(lt);
        vx_core::Type_string gt = vx_core::f_string_from_string_find_replace(text, vx_core::vx_new_string("&gt;"), vx_core::vx_new_string(">"));
        vx_core::vx_ref_plus(gt);
        vx_core::Type_string amp = vx_core::f_string_from_string_find_replace(gt, vx_core::vx_new_string("&amp;"), vx_core::vx_new_string("&"));
        vx_core::vx_ref_plus(amp);
        vx_core::Type_string result = vx_core::f_string_from_string_find_replace(
          text,
          vx_core::c_quote,
          vx_core::vx_new_string("\\\"")
        );
        vx_core::vx_ref_plus(result);
        vx_core::Type_string output_1 = result;
        vx_core::vx_release_one_except({lt, gt, amp, result}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(text, output);
    return output;
  }
  /**
   * @function string_decodexml_from_string
   * Returns string decoded from xml encoding
   * @param  {string} text
   * @return {string}
   * (func string-decodexml<-string)
   */
  // (func string-decodexml<-string)
  // class Class_string_decodexml_from_string {
    Abstract_string_decodexml_from_string::~Abstract_string_decodexml_from_string() {}

    Class_string_decodexml_from_string::Class_string_decodexml_from_string() : Abstract_string_decodexml_from_string::Abstract_string_decodexml_from_string() {
      vx_core::refcount += 1;
    }

    Class_string_decodexml_from_string::~Class_string_decodexml_from_string() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_decodexml_from_string::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_string_decodexml_from_string output = vx_data_xml::e_string_decodexml_from_string;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_decodexml_from_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_string_decodexml_from_string output = vx_data_xml::e_string_decodexml_from_string;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_decodexml_from_string::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/xml", // pkgname
        "string-decodexml<-string", // name
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

    vx_core::Type_constdef Class_string_decodexml_from_string::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_decodexml_from_string::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/xml", // pkgname
        "string-decodexml<-string", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_decodexml_from_string::vx_empty() const {return vx_data_xml::e_string_decodexml_from_string;}
    vx_core::Type_any Class_string_decodexml_from_string::vx_type() const {return vx_data_xml::t_string_decodexml_from_string;}
    vx_core::Type_msgblock Class_string_decodexml_from_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_decodexml_from_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_string_decodexml_from_string::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_string_decodexml_from_string::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_data_xml::f_string_decodexml_from_string(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_string_decodexml_from_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_xml::f_string_decodexml_from_string(text);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string-first<-xml)
  vx_core::Type_string f_string_first_from_xml(vx_data_xml::Type_xml xml) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(xml);
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({xml}, [xml]() {
        vx_data_xml::Type_xmllist children = xml->children();
        vx_core::vx_ref_plus(children);
        vx_data_xml::Type_xml first = vx_core::f_any_from_list(vx_data_xml::t_xml, children, vx_core::vx_new_int(1));
        vx_core::vx_ref_plus(first);
        vx_core::Type_string text = first->text();
        vx_core::vx_ref_plus(text);
        vx_core::Type_string decode = vx_data_xml::f_string_decodexml_from_string(text);
        vx_core::vx_ref_plus(decode);
        vx_core::Type_string outdent = vx_type::f_string_outdent(decode);
        vx_core::vx_ref_plus(outdent);
        vx_core::Type_string trim = vx_type::f_string_trim(outdent);
        vx_core::vx_ref_plus(trim);
        vx_core::Type_string output_1 = trim;
        vx_core::vx_release_one_except({children, first, text, decode, outdent, trim}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(xml, output);
    return output;
  }
  /**
   * @function string_first_from_xml
   * Returns string from first child's text.
   * @param  {xml} xml
   * @return {string}
   * (func string-first<-xml)
   */
  // (func string-first<-xml)
  // class Class_string_first_from_xml {
    Abstract_string_first_from_xml::~Abstract_string_first_from_xml() {}

    Class_string_first_from_xml::Class_string_first_from_xml() : Abstract_string_first_from_xml::Abstract_string_first_from_xml() {
      vx_core::refcount += 1;
    }

    Class_string_first_from_xml::~Class_string_first_from_xml() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_first_from_xml::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_string_first_from_xml output = vx_data_xml::e_string_first_from_xml;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_first_from_xml::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_string_first_from_xml output = vx_data_xml::e_string_first_from_xml;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_first_from_xml::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/xml", // pkgname
        "string-first<-xml", // name
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

    vx_core::Type_constdef Class_string_first_from_xml::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_first_from_xml::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/xml", // pkgname
        "string-first<-xml", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_first_from_xml::vx_empty() const {return vx_data_xml::e_string_first_from_xml;}
    vx_core::Type_any Class_string_first_from_xml::vx_type() const {return vx_data_xml::t_string_first_from_xml;}
    vx_core::Type_msgblock Class_string_first_from_xml::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_first_from_xml::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_string_first_from_xml::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_string_first_from_xml::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_xml::Type_xml inputval = vx_core::vx_any_from_any(vx_data_xml::t_xml, val);
      output = vx_data_xml::f_string_first_from_xml(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_string_first_from_xml::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_xml::Type_xml xml = vx_core::vx_any_from_any(vx_data_xml::t_xml, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_xml::f_string_first_from_xml(xml);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock-xml<-string)
  vx_data_textblock::Type_textblock f_textblock_xml_from_string(vx_core::Type_string text) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve(text);
    output = vx_data_textblock::f_textblock_parse_from_string_delim(
      text,
      vx_data_xml::c_delimxml
    );
    vx_core::vx_release_one_except(text, output);
    return output;
  }
  /**
   * @function textblock_xml_from_string
   * Returns a parsed textblock from a string.
   * @param  {string} text
   * @return {textblock}
   * (func textblock-xml<-string)
   */
  // (func textblock-xml<-string)
  // class Class_textblock_xml_from_string {
    Abstract_textblock_xml_from_string::~Abstract_textblock_xml_from_string() {}

    Class_textblock_xml_from_string::Class_textblock_xml_from_string() : Abstract_textblock_xml_from_string::Abstract_textblock_xml_from_string() {
      vx_core::refcount += 1;
    }

    Class_textblock_xml_from_string::~Class_textblock_xml_from_string() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_xml_from_string::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_textblock_xml_from_string output = vx_data_xml::e_textblock_xml_from_string;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_xml_from_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_textblock_xml_from_string output = vx_data_xml::e_textblock_xml_from_string;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_xml_from_string::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/xml", // pkgname
        "textblock-xml<-string", // name
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

    vx_core::Type_constdef Class_textblock_xml_from_string::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_textblock_xml_from_string::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/xml", // pkgname
        "textblock-xml<-string", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_xml_from_string::vx_empty() const {return vx_data_xml::e_textblock_xml_from_string;}
    vx_core::Type_any Class_textblock_xml_from_string::vx_type() const {return vx_data_xml::t_textblock_xml_from_string;}
    vx_core::Type_msgblock Class_textblock_xml_from_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_xml_from_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_textblock_xml_from_string::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_textblock_xml_from_string::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_data_xml::f_textblock_xml_from_string(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_textblock_xml_from_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_xml::f_textblock_xml_from_string(text);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func xml-angle<-xml-textblock)
  vx_data_xml::Type_xml f_xml_angle_from_xml_textblock(vx_data_xml::Type_xml xmlarg, vx_data_textblock::Type_textblock tb) {
    vx_data_xml::Type_xml output = vx_data_xml::e_xml;
    vx_core::vx_reserve({xmlarg, tb});
    output = vx_core::f_if_2(
      vx_data_xml::t_xml,
      vx_core::vx_new(vx_core::t_thenelselist, {
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({tb, xmlarg}, [tb, xmlarg]() {
            vx_core::Type_boolean output_1 = vx_core::f_eq(
              tb->text(),
              vx_core::f_new(
                vx_core::t_string,
                vx_core::vx_new(vx_core::t_anylist, {
                  vx_core::vx_new_string("</"),
                  xmlarg->tag(),
                  vx_core::vx_new_string(">")
                })
              )
            );
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({xmlarg, tb}, [xmlarg, tb]() {
            vx_data_xml::Type_xml output_1 = vx_data_xml::f_xml_close_from_xml_textblock(xmlarg, tb);
            return output_1;
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func->vx_fn_new({tb, xmlarg}, [tb, xmlarg]() {
            vx_data_xml::Type_xml output_1 = vx_core::f_let(
              vx_data_xml::t_xml,
              vx_core::t_any_from_func->vx_fn_new({tb, xmlarg}, [tb, xmlarg]() {
                vx_data_textblock::Type_textblocklist children = tb->children();
                vx_core::vx_ref_plus(children);
                vx_data_xml::Type_xml xmlchg = vx_core::f_new(
                  vx_data_xml::t_xml,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":tag"),
                    vx_core::vx_new_string(":notag"),
                    vx_core::vx_new_string(":parent"),
                    xmlarg
                  })
                );
                vx_core::vx_ref_plus(xmlchg);
                vx_data_xml::Type_xml output_1 = vx_data_xml::f_xml_properties_from_xml_textblocklist(xmlchg, children);
                vx_core::vx_release_one_except({children, xmlchg}, output_1);
                return output_1;
              })
            );
            return output_1;
          })
        )
      })
    );
    vx_core::vx_release_one_except({xmlarg, tb}, output);
    return output;
  }
  /**
   * @function xml_angle_from_xml_textblock
   * Returns a modified xml from a single textblock.
   * @param  {xml} xmlarg
   * @param  {textblock} tb
   * @return {xml}
   * (func xml-angle<-xml-textblock)
   */
  // (func xml-angle<-xml-textblock)
  // class Class_xml_angle_from_xml_textblock {
    Abstract_xml_angle_from_xml_textblock::~Abstract_xml_angle_from_xml_textblock() {}

    Class_xml_angle_from_xml_textblock::Class_xml_angle_from_xml_textblock() : Abstract_xml_angle_from_xml_textblock::Abstract_xml_angle_from_xml_textblock() {
      vx_core::refcount += 1;
    }

    Class_xml_angle_from_xml_textblock::~Class_xml_angle_from_xml_textblock() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_xml_angle_from_xml_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_xml_angle_from_xml_textblock output = vx_data_xml::e_xml_angle_from_xml_textblock;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_xml_angle_from_xml_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_xml_angle_from_xml_textblock output = vx_data_xml::e_xml_angle_from_xml_textblock;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_xml_angle_from_xml_textblock::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/xml", // pkgname
        "xml-angle<-xml-textblock", // name
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

    vx_core::Type_constdef Class_xml_angle_from_xml_textblock::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_xml_angle_from_xml_textblock::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/xml", // pkgname
        "xml-angle<-xml-textblock", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_xml_angle_from_xml_textblock::vx_empty() const {return vx_data_xml::e_xml_angle_from_xml_textblock;}
    vx_core::Type_any Class_xml_angle_from_xml_textblock::vx_type() const {return vx_data_xml::t_xml_angle_from_xml_textblock;}
    vx_core::Type_msgblock Class_xml_angle_from_xml_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_xml_angle_from_xml_textblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_xml_angle_from_xml_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_xml::Type_xml xmlarg = vx_core::vx_any_from_any(vx_data_xml::t_xml, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_textblock tb = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_xml::f_xml_angle_from_xml_textblock(xmlarg, tb);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func xml-close<-xml-textblock)
  vx_data_xml::Type_xml f_xml_close_from_xml_textblock(vx_data_xml::Type_xml xmlarg, vx_data_textblock::Type_textblock tb) {
    vx_data_xml::Type_xml output = vx_data_xml::e_xml;
    vx_core::vx_reserve({xmlarg, tb});
    output = vx_core::f_let(
      vx_data_xml::t_xml,
      vx_core::t_any_from_func->vx_fn_new({xmlarg, tb}, [xmlarg, tb]() {
        vx_core::Type_string tag = xmlarg->tag();
        vx_core::vx_ref_plus(tag);
        vx_core::Type_string text = tb->text();
        vx_core::vx_ref_plus(text);
        vx_data_xml::Type_xml parent = xmlarg->parent();
        vx_core::vx_ref_plus(parent);
        vx_core::Type_boolean isnoparent = vx_core::f_is_empty_1(parent);
        vx_core::vx_ref_plus(isnoparent);
        vx_data_xml::Type_xml output_1 = vx_core::f_if_2(
          vx_data_xml::t_xml,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({text, tag}, [text, tag]() {
                vx_core::Type_boolean output_1 = vx_core::f_or(
                  vx_core::f_eq(vx_core::vx_new_string("/"), text),
                  vx_core::f_eq(
                    text,
                    vx_core::f_new(
                      vx_core::t_string,
                      vx_core::vx_new(vx_core::t_anylist, {
                        vx_core::vx_new_string("</"),
                        tag,
                        vx_core::vx_new_string(">")
                      })
                    )
                  )
                );
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({isnoparent, xmlarg, parent}, [isnoparent, xmlarg, parent]() {
                vx_data_xml::Type_xml output_1 = vx_core::f_if_2(
                  vx_data_xml::t_xml,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({isnoparent}, [isnoparent]() {
                        vx_core::Type_boolean output_1 = isnoparent;
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({xmlarg}, [xmlarg]() {
                        vx_core::Type_any output_1 = xmlarg;
                        return output_1;
                      })
                    ),
                    vx_core::f_else(
                      vx_core::t_any_from_func->vx_fn_new({parent, xmlarg}, [parent, xmlarg]() {
                        vx_core::Type_any output_1 = vx_core::f_copy(
                          vx_data_xml::t_xml,
                          parent,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":children"),
                            vx_core::f_new(
                              vx_data_xml::t_xmllist,
                              vx_core::vx_new(vx_core::t_anylist, {
                                parent->children(),
                                vx_core::f_copy(
                                  vx_data_xml::t_xml,
                                  xmlarg,
                                  vx_core::vx_new(vx_core::t_anylist, {
                                    vx_core::vx_new_string(":parent"),
                                    vx_core::f_empty(
                                      vx_data_xml::t_xml
                                    )
                                  })
                                )
                              })
                            )
                          })
                        );
                        return output_1;
                      })
                    )
                  })
                );
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({xmlarg, text, tb}, [xmlarg, text, tb]() {
                vx_core::Type_any output_1 = vx_core::f_copy(
                  vx_data_xml::t_xml,
                  xmlarg,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::f_msg_from_error_1(
                      vx_core::vx_new_string(":invalidxmlclosetag"),
                      vx_core::f_new(
                        vx_core::t_anymap,
                        vx_core::vx_new(vx_core::t_anylist, {
                          vx_core::vx_new_string(":tag"),
                          text,
                          vx_core::vx_new_string(":startpos"),
                          tb->startpos(),
                          vx_core::vx_new_string(":endpos"),
                          tb->endpos(),
                          vx_core::vx_new_string(":line"),
                          tb->line(),
                          vx_core::vx_new_string(":column"),
                          tb->column()
                        })
                      )
                    )
                  })
                );
                return output_1;
              })
            )
          })
        );
        vx_core::vx_release_one_except({tag, text, parent, isnoparent}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({xmlarg, tb}, output);
    return output;
  }
  /**
   * @function xml_close_from_xml_textblock
   * Returns a modified xml from a closing tag.
   * @param  {xml} xmlarg
   * @param  {textblock} tb
   * @return {xml}
   * (func xml-close<-xml-textblock)
   */
  // (func xml-close<-xml-textblock)
  // class Class_xml_close_from_xml_textblock {
    Abstract_xml_close_from_xml_textblock::~Abstract_xml_close_from_xml_textblock() {}

    Class_xml_close_from_xml_textblock::Class_xml_close_from_xml_textblock() : Abstract_xml_close_from_xml_textblock::Abstract_xml_close_from_xml_textblock() {
      vx_core::refcount += 1;
    }

    Class_xml_close_from_xml_textblock::~Class_xml_close_from_xml_textblock() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_xml_close_from_xml_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_xml_close_from_xml_textblock output = vx_data_xml::e_xml_close_from_xml_textblock;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_xml_close_from_xml_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_xml_close_from_xml_textblock output = vx_data_xml::e_xml_close_from_xml_textblock;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_xml_close_from_xml_textblock::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/xml", // pkgname
        "xml-close<-xml-textblock", // name
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

    vx_core::Type_constdef Class_xml_close_from_xml_textblock::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_xml_close_from_xml_textblock::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/xml", // pkgname
        "xml-close<-xml-textblock", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_xml_close_from_xml_textblock::vx_empty() const {return vx_data_xml::e_xml_close_from_xml_textblock;}
    vx_core::Type_any Class_xml_close_from_xml_textblock::vx_type() const {return vx_data_xml::t_xml_close_from_xml_textblock;}
    vx_core::Type_msgblock Class_xml_close_from_xml_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_xml_close_from_xml_textblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_xml_close_from_xml_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_xml::Type_xml xmlarg = vx_core::vx_any_from_any(vx_data_xml::t_xml, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_textblock tb = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_xml::f_xml_close_from_xml_textblock(xmlarg, tb);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func xml-parse<-xml-textblock)
  vx_data_xml::Type_xml f_xml_parse_from_xml_textblock(vx_data_xml::Type_xml xmlarg, vx_data_textblock::Type_textblock tb) {
    vx_data_xml::Type_xml output = vx_data_xml::e_xml;
    vx_core::vx_reserve({xmlarg, tb});
    output = vx_core::f_let(
      vx_data_xml::t_xml,
      vx_core::t_any_from_func->vx_fn_new({tb, xmlarg}, [tb, xmlarg]() {
        vx_data_textblock::Type_delim delim = tb->delim();
        vx_core::vx_ref_plus(delim);
        vx_core::Type_string text = tb->text();
        vx_core::vx_ref_plus(text);
        vx_core::Type_string starttext = delim->starttext();
        vx_core::vx_ref_plus(starttext);
        vx_data_xml::Type_xml output_1 = vx_core::f_switch(
          vx_data_xml::t_xml,
          starttext,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_case_1(
              vx_core::vx_new_string(""),
              vx_core::t_any_from_func->vx_fn_new({xmlarg, tb}, [xmlarg, tb]() {
                vx_data_xml::Type_xml output_1 = vx_data_xml::f_xml_text_from_xml_textblock(xmlarg, tb);
                return output_1;
              })
            ),
            vx_core::f_case_1(
              vx_core::f_any_from_struct(
                vx_core::t_string,
                vx_data_textblock::c_delimbracketangle,
                vx_core::vx_new_string(":starttext")
              ),
              vx_core::t_any_from_func->vx_fn_new({xmlarg, tb}, [xmlarg, tb]() {
                vx_data_xml::Type_xml output_1 = vx_data_xml::f_xml_angle_from_xml_textblock(xmlarg, tb);
                return output_1;
              })
            ),
            vx_core::f_case_1(
              vx_core::f_any_from_struct(
                vx_core::t_string,
                vx_data_textblock::c_delimwhitespace,
                vx_core::vx_new_string(":starttext")
              ),
              vx_core::t_any_from_func->vx_fn_new({xmlarg}, [xmlarg]() {
                vx_core::Type_any output_1 = xmlarg;
                return output_1;
              })
            ),
            vx_core::f_case_1(
              vx_core::f_any_from_struct(
                vx_core::t_string,
                vx_data_xml::c_delimxmlcomment,
                vx_core::vx_new_string(":starttext")
              ),
              vx_core::t_any_from_func->vx_fn_new({xmlarg}, [xmlarg]() {
                vx_core::Type_any output_1 = xmlarg;
                return output_1;
              })
            ),
            vx_core::f_case_1(
              vx_core::f_any_from_struct(
                vx_core::t_string,
                vx_data_xml::c_delimxmlcdata,
                vx_core::vx_new_string(":starttext")
              ),
              vx_core::t_any_from_func->vx_fn_new({xmlarg}, [xmlarg]() {
                vx_core::Type_any output_1 = xmlarg;
                return output_1;
              })
            )
          })
        );
        vx_core::vx_release_one_except({delim, text, starttext}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({xmlarg, tb}, output);
    return output;
  }
  /**
   * @function xml_parse_from_xml_textblock
   * Returns a modified xml from a single textblock.
   * @param  {xml} xmlarg
   * @param  {textblock} tb
   * @return {xml}
   * (func xml-parse<-xml-textblock)
   */
  // (func xml-parse<-xml-textblock)
  // class Class_xml_parse_from_xml_textblock {
    Abstract_xml_parse_from_xml_textblock::~Abstract_xml_parse_from_xml_textblock() {}

    Class_xml_parse_from_xml_textblock::Class_xml_parse_from_xml_textblock() : Abstract_xml_parse_from_xml_textblock::Abstract_xml_parse_from_xml_textblock() {
      vx_core::refcount += 1;
    }

    Class_xml_parse_from_xml_textblock::~Class_xml_parse_from_xml_textblock() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_xml_parse_from_xml_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_xml_parse_from_xml_textblock output = vx_data_xml::e_xml_parse_from_xml_textblock;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_xml_parse_from_xml_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_xml_parse_from_xml_textblock output = vx_data_xml::e_xml_parse_from_xml_textblock;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_xml_parse_from_xml_textblock::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/xml", // pkgname
        "xml-parse<-xml-textblock", // name
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

    vx_core::Type_constdef Class_xml_parse_from_xml_textblock::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_xml_parse_from_xml_textblock::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/xml", // pkgname
        "xml-parse<-xml-textblock", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_xml_parse_from_xml_textblock::vx_empty() const {return vx_data_xml::e_xml_parse_from_xml_textblock;}
    vx_core::Type_any Class_xml_parse_from_xml_textblock::vx_type() const {return vx_data_xml::t_xml_parse_from_xml_textblock;}
    vx_core::Type_msgblock Class_xml_parse_from_xml_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_xml_parse_from_xml_textblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_xml_parse_from_xml_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_xml::Type_xml xmlarg = vx_core::vx_any_from_any(vx_data_xml::t_xml, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_textblock tb = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_xml::f_xml_parse_from_xml_textblock(xmlarg, tb);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func xml-parse<-xml-textblocklist)
  vx_data_xml::Type_xml f_xml_parse_from_xml_textblocklist(vx_data_xml::Type_xml xmlarg, vx_data_textblock::Type_textblocklist textblocklist) {
    vx_data_xml::Type_xml output = vx_data_xml::e_xml;
    vx_core::vx_reserve({xmlarg, textblocklist});
    output = vx_core::f_any_from_list_start_reduce(
      vx_data_xml::t_xml,
      textblocklist,
      xmlarg,
      vx_core::t_any_from_reduce->vx_fn_new({}, [](vx_core::Type_any xmlarg_any, vx_core::Type_any tb_any) {
        vx_data_xml::Type_xml xmlarg = vx_core::vx_any_from_any(vx_data_xml::t_xml, xmlarg_any);
        vx_data_textblock::Type_textblock tb = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, tb_any);
        vx_core::Type_any output_1 = vx_data_xml::f_xml_parse_from_xml_textblock(xmlarg, tb);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({xmlarg, textblocklist}, output);
    return output;
  }
  /**
   * @function xml_parse_from_xml_textblocklist
   * Returns a modified xml from a textblocklist.
   * @param  {xml} xmlarg
   * @param  {textblocklist} textblocklist
   * @return {xml}
   * (func xml-parse<-xml-textblocklist)
   */
  // (func xml-parse<-xml-textblocklist)
  // class Class_xml_parse_from_xml_textblocklist {
    Abstract_xml_parse_from_xml_textblocklist::~Abstract_xml_parse_from_xml_textblocklist() {}

    Class_xml_parse_from_xml_textblocklist::Class_xml_parse_from_xml_textblocklist() : Abstract_xml_parse_from_xml_textblocklist::Abstract_xml_parse_from_xml_textblocklist() {
      vx_core::refcount += 1;
    }

    Class_xml_parse_from_xml_textblocklist::~Class_xml_parse_from_xml_textblocklist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_xml_parse_from_xml_textblocklist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_xml_parse_from_xml_textblocklist output = vx_data_xml::e_xml_parse_from_xml_textblocklist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_xml_parse_from_xml_textblocklist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_xml_parse_from_xml_textblocklist output = vx_data_xml::e_xml_parse_from_xml_textblocklist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_xml_parse_from_xml_textblocklist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/xml", // pkgname
        "xml-parse<-xml-textblocklist", // name
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

    vx_core::Type_constdef Class_xml_parse_from_xml_textblocklist::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_xml_parse_from_xml_textblocklist::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/xml", // pkgname
        "xml-parse<-xml-textblocklist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_xml_parse_from_xml_textblocklist::vx_empty() const {return vx_data_xml::e_xml_parse_from_xml_textblocklist;}
    vx_core::Type_any Class_xml_parse_from_xml_textblocklist::vx_type() const {return vx_data_xml::t_xml_parse_from_xml_textblocklist;}
    vx_core::Type_msgblock Class_xml_parse_from_xml_textblocklist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_xml_parse_from_xml_textblocklist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_xml_parse_from_xml_textblocklist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_xml::Type_xml xmlarg = vx_core::vx_any_from_any(vx_data_xml::t_xml, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_textblocklist textblocklist = vx_core::vx_any_from_any(vx_data_textblock::t_textblocklist, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_xml::f_xml_parse_from_xml_textblocklist(xmlarg, textblocklist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func xml-properties<-xml-textblocklist)
  vx_data_xml::Type_xml f_xml_properties_from_xml_textblocklist(vx_data_xml::Type_xml xmlarg, vx_data_textblock::Type_textblocklist textblocklist) {
    vx_data_xml::Type_xml output = vx_data_xml::e_xml;
    vx_core::vx_reserve({xmlarg, textblocklist});
    output = vx_core::f_let(
      vx_data_xml::t_xml,
      vx_core::t_any_from_func->vx_fn_new({textblocklist, xmlarg}, [textblocklist, xmlarg]() {
        vx_data_xml::Type_xml xmlchg = vx_core::f_any_from_list_start_reduce(
          vx_data_xml::t_xml,
          textblocklist,
          xmlarg,
          vx_core::t_any_from_reduce->vx_fn_new({}, [](vx_core::Type_any reduce_any, vx_core::Type_any current_any) {
            vx_data_xml::Type_xml reduce = vx_core::vx_any_from_any(vx_data_xml::t_xml, reduce_any);
            vx_data_textblock::Type_textblock current = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, current_any);
            vx_core::Type_any output_1 = 
              vx_data_xml::f_xml_property_from_xml_textblock(reduce, current);
            return output_1;
          })
        );
        vx_core::vx_ref_plus(xmlchg);
        vx_data_xml::Type_xml output_1 = xmlchg;
        vx_core::vx_release_one_except(xmlchg, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({xmlarg, textblocklist}, output);
    return output;
  }
  /**
   * @function xml_properties_from_xml_textblocklist
   * Returns a modified xml from a textblocklist.
   * @param  {xml} xmlarg
   * @param  {textblocklist} textblocklist
   * @return {xml}
   * (func xml-properties<-xml-textblocklist)
   */
  // (func xml-properties<-xml-textblocklist)
  // class Class_xml_properties_from_xml_textblocklist {
    Abstract_xml_properties_from_xml_textblocklist::~Abstract_xml_properties_from_xml_textblocklist() {}

    Class_xml_properties_from_xml_textblocklist::Class_xml_properties_from_xml_textblocklist() : Abstract_xml_properties_from_xml_textblocklist::Abstract_xml_properties_from_xml_textblocklist() {
      vx_core::refcount += 1;
    }

    Class_xml_properties_from_xml_textblocklist::~Class_xml_properties_from_xml_textblocklist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_xml_properties_from_xml_textblocklist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_xml_properties_from_xml_textblocklist output = vx_data_xml::e_xml_properties_from_xml_textblocklist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_xml_properties_from_xml_textblocklist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_xml_properties_from_xml_textblocklist output = vx_data_xml::e_xml_properties_from_xml_textblocklist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_xml_properties_from_xml_textblocklist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/xml", // pkgname
        "xml-properties<-xml-textblocklist", // name
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

    vx_core::Type_constdef Class_xml_properties_from_xml_textblocklist::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_xml_properties_from_xml_textblocklist::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/xml", // pkgname
        "xml-properties<-xml-textblocklist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_xml_properties_from_xml_textblocklist::vx_empty() const {return vx_data_xml::e_xml_properties_from_xml_textblocklist;}
    vx_core::Type_any Class_xml_properties_from_xml_textblocklist::vx_type() const {return vx_data_xml::t_xml_properties_from_xml_textblocklist;}
    vx_core::Type_msgblock Class_xml_properties_from_xml_textblocklist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_xml_properties_from_xml_textblocklist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_xml_properties_from_xml_textblocklist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_xml::Type_xml xmlarg = vx_core::vx_any_from_any(vx_data_xml::t_xml, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_textblocklist textblocklist = vx_core::vx_any_from_any(vx_data_textblock::t_textblocklist, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_xml::f_xml_properties_from_xml_textblocklist(xmlarg, textblocklist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func xml-property<-xml-textblock)
  vx_data_xml::Type_xml f_xml_property_from_xml_textblock(vx_data_xml::Type_xml xmlarg, vx_data_textblock::Type_textblock tbarg) {
    vx_data_xml::Type_xml output = vx_data_xml::e_xml;
    vx_core::vx_reserve({xmlarg, tbarg});
    output = vx_core::f_let(
      vx_data_xml::t_xml,
      vx_core::t_any_from_func->vx_fn_new({tbarg, xmlarg}, [tbarg, xmlarg]() {
        vx_data_textblock::Type_delim delim = tbarg->delim();
        vx_core::vx_ref_plus(delim);
        vx_core::Type_string text = tbarg->text();
        vx_core::vx_ref_plus(text);
        vx_core::Type_string delimname = delim->name();
        vx_core::vx_ref_plus(delimname);
        vx_core::Type_string tag = xmlarg->tag();
        vx_core::vx_ref_plus(tag);
        vx_core::Type_string prop = xmlarg->prop();
        vx_core::vx_ref_plus(prop);
        vx_core::Type_stringmap propmap = xmlarg->propmap();
        vx_core::vx_ref_plus(propmap);
        vx_data_xml::Type_xml output_1 = vx_core::f_switch(
          vx_data_xml::t_xml,
          delimname,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_case_1(
              vx_core::vx_new_string(""),
              vx_core::t_any_from_func->vx_fn_new({text, xmlarg, tbarg, tag, prop}, [text, xmlarg, tbarg, tag, prop]() {
                vx_data_xml::Type_xml output_1 = vx_core::f_if_2(
                  vx_data_xml::t_xml,
                  vx_core::vx_new(vx_core::t_thenelselist, {
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({text}, [text]() {
                        vx_core::Type_boolean output_1 = vx_type::f_boolean_from_string_starts(text, vx_core::vx_new_string("/"));
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({xmlarg, tbarg}, [xmlarg, tbarg]() {
                        vx_data_xml::Type_xml output_1 = vx_data_xml::f_xml_close_from_xml_textblock(xmlarg, tbarg);
                        return output_1;
                      })
                    ),
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({tag}, [tag]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eq(vx_core::vx_new_string(":notag"), tag);
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({xmlarg, text}, [xmlarg, text]() {
                        vx_core::Type_any output_1 = vx_core::f_copy(
                          vx_data_xml::t_xml,
                          xmlarg,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":tag"),
                            text
                          })
                        );
                        return output_1;
                      })
                    ),
                    vx_core::f_then(
                      vx_core::t_boolean_from_func->vx_fn_new({prop}, [prop]() {
                        vx_core::Type_boolean output_1 = vx_core::f_eq(vx_core::vx_new_string(""), prop);
                        return output_1;
                      }),
                      vx_core::t_any_from_func->vx_fn_new({xmlarg, text}, [xmlarg, text]() {
                        vx_core::Type_any output_1 = vx_core::f_copy(
                          vx_data_xml::t_xml,
                          xmlarg,
                          vx_core::vx_new(vx_core::t_anylist, {
                            vx_core::vx_new_string(":prop"),
                            text
                          })
                        );
                        return output_1;
                      })
                    )
                  })
                );
                return output_1;
              })
            ),
            vx_core::f_case_1(
              vx_core::vx_new_string("delimquote"),
              vx_core::t_any_from_func->vx_fn_new({prop, xmlarg, propmap, tbarg}, [prop, xmlarg, propmap, tbarg]() {
                vx_data_xml::Type_xml output_1 = vx_core::f_if_1(
                  vx_data_xml::t_xml,
                  vx_core::f_eq(vx_core::vx_new_string(""), prop),
                  vx_core::f_copy(
                    vx_data_xml::t_xml,
                    xmlarg,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::f_msg_from_error(vx_core::vx_new_string("Found quoted text with no matching attribute."))
                    })
                  ),
                  vx_core::f_copy(
                    vx_data_xml::t_xml,
                    xmlarg,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(":prop"),
                      vx_core::vx_new_string(""),
                      vx_core::vx_new_string(":propmap"),
                      vx_core::f_copy(
                        vx_core::t_stringmap,
                        propmap,
                        vx_core::vx_new(vx_core::t_anylist, {
                          prop,
                          vx_core::f_any_from_struct(
                            vx_core::t_string,
                            vx_core::f_any_from_list(
                              vx_data_textblock::t_textblock,
                              tbarg->children(),
                              vx_core::vx_new_int(1)
                            ),
                            vx_core::vx_new_string(":text")
                          )
                        })
                      )
                    })
                  )
                );
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({xmlarg}, [xmlarg]() {
                vx_core::Type_any output_1 = xmlarg;
                return output_1;
              })
            )
          })
        );
        vx_core::vx_release_one_except({delim, text, delimname, tag, prop, propmap}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({xmlarg, tbarg}, output);
    return output;
  }
  /**
   * @function xml_property_from_xml_textblock
   * Returns a modified xml from a single property.
   * @param  {xml} xmlarg
   * @param  {textblock} tbarg
   * @return {xml}
   * (func xml-property<-xml-textblock)
   */
  // (func xml-property<-xml-textblock)
  // class Class_xml_property_from_xml_textblock {
    Abstract_xml_property_from_xml_textblock::~Abstract_xml_property_from_xml_textblock() {}

    Class_xml_property_from_xml_textblock::Class_xml_property_from_xml_textblock() : Abstract_xml_property_from_xml_textblock::Abstract_xml_property_from_xml_textblock() {
      vx_core::refcount += 1;
    }

    Class_xml_property_from_xml_textblock::~Class_xml_property_from_xml_textblock() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_xml_property_from_xml_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_xml_property_from_xml_textblock output = vx_data_xml::e_xml_property_from_xml_textblock;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_xml_property_from_xml_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_xml_property_from_xml_textblock output = vx_data_xml::e_xml_property_from_xml_textblock;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_xml_property_from_xml_textblock::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/xml", // pkgname
        "xml-property<-xml-textblock", // name
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

    vx_core::Type_constdef Class_xml_property_from_xml_textblock::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_xml_property_from_xml_textblock::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/xml", // pkgname
        "xml-property<-xml-textblock", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_xml_property_from_xml_textblock::vx_empty() const {return vx_data_xml::e_xml_property_from_xml_textblock;}
    vx_core::Type_any Class_xml_property_from_xml_textblock::vx_type() const {return vx_data_xml::t_xml_property_from_xml_textblock;}
    vx_core::Type_msgblock Class_xml_property_from_xml_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_xml_property_from_xml_textblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_xml_property_from_xml_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_xml::Type_xml xmlarg = vx_core::vx_any_from_any(vx_data_xml::t_xml, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_textblock tbarg = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_xml::f_xml_property_from_xml_textblock(xmlarg, tbarg);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func xml-read<-file)
  vx_data_xml::Type_xml f_xml_read_from_file(vx_core::Type_context context, vx_data_file::Type_file file) {
    vx_data_xml::Type_xml output = vx_data_xml::e_xml;
    vx_core::vx_reserve(file);
    output = vx_core::f_let(
      vx_data_xml::t_xml,
      vx_core::t_any_from_func->vx_fn_new({context, file}, [context, file]() {
        vx_data_file::Type_file loaded = vx_data_file::f_file_read_from_file(context, file);
        vx_core::vx_ref_plus(loaded);
        vx_data_xml::Type_xml output_1 = vx_data_xml::f_xml_from_file(loaded);
        vx_core::vx_release_one_except(loaded, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(file, output);
    return output;
  }
  /**
   * @function xml_read_from_file
   * Returns a parsed xml from a file.
   * @param  {file} file
   * @return {xml}
   * (func xml-read<-file)
   */
  // (func xml-read<-file)
  // class Class_xml_read_from_file {
    Abstract_xml_read_from_file::~Abstract_xml_read_from_file() {}

    Class_xml_read_from_file::Class_xml_read_from_file() : Abstract_xml_read_from_file::Abstract_xml_read_from_file() {
      vx_core::refcount += 1;
    }

    Class_xml_read_from_file::~Class_xml_read_from_file() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_xml_read_from_file::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_xml_read_from_file output = vx_data_xml::e_xml_read_from_file;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_xml_read_from_file::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_xml_read_from_file output = vx_data_xml::e_xml_read_from_file;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_xml_read_from_file::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/xml", // pkgname
        "xml-read<-file", // name
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

    vx_core::Type_constdef Class_xml_read_from_file::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_xml_read_from_file::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/xml", // pkgname
        "xml-read<-file", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_xml_read_from_file::vx_empty() const {return vx_data_xml::e_xml_read_from_file;}
    vx_core::Type_any Class_xml_read_from_file::vx_type() const {return vx_data_xml::t_xml_read_from_file;}
    vx_core::Type_msgblock Class_xml_read_from_file::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_xml_read_from_file::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_xml_read_from_file::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_xml_read_from_file::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file inputval = vx_core::vx_any_from_any(vx_data_file::t_file, val);
      output = vx_data_xml::f_xml_read_from_file(context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_xml_read_from_file::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_file::Type_file file = vx_core::vx_any_from_any(vx_data_file::t_file, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_xml::f_xml_read_from_file(context, file);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func xml-text<-xml-textblock)
  vx_data_xml::Type_xml f_xml_text_from_xml_textblock(vx_data_xml::Type_xml xmlarg, vx_data_textblock::Type_textblock tb) {
    vx_data_xml::Type_xml output = vx_data_xml::e_xml;
    vx_core::vx_reserve({xmlarg, tb});
    output = vx_core::f_let(
      vx_data_xml::t_xml,
      vx_core::t_any_from_func->vx_fn_new({tb, xmlarg}, [tb, xmlarg]() {
        vx_core::Type_string text = tb->text();
        vx_core::vx_ref_plus(text);
        vx_data_xml::Type_xml xmlchg = vx_core::f_new(
          vx_data_xml::t_xml,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":text"),
            text
          })
        );
        vx_core::vx_ref_plus(xmlchg);
        vx_data_xml::Type_xml output_1 = vx_core::f_if_2(
          vx_data_xml::t_xml,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({xmlarg}, [xmlarg]() {
                vx_core::Type_boolean output_1 = vx_core::f_is_empty_1(xmlarg);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({xmlchg}, [xmlchg]() {
                vx_core::Type_any output_1 = xmlchg;
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({xmlarg, xmlchg}, [xmlarg, xmlchg]() {
                vx_core::Type_any output_1 = vx_core::f_copy(
                  vx_data_xml::t_xml,
                  xmlarg,
                  vx_core::vx_new(vx_core::t_anylist, {
                    vx_core::vx_new_string(":children"),
                    vx_core::f_new(
                      vx_data_xml::t_xmllist,
                      vx_core::vx_new(vx_core::t_anylist, {
                        xmlarg->children(),
                        xmlchg
                      })
                    )
                  })
                );
                return output_1;
              })
            )
          })
        );
        vx_core::vx_release_one_except({text, xmlchg}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({xmlarg, tb}, output);
    return output;
  }
  /**
   * @function xml_text_from_xml_textblock
   * Returns a modified xml from text.
   * @param  {xml} xmlarg
   * @param  {textblock} tb
   * @return {xml}
   * (func xml-text<-xml-textblock)
   */
  // (func xml-text<-xml-textblock)
  // class Class_xml_text_from_xml_textblock {
    Abstract_xml_text_from_xml_textblock::~Abstract_xml_text_from_xml_textblock() {}

    Class_xml_text_from_xml_textblock::Class_xml_text_from_xml_textblock() : Abstract_xml_text_from_xml_textblock::Abstract_xml_text_from_xml_textblock() {
      vx_core::refcount += 1;
    }

    Class_xml_text_from_xml_textblock::~Class_xml_text_from_xml_textblock() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_xml_text_from_xml_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_xml_text_from_xml_textblock output = vx_data_xml::e_xml_text_from_xml_textblock;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_xml_text_from_xml_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_xml_text_from_xml_textblock output = vx_data_xml::e_xml_text_from_xml_textblock;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_xml_text_from_xml_textblock::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/xml", // pkgname
        "xml-text<-xml-textblock", // name
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

    vx_core::Type_constdef Class_xml_text_from_xml_textblock::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_xml_text_from_xml_textblock::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/xml", // pkgname
        "xml-text<-xml-textblock", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_xml_text_from_xml_textblock::vx_empty() const {return vx_data_xml::e_xml_text_from_xml_textblock;}
    vx_core::Type_any Class_xml_text_from_xml_textblock::vx_type() const {return vx_data_xml::t_xml_text_from_xml_textblock;}
    vx_core::Type_msgblock Class_xml_text_from_xml_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_xml_text_from_xml_textblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_xml_text_from_xml_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_xml::Type_xml xmlarg = vx_core::vx_any_from_any(vx_data_xml::t_xml, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_textblock::Type_textblock tb = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_data_xml::f_xml_text_from_xml_textblock(xmlarg, tb);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func xml<-file)
  vx_data_xml::Type_xml f_xml_from_file(vx_data_file::Type_file file) {
    vx_data_xml::Type_xml output = vx_data_xml::e_xml;
    vx_core::vx_reserve(file);
    output = vx_core::f_let(
      vx_data_xml::t_xml,
      vx_core::t_any_from_func->vx_fn_new({file}, [file]() {
        vx_core::Type_string text = file->text();
        vx_core::vx_ref_plus(text);
        vx_data_xml::Type_xml output_1 = vx_data_xml::f_xml_from_string(text);
        vx_core::vx_release_one_except(text, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(file, output);
    return output;
  }
  /**
   * @function xml_from_file
   * Returns a parsed xml from a file.
   * @param  {file} file
   * @return {xml}
   * (func xml<-file)
   */
  // (func xml<-file)
  // class Class_xml_from_file {
    Abstract_xml_from_file::~Abstract_xml_from_file() {}

    Class_xml_from_file::Class_xml_from_file() : Abstract_xml_from_file::Abstract_xml_from_file() {
      vx_core::refcount += 1;
    }

    Class_xml_from_file::~Class_xml_from_file() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_xml_from_file::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_xml_from_file output = vx_data_xml::e_xml_from_file;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_xml_from_file::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_xml_from_file output = vx_data_xml::e_xml_from_file;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_xml_from_file::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/xml", // pkgname
        "xml<-file", // name
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

    vx_core::Type_constdef Class_xml_from_file::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_xml_from_file::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/xml", // pkgname
        "xml<-file", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_xml_from_file::vx_empty() const {return vx_data_xml::e_xml_from_file;}
    vx_core::Type_any Class_xml_from_file::vx_type() const {return vx_data_xml::t_xml_from_file;}
    vx_core::Type_msgblock Class_xml_from_file::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_xml_from_file::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_xml_from_file::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_xml_from_file::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file inputval = vx_core::vx_any_from_any(vx_data_file::t_file, val);
      output = vx_data_xml::f_xml_from_file(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_xml_from_file::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file file = vx_core::vx_any_from_any(vx_data_file::t_file, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_xml::f_xml_from_file(file);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func xml<-string)
  vx_data_xml::Type_xml f_xml_from_string(vx_core::Type_string text) {
    vx_data_xml::Type_xml output = vx_data_xml::e_xml;
    vx_core::vx_reserve(text);
    output = vx_core::f_let(
      vx_data_xml::t_xml,
      vx_core::t_any_from_func->vx_fn_new({text}, [text]() {
        vx_data_textblock::Type_textblock tb = vx_data_xml::f_textblock_xml_from_string(text);
        vx_core::vx_ref_plus(tb);
        vx_data_xml::Type_xml output_1 = vx_data_xml::f_xml_from_textblock(tb);
        vx_core::vx_release_one_except(tb, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(text, output);
    return output;
  }
  /**
   * @function xml_from_string
   * Returns a parsed xml from a string.
   * @param  {string} text
   * @return {xml}
   * (func xml<-string)
   */
  // (func xml<-string)
  // class Class_xml_from_string {
    Abstract_xml_from_string::~Abstract_xml_from_string() {}

    Class_xml_from_string::Class_xml_from_string() : Abstract_xml_from_string::Abstract_xml_from_string() {
      vx_core::refcount += 1;
    }

    Class_xml_from_string::~Class_xml_from_string() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_xml_from_string::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_xml_from_string output = vx_data_xml::e_xml_from_string;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_xml_from_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_xml::Func_xml_from_string output = vx_data_xml::e_xml_from_string;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_xml_from_string::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/xml", // pkgname
        "xml<-string", // name
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

    vx_core::Type_constdef Class_xml_from_string::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_xml_from_string::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/xml", // pkgname
        "xml<-string", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_xml_from_string::vx_empty() const {return vx_data_xml::e_xml_from_string;}
    vx_core::Type_any Class_xml_from_string::vx_type() const {return vx_data_xml::t_xml_from_string;}
    vx_core::Type_msgblock Class_xml_from_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_xml_from_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_xml_from_string::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_xml_from_string::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_data_xml::f_xml_from_string(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_xml_from_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_xml::f_xml_from_string(text);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func xml<-textblock)
  vx_data_xml::Type_xml f_xml_from_textblock(vx_data_textblock::Type_textblock textblock) {
    vx_data_xml::Type_xml output = vx_data_xml::e_xml;
    vx_core::vx_reserve(textblock);
    output = vx_data_xml::f_xml_parse_from_xml_textblocklist(
      vx_core::f_empty(
        vx_data_xml::t_xml
      ),
      textblock->children()
    );
    vx_core::vx_release_one_except(textblock, output);
    return output;
  }
  /**
   * @function xml_from_textblock
   * Returns a parsed xml from a textblock.
   * @param  {textblock} textblock
   * @return {xml}
   * (func xml<-textblock)
   */
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

    vx_core::Type_constdef Class_xml_from_textblock::vx_constdef() const {return this->vx_p_constdef;}

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
  vx_data_xml::Type_xmllist e_xmllist = NULL;
  vx_data_xml::Type_xmllist t_xmllist = NULL;
  vx_data_xml::Type_xmlpropmap e_xmlpropmap = NULL;
  vx_data_xml::Type_xmlpropmap t_xmlpropmap = NULL;
  vx_data_xml::Const_delimxml c_delimxml = NULL;
  vx_data_xml::Const_delimxmlcdata c_delimxmlcdata = NULL;
  vx_data_xml::Const_delimxmlcomment c_delimxmlcomment = NULL;
  vx_data_xml::Const_delimxmlequal c_delimxmlequal = NULL;
  vx_data_xml::Func_string_decodexml_from_string e_string_decodexml_from_string = NULL;
  vx_data_xml::Func_string_decodexml_from_string t_string_decodexml_from_string = NULL;
  vx_data_xml::Func_string_first_from_xml e_string_first_from_xml = NULL;
  vx_data_xml::Func_string_first_from_xml t_string_first_from_xml = NULL;
  vx_data_xml::Func_textblock_xml_from_string e_textblock_xml_from_string = NULL;
  vx_data_xml::Func_textblock_xml_from_string t_textblock_xml_from_string = NULL;
  vx_data_xml::Func_xml_angle_from_xml_textblock e_xml_angle_from_xml_textblock = NULL;
  vx_data_xml::Func_xml_angle_from_xml_textblock t_xml_angle_from_xml_textblock = NULL;
  vx_data_xml::Func_xml_close_from_xml_textblock e_xml_close_from_xml_textblock = NULL;
  vx_data_xml::Func_xml_close_from_xml_textblock t_xml_close_from_xml_textblock = NULL;
  vx_data_xml::Func_xml_parse_from_xml_textblock e_xml_parse_from_xml_textblock = NULL;
  vx_data_xml::Func_xml_parse_from_xml_textblock t_xml_parse_from_xml_textblock = NULL;
  vx_data_xml::Func_xml_parse_from_xml_textblocklist e_xml_parse_from_xml_textblocklist = NULL;
  vx_data_xml::Func_xml_parse_from_xml_textblocklist t_xml_parse_from_xml_textblocklist = NULL;
  vx_data_xml::Func_xml_properties_from_xml_textblocklist e_xml_properties_from_xml_textblocklist = NULL;
  vx_data_xml::Func_xml_properties_from_xml_textblocklist t_xml_properties_from_xml_textblocklist = NULL;
  vx_data_xml::Func_xml_property_from_xml_textblock e_xml_property_from_xml_textblock = NULL;
  vx_data_xml::Func_xml_property_from_xml_textblock t_xml_property_from_xml_textblock = NULL;
  vx_data_xml::Func_xml_read_from_file e_xml_read_from_file = NULL;
  vx_data_xml::Func_xml_read_from_file t_xml_read_from_file = NULL;
  vx_data_xml::Func_xml_text_from_xml_textblock e_xml_text_from_xml_textblock = NULL;
  vx_data_xml::Func_xml_text_from_xml_textblock t_xml_text_from_xml_textblock = NULL;
  vx_data_xml::Func_xml_from_file e_xml_from_file = NULL;
  vx_data_xml::Func_xml_from_file t_xml_from_file = NULL;
  vx_data_xml::Func_xml_from_string e_xml_from_string = NULL;
  vx_data_xml::Func_xml_from_string t_xml_from_string = NULL;
  vx_data_xml::Func_xml_from_textblock e_xml_from_textblock = NULL;
  vx_data_xml::Func_xml_from_textblock t_xml_from_textblock = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_data_xml::c_delimxml = new vx_data_xml::Class_delimxml();
      vx_data_xml::c_delimxmlcdata = new vx_data_xml::Class_delimxmlcdata();
      vx_data_xml::c_delimxmlcomment = new vx_data_xml::Class_delimxmlcomment();
      vx_data_xml::c_delimxmlequal = new vx_data_xml::Class_delimxmlequal();
      vx_data_xml::e_xml = new Class_xml();
      vx_core::vx_reserve_empty(vx_data_xml::e_xml);
      vx_data_xml::t_xml = new Class_xml();
      vx_core::vx_reserve_type(vx_data_xml::t_xml);
      vx_data_xml::e_xmllist = new Class_xmllist();
      vx_core::vx_reserve_empty(vx_data_xml::e_xmllist);
      vx_data_xml::t_xmllist = new Class_xmllist();
      vx_core::vx_reserve_type(vx_data_xml::t_xmllist);
      vx_data_xml::e_xmlpropmap = new Class_xmlpropmap();
      vx_core::vx_reserve_empty(vx_data_xml::e_xmlpropmap);
      vx_data_xml::t_xmlpropmap = new Class_xmlpropmap();
      vx_core::vx_reserve_type(vx_data_xml::t_xmlpropmap);
      vx_data_xml::e_string_decodexml_from_string = new vx_data_xml::Class_string_decodexml_from_string();
      vx_core::vx_reserve_empty(vx_data_xml::e_string_decodexml_from_string);
      vx_data_xml::t_string_decodexml_from_string = new vx_data_xml::Class_string_decodexml_from_string();
      vx_core::vx_reserve_type(vx_data_xml::t_string_decodexml_from_string);
      vx_data_xml::e_string_first_from_xml = new vx_data_xml::Class_string_first_from_xml();
      vx_core::vx_reserve_empty(vx_data_xml::e_string_first_from_xml);
      vx_data_xml::t_string_first_from_xml = new vx_data_xml::Class_string_first_from_xml();
      vx_core::vx_reserve_type(vx_data_xml::t_string_first_from_xml);
      vx_data_xml::e_textblock_xml_from_string = new vx_data_xml::Class_textblock_xml_from_string();
      vx_core::vx_reserve_empty(vx_data_xml::e_textblock_xml_from_string);
      vx_data_xml::t_textblock_xml_from_string = new vx_data_xml::Class_textblock_xml_from_string();
      vx_core::vx_reserve_type(vx_data_xml::t_textblock_xml_from_string);
      vx_data_xml::e_xml_angle_from_xml_textblock = new vx_data_xml::Class_xml_angle_from_xml_textblock();
      vx_core::vx_reserve_empty(vx_data_xml::e_xml_angle_from_xml_textblock);
      vx_data_xml::t_xml_angle_from_xml_textblock = new vx_data_xml::Class_xml_angle_from_xml_textblock();
      vx_core::vx_reserve_type(vx_data_xml::t_xml_angle_from_xml_textblock);
      vx_data_xml::e_xml_close_from_xml_textblock = new vx_data_xml::Class_xml_close_from_xml_textblock();
      vx_core::vx_reserve_empty(vx_data_xml::e_xml_close_from_xml_textblock);
      vx_data_xml::t_xml_close_from_xml_textblock = new vx_data_xml::Class_xml_close_from_xml_textblock();
      vx_core::vx_reserve_type(vx_data_xml::t_xml_close_from_xml_textblock);
      vx_data_xml::e_xml_parse_from_xml_textblock = new vx_data_xml::Class_xml_parse_from_xml_textblock();
      vx_core::vx_reserve_empty(vx_data_xml::e_xml_parse_from_xml_textblock);
      vx_data_xml::t_xml_parse_from_xml_textblock = new vx_data_xml::Class_xml_parse_from_xml_textblock();
      vx_core::vx_reserve_type(vx_data_xml::t_xml_parse_from_xml_textblock);
      vx_data_xml::e_xml_parse_from_xml_textblocklist = new vx_data_xml::Class_xml_parse_from_xml_textblocklist();
      vx_core::vx_reserve_empty(vx_data_xml::e_xml_parse_from_xml_textblocklist);
      vx_data_xml::t_xml_parse_from_xml_textblocklist = new vx_data_xml::Class_xml_parse_from_xml_textblocklist();
      vx_core::vx_reserve_type(vx_data_xml::t_xml_parse_from_xml_textblocklist);
      vx_data_xml::e_xml_properties_from_xml_textblocklist = new vx_data_xml::Class_xml_properties_from_xml_textblocklist();
      vx_core::vx_reserve_empty(vx_data_xml::e_xml_properties_from_xml_textblocklist);
      vx_data_xml::t_xml_properties_from_xml_textblocklist = new vx_data_xml::Class_xml_properties_from_xml_textblocklist();
      vx_core::vx_reserve_type(vx_data_xml::t_xml_properties_from_xml_textblocklist);
      vx_data_xml::e_xml_property_from_xml_textblock = new vx_data_xml::Class_xml_property_from_xml_textblock();
      vx_core::vx_reserve_empty(vx_data_xml::e_xml_property_from_xml_textblock);
      vx_data_xml::t_xml_property_from_xml_textblock = new vx_data_xml::Class_xml_property_from_xml_textblock();
      vx_core::vx_reserve_type(vx_data_xml::t_xml_property_from_xml_textblock);
      vx_data_xml::e_xml_read_from_file = new vx_data_xml::Class_xml_read_from_file();
      vx_core::vx_reserve_empty(vx_data_xml::e_xml_read_from_file);
      vx_data_xml::t_xml_read_from_file = new vx_data_xml::Class_xml_read_from_file();
      vx_core::vx_reserve_type(vx_data_xml::t_xml_read_from_file);
      vx_data_xml::e_xml_text_from_xml_textblock = new vx_data_xml::Class_xml_text_from_xml_textblock();
      vx_core::vx_reserve_empty(vx_data_xml::e_xml_text_from_xml_textblock);
      vx_data_xml::t_xml_text_from_xml_textblock = new vx_data_xml::Class_xml_text_from_xml_textblock();
      vx_core::vx_reserve_type(vx_data_xml::t_xml_text_from_xml_textblock);
      vx_data_xml::e_xml_from_file = new vx_data_xml::Class_xml_from_file();
      vx_core::vx_reserve_empty(vx_data_xml::e_xml_from_file);
      vx_data_xml::t_xml_from_file = new vx_data_xml::Class_xml_from_file();
      vx_core::vx_reserve_type(vx_data_xml::t_xml_from_file);
      vx_data_xml::e_xml_from_string = new vx_data_xml::Class_xml_from_string();
      vx_core::vx_reserve_empty(vx_data_xml::e_xml_from_string);
      vx_data_xml::t_xml_from_string = new vx_data_xml::Class_xml_from_string();
      vx_core::vx_reserve_type(vx_data_xml::t_xml_from_string);
      vx_data_xml::e_xml_from_textblock = new vx_data_xml::Class_xml_from_textblock();
      vx_core::vx_reserve_empty(vx_data_xml::e_xml_from_textblock);
      vx_data_xml::t_xml_from_textblock = new vx_data_xml::Class_xml_from_textblock();
      vx_core::vx_reserve_type(vx_data_xml::t_xml_from_textblock);
      vx_data_xml::Class_delimxml::vx_const_new(vx_data_xml::c_delimxml);
      vx_data_xml::Class_delimxmlcdata::vx_const_new(vx_data_xml::c_delimxmlcdata);
      vx_data_xml::Class_delimxmlcomment::vx_const_new(vx_data_xml::c_delimxmlcomment);
      vx_data_xml::Class_delimxmlequal::vx_const_new(vx_data_xml::c_delimxmlequal);
      vx_core::vx_Type_mapany maptype;
      vx_core::vx_Type_mapany mapconst;
      vx_core::vx_Type_mapfunc mapfunc;
      vx_core::vx_Type_mapany mapempty;
      maptype["xml"] = vx_data_xml::t_xml;
      maptype["xmllist"] = vx_data_xml::t_xmllist;
      maptype["xmlpropmap"] = vx_data_xml::t_xmlpropmap;
      mapconst["delimxml"] = vx_data_xml::c_delimxml;
      mapconst["delimxmlcdata"] = vx_data_xml::c_delimxmlcdata;
      mapconst["delimxmlcomment"] = vx_data_xml::c_delimxmlcomment;
      mapconst["delimxmlequal"] = vx_data_xml::c_delimxmlequal;
      mapfunc["string-decodexml<-string"] = vx_data_xml::t_string_decodexml_from_string;
      mapfunc["string-first<-xml"] = vx_data_xml::t_string_first_from_xml;
      mapfunc["textblock-xml<-string"] = vx_data_xml::t_textblock_xml_from_string;
      mapfunc["xml-angle<-xml-textblock"] = vx_data_xml::t_xml_angle_from_xml_textblock;
      mapfunc["xml-close<-xml-textblock"] = vx_data_xml::t_xml_close_from_xml_textblock;
      mapfunc["xml-parse<-xml-textblock"] = vx_data_xml::t_xml_parse_from_xml_textblock;
      mapfunc["xml-parse<-xml-textblocklist"] = vx_data_xml::t_xml_parse_from_xml_textblocklist;
      mapfunc["xml-properties<-xml-textblocklist"] = vx_data_xml::t_xml_properties_from_xml_textblocklist;
      mapfunc["xml-property<-xml-textblock"] = vx_data_xml::t_xml_property_from_xml_textblock;
      mapfunc["xml-read<-file"] = vx_data_xml::t_xml_read_from_file;
      mapfunc["xml-text<-xml-textblock"] = vx_data_xml::t_xml_text_from_xml_textblock;
      mapfunc["xml<-file"] = vx_data_xml::t_xml_from_file;
      mapfunc["xml<-string"] = vx_data_xml::t_xml_from_string;
      mapfunc["xml<-textblock"] = vx_data_xml::t_xml_from_textblock;
      vx_core::vx_global_package_set("vx/data/xml", maptype, mapconst, mapfunc);
	   }
  // }

}
