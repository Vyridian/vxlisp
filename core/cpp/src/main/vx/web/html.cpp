#include <map>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/event.hpp"
#include "../../vx/type.hpp"
#include "html.hpp"

namespace vx_web_html {

// :body


  // (type node)
  // class Class_node {
    Abstract_node::~Abstract_node() {}

    Class_node::Class_node() : Abstract_node::Abstract_node() {
      vx_core::refcount += 1;
    }

    Class_node::~Class_node() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_eventmap,
        this->vx_p_style,
        this->vx_p_style_unique,
        this->vx_p_stylelist
      });
    }

    // id()
    vx_core::Type_string Class_node::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // eventmap()
    vx_event::Type_eventmap Class_node::eventmap() const {
      vx_event::Type_eventmap output = this->vx_p_eventmap;
      if (!output) {
        output = vx_event::e_eventmap;
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_node::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // style_unique()
    vx_web_html::Type_style Class_node::style_unique() const {
      vx_web_html::Type_style output = this->vx_p_style_unique;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // stylelist()
    vx_web_html::Type_stylelist Class_node::stylelist() const {
      vx_web_html::Type_stylelist output = this->vx_p_stylelist;
      if (!output) {
        output = vx_web_html::e_stylelist;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_node::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":eventmap") {
        output = this->eventmap();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":style-unique") {
        output = this->style_unique();
      } else if (skey == ":stylelist") {
        output = this->stylelist();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_node::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":eventmap"] = this->eventmap();
      output[":style"] = this->style();
      output[":style-unique"] = this->style_unique();
      output[":stylelist"] = this->stylelist();
      return output;
    }

    vx_core::Type_any Class_node::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_node, vals);
    }

    vx_core::Type_any Class_node::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_node output = vx_web_html::e_node;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_node val = vx_core::vx_any_from_any(vx_web_html::t_node, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_event::Type_eventmap vx_p_eventmap = val->eventmap();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_web_html::Type_style vx_p_style_unique = val->style_unique();
      vx_web_html::Type_stylelist vx_p_stylelist = val->stylelist();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":eventmap") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":style-unique") {
            key = testkey;
          } else if (testkey == ":stylelist") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new node) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (vx_p_id == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new node :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":eventmap") {
            if (vx_p_eventmap == valsub) {
            } else if (valsubtype == vx_event::t_eventmap) {
              ischanged = true;
              vx_p_eventmap = vx_core::vx_any_from_any(vx_event::t_eventmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new node :eventmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (vx_p_style == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new node :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style-unique") {
            if (vx_p_style_unique == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style_unique = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new node :style-unique " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":stylelist") {
            if (vx_p_stylelist == valsub) {
            } else if (valsubtype == vx_web_html::t_stylelist) {
              ischanged = true;
              vx_p_stylelist = vx_core::vx_any_from_any(vx_web_html::t_stylelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new node :stylelist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new node) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_node();
        if (output->vx_p_id != vx_p_id) {
          if (output->vx_p_id) {
            vx_core::vx_release_one(output->vx_p_id);
          }
          output->vx_p_id = vx_p_id;
          vx_core::vx_reserve(vx_p_id);
        }
        if (output->vx_p_eventmap != vx_p_eventmap) {
          if (output->vx_p_eventmap) {
            vx_core::vx_release_one(output->vx_p_eventmap);
          }
          output->vx_p_eventmap = vx_p_eventmap;
          vx_core::vx_reserve(vx_p_eventmap);
        }
        if (output->vx_p_style != vx_p_style) {
          if (output->vx_p_style) {
            vx_core::vx_release_one(output->vx_p_style);
          }
          output->vx_p_style = vx_p_style;
          vx_core::vx_reserve(vx_p_style);
        }
        if (output->vx_p_style_unique != vx_p_style_unique) {
          if (output->vx_p_style_unique) {
            vx_core::vx_release_one(output->vx_p_style_unique);
          }
          output->vx_p_style_unique = vx_p_style_unique;
          vx_core::vx_reserve(vx_p_style_unique);
        }
        if (output->vx_p_stylelist != vx_p_stylelist) {
          if (output->vx_p_stylelist) {
            vx_core::vx_release_one(output->vx_p_stylelist);
          }
          output->vx_p_stylelist = vx_p_stylelist;
          vx_core::vx_reserve(vx_p_stylelist);
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

    vx_core::Type_msgblock Class_node::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_node::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_node::vx_empty() const {return vx_web_html::e_node;}
    vx_core::Type_any Class_node::vx_type() const {return vx_web_html::t_node;}

    vx_core::Type_typedef Class_node::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "id", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "eventmap", // name
            vx_event::t_eventmap // type
          ),
          vx_core::vx_new_arg(
            "style", // name
            vx_web_html::t_style // type
          ),
          vx_core::vx_new_arg(
            "style-unique", // name
            vx_web_html::t_style // type
          ),
          vx_core::vx_new_arg(
            "stylelist", // name
            vx_web_html::t_stylelist // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_node::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type divchild)
  // class Class_divchild {
    Abstract_divchild::~Abstract_divchild() {}

    Class_divchild::Class_divchild() : Abstract_divchild::Abstract_divchild() {
      vx_core::refcount += 1;
    }

    Class_divchild::~Class_divchild() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        
      });
    }

    // vx_get_any(key)
    vx_core::Type_any Class_divchild::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_divchild::vx_map() const {
      vx_core::vx_Type_mapany output;
      return output;
    }

    vx_core::Type_any Class_divchild::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_divchild, vals);
    }

    vx_core::Type_any Class_divchild::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_divchild output = vx_web_html::e_divchild;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_divchild val = vx_core::vx_any_from_any(vx_web_html::t_divchild, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_divchild::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_divchild::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_divchild::vx_empty() const {return vx_web_html::e_divchild;}
    vx_core::Type_any Class_divchild::vx_type() const {return vx_web_html::t_divchild;}

    vx_core::Type_typedef Class_divchild::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
      return output;
    }

    vx_core::Type_constdef Class_divchild::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type body)
  // class Class_body {
    Abstract_body::~Abstract_body() {}

    Class_body::Class_body() : Abstract_body::Abstract_body() {
      vx_core::refcount += 1;
    }

    Class_body::~Class_body() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_nodes
      });
    }

    // nodes()
    vx_web_html::Type_divchildlist Class_body::nodes() const {
      vx_web_html::Type_divchildlist output = this->vx_p_nodes;
      if (!output) {
        output = vx_web_html::e_divchildlist;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_body::vx_get_any(vx_core::Type_string key) const {
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
    vx_core::vx_Type_mapany Class_body::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":nodes"] = this->nodes();
      return output;
    }

    vx_core::Type_any Class_body::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_body, vals);
    }

    vx_core::Type_any Class_body::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_body output = vx_web_html::e_body;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_body val = vx_core::vx_any_from_any(vx_web_html::t_body, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_web_html::Type_divchildlist vx_p_nodes = val->nodes();
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
          } else if (valsubtype == vx_web_html::t_divchildlist) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_divchildlist, valsub);
          } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_divchildlist)) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_divchildlist, valsub);
          } else if (valsubtype == vx_web_html::t_divchild) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_copy(vx_p_nodes, {valsub});
          } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_divchild)) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_copy(vx_p_nodes, {valsub});
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new body) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":nodes") {
            if (vx_p_nodes == valsub) {
            } else if (valsubtype == vx_web_html::t_divchildlist) {
              ischanged = true;
              vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_divchildlist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new body :nodes " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new body) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_body();
        if (output->vx_p_nodes != vx_p_nodes) {
          if (output->vx_p_nodes) {
            vx_core::vx_release_one(output->vx_p_nodes);
          }
          output->vx_p_nodes = vx_p_nodes;
          vx_core::vx_reserve(vx_p_nodes);
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

    vx_core::Type_msgblock Class_body::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_body::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_body::vx_empty() const {return vx_web_html::e_body;}
    vx_core::Type_any Class_body::vx_type() const {return vx_web_html::t_body;}

    vx_core::Type_typedef Class_body::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "nodes", // name
            vx_web_html::t_divchildlist // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_body::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type details)
  // class Class_details {
    Abstract_details::~Abstract_details() {}

    Class_details::Class_details() : Abstract_details::Abstract_details() {
      vx_core::refcount += 1;
    }

    Class_details::~Class_details() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_eventmap,
        this->vx_p_style,
        this->vx_p_style_unique,
        this->vx_p_stylelist,
        this->vx_p_summary,
        this->vx_p_nodes
      });
    }

    // id()
    vx_core::Type_string Class_details::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // eventmap()
    vx_event::Type_eventmap Class_details::eventmap() const {
      vx_event::Type_eventmap output = this->vx_p_eventmap;
      if (!output) {
        output = vx_event::e_eventmap;
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_details::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // style_unique()
    vx_web_html::Type_style Class_details::style_unique() const {
      vx_web_html::Type_style output = this->vx_p_style_unique;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // stylelist()
    vx_web_html::Type_stylelist Class_details::stylelist() const {
      vx_web_html::Type_stylelist output = this->vx_p_stylelist;
      if (!output) {
        output = vx_web_html::e_stylelist;
      }
      return output;
    }

    // summary()
    vx_web_html::Type_divchildlist Class_details::summary() const {
      vx_web_html::Type_divchildlist output = this->vx_p_summary;
      if (!output) {
        output = vx_web_html::e_divchildlist;
      }
      return output;
    }

    // nodes()
    vx_web_html::Type_divchildlist Class_details::nodes() const {
      vx_web_html::Type_divchildlist output = this->vx_p_nodes;
      if (!output) {
        output = vx_web_html::e_divchildlist;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_details::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":eventmap") {
        output = this->eventmap();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":style-unique") {
        output = this->style_unique();
      } else if (skey == ":stylelist") {
        output = this->stylelist();
      } else if (skey == ":summary") {
        output = this->summary();
      } else if (skey == ":nodes") {
        output = this->nodes();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_details::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":eventmap"] = this->eventmap();
      output[":style"] = this->style();
      output[":style-unique"] = this->style_unique();
      output[":stylelist"] = this->stylelist();
      output[":summary"] = this->summary();
      output[":nodes"] = this->nodes();
      return output;
    }

    vx_core::Type_any Class_details::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_details, vals);
    }

    vx_core::Type_any Class_details::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_details output = vx_web_html::e_details;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_details val = vx_core::vx_any_from_any(vx_web_html::t_details, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_event::Type_eventmap vx_p_eventmap = val->eventmap();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_web_html::Type_style vx_p_style_unique = val->style_unique();
      vx_web_html::Type_stylelist vx_p_stylelist = val->stylelist();
      vx_web_html::Type_divchildlist vx_p_summary = val->summary();
      vx_web_html::Type_divchildlist vx_p_nodes = val->nodes();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":eventmap") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":style-unique") {
            key = testkey;
          } else if (testkey == ":stylelist") {
            key = testkey;
          } else if (testkey == ":summary") {
            key = testkey;
          } else if (testkey == ":nodes") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new details) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (vx_p_id == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new details :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":eventmap") {
            if (vx_p_eventmap == valsub) {
            } else if (valsubtype == vx_event::t_eventmap) {
              ischanged = true;
              vx_p_eventmap = vx_core::vx_any_from_any(vx_event::t_eventmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new details :eventmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (vx_p_style == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new details :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style-unique") {
            if (vx_p_style_unique == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style_unique = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new details :style-unique " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":stylelist") {
            if (vx_p_stylelist == valsub) {
            } else if (valsubtype == vx_web_html::t_stylelist) {
              ischanged = true;
              vx_p_stylelist = vx_core::vx_any_from_any(vx_web_html::t_stylelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new details :stylelist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":summary") {
            if (vx_p_summary == valsub) {
            } else if (valsubtype == vx_web_html::t_divchildlist) {
              ischanged = true;
              vx_p_summary = vx_core::vx_any_from_any(vx_web_html::t_divchildlist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new details :summary " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":nodes") {
            if (vx_p_nodes == valsub) {
            } else if (valsubtype == vx_web_html::t_divchildlist) {
              ischanged = true;
              vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_divchildlist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new details :nodes " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new details) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_details();
        if (output->vx_p_id != vx_p_id) {
          if (output->vx_p_id) {
            vx_core::vx_release_one(output->vx_p_id);
          }
          output->vx_p_id = vx_p_id;
          vx_core::vx_reserve(vx_p_id);
        }
        if (output->vx_p_eventmap != vx_p_eventmap) {
          if (output->vx_p_eventmap) {
            vx_core::vx_release_one(output->vx_p_eventmap);
          }
          output->vx_p_eventmap = vx_p_eventmap;
          vx_core::vx_reserve(vx_p_eventmap);
        }
        if (output->vx_p_style != vx_p_style) {
          if (output->vx_p_style) {
            vx_core::vx_release_one(output->vx_p_style);
          }
          output->vx_p_style = vx_p_style;
          vx_core::vx_reserve(vx_p_style);
        }
        if (output->vx_p_style_unique != vx_p_style_unique) {
          if (output->vx_p_style_unique) {
            vx_core::vx_release_one(output->vx_p_style_unique);
          }
          output->vx_p_style_unique = vx_p_style_unique;
          vx_core::vx_reserve(vx_p_style_unique);
        }
        if (output->vx_p_stylelist != vx_p_stylelist) {
          if (output->vx_p_stylelist) {
            vx_core::vx_release_one(output->vx_p_stylelist);
          }
          output->vx_p_stylelist = vx_p_stylelist;
          vx_core::vx_reserve(vx_p_stylelist);
        }
        if (output->vx_p_summary != vx_p_summary) {
          if (output->vx_p_summary) {
            vx_core::vx_release_one(output->vx_p_summary);
          }
          output->vx_p_summary = vx_p_summary;
          vx_core::vx_reserve(vx_p_summary);
        }
        if (output->vx_p_nodes != vx_p_nodes) {
          if (output->vx_p_nodes) {
            vx_core::vx_release_one(output->vx_p_nodes);
          }
          output->vx_p_nodes = vx_p_nodes;
          vx_core::vx_reserve(vx_p_nodes);
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

    vx_core::Type_msgblock Class_details::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_details::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_details::vx_empty() const {return vx_web_html::e_details;}
    vx_core::Type_any Class_details::vx_type() const {return vx_web_html::t_details;}

    vx_core::Type_typedef Class_details::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "details", // name
        ":struct", // extends
        vx_core::vx_typelist_from_listany({vx_web_html::t_node, vx_web_html::t_divchild}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "summary", // name
            vx_web_html::t_divchildlist // type
          ),
          vx_core::vx_new_arg(
            "nodes", // name
            vx_web_html::t_divchildlist // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_details::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type div)
  // class Class_div {
    Abstract_div::~Abstract_div() {}

    Class_div::Class_div() : Abstract_div::Abstract_div() {
      vx_core::refcount += 1;
    }

    Class_div::~Class_div() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_eventmap,
        this->vx_p_style,
        this->vx_p_style_unique,
        this->vx_p_stylelist,
        this->vx_p_nodes
      });
    }

    // id()
    vx_core::Type_string Class_div::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // eventmap()
    vx_event::Type_eventmap Class_div::eventmap() const {
      vx_event::Type_eventmap output = this->vx_p_eventmap;
      if (!output) {
        output = vx_event::e_eventmap;
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_div::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // style_unique()
    vx_web_html::Type_style Class_div::style_unique() const {
      vx_web_html::Type_style output = this->vx_p_style_unique;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // stylelist()
    vx_web_html::Type_stylelist Class_div::stylelist() const {
      vx_web_html::Type_stylelist output = this->vx_p_stylelist;
      if (!output) {
        output = vx_web_html::e_stylelist;
      }
      return output;
    }

    // nodes()
    vx_web_html::Type_divchildlist Class_div::nodes() const {
      vx_web_html::Type_divchildlist output = this->vx_p_nodes;
      if (!output) {
        output = vx_web_html::e_divchildlist;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_div::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":eventmap") {
        output = this->eventmap();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":style-unique") {
        output = this->style_unique();
      } else if (skey == ":stylelist") {
        output = this->stylelist();
      } else if (skey == ":nodes") {
        output = this->nodes();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_div::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":eventmap"] = this->eventmap();
      output[":style"] = this->style();
      output[":style-unique"] = this->style_unique();
      output[":stylelist"] = this->stylelist();
      output[":nodes"] = this->nodes();
      return output;
    }

    vx_core::Type_any Class_div::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_div, vals);
    }

    vx_core::Type_any Class_div::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_div output = vx_web_html::e_div;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_div val = vx_core::vx_any_from_any(vx_web_html::t_div, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_event::Type_eventmap vx_p_eventmap = val->eventmap();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_web_html::Type_style vx_p_style_unique = val->style_unique();
      vx_web_html::Type_stylelist vx_p_stylelist = val->stylelist();
      vx_web_html::Type_divchildlist vx_p_nodes = val->nodes();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":eventmap") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":style-unique") {
            key = testkey;
          } else if (testkey == ":stylelist") {
            key = testkey;
          } else if (testkey == ":nodes") {
            key = testkey;
          } else if (valsubtype == vx_web_html::t_divchildlist) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_divchildlist, valsub);
          } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_divchildlist)) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_divchildlist, valsub);
          } else if (valsubtype == vx_web_html::t_divchild) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_copy(vx_p_nodes, {valsub});
          } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_divchild)) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_copy(vx_p_nodes, {valsub});
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new div) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (vx_p_id == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new div :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":eventmap") {
            if (vx_p_eventmap == valsub) {
            } else if (valsubtype == vx_event::t_eventmap) {
              ischanged = true;
              vx_p_eventmap = vx_core::vx_any_from_any(vx_event::t_eventmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new div :eventmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (vx_p_style == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new div :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style-unique") {
            if (vx_p_style_unique == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style_unique = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new div :style-unique " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":stylelist") {
            if (vx_p_stylelist == valsub) {
            } else if (valsubtype == vx_web_html::t_stylelist) {
              ischanged = true;
              vx_p_stylelist = vx_core::vx_any_from_any(vx_web_html::t_stylelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new div :stylelist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":nodes") {
            if (vx_p_nodes == valsub) {
            } else if (valsubtype == vx_web_html::t_divchildlist) {
              ischanged = true;
              vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_divchildlist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new div :nodes " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new div) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_div();
        if (output->vx_p_id != vx_p_id) {
          if (output->vx_p_id) {
            vx_core::vx_release_one(output->vx_p_id);
          }
          output->vx_p_id = vx_p_id;
          vx_core::vx_reserve(vx_p_id);
        }
        if (output->vx_p_eventmap != vx_p_eventmap) {
          if (output->vx_p_eventmap) {
            vx_core::vx_release_one(output->vx_p_eventmap);
          }
          output->vx_p_eventmap = vx_p_eventmap;
          vx_core::vx_reserve(vx_p_eventmap);
        }
        if (output->vx_p_style != vx_p_style) {
          if (output->vx_p_style) {
            vx_core::vx_release_one(output->vx_p_style);
          }
          output->vx_p_style = vx_p_style;
          vx_core::vx_reserve(vx_p_style);
        }
        if (output->vx_p_style_unique != vx_p_style_unique) {
          if (output->vx_p_style_unique) {
            vx_core::vx_release_one(output->vx_p_style_unique);
          }
          output->vx_p_style_unique = vx_p_style_unique;
          vx_core::vx_reserve(vx_p_style_unique);
        }
        if (output->vx_p_stylelist != vx_p_stylelist) {
          if (output->vx_p_stylelist) {
            vx_core::vx_release_one(output->vx_p_stylelist);
          }
          output->vx_p_stylelist = vx_p_stylelist;
          vx_core::vx_reserve(vx_p_stylelist);
        }
        if (output->vx_p_nodes != vx_p_nodes) {
          if (output->vx_p_nodes) {
            vx_core::vx_release_one(output->vx_p_nodes);
          }
          output->vx_p_nodes = vx_p_nodes;
          vx_core::vx_reserve(vx_p_nodes);
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

    vx_core::Type_msgblock Class_div::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_div::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_div::vx_empty() const {return vx_web_html::e_div;}
    vx_core::Type_any Class_div::vx_type() const {return vx_web_html::t_div;}

    vx_core::Type_typedef Class_div::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "div", // name
        ":struct", // extends
        vx_core::vx_typelist_from_listany({vx_web_html::t_node, vx_web_html::t_divchild}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "nodes", // name
            vx_web_html::t_divchildlist // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_div::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type divchildlist)
  // class Class_divchildlist {
    Abstract_divchildlist::~Abstract_divchildlist() {}

    Class_divchildlist::Class_divchildlist() : Abstract_divchildlist::Abstract_divchildlist() {
      vx_core::refcount += 1;
    }

    Class_divchildlist::~Class_divchildlist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_divchildlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_web_html::Type_divchild Class_divchildlist::vx_get_divchild(vx_core::Type_int index) const {
      vx_web_html::Type_divchild output = vx_web_html::e_divchild;
      long iindex = index->vx_int();
      std::vector<vx_web_html::Type_divchild> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_web_html::Type_divchild> Class_divchildlist::vx_listdivchild() const {return vx_p_list;}

    vx_core::Type_any vx_web_html::Class_divchildlist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_divchild(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_divchildlist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_web_html::Type_divchildlist output = vx_web_html::e_divchildlist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_web_html::Type_divchild> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_web_html::t_divchild) {
          vx_web_html::Type_divchild castval = vx_core::vx_any_from_any(vx_web_html::t_divchild, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_web_html::t_divchild)) {
          vx_web_html::Type_divchild castval = vx_core::vx_any_from_any(vx_web_html::t_divchild, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(divchildlist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_divchildlist();
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

    vx_core::Type_any Class_divchildlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_divchildlist, vals);
    }

    vx_core::Type_any Class_divchildlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_divchildlist output = vx_web_html::e_divchildlist;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_divchildlist val = vx_core::vx_any_from_any(vx_web_html::t_divchildlist, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_web_html::Type_divchild> listval = val->vx_listdivchild();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_web_html::t_divchild) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_web_html::t_divchild, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_divchild)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_web_html::t_divchild, valsub));
        } else if (valsubtype == vx_web_html::t_divchildlist) {
          ischanged = true;
          vx_web_html::Type_divchildlist multi = vx_core::vx_any_from_any(vx_web_html::t_divchildlist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listdivchild());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new divchildlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_divchildlist();
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

    vx_core::Type_msgblock Class_divchildlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_divchildlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_divchildlist::vx_empty() const {return vx_web_html::e_divchildlist;}
    vx_core::Type_any Class_divchildlist::vx_type() const {return vx_web_html::t_divchildlist;}

    vx_core::Type_typedef Class_divchildlist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "divchildlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_web_html::t_divchild}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_divchildlist::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type divlist)
  // class Class_divlist {
    Abstract_divlist::~Abstract_divlist() {}

    Class_divlist::Class_divlist() : Abstract_divlist::Abstract_divlist() {
      vx_core::refcount += 1;
    }

    Class_divlist::~Class_divlist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_divlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_web_html::Type_div Class_divlist::vx_get_div(vx_core::Type_int index) const {
      vx_web_html::Type_div output = vx_web_html::e_div;
      long iindex = index->vx_int();
      std::vector<vx_web_html::Type_div> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_web_html::Type_div> Class_divlist::vx_listdiv() const {return vx_p_list;}

    vx_core::Type_any vx_web_html::Class_divlist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_div(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_divlist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_web_html::Type_divlist output = vx_web_html::e_divlist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_web_html::Type_div> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_web_html::t_div) {
          vx_web_html::Type_div castval = vx_core::vx_any_from_any(vx_web_html::t_div, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_web_html::t_div)) {
          vx_web_html::Type_div castval = vx_core::vx_any_from_any(vx_web_html::t_div, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(divlist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_divlist();
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

    vx_core::Type_any Class_divlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_divlist, vals);
    }

    vx_core::Type_any Class_divlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_divlist output = vx_web_html::e_divlist;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_divlist val = vx_core::vx_any_from_any(vx_web_html::t_divlist, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_web_html::Type_div> listval = val->vx_listdiv();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_web_html::t_div) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_web_html::t_div, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_div)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_web_html::t_div, valsub));
        } else if (valsubtype == vx_web_html::t_divlist) {
          ischanged = true;
          vx_web_html::Type_divlist multi = vx_core::vx_any_from_any(vx_web_html::t_divlist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listdiv());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new divlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_divlist();
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

    vx_core::Type_msgblock Class_divlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_divlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_divlist::vx_empty() const {return vx_web_html::e_divlist;}
    vx_core::Type_any Class_divlist::vx_type() const {return vx_web_html::t_divlist;}

    vx_core::Type_typedef Class_divlist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "divlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_web_html::t_div}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_divlist::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type footer)
  // class Class_footer {
    Abstract_footer::~Abstract_footer() {}

    Class_footer::Class_footer() : Abstract_footer::Abstract_footer() {
      vx_core::refcount += 1;
    }

    Class_footer::~Class_footer() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_nodes
      });
    }

    // nodes()
    vx_web_html::Type_divchildlist Class_footer::nodes() const {
      vx_web_html::Type_divchildlist output = this->vx_p_nodes;
      if (!output) {
        output = vx_web_html::e_divchildlist;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_footer::vx_get_any(vx_core::Type_string key) const {
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
    vx_core::vx_Type_mapany Class_footer::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":nodes"] = this->nodes();
      return output;
    }

    vx_core::Type_any Class_footer::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_footer, vals);
    }

    vx_core::Type_any Class_footer::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_footer output = vx_web_html::e_footer;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_footer val = vx_core::vx_any_from_any(vx_web_html::t_footer, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_web_html::Type_divchildlist vx_p_nodes = val->nodes();
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
          } else if (valsubtype == vx_web_html::t_divchildlist) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_divchildlist, valsub);
          } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_divchildlist)) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_divchildlist, valsub);
          } else if (valsubtype == vx_web_html::t_divchild) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_copy(vx_p_nodes, {valsub});
          } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_divchild)) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_copy(vx_p_nodes, {valsub});
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new footer) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":nodes") {
            if (vx_p_nodes == valsub) {
            } else if (valsubtype == vx_web_html::t_divchildlist) {
              ischanged = true;
              vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_divchildlist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new footer :nodes " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new footer) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_footer();
        if (output->vx_p_nodes != vx_p_nodes) {
          if (output->vx_p_nodes) {
            vx_core::vx_release_one(output->vx_p_nodes);
          }
          output->vx_p_nodes = vx_p_nodes;
          vx_core::vx_reserve(vx_p_nodes);
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

    vx_core::Type_msgblock Class_footer::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_footer::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_footer::vx_empty() const {return vx_web_html::e_footer;}
    vx_core::Type_any Class_footer::vx_type() const {return vx_web_html::t_footer;}

    vx_core::Type_typedef Class_footer::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "nodes", // name
            vx_web_html::t_divchildlist // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_footer::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type h1)
  // class Class_h1 {
    Abstract_h1::~Abstract_h1() {}

    Class_h1::Class_h1() : Abstract_h1::Abstract_h1() {
      vx_core::refcount += 1;
    }

    Class_h1::~Class_h1() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_eventmap,
        this->vx_p_style,
        this->vx_p_style_unique,
        this->vx_p_stylelist,
        this->vx_p_text
      });
    }

    // id()
    vx_core::Type_string Class_h1::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // eventmap()
    vx_event::Type_eventmap Class_h1::eventmap() const {
      vx_event::Type_eventmap output = this->vx_p_eventmap;
      if (!output) {
        output = vx_event::e_eventmap;
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_h1::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // style_unique()
    vx_web_html::Type_style Class_h1::style_unique() const {
      vx_web_html::Type_style output = this->vx_p_style_unique;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // stylelist()
    vx_web_html::Type_stylelist Class_h1::stylelist() const {
      vx_web_html::Type_stylelist output = this->vx_p_stylelist;
      if (!output) {
        output = vx_web_html::e_stylelist;
      }
      return output;
    }

    // text()
    vx_core::Type_string Class_h1::text() const {
      vx_core::Type_string output = this->vx_p_text;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_h1::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":eventmap") {
        output = this->eventmap();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":style-unique") {
        output = this->style_unique();
      } else if (skey == ":stylelist") {
        output = this->stylelist();
      } else if (skey == ":text") {
        output = this->text();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_h1::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":eventmap"] = this->eventmap();
      output[":style"] = this->style();
      output[":style-unique"] = this->style_unique();
      output[":stylelist"] = this->stylelist();
      output[":text"] = this->text();
      return output;
    }

    vx_core::Type_any Class_h1::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_h1, vals);
    }

    vx_core::Type_any Class_h1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_h1 output = vx_web_html::e_h1;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_h1 val = vx_core::vx_any_from_any(vx_web_html::t_h1, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_event::Type_eventmap vx_p_eventmap = val->eventmap();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_web_html::Type_style vx_p_style_unique = val->style_unique();
      vx_web_html::Type_stylelist vx_p_stylelist = val->stylelist();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":eventmap") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":style-unique") {
            key = testkey;
          } else if (testkey == ":stylelist") {
            key = testkey;
          } else if (testkey == ":text") {
            key = testkey;
          } else if (valsubtype == vx_core::t_string) { // default property
            ischanged = true;
            vx_p_text = vx_core::vx_any_from_any(vx_core::t_string, valsub);
          } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_core::t_string)) { // default property
            ischanged = true;
            vx_p_text = vx_core::vx_any_from_any(vx_core::t_string, valsub);
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h1) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (vx_p_id == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h1 :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":eventmap") {
            if (vx_p_eventmap == valsub) {
            } else if (valsubtype == vx_event::t_eventmap) {
              ischanged = true;
              vx_p_eventmap = vx_core::vx_any_from_any(vx_event::t_eventmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h1 :eventmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (vx_p_style == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h1 :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style-unique") {
            if (vx_p_style_unique == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style_unique = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h1 :style-unique " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":stylelist") {
            if (vx_p_stylelist == valsub) {
            } else if (valsubtype == vx_web_html::t_stylelist) {
              ischanged = true;
              vx_p_stylelist = vx_core::vx_any_from_any(vx_web_html::t_stylelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h1 :stylelist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":text") {
            if (vx_p_text == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_text = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h1 :text " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h1) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_h1();
        if (output->vx_p_id != vx_p_id) {
          if (output->vx_p_id) {
            vx_core::vx_release_one(output->vx_p_id);
          }
          output->vx_p_id = vx_p_id;
          vx_core::vx_reserve(vx_p_id);
        }
        if (output->vx_p_eventmap != vx_p_eventmap) {
          if (output->vx_p_eventmap) {
            vx_core::vx_release_one(output->vx_p_eventmap);
          }
          output->vx_p_eventmap = vx_p_eventmap;
          vx_core::vx_reserve(vx_p_eventmap);
        }
        if (output->vx_p_style != vx_p_style) {
          if (output->vx_p_style) {
            vx_core::vx_release_one(output->vx_p_style);
          }
          output->vx_p_style = vx_p_style;
          vx_core::vx_reserve(vx_p_style);
        }
        if (output->vx_p_style_unique != vx_p_style_unique) {
          if (output->vx_p_style_unique) {
            vx_core::vx_release_one(output->vx_p_style_unique);
          }
          output->vx_p_style_unique = vx_p_style_unique;
          vx_core::vx_reserve(vx_p_style_unique);
        }
        if (output->vx_p_stylelist != vx_p_stylelist) {
          if (output->vx_p_stylelist) {
            vx_core::vx_release_one(output->vx_p_stylelist);
          }
          output->vx_p_stylelist = vx_p_stylelist;
          vx_core::vx_reserve(vx_p_stylelist);
        }
        if (output->vx_p_text != vx_p_text) {
          if (output->vx_p_text) {
            vx_core::vx_release_one(output->vx_p_text);
          }
          output->vx_p_text = vx_p_text;
          vx_core::vx_reserve(vx_p_text);
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

    vx_core::Type_msgblock Class_h1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_h1::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_h1::vx_empty() const {return vx_web_html::e_h1;}
    vx_core::Type_any Class_h1::vx_type() const {return vx_web_html::t_h1;}

    vx_core::Type_typedef Class_h1::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "h1", // name
        ":struct", // extends
        vx_core::vx_typelist_from_listany({vx_web_html::t_node, vx_web_html::t_divchild}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "text", // name
            vx_core::t_string // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_h1::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type h2)
  // class Class_h2 {
    Abstract_h2::~Abstract_h2() {}

    Class_h2::Class_h2() : Abstract_h2::Abstract_h2() {
      vx_core::refcount += 1;
    }

    Class_h2::~Class_h2() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_eventmap,
        this->vx_p_style,
        this->vx_p_style_unique,
        this->vx_p_stylelist,
        this->vx_p_text
      });
    }

    // id()
    vx_core::Type_string Class_h2::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // eventmap()
    vx_event::Type_eventmap Class_h2::eventmap() const {
      vx_event::Type_eventmap output = this->vx_p_eventmap;
      if (!output) {
        output = vx_event::e_eventmap;
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_h2::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // style_unique()
    vx_web_html::Type_style Class_h2::style_unique() const {
      vx_web_html::Type_style output = this->vx_p_style_unique;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // stylelist()
    vx_web_html::Type_stylelist Class_h2::stylelist() const {
      vx_web_html::Type_stylelist output = this->vx_p_stylelist;
      if (!output) {
        output = vx_web_html::e_stylelist;
      }
      return output;
    }

    // text()
    vx_core::Type_string Class_h2::text() const {
      vx_core::Type_string output = this->vx_p_text;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_h2::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":eventmap") {
        output = this->eventmap();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":style-unique") {
        output = this->style_unique();
      } else if (skey == ":stylelist") {
        output = this->stylelist();
      } else if (skey == ":text") {
        output = this->text();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_h2::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":eventmap"] = this->eventmap();
      output[":style"] = this->style();
      output[":style-unique"] = this->style_unique();
      output[":stylelist"] = this->stylelist();
      output[":text"] = this->text();
      return output;
    }

    vx_core::Type_any Class_h2::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_h2, vals);
    }

    vx_core::Type_any Class_h2::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_h2 output = vx_web_html::e_h2;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_h2 val = vx_core::vx_any_from_any(vx_web_html::t_h2, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_event::Type_eventmap vx_p_eventmap = val->eventmap();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_web_html::Type_style vx_p_style_unique = val->style_unique();
      vx_web_html::Type_stylelist vx_p_stylelist = val->stylelist();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":eventmap") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":style-unique") {
            key = testkey;
          } else if (testkey == ":stylelist") {
            key = testkey;
          } else if (testkey == ":text") {
            key = testkey;
          } else if (valsubtype == vx_core::t_string) { // default property
            ischanged = true;
            vx_p_text = vx_core::vx_any_from_any(vx_core::t_string, valsub);
          } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_core::t_string)) { // default property
            ischanged = true;
            vx_p_text = vx_core::vx_any_from_any(vx_core::t_string, valsub);
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h2) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (vx_p_id == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h2 :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":eventmap") {
            if (vx_p_eventmap == valsub) {
            } else if (valsubtype == vx_event::t_eventmap) {
              ischanged = true;
              vx_p_eventmap = vx_core::vx_any_from_any(vx_event::t_eventmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h2 :eventmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (vx_p_style == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h2 :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style-unique") {
            if (vx_p_style_unique == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style_unique = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h2 :style-unique " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":stylelist") {
            if (vx_p_stylelist == valsub) {
            } else if (valsubtype == vx_web_html::t_stylelist) {
              ischanged = true;
              vx_p_stylelist = vx_core::vx_any_from_any(vx_web_html::t_stylelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h2 :stylelist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":text") {
            if (vx_p_text == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_text = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h2 :text " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h2) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_h2();
        if (output->vx_p_id != vx_p_id) {
          if (output->vx_p_id) {
            vx_core::vx_release_one(output->vx_p_id);
          }
          output->vx_p_id = vx_p_id;
          vx_core::vx_reserve(vx_p_id);
        }
        if (output->vx_p_eventmap != vx_p_eventmap) {
          if (output->vx_p_eventmap) {
            vx_core::vx_release_one(output->vx_p_eventmap);
          }
          output->vx_p_eventmap = vx_p_eventmap;
          vx_core::vx_reserve(vx_p_eventmap);
        }
        if (output->vx_p_style != vx_p_style) {
          if (output->vx_p_style) {
            vx_core::vx_release_one(output->vx_p_style);
          }
          output->vx_p_style = vx_p_style;
          vx_core::vx_reserve(vx_p_style);
        }
        if (output->vx_p_style_unique != vx_p_style_unique) {
          if (output->vx_p_style_unique) {
            vx_core::vx_release_one(output->vx_p_style_unique);
          }
          output->vx_p_style_unique = vx_p_style_unique;
          vx_core::vx_reserve(vx_p_style_unique);
        }
        if (output->vx_p_stylelist != vx_p_stylelist) {
          if (output->vx_p_stylelist) {
            vx_core::vx_release_one(output->vx_p_stylelist);
          }
          output->vx_p_stylelist = vx_p_stylelist;
          vx_core::vx_reserve(vx_p_stylelist);
        }
        if (output->vx_p_text != vx_p_text) {
          if (output->vx_p_text) {
            vx_core::vx_release_one(output->vx_p_text);
          }
          output->vx_p_text = vx_p_text;
          vx_core::vx_reserve(vx_p_text);
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

    vx_core::Type_msgblock Class_h2::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_h2::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_h2::vx_empty() const {return vx_web_html::e_h2;}
    vx_core::Type_any Class_h2::vx_type() const {return vx_web_html::t_h2;}

    vx_core::Type_typedef Class_h2::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "h2", // name
        ":struct", // extends
        vx_core::vx_typelist_from_listany({vx_web_html::t_node, vx_web_html::t_divchild}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "text", // name
            vx_core::t_string // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_h2::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type h3)
  // class Class_h3 {
    Abstract_h3::~Abstract_h3() {}

    Class_h3::Class_h3() : Abstract_h3::Abstract_h3() {
      vx_core::refcount += 1;
    }

    Class_h3::~Class_h3() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_eventmap,
        this->vx_p_style,
        this->vx_p_style_unique,
        this->vx_p_stylelist,
        this->vx_p_text
      });
    }

    // id()
    vx_core::Type_string Class_h3::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // eventmap()
    vx_event::Type_eventmap Class_h3::eventmap() const {
      vx_event::Type_eventmap output = this->vx_p_eventmap;
      if (!output) {
        output = vx_event::e_eventmap;
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_h3::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // style_unique()
    vx_web_html::Type_style Class_h3::style_unique() const {
      vx_web_html::Type_style output = this->vx_p_style_unique;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // stylelist()
    vx_web_html::Type_stylelist Class_h3::stylelist() const {
      vx_web_html::Type_stylelist output = this->vx_p_stylelist;
      if (!output) {
        output = vx_web_html::e_stylelist;
      }
      return output;
    }

    // text()
    vx_core::Type_string Class_h3::text() const {
      vx_core::Type_string output = this->vx_p_text;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_h3::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":eventmap") {
        output = this->eventmap();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":style-unique") {
        output = this->style_unique();
      } else if (skey == ":stylelist") {
        output = this->stylelist();
      } else if (skey == ":text") {
        output = this->text();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_h3::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":eventmap"] = this->eventmap();
      output[":style"] = this->style();
      output[":style-unique"] = this->style_unique();
      output[":stylelist"] = this->stylelist();
      output[":text"] = this->text();
      return output;
    }

    vx_core::Type_any Class_h3::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_h3, vals);
    }

    vx_core::Type_any Class_h3::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_h3 output = vx_web_html::e_h3;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_h3 val = vx_core::vx_any_from_any(vx_web_html::t_h3, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_event::Type_eventmap vx_p_eventmap = val->eventmap();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_web_html::Type_style vx_p_style_unique = val->style_unique();
      vx_web_html::Type_stylelist vx_p_stylelist = val->stylelist();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":eventmap") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":style-unique") {
            key = testkey;
          } else if (testkey == ":stylelist") {
            key = testkey;
          } else if (testkey == ":text") {
            key = testkey;
          } else if (valsubtype == vx_core::t_string) { // default property
            ischanged = true;
            vx_p_text = vx_core::vx_any_from_any(vx_core::t_string, valsub);
          } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_core::t_string)) { // default property
            ischanged = true;
            vx_p_text = vx_core::vx_any_from_any(vx_core::t_string, valsub);
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h3) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (vx_p_id == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h3 :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":eventmap") {
            if (vx_p_eventmap == valsub) {
            } else if (valsubtype == vx_event::t_eventmap) {
              ischanged = true;
              vx_p_eventmap = vx_core::vx_any_from_any(vx_event::t_eventmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h3 :eventmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (vx_p_style == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h3 :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style-unique") {
            if (vx_p_style_unique == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style_unique = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h3 :style-unique " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":stylelist") {
            if (vx_p_stylelist == valsub) {
            } else if (valsubtype == vx_web_html::t_stylelist) {
              ischanged = true;
              vx_p_stylelist = vx_core::vx_any_from_any(vx_web_html::t_stylelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h3 :stylelist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":text") {
            if (vx_p_text == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_text = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h3 :text " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new h3) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_h3();
        if (output->vx_p_id != vx_p_id) {
          if (output->vx_p_id) {
            vx_core::vx_release_one(output->vx_p_id);
          }
          output->vx_p_id = vx_p_id;
          vx_core::vx_reserve(vx_p_id);
        }
        if (output->vx_p_eventmap != vx_p_eventmap) {
          if (output->vx_p_eventmap) {
            vx_core::vx_release_one(output->vx_p_eventmap);
          }
          output->vx_p_eventmap = vx_p_eventmap;
          vx_core::vx_reserve(vx_p_eventmap);
        }
        if (output->vx_p_style != vx_p_style) {
          if (output->vx_p_style) {
            vx_core::vx_release_one(output->vx_p_style);
          }
          output->vx_p_style = vx_p_style;
          vx_core::vx_reserve(vx_p_style);
        }
        if (output->vx_p_style_unique != vx_p_style_unique) {
          if (output->vx_p_style_unique) {
            vx_core::vx_release_one(output->vx_p_style_unique);
          }
          output->vx_p_style_unique = vx_p_style_unique;
          vx_core::vx_reserve(vx_p_style_unique);
        }
        if (output->vx_p_stylelist != vx_p_stylelist) {
          if (output->vx_p_stylelist) {
            vx_core::vx_release_one(output->vx_p_stylelist);
          }
          output->vx_p_stylelist = vx_p_stylelist;
          vx_core::vx_reserve(vx_p_stylelist);
        }
        if (output->vx_p_text != vx_p_text) {
          if (output->vx_p_text) {
            vx_core::vx_release_one(output->vx_p_text);
          }
          output->vx_p_text = vx_p_text;
          vx_core::vx_reserve(vx_p_text);
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

    vx_core::Type_msgblock Class_h3::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_h3::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_h3::vx_empty() const {return vx_web_html::e_h3;}
    vx_core::Type_any Class_h3::vx_type() const {return vx_web_html::t_h3;}

    vx_core::Type_typedef Class_h3::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "h3", // name
        ":struct", // extends
        vx_core::vx_typelist_from_listany({vx_web_html::t_node, vx_web_html::t_divchild}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "text", // name
            vx_core::t_string // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_h3::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type head)
  // class Class_head {
    Abstract_head::~Abstract_head() {}

    Class_head::Class_head() : Abstract_head::Abstract_head() {
      vx_core::refcount += 1;
    }

    Class_head::~Class_head() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_nodes
      });
    }

    // nodes()
    vx_web_html::Type_headchildlist Class_head::nodes() const {
      vx_web_html::Type_headchildlist output = this->vx_p_nodes;
      if (!output) {
        output = vx_web_html::e_headchildlist;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_head::vx_get_any(vx_core::Type_string key) const {
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
    vx_core::vx_Type_mapany Class_head::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":nodes"] = this->nodes();
      return output;
    }

    vx_core::Type_any Class_head::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_head, vals);
    }

    vx_core::Type_any Class_head::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_head output = vx_web_html::e_head;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_head val = vx_core::vx_any_from_any(vx_web_html::t_head, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_web_html::Type_headchildlist vx_p_nodes = val->nodes();
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
          } else if (valsubtype == vx_web_html::t_headchildlist) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_headchildlist, valsub);
          } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_headchildlist)) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_headchildlist, valsub);
          } else if (valsubtype == vx_web_html::t_headchild) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_copy(vx_p_nodes, {valsub});
          } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_headchild)) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_copy(vx_p_nodes, {valsub});
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new head) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":nodes") {
            if (vx_p_nodes == valsub) {
            } else if (valsubtype == vx_web_html::t_headchildlist) {
              ischanged = true;
              vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_headchildlist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new head :nodes " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new head) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_head();
        if (output->vx_p_nodes != vx_p_nodes) {
          if (output->vx_p_nodes) {
            vx_core::vx_release_one(output->vx_p_nodes);
          }
          output->vx_p_nodes = vx_p_nodes;
          vx_core::vx_reserve(vx_p_nodes);
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

    vx_core::Type_msgblock Class_head::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_head::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_head::vx_empty() const {return vx_web_html::e_head;}
    vx_core::Type_any Class_head::vx_type() const {return vx_web_html::t_head;}

    vx_core::Type_typedef Class_head::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "nodes", // name
            vx_web_html::t_headchildlist // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_head::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type headchild)
  // class Class_headchild {
    Abstract_headchild::~Abstract_headchild() {}

    Class_headchild::Class_headchild() : Abstract_headchild::Abstract_headchild() {
      vx_core::refcount += 1;
    }

    Class_headchild::~Class_headchild() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        
      });
    }

    // vx_get_any(key)
    vx_core::Type_any Class_headchild::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_headchild::vx_map() const {
      vx_core::vx_Type_mapany output;
      return output;
    }

    vx_core::Type_any Class_headchild::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_headchild, vals);
    }

    vx_core::Type_any Class_headchild::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_headchild output = vx_web_html::e_headchild;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_headchild val = vx_core::vx_any_from_any(vx_web_html::t_headchild, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      if (msgblock != vx_core::e_msgblock) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_headchild::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_headchild::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_headchild::vx_empty() const {return vx_web_html::e_headchild;}
    vx_core::Type_any Class_headchild::vx_type() const {return vx_web_html::t_headchild;}

    vx_core::Type_typedef Class_headchild::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
      return output;
    }

    vx_core::Type_constdef Class_headchild::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type headchildlist)
  // class Class_headchildlist {
    Abstract_headchildlist::~Abstract_headchildlist() {}

    Class_headchildlist::Class_headchildlist() : Abstract_headchildlist::Abstract_headchildlist() {
      vx_core::refcount += 1;
    }

    Class_headchildlist::~Class_headchildlist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_headchildlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_web_html::Type_headchild Class_headchildlist::vx_get_headchild(vx_core::Type_int index) const {
      vx_web_html::Type_headchild output = vx_web_html::e_headchild;
      long iindex = index->vx_int();
      std::vector<vx_web_html::Type_headchild> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_web_html::Type_headchild> Class_headchildlist::vx_listheadchild() const {return vx_p_list;}

    vx_core::Type_any vx_web_html::Class_headchildlist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_headchild(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_headchildlist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_web_html::Type_headchildlist output = vx_web_html::e_headchildlist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_web_html::Type_headchild> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_web_html::t_headchild) {
          vx_web_html::Type_headchild castval = vx_core::vx_any_from_any(vx_web_html::t_headchild, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_web_html::t_headchild)) {
          vx_web_html::Type_headchild castval = vx_core::vx_any_from_any(vx_web_html::t_headchild, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(headchildlist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_headchildlist();
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

    vx_core::Type_any Class_headchildlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_headchildlist, vals);
    }

    vx_core::Type_any Class_headchildlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_headchildlist output = vx_web_html::e_headchildlist;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_headchildlist val = vx_core::vx_any_from_any(vx_web_html::t_headchildlist, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_web_html::Type_headchild> listval = val->vx_listheadchild();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_web_html::t_headchild) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_web_html::t_headchild, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_headchild)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_web_html::t_headchild, valsub));
        } else if (valsubtype == vx_web_html::t_headchildlist) {
          ischanged = true;
          vx_web_html::Type_headchildlist multi = vx_core::vx_any_from_any(vx_web_html::t_headchildlist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listheadchild());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new headchildlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_headchildlist();
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

    vx_core::Type_msgblock Class_headchildlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_headchildlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_headchildlist::vx_empty() const {return vx_web_html::e_headchildlist;}
    vx_core::Type_any Class_headchildlist::vx_type() const {return vx_web_html::t_headchildlist;}

    vx_core::Type_typedef Class_headchildlist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "headchildlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_web_html::t_headchild}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_headchildlist::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type html)
  // class Class_html {
    Abstract_html::~Abstract_html() {}

    Class_html::Class_html() : Abstract_html::Abstract_html() {
      vx_core::refcount += 1;
    }

    Class_html::~Class_html() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_lang,
        this->vx_p_head,
        this->vx_p_body,
        this->vx_p_footer
      });
    }

    // lang()
    vx_core::Type_string Class_html::lang() const {
      vx_core::Type_string output = this->vx_p_lang;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // head()
    vx_web_html::Type_head Class_html::head() const {
      vx_web_html::Type_head output = this->vx_p_head;
      if (!output) {
        output = vx_web_html::e_head;
      }
      return output;
    }

    // body()
    vx_web_html::Type_body Class_html::body() const {
      vx_web_html::Type_body output = this->vx_p_body;
      if (!output) {
        output = vx_web_html::e_body;
      }
      return output;
    }

    // footer()
    vx_web_html::Type_footer Class_html::footer() const {
      vx_web_html::Type_footer output = this->vx_p_footer;
      if (!output) {
        output = vx_web_html::e_footer;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_html::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
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
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_html::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":lang"] = this->lang();
      output[":head"] = this->head();
      output[":body"] = this->body();
      output[":footer"] = this->footer();
      return output;
    }

    vx_core::Type_any Class_html::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_html, vals);
    }

    vx_core::Type_any Class_html::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_html output = vx_web_html::e_html;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_html val = vx_core::vx_any_from_any(vx_web_html::t_html, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_lang = val->lang();
      vx_web_html::Type_head vx_p_head = val->head();
      vx_web_html::Type_body vx_p_body = val->body();
      vx_web_html::Type_footer vx_p_footer = val->footer();
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
          } else if (testkey == ":lang") {
            key = testkey;
          } else if (testkey == ":head") {
            key = testkey;
          } else if (testkey == ":body") {
            key = testkey;
          } else if (testkey == ":footer") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new html) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":lang") {
            if (vx_p_lang == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_lang = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new html :lang " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":head") {
            if (vx_p_head == valsub) {
            } else if (valsubtype == vx_web_html::t_head) {
              ischanged = true;
              vx_p_head = vx_core::vx_any_from_any(vx_web_html::t_head, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new html :head " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":body") {
            if (vx_p_body == valsub) {
            } else if (valsubtype == vx_web_html::t_body) {
              ischanged = true;
              vx_p_body = vx_core::vx_any_from_any(vx_web_html::t_body, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new html :body " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":footer") {
            if (vx_p_footer == valsub) {
            } else if (valsubtype == vx_web_html::t_footer) {
              ischanged = true;
              vx_p_footer = vx_core::vx_any_from_any(vx_web_html::t_footer, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new html :footer " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new html) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_html();
        if (output->vx_p_lang != vx_p_lang) {
          if (output->vx_p_lang) {
            vx_core::vx_release_one(output->vx_p_lang);
          }
          output->vx_p_lang = vx_p_lang;
          vx_core::vx_reserve(vx_p_lang);
        }
        if (output->vx_p_head != vx_p_head) {
          if (output->vx_p_head) {
            vx_core::vx_release_one(output->vx_p_head);
          }
          output->vx_p_head = vx_p_head;
          vx_core::vx_reserve(vx_p_head);
        }
        if (output->vx_p_body != vx_p_body) {
          if (output->vx_p_body) {
            vx_core::vx_release_one(output->vx_p_body);
          }
          output->vx_p_body = vx_p_body;
          vx_core::vx_reserve(vx_p_body);
        }
        if (output->vx_p_footer != vx_p_footer) {
          if (output->vx_p_footer) {
            vx_core::vx_release_one(output->vx_p_footer);
          }
          output->vx_p_footer = vx_p_footer;
          vx_core::vx_reserve(vx_p_footer);
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

    vx_core::Type_msgblock Class_html::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_html::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_html::vx_empty() const {return vx_web_html::e_html;}
    vx_core::Type_any Class_html::vx_type() const {return vx_web_html::t_html;}

    vx_core::Type_typedef Class_html::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "lang", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "head", // name
            vx_web_html::t_head // type
          ),
          vx_core::vx_new_arg(
            "body", // name
            vx_web_html::t_body // type
          ),
          vx_core::vx_new_arg(
            "footer", // name
            vx_web_html::t_footer // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_html::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type meta)
  // class Class_meta {
    Abstract_meta::~Abstract_meta() {}

    Class_meta::Class_meta() : Abstract_meta::Abstract_meta() {
      vx_core::refcount += 1;
    }

    Class_meta::~Class_meta() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_eventmap,
        this->vx_p_style,
        this->vx_p_style_unique,
        this->vx_p_stylelist,
        this->vx_p_charset,
        this->vx_p_name,
        this->vx_p_content
      });
    }

    // id()
    vx_core::Type_string Class_meta::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // eventmap()
    vx_event::Type_eventmap Class_meta::eventmap() const {
      vx_event::Type_eventmap output = this->vx_p_eventmap;
      if (!output) {
        output = vx_event::e_eventmap;
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_meta::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // style_unique()
    vx_web_html::Type_style Class_meta::style_unique() const {
      vx_web_html::Type_style output = this->vx_p_style_unique;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // stylelist()
    vx_web_html::Type_stylelist Class_meta::stylelist() const {
      vx_web_html::Type_stylelist output = this->vx_p_stylelist;
      if (!output) {
        output = vx_web_html::e_stylelist;
      }
      return output;
    }

    // charset()
    vx_core::Type_string Class_meta::charset() const {
      vx_core::Type_string output = this->vx_p_charset;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // name()
    vx_core::Type_string Class_meta::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // content()
    vx_core::Type_string Class_meta::content() const {
      vx_core::Type_string output = this->vx_p_content;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_meta::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":eventmap") {
        output = this->eventmap();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":style-unique") {
        output = this->style_unique();
      } else if (skey == ":stylelist") {
        output = this->stylelist();
      } else if (skey == ":charset") {
        output = this->charset();
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":content") {
        output = this->content();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_meta::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":eventmap"] = this->eventmap();
      output[":style"] = this->style();
      output[":style-unique"] = this->style_unique();
      output[":stylelist"] = this->stylelist();
      output[":charset"] = this->charset();
      output[":name"] = this->name();
      output[":content"] = this->content();
      return output;
    }

    vx_core::Type_any Class_meta::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_meta, vals);
    }

    vx_core::Type_any Class_meta::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_meta output = vx_web_html::e_meta;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_meta val = vx_core::vx_any_from_any(vx_web_html::t_meta, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_event::Type_eventmap vx_p_eventmap = val->eventmap();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_web_html::Type_style vx_p_style_unique = val->style_unique();
      vx_web_html::Type_stylelist vx_p_stylelist = val->stylelist();
      vx_core::Type_string vx_p_charset = val->charset();
      vx_core::Type_string vx_p_name = val->name();
      vx_core::Type_string vx_p_content = val->content();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":eventmap") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":style-unique") {
            key = testkey;
          } else if (testkey == ":stylelist") {
            key = testkey;
          } else if (testkey == ":charset") {
            key = testkey;
          } else if (testkey == ":name") {
            key = testkey;
          } else if (testkey == ":content") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new meta) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (vx_p_id == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new meta :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":eventmap") {
            if (vx_p_eventmap == valsub) {
            } else if (valsubtype == vx_event::t_eventmap) {
              ischanged = true;
              vx_p_eventmap = vx_core::vx_any_from_any(vx_event::t_eventmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new meta :eventmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (vx_p_style == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new meta :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style-unique") {
            if (vx_p_style_unique == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style_unique = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new meta :style-unique " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":stylelist") {
            if (vx_p_stylelist == valsub) {
            } else if (valsubtype == vx_web_html::t_stylelist) {
              ischanged = true;
              vx_p_stylelist = vx_core::vx_any_from_any(vx_web_html::t_stylelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new meta :stylelist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":charset") {
            if (vx_p_charset == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_charset = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new meta :charset " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":name") {
            if (vx_p_name == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new meta :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":content") {
            if (vx_p_content == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_content = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new meta :content " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new meta) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_meta();
        if (output->vx_p_id != vx_p_id) {
          if (output->vx_p_id) {
            vx_core::vx_release_one(output->vx_p_id);
          }
          output->vx_p_id = vx_p_id;
          vx_core::vx_reserve(vx_p_id);
        }
        if (output->vx_p_eventmap != vx_p_eventmap) {
          if (output->vx_p_eventmap) {
            vx_core::vx_release_one(output->vx_p_eventmap);
          }
          output->vx_p_eventmap = vx_p_eventmap;
          vx_core::vx_reserve(vx_p_eventmap);
        }
        if (output->vx_p_style != vx_p_style) {
          if (output->vx_p_style) {
            vx_core::vx_release_one(output->vx_p_style);
          }
          output->vx_p_style = vx_p_style;
          vx_core::vx_reserve(vx_p_style);
        }
        if (output->vx_p_style_unique != vx_p_style_unique) {
          if (output->vx_p_style_unique) {
            vx_core::vx_release_one(output->vx_p_style_unique);
          }
          output->vx_p_style_unique = vx_p_style_unique;
          vx_core::vx_reserve(vx_p_style_unique);
        }
        if (output->vx_p_stylelist != vx_p_stylelist) {
          if (output->vx_p_stylelist) {
            vx_core::vx_release_one(output->vx_p_stylelist);
          }
          output->vx_p_stylelist = vx_p_stylelist;
          vx_core::vx_reserve(vx_p_stylelist);
        }
        if (output->vx_p_charset != vx_p_charset) {
          if (output->vx_p_charset) {
            vx_core::vx_release_one(output->vx_p_charset);
          }
          output->vx_p_charset = vx_p_charset;
          vx_core::vx_reserve(vx_p_charset);
        }
        if (output->vx_p_name != vx_p_name) {
          if (output->vx_p_name) {
            vx_core::vx_release_one(output->vx_p_name);
          }
          output->vx_p_name = vx_p_name;
          vx_core::vx_reserve(vx_p_name);
        }
        if (output->vx_p_content != vx_p_content) {
          if (output->vx_p_content) {
            vx_core::vx_release_one(output->vx_p_content);
          }
          output->vx_p_content = vx_p_content;
          vx_core::vx_reserve(vx_p_content);
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

    vx_core::Type_msgblock Class_meta::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_meta::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_meta::vx_empty() const {return vx_web_html::e_meta;}
    vx_core::Type_any Class_meta::vx_type() const {return vx_web_html::t_meta;}

    vx_core::Type_typedef Class_meta::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "meta", // name
        ":struct", // extends
        vx_core::vx_typelist_from_listany({vx_web_html::t_node, vx_web_html::t_headchild}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "charset", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "name", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "content", // name
            vx_core::t_string // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_meta::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type nodelist)
  // class Class_nodelist {
    Abstract_nodelist::~Abstract_nodelist() {}

    Class_nodelist::Class_nodelist() : Abstract_nodelist::Abstract_nodelist() {
      vx_core::refcount += 1;
    }

    Class_nodelist::~Class_nodelist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_nodelist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_web_html::Type_node Class_nodelist::vx_get_node(vx_core::Type_int index) const {
      vx_web_html::Type_node output = vx_web_html::e_node;
      long iindex = index->vx_int();
      std::vector<vx_web_html::Type_node> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_web_html::Type_node> Class_nodelist::vx_listnode() const {return vx_p_list;}

    vx_core::Type_any vx_web_html::Class_nodelist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_node(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_nodelist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_web_html::Type_nodelist output = vx_web_html::e_nodelist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_web_html::Type_node> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_web_html::t_node) {
          vx_web_html::Type_node castval = vx_core::vx_any_from_any(vx_web_html::t_node, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_web_html::t_node)) {
          vx_web_html::Type_node castval = vx_core::vx_any_from_any(vx_web_html::t_node, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(nodelist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_nodelist();
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

    vx_core::Type_any Class_nodelist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_nodelist, vals);
    }

    vx_core::Type_any Class_nodelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_nodelist output = vx_web_html::e_nodelist;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_nodelist val = vx_core::vx_any_from_any(vx_web_html::t_nodelist, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_web_html::Type_node> listval = val->vx_listnode();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_web_html::t_node) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_web_html::t_node, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_node)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_web_html::t_node, valsub));
        } else if (valsubtype == vx_web_html::t_nodelist) {
          ischanged = true;
          vx_web_html::Type_nodelist multi = vx_core::vx_any_from_any(vx_web_html::t_nodelist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listnode());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new nodelist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_nodelist();
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

    vx_core::Type_msgblock Class_nodelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_nodelist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_nodelist::vx_empty() const {return vx_web_html::e_nodelist;}
    vx_core::Type_any Class_nodelist::vx_type() const {return vx_web_html::t_nodelist;}

    vx_core::Type_typedef Class_nodelist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "nodelist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_web_html::t_node}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_nodelist::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type p)
  // class Class_p {
    Abstract_p::~Abstract_p() {}

    Class_p::Class_p() : Abstract_p::Abstract_p() {
      vx_core::refcount += 1;
    }

    Class_p::~Class_p() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_eventmap,
        this->vx_p_style,
        this->vx_p_style_unique,
        this->vx_p_stylelist,
        this->vx_p_text
      });
    }

    // id()
    vx_core::Type_string Class_p::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // eventmap()
    vx_event::Type_eventmap Class_p::eventmap() const {
      vx_event::Type_eventmap output = this->vx_p_eventmap;
      if (!output) {
        output = vx_event::e_eventmap;
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_p::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // style_unique()
    vx_web_html::Type_style Class_p::style_unique() const {
      vx_web_html::Type_style output = this->vx_p_style_unique;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // stylelist()
    vx_web_html::Type_stylelist Class_p::stylelist() const {
      vx_web_html::Type_stylelist output = this->vx_p_stylelist;
      if (!output) {
        output = vx_web_html::e_stylelist;
      }
      return output;
    }

    // text()
    vx_core::Type_string Class_p::text() const {
      vx_core::Type_string output = this->vx_p_text;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_p::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":eventmap") {
        output = this->eventmap();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":style-unique") {
        output = this->style_unique();
      } else if (skey == ":stylelist") {
        output = this->stylelist();
      } else if (skey == ":text") {
        output = this->text();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_p::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":eventmap"] = this->eventmap();
      output[":style"] = this->style();
      output[":style-unique"] = this->style_unique();
      output[":stylelist"] = this->stylelist();
      output[":text"] = this->text();
      return output;
    }

    vx_core::Type_any Class_p::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_p, vals);
    }

    vx_core::Type_any Class_p::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_p output = vx_web_html::e_p;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_p val = vx_core::vx_any_from_any(vx_web_html::t_p, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_event::Type_eventmap vx_p_eventmap = val->eventmap();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_web_html::Type_style vx_p_style_unique = val->style_unique();
      vx_web_html::Type_stylelist vx_p_stylelist = val->stylelist();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":eventmap") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":style-unique") {
            key = testkey;
          } else if (testkey == ":stylelist") {
            key = testkey;
          } else if (testkey == ":text") {
            key = testkey;
          } else if (valsubtype == vx_core::t_string) { // default property
            ischanged = true;
            vx_p_text = vx_core::vx_any_from_any(vx_core::t_string, valsub);
          } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_core::t_string)) { // default property
            ischanged = true;
            vx_p_text = vx_core::vx_any_from_any(vx_core::t_string, valsub);
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new p) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (vx_p_id == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new p :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":eventmap") {
            if (vx_p_eventmap == valsub) {
            } else if (valsubtype == vx_event::t_eventmap) {
              ischanged = true;
              vx_p_eventmap = vx_core::vx_any_from_any(vx_event::t_eventmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new p :eventmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (vx_p_style == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new p :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style-unique") {
            if (vx_p_style_unique == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style_unique = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new p :style-unique " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":stylelist") {
            if (vx_p_stylelist == valsub) {
            } else if (valsubtype == vx_web_html::t_stylelist) {
              ischanged = true;
              vx_p_stylelist = vx_core::vx_any_from_any(vx_web_html::t_stylelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new p :stylelist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":text") {
            if (vx_p_text == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_text = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new p :text " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new p) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_p();
        if (output->vx_p_id != vx_p_id) {
          if (output->vx_p_id) {
            vx_core::vx_release_one(output->vx_p_id);
          }
          output->vx_p_id = vx_p_id;
          vx_core::vx_reserve(vx_p_id);
        }
        if (output->vx_p_eventmap != vx_p_eventmap) {
          if (output->vx_p_eventmap) {
            vx_core::vx_release_one(output->vx_p_eventmap);
          }
          output->vx_p_eventmap = vx_p_eventmap;
          vx_core::vx_reserve(vx_p_eventmap);
        }
        if (output->vx_p_style != vx_p_style) {
          if (output->vx_p_style) {
            vx_core::vx_release_one(output->vx_p_style);
          }
          output->vx_p_style = vx_p_style;
          vx_core::vx_reserve(vx_p_style);
        }
        if (output->vx_p_style_unique != vx_p_style_unique) {
          if (output->vx_p_style_unique) {
            vx_core::vx_release_one(output->vx_p_style_unique);
          }
          output->vx_p_style_unique = vx_p_style_unique;
          vx_core::vx_reserve(vx_p_style_unique);
        }
        if (output->vx_p_stylelist != vx_p_stylelist) {
          if (output->vx_p_stylelist) {
            vx_core::vx_release_one(output->vx_p_stylelist);
          }
          output->vx_p_stylelist = vx_p_stylelist;
          vx_core::vx_reserve(vx_p_stylelist);
        }
        if (output->vx_p_text != vx_p_text) {
          if (output->vx_p_text) {
            vx_core::vx_release_one(output->vx_p_text);
          }
          output->vx_p_text = vx_p_text;
          vx_core::vx_reserve(vx_p_text);
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

    vx_core::Type_msgblock Class_p::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_p::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_p::vx_empty() const {return vx_web_html::e_p;}
    vx_core::Type_any Class_p::vx_type() const {return vx_web_html::t_p;}

    vx_core::Type_typedef Class_p::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "p", // name
        ":struct", // extends
        vx_core::vx_typelist_from_listany({vx_web_html::t_node, vx_web_html::t_divchild}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "text", // name
            vx_core::t_string // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_p::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type propmap)
  // class Class_propmap {
    Abstract_propmap::~Abstract_propmap() {}

    Class_propmap::Class_propmap() : Abstract_propmap::Abstract_propmap() {
      vx_core::refcount += 1;
    }

    Class_propmap::~Class_propmap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (auto const& [key, val] : this->vx_p_map) {
        vx_core::vx_release_one(val);
      }
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_propmap::vx_map() const {
      vx_core::vx_Type_mapany output = vx_core::vx_map_from_map(vx_core::t_any, this->vx_p_map);
      return output;
    }

    // vx_get_string(key)
    vx_core::Type_string Class_propmap::vx_get_string(vx_core::Type_string key) const {
      vx_core::Type_string output = vx_core::e_string;
      const vx_web_html::Class_propmap* map = this;
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
    vx_core::Type_any Class_propmap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_string(key);
    }

    // vx_mapstring()
    std::map<std::string, vx_core::Type_string> Class_propmap::vx_mapstring() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_propmap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_web_html::Type_propmap output = vx_web_html::e_propmap;
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
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(propmap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((map.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_propmap();
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

    vx_core::Type_any Class_propmap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_propmap, vals);
    }

    vx_core::Type_any Class_propmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_propmap output = vx_web_html::e_propmap;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_propmap valmap = vx_core::vx_any_from_any(vx_web_html::t_propmap, copyval);
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
        output = new vx_web_html::Class_propmap();
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

    vx_core::Type_msgblock Class_propmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_propmap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_propmap::vx_empty() const {return vx_web_html::e_propmap;}
    vx_core::Type_any Class_propmap::vx_type() const {return vx_web_html::t_propmap;}

    vx_core::Type_typedef Class_propmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "propmap", // name
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

    vx_core::Type_constdef Class_propmap::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type style)
  // class Class_style {
    Abstract_style::~Abstract_style() {}

    Class_style::Class_style() : Abstract_style::Abstract_style() {
      vx_core::refcount += 1;
    }

    Class_style::~Class_style() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_name,
        this->vx_p_props,
        this->vx_p_subprops
      });
    }

    // name()
    vx_core::Type_string Class_style::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // props()
    vx_web_html::Type_propmap Class_style::props() const {
      vx_web_html::Type_propmap output = this->vx_p_props;
      if (!output) {
        output = vx_web_html::e_propmap;
      }
      return output;
    }

    // subprops()
    vx_web_html::Type_subpropmap Class_style::subprops() const {
      vx_web_html::Type_subpropmap output = this->vx_p_subprops;
      if (!output) {
        output = vx_web_html::e_subpropmap;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_style::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":props") {
        output = this->props();
      } else if (skey == ":subprops") {
        output = this->subprops();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_style::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":name"] = this->name();
      output[":props"] = this->props();
      output[":subprops"] = this->subprops();
      return output;
    }

    vx_core::Type_any Class_style::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_style, vals);
    }

    vx_core::Type_any Class_style::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_style output = vx_web_html::e_style;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_style val = vx_core::vx_any_from_any(vx_web_html::t_style, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_name = val->name();
      vx_web_html::Type_propmap vx_p_props = val->props();
      vx_web_html::Type_subpropmap vx_p_subprops = val->subprops();
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
          } else if (testkey == ":props") {
            key = testkey;
          } else if (testkey == ":subprops") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new style) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":name") {
            if (vx_p_name == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new style :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":props") {
            if (vx_p_props == valsub) {
            } else if (valsubtype == vx_web_html::t_propmap) {
              ischanged = true;
              vx_p_props = vx_core::vx_any_from_any(vx_web_html::t_propmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new style :props " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":subprops") {
            if (vx_p_subprops == valsub) {
            } else if (valsubtype == vx_web_html::t_subpropmap) {
              ischanged = true;
              vx_p_subprops = vx_core::vx_any_from_any(vx_web_html::t_subpropmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new style :subprops " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new style) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_style();
        if (output->vx_p_name != vx_p_name) {
          if (output->vx_p_name) {
            vx_core::vx_release_one(output->vx_p_name);
          }
          output->vx_p_name = vx_p_name;
          vx_core::vx_reserve(vx_p_name);
        }
        if (output->vx_p_props != vx_p_props) {
          if (output->vx_p_props) {
            vx_core::vx_release_one(output->vx_p_props);
          }
          output->vx_p_props = vx_p_props;
          vx_core::vx_reserve(vx_p_props);
        }
        if (output->vx_p_subprops != vx_p_subprops) {
          if (output->vx_p_subprops) {
            vx_core::vx_release_one(output->vx_p_subprops);
          }
          output->vx_p_subprops = vx_p_subprops;
          vx_core::vx_reserve(vx_p_subprops);
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

    vx_core::Type_msgblock Class_style::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_style::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_style::vx_empty() const {return vx_web_html::e_style;}
    vx_core::Type_any Class_style::vx_type() const {return vx_web_html::t_style;}

    vx_core::Type_typedef Class_style::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
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
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "name", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "props", // name
            vx_web_html::t_propmap // type
          ),
          vx_core::vx_new_arg(
            "subprops", // name
            vx_web_html::t_subpropmap // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_style::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type stylelist)
  // class Class_stylelist {
    Abstract_stylelist::~Abstract_stylelist() {}

    Class_stylelist::Class_stylelist() : Abstract_stylelist::Abstract_stylelist() {
      vx_core::refcount += 1;
    }

    Class_stylelist::~Class_stylelist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_stylelist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_web_html::Type_style Class_stylelist::vx_get_style(vx_core::Type_int index) const {
      vx_web_html::Type_style output = vx_web_html::e_style;
      long iindex = index->vx_int();
      std::vector<vx_web_html::Type_style> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_web_html::Type_style> Class_stylelist::vx_liststyle() const {return vx_p_list;}

    vx_core::Type_any vx_web_html::Class_stylelist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_style(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_stylelist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_web_html::Type_stylelist output = vx_web_html::e_stylelist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_web_html::Type_style> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_web_html::t_style) {
          vx_web_html::Type_style castval = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_web_html::t_style)) {
          vx_web_html::Type_style castval = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(stylelist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_stylelist();
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

    vx_core::Type_any Class_stylelist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_stylelist, vals);
    }

    vx_core::Type_any Class_stylelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_stylelist output = vx_web_html::e_stylelist;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_stylelist val = vx_core::vx_any_from_any(vx_web_html::t_stylelist, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_web_html::Type_style> listval = val->vx_liststyle();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_web_html::t_style) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_web_html::t_style, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_style)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_web_html::t_style, valsub));
        } else if (valsubtype == vx_web_html::t_stylelist) {
          ischanged = true;
          vx_web_html::Type_stylelist multi = vx_core::vx_any_from_any(vx_web_html::t_stylelist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_liststyle());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new stylelist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_stylelist();
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

    vx_core::Type_msgblock Class_stylelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_stylelist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_stylelist::vx_empty() const {return vx_web_html::e_stylelist;}
    vx_core::Type_any Class_stylelist::vx_type() const {return vx_web_html::t_stylelist;}

    vx_core::Type_typedef Class_stylelist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "stylelist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_web_html::t_style}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_stylelist::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type stylemap)
  // class Class_stylemap {
    Abstract_stylemap::~Abstract_stylemap() {}

    Class_stylemap::Class_stylemap() : Abstract_stylemap::Abstract_stylemap() {
      vx_core::refcount += 1;
    }

    Class_stylemap::~Class_stylemap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (auto const& [key, val] : this->vx_p_map) {
        vx_core::vx_release_one(val);
      }
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_stylemap::vx_map() const {
      vx_core::vx_Type_mapany output = vx_core::vx_map_from_map(vx_core::t_any, this->vx_p_map);
      return output;
    }

    // vx_get_style(key)
    vx_web_html::Type_style Class_stylemap::vx_get_style(vx_core::Type_string key) const {
      vx_web_html::Type_style output = vx_web_html::e_style;
      const vx_web_html::Class_stylemap* map = this;
      std::string skey = key->vx_string();
      if (vx_core::vx_boolean_from_string_starts(skey, ":")) {
        skey = vx_core::vx_string_from_string_start(skey, 2);
      }
      std::map<std::string, vx_web_html::Type_style> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_web_html::e_style);
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_stylemap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_style(key);
    }

    // vx_mapstyle()
    std::map<std::string, vx_web_html::Type_style> Class_stylemap::vx_mapstyle() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_stylemap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_web_html::Type_stylemap output = vx_web_html::e_stylemap;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_web_html::Type_style> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_web_html::t_style) {
          vx_web_html::Type_style castval = vx_core::vx_any_from_any(vx_web_html::t_style, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(stylemap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((map.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_stylemap();
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

    vx_core::Type_any Class_stylemap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_stylemap, vals);
    }

    vx_core::Type_any Class_stylemap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_stylemap output = vx_web_html::e_stylemap;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_stylemap valmap = vx_core::vx_any_from_any(vx_web_html::t_stylemap, copyval);
      output = valmap;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_web_html::Type_style> mapval = valmap->vx_mapstyle();
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
          vx_web_html::Type_style valany = NULL;
          if (valsubtype == vx_web_html::t_style) {
            valany = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
          } else if (valsubtype == vx_web_html::t_style) {
            valany = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
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
        output = new vx_web_html::Class_stylemap();
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

    vx_core::Type_msgblock Class_stylemap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_stylemap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_stylemap::vx_empty() const {return vx_web_html::e_stylemap;}
    vx_core::Type_any Class_stylemap::vx_type() const {return vx_web_html::t_stylemap;}

    vx_core::Type_typedef Class_stylemap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "stylemap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_web_html::t_style}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_stylemap::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type stylesheet)
  // class Class_stylesheet {
    Abstract_stylesheet::~Abstract_stylesheet() {}

    Class_stylesheet::Class_stylesheet() : Abstract_stylesheet::Abstract_stylesheet() {
      vx_core::refcount += 1;
    }

    Class_stylesheet::~Class_stylesheet() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_eventmap,
        this->vx_p_style,
        this->vx_p_style_unique,
        this->vx_p_stylelist,
        this->vx_p_name,
        this->vx_p_styles,
        this->vx_p_stylemap
      });
    }

    // id()
    vx_core::Type_string Class_stylesheet::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // eventmap()
    vx_event::Type_eventmap Class_stylesheet::eventmap() const {
      vx_event::Type_eventmap output = this->vx_p_eventmap;
      if (!output) {
        output = vx_event::e_eventmap;
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_stylesheet::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // style_unique()
    vx_web_html::Type_style Class_stylesheet::style_unique() const {
      vx_web_html::Type_style output = this->vx_p_style_unique;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // stylelist()
    vx_web_html::Type_stylelist Class_stylesheet::stylelist() const {
      vx_web_html::Type_stylelist output = this->vx_p_stylelist;
      if (!output) {
        output = vx_web_html::e_stylelist;
      }
      return output;
    }

    // name()
    vx_core::Type_string Class_stylesheet::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // styles()
    vx_web_html::Type_stylelist Class_stylesheet::styles() const {
      vx_web_html::Type_stylelist output = this->vx_p_styles;
      if (!output) {
        output = vx_web_html::e_stylelist;
      }
      return output;
    }

    // stylemap()
    vx_web_html::Type_stylemap Class_stylesheet::stylemap() const {
      vx_web_html::Type_stylemap output = this->vx_p_stylemap;
      if (!output) {
        output = vx_web_html::e_stylemap;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_stylesheet::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":eventmap") {
        output = this->eventmap();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":style-unique") {
        output = this->style_unique();
      } else if (skey == ":stylelist") {
        output = this->stylelist();
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":styles") {
        output = this->styles();
      } else if (skey == ":stylemap") {
        output = this->stylemap();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_stylesheet::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":eventmap"] = this->eventmap();
      output[":style"] = this->style();
      output[":style-unique"] = this->style_unique();
      output[":stylelist"] = this->stylelist();
      output[":name"] = this->name();
      output[":styles"] = this->styles();
      output[":stylemap"] = this->stylemap();
      return output;
    }

    vx_core::Type_any Class_stylesheet::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_stylesheet, vals);
    }

    vx_core::Type_any Class_stylesheet::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_stylesheet output = vx_web_html::e_stylesheet;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_stylesheet val = vx_core::vx_any_from_any(vx_web_html::t_stylesheet, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_event::Type_eventmap vx_p_eventmap = val->eventmap();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_web_html::Type_style vx_p_style_unique = val->style_unique();
      vx_web_html::Type_stylelist vx_p_stylelist = val->stylelist();
      vx_core::Type_string vx_p_name = val->name();
      vx_web_html::Type_stylelist vx_p_styles = val->styles();
      vx_web_html::Type_stylemap vx_p_stylemap = val->stylemap();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":eventmap") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":style-unique") {
            key = testkey;
          } else if (testkey == ":stylelist") {
            key = testkey;
          } else if (testkey == ":name") {
            key = testkey;
          } else if (testkey == ":styles") {
            key = testkey;
          } else if (testkey == ":stylemap") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new stylesheet) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (vx_p_id == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new stylesheet :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":eventmap") {
            if (vx_p_eventmap == valsub) {
            } else if (valsubtype == vx_event::t_eventmap) {
              ischanged = true;
              vx_p_eventmap = vx_core::vx_any_from_any(vx_event::t_eventmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new stylesheet :eventmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (vx_p_style == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new stylesheet :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style-unique") {
            if (vx_p_style_unique == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style_unique = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new stylesheet :style-unique " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":stylelist") {
            if (vx_p_stylelist == valsub) {
            } else if (valsubtype == vx_web_html::t_stylelist) {
              ischanged = true;
              vx_p_stylelist = vx_core::vx_any_from_any(vx_web_html::t_stylelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new stylesheet :stylelist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":name") {
            if (vx_p_name == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new stylesheet :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":styles") {
            if (vx_p_styles == valsub) {
            } else if (valsubtype == vx_web_html::t_stylelist) {
              ischanged = true;
              vx_p_styles = vx_core::vx_any_from_any(vx_web_html::t_stylelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new stylesheet :styles " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":stylemap") {
            if (vx_p_stylemap == valsub) {
            } else if (valsubtype == vx_web_html::t_stylemap) {
              ischanged = true;
              vx_p_stylemap = vx_core::vx_any_from_any(vx_web_html::t_stylemap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new stylesheet :stylemap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new stylesheet) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_stylesheet();
        if (output->vx_p_id != vx_p_id) {
          if (output->vx_p_id) {
            vx_core::vx_release_one(output->vx_p_id);
          }
          output->vx_p_id = vx_p_id;
          vx_core::vx_reserve(vx_p_id);
        }
        if (output->vx_p_eventmap != vx_p_eventmap) {
          if (output->vx_p_eventmap) {
            vx_core::vx_release_one(output->vx_p_eventmap);
          }
          output->vx_p_eventmap = vx_p_eventmap;
          vx_core::vx_reserve(vx_p_eventmap);
        }
        if (output->vx_p_style != vx_p_style) {
          if (output->vx_p_style) {
            vx_core::vx_release_one(output->vx_p_style);
          }
          output->vx_p_style = vx_p_style;
          vx_core::vx_reserve(vx_p_style);
        }
        if (output->vx_p_style_unique != vx_p_style_unique) {
          if (output->vx_p_style_unique) {
            vx_core::vx_release_one(output->vx_p_style_unique);
          }
          output->vx_p_style_unique = vx_p_style_unique;
          vx_core::vx_reserve(vx_p_style_unique);
        }
        if (output->vx_p_stylelist != vx_p_stylelist) {
          if (output->vx_p_stylelist) {
            vx_core::vx_release_one(output->vx_p_stylelist);
          }
          output->vx_p_stylelist = vx_p_stylelist;
          vx_core::vx_reserve(vx_p_stylelist);
        }
        if (output->vx_p_name != vx_p_name) {
          if (output->vx_p_name) {
            vx_core::vx_release_one(output->vx_p_name);
          }
          output->vx_p_name = vx_p_name;
          vx_core::vx_reserve(vx_p_name);
        }
        if (output->vx_p_styles != vx_p_styles) {
          if (output->vx_p_styles) {
            vx_core::vx_release_one(output->vx_p_styles);
          }
          output->vx_p_styles = vx_p_styles;
          vx_core::vx_reserve(vx_p_styles);
        }
        if (output->vx_p_stylemap != vx_p_stylemap) {
          if (output->vx_p_stylemap) {
            vx_core::vx_release_one(output->vx_p_stylemap);
          }
          output->vx_p_stylemap = vx_p_stylemap;
          vx_core::vx_reserve(vx_p_stylemap);
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

    vx_core::Type_msgblock Class_stylesheet::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_stylesheet::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_stylesheet::vx_empty() const {return vx_web_html::e_stylesheet;}
    vx_core::Type_any Class_stylesheet::vx_type() const {return vx_web_html::t_stylesheet;}

    vx_core::Type_typedef Class_stylesheet::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "stylesheet", // name
        ":struct", // extends
        vx_core::vx_typelist_from_listany({vx_web_html::t_node, vx_web_html::t_headchild}), // traits
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
            "styles", // name
            vx_web_html::t_stylelist // type
          ),
          vx_core::vx_new_arg(
            "stylemap", // name
            vx_web_html::t_stylemap // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_stylesheet::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type subpropmap)
  // class Class_subpropmap {
    Abstract_subpropmap::~Abstract_subpropmap() {}

    Class_subpropmap::Class_subpropmap() : Abstract_subpropmap::Abstract_subpropmap() {
      vx_core::refcount += 1;
    }

    Class_subpropmap::~Class_subpropmap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (auto const& [key, val] : this->vx_p_map) {
        vx_core::vx_release_one(val);
      }
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_subpropmap::vx_map() const {
      vx_core::vx_Type_mapany output = vx_core::vx_map_from_map(vx_core::t_any, this->vx_p_map);
      return output;
    }

    // vx_get_propmap(key)
    vx_web_html::Type_propmap Class_subpropmap::vx_get_propmap(vx_core::Type_string key) const {
      vx_web_html::Type_propmap output = vx_web_html::e_propmap;
      const vx_web_html::Class_subpropmap* map = this;
      std::string skey = key->vx_string();
      if (vx_core::vx_boolean_from_string_starts(skey, ":")) {
        skey = vx_core::vx_string_from_string_start(skey, 2);
      }
      std::map<std::string, vx_web_html::Type_propmap> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_web_html::e_propmap);
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_subpropmap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_propmap(key);
    }

    // vx_mappropmap()
    std::map<std::string, vx_web_html::Type_propmap> Class_subpropmap::vx_mappropmap() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_subpropmap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_web_html::Type_subpropmap output = vx_web_html::e_subpropmap;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_web_html::Type_propmap> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_web_html::t_propmap) {
          vx_web_html::Type_propmap castval = vx_core::vx_any_from_any(vx_web_html::t_propmap, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(subpropmap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((map.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_subpropmap();
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

    vx_core::Type_any Class_subpropmap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_subpropmap, vals);
    }

    vx_core::Type_any Class_subpropmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_subpropmap output = vx_web_html::e_subpropmap;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_subpropmap valmap = vx_core::vx_any_from_any(vx_web_html::t_subpropmap, copyval);
      output = valmap;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_web_html::Type_propmap> mapval = valmap->vx_mappropmap();
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
          vx_web_html::Type_propmap valany = NULL;
          if (valsubtype == vx_web_html::t_propmap) {
            valany = vx_core::vx_any_from_any(vx_web_html::t_propmap, valsub);
          } else if (valsubtype == vx_web_html::t_propmap) {
            valany = vx_core::vx_any_from_any(vx_web_html::t_propmap, valsub);
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
        output = new vx_web_html::Class_subpropmap();
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

    vx_core::Type_msgblock Class_subpropmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_subpropmap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_subpropmap::vx_empty() const {return vx_web_html::e_subpropmap;}
    vx_core::Type_any Class_subpropmap::vx_type() const {return vx_web_html::t_subpropmap;}

    vx_core::Type_typedef Class_subpropmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "subpropmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_web_html::t_propmap}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_subpropmap::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type table)
  // class Class_table {
    Abstract_table::~Abstract_table() {}

    Class_table::Class_table() : Abstract_table::Abstract_table() {
      vx_core::refcount += 1;
    }

    Class_table::~Class_table() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_eventmap,
        this->vx_p_style,
        this->vx_p_style_unique,
        this->vx_p_stylelist,
        this->vx_p_tbody,
        this->vx_p_thead
      });
    }

    // id()
    vx_core::Type_string Class_table::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // eventmap()
    vx_event::Type_eventmap Class_table::eventmap() const {
      vx_event::Type_eventmap output = this->vx_p_eventmap;
      if (!output) {
        output = vx_event::e_eventmap;
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_table::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // style_unique()
    vx_web_html::Type_style Class_table::style_unique() const {
      vx_web_html::Type_style output = this->vx_p_style_unique;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // stylelist()
    vx_web_html::Type_stylelist Class_table::stylelist() const {
      vx_web_html::Type_stylelist output = this->vx_p_stylelist;
      if (!output) {
        output = vx_web_html::e_stylelist;
      }
      return output;
    }

    // tbody()
    vx_web_html::Type_tbody Class_table::tbody() const {
      vx_web_html::Type_tbody output = this->vx_p_tbody;
      if (!output) {
        output = vx_web_html::e_tbody;
      }
      return output;
    }

    // thead()
    vx_web_html::Type_thead Class_table::thead() const {
      vx_web_html::Type_thead output = this->vx_p_thead;
      if (!output) {
        output = vx_web_html::e_thead;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_table::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":eventmap") {
        output = this->eventmap();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":style-unique") {
        output = this->style_unique();
      } else if (skey == ":stylelist") {
        output = this->stylelist();
      } else if (skey == ":tbody") {
        output = this->tbody();
      } else if (skey == ":thead") {
        output = this->thead();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_table::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":eventmap"] = this->eventmap();
      output[":style"] = this->style();
      output[":style-unique"] = this->style_unique();
      output[":stylelist"] = this->stylelist();
      output[":tbody"] = this->tbody();
      output[":thead"] = this->thead();
      return output;
    }

    vx_core::Type_any Class_table::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_table, vals);
    }

    vx_core::Type_any Class_table::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_table output = vx_web_html::e_table;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_table val = vx_core::vx_any_from_any(vx_web_html::t_table, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_event::Type_eventmap vx_p_eventmap = val->eventmap();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_web_html::Type_style vx_p_style_unique = val->style_unique();
      vx_web_html::Type_stylelist vx_p_stylelist = val->stylelist();
      vx_web_html::Type_tbody vx_p_tbody = val->tbody();
      vx_web_html::Type_thead vx_p_thead = val->thead();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":eventmap") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":style-unique") {
            key = testkey;
          } else if (testkey == ":stylelist") {
            key = testkey;
          } else if (testkey == ":tbody") {
            key = testkey;
          } else if (testkey == ":thead") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new table) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (vx_p_id == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new table :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":eventmap") {
            if (vx_p_eventmap == valsub) {
            } else if (valsubtype == vx_event::t_eventmap) {
              ischanged = true;
              vx_p_eventmap = vx_core::vx_any_from_any(vx_event::t_eventmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new table :eventmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (vx_p_style == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new table :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style-unique") {
            if (vx_p_style_unique == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style_unique = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new table :style-unique " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":stylelist") {
            if (vx_p_stylelist == valsub) {
            } else if (valsubtype == vx_web_html::t_stylelist) {
              ischanged = true;
              vx_p_stylelist = vx_core::vx_any_from_any(vx_web_html::t_stylelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new table :stylelist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":tbody") {
            if (vx_p_tbody == valsub) {
            } else if (valsubtype == vx_web_html::t_tbody) {
              ischanged = true;
              vx_p_tbody = vx_core::vx_any_from_any(vx_web_html::t_tbody, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new table :tbody " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":thead") {
            if (vx_p_thead == valsub) {
            } else if (valsubtype == vx_web_html::t_thead) {
              ischanged = true;
              vx_p_thead = vx_core::vx_any_from_any(vx_web_html::t_thead, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new table :thead " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new table) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_table();
        if (output->vx_p_id != vx_p_id) {
          if (output->vx_p_id) {
            vx_core::vx_release_one(output->vx_p_id);
          }
          output->vx_p_id = vx_p_id;
          vx_core::vx_reserve(vx_p_id);
        }
        if (output->vx_p_eventmap != vx_p_eventmap) {
          if (output->vx_p_eventmap) {
            vx_core::vx_release_one(output->vx_p_eventmap);
          }
          output->vx_p_eventmap = vx_p_eventmap;
          vx_core::vx_reserve(vx_p_eventmap);
        }
        if (output->vx_p_style != vx_p_style) {
          if (output->vx_p_style) {
            vx_core::vx_release_one(output->vx_p_style);
          }
          output->vx_p_style = vx_p_style;
          vx_core::vx_reserve(vx_p_style);
        }
        if (output->vx_p_style_unique != vx_p_style_unique) {
          if (output->vx_p_style_unique) {
            vx_core::vx_release_one(output->vx_p_style_unique);
          }
          output->vx_p_style_unique = vx_p_style_unique;
          vx_core::vx_reserve(vx_p_style_unique);
        }
        if (output->vx_p_stylelist != vx_p_stylelist) {
          if (output->vx_p_stylelist) {
            vx_core::vx_release_one(output->vx_p_stylelist);
          }
          output->vx_p_stylelist = vx_p_stylelist;
          vx_core::vx_reserve(vx_p_stylelist);
        }
        if (output->vx_p_tbody != vx_p_tbody) {
          if (output->vx_p_tbody) {
            vx_core::vx_release_one(output->vx_p_tbody);
          }
          output->vx_p_tbody = vx_p_tbody;
          vx_core::vx_reserve(vx_p_tbody);
        }
        if (output->vx_p_thead != vx_p_thead) {
          if (output->vx_p_thead) {
            vx_core::vx_release_one(output->vx_p_thead);
          }
          output->vx_p_thead = vx_p_thead;
          vx_core::vx_reserve(vx_p_thead);
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

    vx_core::Type_msgblock Class_table::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_table::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_table::vx_empty() const {return vx_web_html::e_table;}
    vx_core::Type_any Class_table::vx_type() const {return vx_web_html::t_table;}

    vx_core::Type_typedef Class_table::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "table", // name
        ":struct", // extends
        vx_core::vx_typelist_from_listany({vx_web_html::t_node, vx_web_html::t_divchild}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "tbody", // name
            vx_web_html::t_tbody // type
          ),
          vx_core::vx_new_arg(
            "thead", // name
            vx_web_html::t_thead // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_table::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type tbody)
  // class Class_tbody {
    Abstract_tbody::~Abstract_tbody() {}

    Class_tbody::Class_tbody() : Abstract_tbody::Abstract_tbody() {
      vx_core::refcount += 1;
    }

    Class_tbody::~Class_tbody() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_eventmap,
        this->vx_p_style,
        this->vx_p_style_unique,
        this->vx_p_stylelist,
        this->vx_p_nodes
      });
    }

    // id()
    vx_core::Type_string Class_tbody::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // eventmap()
    vx_event::Type_eventmap Class_tbody::eventmap() const {
      vx_event::Type_eventmap output = this->vx_p_eventmap;
      if (!output) {
        output = vx_event::e_eventmap;
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_tbody::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // style_unique()
    vx_web_html::Type_style Class_tbody::style_unique() const {
      vx_web_html::Type_style output = this->vx_p_style_unique;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // stylelist()
    vx_web_html::Type_stylelist Class_tbody::stylelist() const {
      vx_web_html::Type_stylelist output = this->vx_p_stylelist;
      if (!output) {
        output = vx_web_html::e_stylelist;
      }
      return output;
    }

    // nodes()
    vx_web_html::Type_trlist Class_tbody::nodes() const {
      vx_web_html::Type_trlist output = this->vx_p_nodes;
      if (!output) {
        output = vx_web_html::e_trlist;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_tbody::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":eventmap") {
        output = this->eventmap();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":style-unique") {
        output = this->style_unique();
      } else if (skey == ":stylelist") {
        output = this->stylelist();
      } else if (skey == ":nodes") {
        output = this->nodes();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_tbody::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":eventmap"] = this->eventmap();
      output[":style"] = this->style();
      output[":style-unique"] = this->style_unique();
      output[":stylelist"] = this->stylelist();
      output[":nodes"] = this->nodes();
      return output;
    }

    vx_core::Type_any Class_tbody::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_tbody, vals);
    }

    vx_core::Type_any Class_tbody::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_tbody output = vx_web_html::e_tbody;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_tbody val = vx_core::vx_any_from_any(vx_web_html::t_tbody, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_event::Type_eventmap vx_p_eventmap = val->eventmap();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_web_html::Type_style vx_p_style_unique = val->style_unique();
      vx_web_html::Type_stylelist vx_p_stylelist = val->stylelist();
      vx_web_html::Type_trlist vx_p_nodes = val->nodes();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":eventmap") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":style-unique") {
            key = testkey;
          } else if (testkey == ":stylelist") {
            key = testkey;
          } else if (testkey == ":nodes") {
            key = testkey;
          } else if (valsubtype == vx_web_html::t_trlist) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_trlist, valsub);
          } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_trlist)) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_trlist, valsub);
          } else if (valsubtype == vx_web_html::t_tr) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_copy(vx_p_nodes, {valsub});
          } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_tr)) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_copy(vx_p_nodes, {valsub});
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new tbody) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (vx_p_id == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new tbody :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":eventmap") {
            if (vx_p_eventmap == valsub) {
            } else if (valsubtype == vx_event::t_eventmap) {
              ischanged = true;
              vx_p_eventmap = vx_core::vx_any_from_any(vx_event::t_eventmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new tbody :eventmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (vx_p_style == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new tbody :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style-unique") {
            if (vx_p_style_unique == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style_unique = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new tbody :style-unique " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":stylelist") {
            if (vx_p_stylelist == valsub) {
            } else if (valsubtype == vx_web_html::t_stylelist) {
              ischanged = true;
              vx_p_stylelist = vx_core::vx_any_from_any(vx_web_html::t_stylelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new tbody :stylelist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":nodes") {
            if (vx_p_nodes == valsub) {
            } else if (valsubtype == vx_web_html::t_trlist) {
              ischanged = true;
              vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_trlist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new tbody :nodes " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new tbody) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_tbody();
        if (output->vx_p_id != vx_p_id) {
          if (output->vx_p_id) {
            vx_core::vx_release_one(output->vx_p_id);
          }
          output->vx_p_id = vx_p_id;
          vx_core::vx_reserve(vx_p_id);
        }
        if (output->vx_p_eventmap != vx_p_eventmap) {
          if (output->vx_p_eventmap) {
            vx_core::vx_release_one(output->vx_p_eventmap);
          }
          output->vx_p_eventmap = vx_p_eventmap;
          vx_core::vx_reserve(vx_p_eventmap);
        }
        if (output->vx_p_style != vx_p_style) {
          if (output->vx_p_style) {
            vx_core::vx_release_one(output->vx_p_style);
          }
          output->vx_p_style = vx_p_style;
          vx_core::vx_reserve(vx_p_style);
        }
        if (output->vx_p_style_unique != vx_p_style_unique) {
          if (output->vx_p_style_unique) {
            vx_core::vx_release_one(output->vx_p_style_unique);
          }
          output->vx_p_style_unique = vx_p_style_unique;
          vx_core::vx_reserve(vx_p_style_unique);
        }
        if (output->vx_p_stylelist != vx_p_stylelist) {
          if (output->vx_p_stylelist) {
            vx_core::vx_release_one(output->vx_p_stylelist);
          }
          output->vx_p_stylelist = vx_p_stylelist;
          vx_core::vx_reserve(vx_p_stylelist);
        }
        if (output->vx_p_nodes != vx_p_nodes) {
          if (output->vx_p_nodes) {
            vx_core::vx_release_one(output->vx_p_nodes);
          }
          output->vx_p_nodes = vx_p_nodes;
          vx_core::vx_reserve(vx_p_nodes);
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

    vx_core::Type_msgblock Class_tbody::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_tbody::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_tbody::vx_empty() const {return vx_web_html::e_tbody;}
    vx_core::Type_any Class_tbody::vx_type() const {return vx_web_html::t_tbody;}

    vx_core::Type_typedef Class_tbody::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "tbody", // name
        ":struct", // extends
        vx_core::vx_typelist_from_listany({vx_web_html::t_node}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "nodes", // name
            vx_web_html::t_trlist // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_tbody::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type td)
  // class Class_td {
    Abstract_td::~Abstract_td() {}

    Class_td::Class_td() : Abstract_td::Abstract_td() {
      vx_core::refcount += 1;
    }

    Class_td::~Class_td() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_eventmap,
        this->vx_p_style,
        this->vx_p_style_unique,
        this->vx_p_stylelist,
        this->vx_p_nodes
      });
    }

    // id()
    vx_core::Type_string Class_td::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // eventmap()
    vx_event::Type_eventmap Class_td::eventmap() const {
      vx_event::Type_eventmap output = this->vx_p_eventmap;
      if (!output) {
        output = vx_event::e_eventmap;
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_td::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // style_unique()
    vx_web_html::Type_style Class_td::style_unique() const {
      vx_web_html::Type_style output = this->vx_p_style_unique;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // stylelist()
    vx_web_html::Type_stylelist Class_td::stylelist() const {
      vx_web_html::Type_stylelist output = this->vx_p_stylelist;
      if (!output) {
        output = vx_web_html::e_stylelist;
      }
      return output;
    }

    // nodes()
    vx_web_html::Type_divchildlist Class_td::nodes() const {
      vx_web_html::Type_divchildlist output = this->vx_p_nodes;
      if (!output) {
        output = vx_web_html::e_divchildlist;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_td::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":eventmap") {
        output = this->eventmap();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":style-unique") {
        output = this->style_unique();
      } else if (skey == ":stylelist") {
        output = this->stylelist();
      } else if (skey == ":nodes") {
        output = this->nodes();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_td::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":eventmap"] = this->eventmap();
      output[":style"] = this->style();
      output[":style-unique"] = this->style_unique();
      output[":stylelist"] = this->stylelist();
      output[":nodes"] = this->nodes();
      return output;
    }

    vx_core::Type_any Class_td::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_td, vals);
    }

    vx_core::Type_any Class_td::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_td output = vx_web_html::e_td;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_td val = vx_core::vx_any_from_any(vx_web_html::t_td, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_event::Type_eventmap vx_p_eventmap = val->eventmap();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_web_html::Type_style vx_p_style_unique = val->style_unique();
      vx_web_html::Type_stylelist vx_p_stylelist = val->stylelist();
      vx_web_html::Type_divchildlist vx_p_nodes = val->nodes();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":eventmap") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":style-unique") {
            key = testkey;
          } else if (testkey == ":stylelist") {
            key = testkey;
          } else if (testkey == ":nodes") {
            key = testkey;
          } else if (valsubtype == vx_web_html::t_divchildlist) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_divchildlist, valsub);
          } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_divchildlist)) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_divchildlist, valsub);
          } else if (valsubtype == vx_web_html::t_divchild) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_copy(vx_p_nodes, {valsub});
          } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_divchild)) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_copy(vx_p_nodes, {valsub});
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new td) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (vx_p_id == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new td :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":eventmap") {
            if (vx_p_eventmap == valsub) {
            } else if (valsubtype == vx_event::t_eventmap) {
              ischanged = true;
              vx_p_eventmap = vx_core::vx_any_from_any(vx_event::t_eventmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new td :eventmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (vx_p_style == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new td :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style-unique") {
            if (vx_p_style_unique == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style_unique = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new td :style-unique " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":stylelist") {
            if (vx_p_stylelist == valsub) {
            } else if (valsubtype == vx_web_html::t_stylelist) {
              ischanged = true;
              vx_p_stylelist = vx_core::vx_any_from_any(vx_web_html::t_stylelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new td :stylelist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":nodes") {
            if (vx_p_nodes == valsub) {
            } else if (valsubtype == vx_web_html::t_divchildlist) {
              ischanged = true;
              vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_divchildlist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new td :nodes " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new td) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_td();
        if (output->vx_p_id != vx_p_id) {
          if (output->vx_p_id) {
            vx_core::vx_release_one(output->vx_p_id);
          }
          output->vx_p_id = vx_p_id;
          vx_core::vx_reserve(vx_p_id);
        }
        if (output->vx_p_eventmap != vx_p_eventmap) {
          if (output->vx_p_eventmap) {
            vx_core::vx_release_one(output->vx_p_eventmap);
          }
          output->vx_p_eventmap = vx_p_eventmap;
          vx_core::vx_reserve(vx_p_eventmap);
        }
        if (output->vx_p_style != vx_p_style) {
          if (output->vx_p_style) {
            vx_core::vx_release_one(output->vx_p_style);
          }
          output->vx_p_style = vx_p_style;
          vx_core::vx_reserve(vx_p_style);
        }
        if (output->vx_p_style_unique != vx_p_style_unique) {
          if (output->vx_p_style_unique) {
            vx_core::vx_release_one(output->vx_p_style_unique);
          }
          output->vx_p_style_unique = vx_p_style_unique;
          vx_core::vx_reserve(vx_p_style_unique);
        }
        if (output->vx_p_stylelist != vx_p_stylelist) {
          if (output->vx_p_stylelist) {
            vx_core::vx_release_one(output->vx_p_stylelist);
          }
          output->vx_p_stylelist = vx_p_stylelist;
          vx_core::vx_reserve(vx_p_stylelist);
        }
        if (output->vx_p_nodes != vx_p_nodes) {
          if (output->vx_p_nodes) {
            vx_core::vx_release_one(output->vx_p_nodes);
          }
          output->vx_p_nodes = vx_p_nodes;
          vx_core::vx_reserve(vx_p_nodes);
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

    vx_core::Type_msgblock Class_td::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_td::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_td::vx_empty() const {return vx_web_html::e_td;}
    vx_core::Type_any Class_td::vx_type() const {return vx_web_html::t_td;}

    vx_core::Type_typedef Class_td::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "td", // name
        ":struct", // extends
        vx_core::vx_typelist_from_listany({vx_web_html::t_node}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "nodes", // name
            vx_web_html::t_divchildlist // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_td::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type tdlist)
  // class Class_tdlist {
    Abstract_tdlist::~Abstract_tdlist() {}

    Class_tdlist::Class_tdlist() : Abstract_tdlist::Abstract_tdlist() {
      vx_core::refcount += 1;
    }

    Class_tdlist::~Class_tdlist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_tdlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_web_html::Type_td Class_tdlist::vx_get_td(vx_core::Type_int index) const {
      vx_web_html::Type_td output = vx_web_html::e_td;
      long iindex = index->vx_int();
      std::vector<vx_web_html::Type_td> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_web_html::Type_td> Class_tdlist::vx_listtd() const {return vx_p_list;}

    vx_core::Type_any vx_web_html::Class_tdlist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_td(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_tdlist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_web_html::Type_tdlist output = vx_web_html::e_tdlist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_web_html::Type_td> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_web_html::t_td) {
          vx_web_html::Type_td castval = vx_core::vx_any_from_any(vx_web_html::t_td, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_web_html::t_td)) {
          vx_web_html::Type_td castval = vx_core::vx_any_from_any(vx_web_html::t_td, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(tdlist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_tdlist();
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

    vx_core::Type_any Class_tdlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_tdlist, vals);
    }

    vx_core::Type_any Class_tdlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_tdlist output = vx_web_html::e_tdlist;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_tdlist val = vx_core::vx_any_from_any(vx_web_html::t_tdlist, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_web_html::Type_td> listval = val->vx_listtd();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_web_html::t_td) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_web_html::t_td, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_td)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_web_html::t_td, valsub));
        } else if (valsubtype == vx_web_html::t_tdlist) {
          ischanged = true;
          vx_web_html::Type_tdlist multi = vx_core::vx_any_from_any(vx_web_html::t_tdlist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listtd());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new tdlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_tdlist();
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

    vx_core::Type_msgblock Class_tdlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_tdlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_tdlist::vx_empty() const {return vx_web_html::e_tdlist;}
    vx_core::Type_any Class_tdlist::vx_type() const {return vx_web_html::t_tdlist;}

    vx_core::Type_typedef Class_tdlist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "tdlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_web_html::t_td}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_tdlist::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type thead)
  // class Class_thead {
    Abstract_thead::~Abstract_thead() {}

    Class_thead::Class_thead() : Abstract_thead::Abstract_thead() {
      vx_core::refcount += 1;
    }

    Class_thead::~Class_thead() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_eventmap,
        this->vx_p_style,
        this->vx_p_style_unique,
        this->vx_p_stylelist,
        this->vx_p_nodes
      });
    }

    // id()
    vx_core::Type_string Class_thead::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // eventmap()
    vx_event::Type_eventmap Class_thead::eventmap() const {
      vx_event::Type_eventmap output = this->vx_p_eventmap;
      if (!output) {
        output = vx_event::e_eventmap;
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_thead::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // style_unique()
    vx_web_html::Type_style Class_thead::style_unique() const {
      vx_web_html::Type_style output = this->vx_p_style_unique;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // stylelist()
    vx_web_html::Type_stylelist Class_thead::stylelist() const {
      vx_web_html::Type_stylelist output = this->vx_p_stylelist;
      if (!output) {
        output = vx_web_html::e_stylelist;
      }
      return output;
    }

    // nodes()
    vx_web_html::Type_trlist Class_thead::nodes() const {
      vx_web_html::Type_trlist output = this->vx_p_nodes;
      if (!output) {
        output = vx_web_html::e_trlist;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_thead::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":eventmap") {
        output = this->eventmap();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":style-unique") {
        output = this->style_unique();
      } else if (skey == ":stylelist") {
        output = this->stylelist();
      } else if (skey == ":nodes") {
        output = this->nodes();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_thead::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":eventmap"] = this->eventmap();
      output[":style"] = this->style();
      output[":style-unique"] = this->style_unique();
      output[":stylelist"] = this->stylelist();
      output[":nodes"] = this->nodes();
      return output;
    }

    vx_core::Type_any Class_thead::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_thead, vals);
    }

    vx_core::Type_any Class_thead::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_thead output = vx_web_html::e_thead;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_thead val = vx_core::vx_any_from_any(vx_web_html::t_thead, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_event::Type_eventmap vx_p_eventmap = val->eventmap();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_web_html::Type_style vx_p_style_unique = val->style_unique();
      vx_web_html::Type_stylelist vx_p_stylelist = val->stylelist();
      vx_web_html::Type_trlist vx_p_nodes = val->nodes();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":eventmap") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":style-unique") {
            key = testkey;
          } else if (testkey == ":stylelist") {
            key = testkey;
          } else if (testkey == ":nodes") {
            key = testkey;
          } else if (valsubtype == vx_web_html::t_trlist) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_trlist, valsub);
          } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_trlist)) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_trlist, valsub);
          } else if (valsubtype == vx_web_html::t_tr) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_copy(vx_p_nodes, {valsub});
          } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_tr)) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_copy(vx_p_nodes, {valsub});
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new thead) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (vx_p_id == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new thead :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":eventmap") {
            if (vx_p_eventmap == valsub) {
            } else if (valsubtype == vx_event::t_eventmap) {
              ischanged = true;
              vx_p_eventmap = vx_core::vx_any_from_any(vx_event::t_eventmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new thead :eventmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (vx_p_style == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new thead :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style-unique") {
            if (vx_p_style_unique == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style_unique = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new thead :style-unique " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":stylelist") {
            if (vx_p_stylelist == valsub) {
            } else if (valsubtype == vx_web_html::t_stylelist) {
              ischanged = true;
              vx_p_stylelist = vx_core::vx_any_from_any(vx_web_html::t_stylelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new thead :stylelist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":nodes") {
            if (vx_p_nodes == valsub) {
            } else if (valsubtype == vx_web_html::t_trlist) {
              ischanged = true;
              vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_trlist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new thead :nodes " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new thead) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_thead();
        if (output->vx_p_id != vx_p_id) {
          if (output->vx_p_id) {
            vx_core::vx_release_one(output->vx_p_id);
          }
          output->vx_p_id = vx_p_id;
          vx_core::vx_reserve(vx_p_id);
        }
        if (output->vx_p_eventmap != vx_p_eventmap) {
          if (output->vx_p_eventmap) {
            vx_core::vx_release_one(output->vx_p_eventmap);
          }
          output->vx_p_eventmap = vx_p_eventmap;
          vx_core::vx_reserve(vx_p_eventmap);
        }
        if (output->vx_p_style != vx_p_style) {
          if (output->vx_p_style) {
            vx_core::vx_release_one(output->vx_p_style);
          }
          output->vx_p_style = vx_p_style;
          vx_core::vx_reserve(vx_p_style);
        }
        if (output->vx_p_style_unique != vx_p_style_unique) {
          if (output->vx_p_style_unique) {
            vx_core::vx_release_one(output->vx_p_style_unique);
          }
          output->vx_p_style_unique = vx_p_style_unique;
          vx_core::vx_reserve(vx_p_style_unique);
        }
        if (output->vx_p_stylelist != vx_p_stylelist) {
          if (output->vx_p_stylelist) {
            vx_core::vx_release_one(output->vx_p_stylelist);
          }
          output->vx_p_stylelist = vx_p_stylelist;
          vx_core::vx_reserve(vx_p_stylelist);
        }
        if (output->vx_p_nodes != vx_p_nodes) {
          if (output->vx_p_nodes) {
            vx_core::vx_release_one(output->vx_p_nodes);
          }
          output->vx_p_nodes = vx_p_nodes;
          vx_core::vx_reserve(vx_p_nodes);
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

    vx_core::Type_msgblock Class_thead::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_thead::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_thead::vx_empty() const {return vx_web_html::e_thead;}
    vx_core::Type_any Class_thead::vx_type() const {return vx_web_html::t_thead;}

    vx_core::Type_typedef Class_thead::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "thead", // name
        ":struct", // extends
        vx_core::vx_typelist_from_listany({vx_web_html::t_node}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "nodes", // name
            vx_web_html::t_trlist // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_thead::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type title)
  // class Class_title {
    Abstract_title::~Abstract_title() {}

    Class_title::Class_title() : Abstract_title::Abstract_title() {
      vx_core::refcount += 1;
    }

    Class_title::~Class_title() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_eventmap,
        this->vx_p_style,
        this->vx_p_style_unique,
        this->vx_p_stylelist,
        this->vx_p_text
      });
    }

    // id()
    vx_core::Type_string Class_title::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // eventmap()
    vx_event::Type_eventmap Class_title::eventmap() const {
      vx_event::Type_eventmap output = this->vx_p_eventmap;
      if (!output) {
        output = vx_event::e_eventmap;
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_title::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // style_unique()
    vx_web_html::Type_style Class_title::style_unique() const {
      vx_web_html::Type_style output = this->vx_p_style_unique;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // stylelist()
    vx_web_html::Type_stylelist Class_title::stylelist() const {
      vx_web_html::Type_stylelist output = this->vx_p_stylelist;
      if (!output) {
        output = vx_web_html::e_stylelist;
      }
      return output;
    }

    // text()
    vx_core::Type_string Class_title::text() const {
      vx_core::Type_string output = this->vx_p_text;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_title::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":eventmap") {
        output = this->eventmap();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":style-unique") {
        output = this->style_unique();
      } else if (skey == ":stylelist") {
        output = this->stylelist();
      } else if (skey == ":text") {
        output = this->text();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_title::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":eventmap"] = this->eventmap();
      output[":style"] = this->style();
      output[":style-unique"] = this->style_unique();
      output[":stylelist"] = this->stylelist();
      output[":text"] = this->text();
      return output;
    }

    vx_core::Type_any Class_title::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_title, vals);
    }

    vx_core::Type_any Class_title::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_title output = vx_web_html::e_title;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_title val = vx_core::vx_any_from_any(vx_web_html::t_title, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_event::Type_eventmap vx_p_eventmap = val->eventmap();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_web_html::Type_style vx_p_style_unique = val->style_unique();
      vx_web_html::Type_stylelist vx_p_stylelist = val->stylelist();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":eventmap") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":style-unique") {
            key = testkey;
          } else if (testkey == ":stylelist") {
            key = testkey;
          } else if (testkey == ":text") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new title) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (vx_p_id == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new title :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":eventmap") {
            if (vx_p_eventmap == valsub) {
            } else if (valsubtype == vx_event::t_eventmap) {
              ischanged = true;
              vx_p_eventmap = vx_core::vx_any_from_any(vx_event::t_eventmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new title :eventmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (vx_p_style == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new title :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style-unique") {
            if (vx_p_style_unique == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style_unique = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new title :style-unique " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":stylelist") {
            if (vx_p_stylelist == valsub) {
            } else if (valsubtype == vx_web_html::t_stylelist) {
              ischanged = true;
              vx_p_stylelist = vx_core::vx_any_from_any(vx_web_html::t_stylelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new title :stylelist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":text") {
            if (vx_p_text == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_text = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new title :text " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new title) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_title();
        if (output->vx_p_id != vx_p_id) {
          if (output->vx_p_id) {
            vx_core::vx_release_one(output->vx_p_id);
          }
          output->vx_p_id = vx_p_id;
          vx_core::vx_reserve(vx_p_id);
        }
        if (output->vx_p_eventmap != vx_p_eventmap) {
          if (output->vx_p_eventmap) {
            vx_core::vx_release_one(output->vx_p_eventmap);
          }
          output->vx_p_eventmap = vx_p_eventmap;
          vx_core::vx_reserve(vx_p_eventmap);
        }
        if (output->vx_p_style != vx_p_style) {
          if (output->vx_p_style) {
            vx_core::vx_release_one(output->vx_p_style);
          }
          output->vx_p_style = vx_p_style;
          vx_core::vx_reserve(vx_p_style);
        }
        if (output->vx_p_style_unique != vx_p_style_unique) {
          if (output->vx_p_style_unique) {
            vx_core::vx_release_one(output->vx_p_style_unique);
          }
          output->vx_p_style_unique = vx_p_style_unique;
          vx_core::vx_reserve(vx_p_style_unique);
        }
        if (output->vx_p_stylelist != vx_p_stylelist) {
          if (output->vx_p_stylelist) {
            vx_core::vx_release_one(output->vx_p_stylelist);
          }
          output->vx_p_stylelist = vx_p_stylelist;
          vx_core::vx_reserve(vx_p_stylelist);
        }
        if (output->vx_p_text != vx_p_text) {
          if (output->vx_p_text) {
            vx_core::vx_release_one(output->vx_p_text);
          }
          output->vx_p_text = vx_p_text;
          vx_core::vx_reserve(vx_p_text);
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

    vx_core::Type_msgblock Class_title::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_title::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_title::vx_empty() const {return vx_web_html::e_title;}
    vx_core::Type_any Class_title::vx_type() const {return vx_web_html::t_title;}

    vx_core::Type_typedef Class_title::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "title", // name
        ":struct", // extends
        vx_core::vx_typelist_from_listany({vx_web_html::t_node, vx_web_html::t_headchild}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "text", // name
            vx_core::t_string // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_title::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type tr)
  // class Class_tr {
    Abstract_tr::~Abstract_tr() {}

    Class_tr::Class_tr() : Abstract_tr::Abstract_tr() {
      vx_core::refcount += 1;
    }

    Class_tr::~Class_tr() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_eventmap,
        this->vx_p_style,
        this->vx_p_style_unique,
        this->vx_p_stylelist,
        this->vx_p_nodes
      });
    }

    // id()
    vx_core::Type_string Class_tr::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // eventmap()
    vx_event::Type_eventmap Class_tr::eventmap() const {
      vx_event::Type_eventmap output = this->vx_p_eventmap;
      if (!output) {
        output = vx_event::e_eventmap;
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_tr::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // style_unique()
    vx_web_html::Type_style Class_tr::style_unique() const {
      vx_web_html::Type_style output = this->vx_p_style_unique;
      if (!output) {
        output = vx_web_html::e_style;
      }
      return output;
    }

    // stylelist()
    vx_web_html::Type_stylelist Class_tr::stylelist() const {
      vx_web_html::Type_stylelist output = this->vx_p_stylelist;
      if (!output) {
        output = vx_web_html::e_stylelist;
      }
      return output;
    }

    // nodes()
    vx_web_html::Type_tdlist Class_tr::nodes() const {
      vx_web_html::Type_tdlist output = this->vx_p_nodes;
      if (!output) {
        output = vx_web_html::e_tdlist;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_tr::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":eventmap") {
        output = this->eventmap();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":style-unique") {
        output = this->style_unique();
      } else if (skey == ":stylelist") {
        output = this->stylelist();
      } else if (skey == ":nodes") {
        output = this->nodes();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_tr::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":eventmap"] = this->eventmap();
      output[":style"] = this->style();
      output[":style-unique"] = this->style_unique();
      output[":stylelist"] = this->stylelist();
      output[":nodes"] = this->nodes();
      return output;
    }

    vx_core::Type_any Class_tr::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_tr, vals);
    }

    vx_core::Type_any Class_tr::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_tr output = vx_web_html::e_tr;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_tr val = vx_core::vx_any_from_any(vx_web_html::t_tr, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_event::Type_eventmap vx_p_eventmap = val->eventmap();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_web_html::Type_style vx_p_style_unique = val->style_unique();
      vx_web_html::Type_stylelist vx_p_stylelist = val->stylelist();
      vx_web_html::Type_tdlist vx_p_nodes = val->nodes();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":eventmap") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":style-unique") {
            key = testkey;
          } else if (testkey == ":stylelist") {
            key = testkey;
          } else if (testkey == ":nodes") {
            key = testkey;
          } else if (valsubtype == vx_web_html::t_tdlist) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_tdlist, valsub);
          } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_tdlist)) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_tdlist, valsub);
          } else if (valsubtype == vx_web_html::t_td) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_copy(vx_p_nodes, {valsub});
          } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_td)) { // default property
            ischanged = true;
            vx_p_nodes = vx_core::vx_copy(vx_p_nodes, {valsub});
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new tr) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (vx_p_id == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new tr :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":eventmap") {
            if (vx_p_eventmap == valsub) {
            } else if (valsubtype == vx_event::t_eventmap) {
              ischanged = true;
              vx_p_eventmap = vx_core::vx_any_from_any(vx_event::t_eventmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new tr :eventmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (vx_p_style == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new tr :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style-unique") {
            if (vx_p_style_unique == valsub) {
            } else if (valsubtype == vx_web_html::t_style) {
              ischanged = true;
              vx_p_style_unique = vx_core::vx_any_from_any(vx_web_html::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new tr :style-unique " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":stylelist") {
            if (vx_p_stylelist == valsub) {
            } else if (valsubtype == vx_web_html::t_stylelist) {
              ischanged = true;
              vx_p_stylelist = vx_core::vx_any_from_any(vx_web_html::t_stylelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new tr :stylelist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":nodes") {
            if (vx_p_nodes == valsub) {
            } else if (valsubtype == vx_web_html::t_tdlist) {
              ischanged = true;
              vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_tdlist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new tr :nodes " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new tr) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_tr();
        if (output->vx_p_id != vx_p_id) {
          if (output->vx_p_id) {
            vx_core::vx_release_one(output->vx_p_id);
          }
          output->vx_p_id = vx_p_id;
          vx_core::vx_reserve(vx_p_id);
        }
        if (output->vx_p_eventmap != vx_p_eventmap) {
          if (output->vx_p_eventmap) {
            vx_core::vx_release_one(output->vx_p_eventmap);
          }
          output->vx_p_eventmap = vx_p_eventmap;
          vx_core::vx_reserve(vx_p_eventmap);
        }
        if (output->vx_p_style != vx_p_style) {
          if (output->vx_p_style) {
            vx_core::vx_release_one(output->vx_p_style);
          }
          output->vx_p_style = vx_p_style;
          vx_core::vx_reserve(vx_p_style);
        }
        if (output->vx_p_style_unique != vx_p_style_unique) {
          if (output->vx_p_style_unique) {
            vx_core::vx_release_one(output->vx_p_style_unique);
          }
          output->vx_p_style_unique = vx_p_style_unique;
          vx_core::vx_reserve(vx_p_style_unique);
        }
        if (output->vx_p_stylelist != vx_p_stylelist) {
          if (output->vx_p_stylelist) {
            vx_core::vx_release_one(output->vx_p_stylelist);
          }
          output->vx_p_stylelist = vx_p_stylelist;
          vx_core::vx_reserve(vx_p_stylelist);
        }
        if (output->vx_p_nodes != vx_p_nodes) {
          if (output->vx_p_nodes) {
            vx_core::vx_release_one(output->vx_p_nodes);
          }
          output->vx_p_nodes = vx_p_nodes;
          vx_core::vx_reserve(vx_p_nodes);
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

    vx_core::Type_msgblock Class_tr::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_tr::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_tr::vx_empty() const {return vx_web_html::e_tr;}
    vx_core::Type_any Class_tr::vx_type() const {return vx_web_html::t_tr;}

    vx_core::Type_typedef Class_tr::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "tr", // name
        ":struct", // extends
        vx_core::vx_typelist_from_listany({vx_web_html::t_node}), // traits
        vx_core::e_typelist, // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::vx_argmap_from_listarg({
          vx_core::vx_new_arg(
            "nodes", // name
            vx_web_html::t_tdlist // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_tr::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type trlist)
  // class Class_trlist {
    Abstract_trlist::~Abstract_trlist() {}

    Class_trlist::Class_trlist() : Abstract_trlist::Abstract_trlist() {
      vx_core::refcount += 1;
    }

    Class_trlist::~Class_trlist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_trlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_web_html::Type_tr Class_trlist::vx_get_tr(vx_core::Type_int index) const {
      vx_web_html::Type_tr output = vx_web_html::e_tr;
      long iindex = index->vx_int();
      std::vector<vx_web_html::Type_tr> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_web_html::Type_tr> Class_trlist::vx_listtr() const {return vx_p_list;}

    vx_core::Type_any vx_web_html::Class_trlist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_tr(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_trlist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_web_html::Type_trlist output = vx_web_html::e_trlist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_web_html::Type_tr> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_web_html::t_tr) {
          vx_web_html::Type_tr castval = vx_core::vx_any_from_any(vx_web_html::t_tr, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_web_html::t_tr)) {
          vx_web_html::Type_tr castval = vx_core::vx_any_from_any(vx_web_html::t_tr, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(trlist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_trlist();
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

    vx_core::Type_any Class_trlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_trlist, vals);
    }

    vx_core::Type_any Class_trlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_trlist output = vx_web_html::e_trlist;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_web_html::Type_trlist val = vx_core::vx_any_from_any(vx_web_html::t_trlist, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_web_html::Type_tr> listval = val->vx_listtr();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_web_html::t_tr) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_web_html::t_tr, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_web_html::t_tr)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_web_html::t_tr, valsub));
        } else if (valsubtype == vx_web_html::t_trlist) {
          ischanged = true;
          vx_web_html::Type_trlist multi = vx_core::vx_any_from_any(vx_web_html::t_trlist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listtr());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new trlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_web_html::Class_trlist();
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

    vx_core::Type_msgblock Class_trlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_trlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_trlist::vx_empty() const {return vx_web_html::e_trlist;}
    vx_core::Type_any Class_trlist::vx_type() const {return vx_web_html::t_trlist;}

    vx_core::Type_typedef Class_trlist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "trlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_web_html::t_tr}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_trlist::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (func htmlstring<-string)
  vx_core::Type_string f_htmlstring_from_string(vx_core::Type_string text) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(text);
    std::string str = text->vx_string();
    str = vx_core::vx_string_from_string_find_replace(str, "&", "&amp;");
    str = vx_core::vx_string_from_string_find_replace(str, "'", "\'");
    str = vx_core::vx_string_from_string_find_replace(str, ">", "&gt;");
    str = vx_core::vx_string_from_string_find_replace(str, "<", "&lt;");
    output = vx_core::vx_new_string(str);
    vx_core::vx_release_one_except(text, output);
    return output;
  }

  // (func htmlstring<-string)
  // class Class_htmlstring_from_string {
    Abstract_htmlstring_from_string::~Abstract_htmlstring_from_string() {}

    Class_htmlstring_from_string::Class_htmlstring_from_string() : Abstract_htmlstring_from_string::Abstract_htmlstring_from_string() {
      vx_core::refcount += 1;
    }

    Class_htmlstring_from_string::~Class_htmlstring_from_string() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_htmlstring_from_string::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_htmlstring_from_string output = vx_web_html::e_htmlstring_from_string;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_htmlstring_from_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_htmlstring_from_string output = vx_web_html::e_htmlstring_from_string;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_htmlstring_from_string::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "htmlstring<-string", // name
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

    vx_core::Type_constdef Class_htmlstring_from_string::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_htmlstring_from_string::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "htmlstring<-string", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_htmlstring_from_string::vx_empty() const {return vx_web_html::e_htmlstring_from_string;}
    vx_core::Type_any Class_htmlstring_from_string::vx_type() const {return vx_web_html::t_htmlstring_from_string;}
    vx_core::Type_msgblock Class_htmlstring_from_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_htmlstring_from_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_htmlstring_from_string::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_htmlstring_from_string::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_web_html::f_htmlstring_from_string(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_htmlstring_from_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_htmlstring_from_string(text);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string-indent)
  vx_core::Type_string f_string_indent(vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(indent);
    output = vx_core::f_string_repeat(vx_core::vx_new_string("  "), indent);
    vx_core::vx_release_one_except(indent, output);
    return output;
  }

  // (func string-indent)
  // class Class_string_indent {
    Abstract_string_indent::~Abstract_string_indent() {}

    Class_string_indent::Class_string_indent() : Abstract_string_indent::Abstract_string_indent() {
      vx_core::refcount += 1;
    }

    Class_string_indent::~Class_string_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_indent output = vx_web_html::e_string_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_indent output = vx_web_html::e_string_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string-indent", // name
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

    vx_core::Type_constdef Class_string_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_indent::vx_empty() const {return vx_web_html::e_string_indent;}
    vx_core::Type_any Class_string_indent::vx_type() const {return vx_web_html::t_string_indent;}
    vx_core::Type_msgblock Class_string_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_string_indent::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_string_indent::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_int inputval = vx_core::vx_any_from_any(vx_core::t_int, val);
      output = vx_web_html::f_string_indent(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_string_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_string_indent(indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-body-indent)
  vx_core::Type_string f_string_from_body_indent(vx_web_html::Type_body body, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({body, indent});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({body, indent}, [body, indent]() {
        vx_web_html::Type_divchildlist nodes = body->nodes();
        vx_core::vx_ref_plus(nodes);
        vx_core::Type_string output_1 = vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, vx_core::vx_new_string("body"), vx_core::vx_new_string(""), indent);
        vx_core::vx_release_one_except(nodes, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({body, indent}, output);
    return output;
  }

  // (func string<-body-indent)
  // class Class_string_from_body_indent {
    Abstract_string_from_body_indent::~Abstract_string_from_body_indent() {}

    Class_string_from_body_indent::Class_string_from_body_indent() : Abstract_string_from_body_indent::Abstract_string_from_body_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_body_indent::~Class_string_from_body_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_body_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_body_indent output = vx_web_html::e_string_from_body_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_body_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_body_indent output = vx_web_html::e_string_from_body_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_body_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-body-indent", // name
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

    vx_core::Type_constdef Class_string_from_body_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_body_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-body-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_body_indent::vx_empty() const {return vx_web_html::e_string_from_body_indent;}
    vx_core::Type_any Class_string_from_body_indent::vx_type() const {return vx_web_html::t_string_from_body_indent;}
    vx_core::Type_msgblock Class_string_from_body_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_body_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_body_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_body body = vx_core::vx_any_from_any(vx_web_html::t_body, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_body_indent(body, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-details-indent)
  vx_core::Type_string f_string_from_details_indent(vx_web_html::Type_details details, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({details, indent});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({indent, details}, [indent, details]() {
        vx_core::Type_string sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::vx_ref_plus(sindent);
        vx_web_html::Type_divchildlist summary = details->summary();
        vx_core::vx_ref_plus(summary);
        vx_web_html::Type_divchildlist nodes = details->nodes();
        vx_core::vx_ref_plus(nodes);
        vx_core::Type_string ssummary = vx_web_html::f_string_from_nodelist_indent(
          summary,
          vx_core::f_plus(indent, vx_core::vx_new_int(2))
        );
        vx_core::vx_ref_plus(ssummary);
        vx_core::Type_string snodes = vx_web_html::f_string_from_nodelist_indent(
          nodes,
          vx_core::f_plus(indent, vx_core::vx_new_int(1))
        );
        vx_core::vx_ref_plus(snodes);
        vx_core::Type_string output_1 = vx_core::f_new(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_anylist, {
            sindent,
            vx_core::vx_new_string("<details>"),
            sindent,
            vx_core::vx_new_string("  <summary>"),
            ssummary,
            sindent,
            vx_core::vx_new_string("  </summary>"),
            snodes,
            sindent,
            vx_core::vx_new_string("</details>")
          })
        );
        vx_core::vx_release_one_except({sindent, summary, nodes, ssummary, snodes}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({details, indent}, output);
    return output;
  }

  // (func string<-details-indent)
  // class Class_string_from_details_indent {
    Abstract_string_from_details_indent::~Abstract_string_from_details_indent() {}

    Class_string_from_details_indent::Class_string_from_details_indent() : Abstract_string_from_details_indent::Abstract_string_from_details_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_details_indent::~Class_string_from_details_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_details_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_details_indent output = vx_web_html::e_string_from_details_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_details_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_details_indent output = vx_web_html::e_string_from_details_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_details_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-details-indent", // name
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

    vx_core::Type_constdef Class_string_from_details_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_details_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-details-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_details_indent::vx_empty() const {return vx_web_html::e_string_from_details_indent;}
    vx_core::Type_any Class_string_from_details_indent::vx_type() const {return vx_web_html::t_string_from_details_indent;}
    vx_core::Type_msgblock Class_string_from_details_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_details_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_details_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_details details = vx_core::vx_any_from_any(vx_web_html::t_details, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_details_indent(details, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-div-indent)
  vx_core::Type_string f_string_from_div_indent(vx_web_html::Type_div div, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({div, indent});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({div, indent}, [div, indent]() {
        vx_web_html::Type_divchildlist nodes = div->nodes();
        vx_core::vx_ref_plus(nodes);
        vx_core::Type_string sid = vx_web_html::f_string_from_propname_val(
          vx_core::vx_new_string("id"),
          div->id()
        );
        vx_core::vx_ref_plus(sid);
        vx_core::Type_string sclass = vx_web_html::f_string_from_propstyle_stylelist(
          div->style(),
          div->stylelist()
        );
        vx_core::vx_ref_plus(sclass);
        vx_core::Type_string sstyle = vx_web_html::f_string_from_propstyleunique(
          div->style_unique()
        );
        vx_core::vx_ref_plus(sstyle);
        vx_core::Type_string output_1 = vx_web_html::f_string_from_nodelist_tag_prop_indent(
          nodes,
          vx_core::vx_new_string("div"),
          vx_core::f_new(
            vx_core::t_string,
            vx_core::vx_new(vx_core::t_anylist, {
              sid,
              sclass,
              sstyle
            })
          ),
          indent
        );
        vx_core::vx_release_one_except({nodes, sid, sclass, sstyle}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({div, indent}, output);
    return output;
  }

  // (func string<-div-indent)
  // class Class_string_from_div_indent {
    Abstract_string_from_div_indent::~Abstract_string_from_div_indent() {}

    Class_string_from_div_indent::Class_string_from_div_indent() : Abstract_string_from_div_indent::Abstract_string_from_div_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_div_indent::~Class_string_from_div_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_div_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_div_indent output = vx_web_html::e_string_from_div_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_div_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_div_indent output = vx_web_html::e_string_from_div_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_div_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-div-indent", // name
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

    vx_core::Type_constdef Class_string_from_div_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_div_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-div-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_div_indent::vx_empty() const {return vx_web_html::e_string_from_div_indent;}
    vx_core::Type_any Class_string_from_div_indent::vx_type() const {return vx_web_html::t_string_from_div_indent;}
    vx_core::Type_msgblock Class_string_from_div_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_div_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_div_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_div div = vx_core::vx_any_from_any(vx_web_html::t_div, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_div_indent(div, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-footer-indent)
  vx_core::Type_string f_string_from_footer_indent(vx_web_html::Type_footer footer, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({footer, indent});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({footer, indent}, [footer, indent]() {
        vx_web_html::Type_divchildlist nodes = footer->nodes();
        vx_core::vx_ref_plus(nodes);
        vx_core::Type_string output_1 = vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, vx_core::vx_new_string("footer"), vx_core::vx_new_string(""), indent);
        vx_core::vx_release_one_except(nodes, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({footer, indent}, output);
    return output;
  }

  // (func string<-footer-indent)
  // class Class_string_from_footer_indent {
    Abstract_string_from_footer_indent::~Abstract_string_from_footer_indent() {}

    Class_string_from_footer_indent::Class_string_from_footer_indent() : Abstract_string_from_footer_indent::Abstract_string_from_footer_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_footer_indent::~Class_string_from_footer_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_footer_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_footer_indent output = vx_web_html::e_string_from_footer_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_footer_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_footer_indent output = vx_web_html::e_string_from_footer_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_footer_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-footer-indent", // name
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

    vx_core::Type_constdef Class_string_from_footer_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_footer_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-footer-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_footer_indent::vx_empty() const {return vx_web_html::e_string_from_footer_indent;}
    vx_core::Type_any Class_string_from_footer_indent::vx_type() const {return vx_web_html::t_string_from_footer_indent;}
    vx_core::Type_msgblock Class_string_from_footer_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_footer_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_footer_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_footer footer = vx_core::vx_any_from_any(vx_web_html::t_footer, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_footer_indent(footer, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-h1-indent)
  vx_core::Type_string f_string_from_h1_indent(vx_web_html::Type_h1 h1, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({h1, indent});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({indent, h1}, [indent, h1]() {
        vx_core::Type_string sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::vx_ref_plus(sindent);
        vx_core::Type_string text = h1->text();
        vx_core::vx_ref_plus(text);
        vx_core::Type_string sid = vx_web_html::f_string_from_propname_val(
          vx_core::vx_new_string("id"),
          h1->id()
        );
        vx_core::vx_ref_plus(sid);
        vx_core::Type_string output_1 = vx_core::f_new(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_anylist, {
            sindent,
            vx_core::vx_new_string("<h1"),
            sid,
            vx_core::vx_new_string(">"),
            text,
            vx_core::vx_new_string("</h1>")
          })
        );
        vx_core::vx_release_one_except({sindent, text, sid}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({h1, indent}, output);
    return output;
  }

  // (func string<-h1-indent)
  // class Class_string_from_h1_indent {
    Abstract_string_from_h1_indent::~Abstract_string_from_h1_indent() {}

    Class_string_from_h1_indent::Class_string_from_h1_indent() : Abstract_string_from_h1_indent::Abstract_string_from_h1_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_h1_indent::~Class_string_from_h1_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_h1_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_h1_indent output = vx_web_html::e_string_from_h1_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_h1_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_h1_indent output = vx_web_html::e_string_from_h1_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_h1_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-h1-indent", // name
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

    vx_core::Type_constdef Class_string_from_h1_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_h1_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-h1-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_h1_indent::vx_empty() const {return vx_web_html::e_string_from_h1_indent;}
    vx_core::Type_any Class_string_from_h1_indent::vx_type() const {return vx_web_html::t_string_from_h1_indent;}
    vx_core::Type_msgblock Class_string_from_h1_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_h1_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_h1_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_h1 h1 = vx_core::vx_any_from_any(vx_web_html::t_h1, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_h1_indent(h1, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-h2-indent)
  vx_core::Type_string f_string_from_h2_indent(vx_web_html::Type_h2 h2, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({h2, indent});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({h2, indent}, [h2, indent]() {
        vx_core::Type_string text = h2->text();
        vx_core::vx_ref_plus(text);
        vx_core::Type_string sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::vx_ref_plus(sindent);
        vx_core::Type_string sid = vx_web_html::f_string_from_propname_val(
          vx_core::vx_new_string("id"),
          h2->id()
        );
        vx_core::vx_ref_plus(sid);
        vx_core::Type_string output_1 = vx_core::f_new(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_anylist, {
            sindent,
            vx_core::vx_new_string("<h2"),
            sid,
            vx_core::vx_new_string(">"),
            text,
            vx_core::vx_new_string("</h2>")
          })
        );
        vx_core::vx_release_one_except({text, sindent, sid}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({h2, indent}, output);
    return output;
  }

  // (func string<-h2-indent)
  // class Class_string_from_h2_indent {
    Abstract_string_from_h2_indent::~Abstract_string_from_h2_indent() {}

    Class_string_from_h2_indent::Class_string_from_h2_indent() : Abstract_string_from_h2_indent::Abstract_string_from_h2_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_h2_indent::~Class_string_from_h2_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_h2_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_h2_indent output = vx_web_html::e_string_from_h2_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_h2_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_h2_indent output = vx_web_html::e_string_from_h2_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_h2_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-h2-indent", // name
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

    vx_core::Type_constdef Class_string_from_h2_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_h2_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-h2-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_h2_indent::vx_empty() const {return vx_web_html::e_string_from_h2_indent;}
    vx_core::Type_any Class_string_from_h2_indent::vx_type() const {return vx_web_html::t_string_from_h2_indent;}
    vx_core::Type_msgblock Class_string_from_h2_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_h2_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_h2_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_h2 h2 = vx_core::vx_any_from_any(vx_web_html::t_h2, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_h2_indent(h2, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-h3-indent)
  vx_core::Type_string f_string_from_h3_indent(vx_web_html::Type_h3 h3, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({h3, indent});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({h3, indent}, [h3, indent]() {
        vx_core::Type_string text = h3->text();
        vx_core::vx_ref_plus(text);
        vx_core::Type_string sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::vx_ref_plus(sindent);
        vx_core::Type_string sid = vx_web_html::f_string_from_propname_val(
          vx_core::vx_new_string("id"),
          h3->id()
        );
        vx_core::vx_ref_plus(sid);
        vx_core::Type_string output_1 = vx_core::f_new(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_anylist, {
            sindent,
            vx_core::vx_new_string("<h3"),
            sid,
            vx_core::vx_new_string(">"),
            text,
            vx_core::vx_new_string("</h3>")
          })
        );
        vx_core::vx_release_one_except({text, sindent, sid}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({h3, indent}, output);
    return output;
  }

  // (func string<-h3-indent)
  // class Class_string_from_h3_indent {
    Abstract_string_from_h3_indent::~Abstract_string_from_h3_indent() {}

    Class_string_from_h3_indent::Class_string_from_h3_indent() : Abstract_string_from_h3_indent::Abstract_string_from_h3_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_h3_indent::~Class_string_from_h3_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_h3_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_h3_indent output = vx_web_html::e_string_from_h3_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_h3_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_h3_indent output = vx_web_html::e_string_from_h3_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_h3_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-h3-indent", // name
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

    vx_core::Type_constdef Class_string_from_h3_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_h3_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-h3-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_h3_indent::vx_empty() const {return vx_web_html::e_string_from_h3_indent;}
    vx_core::Type_any Class_string_from_h3_indent::vx_type() const {return vx_web_html::t_string_from_h3_indent;}
    vx_core::Type_msgblock Class_string_from_h3_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_h3_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_h3_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_h3 h3 = vx_core::vx_any_from_any(vx_web_html::t_h3, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_h3_indent(h3, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-head-indent)
  vx_core::Type_string f_string_from_head_indent(vx_web_html::Type_head head, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({head, indent});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({head, indent}, [head, indent]() {
        vx_web_html::Type_headchildlist nodes = head->nodes();
        vx_core::vx_ref_plus(nodes);
        vx_core::Type_string output_1 = vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, vx_core::vx_new_string("head"), vx_core::vx_new_string(""), indent);
        vx_core::vx_release_one_except(nodes, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({head, indent}, output);
    return output;
  }

  // (func string<-head-indent)
  // class Class_string_from_head_indent {
    Abstract_string_from_head_indent::~Abstract_string_from_head_indent() {}

    Class_string_from_head_indent::Class_string_from_head_indent() : Abstract_string_from_head_indent::Abstract_string_from_head_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_head_indent::~Class_string_from_head_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_head_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_head_indent output = vx_web_html::e_string_from_head_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_head_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_head_indent output = vx_web_html::e_string_from_head_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_head_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-head-indent", // name
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

    vx_core::Type_constdef Class_string_from_head_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_head_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-head-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_head_indent::vx_empty() const {return vx_web_html::e_string_from_head_indent;}
    vx_core::Type_any Class_string_from_head_indent::vx_type() const {return vx_web_html::t_string_from_head_indent;}
    vx_core::Type_msgblock Class_string_from_head_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_head_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_head_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_head head = vx_core::vx_any_from_any(vx_web_html::t_head, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_head_indent(head, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-html)
  vx_core::Type_string f_string_from_html(vx_web_html::Type_html html) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(html);
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({html}, [html]() {
        vx_core::Type_string lang = vx_web_html::f_string_from_propname_val(
          vx_core::vx_new_string("lang"),
          html->lang()
        );
        vx_core::vx_ref_plus(lang);
        vx_web_html::Type_head head = html->head();
        vx_core::vx_ref_plus(head);
        vx_web_html::Type_body body = html->body();
        vx_core::vx_ref_plus(body);
        vx_web_html::Type_footer footer = html->footer();
        vx_core::vx_ref_plus(footer);
        vx_core::Type_string shead = vx_web_html::f_string_from_head_indent(head, vx_core::vx_new_int(1));
        vx_core::vx_ref_plus(shead);
        vx_core::Type_string sbody = vx_web_html::f_string_from_body_indent(body, vx_core::vx_new_int(1));
        vx_core::vx_ref_plus(sbody);
        vx_core::Type_string sfooter = vx_web_html::f_string_from_footer_indent(footer, vx_core::vx_new_int(1));
        vx_core::vx_ref_plus(sfooter);
        vx_core::Type_string output_1 = vx_core::f_new(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string("<!DOCTYPE html>"),
            vx_core::c_newline,
            vx_core::vx_new_string("<html"),
            lang,
            vx_core::vx_new_string(">"),
            shead,
            sbody,
            sfooter,
            vx_core::c_newline,
            vx_core::vx_new_string("</html>")
          })
        );
        vx_core::vx_release_one_except({lang, head, body, footer, shead, sbody, sfooter}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(html, output);
    return output;
  }

  // (func string<-html)
  // class Class_string_from_html {
    Abstract_string_from_html::~Abstract_string_from_html() {}

    Class_string_from_html::Class_string_from_html() : Abstract_string_from_html::Abstract_string_from_html() {
      vx_core::refcount += 1;
    }

    Class_string_from_html::~Class_string_from_html() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_html::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_html output = vx_web_html::e_string_from_html;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_html::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_html output = vx_web_html::e_string_from_html;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_html::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-html", // name
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

    vx_core::Type_constdef Class_string_from_html::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_html::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-html", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_html::vx_empty() const {return vx_web_html::e_string_from_html;}
    vx_core::Type_any Class_string_from_html::vx_type() const {return vx_web_html::t_string_from_html;}
    vx_core::Type_msgblock Class_string_from_html::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_html::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_string_from_html::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_string_from_html::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_html inputval = vx_core::vx_any_from_any(vx_web_html::t_html, val);
      output = vx_web_html::f_string_from_html(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_string_from_html::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_html html = vx_core::vx_any_from_any(vx_web_html::t_html, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_string_from_html(html);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-indent)
  vx_core::Type_string f_string_from_indent(vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(indent);
    output = vx_core::f_if_1(
      vx_core::t_string,
      vx_core::f_eq(indent, vx_core::vx_new_int(0)),
      vx_core::vx_new_string(""),
      vx_core::f_new(
        vx_core::t_string,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::c_newline,
          vx_web_html::f_string_indent(indent)
        })
      )
    );
    vx_core::vx_release_one_except(indent, output);
    return output;
  }

  // (func string<-indent)
  // class Class_string_from_indent {
    Abstract_string_from_indent::~Abstract_string_from_indent() {}

    Class_string_from_indent::Class_string_from_indent() : Abstract_string_from_indent::Abstract_string_from_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_indent::~Class_string_from_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_indent output = vx_web_html::e_string_from_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_indent output = vx_web_html::e_string_from_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-indent", // name
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

    vx_core::Type_constdef Class_string_from_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_indent::vx_empty() const {return vx_web_html::e_string_from_indent;}
    vx_core::Type_any Class_string_from_indent::vx_type() const {return vx_web_html::t_string_from_indent;}
    vx_core::Type_msgblock Class_string_from_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_string_from_indent::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_string_from_indent::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_int inputval = vx_core::vx_any_from_any(vx_core::t_int, val);
      output = vx_web_html::f_string_from_indent(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_string_from_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_string_from_indent(indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-meta-indent)
  vx_core::Type_string f_string_from_meta_indent(vx_web_html::Type_meta meta, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({meta, indent});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({indent, meta}, [indent, meta]() {
        vx_core::Type_string sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::vx_ref_plus(sindent);
        vx_core::Type_string charset = meta->charset();
        vx_core::vx_ref_plus(charset);
        vx_core::Type_string name = meta->name();
        vx_core::vx_ref_plus(name);
        vx_core::Type_string content = meta->content();
        vx_core::vx_ref_plus(content);
        vx_core::Type_string scharset = vx_core::f_if_2(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({charset}, [charset]() {
                vx_core::Type_boolean output_1 = vx_core::f_ne(vx_core::vx_new_string(""), charset);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({charset}, [charset]() {
                vx_core::Type_string output_1 = vx_web_html::f_string_from_propname_val(vx_core::vx_new_string("charset"), charset);
                return output_1;
              })
            )
          })
        );
        vx_core::vx_ref_plus(scharset);
        vx_core::Type_string sname = vx_core::f_if_2(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({name}, [name]() {
                vx_core::Type_boolean output_1 = vx_core::f_ne(vx_core::vx_new_string(""), name);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({name}, [name]() {
                vx_core::Type_string output_1 = vx_web_html::f_string_from_propname_val(vx_core::vx_new_string("name"), name);
                return output_1;
              })
            )
          })
        );
        vx_core::vx_ref_plus(sname);
        vx_core::Type_string scontext = vx_core::f_if_2(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({content}, [content]() {
                vx_core::Type_boolean output_1 = vx_core::f_ne(vx_core::vx_new_string(""), content);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({content}, [content]() {
                vx_core::Type_string output_1 = vx_web_html::f_string_from_propname_val(vx_core::vx_new_string("content"), content);
                return output_1;
              })
            )
          })
        );
        vx_core::vx_ref_plus(scontext);
        vx_core::Type_string output_1 = vx_core::f_new(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_anylist, {
            sindent,
            vx_core::vx_new_string("<meta"),
            scharset,
            sname,
            scontext,
            vx_core::vx_new_string(" />")
          })
        );
        vx_core::vx_release_one_except({sindent, charset, name, content, scharset, sname, scontext}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({meta, indent}, output);
    return output;
  }

  // (func string<-meta-indent)
  // class Class_string_from_meta_indent {
    Abstract_string_from_meta_indent::~Abstract_string_from_meta_indent() {}

    Class_string_from_meta_indent::Class_string_from_meta_indent() : Abstract_string_from_meta_indent::Abstract_string_from_meta_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_meta_indent::~Class_string_from_meta_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_meta_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_meta_indent output = vx_web_html::e_string_from_meta_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_meta_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_meta_indent output = vx_web_html::e_string_from_meta_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_meta_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-meta-indent", // name
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

    vx_core::Type_constdef Class_string_from_meta_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_meta_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-meta-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_meta_indent::vx_empty() const {return vx_web_html::e_string_from_meta_indent;}
    vx_core::Type_any Class_string_from_meta_indent::vx_type() const {return vx_web_html::t_string_from_meta_indent;}
    vx_core::Type_msgblock Class_string_from_meta_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_meta_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_meta_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_meta meta = vx_core::vx_any_from_any(vx_web_html::t_meta, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_meta_indent(meta, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-node-indent)
  vx_core::Type_string f_string_from_node_indent(vx_core::Type_any node, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({node, indent});
    output = vx_core::f_switch(
      vx_core::t_string,
      vx_core::f_type_from_any(node),
      vx_core::vx_new(vx_core::t_thenelselist, {
        vx_core::f_case_1(
          vx_web_html::t_body,
          vx_core::t_any_from_func->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_body_indent(
              vx_core::f_any_from_any(vx_web_html::t_body, node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_details,
          vx_core::t_any_from_func->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_details_indent(
              vx_core::f_any_from_any(vx_web_html::t_details, node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_div,
          vx_core::t_any_from_func->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_div_indent(
              vx_core::f_any_from_any(vx_web_html::t_div, node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_h1,
          vx_core::t_any_from_func->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_h1_indent(
              vx_core::f_any_from_any(vx_web_html::t_h1, node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_h2,
          vx_core::t_any_from_func->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_h2_indent(
              vx_core::f_any_from_any(vx_web_html::t_h2, node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_h3,
          vx_core::t_any_from_func->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_h3_indent(
              vx_core::f_any_from_any(vx_web_html::t_h3, node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_head,
          vx_core::t_any_from_func->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_head_indent(
              vx_core::f_any_from_any(vx_web_html::t_head, node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_footer,
          vx_core::t_any_from_func->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_footer_indent(
              vx_core::f_any_from_any(vx_web_html::t_footer, node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_meta,
          vx_core::t_any_from_func->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_meta_indent(
              vx_core::f_any_from_any(vx_web_html::t_meta, node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_p,
          vx_core::t_any_from_func->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_p_indent(
              vx_core::f_any_from_any(vx_web_html::t_p, node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_stylesheet,
          vx_core::t_any_from_func->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_stylesheet_indent(
              vx_core::f_any_from_any(vx_web_html::t_stylesheet, node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_table,
          vx_core::t_any_from_func->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_table_indent(
              vx_core::f_any_from_any(vx_web_html::t_table, node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_title,
          vx_core::t_any_from_func->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_title_indent(
              vx_core::f_any_from_any(vx_web_html::t_title, node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_tbody,
          vx_core::t_any_from_func->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_tbody_indent(
              vx_core::f_any_from_any(vx_web_html::t_tbody, node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_thead,
          vx_core::t_any_from_func->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_thead_indent(
              vx_core::f_any_from_any(vx_web_html::t_thead, node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_td,
          vx_core::t_any_from_func->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_td_indent(
              vx_core::f_any_from_any(vx_web_html::t_td, node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_tr,
          vx_core::t_any_from_func->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_tr_indent(
              vx_core::f_any_from_any(vx_web_html::t_tr, node),
              indent
            );
            return output_1;
          })
        )
      })
    );
    vx_core::vx_release_one_except({node, indent}, output);
    return output;
  }

  // (func string<-node-indent)
  // class Class_string_from_node_indent {
    Abstract_string_from_node_indent::~Abstract_string_from_node_indent() {}

    Class_string_from_node_indent::Class_string_from_node_indent() : Abstract_string_from_node_indent::Abstract_string_from_node_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_node_indent::~Class_string_from_node_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_node_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_node_indent output = vx_web_html::e_string_from_node_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_node_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_node_indent output = vx_web_html::e_string_from_node_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_node_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-node-indent", // name
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

    vx_core::Type_constdef Class_string_from_node_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_node_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-node-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_node_indent::vx_empty() const {return vx_web_html::e_string_from_node_indent;}
    vx_core::Type_any Class_string_from_node_indent::vx_type() const {return vx_web_html::t_string_from_node_indent;}
    vx_core::Type_msgblock Class_string_from_node_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_node_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_node_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any node = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_node_indent(node, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-nodelist-indent)
  vx_core::Type_string f_string_from_nodelist_indent(vx_core::Type_list nodelist, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({nodelist, indent});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({nodelist, indent}, [nodelist, indent]() {
        vx_core::Type_stringlist textlist = vx_core::f_list_from_list(
          vx_core::t_stringlist,
          nodelist,
          vx_core::t_any_from_any->vx_fn_new({indent}, [indent](vx_core::Type_any node_any) {
            vx_web_html::Type_node node = vx_core::vx_any_from_any(vx_web_html::t_node, node_any);
            vx_core::Type_any output_1 = 
              vx_web_html::f_string_from_node_indent(node, indent);
            return output_1;
          })
        );
        vx_core::vx_ref_plus(textlist);
        vx_core::Type_string output_1 = vx_type::f_string_from_stringlist_join(textlist, vx_core::vx_new_string(""));
        vx_core::vx_release_one_except(textlist, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({nodelist, indent}, output);
    return output;
  }

  // (func string<-nodelist-indent)
  // class Class_string_from_nodelist_indent {
    Abstract_string_from_nodelist_indent::~Abstract_string_from_nodelist_indent() {}

    Class_string_from_nodelist_indent::Class_string_from_nodelist_indent() : Abstract_string_from_nodelist_indent::Abstract_string_from_nodelist_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_nodelist_indent::~Class_string_from_nodelist_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_nodelist_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_nodelist_indent output = vx_web_html::e_string_from_nodelist_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_nodelist_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_nodelist_indent output = vx_web_html::e_string_from_nodelist_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_nodelist_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-nodelist-indent", // name
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

    vx_core::Type_constdef Class_string_from_nodelist_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_nodelist_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-nodelist-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_nodelist_indent::vx_empty() const {return vx_web_html::e_string_from_nodelist_indent;}
    vx_core::Type_any Class_string_from_nodelist_indent::vx_type() const {return vx_web_html::t_string_from_nodelist_indent;}
    vx_core::Type_msgblock Class_string_from_nodelist_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_nodelist_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_nodelist_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list nodelist = vx_core::vx_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_nodelist_indent(nodelist, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-nodelist-tag-prop-indent)
  vx_core::Type_string f_string_from_nodelist_tag_prop_indent(vx_core::Type_list nodes, vx_core::Type_string tag, vx_core::Type_string prop, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({nodes, tag, prop, indent});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({nodes, indent, tag, prop}, [nodes, indent, tag, prop]() {
        vx_core::Type_string text = vx_web_html::f_string_from_nodelist_indent(
          nodes,
          vx_core::f_plus1(indent)
        );
        vx_core::vx_ref_plus(text);
        vx_core::Type_string sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::vx_ref_plus(sindent);
        vx_core::Type_string eindent = vx_core::f_if_2(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_thenelselist, {
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({text}, [text]() {
                vx_core::Type_boolean output_1 = vx_core::f_is_empty(text);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({}, []() {
                vx_core::Type_string output_1 = vx_core::vx_new_string("");
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func->vx_fn_new({sindent}, [sindent]() {
                vx_core::Type_boolean output_1 = vx_core::f_is_empty(sindent);
                return output_1;
              }),
              vx_core::t_any_from_func->vx_fn_new({}, []() {
                vx_core::Type_string output_1 = vx_core::c_newline;
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func->vx_fn_new({sindent}, [sindent]() {
                vx_core::Type_any output_1 = sindent;
                return output_1;
              })
            )
          })
        );
        vx_core::vx_ref_plus(eindent);
        vx_core::Type_string output_1 = vx_core::f_new(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_anylist, {
            sindent,
            vx_core::vx_new_string("<"),
            tag,
            prop,
            vx_core::vx_new_string(">"),
            text,
            eindent,
            vx_core::vx_new_string("</"),
            tag,
            vx_core::vx_new_string(">")
          })
        );
        vx_core::vx_release_one_except({text, sindent, eindent}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({nodes, tag, prop, indent}, output);
    return output;
  }

  // (func string<-nodelist-tag-prop-indent)
  // class Class_string_from_nodelist_tag_prop_indent {
    Abstract_string_from_nodelist_tag_prop_indent::~Abstract_string_from_nodelist_tag_prop_indent() {}

    Class_string_from_nodelist_tag_prop_indent::Class_string_from_nodelist_tag_prop_indent() : Abstract_string_from_nodelist_tag_prop_indent::Abstract_string_from_nodelist_tag_prop_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_nodelist_tag_prop_indent::~Class_string_from_nodelist_tag_prop_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_nodelist_tag_prop_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_nodelist_tag_prop_indent output = vx_web_html::e_string_from_nodelist_tag_prop_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_nodelist_tag_prop_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_nodelist_tag_prop_indent output = vx_web_html::e_string_from_nodelist_tag_prop_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_nodelist_tag_prop_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-nodelist-tag-prop-indent", // name
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

    vx_core::Type_constdef Class_string_from_nodelist_tag_prop_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_nodelist_tag_prop_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-nodelist-tag-prop-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_nodelist_tag_prop_indent::vx_empty() const {return vx_web_html::e_string_from_nodelist_tag_prop_indent;}
    vx_core::Type_any Class_string_from_nodelist_tag_prop_indent::vx_type() const {return vx_web_html::t_string_from_nodelist_tag_prop_indent;}
    vx_core::Type_msgblock Class_string_from_nodelist_tag_prop_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_nodelist_tag_prop_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_nodelist_tag_prop_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_list nodes = vx_core::vx_any_from_any(vx_core::t_list, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string tag = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_string prop = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(2)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(3)));
      output = vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, tag, prop, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-p-indent)
  vx_core::Type_string f_string_from_p_indent(vx_web_html::Type_p p, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({p, indent});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({indent, p}, [indent, p]() {
        vx_core::Type_string sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::vx_ref_plus(sindent);
        vx_core::Type_string text = vx_web_html::f_htmlstring_from_string(
          p->text()
        );
        vx_core::vx_ref_plus(text);
        vx_core::Type_string sid = vx_web_html::f_string_from_propname_val(
          vx_core::vx_new_string("id"),
          p->id()
        );
        vx_core::vx_ref_plus(sid);
        vx_core::Type_string sclass = vx_web_html::f_string_from_propstyle(
          p->style()
        );
        vx_core::vx_ref_plus(sclass);
        vx_core::Type_string sstyle = vx_web_html::f_string_from_propstyleunique(
          p->style_unique()
        );
        vx_core::vx_ref_plus(sstyle);
        vx_core::Type_string output_1 = vx_core::f_new(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_anylist, {
            sindent,
            vx_core::vx_new_string("<p"),
            sid,
            sclass,
            sstyle,
            vx_core::vx_new_string(">"),
            text,
            vx_core::vx_new_string("</p>")
          })
        );
        vx_core::vx_release_one_except({sindent, text, sid, sclass, sstyle}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({p, indent}, output);
    return output;
  }

  // (func string<-p-indent)
  // class Class_string_from_p_indent {
    Abstract_string_from_p_indent::~Abstract_string_from_p_indent() {}

    Class_string_from_p_indent::Class_string_from_p_indent() : Abstract_string_from_p_indent::Abstract_string_from_p_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_p_indent::~Class_string_from_p_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_p_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_p_indent output = vx_web_html::e_string_from_p_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_p_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_p_indent output = vx_web_html::e_string_from_p_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_p_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-p-indent", // name
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

    vx_core::Type_constdef Class_string_from_p_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_p_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-p-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_p_indent::vx_empty() const {return vx_web_html::e_string_from_p_indent;}
    vx_core::Type_any Class_string_from_p_indent::vx_type() const {return vx_web_html::t_string_from_p_indent;}
    vx_core::Type_msgblock Class_string_from_p_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_p_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_p_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_p p = vx_core::vx_any_from_any(vx_web_html::t_p, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_p_indent(p, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-propname-val)
  vx_core::Type_string f_string_from_propname_val(vx_core::Type_string key, vx_core::Type_string val) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({key, val});
    output = vx_core::f_if(
      vx_core::t_string,
      vx_core::f_notempty(val),
      vx_core::f_new(
        vx_core::t_string,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(" "),
          key,
          vx_core::vx_new_string("="),
          vx_core::c_quote,
          val,
          vx_core::c_quote
        })
      )
    );
    vx_core::vx_release_one_except({key, val}, output);
    return output;
  }

  // (func string<-propname-val)
  // class Class_string_from_propname_val {
    Abstract_string_from_propname_val::~Abstract_string_from_propname_val() {}

    Class_string_from_propname_val::Class_string_from_propname_val() : Abstract_string_from_propname_val::Abstract_string_from_propname_val() {
      vx_core::refcount += 1;
    }

    Class_string_from_propname_val::~Class_string_from_propname_val() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_propname_val::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_propname_val output = vx_web_html::e_string_from_propname_val;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_propname_val::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_propname_val output = vx_web_html::e_string_from_propname_val;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_propname_val::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-propname-val", // name
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

    vx_core::Type_constdef Class_string_from_propname_val::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_propname_val::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-propname-val", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_propname_val::vx_empty() const {return vx_web_html::e_string_from_propname_val;}
    vx_core::Type_any Class_string_from_propname_val::vx_type() const {return vx_web_html::t_string_from_propname_val;}
    vx_core::Type_msgblock Class_string_from_propname_val::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_propname_val::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_propname_val::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string key = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string val = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_propname_val(key, val);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-propstyle)
  vx_core::Type_string f_string_from_propstyle(vx_web_html::Type_style style) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(style);
    output = vx_core::f_if_2(
      vx_core::t_string,
      vx_core::vx_new(vx_core::t_thenelselist, {
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({style}, [style]() {
            vx_core::Type_boolean output_1 = vx_core::f_notempty_1(style);
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({style}, [style]() {
            vx_core::Type_string output_1 = vx_core::f_new(
              vx_core::t_string,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(" class="),
                vx_core::c_quote,
                vx_type::f_string_from_string_start(
                  style->name(),
                  vx_core::vx_new_int(2)
                ),
                vx_core::c_quote
              })
            );
            return output_1;
          })
        )
      })
    );
    vx_core::vx_release_one_except(style, output);
    return output;
  }

  // (func string<-propstyle)
  // class Class_string_from_propstyle {
    Abstract_string_from_propstyle::~Abstract_string_from_propstyle() {}

    Class_string_from_propstyle::Class_string_from_propstyle() : Abstract_string_from_propstyle::Abstract_string_from_propstyle() {
      vx_core::refcount += 1;
    }

    Class_string_from_propstyle::~Class_string_from_propstyle() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_propstyle::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_propstyle output = vx_web_html::e_string_from_propstyle;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_propstyle::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_propstyle output = vx_web_html::e_string_from_propstyle;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_propstyle::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-propstyle", // name
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

    vx_core::Type_constdef Class_string_from_propstyle::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_propstyle::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-propstyle", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_propstyle::vx_empty() const {return vx_web_html::e_string_from_propstyle;}
    vx_core::Type_any Class_string_from_propstyle::vx_type() const {return vx_web_html::t_string_from_propstyle;}
    vx_core::Type_msgblock Class_string_from_propstyle::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_propstyle::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_string_from_propstyle::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_string_from_propstyle::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_style inputval = vx_core::vx_any_from_any(vx_web_html::t_style, val);
      output = vx_web_html::f_string_from_propstyle(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_string_from_propstyle::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_style style = vx_core::vx_any_from_any(vx_web_html::t_style, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_string_from_propstyle(style);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-propstyle-stylelist)
  vx_core::Type_string f_string_from_propstyle_stylelist(vx_web_html::Type_style style, vx_web_html::Type_stylelist stylelist) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({style, stylelist});
    output = vx_core::f_if_2(
      vx_core::t_string,
      vx_core::vx_new(vx_core::t_thenelselist, {
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({style}, [style]() {
            vx_core::Type_boolean output_1 = vx_core::f_notempty_1(style);
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({style}, [style]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_propstyle(style);
            return output_1;
          })
        ),
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({stylelist}, [stylelist]() {
            vx_core::Type_boolean output_1 = vx_core::f_notempty_1(stylelist);
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({stylelist}, [stylelist]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_propstylelist(stylelist);
            return output_1;
          })
        )
      })
    );
    vx_core::vx_release_one_except({style, stylelist}, output);
    return output;
  }

  // (func string<-propstyle-stylelist)
  // class Class_string_from_propstyle_stylelist {
    Abstract_string_from_propstyle_stylelist::~Abstract_string_from_propstyle_stylelist() {}

    Class_string_from_propstyle_stylelist::Class_string_from_propstyle_stylelist() : Abstract_string_from_propstyle_stylelist::Abstract_string_from_propstyle_stylelist() {
      vx_core::refcount += 1;
    }

    Class_string_from_propstyle_stylelist::~Class_string_from_propstyle_stylelist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_propstyle_stylelist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_propstyle_stylelist output = vx_web_html::e_string_from_propstyle_stylelist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_propstyle_stylelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_propstyle_stylelist output = vx_web_html::e_string_from_propstyle_stylelist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_propstyle_stylelist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-propstyle-stylelist", // name
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

    vx_core::Type_constdef Class_string_from_propstyle_stylelist::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_propstyle_stylelist::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-propstyle-stylelist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_propstyle_stylelist::vx_empty() const {return vx_web_html::e_string_from_propstyle_stylelist;}
    vx_core::Type_any Class_string_from_propstyle_stylelist::vx_type() const {return vx_web_html::t_string_from_propstyle_stylelist;}
    vx_core::Type_msgblock Class_string_from_propstyle_stylelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_propstyle_stylelist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_propstyle_stylelist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_style style = vx_core::vx_any_from_any(vx_web_html::t_style, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_web_html::Type_stylelist stylelist = vx_core::vx_any_from_any(vx_web_html::t_stylelist, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_propstyle_stylelist(style, stylelist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-propstylelist)
  vx_core::Type_string f_string_from_propstylelist(vx_web_html::Type_stylelist stylelist) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(stylelist);
    output = vx_core::f_if_2(
      vx_core::t_string,
      vx_core::vx_new(vx_core::t_thenelselist, {
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({stylelist}, [stylelist]() {
            vx_core::Type_boolean output_1 = vx_core::f_notempty_1(stylelist);
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({stylelist}, [stylelist]() {
            vx_core::Type_string output_1 = vx_core::f_let(
              vx_core::t_string,
              vx_core::t_any_from_func->vx_fn_new({stylelist}, [stylelist]() {
                vx_core::Type_stringlist namelist = vx_core::f_list_from_list(
                  vx_core::t_stringlist,
                  stylelist,
                  vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any item_any) {
                    vx_web_html::Type_style item = vx_core::vx_any_from_any(vx_web_html::t_style, item_any);
                    vx_core::Type_any output_1 = 
                      vx_type::f_string_from_string_start(
                        item->name(),
                        vx_core::vx_new_int(2)
                      );
                    return output_1;
                  })
                );
                vx_core::vx_ref_plus(namelist);
                vx_core::Type_string joined = vx_type::f_string_from_stringlist_join(namelist, vx_core::vx_new_string(" "));
                vx_core::vx_ref_plus(joined);
                vx_core::Type_string output_1 = vx_core::f_if(
                  vx_core::t_string,
                  vx_core::f_ne(vx_core::vx_new_string(""), joined),
                  vx_core::f_new(
                    vx_core::t_string,
                    vx_core::vx_new(vx_core::t_anylist, {
                      vx_core::vx_new_string(" class="),
                      vx_core::c_quote,
                      joined,
                      vx_core::c_quote
                    })
                  )
                );
                vx_core::vx_release_one_except({namelist, joined}, output_1);
                return output_1;
              })
            );
            return output_1;
          })
        )
      })
    );
    vx_core::vx_release_one_except(stylelist, output);
    return output;
  }

  // (func string<-propstylelist)
  // class Class_string_from_propstylelist {
    Abstract_string_from_propstylelist::~Abstract_string_from_propstylelist() {}

    Class_string_from_propstylelist::Class_string_from_propstylelist() : Abstract_string_from_propstylelist::Abstract_string_from_propstylelist() {
      vx_core::refcount += 1;
    }

    Class_string_from_propstylelist::~Class_string_from_propstylelist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_propstylelist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_propstylelist output = vx_web_html::e_string_from_propstylelist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_propstylelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_propstylelist output = vx_web_html::e_string_from_propstylelist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_propstylelist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-propstylelist", // name
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

    vx_core::Type_constdef Class_string_from_propstylelist::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_propstylelist::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-propstylelist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_propstylelist::vx_empty() const {return vx_web_html::e_string_from_propstylelist;}
    vx_core::Type_any Class_string_from_propstylelist::vx_type() const {return vx_web_html::t_string_from_propstylelist;}
    vx_core::Type_msgblock Class_string_from_propstylelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_propstylelist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_string_from_propstylelist::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_string_from_propstylelist::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_stylelist inputval = vx_core::vx_any_from_any(vx_web_html::t_stylelist, val);
      output = vx_web_html::f_string_from_propstylelist(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_string_from_propstylelist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_stylelist stylelist = vx_core::vx_any_from_any(vx_web_html::t_stylelist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_string_from_propstylelist(stylelist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-propstyleunique)
  vx_core::Type_string f_string_from_propstyleunique(vx_web_html::Type_style style) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(style);
    output = vx_core::f_if_2(
      vx_core::t_string,
      vx_core::vx_new(vx_core::t_thenelselist, {
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({style}, [style]() {
            vx_core::Type_boolean output_1 = vx_core::f_notempty_1(style);
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({style}, [style]() {
            vx_core::Type_string output_1 = vx_core::f_new(
              vx_core::t_string,
              vx_core::vx_new(vx_core::t_anylist, {
                vx_core::vx_new_string(" style="),
                vx_core::c_quote,
                vx_web_html::f_string_from_stylepropmap_indent(
                  style->props(),
                  vx_core::vx_new_int(0)
                ),
                vx_core::c_quote
              })
            );
            return output_1;
          })
        )
      })
    );
    vx_core::vx_release_one_except(style, output);
    return output;
  }

  // (func string<-propstyleunique)
  // class Class_string_from_propstyleunique {
    Abstract_string_from_propstyleunique::~Abstract_string_from_propstyleunique() {}

    Class_string_from_propstyleunique::Class_string_from_propstyleunique() : Abstract_string_from_propstyleunique::Abstract_string_from_propstyleunique() {
      vx_core::refcount += 1;
    }

    Class_string_from_propstyleunique::~Class_string_from_propstyleunique() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_propstyleunique::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_propstyleunique output = vx_web_html::e_string_from_propstyleunique;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_propstyleunique::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_propstyleunique output = vx_web_html::e_string_from_propstyleunique;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_propstyleunique::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-propstyleunique", // name
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

    vx_core::Type_constdef Class_string_from_propstyleunique::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_propstyleunique::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-propstyleunique", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_propstyleunique::vx_empty() const {return vx_web_html::e_string_from_propstyleunique;}
    vx_core::Type_any Class_string_from_propstyleunique::vx_type() const {return vx_web_html::t_string_from_propstyleunique;}
    vx_core::Type_msgblock Class_string_from_propstyleunique::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_propstyleunique::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_string_from_propstyleunique::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_string_from_propstyleunique::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_style inputval = vx_core::vx_any_from_any(vx_web_html::t_style, val);
      output = vx_web_html::f_string_from_propstyleunique(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_string_from_propstyleunique::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_style style = vx_core::vx_any_from_any(vx_web_html::t_style, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_string_from_propstyleunique(style);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-style-indent)
  vx_core::Type_string f_string_from_style_indent(vx_web_html::Type_style style, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({style, indent});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({indent, style}, [indent, style]() {
        vx_core::Type_string sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::vx_ref_plus(sindent);
        vx_core::Type_string name = style->name();
        vx_core::vx_ref_plus(name);
        vx_web_html::Type_propmap propmap = style->props();
        vx_core::vx_ref_plus(propmap);
        vx_core::Type_string stext = vx_web_html::f_string_from_stylepropmap_indent(
          propmap,
          vx_core::f_plus1(indent)
        );
        vx_core::vx_ref_plus(stext);
        vx_core::Type_string output_1 = vx_core::f_new(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_anylist, {
            sindent,
            name,
            vx_core::vx_new_string(" {"),
            stext,
            sindent,
            vx_core::vx_new_string("}")
          })
        );
        vx_core::vx_release_one_except({sindent, name, propmap, stext}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({style, indent}, output);
    return output;
  }

  // (func string<-style-indent)
  // class Class_string_from_style_indent {
    Abstract_string_from_style_indent::~Abstract_string_from_style_indent() {}

    Class_string_from_style_indent::Class_string_from_style_indent() : Abstract_string_from_style_indent::Abstract_string_from_style_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_style_indent::~Class_string_from_style_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_style_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_style_indent output = vx_web_html::e_string_from_style_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_style_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_style_indent output = vx_web_html::e_string_from_style_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_style_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-style-indent", // name
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

    vx_core::Type_constdef Class_string_from_style_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_style_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-style-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_style_indent::vx_empty() const {return vx_web_html::e_string_from_style_indent;}
    vx_core::Type_any Class_string_from_style_indent::vx_type() const {return vx_web_html::t_string_from_style_indent;}
    vx_core::Type_msgblock Class_string_from_style_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_style_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_style_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_style style = vx_core::vx_any_from_any(vx_web_html::t_style, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_style_indent(style, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-stylelist-indent)
  vx_core::Type_string f_string_from_stylelist_indent(vx_web_html::Type_stylelist stylelist, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({stylelist, indent});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({stylelist, indent}, [stylelist, indent]() {
        vx_core::Type_stringlist sstyles = vx_core::f_list_from_list(
          vx_core::t_stringlist,
          stylelist,
          vx_core::t_any_from_any->vx_fn_new({indent}, [indent](vx_core::Type_any substyle_any) {
            vx_web_html::Type_style substyle = vx_core::vx_any_from_any(vx_web_html::t_style, substyle_any);
            vx_core::Type_any output_1 = 
              vx_web_html::f_string_from_style_indent(substyle, indent);
            return output_1;
          })
        );
        vx_core::vx_ref_plus(sstyles);
        vx_core::Type_string output_1 = vx_type::f_string_from_stringlist_join(sstyles, vx_core::vx_new_string(""));
        vx_core::vx_release_one_except(sstyles, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({stylelist, indent}, output);
    return output;
  }

  // (func string<-stylelist-indent)
  // class Class_string_from_stylelist_indent {
    Abstract_string_from_stylelist_indent::~Abstract_string_from_stylelist_indent() {}

    Class_string_from_stylelist_indent::Class_string_from_stylelist_indent() : Abstract_string_from_stylelist_indent::Abstract_string_from_stylelist_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_stylelist_indent::~Class_string_from_stylelist_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_stylelist_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_stylelist_indent output = vx_web_html::e_string_from_stylelist_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_stylelist_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_stylelist_indent output = vx_web_html::e_string_from_stylelist_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_stylelist_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-stylelist-indent", // name
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

    vx_core::Type_constdef Class_string_from_stylelist_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_stylelist_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-stylelist-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_stylelist_indent::vx_empty() const {return vx_web_html::e_string_from_stylelist_indent;}
    vx_core::Type_any Class_string_from_stylelist_indent::vx_type() const {return vx_web_html::t_string_from_stylelist_indent;}
    vx_core::Type_msgblock Class_string_from_stylelist_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_stylelist_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_stylelist_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_stylelist stylelist = vx_core::vx_any_from_any(vx_web_html::t_stylelist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_stylelist_indent(stylelist, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-stylepropmap-indent)
  vx_core::Type_string f_string_from_stylepropmap_indent(vx_web_html::Type_propmap propmap, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({propmap, indent});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({indent, propmap}, [indent, propmap]() {
        vx_core::Type_string sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::vx_ref_plus(sindent);
        vx_core::Type_stringlist sprops = vx_core::f_list_from_map(
          vx_core::t_stringlist,
          propmap,
          vx_core::t_any_from_key_value->vx_fn_new({sindent}, [sindent](vx_core::Type_any key_any, vx_core::Type_any val_any) {
            vx_core::Type_string key = vx_core::vx_any_from_any(vx_core::t_string, key_any);
            vx_core::Type_string val = vx_core::vx_any_from_any(vx_core::t_string, val_any);
            vx_core::Type_any output_1 = 
              vx_core::f_new(
                vx_core::t_string,
                vx_core::vx_new(vx_core::t_anylist, {
                  sindent,
                  key,
                  vx_core::vx_new_string(": "),
                  val,
                  vx_core::vx_new_string(";")
                })
              );
            return output_1;
          })
        );
        vx_core::vx_ref_plus(sprops);
        vx_core::Type_string output_1 = vx_type::f_string_from_stringlist_join(sprops, vx_core::vx_new_string(""));
        vx_core::vx_release_one_except({sindent, sprops}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({propmap, indent}, output);
    return output;
  }

  // (func string<-stylepropmap-indent)
  // class Class_string_from_stylepropmap_indent {
    Abstract_string_from_stylepropmap_indent::~Abstract_string_from_stylepropmap_indent() {}

    Class_string_from_stylepropmap_indent::Class_string_from_stylepropmap_indent() : Abstract_string_from_stylepropmap_indent::Abstract_string_from_stylepropmap_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_stylepropmap_indent::~Class_string_from_stylepropmap_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_stylepropmap_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_stylepropmap_indent output = vx_web_html::e_string_from_stylepropmap_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_stylepropmap_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_stylepropmap_indent output = vx_web_html::e_string_from_stylepropmap_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_stylepropmap_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-stylepropmap-indent", // name
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

    vx_core::Type_constdef Class_string_from_stylepropmap_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_stylepropmap_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-stylepropmap-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_stylepropmap_indent::vx_empty() const {return vx_web_html::e_string_from_stylepropmap_indent;}
    vx_core::Type_any Class_string_from_stylepropmap_indent::vx_type() const {return vx_web_html::t_string_from_stylepropmap_indent;}
    vx_core::Type_msgblock Class_string_from_stylepropmap_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_stylepropmap_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_stylepropmap_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_propmap propmap = vx_core::vx_any_from_any(vx_web_html::t_propmap, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_stylepropmap_indent(propmap, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-stylesheet-indent)
  vx_core::Type_string f_string_from_stylesheet_indent(vx_web_html::Type_stylesheet stylesheet, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({stylesheet, indent});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({stylesheet, indent}, [stylesheet, indent]() {
        vx_core::Type_string text = vx_web_html::f_string_from_stylelist_indent(
          stylesheet->styles(),
          vx_core::f_plus1(indent)
        );
        vx_core::vx_ref_plus(text);
        vx_core::Type_string sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::vx_ref_plus(sindent);
        vx_core::Type_string eindent = vx_core::f_if(
          vx_core::t_string,
          vx_core::f_notempty(text),
          sindent
        );
        vx_core::vx_ref_plus(eindent);
        vx_core::Type_string output_1 = vx_core::f_new(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_anylist, {
            sindent,
            vx_core::vx_new_string("<style>"),
            text,
            eindent,
            vx_core::vx_new_string("</style>")
          })
        );
        vx_core::vx_release_one_except({text, sindent, eindent}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({stylesheet, indent}, output);
    return output;
  }

  // (func string<-stylesheet-indent)
  // class Class_string_from_stylesheet_indent {
    Abstract_string_from_stylesheet_indent::~Abstract_string_from_stylesheet_indent() {}

    Class_string_from_stylesheet_indent::Class_string_from_stylesheet_indent() : Abstract_string_from_stylesheet_indent::Abstract_string_from_stylesheet_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_stylesheet_indent::~Class_string_from_stylesheet_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_stylesheet_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_stylesheet_indent output = vx_web_html::e_string_from_stylesheet_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_stylesheet_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_stylesheet_indent output = vx_web_html::e_string_from_stylesheet_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_stylesheet_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-stylesheet-indent", // name
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

    vx_core::Type_constdef Class_string_from_stylesheet_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_stylesheet_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-stylesheet-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_stylesheet_indent::vx_empty() const {return vx_web_html::e_string_from_stylesheet_indent;}
    vx_core::Type_any Class_string_from_stylesheet_indent::vx_type() const {return vx_web_html::t_string_from_stylesheet_indent;}
    vx_core::Type_msgblock Class_string_from_stylesheet_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_stylesheet_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_stylesheet_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_stylesheet stylesheet = vx_core::vx_any_from_any(vx_web_html::t_stylesheet, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_stylesheet_indent(stylesheet, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-table-indent)
  vx_core::Type_string f_string_from_table_indent(vx_web_html::Type_table table, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({table, indent});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({indent, table}, [indent, table]() {
        vx_core::Type_string sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::vx_ref_plus(sindent);
        vx_core::Type_string sid = vx_web_html::f_string_from_propname_val(
          vx_core::vx_new_string("id"),
          table->id()
        );
        vx_core::vx_ref_plus(sid);
        vx_web_html::Type_thead thead = table->thead();
        vx_core::vx_ref_plus(thead);
        vx_web_html::Type_tbody tbody = table->tbody();
        vx_core::vx_ref_plus(tbody);
        vx_core::Type_string shead = vx_web_html::f_string_from_thead_indent(
          thead,
          vx_core::f_plus1(indent)
        );
        vx_core::vx_ref_plus(shead);
        vx_core::Type_string sbody = vx_web_html::f_string_from_tbody_indent(
          tbody,
          vx_core::f_plus1(indent)
        );
        vx_core::vx_ref_plus(sbody);
        vx_core::Type_string output_1 = vx_core::f_new(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_anylist, {
            sindent,
            vx_core::vx_new_string("<table"),
            sid,
            vx_core::vx_new_string(">"),
            shead,
            sbody,
            sindent,
            vx_core::vx_new_string("</table>")
          })
        );
        vx_core::vx_release_one_except({sindent, sid, thead, tbody, shead, sbody}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({table, indent}, output);
    return output;
  }

  // (func string<-table-indent)
  // class Class_string_from_table_indent {
    Abstract_string_from_table_indent::~Abstract_string_from_table_indent() {}

    Class_string_from_table_indent::Class_string_from_table_indent() : Abstract_string_from_table_indent::Abstract_string_from_table_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_table_indent::~Class_string_from_table_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_table_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_table_indent output = vx_web_html::e_string_from_table_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_table_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_table_indent output = vx_web_html::e_string_from_table_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_table_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-table-indent", // name
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

    vx_core::Type_constdef Class_string_from_table_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_table_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-table-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_table_indent::vx_empty() const {return vx_web_html::e_string_from_table_indent;}
    vx_core::Type_any Class_string_from_table_indent::vx_type() const {return vx_web_html::t_string_from_table_indent;}
    vx_core::Type_msgblock Class_string_from_table_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_table_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_table_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_table table = vx_core::vx_any_from_any(vx_web_html::t_table, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_table_indent(table, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-tbody-indent)
  vx_core::Type_string f_string_from_tbody_indent(vx_web_html::Type_tbody tbody, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({tbody, indent});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({tbody, indent}, [tbody, indent]() {
        vx_web_html::Type_trlist nodes = tbody->nodes();
        vx_core::vx_ref_plus(nodes);
        vx_core::Type_string output_1 = vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, vx_core::vx_new_string("tbody"), vx_core::vx_new_string(""), indent);
        vx_core::vx_release_one_except(nodes, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({tbody, indent}, output);
    return output;
  }

  // (func string<-tbody-indent)
  // class Class_string_from_tbody_indent {
    Abstract_string_from_tbody_indent::~Abstract_string_from_tbody_indent() {}

    Class_string_from_tbody_indent::Class_string_from_tbody_indent() : Abstract_string_from_tbody_indent::Abstract_string_from_tbody_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_tbody_indent::~Class_string_from_tbody_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_tbody_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_tbody_indent output = vx_web_html::e_string_from_tbody_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_tbody_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_tbody_indent output = vx_web_html::e_string_from_tbody_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_tbody_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-tbody-indent", // name
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

    vx_core::Type_constdef Class_string_from_tbody_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_tbody_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-tbody-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_tbody_indent::vx_empty() const {return vx_web_html::e_string_from_tbody_indent;}
    vx_core::Type_any Class_string_from_tbody_indent::vx_type() const {return vx_web_html::t_string_from_tbody_indent;}
    vx_core::Type_msgblock Class_string_from_tbody_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_tbody_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_tbody_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_tbody tbody = vx_core::vx_any_from_any(vx_web_html::t_tbody, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_tbody_indent(tbody, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-td-indent)
  vx_core::Type_string f_string_from_td_indent(vx_web_html::Type_td td, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({td, indent});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({td, indent}, [td, indent]() {
        vx_web_html::Type_divchildlist nodes = td->nodes();
        vx_core::vx_ref_plus(nodes);
        vx_core::Type_string output_1 = vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, vx_core::vx_new_string("td"), vx_core::vx_new_string(""), indent);
        vx_core::vx_release_one_except(nodes, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({td, indent}, output);
    return output;
  }

  // (func string<-td-indent)
  // class Class_string_from_td_indent {
    Abstract_string_from_td_indent::~Abstract_string_from_td_indent() {}

    Class_string_from_td_indent::Class_string_from_td_indent() : Abstract_string_from_td_indent::Abstract_string_from_td_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_td_indent::~Class_string_from_td_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_td_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_td_indent output = vx_web_html::e_string_from_td_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_td_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_td_indent output = vx_web_html::e_string_from_td_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_td_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-td-indent", // name
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

    vx_core::Type_constdef Class_string_from_td_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_td_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-td-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_td_indent::vx_empty() const {return vx_web_html::e_string_from_td_indent;}
    vx_core::Type_any Class_string_from_td_indent::vx_type() const {return vx_web_html::t_string_from_td_indent;}
    vx_core::Type_msgblock Class_string_from_td_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_td_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_td_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_td td = vx_core::vx_any_from_any(vx_web_html::t_td, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_td_indent(td, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-thead-indent)
  vx_core::Type_string f_string_from_thead_indent(vx_web_html::Type_thead thead, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({thead, indent});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({thead, indent}, [thead, indent]() {
        vx_web_html::Type_trlist nodes = thead->nodes();
        vx_core::vx_ref_plus(nodes);
        vx_core::Type_string output_1 = vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, vx_core::vx_new_string("thead"), vx_core::vx_new_string(""), indent);
        vx_core::vx_release_one_except(nodes, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({thead, indent}, output);
    return output;
  }

  // (func string<-thead-indent)
  // class Class_string_from_thead_indent {
    Abstract_string_from_thead_indent::~Abstract_string_from_thead_indent() {}

    Class_string_from_thead_indent::Class_string_from_thead_indent() : Abstract_string_from_thead_indent::Abstract_string_from_thead_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_thead_indent::~Class_string_from_thead_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_thead_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_thead_indent output = vx_web_html::e_string_from_thead_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_thead_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_thead_indent output = vx_web_html::e_string_from_thead_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_thead_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-thead-indent", // name
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

    vx_core::Type_constdef Class_string_from_thead_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_thead_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-thead-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_thead_indent::vx_empty() const {return vx_web_html::e_string_from_thead_indent;}
    vx_core::Type_any Class_string_from_thead_indent::vx_type() const {return vx_web_html::t_string_from_thead_indent;}
    vx_core::Type_msgblock Class_string_from_thead_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_thead_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_thead_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_thead thead = vx_core::vx_any_from_any(vx_web_html::t_thead, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_thead_indent(thead, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-title-indent)
  vx_core::Type_string f_string_from_title_indent(vx_web_html::Type_title title, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({title, indent});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({indent, title}, [indent, title]() {
        vx_core::Type_string sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::vx_ref_plus(sindent);
        vx_core::Type_string text = title->text();
        vx_core::vx_ref_plus(text);
        vx_core::Type_string output_1 = vx_core::f_new(
          vx_core::t_string,
          vx_core::vx_new(vx_core::t_anylist, {
            sindent,
            vx_core::vx_new_string("<title>"),
            text,
            vx_core::vx_new_string("</title>")
          })
        );
        vx_core::vx_release_one_except({sindent, text}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({title, indent}, output);
    return output;
  }

  // (func string<-title-indent)
  // class Class_string_from_title_indent {
    Abstract_string_from_title_indent::~Abstract_string_from_title_indent() {}

    Class_string_from_title_indent::Class_string_from_title_indent() : Abstract_string_from_title_indent::Abstract_string_from_title_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_title_indent::~Class_string_from_title_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_title_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_title_indent output = vx_web_html::e_string_from_title_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_title_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_title_indent output = vx_web_html::e_string_from_title_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_title_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-title-indent", // name
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

    vx_core::Type_constdef Class_string_from_title_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_title_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-title-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_title_indent::vx_empty() const {return vx_web_html::e_string_from_title_indent;}
    vx_core::Type_any Class_string_from_title_indent::vx_type() const {return vx_web_html::t_string_from_title_indent;}
    vx_core::Type_msgblock Class_string_from_title_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_title_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_title_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_title title = vx_core::vx_any_from_any(vx_web_html::t_title, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_title_indent(title, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-tr-indent)
  vx_core::Type_string f_string_from_tr_indent(vx_web_html::Type_tr tr, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve({tr, indent});
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({tr, indent}, [tr, indent]() {
        vx_web_html::Type_tdlist nodes = tr->nodes();
        vx_core::vx_ref_plus(nodes);
        vx_core::Type_string output_1 = vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, vx_core::vx_new_string("tr"), vx_core::vx_new_string(""), indent);
        vx_core::vx_release_one_except(nodes, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({tr, indent}, output);
    return output;
  }

  // (func string<-tr-indent)
  // class Class_string_from_tr_indent {
    Abstract_string_from_tr_indent::~Abstract_string_from_tr_indent() {}

    Class_string_from_tr_indent::Class_string_from_tr_indent() : Abstract_string_from_tr_indent::Abstract_string_from_tr_indent() {
      vx_core::refcount += 1;
    }

    Class_string_from_tr_indent::~Class_string_from_tr_indent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_tr_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_tr_indent output = vx_web_html::e_string_from_tr_indent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_tr_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_tr_indent output = vx_web_html::e_string_from_tr_indent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_tr_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-tr-indent", // name
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

    vx_core::Type_constdef Class_string_from_tr_indent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_tr_indent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-tr-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_tr_indent::vx_empty() const {return vx_web_html::e_string_from_tr_indent;}
    vx_core::Type_any Class_string_from_tr_indent::vx_type() const {return vx_web_html::t_string_from_tr_indent;}
    vx_core::Type_msgblock Class_string_from_tr_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_tr_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_tr_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_tr tr = vx_core::vx_any_from_any(vx_web_html::t_tr, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_tr_indent(tr, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-uri)
  vx_core::Type_string f_string_from_uri(vx_core::Type_string uri) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(uri);
    vx_core::vx_release_one_except(uri, output);
    return output;
  }

  // (func string<-uri)
  // class Class_string_from_uri {
    Abstract_string_from_uri::~Abstract_string_from_uri() {}

    Class_string_from_uri::Class_string_from_uri() : Abstract_string_from_uri::Abstract_string_from_uri() {
      vx_core::refcount += 1;
    }

    Class_string_from_uri::~Class_string_from_uri() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_from_uri::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_uri output = vx_web_html::e_string_from_uri;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_uri::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_uri output = vx_web_html::e_string_from_uri;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_uri::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-uri", // name
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

    vx_core::Type_constdef Class_string_from_uri::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_from_uri::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "string<-uri", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_from_uri::vx_empty() const {return vx_web_html::e_string_from_uri;}
    vx_core::Type_any Class_string_from_uri::vx_type() const {return vx_web_html::t_string_from_uri;}
    vx_core::Type_msgblock Class_string_from_uri::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_uri::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_string_from_uri::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_string_from_uri::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_web_html::f_string_from_uri(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_string_from_uri::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string uri = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_string_from_uri(uri);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func style<-stylesheet-name)
  vx_web_html::Type_style f_style_from_stylesheet_name(vx_web_html::Type_stylesheet stylesheet, vx_core::Type_string name) {
    vx_web_html::Type_style output = vx_web_html::e_style;
    vx_core::vx_reserve({stylesheet, name});
    output = vx_core::f_any_from_map(
      vx_web_html::t_style,
      vx_web_html::f_stylemap_from_stylesheet(stylesheet),
      name
    );
    vx_core::vx_release_one_except({stylesheet, name}, output);
    return output;
  }

  // (func style<-stylesheet-name)
  // class Class_style_from_stylesheet_name {
    Abstract_style_from_stylesheet_name::~Abstract_style_from_stylesheet_name() {}

    Class_style_from_stylesheet_name::Class_style_from_stylesheet_name() : Abstract_style_from_stylesheet_name::Abstract_style_from_stylesheet_name() {
      vx_core::refcount += 1;
    }

    Class_style_from_stylesheet_name::~Class_style_from_stylesheet_name() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_style_from_stylesheet_name::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_style_from_stylesheet_name output = vx_web_html::e_style_from_stylesheet_name;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_style_from_stylesheet_name::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_style_from_stylesheet_name output = vx_web_html::e_style_from_stylesheet_name;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_style_from_stylesheet_name::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "style<-stylesheet-name", // name
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

    vx_core::Type_constdef Class_style_from_stylesheet_name::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_style_from_stylesheet_name::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "style<-stylesheet-name", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_style_from_stylesheet_name::vx_empty() const {return vx_web_html::e_style_from_stylesheet_name;}
    vx_core::Type_any Class_style_from_stylesheet_name::vx_type() const {return vx_web_html::t_style_from_stylesheet_name;}
    vx_core::Type_msgblock Class_style_from_stylesheet_name::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_style_from_stylesheet_name::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_style_from_stylesheet_name::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_stylesheet stylesheet = vx_core::vx_any_from_any(vx_web_html::t_stylesheet, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string name = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_style_from_stylesheet_name(stylesheet, name);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func stylemap<-stylelist)
  vx_web_html::Type_stylemap f_stylemap_from_stylelist(vx_web_html::Type_stylelist stylelist) {
    vx_web_html::Type_stylemap output = vx_web_html::e_stylemap;
    vx_core::vx_reserve(stylelist);
    output = vx_core::f_map_from_list(
      vx_web_html::t_stylemap,
      stylelist,
      vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any style_any) {
        vx_web_html::Type_style style = vx_core::vx_any_from_any(vx_web_html::t_style, style_any);
        vx_core::Type_any output_1 = 
          style->name();
        return output_1;
      })
    );
    vx_core::vx_release_one_except(stylelist, output);
    return output;
  }

  // (func stylemap<-stylelist)
  // class Class_stylemap_from_stylelist {
    Abstract_stylemap_from_stylelist::~Abstract_stylemap_from_stylelist() {}

    Class_stylemap_from_stylelist::Class_stylemap_from_stylelist() : Abstract_stylemap_from_stylelist::Abstract_stylemap_from_stylelist() {
      vx_core::refcount += 1;
    }

    Class_stylemap_from_stylelist::~Class_stylemap_from_stylelist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_stylemap_from_stylelist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_stylemap_from_stylelist output = vx_web_html::e_stylemap_from_stylelist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_stylemap_from_stylelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_stylemap_from_stylelist output = vx_web_html::e_stylemap_from_stylelist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_stylemap_from_stylelist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "stylemap<-stylelist", // name
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

    vx_core::Type_constdef Class_stylemap_from_stylelist::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_stylemap_from_stylelist::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "stylemap<-stylelist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_stylemap_from_stylelist::vx_empty() const {return vx_web_html::e_stylemap_from_stylelist;}
    vx_core::Type_any Class_stylemap_from_stylelist::vx_type() const {return vx_web_html::t_stylemap_from_stylelist;}
    vx_core::Type_msgblock Class_stylemap_from_stylelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stylemap_from_stylelist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_stylemap_from_stylelist::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_stylemap_from_stylelist::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_stylelist inputval = vx_core::vx_any_from_any(vx_web_html::t_stylelist, val);
      output = vx_web_html::f_stylemap_from_stylelist(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_stylemap_from_stylelist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_stylelist stylelist = vx_core::vx_any_from_any(vx_web_html::t_stylelist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_stylemap_from_stylelist(stylelist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func stylemap<-stylesheet)
  vx_web_html::Type_stylemap f_stylemap_from_stylesheet(vx_web_html::Type_stylesheet stylesheet) {
    vx_web_html::Type_stylemap output = vx_web_html::e_stylemap;
    vx_core::vx_reserve(stylesheet);
    output = stylesheet->stylemap();
    vx_core::vx_release_one_except(stylesheet, output);
    return output;
  }

  // (func stylemap<-stylesheet)
  // class Class_stylemap_from_stylesheet {
    Abstract_stylemap_from_stylesheet::~Abstract_stylemap_from_stylesheet() {}

    Class_stylemap_from_stylesheet::Class_stylemap_from_stylesheet() : Abstract_stylemap_from_stylesheet::Abstract_stylemap_from_stylesheet() {
      vx_core::refcount += 1;
    }

    Class_stylemap_from_stylesheet::~Class_stylemap_from_stylesheet() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_stylemap_from_stylesheet::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_stylemap_from_stylesheet output = vx_web_html::e_stylemap_from_stylesheet;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_stylemap_from_stylesheet::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_stylemap_from_stylesheet output = vx_web_html::e_stylemap_from_stylesheet;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_stylemap_from_stylesheet::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "stylemap<-stylesheet", // name
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

    vx_core::Type_constdef Class_stylemap_from_stylesheet::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_stylemap_from_stylesheet::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "stylemap<-stylesheet", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_stylemap_from_stylesheet::vx_empty() const {return vx_web_html::e_stylemap_from_stylesheet;}
    vx_core::Type_any Class_stylemap_from_stylesheet::vx_type() const {return vx_web_html::t_stylemap_from_stylesheet;}
    vx_core::Type_msgblock Class_stylemap_from_stylesheet::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stylemap_from_stylesheet::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_stylemap_from_stylesheet::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_stylemap_from_stylesheet::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_stylesheet inputval = vx_core::vx_any_from_any(vx_web_html::t_stylesheet, val);
      output = vx_web_html::f_stylemap_from_stylesheet(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_stylemap_from_stylesheet::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_stylesheet stylesheet = vx_core::vx_any_from_any(vx_web_html::t_stylesheet, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_stylemap_from_stylesheet(stylesheet);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func styles<-stylesheet)
  vx_web_html::Type_stylelist f_styles_from_stylesheet(vx_web_html::Type_stylesheet stylesheet) {
    vx_web_html::Type_stylelist output = vx_web_html::e_stylelist;
    vx_core::vx_reserve(stylesheet);
    output = stylesheet->styles();
    vx_core::vx_release_one_except(stylesheet, output);
    return output;
  }

  // (func styles<-stylesheet)
  // class Class_styles_from_stylesheet {
    Abstract_styles_from_stylesheet::~Abstract_styles_from_stylesheet() {}

    Class_styles_from_stylesheet::Class_styles_from_stylesheet() : Abstract_styles_from_stylesheet::Abstract_styles_from_stylesheet() {
      vx_core::refcount += 1;
    }

    Class_styles_from_stylesheet::~Class_styles_from_stylesheet() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_styles_from_stylesheet::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_styles_from_stylesheet output = vx_web_html::e_styles_from_stylesheet;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_styles_from_stylesheet::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_styles_from_stylesheet output = vx_web_html::e_styles_from_stylesheet;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_styles_from_stylesheet::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "styles<-stylesheet", // name
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

    vx_core::Type_constdef Class_styles_from_stylesheet::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_styles_from_stylesheet::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "styles<-stylesheet", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_styles_from_stylesheet::vx_empty() const {return vx_web_html::e_styles_from_stylesheet;}
    vx_core::Type_any Class_styles_from_stylesheet::vx_type() const {return vx_web_html::t_styles_from_stylesheet;}
    vx_core::Type_msgblock Class_styles_from_stylesheet::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_styles_from_stylesheet::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_styles_from_stylesheet::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_styles_from_stylesheet::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_stylesheet inputval = vx_core::vx_any_from_any(vx_web_html::t_stylesheet, val);
      output = vx_web_html::f_styles_from_stylesheet(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_styles_from_stylesheet::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_stylesheet stylesheet = vx_core::vx_any_from_any(vx_web_html::t_stylesheet, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_styles_from_stylesheet(stylesheet);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func stylesheet-loadmap)
  vx_web_html::Type_stylesheet f_stylesheet_loadmap(vx_web_html::Type_stylesheet stylesheet) {
    vx_web_html::Type_stylesheet output = vx_web_html::e_stylesheet;
    vx_core::vx_reserve(stylesheet);
    output = vx_core::f_copy(
      vx_web_html::t_stylesheet,
      stylesheet,
      vx_core::vx_new(vx_core::t_anylist, {
        vx_core::vx_new_string(":stylemap"),
        vx_web_html::f_stylemap_from_stylelist(
          stylesheet->styles()
        )
      })
    );
    vx_core::vx_release_one_except(stylesheet, output);
    return output;
  }

  // (func stylesheet-loadmap)
  // class Class_stylesheet_loadmap {
    Abstract_stylesheet_loadmap::~Abstract_stylesheet_loadmap() {}

    Class_stylesheet_loadmap::Class_stylesheet_loadmap() : Abstract_stylesheet_loadmap::Abstract_stylesheet_loadmap() {
      vx_core::refcount += 1;
    }

    Class_stylesheet_loadmap::~Class_stylesheet_loadmap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_stylesheet_loadmap::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_stylesheet_loadmap output = vx_web_html::e_stylesheet_loadmap;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_stylesheet_loadmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_stylesheet_loadmap output = vx_web_html::e_stylesheet_loadmap;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_stylesheet_loadmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "stylesheet-loadmap", // name
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

    vx_core::Type_constdef Class_stylesheet_loadmap::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_stylesheet_loadmap::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "stylesheet-loadmap", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_stylesheet_loadmap::vx_empty() const {return vx_web_html::e_stylesheet_loadmap;}
    vx_core::Type_any Class_stylesheet_loadmap::vx_type() const {return vx_web_html::t_stylesheet_loadmap;}
    vx_core::Type_msgblock Class_stylesheet_loadmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stylesheet_loadmap::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_stylesheet_loadmap::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_stylesheet_loadmap::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_stylesheet inputval = vx_core::vx_any_from_any(vx_web_html::t_stylesheet, val);
      output = vx_web_html::f_stylesheet_loadmap(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_stylesheet_loadmap::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_web_html::Type_stylesheet stylesheet = vx_core::vx_any_from_any(vx_web_html::t_stylesheet, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_stylesheet_loadmap(stylesheet);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func uri<-string)
  vx_core::Type_string f_uri_from_string(vx_core::Type_string text) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(text);
    vx_core::vx_release_one_except(text, output);
    return output;
  }

  // (func uri<-string)
  // class Class_uri_from_string {
    Abstract_uri_from_string::~Abstract_uri_from_string() {}

    Class_uri_from_string::Class_uri_from_string() : Abstract_uri_from_string::Abstract_uri_from_string() {
      vx_core::refcount += 1;
    }

    Class_uri_from_string::~Class_uri_from_string() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_uri_from_string::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_uri_from_string output = vx_web_html::e_uri_from_string;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_uri_from_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_uri_from_string output = vx_web_html::e_uri_from_string;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_uri_from_string::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "uri<-string", // name
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

    vx_core::Type_constdef Class_uri_from_string::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_uri_from_string::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "uri<-string", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_uri_from_string::vx_empty() const {return vx_web_html::e_uri_from_string;}
    vx_core::Type_any Class_uri_from_string::vx_type() const {return vx_web_html::t_uri_from_string;}
    vx_core::Type_msgblock Class_uri_from_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_uri_from_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_uri_from_string::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_uri_from_string::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_web_html::f_uri_from_string(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_uri_from_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_uri_from_string(text);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_web_html::Type_node e_node = NULL;
  vx_web_html::Type_node t_node = NULL;
  vx_web_html::Type_divchild e_divchild = NULL;
  vx_web_html::Type_divchild t_divchild = NULL;
  vx_web_html::Type_body e_body = NULL;
  vx_web_html::Type_body t_body = NULL;
  vx_web_html::Type_details e_details = NULL;
  vx_web_html::Type_details t_details = NULL;
  vx_web_html::Type_div e_div = NULL;
  vx_web_html::Type_div t_div = NULL;
  vx_web_html::Type_divchildlist e_divchildlist = NULL;
  vx_web_html::Type_divchildlist t_divchildlist = NULL;
  vx_web_html::Type_divlist e_divlist = NULL;
  vx_web_html::Type_divlist t_divlist = NULL;
  vx_web_html::Type_footer e_footer = NULL;
  vx_web_html::Type_footer t_footer = NULL;
  vx_web_html::Type_h1 e_h1 = NULL;
  vx_web_html::Type_h1 t_h1 = NULL;
  vx_web_html::Type_h2 e_h2 = NULL;
  vx_web_html::Type_h2 t_h2 = NULL;
  vx_web_html::Type_h3 e_h3 = NULL;
  vx_web_html::Type_h3 t_h3 = NULL;
  vx_web_html::Type_head e_head = NULL;
  vx_web_html::Type_head t_head = NULL;
  vx_web_html::Type_headchild e_headchild = NULL;
  vx_web_html::Type_headchild t_headchild = NULL;
  vx_web_html::Type_headchildlist e_headchildlist = NULL;
  vx_web_html::Type_headchildlist t_headchildlist = NULL;
  vx_web_html::Type_html e_html = NULL;
  vx_web_html::Type_html t_html = NULL;
  vx_web_html::Type_meta e_meta = NULL;
  vx_web_html::Type_meta t_meta = NULL;
  vx_web_html::Type_nodelist e_nodelist = NULL;
  vx_web_html::Type_nodelist t_nodelist = NULL;
  vx_web_html::Type_p e_p = NULL;
  vx_web_html::Type_p t_p = NULL;
  vx_web_html::Type_propmap e_propmap = NULL;
  vx_web_html::Type_propmap t_propmap = NULL;
  vx_web_html::Type_style e_style = NULL;
  vx_web_html::Type_style t_style = NULL;
  vx_web_html::Type_stylelist e_stylelist = NULL;
  vx_web_html::Type_stylelist t_stylelist = NULL;
  vx_web_html::Type_stylemap e_stylemap = NULL;
  vx_web_html::Type_stylemap t_stylemap = NULL;
  vx_web_html::Type_stylesheet e_stylesheet = NULL;
  vx_web_html::Type_stylesheet t_stylesheet = NULL;
  vx_web_html::Type_subpropmap e_subpropmap = NULL;
  vx_web_html::Type_subpropmap t_subpropmap = NULL;
  vx_web_html::Type_table e_table = NULL;
  vx_web_html::Type_table t_table = NULL;
  vx_web_html::Type_tbody e_tbody = NULL;
  vx_web_html::Type_tbody t_tbody = NULL;
  vx_web_html::Type_td e_td = NULL;
  vx_web_html::Type_td t_td = NULL;
  vx_web_html::Type_tdlist e_tdlist = NULL;
  vx_web_html::Type_tdlist t_tdlist = NULL;
  vx_web_html::Type_thead e_thead = NULL;
  vx_web_html::Type_thead t_thead = NULL;
  vx_web_html::Type_title e_title = NULL;
  vx_web_html::Type_title t_title = NULL;
  vx_web_html::Type_tr e_tr = NULL;
  vx_web_html::Type_tr t_tr = NULL;
  vx_web_html::Type_trlist e_trlist = NULL;
  vx_web_html::Type_trlist t_trlist = NULL;
  vx_web_html::Func_htmlstring_from_string e_htmlstring_from_string = NULL;
  vx_web_html::Func_htmlstring_from_string t_htmlstring_from_string = NULL;
  vx_web_html::Func_string_indent e_string_indent = NULL;
  vx_web_html::Func_string_indent t_string_indent = NULL;
  vx_web_html::Func_string_from_body_indent e_string_from_body_indent = NULL;
  vx_web_html::Func_string_from_body_indent t_string_from_body_indent = NULL;
  vx_web_html::Func_string_from_details_indent e_string_from_details_indent = NULL;
  vx_web_html::Func_string_from_details_indent t_string_from_details_indent = NULL;
  vx_web_html::Func_string_from_div_indent e_string_from_div_indent = NULL;
  vx_web_html::Func_string_from_div_indent t_string_from_div_indent = NULL;
  vx_web_html::Func_string_from_footer_indent e_string_from_footer_indent = NULL;
  vx_web_html::Func_string_from_footer_indent t_string_from_footer_indent = NULL;
  vx_web_html::Func_string_from_h1_indent e_string_from_h1_indent = NULL;
  vx_web_html::Func_string_from_h1_indent t_string_from_h1_indent = NULL;
  vx_web_html::Func_string_from_h2_indent e_string_from_h2_indent = NULL;
  vx_web_html::Func_string_from_h2_indent t_string_from_h2_indent = NULL;
  vx_web_html::Func_string_from_h3_indent e_string_from_h3_indent = NULL;
  vx_web_html::Func_string_from_h3_indent t_string_from_h3_indent = NULL;
  vx_web_html::Func_string_from_head_indent e_string_from_head_indent = NULL;
  vx_web_html::Func_string_from_head_indent t_string_from_head_indent = NULL;
  vx_web_html::Func_string_from_html e_string_from_html = NULL;
  vx_web_html::Func_string_from_html t_string_from_html = NULL;
  vx_web_html::Func_string_from_indent e_string_from_indent = NULL;
  vx_web_html::Func_string_from_indent t_string_from_indent = NULL;
  vx_web_html::Func_string_from_meta_indent e_string_from_meta_indent = NULL;
  vx_web_html::Func_string_from_meta_indent t_string_from_meta_indent = NULL;
  vx_web_html::Func_string_from_node_indent e_string_from_node_indent = NULL;
  vx_web_html::Func_string_from_node_indent t_string_from_node_indent = NULL;
  vx_web_html::Func_string_from_nodelist_indent e_string_from_nodelist_indent = NULL;
  vx_web_html::Func_string_from_nodelist_indent t_string_from_nodelist_indent = NULL;
  vx_web_html::Func_string_from_nodelist_tag_prop_indent e_string_from_nodelist_tag_prop_indent = NULL;
  vx_web_html::Func_string_from_nodelist_tag_prop_indent t_string_from_nodelist_tag_prop_indent = NULL;
  vx_web_html::Func_string_from_p_indent e_string_from_p_indent = NULL;
  vx_web_html::Func_string_from_p_indent t_string_from_p_indent = NULL;
  vx_web_html::Func_string_from_propname_val e_string_from_propname_val = NULL;
  vx_web_html::Func_string_from_propname_val t_string_from_propname_val = NULL;
  vx_web_html::Func_string_from_propstyle e_string_from_propstyle = NULL;
  vx_web_html::Func_string_from_propstyle t_string_from_propstyle = NULL;
  vx_web_html::Func_string_from_propstyle_stylelist e_string_from_propstyle_stylelist = NULL;
  vx_web_html::Func_string_from_propstyle_stylelist t_string_from_propstyle_stylelist = NULL;
  vx_web_html::Func_string_from_propstylelist e_string_from_propstylelist = NULL;
  vx_web_html::Func_string_from_propstylelist t_string_from_propstylelist = NULL;
  vx_web_html::Func_string_from_propstyleunique e_string_from_propstyleunique = NULL;
  vx_web_html::Func_string_from_propstyleunique t_string_from_propstyleunique = NULL;
  vx_web_html::Func_string_from_style_indent e_string_from_style_indent = NULL;
  vx_web_html::Func_string_from_style_indent t_string_from_style_indent = NULL;
  vx_web_html::Func_string_from_stylelist_indent e_string_from_stylelist_indent = NULL;
  vx_web_html::Func_string_from_stylelist_indent t_string_from_stylelist_indent = NULL;
  vx_web_html::Func_string_from_stylepropmap_indent e_string_from_stylepropmap_indent = NULL;
  vx_web_html::Func_string_from_stylepropmap_indent t_string_from_stylepropmap_indent = NULL;
  vx_web_html::Func_string_from_stylesheet_indent e_string_from_stylesheet_indent = NULL;
  vx_web_html::Func_string_from_stylesheet_indent t_string_from_stylesheet_indent = NULL;
  vx_web_html::Func_string_from_table_indent e_string_from_table_indent = NULL;
  vx_web_html::Func_string_from_table_indent t_string_from_table_indent = NULL;
  vx_web_html::Func_string_from_tbody_indent e_string_from_tbody_indent = NULL;
  vx_web_html::Func_string_from_tbody_indent t_string_from_tbody_indent = NULL;
  vx_web_html::Func_string_from_td_indent e_string_from_td_indent = NULL;
  vx_web_html::Func_string_from_td_indent t_string_from_td_indent = NULL;
  vx_web_html::Func_string_from_thead_indent e_string_from_thead_indent = NULL;
  vx_web_html::Func_string_from_thead_indent t_string_from_thead_indent = NULL;
  vx_web_html::Func_string_from_title_indent e_string_from_title_indent = NULL;
  vx_web_html::Func_string_from_title_indent t_string_from_title_indent = NULL;
  vx_web_html::Func_string_from_tr_indent e_string_from_tr_indent = NULL;
  vx_web_html::Func_string_from_tr_indent t_string_from_tr_indent = NULL;
  vx_web_html::Func_string_from_uri e_string_from_uri = NULL;
  vx_web_html::Func_string_from_uri t_string_from_uri = NULL;
  vx_web_html::Func_style_from_stylesheet_name e_style_from_stylesheet_name = NULL;
  vx_web_html::Func_style_from_stylesheet_name t_style_from_stylesheet_name = NULL;
  vx_web_html::Func_stylemap_from_stylelist e_stylemap_from_stylelist = NULL;
  vx_web_html::Func_stylemap_from_stylelist t_stylemap_from_stylelist = NULL;
  vx_web_html::Func_stylemap_from_stylesheet e_stylemap_from_stylesheet = NULL;
  vx_web_html::Func_stylemap_from_stylesheet t_stylemap_from_stylesheet = NULL;
  vx_web_html::Func_styles_from_stylesheet e_styles_from_stylesheet = NULL;
  vx_web_html::Func_styles_from_stylesheet t_styles_from_stylesheet = NULL;
  vx_web_html::Func_stylesheet_loadmap e_stylesheet_loadmap = NULL;
  vx_web_html::Func_stylesheet_loadmap t_stylesheet_loadmap = NULL;
  vx_web_html::Func_uri_from_string e_uri_from_string = NULL;
  vx_web_html::Func_uri_from_string t_uri_from_string = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_web_html::e_node = new Class_node();
      vx_core::vx_reserve_empty(vx_web_html::e_node);
      vx_web_html::t_node = new Class_node();
      vx_core::vx_reserve_type(vx_web_html::t_node);
      vx_web_html::e_divchild = new Class_divchild();
      vx_core::vx_reserve_empty(vx_web_html::e_divchild);
      vx_web_html::t_divchild = new Class_divchild();
      vx_core::vx_reserve_type(vx_web_html::t_divchild);
      vx_web_html::e_body = new Class_body();
      vx_core::vx_reserve_empty(vx_web_html::e_body);
      vx_web_html::t_body = new Class_body();
      vx_core::vx_reserve_type(vx_web_html::t_body);
      vx_web_html::e_details = new Class_details();
      vx_core::vx_reserve_empty(vx_web_html::e_details);
      vx_web_html::t_details = new Class_details();
      vx_core::vx_reserve_type(vx_web_html::t_details);
      vx_web_html::e_div = new Class_div();
      vx_core::vx_reserve_empty(vx_web_html::e_div);
      vx_web_html::t_div = new Class_div();
      vx_core::vx_reserve_type(vx_web_html::t_div);
      vx_web_html::e_divchildlist = new Class_divchildlist();
      vx_core::vx_reserve_empty(vx_web_html::e_divchildlist);
      vx_web_html::t_divchildlist = new Class_divchildlist();
      vx_core::vx_reserve_type(vx_web_html::t_divchildlist);
      vx_web_html::e_divlist = new Class_divlist();
      vx_core::vx_reserve_empty(vx_web_html::e_divlist);
      vx_web_html::t_divlist = new Class_divlist();
      vx_core::vx_reserve_type(vx_web_html::t_divlist);
      vx_web_html::e_footer = new Class_footer();
      vx_core::vx_reserve_empty(vx_web_html::e_footer);
      vx_web_html::t_footer = new Class_footer();
      vx_core::vx_reserve_type(vx_web_html::t_footer);
      vx_web_html::e_h1 = new Class_h1();
      vx_core::vx_reserve_empty(vx_web_html::e_h1);
      vx_web_html::t_h1 = new Class_h1();
      vx_core::vx_reserve_type(vx_web_html::t_h1);
      vx_web_html::e_h2 = new Class_h2();
      vx_core::vx_reserve_empty(vx_web_html::e_h2);
      vx_web_html::t_h2 = new Class_h2();
      vx_core::vx_reserve_type(vx_web_html::t_h2);
      vx_web_html::e_h3 = new Class_h3();
      vx_core::vx_reserve_empty(vx_web_html::e_h3);
      vx_web_html::t_h3 = new Class_h3();
      vx_core::vx_reserve_type(vx_web_html::t_h3);
      vx_web_html::e_head = new Class_head();
      vx_core::vx_reserve_empty(vx_web_html::e_head);
      vx_web_html::t_head = new Class_head();
      vx_core::vx_reserve_type(vx_web_html::t_head);
      vx_web_html::e_headchild = new Class_headchild();
      vx_core::vx_reserve_empty(vx_web_html::e_headchild);
      vx_web_html::t_headchild = new Class_headchild();
      vx_core::vx_reserve_type(vx_web_html::t_headchild);
      vx_web_html::e_headchildlist = new Class_headchildlist();
      vx_core::vx_reserve_empty(vx_web_html::e_headchildlist);
      vx_web_html::t_headchildlist = new Class_headchildlist();
      vx_core::vx_reserve_type(vx_web_html::t_headchildlist);
      vx_web_html::e_html = new Class_html();
      vx_core::vx_reserve_empty(vx_web_html::e_html);
      vx_web_html::t_html = new Class_html();
      vx_core::vx_reserve_type(vx_web_html::t_html);
      vx_web_html::e_meta = new Class_meta();
      vx_core::vx_reserve_empty(vx_web_html::e_meta);
      vx_web_html::t_meta = new Class_meta();
      vx_core::vx_reserve_type(vx_web_html::t_meta);
      vx_web_html::e_nodelist = new Class_nodelist();
      vx_core::vx_reserve_empty(vx_web_html::e_nodelist);
      vx_web_html::t_nodelist = new Class_nodelist();
      vx_core::vx_reserve_type(vx_web_html::t_nodelist);
      vx_web_html::e_p = new Class_p();
      vx_core::vx_reserve_empty(vx_web_html::e_p);
      vx_web_html::t_p = new Class_p();
      vx_core::vx_reserve_type(vx_web_html::t_p);
      vx_web_html::e_propmap = new Class_propmap();
      vx_core::vx_reserve_empty(vx_web_html::e_propmap);
      vx_web_html::t_propmap = new Class_propmap();
      vx_core::vx_reserve_type(vx_web_html::t_propmap);
      vx_web_html::e_style = new Class_style();
      vx_core::vx_reserve_empty(vx_web_html::e_style);
      vx_web_html::t_style = new Class_style();
      vx_core::vx_reserve_type(vx_web_html::t_style);
      vx_web_html::e_stylelist = new Class_stylelist();
      vx_core::vx_reserve_empty(vx_web_html::e_stylelist);
      vx_web_html::t_stylelist = new Class_stylelist();
      vx_core::vx_reserve_type(vx_web_html::t_stylelist);
      vx_web_html::e_stylemap = new Class_stylemap();
      vx_core::vx_reserve_empty(vx_web_html::e_stylemap);
      vx_web_html::t_stylemap = new Class_stylemap();
      vx_core::vx_reserve_type(vx_web_html::t_stylemap);
      vx_web_html::e_stylesheet = new Class_stylesheet();
      vx_core::vx_reserve_empty(vx_web_html::e_stylesheet);
      vx_web_html::t_stylesheet = new Class_stylesheet();
      vx_core::vx_reserve_type(vx_web_html::t_stylesheet);
      vx_web_html::e_subpropmap = new Class_subpropmap();
      vx_core::vx_reserve_empty(vx_web_html::e_subpropmap);
      vx_web_html::t_subpropmap = new Class_subpropmap();
      vx_core::vx_reserve_type(vx_web_html::t_subpropmap);
      vx_web_html::e_table = new Class_table();
      vx_core::vx_reserve_empty(vx_web_html::e_table);
      vx_web_html::t_table = new Class_table();
      vx_core::vx_reserve_type(vx_web_html::t_table);
      vx_web_html::e_tbody = new Class_tbody();
      vx_core::vx_reserve_empty(vx_web_html::e_tbody);
      vx_web_html::t_tbody = new Class_tbody();
      vx_core::vx_reserve_type(vx_web_html::t_tbody);
      vx_web_html::e_td = new Class_td();
      vx_core::vx_reserve_empty(vx_web_html::e_td);
      vx_web_html::t_td = new Class_td();
      vx_core::vx_reserve_type(vx_web_html::t_td);
      vx_web_html::e_tdlist = new Class_tdlist();
      vx_core::vx_reserve_empty(vx_web_html::e_tdlist);
      vx_web_html::t_tdlist = new Class_tdlist();
      vx_core::vx_reserve_type(vx_web_html::t_tdlist);
      vx_web_html::e_thead = new Class_thead();
      vx_core::vx_reserve_empty(vx_web_html::e_thead);
      vx_web_html::t_thead = new Class_thead();
      vx_core::vx_reserve_type(vx_web_html::t_thead);
      vx_web_html::e_title = new Class_title();
      vx_core::vx_reserve_empty(vx_web_html::e_title);
      vx_web_html::t_title = new Class_title();
      vx_core::vx_reserve_type(vx_web_html::t_title);
      vx_web_html::e_tr = new Class_tr();
      vx_core::vx_reserve_empty(vx_web_html::e_tr);
      vx_web_html::t_tr = new Class_tr();
      vx_core::vx_reserve_type(vx_web_html::t_tr);
      vx_web_html::e_trlist = new Class_trlist();
      vx_core::vx_reserve_empty(vx_web_html::e_trlist);
      vx_web_html::t_trlist = new Class_trlist();
      vx_core::vx_reserve_type(vx_web_html::t_trlist);
      vx_web_html::e_htmlstring_from_string = new vx_web_html::Class_htmlstring_from_string();
      vx_core::vx_reserve_empty(vx_web_html::e_htmlstring_from_string);
      vx_web_html::t_htmlstring_from_string = new vx_web_html::Class_htmlstring_from_string();
      vx_core::vx_reserve_type(vx_web_html::t_htmlstring_from_string);
      vx_web_html::e_string_indent = new vx_web_html::Class_string_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_indent);
      vx_web_html::t_string_indent = new vx_web_html::Class_string_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_indent);
      vx_web_html::e_string_from_body_indent = new vx_web_html::Class_string_from_body_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_body_indent);
      vx_web_html::t_string_from_body_indent = new vx_web_html::Class_string_from_body_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_body_indent);
      vx_web_html::e_string_from_details_indent = new vx_web_html::Class_string_from_details_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_details_indent);
      vx_web_html::t_string_from_details_indent = new vx_web_html::Class_string_from_details_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_details_indent);
      vx_web_html::e_string_from_div_indent = new vx_web_html::Class_string_from_div_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_div_indent);
      vx_web_html::t_string_from_div_indent = new vx_web_html::Class_string_from_div_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_div_indent);
      vx_web_html::e_string_from_footer_indent = new vx_web_html::Class_string_from_footer_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_footer_indent);
      vx_web_html::t_string_from_footer_indent = new vx_web_html::Class_string_from_footer_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_footer_indent);
      vx_web_html::e_string_from_h1_indent = new vx_web_html::Class_string_from_h1_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_h1_indent);
      vx_web_html::t_string_from_h1_indent = new vx_web_html::Class_string_from_h1_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_h1_indent);
      vx_web_html::e_string_from_h2_indent = new vx_web_html::Class_string_from_h2_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_h2_indent);
      vx_web_html::t_string_from_h2_indent = new vx_web_html::Class_string_from_h2_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_h2_indent);
      vx_web_html::e_string_from_h3_indent = new vx_web_html::Class_string_from_h3_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_h3_indent);
      vx_web_html::t_string_from_h3_indent = new vx_web_html::Class_string_from_h3_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_h3_indent);
      vx_web_html::e_string_from_head_indent = new vx_web_html::Class_string_from_head_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_head_indent);
      vx_web_html::t_string_from_head_indent = new vx_web_html::Class_string_from_head_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_head_indent);
      vx_web_html::e_string_from_html = new vx_web_html::Class_string_from_html();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_html);
      vx_web_html::t_string_from_html = new vx_web_html::Class_string_from_html();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_html);
      vx_web_html::e_string_from_indent = new vx_web_html::Class_string_from_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_indent);
      vx_web_html::t_string_from_indent = new vx_web_html::Class_string_from_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_indent);
      vx_web_html::e_string_from_meta_indent = new vx_web_html::Class_string_from_meta_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_meta_indent);
      vx_web_html::t_string_from_meta_indent = new vx_web_html::Class_string_from_meta_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_meta_indent);
      vx_web_html::e_string_from_node_indent = new vx_web_html::Class_string_from_node_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_node_indent);
      vx_web_html::t_string_from_node_indent = new vx_web_html::Class_string_from_node_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_node_indent);
      vx_web_html::e_string_from_nodelist_indent = new vx_web_html::Class_string_from_nodelist_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_nodelist_indent);
      vx_web_html::t_string_from_nodelist_indent = new vx_web_html::Class_string_from_nodelist_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_nodelist_indent);
      vx_web_html::e_string_from_nodelist_tag_prop_indent = new vx_web_html::Class_string_from_nodelist_tag_prop_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_nodelist_tag_prop_indent);
      vx_web_html::t_string_from_nodelist_tag_prop_indent = new vx_web_html::Class_string_from_nodelist_tag_prop_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_nodelist_tag_prop_indent);
      vx_web_html::e_string_from_p_indent = new vx_web_html::Class_string_from_p_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_p_indent);
      vx_web_html::t_string_from_p_indent = new vx_web_html::Class_string_from_p_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_p_indent);
      vx_web_html::e_string_from_propname_val = new vx_web_html::Class_string_from_propname_val();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_propname_val);
      vx_web_html::t_string_from_propname_val = new vx_web_html::Class_string_from_propname_val();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_propname_val);
      vx_web_html::e_string_from_propstyle = new vx_web_html::Class_string_from_propstyle();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_propstyle);
      vx_web_html::t_string_from_propstyle = new vx_web_html::Class_string_from_propstyle();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_propstyle);
      vx_web_html::e_string_from_propstyle_stylelist = new vx_web_html::Class_string_from_propstyle_stylelist();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_propstyle_stylelist);
      vx_web_html::t_string_from_propstyle_stylelist = new vx_web_html::Class_string_from_propstyle_stylelist();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_propstyle_stylelist);
      vx_web_html::e_string_from_propstylelist = new vx_web_html::Class_string_from_propstylelist();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_propstylelist);
      vx_web_html::t_string_from_propstylelist = new vx_web_html::Class_string_from_propstylelist();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_propstylelist);
      vx_web_html::e_string_from_propstyleunique = new vx_web_html::Class_string_from_propstyleunique();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_propstyleunique);
      vx_web_html::t_string_from_propstyleunique = new vx_web_html::Class_string_from_propstyleunique();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_propstyleunique);
      vx_web_html::e_string_from_style_indent = new vx_web_html::Class_string_from_style_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_style_indent);
      vx_web_html::t_string_from_style_indent = new vx_web_html::Class_string_from_style_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_style_indent);
      vx_web_html::e_string_from_stylelist_indent = new vx_web_html::Class_string_from_stylelist_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_stylelist_indent);
      vx_web_html::t_string_from_stylelist_indent = new vx_web_html::Class_string_from_stylelist_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_stylelist_indent);
      vx_web_html::e_string_from_stylepropmap_indent = new vx_web_html::Class_string_from_stylepropmap_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_stylepropmap_indent);
      vx_web_html::t_string_from_stylepropmap_indent = new vx_web_html::Class_string_from_stylepropmap_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_stylepropmap_indent);
      vx_web_html::e_string_from_stylesheet_indent = new vx_web_html::Class_string_from_stylesheet_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_stylesheet_indent);
      vx_web_html::t_string_from_stylesheet_indent = new vx_web_html::Class_string_from_stylesheet_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_stylesheet_indent);
      vx_web_html::e_string_from_table_indent = new vx_web_html::Class_string_from_table_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_table_indent);
      vx_web_html::t_string_from_table_indent = new vx_web_html::Class_string_from_table_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_table_indent);
      vx_web_html::e_string_from_tbody_indent = new vx_web_html::Class_string_from_tbody_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_tbody_indent);
      vx_web_html::t_string_from_tbody_indent = new vx_web_html::Class_string_from_tbody_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_tbody_indent);
      vx_web_html::e_string_from_td_indent = new vx_web_html::Class_string_from_td_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_td_indent);
      vx_web_html::t_string_from_td_indent = new vx_web_html::Class_string_from_td_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_td_indent);
      vx_web_html::e_string_from_thead_indent = new vx_web_html::Class_string_from_thead_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_thead_indent);
      vx_web_html::t_string_from_thead_indent = new vx_web_html::Class_string_from_thead_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_thead_indent);
      vx_web_html::e_string_from_title_indent = new vx_web_html::Class_string_from_title_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_title_indent);
      vx_web_html::t_string_from_title_indent = new vx_web_html::Class_string_from_title_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_title_indent);
      vx_web_html::e_string_from_tr_indent = new vx_web_html::Class_string_from_tr_indent();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_tr_indent);
      vx_web_html::t_string_from_tr_indent = new vx_web_html::Class_string_from_tr_indent();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_tr_indent);
      vx_web_html::e_string_from_uri = new vx_web_html::Class_string_from_uri();
      vx_core::vx_reserve_empty(vx_web_html::e_string_from_uri);
      vx_web_html::t_string_from_uri = new vx_web_html::Class_string_from_uri();
      vx_core::vx_reserve_type(vx_web_html::t_string_from_uri);
      vx_web_html::e_style_from_stylesheet_name = new vx_web_html::Class_style_from_stylesheet_name();
      vx_core::vx_reserve_empty(vx_web_html::e_style_from_stylesheet_name);
      vx_web_html::t_style_from_stylesheet_name = new vx_web_html::Class_style_from_stylesheet_name();
      vx_core::vx_reserve_type(vx_web_html::t_style_from_stylesheet_name);
      vx_web_html::e_stylemap_from_stylelist = new vx_web_html::Class_stylemap_from_stylelist();
      vx_core::vx_reserve_empty(vx_web_html::e_stylemap_from_stylelist);
      vx_web_html::t_stylemap_from_stylelist = new vx_web_html::Class_stylemap_from_stylelist();
      vx_core::vx_reserve_type(vx_web_html::t_stylemap_from_stylelist);
      vx_web_html::e_stylemap_from_stylesheet = new vx_web_html::Class_stylemap_from_stylesheet();
      vx_core::vx_reserve_empty(vx_web_html::e_stylemap_from_stylesheet);
      vx_web_html::t_stylemap_from_stylesheet = new vx_web_html::Class_stylemap_from_stylesheet();
      vx_core::vx_reserve_type(vx_web_html::t_stylemap_from_stylesheet);
      vx_web_html::e_styles_from_stylesheet = new vx_web_html::Class_styles_from_stylesheet();
      vx_core::vx_reserve_empty(vx_web_html::e_styles_from_stylesheet);
      vx_web_html::t_styles_from_stylesheet = new vx_web_html::Class_styles_from_stylesheet();
      vx_core::vx_reserve_type(vx_web_html::t_styles_from_stylesheet);
      vx_web_html::e_stylesheet_loadmap = new vx_web_html::Class_stylesheet_loadmap();
      vx_core::vx_reserve_empty(vx_web_html::e_stylesheet_loadmap);
      vx_web_html::t_stylesheet_loadmap = new vx_web_html::Class_stylesheet_loadmap();
      vx_core::vx_reserve_type(vx_web_html::t_stylesheet_loadmap);
      vx_web_html::e_uri_from_string = new vx_web_html::Class_uri_from_string();
      vx_core::vx_reserve_empty(vx_web_html::e_uri_from_string);
      vx_web_html::t_uri_from_string = new vx_web_html::Class_uri_from_string();
      vx_core::vx_reserve_type(vx_web_html::t_uri_from_string);
      vx_core::vx_Type_mapany maptype;
      vx_core::vx_Type_mapany mapconst;
      vx_core::vx_Type_mapfunc mapfunc;
      vx_core::vx_Type_mapany mapempty;
      maptype["node"] = vx_web_html::t_node;
      maptype["divchild"] = vx_web_html::t_divchild;
      maptype["body"] = vx_web_html::t_body;
      maptype["details"] = vx_web_html::t_details;
      maptype["div"] = vx_web_html::t_div;
      maptype["divchildlist"] = vx_web_html::t_divchildlist;
      maptype["divlist"] = vx_web_html::t_divlist;
      maptype["footer"] = vx_web_html::t_footer;
      maptype["h1"] = vx_web_html::t_h1;
      maptype["h2"] = vx_web_html::t_h2;
      maptype["h3"] = vx_web_html::t_h3;
      maptype["head"] = vx_web_html::t_head;
      maptype["headchild"] = vx_web_html::t_headchild;
      maptype["headchildlist"] = vx_web_html::t_headchildlist;
      maptype["html"] = vx_web_html::t_html;
      maptype["meta"] = vx_web_html::t_meta;
      maptype["nodelist"] = vx_web_html::t_nodelist;
      maptype["p"] = vx_web_html::t_p;
      maptype["propmap"] = vx_web_html::t_propmap;
      maptype["style"] = vx_web_html::t_style;
      maptype["stylelist"] = vx_web_html::t_stylelist;
      maptype["stylemap"] = vx_web_html::t_stylemap;
      maptype["stylesheet"] = vx_web_html::t_stylesheet;
      maptype["subpropmap"] = vx_web_html::t_subpropmap;
      maptype["table"] = vx_web_html::t_table;
      maptype["tbody"] = vx_web_html::t_tbody;
      maptype["td"] = vx_web_html::t_td;
      maptype["tdlist"] = vx_web_html::t_tdlist;
      maptype["thead"] = vx_web_html::t_thead;
      maptype["title"] = vx_web_html::t_title;
      maptype["tr"] = vx_web_html::t_tr;
      maptype["trlist"] = vx_web_html::t_trlist;
      mapfunc["htmlstring<-string"] = vx_web_html::t_htmlstring_from_string;
      mapfunc["string-indent"] = vx_web_html::t_string_indent;
      mapfunc["string<-body-indent"] = vx_web_html::t_string_from_body_indent;
      mapfunc["string<-details-indent"] = vx_web_html::t_string_from_details_indent;
      mapfunc["string<-div-indent"] = vx_web_html::t_string_from_div_indent;
      mapfunc["string<-footer-indent"] = vx_web_html::t_string_from_footer_indent;
      mapfunc["string<-h1-indent"] = vx_web_html::t_string_from_h1_indent;
      mapfunc["string<-h2-indent"] = vx_web_html::t_string_from_h2_indent;
      mapfunc["string<-h3-indent"] = vx_web_html::t_string_from_h3_indent;
      mapfunc["string<-head-indent"] = vx_web_html::t_string_from_head_indent;
      mapfunc["string<-html"] = vx_web_html::t_string_from_html;
      mapfunc["string<-indent"] = vx_web_html::t_string_from_indent;
      mapfunc["string<-meta-indent"] = vx_web_html::t_string_from_meta_indent;
      mapfunc["string<-node-indent"] = vx_web_html::t_string_from_node_indent;
      mapfunc["string<-nodelist-indent"] = vx_web_html::t_string_from_nodelist_indent;
      mapfunc["string<-nodelist-tag-prop-indent"] = vx_web_html::t_string_from_nodelist_tag_prop_indent;
      mapfunc["string<-p-indent"] = vx_web_html::t_string_from_p_indent;
      mapfunc["string<-propname-val"] = vx_web_html::t_string_from_propname_val;
      mapfunc["string<-propstyle"] = vx_web_html::t_string_from_propstyle;
      mapfunc["string<-propstyle-stylelist"] = vx_web_html::t_string_from_propstyle_stylelist;
      mapfunc["string<-propstylelist"] = vx_web_html::t_string_from_propstylelist;
      mapfunc["string<-propstyleunique"] = vx_web_html::t_string_from_propstyleunique;
      mapfunc["string<-style-indent"] = vx_web_html::t_string_from_style_indent;
      mapfunc["string<-stylelist-indent"] = vx_web_html::t_string_from_stylelist_indent;
      mapfunc["string<-stylepropmap-indent"] = vx_web_html::t_string_from_stylepropmap_indent;
      mapfunc["string<-stylesheet-indent"] = vx_web_html::t_string_from_stylesheet_indent;
      mapfunc["string<-table-indent"] = vx_web_html::t_string_from_table_indent;
      mapfunc["string<-tbody-indent"] = vx_web_html::t_string_from_tbody_indent;
      mapfunc["string<-td-indent"] = vx_web_html::t_string_from_td_indent;
      mapfunc["string<-thead-indent"] = vx_web_html::t_string_from_thead_indent;
      mapfunc["string<-title-indent"] = vx_web_html::t_string_from_title_indent;
      mapfunc["string<-tr-indent"] = vx_web_html::t_string_from_tr_indent;
      mapfunc["string<-uri"] = vx_web_html::t_string_from_uri;
      mapfunc["style<-stylesheet-name"] = vx_web_html::t_style_from_stylesheet_name;
      mapfunc["stylemap<-stylelist"] = vx_web_html::t_stylemap_from_stylelist;
      mapfunc["stylemap<-stylesheet"] = vx_web_html::t_stylemap_from_stylesheet;
      mapfunc["styles<-stylesheet"] = vx_web_html::t_styles_from_stylesheet;
      mapfunc["stylesheet-loadmap"] = vx_web_html::t_stylesheet_loadmap;
      mapfunc["uri<-string"] = vx_web_html::t_uri_from_string;
      vx_core::vx_global_package_set("vx/web/html", maptype, mapconst, mapfunc);
	   }
  // }

}
