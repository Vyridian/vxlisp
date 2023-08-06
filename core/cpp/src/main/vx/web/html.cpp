#include <map>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
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
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_style
      });
    }

    // id()
    vx_core::Type_string Class_node::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_node::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_node::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_node::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":style"] = this->style();
      return output;
    }

    vx_core::Type_any Class_node::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_node(), vals);
    }

    vx_core::Type_any Class_node::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_node output = vx_web_html::e_node();
      vx_web_html::Type_node val = vx_core::vx_any_from_any(vx_web_html::t_node(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_web_html::Type_style vx_p_style = val->style();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new node) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new node :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style()) {
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new node :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new node) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_web_html::Class_node();
      if (output->vx_p_id != vx_p_id) {
        if (output->vx_p_id) {
          vx_core::vx_release_one(output->vx_p_id);
        }
        output->vx_p_id = vx_p_id;
        vx_core::vx_reserve(vx_p_id);
      }
      if (output->vx_p_style != vx_p_style) {
        if (output->vx_p_style) {
          vx_core::vx_release_one(output->vx_p_style);
        }
        output->vx_p_style = vx_p_style;
        vx_core::vx_reserve(vx_p_style);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_node::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_node::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_node::vx_empty() const {return vx_web_html::e_node();}
    vx_core::Type_any Class_node::vx_type() const {return vx_web_html::t_node();}

    vx_core::Type_typedef Class_node::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "node", // name
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

  // (type divchild)
  // class Class_divchild {
    Abstract_divchild::~Abstract_divchild() {}

    Class_divchild::Class_divchild() : Abstract_divchild::Abstract_divchild() {
      vx_core::refcount += 1;
    }

    Class_divchild::~Class_divchild() {
      vx_core::refcount -= 1;
      vx_core::vx_release_one({
        
      });
    }

    // vx_get_any(key)
    vx_core::Type_any Class_divchild::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
      return this->vx_copy(vx_web_html::e_divchild(), vals);
    }

    vx_core::Type_any Class_divchild::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_divchild output = vx_web_html::e_divchild();
      vx_web_html::Type_divchild val = vx_core::vx_any_from_any(vx_web_html::t_divchild(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_divchild::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_divchild::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_divchild::vx_empty() const {return vx_web_html::e_divchild();}
    vx_core::Type_any Class_divchild::vx_type() const {return vx_web_html::t_divchild();}

    vx_core::Type_typedef Class_divchild::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "divchild", // name
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

  // (type body)
  // class Class_body {
    Abstract_body::~Abstract_body() {}

    Class_body::Class_body() : Abstract_body::Abstract_body() {
      vx_core::refcount += 1;
    }

    Class_body::~Class_body() {
      vx_core::refcount -= 1;
      vx_core::vx_release_one({
        this->vx_p_nodes
      });
    }

    // nodes()
    vx_web_html::Type_divchildlist Class_body::nodes() const {
      vx_web_html::Type_divchildlist output = this->vx_p_nodes;
      if (!output) {
        output = vx_web_html::e_divchildlist();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_body::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
      return this->vx_copy(vx_web_html::e_body(), vals);
    }

    vx_core::Type_any Class_body::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_body output = vx_web_html::e_body();
      vx_web_html::Type_body val = vx_core::vx_any_from_any(vx_web_html::t_body(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_web_html::Type_divchildlist vx_p_nodes = val->nodes();
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
          } else if (testkey == ":nodes") {
            key = testkey;
          } else if (valsubtype == vx_web_html::t_divchildlist()) { // default property
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_divchildlist(), valsub);
          } else if (valsubtype == vx_web_html::t_divchild()) { // default property
            vx_web_html::Type_divchild valdefault = vx_core::vx_any_from_any(vx_web_html::t_divchild(), valsub);
            vx_web_html::Type_divchildlist vallist = output->vx_p_nodes;
            if (!vallist) {
              vallist = vx_core::vx_new(vx_web_html::t_divchildlist(), {valdefault});
            } else {
              vallist = vx_core::vx_copy(vx_web_html::t_divchildlist(), {valdefault});
            }
            vx_p_nodes = vallist;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new body) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":nodes") {
            if (valsubtype == vx_web_html::t_divchildlist()) {
              vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_divchildlist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new body :nodes " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new body) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_web_html::Class_body();
      if (output->vx_p_nodes != vx_p_nodes) {
        if (output->vx_p_nodes) {
          vx_core::vx_release_one(output->vx_p_nodes);
        }
        output->vx_p_nodes = vx_p_nodes;
        vx_core::vx_reserve(vx_p_nodes);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_body::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_body::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_body::vx_empty() const {return vx_web_html::e_body();}
    vx_core::Type_any Class_body::vx_type() const {return vx_web_html::t_body();}

    vx_core::Type_typedef Class_body::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "body", // name
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

  // (type details)
  // class Class_details {
    Abstract_details::~Abstract_details() {}

    Class_details::Class_details() : Abstract_details::Abstract_details() {
      vx_core::refcount += 1;
    }

    Class_details::~Class_details() {
      vx_core::refcount -= 1;
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_style,
        this->vx_p_summary,
        this->vx_p_nodes
      });
    }

    // id()
    vx_core::Type_string Class_details::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_details::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style();
      }
      return output;
    }

    // summary()
    vx_web_html::Type_divchildlist Class_details::summary() const {
      vx_web_html::Type_divchildlist output = this->vx_p_summary;
      if (!output) {
        output = vx_web_html::e_divchildlist();
      }
      return output;
    }

    // nodes()
    vx_web_html::Type_divchildlist Class_details::nodes() const {
      vx_web_html::Type_divchildlist output = this->vx_p_nodes;
      if (!output) {
        output = vx_web_html::e_divchildlist();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_details::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_details::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":style"] = this->style();
      output[":summary"] = this->summary();
      output[":nodes"] = this->nodes();
      return output;
    }

    vx_core::Type_any Class_details::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_details(), vals);
    }

    vx_core::Type_any Class_details::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_details output = vx_web_html::e_details();
      vx_web_html::Type_details val = vx_core::vx_any_from_any(vx_web_html::t_details(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_web_html::Type_divchildlist vx_p_summary = val->summary();
      vx_web_html::Type_divchildlist vx_p_nodes = val->nodes();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":summary") {
            key = testkey;
          } else if (testkey == ":nodes") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new details) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new details :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style()) {
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new details :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":summary") {
            if (valsubtype == vx_web_html::t_divchildlist()) {
              vx_p_summary = vx_core::vx_any_from_any(vx_web_html::t_divchildlist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new details :summary " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":nodes") {
            if (valsubtype == vx_web_html::t_divchildlist()) {
              vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_divchildlist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new details :nodes " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new details) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_web_html::Class_details();
      if (output->vx_p_id != vx_p_id) {
        if (output->vx_p_id) {
          vx_core::vx_release_one(output->vx_p_id);
        }
        output->vx_p_id = vx_p_id;
        vx_core::vx_reserve(vx_p_id);
      }
      if (output->vx_p_style != vx_p_style) {
        if (output->vx_p_style) {
          vx_core::vx_release_one(output->vx_p_style);
        }
        output->vx_p_style = vx_p_style;
        vx_core::vx_reserve(vx_p_style);
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
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_details::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_details::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_details::vx_empty() const {return vx_web_html::e_details();}
    vx_core::Type_any Class_details::vx_type() const {return vx_web_html::t_details();}

    vx_core::Type_typedef Class_details::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "details", // name
        ":struct", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_node(), vx_web_html::t_divchild()}), // traits
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

  // (type div)
  // class Class_div {
    Abstract_div::~Abstract_div() {}

    Class_div::Class_div() : Abstract_div::Abstract_div() {
      vx_core::refcount += 1;
    }

    Class_div::~Class_div() {
      vx_core::refcount -= 1;
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_style,
        this->vx_p_nodes
      });
    }

    // id()
    vx_core::Type_string Class_div::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_div::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style();
      }
      return output;
    }

    // nodes()
    vx_web_html::Type_divchildlist Class_div::nodes() const {
      vx_web_html::Type_divchildlist output = this->vx_p_nodes;
      if (!output) {
        output = vx_web_html::e_divchildlist();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_div::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
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
      output[":style"] = this->style();
      output[":nodes"] = this->nodes();
      return output;
    }

    vx_core::Type_any Class_div::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_div(), vals);
    }

    vx_core::Type_any Class_div::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_div output = vx_web_html::e_div();
      vx_web_html::Type_div val = vx_core::vx_any_from_any(vx_web_html::t_div(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_web_html::Type_divchildlist vx_p_nodes = val->nodes();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":nodes") {
            key = testkey;
          } else if (valsubtype == vx_web_html::t_divchildlist()) { // default property
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_divchildlist(), valsub);
          } else if (valsubtype == vx_web_html::t_divchild()) { // default property
            vx_web_html::Type_divchild valdefault = vx_core::vx_any_from_any(vx_web_html::t_divchild(), valsub);
            vx_web_html::Type_divchildlist vallist = output->vx_p_nodes;
            if (!vallist) {
              vallist = vx_core::vx_new(vx_web_html::t_divchildlist(), {valdefault});
            } else {
              vallist = vx_core::vx_copy(vx_web_html::t_divchildlist(), {valdefault});
            }
            vx_p_nodes = vallist;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new div) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new div :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style()) {
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new div :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":nodes") {
            if (valsubtype == vx_web_html::t_divchildlist()) {
              vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_divchildlist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new div :nodes " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new div) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_web_html::Class_div();
      if (output->vx_p_id != vx_p_id) {
        if (output->vx_p_id) {
          vx_core::vx_release_one(output->vx_p_id);
        }
        output->vx_p_id = vx_p_id;
        vx_core::vx_reserve(vx_p_id);
      }
      if (output->vx_p_style != vx_p_style) {
        if (output->vx_p_style) {
          vx_core::vx_release_one(output->vx_p_style);
        }
        output->vx_p_style = vx_p_style;
        vx_core::vx_reserve(vx_p_style);
      }
      if (output->vx_p_nodes != vx_p_nodes) {
        if (output->vx_p_nodes) {
          vx_core::vx_release_one(output->vx_p_nodes);
        }
        output->vx_p_nodes = vx_p_nodes;
        vx_core::vx_reserve(vx_p_nodes);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_div::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_div::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_div::vx_empty() const {return vx_web_html::e_div();}
    vx_core::Type_any Class_div::vx_type() const {return vx_web_html::t_div();}

    vx_core::Type_typedef Class_div::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "div", // name
        ":struct", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_node(), vx_web_html::t_divchild()}), // traits
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

  // (type divchildlist)
  // class Class_divchildlist {
    Abstract_divchildlist::~Abstract_divchildlist() {}

    Class_divchildlist::Class_divchildlist() : Abstract_divchildlist::Abstract_divchildlist() {
      vx_core::refcount += 1;
    }

    Class_divchildlist::~Class_divchildlist() {
      vx_core::refcount -= 1;
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_divchildlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_web_html::Type_divchild Class_divchildlist::vx_get_divchild(vx_core::Type_int index) const {
      vx_web_html::Type_divchild output = vx_web_html::e_divchild();
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
      vx_web_html::Type_divchildlist output = vx_web_html::e_divchildlist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_web_html::Type_divchild> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_web_html::t_divchild()) {
          vx_web_html::Type_divchild castval = vx_core::vx_any_from_any(vx_web_html::t_divchild(), valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(divchildlist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_web_html::Class_divchildlist();
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

    vx_core::Type_any Class_divchildlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_divchildlist(), vals);
    }

    vx_core::Type_any Class_divchildlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_divchildlist output = vx_web_html::e_divchildlist();
      vx_web_html::Type_divchildlist val = vx_core::vx_any_from_any(vx_web_html::t_divchildlist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_web_html::Type_divchild> listval = val->vx_listdivchild();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_web_html::t_divchild()) {
          listval.push_back(vx_core::vx_any_from_any(vx_web_html::t_divchild(), valsub));
        } else if (valsubtype == vx_web_html::t_divchildlist()) {
          vx_web_html::Type_divchildlist multi = vx_core::vx_any_from_any(vx_web_html::t_divchildlist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listdivchild());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new divchildlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_web_html::Class_divchildlist();
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

    vx_core::Type_msgblock Class_divchildlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_divchildlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_divchildlist::vx_empty() const {return vx_web_html::e_divchildlist();}
    vx_core::Type_any Class_divchildlist::vx_type() const {return vx_web_html::t_divchildlist();}

    vx_core::Type_typedef Class_divchildlist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "divchildlist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_divchild()}), // allowtypes
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

  // (type divlist)
  // class Class_divlist {
    Abstract_divlist::~Abstract_divlist() {}

    Class_divlist::Class_divlist() : Abstract_divlist::Abstract_divlist() {
      vx_core::refcount += 1;
    }

    Class_divlist::~Class_divlist() {
      vx_core::refcount -= 1;
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_divlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_web_html::Type_div Class_divlist::vx_get_div(vx_core::Type_int index) const {
      vx_web_html::Type_div output = vx_web_html::e_div();
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
      vx_web_html::Type_divlist output = vx_web_html::e_divlist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_web_html::Type_div> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_web_html::t_div()) {
          vx_web_html::Type_div castval = vx_core::vx_any_from_any(vx_web_html::t_div(), valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(divlist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_web_html::Class_divlist();
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

    vx_core::Type_any Class_divlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_divlist(), vals);
    }

    vx_core::Type_any Class_divlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_divlist output = vx_web_html::e_divlist();
      vx_web_html::Type_divlist val = vx_core::vx_any_from_any(vx_web_html::t_divlist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_web_html::Type_div> listval = val->vx_listdiv();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_web_html::t_div()) {
          listval.push_back(vx_core::vx_any_from_any(vx_web_html::t_div(), valsub));
        } else if (valsubtype == vx_web_html::t_divlist()) {
          vx_web_html::Type_divlist multi = vx_core::vx_any_from_any(vx_web_html::t_divlist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listdiv());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new divlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_web_html::Class_divlist();
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

    vx_core::Type_msgblock Class_divlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_divlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_divlist::vx_empty() const {return vx_web_html::e_divlist();}
    vx_core::Type_any Class_divlist::vx_type() const {return vx_web_html::t_divlist();}

    vx_core::Type_typedef Class_divlist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "divlist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_div()}), // allowtypes
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

  // (type footer)
  // class Class_footer {
    Abstract_footer::~Abstract_footer() {}

    Class_footer::Class_footer() : Abstract_footer::Abstract_footer() {
      vx_core::refcount += 1;
    }

    Class_footer::~Class_footer() {
      vx_core::refcount -= 1;
      vx_core::vx_release_one({
        this->vx_p_nodes
      });
    }

    // nodes()
    vx_web_html::Type_divchildlist Class_footer::nodes() const {
      vx_web_html::Type_divchildlist output = this->vx_p_nodes;
      if (!output) {
        output = vx_web_html::e_divchildlist();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_footer::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
      return this->vx_copy(vx_web_html::e_footer(), vals);
    }

    vx_core::Type_any Class_footer::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_footer output = vx_web_html::e_footer();
      vx_web_html::Type_footer val = vx_core::vx_any_from_any(vx_web_html::t_footer(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_web_html::Type_divchildlist vx_p_nodes = val->nodes();
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
          } else if (testkey == ":nodes") {
            key = testkey;
          } else if (valsubtype == vx_web_html::t_divchildlist()) { // default property
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_divchildlist(), valsub);
          } else if (valsubtype == vx_web_html::t_divchild()) { // default property
            vx_web_html::Type_divchild valdefault = vx_core::vx_any_from_any(vx_web_html::t_divchild(), valsub);
            vx_web_html::Type_divchildlist vallist = output->vx_p_nodes;
            if (!vallist) {
              vallist = vx_core::vx_new(vx_web_html::t_divchildlist(), {valdefault});
            } else {
              vallist = vx_core::vx_copy(vx_web_html::t_divchildlist(), {valdefault});
            }
            vx_p_nodes = vallist;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new footer) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":nodes") {
            if (valsubtype == vx_web_html::t_divchildlist()) {
              vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_divchildlist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new footer :nodes " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new footer) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_web_html::Class_footer();
      if (output->vx_p_nodes != vx_p_nodes) {
        if (output->vx_p_nodes) {
          vx_core::vx_release_one(output->vx_p_nodes);
        }
        output->vx_p_nodes = vx_p_nodes;
        vx_core::vx_reserve(vx_p_nodes);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_footer::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_footer::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_footer::vx_empty() const {return vx_web_html::e_footer();}
    vx_core::Type_any Class_footer::vx_type() const {return vx_web_html::t_footer();}

    vx_core::Type_typedef Class_footer::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "footer", // name
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

  // (type h1)
  // class Class_h1 {
    Abstract_h1::~Abstract_h1() {}

    Class_h1::Class_h1() : Abstract_h1::Abstract_h1() {
      vx_core::refcount += 1;
    }

    Class_h1::~Class_h1() {
      vx_core::refcount -= 1;
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_style,
        this->vx_p_text
      });
    }

    // id()
    vx_core::Type_string Class_h1::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_h1::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style();
      }
      return output;
    }

    // text()
    vx_core::Type_string Class_h1::text() const {
      vx_core::Type_string output = this->vx_p_text;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_h1::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
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
      output[":style"] = this->style();
      output[":text"] = this->text();
      return output;
    }

    vx_core::Type_any Class_h1::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_h1(), vals);
    }

    vx_core::Type_any Class_h1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_h1 output = vx_web_html::e_h1();
      vx_web_html::Type_h1 val = vx_core::vx_any_from_any(vx_web_html::t_h1(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_core::Type_string vx_p_text = val->text();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":text") {
            key = testkey;
          } else if (valsubtype == vx_core::t_string()) { // default property
            vx_p_text = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new h1) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new h1 :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style()) {
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new h1 :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":text") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_text = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new h1 :text " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new h1) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_web_html::Class_h1();
      if (output->vx_p_id != vx_p_id) {
        if (output->vx_p_id) {
          vx_core::vx_release_one(output->vx_p_id);
        }
        output->vx_p_id = vx_p_id;
        vx_core::vx_reserve(vx_p_id);
      }
      if (output->vx_p_style != vx_p_style) {
        if (output->vx_p_style) {
          vx_core::vx_release_one(output->vx_p_style);
        }
        output->vx_p_style = vx_p_style;
        vx_core::vx_reserve(vx_p_style);
      }
      if (output->vx_p_text != vx_p_text) {
        if (output->vx_p_text) {
          vx_core::vx_release_one(output->vx_p_text);
        }
        output->vx_p_text = vx_p_text;
        vx_core::vx_reserve(vx_p_text);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_h1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_h1::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_h1::vx_empty() const {return vx_web_html::e_h1();}
    vx_core::Type_any Class_h1::vx_type() const {return vx_web_html::t_h1();}

    vx_core::Type_typedef Class_h1::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "h1", // name
        ":struct", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_node(), vx_web_html::t_divchild()}), // traits
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

  // (type h2)
  // class Class_h2 {
    Abstract_h2::~Abstract_h2() {}

    Class_h2::Class_h2() : Abstract_h2::Abstract_h2() {
      vx_core::refcount += 1;
    }

    Class_h2::~Class_h2() {
      vx_core::refcount -= 1;
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_style,
        this->vx_p_text
      });
    }

    // id()
    vx_core::Type_string Class_h2::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_h2::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style();
      }
      return output;
    }

    // text()
    vx_core::Type_string Class_h2::text() const {
      vx_core::Type_string output = this->vx_p_text;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_h2::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
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
      output[":style"] = this->style();
      output[":text"] = this->text();
      return output;
    }

    vx_core::Type_any Class_h2::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_h2(), vals);
    }

    vx_core::Type_any Class_h2::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_h2 output = vx_web_html::e_h2();
      vx_web_html::Type_h2 val = vx_core::vx_any_from_any(vx_web_html::t_h2(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_core::Type_string vx_p_text = val->text();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":text") {
            key = testkey;
          } else if (valsubtype == vx_core::t_string()) { // default property
            vx_p_text = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new h2) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new h2 :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style()) {
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new h2 :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":text") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_text = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new h2 :text " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new h2) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_web_html::Class_h2();
      if (output->vx_p_id != vx_p_id) {
        if (output->vx_p_id) {
          vx_core::vx_release_one(output->vx_p_id);
        }
        output->vx_p_id = vx_p_id;
        vx_core::vx_reserve(vx_p_id);
      }
      if (output->vx_p_style != vx_p_style) {
        if (output->vx_p_style) {
          vx_core::vx_release_one(output->vx_p_style);
        }
        output->vx_p_style = vx_p_style;
        vx_core::vx_reserve(vx_p_style);
      }
      if (output->vx_p_text != vx_p_text) {
        if (output->vx_p_text) {
          vx_core::vx_release_one(output->vx_p_text);
        }
        output->vx_p_text = vx_p_text;
        vx_core::vx_reserve(vx_p_text);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_h2::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_h2::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_h2::vx_empty() const {return vx_web_html::e_h2();}
    vx_core::Type_any Class_h2::vx_type() const {return vx_web_html::t_h2();}

    vx_core::Type_typedef Class_h2::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "h2", // name
        ":struct", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_node(), vx_web_html::t_divchild()}), // traits
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

  // (type h3)
  // class Class_h3 {
    Abstract_h3::~Abstract_h3() {}

    Class_h3::Class_h3() : Abstract_h3::Abstract_h3() {
      vx_core::refcount += 1;
    }

    Class_h3::~Class_h3() {
      vx_core::refcount -= 1;
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_style,
        this->vx_p_text
      });
    }

    // id()
    vx_core::Type_string Class_h3::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_h3::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style();
      }
      return output;
    }

    // text()
    vx_core::Type_string Class_h3::text() const {
      vx_core::Type_string output = this->vx_p_text;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_h3::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
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
      output[":style"] = this->style();
      output[":text"] = this->text();
      return output;
    }

    vx_core::Type_any Class_h3::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_h3(), vals);
    }

    vx_core::Type_any Class_h3::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_h3 output = vx_web_html::e_h3();
      vx_web_html::Type_h3 val = vx_core::vx_any_from_any(vx_web_html::t_h3(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_core::Type_string vx_p_text = val->text();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":text") {
            key = testkey;
          } else if (valsubtype == vx_core::t_string()) { // default property
            vx_p_text = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new h3) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new h3 :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style()) {
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new h3 :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":text") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_text = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new h3 :text " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new h3) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_web_html::Class_h3();
      if (output->vx_p_id != vx_p_id) {
        if (output->vx_p_id) {
          vx_core::vx_release_one(output->vx_p_id);
        }
        output->vx_p_id = vx_p_id;
        vx_core::vx_reserve(vx_p_id);
      }
      if (output->vx_p_style != vx_p_style) {
        if (output->vx_p_style) {
          vx_core::vx_release_one(output->vx_p_style);
        }
        output->vx_p_style = vx_p_style;
        vx_core::vx_reserve(vx_p_style);
      }
      if (output->vx_p_text != vx_p_text) {
        if (output->vx_p_text) {
          vx_core::vx_release_one(output->vx_p_text);
        }
        output->vx_p_text = vx_p_text;
        vx_core::vx_reserve(vx_p_text);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_h3::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_h3::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_h3::vx_empty() const {return vx_web_html::e_h3();}
    vx_core::Type_any Class_h3::vx_type() const {return vx_web_html::t_h3();}

    vx_core::Type_typedef Class_h3::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "h3", // name
        ":struct", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_node(), vx_web_html::t_divchild()}), // traits
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

  // (type head)
  // class Class_head {
    Abstract_head::~Abstract_head() {}

    Class_head::Class_head() : Abstract_head::Abstract_head() {
      vx_core::refcount += 1;
    }

    Class_head::~Class_head() {
      vx_core::refcount -= 1;
      vx_core::vx_release_one({
        this->vx_p_nodes
      });
    }

    // nodes()
    vx_web_html::Type_headchildlist Class_head::nodes() const {
      vx_web_html::Type_headchildlist output = this->vx_p_nodes;
      if (!output) {
        output = vx_web_html::e_headchildlist();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_head::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
      return this->vx_copy(vx_web_html::e_head(), vals);
    }

    vx_core::Type_any Class_head::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_head output = vx_web_html::e_head();
      vx_web_html::Type_head val = vx_core::vx_any_from_any(vx_web_html::t_head(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_web_html::Type_headchildlist vx_p_nodes = val->nodes();
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
          } else if (testkey == ":nodes") {
            key = testkey;
          } else if (valsubtype == vx_web_html::t_headchildlist()) { // default property
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_headchildlist(), valsub);
          } else if (valsubtype == vx_web_html::t_headchild()) { // default property
            vx_web_html::Type_headchild valdefault = vx_core::vx_any_from_any(vx_web_html::t_headchild(), valsub);
            vx_web_html::Type_headchildlist vallist = output->vx_p_nodes;
            if (!vallist) {
              vallist = vx_core::vx_new(vx_web_html::t_headchildlist(), {valdefault});
            } else {
              vallist = vx_core::vx_copy(vx_web_html::t_headchildlist(), {valdefault});
            }
            vx_p_nodes = vallist;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new head) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":nodes") {
            if (valsubtype == vx_web_html::t_headchildlist()) {
              vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_headchildlist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new head :nodes " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new head) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_web_html::Class_head();
      if (output->vx_p_nodes != vx_p_nodes) {
        if (output->vx_p_nodes) {
          vx_core::vx_release_one(output->vx_p_nodes);
        }
        output->vx_p_nodes = vx_p_nodes;
        vx_core::vx_reserve(vx_p_nodes);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_head::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_head::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_head::vx_empty() const {return vx_web_html::e_head();}
    vx_core::Type_any Class_head::vx_type() const {return vx_web_html::t_head();}

    vx_core::Type_typedef Class_head::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "head", // name
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

  // (type headchild)
  // class Class_headchild {
    Abstract_headchild::~Abstract_headchild() {}

    Class_headchild::Class_headchild() : Abstract_headchild::Abstract_headchild() {
      vx_core::refcount += 1;
    }

    Class_headchild::~Class_headchild() {
      vx_core::refcount -= 1;
      vx_core::vx_release_one({
        
      });
    }

    // vx_get_any(key)
    vx_core::Type_any Class_headchild::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
      return this->vx_copy(vx_web_html::e_headchild(), vals);
    }

    vx_core::Type_any Class_headchild::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_headchild output = vx_web_html::e_headchild();
      vx_web_html::Type_headchild val = vx_core::vx_any_from_any(vx_web_html::t_headchild(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_headchild::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_headchild::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_headchild::vx_empty() const {return vx_web_html::e_headchild();}
    vx_core::Type_any Class_headchild::vx_type() const {return vx_web_html::t_headchild();}

    vx_core::Type_typedef Class_headchild::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "headchild", // name
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

  // (type headchildlist)
  // class Class_headchildlist {
    Abstract_headchildlist::~Abstract_headchildlist() {}

    Class_headchildlist::Class_headchildlist() : Abstract_headchildlist::Abstract_headchildlist() {
      vx_core::refcount += 1;
    }

    Class_headchildlist::~Class_headchildlist() {
      vx_core::refcount -= 1;
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_headchildlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_web_html::Type_headchild Class_headchildlist::vx_get_headchild(vx_core::Type_int index) const {
      vx_web_html::Type_headchild output = vx_web_html::e_headchild();
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
      vx_web_html::Type_headchildlist output = vx_web_html::e_headchildlist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_web_html::Type_headchild> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_web_html::t_headchild()) {
          vx_web_html::Type_headchild castval = vx_core::vx_any_from_any(vx_web_html::t_headchild(), valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(headchildlist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_web_html::Class_headchildlist();
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

    vx_core::Type_any Class_headchildlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_headchildlist(), vals);
    }

    vx_core::Type_any Class_headchildlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_headchildlist output = vx_web_html::e_headchildlist();
      vx_web_html::Type_headchildlist val = vx_core::vx_any_from_any(vx_web_html::t_headchildlist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_web_html::Type_headchild> listval = val->vx_listheadchild();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_web_html::t_headchild()) {
          listval.push_back(vx_core::vx_any_from_any(vx_web_html::t_headchild(), valsub));
        } else if (valsubtype == vx_web_html::t_headchildlist()) {
          vx_web_html::Type_headchildlist multi = vx_core::vx_any_from_any(vx_web_html::t_headchildlist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listheadchild());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new headchildlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_web_html::Class_headchildlist();
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

    vx_core::Type_msgblock Class_headchildlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_headchildlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_headchildlist::vx_empty() const {return vx_web_html::e_headchildlist();}
    vx_core::Type_any Class_headchildlist::vx_type() const {return vx_web_html::t_headchildlist();}

    vx_core::Type_typedef Class_headchildlist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "headchildlist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_headchild()}), // allowtypes
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

  // (type html)
  // class Class_html {
    Abstract_html::~Abstract_html() {}

    Class_html::Class_html() : Abstract_html::Abstract_html() {
      vx_core::refcount += 1;
    }

    Class_html::~Class_html() {
      vx_core::refcount -= 1;
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
        output = vx_core::e_string();
      }
      return output;
    }

    // head()
    vx_web_html::Type_head Class_html::head() const {
      vx_web_html::Type_head output = this->vx_p_head;
      if (!output) {
        output = vx_web_html::e_head();
      }
      return output;
    }

    // body()
    vx_web_html::Type_body Class_html::body() const {
      vx_web_html::Type_body output = this->vx_p_body;
      if (!output) {
        output = vx_web_html::e_body();
      }
      return output;
    }

    // footer()
    vx_web_html::Type_footer Class_html::footer() const {
      vx_web_html::Type_footer output = this->vx_p_footer;
      if (!output) {
        output = vx_web_html::e_footer();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_html::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
      return this->vx_copy(vx_web_html::e_html(), vals);
    }

    vx_core::Type_any Class_html::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_html output = vx_web_html::e_html();
      vx_web_html::Type_html val = vx_core::vx_any_from_any(vx_web_html::t_html(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_lang = val->lang();
      vx_web_html::Type_head vx_p_head = val->head();
      vx_web_html::Type_body vx_p_body = val->body();
      vx_web_html::Type_footer vx_p_footer = val->footer();
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
          } else if (testkey == ":lang") {
            key = testkey;
          } else if (testkey == ":head") {
            key = testkey;
          } else if (testkey == ":body") {
            key = testkey;
          } else if (testkey == ":footer") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new html) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":lang") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_lang = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new html :lang " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":head") {
            if (valsubtype == vx_web_html::t_head()) {
              vx_p_head = vx_core::vx_any_from_any(vx_web_html::t_head(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new html :head " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":body") {
            if (valsubtype == vx_web_html::t_body()) {
              vx_p_body = vx_core::vx_any_from_any(vx_web_html::t_body(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new html :body " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":footer") {
            if (valsubtype == vx_web_html::t_footer()) {
              vx_p_footer = vx_core::vx_any_from_any(vx_web_html::t_footer(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new html :footer " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new html) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
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
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_html::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_html::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_html::vx_empty() const {return vx_web_html::e_html();}
    vx_core::Type_any Class_html::vx_type() const {return vx_web_html::t_html();}

    vx_core::Type_typedef Class_html::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "html", // name
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

  // (type meta)
  // class Class_meta {
    Abstract_meta::~Abstract_meta() {}

    Class_meta::Class_meta() : Abstract_meta::Abstract_meta() {
      vx_core::refcount += 1;
    }

    Class_meta::~Class_meta() {
      vx_core::refcount -= 1;
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_style,
        this->vx_p_charset
      });
    }

    // id()
    vx_core::Type_string Class_meta::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_meta::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style();
      }
      return output;
    }

    // charset()
    vx_core::Type_string Class_meta::charset() const {
      vx_core::Type_string output = this->vx_p_charset;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_meta::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":charset") {
        output = this->charset();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_meta::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":style"] = this->style();
      output[":charset"] = this->charset();
      return output;
    }

    vx_core::Type_any Class_meta::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_meta(), vals);
    }

    vx_core::Type_any Class_meta::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_meta output = vx_web_html::e_meta();
      vx_web_html::Type_meta val = vx_core::vx_any_from_any(vx_web_html::t_meta(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_core::Type_string vx_p_charset = val->charset();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":charset") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new meta) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new meta :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style()) {
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new meta :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":charset") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_charset = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new meta :charset " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new meta) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_web_html::Class_meta();
      if (output->vx_p_id != vx_p_id) {
        if (output->vx_p_id) {
          vx_core::vx_release_one(output->vx_p_id);
        }
        output->vx_p_id = vx_p_id;
        vx_core::vx_reserve(vx_p_id);
      }
      if (output->vx_p_style != vx_p_style) {
        if (output->vx_p_style) {
          vx_core::vx_release_one(output->vx_p_style);
        }
        output->vx_p_style = vx_p_style;
        vx_core::vx_reserve(vx_p_style);
      }
      if (output->vx_p_charset != vx_p_charset) {
        if (output->vx_p_charset) {
          vx_core::vx_release_one(output->vx_p_charset);
        }
        output->vx_p_charset = vx_p_charset;
        vx_core::vx_reserve(vx_p_charset);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_meta::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_meta::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_meta::vx_empty() const {return vx_web_html::e_meta();}
    vx_core::Type_any Class_meta::vx_type() const {return vx_web_html::t_meta();}

    vx_core::Type_typedef Class_meta::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "meta", // name
        ":struct", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_node(), vx_web_html::t_headchild()}), // traits
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

  // (type nodelist)
  // class Class_nodelist {
    Abstract_nodelist::~Abstract_nodelist() {}

    Class_nodelist::Class_nodelist() : Abstract_nodelist::Abstract_nodelist() {
      vx_core::refcount += 1;
    }

    Class_nodelist::~Class_nodelist() {
      vx_core::refcount -= 1;
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_nodelist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_web_html::Type_node Class_nodelist::vx_get_node(vx_core::Type_int index) const {
      vx_web_html::Type_node output = vx_web_html::e_node();
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
      vx_web_html::Type_nodelist output = vx_web_html::e_nodelist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_web_html::Type_node> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_web_html::t_node()) {
          vx_web_html::Type_node castval = vx_core::vx_any_from_any(vx_web_html::t_node(), valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(nodelist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_web_html::Class_nodelist();
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

    vx_core::Type_any Class_nodelist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_nodelist(), vals);
    }

    vx_core::Type_any Class_nodelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_nodelist output = vx_web_html::e_nodelist();
      vx_web_html::Type_nodelist val = vx_core::vx_any_from_any(vx_web_html::t_nodelist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_web_html::Type_node> listval = val->vx_listnode();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_web_html::t_node()) {
          listval.push_back(vx_core::vx_any_from_any(vx_web_html::t_node(), valsub));
        } else if (valsubtype == vx_web_html::t_nodelist()) {
          vx_web_html::Type_nodelist multi = vx_core::vx_any_from_any(vx_web_html::t_nodelist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listnode());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new nodelist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_web_html::Class_nodelist();
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

    vx_core::Type_msgblock Class_nodelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_nodelist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_nodelist::vx_empty() const {return vx_web_html::e_nodelist();}
    vx_core::Type_any Class_nodelist::vx_type() const {return vx_web_html::t_nodelist();}

    vx_core::Type_typedef Class_nodelist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "nodelist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_node()}), // allowtypes
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

  // (type p)
  // class Class_p {
    Abstract_p::~Abstract_p() {}

    Class_p::Class_p() : Abstract_p::Abstract_p() {
      vx_core::refcount += 1;
    }

    Class_p::~Class_p() {
      vx_core::refcount -= 1;
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_style,
        this->vx_p_text
      });
    }

    // id()
    vx_core::Type_string Class_p::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_p::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style();
      }
      return output;
    }

    // text()
    vx_core::Type_string Class_p::text() const {
      vx_core::Type_string output = this->vx_p_text;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_p::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
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
      output[":style"] = this->style();
      output[":text"] = this->text();
      return output;
    }

    vx_core::Type_any Class_p::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_p(), vals);
    }

    vx_core::Type_any Class_p::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_p output = vx_web_html::e_p();
      vx_web_html::Type_p val = vx_core::vx_any_from_any(vx_web_html::t_p(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_core::Type_string vx_p_text = val->text();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":text") {
            key = testkey;
          } else if (valsubtype == vx_core::t_string()) { // default property
            vx_p_text = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new p) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new p :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style()) {
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new p :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":text") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_text = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new p :text " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new p) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_web_html::Class_p();
      if (output->vx_p_id != vx_p_id) {
        if (output->vx_p_id) {
          vx_core::vx_release_one(output->vx_p_id);
        }
        output->vx_p_id = vx_p_id;
        vx_core::vx_reserve(vx_p_id);
      }
      if (output->vx_p_style != vx_p_style) {
        if (output->vx_p_style) {
          vx_core::vx_release_one(output->vx_p_style);
        }
        output->vx_p_style = vx_p_style;
        vx_core::vx_reserve(vx_p_style);
      }
      if (output->vx_p_text != vx_p_text) {
        if (output->vx_p_text) {
          vx_core::vx_release_one(output->vx_p_text);
        }
        output->vx_p_text = vx_p_text;
        vx_core::vx_reserve(vx_p_text);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_p::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_p::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_p::vx_empty() const {return vx_web_html::e_p();}
    vx_core::Type_any Class_p::vx_type() const {return vx_web_html::t_p();}

    vx_core::Type_typedef Class_p::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "p", // name
        ":struct", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_node(), vx_web_html::t_divchild()}), // traits
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

  // (type propmap)
  // class Class_propmap {
    Abstract_propmap::~Abstract_propmap() {}

    Class_propmap::Class_propmap() : Abstract_propmap::Abstract_propmap() {
      vx_core::refcount += 1;
    }

    Class_propmap::~Class_propmap() {
      vx_core::refcount -= 1;
      for (auto const& [key, val] : this->vx_p_map) {
        vx_core::vx_release_one(val);
      }
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_propmap::vx_map() const {
      vx_core::vx_Type_mapany output = vx_core::vx_map_from_map(vx_core::t_any(), this->vx_p_map);
      return output;
    }

    // vx_get_string(key)
    vx_core::Type_string Class_propmap::vx_get_string(vx_core::Type_string key) const {
      vx_core::Type_string output = vx_core::e_string();
      const vx_web_html::Class_propmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_string> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_core::e_string());
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
      vx_web_html::Type_propmap output = vx_web_html::e_propmap();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::map<std::string, vx_core::Type_string> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_string()) {
          vx_core::Type_string castval = vx_core::vx_any_from_any(vx_core::t_string(), val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(propmap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_web_html::Class_propmap();
      output->vx_p_map = map;
      for (auto const& [key, val] : map) {
        vx_core::vx_reserve(val);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      for (auto const& [key, val] : mapval) {
        vx_core::vx_release_except(val, output);
      }
      return output;
    }

    vx_core::Type_any Class_propmap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_propmap(), vals);
    }

    vx_core::Type_any Class_propmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_propmap output = vx_web_html::e_propmap();
      vx_web_html::Type_propmap valmap = vx_core::vx_any_from_any(vx_web_html::t_propmap(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_core::Type_string> mapval;
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          if (valsubtype == vx_core::t_string()) {
            vx_core::Type_string valstring = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            key = valstring->vx_string();
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("Key Expected: " + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          vx_core::Type_string valany = NULL;
          if (valsubtype == vx_core::t_string()) {
            valany = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
          } else if (valsubtype == vx_core::t_string()) {
            valany = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("Invalid Key/Value: " + key + " "  + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          if (valany) {
            mapval[key] = valany;
            key = "";
          }
        }
      }
      output = new vx_web_html::Class_propmap();
      output->vx_p_map = mapval;
      for (auto const& [key, val] : mapval) {
        vx_core::vx_reserve(val);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_propmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_propmap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_propmap::vx_empty() const {return vx_web_html::e_propmap();}
    vx_core::Type_any Class_propmap::vx_type() const {return vx_web_html::t_propmap();}

    vx_core::Type_typedef Class_propmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "propmap", // name
        ":map", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_string()}), // allowtypes
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

  // (type style)
  // class Class_style {
    Abstract_style::~Abstract_style() {}

    Class_style::Class_style() : Abstract_style::Abstract_style() {
      vx_core::refcount += 1;
    }

    Class_style::~Class_style() {
      vx_core::refcount -= 1;
      vx_core::vx_release_one({
        this->vx_p_name,
        this->vx_p_props
      });
    }

    // name()
    vx_core::Type_string Class_style::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // props()
    vx_web_html::Type_propmap Class_style::props() const {
      vx_web_html::Type_propmap output = this->vx_p_props;
      if (!output) {
        output = vx_web_html::e_propmap();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_style::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":props") {
        output = this->props();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_style::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":name"] = this->name();
      output[":props"] = this->props();
      return output;
    }

    vx_core::Type_any Class_style::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_style(), vals);
    }

    vx_core::Type_any Class_style::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_style output = vx_web_html::e_style();
      vx_web_html::Type_style val = vx_core::vx_any_from_any(vx_web_html::t_style(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_name = val->name();
      vx_web_html::Type_propmap vx_p_props = val->props();
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
          } else if (testkey == ":name") {
            key = testkey;
          } else if (testkey == ":props") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new style) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new style :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":props") {
            if (valsubtype == vx_web_html::t_propmap()) {
              vx_p_props = vx_core::vx_any_from_any(vx_web_html::t_propmap(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new style :props " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new style) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
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
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_style::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_style::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_style::vx_empty() const {return vx_web_html::e_style();}
    vx_core::Type_any Class_style::vx_type() const {return vx_web_html::t_style();}

    vx_core::Type_typedef Class_style::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "style", // name
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

  // (type stylelist)
  // class Class_stylelist {
    Abstract_stylelist::~Abstract_stylelist() {}

    Class_stylelist::Class_stylelist() : Abstract_stylelist::Abstract_stylelist() {
      vx_core::refcount += 1;
    }

    Class_stylelist::~Class_stylelist() {
      vx_core::refcount -= 1;
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_stylelist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_web_html::Type_style Class_stylelist::vx_get_style(vx_core::Type_int index) const {
      vx_web_html::Type_style output = vx_web_html::e_style();
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
      vx_web_html::Type_stylelist output = vx_web_html::e_stylelist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_web_html::Type_style> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_web_html::t_style()) {
          vx_web_html::Type_style castval = vx_core::vx_any_from_any(vx_web_html::t_style(), valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(stylelist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_web_html::Class_stylelist();
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

    vx_core::Type_any Class_stylelist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_stylelist(), vals);
    }

    vx_core::Type_any Class_stylelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_stylelist output = vx_web_html::e_stylelist();
      vx_web_html::Type_stylelist val = vx_core::vx_any_from_any(vx_web_html::t_stylelist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_web_html::Type_style> listval = val->vx_liststyle();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_web_html::t_style()) {
          listval.push_back(vx_core::vx_any_from_any(vx_web_html::t_style(), valsub));
        } else if (valsubtype == vx_web_html::t_stylelist()) {
          vx_web_html::Type_stylelist multi = vx_core::vx_any_from_any(vx_web_html::t_stylelist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_liststyle());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new stylelist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_web_html::Class_stylelist();
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

    vx_core::Type_msgblock Class_stylelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_stylelist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_stylelist::vx_empty() const {return vx_web_html::e_stylelist();}
    vx_core::Type_any Class_stylelist::vx_type() const {return vx_web_html::t_stylelist();}

    vx_core::Type_typedef Class_stylelist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "stylelist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_style()}), // allowtypes
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

  // (type stylemap)
  // class Class_stylemap {
    Abstract_stylemap::~Abstract_stylemap() {}

    Class_stylemap::Class_stylemap() : Abstract_stylemap::Abstract_stylemap() {
      vx_core::refcount += 1;
    }

    Class_stylemap::~Class_stylemap() {
      vx_core::refcount -= 1;
      for (auto const& [key, val] : this->vx_p_map) {
        vx_core::vx_release_one(val);
      }
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_stylemap::vx_map() const {
      vx_core::vx_Type_mapany output = vx_core::vx_map_from_map(vx_core::t_any(), this->vx_p_map);
      return output;
    }

    // vx_get_style(key)
    vx_web_html::Type_style Class_stylemap::vx_get_style(vx_core::Type_string key) const {
      vx_web_html::Type_style output = vx_web_html::e_style();
      const vx_web_html::Class_stylemap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_web_html::Type_style> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_web_html::e_style());
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
      vx_web_html::Type_stylemap output = vx_web_html::e_stylemap();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::map<std::string, vx_web_html::Type_style> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_web_html::t_style()) {
          vx_web_html::Type_style castval = vx_core::vx_any_from_any(vx_web_html::t_style(), val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(stylemap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_web_html::Class_stylemap();
      output->vx_p_map = map;
      for (auto const& [key, val] : map) {
        vx_core::vx_reserve(val);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      for (auto const& [key, val] : mapval) {
        vx_core::vx_release_except(val, output);
      }
      return output;
    }

    vx_core::Type_any Class_stylemap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_stylemap(), vals);
    }

    vx_core::Type_any Class_stylemap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_stylemap output = vx_web_html::e_stylemap();
      vx_web_html::Type_stylemap valmap = vx_core::vx_any_from_any(vx_web_html::t_stylemap(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_web_html::Type_style> mapval;
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (key == "") {
          if (valsubtype == vx_core::t_string()) {
            vx_core::Type_string valstring = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            key = valstring->vx_string();
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("Key Expected: " + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          vx_web_html::Type_style valany = NULL;
          if (valsubtype == vx_web_html::t_style()) {
            valany = vx_core::vx_any_from_any(vx_web_html::t_style(), valsub);
          } else if (valsubtype == vx_web_html::t_style()) {
            valany = vx_core::vx_any_from_any(vx_web_html::t_style(), valsub);
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("Invalid Key/Value: " + key + " "  + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          if (valany) {
            mapval[key] = valany;
            key = "";
          }
        }
      }
      output = new vx_web_html::Class_stylemap();
      output->vx_p_map = mapval;
      for (auto const& [key, val] : mapval) {
        vx_core::vx_reserve(val);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_stylemap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_stylemap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_stylemap::vx_empty() const {return vx_web_html::e_stylemap();}
    vx_core::Type_any Class_stylemap::vx_type() const {return vx_web_html::t_stylemap();}

    vx_core::Type_typedef Class_stylemap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "stylemap", // name
        ":map", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_style()}), // allowtypes
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

  // (type stylesheet)
  // class Class_stylesheet {
    Abstract_stylesheet::~Abstract_stylesheet() {}

    Class_stylesheet::Class_stylesheet() : Abstract_stylesheet::Abstract_stylesheet() {
      vx_core::refcount += 1;
    }

    Class_stylesheet::~Class_stylesheet() {
      vx_core::refcount -= 1;
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_style,
        this->vx_p_name,
        this->vx_p_styles,
        this->vx_p_stylemap
      });
    }

    // id()
    vx_core::Type_string Class_stylesheet::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_stylesheet::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style();
      }
      return output;
    }

    // name()
    vx_core::Type_string Class_stylesheet::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // styles()
    vx_web_html::Type_stylelist Class_stylesheet::styles() const {
      vx_web_html::Type_stylelist output = this->vx_p_styles;
      if (!output) {
        output = vx_web_html::e_stylelist();
      }
      return output;
    }

    // stylemap()
    vx_web_html::Type_stylemap Class_stylesheet::stylemap() const {
      vx_web_html::Type_stylemap output = this->vx_p_stylemap;
      if (!output) {
        output = vx_web_html::e_stylemap();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_stylesheet::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_stylesheet::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":style"] = this->style();
      output[":name"] = this->name();
      output[":styles"] = this->styles();
      output[":stylemap"] = this->stylemap();
      return output;
    }

    vx_core::Type_any Class_stylesheet::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_stylesheet(), vals);
    }

    vx_core::Type_any Class_stylesheet::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_stylesheet output = vx_web_html::e_stylesheet();
      vx_web_html::Type_stylesheet val = vx_core::vx_any_from_any(vx_web_html::t_stylesheet(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_core::Type_string vx_p_name = val->name();
      vx_web_html::Type_stylelist vx_p_styles = val->styles();
      vx_web_html::Type_stylemap vx_p_stylemap = val->stylemap();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":name") {
            key = testkey;
          } else if (testkey == ":styles") {
            key = testkey;
          } else if (testkey == ":stylemap") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new stylesheet) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new stylesheet :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style()) {
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new stylesheet :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new stylesheet :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":styles") {
            if (valsubtype == vx_web_html::t_stylelist()) {
              vx_p_styles = vx_core::vx_any_from_any(vx_web_html::t_stylelist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new stylesheet :styles " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":stylemap") {
            if (valsubtype == vx_web_html::t_stylemap()) {
              vx_p_stylemap = vx_core::vx_any_from_any(vx_web_html::t_stylemap(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new stylesheet :stylemap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new stylesheet) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_web_html::Class_stylesheet();
      if (output->vx_p_id != vx_p_id) {
        if (output->vx_p_id) {
          vx_core::vx_release_one(output->vx_p_id);
        }
        output->vx_p_id = vx_p_id;
        vx_core::vx_reserve(vx_p_id);
      }
      if (output->vx_p_style != vx_p_style) {
        if (output->vx_p_style) {
          vx_core::vx_release_one(output->vx_p_style);
        }
        output->vx_p_style = vx_p_style;
        vx_core::vx_reserve(vx_p_style);
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
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_stylesheet::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_stylesheet::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_stylesheet::vx_empty() const {return vx_web_html::e_stylesheet();}
    vx_core::Type_any Class_stylesheet::vx_type() const {return vx_web_html::t_stylesheet();}

    vx_core::Type_typedef Class_stylesheet::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "stylesheet", // name
        ":struct", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_node(), vx_web_html::t_headchild()}), // traits
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

  // (type table)
  // class Class_table {
    Abstract_table::~Abstract_table() {}

    Class_table::Class_table() : Abstract_table::Abstract_table() {
      vx_core::refcount += 1;
    }

    Class_table::~Class_table() {
      vx_core::refcount -= 1;
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_style,
        this->vx_p_tbody,
        this->vx_p_thead
      });
    }

    // id()
    vx_core::Type_string Class_table::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_table::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style();
      }
      return output;
    }

    // tbody()
    vx_web_html::Type_tbody Class_table::tbody() const {
      vx_web_html::Type_tbody output = this->vx_p_tbody;
      if (!output) {
        output = vx_web_html::e_tbody();
      }
      return output;
    }

    // thead()
    vx_web_html::Type_thead Class_table::thead() const {
      vx_web_html::Type_thead output = this->vx_p_thead;
      if (!output) {
        output = vx_web_html::e_thead();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_table::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
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
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_table::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      output[":style"] = this->style();
      output[":tbody"] = this->tbody();
      output[":thead"] = this->thead();
      return output;
    }

    vx_core::Type_any Class_table::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_table(), vals);
    }

    vx_core::Type_any Class_table::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_table output = vx_web_html::e_table();
      vx_web_html::Type_table val = vx_core::vx_any_from_any(vx_web_html::t_table(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_web_html::Type_tbody vx_p_tbody = val->tbody();
      vx_web_html::Type_thead vx_p_thead = val->thead();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":tbody") {
            key = testkey;
          } else if (testkey == ":thead") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new table) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new table :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style()) {
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new table :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":tbody") {
            if (valsubtype == vx_web_html::t_tbody()) {
              vx_p_tbody = vx_core::vx_any_from_any(vx_web_html::t_tbody(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new table :tbody " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":thead") {
            if (valsubtype == vx_web_html::t_thead()) {
              vx_p_thead = vx_core::vx_any_from_any(vx_web_html::t_thead(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new table :thead " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new table) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_web_html::Class_table();
      if (output->vx_p_id != vx_p_id) {
        if (output->vx_p_id) {
          vx_core::vx_release_one(output->vx_p_id);
        }
        output->vx_p_id = vx_p_id;
        vx_core::vx_reserve(vx_p_id);
      }
      if (output->vx_p_style != vx_p_style) {
        if (output->vx_p_style) {
          vx_core::vx_release_one(output->vx_p_style);
        }
        output->vx_p_style = vx_p_style;
        vx_core::vx_reserve(vx_p_style);
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
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_table::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_table::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_table::vx_empty() const {return vx_web_html::e_table();}
    vx_core::Type_any Class_table::vx_type() const {return vx_web_html::t_table();}

    vx_core::Type_typedef Class_table::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "table", // name
        ":struct", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_node(), vx_web_html::t_divchild()}), // traits
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

  // (type tbody)
  // class Class_tbody {
    Abstract_tbody::~Abstract_tbody() {}

    Class_tbody::Class_tbody() : Abstract_tbody::Abstract_tbody() {
      vx_core::refcount += 1;
    }

    Class_tbody::~Class_tbody() {
      vx_core::refcount -= 1;
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_style,
        this->vx_p_nodes
      });
    }

    // id()
    vx_core::Type_string Class_tbody::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_tbody::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style();
      }
      return output;
    }

    // nodes()
    vx_web_html::Type_trlist Class_tbody::nodes() const {
      vx_web_html::Type_trlist output = this->vx_p_nodes;
      if (!output) {
        output = vx_web_html::e_trlist();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_tbody::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
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
      output[":style"] = this->style();
      output[":nodes"] = this->nodes();
      return output;
    }

    vx_core::Type_any Class_tbody::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_tbody(), vals);
    }

    vx_core::Type_any Class_tbody::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_tbody output = vx_web_html::e_tbody();
      vx_web_html::Type_tbody val = vx_core::vx_any_from_any(vx_web_html::t_tbody(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_web_html::Type_trlist vx_p_nodes = val->nodes();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":nodes") {
            key = testkey;
          } else if (valsubtype == vx_web_html::t_trlist()) { // default property
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_trlist(), valsub);
          } else if (valsubtype == vx_web_html::t_tr()) { // default property
            vx_web_html::Type_tr valdefault = vx_core::vx_any_from_any(vx_web_html::t_tr(), valsub);
            vx_web_html::Type_trlist vallist = output->vx_p_nodes;
            if (!vallist) {
              vallist = vx_core::vx_new(vx_web_html::t_trlist(), {valdefault});
            } else {
              vallist = vx_core::vx_copy(vx_web_html::t_trlist(), {valdefault});
            }
            vx_p_nodes = vallist;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new tbody) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new tbody :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style()) {
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new tbody :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":nodes") {
            if (valsubtype == vx_web_html::t_trlist()) {
              vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_trlist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new tbody :nodes " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new tbody) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_web_html::Class_tbody();
      if (output->vx_p_id != vx_p_id) {
        if (output->vx_p_id) {
          vx_core::vx_release_one(output->vx_p_id);
        }
        output->vx_p_id = vx_p_id;
        vx_core::vx_reserve(vx_p_id);
      }
      if (output->vx_p_style != vx_p_style) {
        if (output->vx_p_style) {
          vx_core::vx_release_one(output->vx_p_style);
        }
        output->vx_p_style = vx_p_style;
        vx_core::vx_reserve(vx_p_style);
      }
      if (output->vx_p_nodes != vx_p_nodes) {
        if (output->vx_p_nodes) {
          vx_core::vx_release_one(output->vx_p_nodes);
        }
        output->vx_p_nodes = vx_p_nodes;
        vx_core::vx_reserve(vx_p_nodes);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_tbody::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_tbody::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_tbody::vx_empty() const {return vx_web_html::e_tbody();}
    vx_core::Type_any Class_tbody::vx_type() const {return vx_web_html::t_tbody();}

    vx_core::Type_typedef Class_tbody::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "tbody", // name
        ":struct", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_node()}), // traits
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

  // (type td)
  // class Class_td {
    Abstract_td::~Abstract_td() {}

    Class_td::Class_td() : Abstract_td::Abstract_td() {
      vx_core::refcount += 1;
    }

    Class_td::~Class_td() {
      vx_core::refcount -= 1;
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_style,
        this->vx_p_nodes
      });
    }

    // id()
    vx_core::Type_string Class_td::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_td::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style();
      }
      return output;
    }

    // nodes()
    vx_web_html::Type_divchildlist Class_td::nodes() const {
      vx_web_html::Type_divchildlist output = this->vx_p_nodes;
      if (!output) {
        output = vx_web_html::e_divchildlist();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_td::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
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
      output[":style"] = this->style();
      output[":nodes"] = this->nodes();
      return output;
    }

    vx_core::Type_any Class_td::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_td(), vals);
    }

    vx_core::Type_any Class_td::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_td output = vx_web_html::e_td();
      vx_web_html::Type_td val = vx_core::vx_any_from_any(vx_web_html::t_td(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_web_html::Type_divchildlist vx_p_nodes = val->nodes();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":nodes") {
            key = testkey;
          } else if (valsubtype == vx_web_html::t_divchildlist()) { // default property
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_divchildlist(), valsub);
          } else if (valsubtype == vx_web_html::t_divchild()) { // default property
            vx_web_html::Type_divchild valdefault = vx_core::vx_any_from_any(vx_web_html::t_divchild(), valsub);
            vx_web_html::Type_divchildlist vallist = output->vx_p_nodes;
            if (!vallist) {
              vallist = vx_core::vx_new(vx_web_html::t_divchildlist(), {valdefault});
            } else {
              vallist = vx_core::vx_copy(vx_web_html::t_divchildlist(), {valdefault});
            }
            vx_p_nodes = vallist;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new td) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new td :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style()) {
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new td :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":nodes") {
            if (valsubtype == vx_web_html::t_divchildlist()) {
              vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_divchildlist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new td :nodes " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new td) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_web_html::Class_td();
      if (output->vx_p_id != vx_p_id) {
        if (output->vx_p_id) {
          vx_core::vx_release_one(output->vx_p_id);
        }
        output->vx_p_id = vx_p_id;
        vx_core::vx_reserve(vx_p_id);
      }
      if (output->vx_p_style != vx_p_style) {
        if (output->vx_p_style) {
          vx_core::vx_release_one(output->vx_p_style);
        }
        output->vx_p_style = vx_p_style;
        vx_core::vx_reserve(vx_p_style);
      }
      if (output->vx_p_nodes != vx_p_nodes) {
        if (output->vx_p_nodes) {
          vx_core::vx_release_one(output->vx_p_nodes);
        }
        output->vx_p_nodes = vx_p_nodes;
        vx_core::vx_reserve(vx_p_nodes);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_td::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_td::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_td::vx_empty() const {return vx_web_html::e_td();}
    vx_core::Type_any Class_td::vx_type() const {return vx_web_html::t_td();}

    vx_core::Type_typedef Class_td::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "td", // name
        ":struct", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_node()}), // traits
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

  // (type tdlist)
  // class Class_tdlist {
    Abstract_tdlist::~Abstract_tdlist() {}

    Class_tdlist::Class_tdlist() : Abstract_tdlist::Abstract_tdlist() {
      vx_core::refcount += 1;
    }

    Class_tdlist::~Class_tdlist() {
      vx_core::refcount -= 1;
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_tdlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_web_html::Type_td Class_tdlist::vx_get_td(vx_core::Type_int index) const {
      vx_web_html::Type_td output = vx_web_html::e_td();
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
      vx_web_html::Type_tdlist output = vx_web_html::e_tdlist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_web_html::Type_td> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_web_html::t_td()) {
          vx_web_html::Type_td castval = vx_core::vx_any_from_any(vx_web_html::t_td(), valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(tdlist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_web_html::Class_tdlist();
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

    vx_core::Type_any Class_tdlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_tdlist(), vals);
    }

    vx_core::Type_any Class_tdlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_tdlist output = vx_web_html::e_tdlist();
      vx_web_html::Type_tdlist val = vx_core::vx_any_from_any(vx_web_html::t_tdlist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_web_html::Type_td> listval = val->vx_listtd();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_web_html::t_td()) {
          listval.push_back(vx_core::vx_any_from_any(vx_web_html::t_td(), valsub));
        } else if (valsubtype == vx_web_html::t_tdlist()) {
          vx_web_html::Type_tdlist multi = vx_core::vx_any_from_any(vx_web_html::t_tdlist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listtd());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new tdlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_web_html::Class_tdlist();
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

    vx_core::Type_msgblock Class_tdlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_tdlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_tdlist::vx_empty() const {return vx_web_html::e_tdlist();}
    vx_core::Type_any Class_tdlist::vx_type() const {return vx_web_html::t_tdlist();}

    vx_core::Type_typedef Class_tdlist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "tdlist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_td()}), // allowtypes
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

  // (type thead)
  // class Class_thead {
    Abstract_thead::~Abstract_thead() {}

    Class_thead::Class_thead() : Abstract_thead::Abstract_thead() {
      vx_core::refcount += 1;
    }

    Class_thead::~Class_thead() {
      vx_core::refcount -= 1;
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_style,
        this->vx_p_nodes
      });
    }

    // id()
    vx_core::Type_string Class_thead::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_thead::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style();
      }
      return output;
    }

    // nodes()
    vx_web_html::Type_trlist Class_thead::nodes() const {
      vx_web_html::Type_trlist output = this->vx_p_nodes;
      if (!output) {
        output = vx_web_html::e_trlist();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_thead::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
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
      output[":style"] = this->style();
      output[":nodes"] = this->nodes();
      return output;
    }

    vx_core::Type_any Class_thead::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_thead(), vals);
    }

    vx_core::Type_any Class_thead::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_thead output = vx_web_html::e_thead();
      vx_web_html::Type_thead val = vx_core::vx_any_from_any(vx_web_html::t_thead(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_web_html::Type_trlist vx_p_nodes = val->nodes();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":nodes") {
            key = testkey;
          } else if (valsubtype == vx_web_html::t_trlist()) { // default property
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_trlist(), valsub);
          } else if (valsubtype == vx_web_html::t_tr()) { // default property
            vx_web_html::Type_tr valdefault = vx_core::vx_any_from_any(vx_web_html::t_tr(), valsub);
            vx_web_html::Type_trlist vallist = output->vx_p_nodes;
            if (!vallist) {
              vallist = vx_core::vx_new(vx_web_html::t_trlist(), {valdefault});
            } else {
              vallist = vx_core::vx_copy(vx_web_html::t_trlist(), {valdefault});
            }
            vx_p_nodes = vallist;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new thead) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new thead :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style()) {
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new thead :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":nodes") {
            if (valsubtype == vx_web_html::t_trlist()) {
              vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_trlist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new thead :nodes " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new thead) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_web_html::Class_thead();
      if (output->vx_p_id != vx_p_id) {
        if (output->vx_p_id) {
          vx_core::vx_release_one(output->vx_p_id);
        }
        output->vx_p_id = vx_p_id;
        vx_core::vx_reserve(vx_p_id);
      }
      if (output->vx_p_style != vx_p_style) {
        if (output->vx_p_style) {
          vx_core::vx_release_one(output->vx_p_style);
        }
        output->vx_p_style = vx_p_style;
        vx_core::vx_reserve(vx_p_style);
      }
      if (output->vx_p_nodes != vx_p_nodes) {
        if (output->vx_p_nodes) {
          vx_core::vx_release_one(output->vx_p_nodes);
        }
        output->vx_p_nodes = vx_p_nodes;
        vx_core::vx_reserve(vx_p_nodes);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_thead::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_thead::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_thead::vx_empty() const {return vx_web_html::e_thead();}
    vx_core::Type_any Class_thead::vx_type() const {return vx_web_html::t_thead();}

    vx_core::Type_typedef Class_thead::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "thead", // name
        ":struct", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_node()}), // traits
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

  // (type title)
  // class Class_title {
    Abstract_title::~Abstract_title() {}

    Class_title::Class_title() : Abstract_title::Abstract_title() {
      vx_core::refcount += 1;
    }

    Class_title::~Class_title() {
      vx_core::refcount -= 1;
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_style,
        this->vx_p_text
      });
    }

    // id()
    vx_core::Type_string Class_title::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_title::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style();
      }
      return output;
    }

    // text()
    vx_core::Type_string Class_title::text() const {
      vx_core::Type_string output = this->vx_p_text;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_title::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
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
      output[":style"] = this->style();
      output[":text"] = this->text();
      return output;
    }

    vx_core::Type_any Class_title::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_title(), vals);
    }

    vx_core::Type_any Class_title::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_title output = vx_web_html::e_title();
      vx_web_html::Type_title val = vx_core::vx_any_from_any(vx_web_html::t_title(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_core::Type_string vx_p_text = val->text();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":text") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new title) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new title :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style()) {
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new title :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":text") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_text = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new title :text " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new title) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_web_html::Class_title();
      if (output->vx_p_id != vx_p_id) {
        if (output->vx_p_id) {
          vx_core::vx_release_one(output->vx_p_id);
        }
        output->vx_p_id = vx_p_id;
        vx_core::vx_reserve(vx_p_id);
      }
      if (output->vx_p_style != vx_p_style) {
        if (output->vx_p_style) {
          vx_core::vx_release_one(output->vx_p_style);
        }
        output->vx_p_style = vx_p_style;
        vx_core::vx_reserve(vx_p_style);
      }
      if (output->vx_p_text != vx_p_text) {
        if (output->vx_p_text) {
          vx_core::vx_release_one(output->vx_p_text);
        }
        output->vx_p_text = vx_p_text;
        vx_core::vx_reserve(vx_p_text);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_title::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_title::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_title::vx_empty() const {return vx_web_html::e_title();}
    vx_core::Type_any Class_title::vx_type() const {return vx_web_html::t_title();}

    vx_core::Type_typedef Class_title::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "title", // name
        ":struct", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_node(), vx_web_html::t_headchild()}), // traits
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

  // (type tr)
  // class Class_tr {
    Abstract_tr::~Abstract_tr() {}

    Class_tr::Class_tr() : Abstract_tr::Abstract_tr() {
      vx_core::refcount += 1;
    }

    Class_tr::~Class_tr() {
      vx_core::refcount -= 1;
      vx_core::vx_release_one({
        this->vx_p_id,
        this->vx_p_style,
        this->vx_p_nodes
      });
    }

    // id()
    vx_core::Type_string Class_tr::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (!output) {
        output = vx_core::e_string();
      }
      return output;
    }

    // style()
    vx_web_html::Type_style Class_tr::style() const {
      vx_web_html::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_web_html::e_style();
      }
      return output;
    }

    // nodes()
    vx_web_html::Type_tdlist Class_tr::nodes() const {
      vx_web_html::Type_tdlist output = this->vx_p_nodes;
      if (!output) {
        output = vx_web_html::e_tdlist();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_tr::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      } else if (skey == ":style") {
        output = this->style();
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
      output[":style"] = this->style();
      output[":nodes"] = this->nodes();
      return output;
    }

    vx_core::Type_any Class_tr::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_tr(), vals);
    }

    vx_core::Type_any Class_tr::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_tr output = vx_web_html::e_tr();
      vx_web_html::Type_tr val = vx_core::vx_any_from_any(vx_web_html::t_tr(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
      vx_web_html::Type_style vx_p_style = val->style();
      vx_web_html::Type_tdlist vx_p_nodes = val->nodes();
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
          } else if (testkey == ":id") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":nodes") {
            key = testkey;
          } else if (valsubtype == vx_web_html::t_tdlist()) { // default property
            vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_tdlist(), valsub);
          } else if (valsubtype == vx_web_html::t_td()) { // default property
            vx_web_html::Type_td valdefault = vx_core::vx_any_from_any(vx_web_html::t_td(), valsub);
            vx_web_html::Type_tdlist vallist = output->vx_p_nodes;
            if (!vallist) {
              vallist = vx_core::vx_new(vx_web_html::t_tdlist(), {valdefault});
            } else {
              vallist = vx_core::vx_copy(vx_web_html::t_tdlist(), {valdefault});
            }
            vx_p_nodes = vallist;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new tr) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new tr :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (valsubtype == vx_web_html::t_style()) {
              vx_p_style = vx_core::vx_any_from_any(vx_web_html::t_style(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new tr :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":nodes") {
            if (valsubtype == vx_web_html::t_tdlist()) {
              vx_p_nodes = vx_core::vx_any_from_any(vx_web_html::t_tdlist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new tr :nodes " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new tr) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_web_html::Class_tr();
      if (output->vx_p_id != vx_p_id) {
        if (output->vx_p_id) {
          vx_core::vx_release_one(output->vx_p_id);
        }
        output->vx_p_id = vx_p_id;
        vx_core::vx_reserve(vx_p_id);
      }
      if (output->vx_p_style != vx_p_style) {
        if (output->vx_p_style) {
          vx_core::vx_release_one(output->vx_p_style);
        }
        output->vx_p_style = vx_p_style;
        vx_core::vx_reserve(vx_p_style);
      }
      if (output->vx_p_nodes != vx_p_nodes) {
        if (output->vx_p_nodes) {
          vx_core::vx_release_one(output->vx_p_nodes);
        }
        output->vx_p_nodes = vx_p_nodes;
        vx_core::vx_reserve(vx_p_nodes);
      }
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
        vx_core::vx_reserve(msgblock);
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_tr::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_tr::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_tr::vx_empty() const {return vx_web_html::e_tr();}
    vx_core::Type_any Class_tr::vx_type() const {return vx_web_html::t_tr();}

    vx_core::Type_typedef Class_tr::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "tr", // name
        ":struct", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_node()}), // traits
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

  // (type trlist)
  // class Class_trlist {
    Abstract_trlist::~Abstract_trlist() {}

    Class_trlist::Class_trlist() : Abstract_trlist::Abstract_trlist() {
      vx_core::refcount += 1;
    }

    Class_trlist::~Class_trlist() {
      vx_core::refcount -= 1;
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_trlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_web_html::Type_tr Class_trlist::vx_get_tr(vx_core::Type_int index) const {
      vx_web_html::Type_tr output = vx_web_html::e_tr();
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
      vx_web_html::Type_trlist output = vx_web_html::e_trlist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_web_html::Type_tr> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_web_html::t_tr()) {
          vx_web_html::Type_tr castval = vx_core::vx_any_from_any(vx_web_html::t_tr(), valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(trlist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_web_html::Class_trlist();
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

    vx_core::Type_any Class_trlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_web_html::e_trlist(), vals);
    }

    vx_core::Type_any Class_trlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Type_trlist output = vx_web_html::e_trlist();
      vx_web_html::Type_trlist val = vx_core::vx_any_from_any(vx_web_html::t_trlist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_web_html::Type_tr> listval = val->vx_listtr();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_web_html::t_tr()) {
          listval.push_back(vx_core::vx_any_from_any(vx_web_html::t_tr(), valsub));
        } else if (valsubtype == vx_web_html::t_trlist()) {
          vx_web_html::Type_trlist multi = vx_core::vx_any_from_any(vx_web_html::t_trlist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listtr());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new trlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_web_html::Class_trlist();
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

    vx_core::Type_msgblock Class_trlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_web_html::Class_trlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_trlist::vx_empty() const {return vx_web_html::e_trlist();}
    vx_core::Type_any Class_trlist::vx_type() const {return vx_web_html::t_trlist();}

    vx_core::Type_typedef Class_trlist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "trlist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_web_html::t_tr()}), // allowtypes
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

  // (func boolean-write<-id-htmltext)
  vx_core::Type_boolean f_boolean_write_from_id_htmltext(vx_core::Type_string id, vx_core::Type_string htmltext) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    vx_core::vx_release_except({id, htmltext}, output);
    return output;
  }

  // (func boolean-write<-id-htmltext)
  // class Class_boolean_write_from_id_htmltext {
    Abstract_boolean_write_from_id_htmltext::~Abstract_boolean_write_from_id_htmltext() {}

    Class_boolean_write_from_id_htmltext::Class_boolean_write_from_id_htmltext() : Abstract_boolean_write_from_id_htmltext::Abstract_boolean_write_from_id_htmltext() {
      vx_core::refcount += 1;
    }

    Class_boolean_write_from_id_htmltext::~Class_boolean_write_from_id_htmltext() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_boolean_write_from_id_htmltext::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_boolean_write_from_id_htmltext output = vx_web_html::e_boolean_write_from_id_htmltext();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_boolean_write_from_id_htmltext::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_boolean_write_from_id_htmltext output = vx_web_html::e_boolean_write_from_id_htmltext();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_boolean_write_from_id_htmltext::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "boolean-write<-id-htmltext", // name
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

    vx_core::Type_funcdef Class_boolean_write_from_id_htmltext::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "boolean-write<-id-htmltext", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_boolean_write_from_id_htmltext::vx_empty() const {return vx_web_html::e_boolean_write_from_id_htmltext();}
    vx_core::Type_any Class_boolean_write_from_id_htmltext::vx_type() const {return vx_web_html::t_boolean_write_from_id_htmltext();}
    vx_core::Type_msgblock Class_boolean_write_from_id_htmltext::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_write_from_id_htmltext::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_boolean_write_from_id_htmltext::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string id = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string htmltext = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_boolean_write_from_id_htmltext(id, htmltext);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func boolean-write<-stylesheet)
  vx_core::vx_Type_async f_boolean_write_from_stylesheet(vx_web_html::Type_stylesheet stylesheet) {
    vx_core::vx_Type_async output = NULL;
    vx_core::vx_release(stylesheet);
    if (!output) {
      output = vx_core::vx_async_new_from_value(vx_core::e_boolean());
    }
    return output;
  }

  // (func boolean-write<-stylesheet)
  // class Class_boolean_write_from_stylesheet {
    Abstract_boolean_write_from_stylesheet::~Abstract_boolean_write_from_stylesheet() {}

    Class_boolean_write_from_stylesheet::Class_boolean_write_from_stylesheet() : Abstract_boolean_write_from_stylesheet::Abstract_boolean_write_from_stylesheet() {
      vx_core::refcount += 1;
    }

    Class_boolean_write_from_stylesheet::~Class_boolean_write_from_stylesheet() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_boolean_write_from_stylesheet::vx_new(vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_boolean_write_from_stylesheet output = vx_web_html::e_boolean_write_from_stylesheet();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_boolean_write_from_stylesheet::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_boolean_write_from_stylesheet output = vx_web_html::e_boolean_write_from_stylesheet();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_boolean_write_from_stylesheet::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "boolean-write<-stylesheet", // name
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

    vx_core::Type_funcdef Class_boolean_write_from_stylesheet::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/web/html", // pkgname
        "boolean-write<-stylesheet", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_boolean_write_from_stylesheet::vx_empty() const {return vx_web_html::e_boolean_write_from_stylesheet();}
    vx_core::Type_any Class_boolean_write_from_stylesheet::vx_type() const {return vx_web_html::t_boolean_write_from_stylesheet();}
    vx_core::Type_msgblock Class_boolean_write_from_stylesheet::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_write_from_stylesheet::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_boolean_write_from_stylesheet::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async();
    }

    vx_core::vx_Type_async Class_boolean_write_from_stylesheet::vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const {
      vx_web_html::Type_stylesheet inputval = vx_core::vx_any_from_any(vx_web_html::t_stylesheet(), val);
      vx_core::vx_Type_async output = vx_web_html::f_boolean_write_from_stylesheet(inputval);
      vx_core::vx_release(val);
      return output;
    }

    vx_core::vx_Type_async Class_boolean_write_from_stylesheet::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_value(vx_core::e_any());
      vx_web_html::Type_stylesheet stylesheet = vx_core::vx_any_from_any(vx_web_html::t_stylesheet(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_boolean_write_from_stylesheet(stylesheet);
      vx_core::vx_release(arglist);
      return output;
    }

  //}

  // (func htmlstring<-string)
  vx_core::Type_string f_htmlstring_from_string(vx_core::Type_string text) {
    vx_core::Type_string output = vx_core::e_string();
    vx_core::vx_release_except(text, output);
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
      vx_web_html::Func_htmlstring_from_string output = vx_web_html::e_htmlstring_from_string();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_htmlstring_from_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_htmlstring_from_string output = vx_web_html::e_htmlstring_from_string();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_htmlstring_from_string::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "htmlstring<-string", // name
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

    vx_core::Type_any Class_htmlstring_from_string::vx_empty() const {return vx_web_html::e_htmlstring_from_string();}
    vx_core::Type_any Class_htmlstring_from_string::vx_type() const {return vx_web_html::t_htmlstring_from_string();}
    vx_core::Type_msgblock Class_htmlstring_from_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_htmlstring_from_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_htmlstring_from_string::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_htmlstring_from_string::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string(), val);
      output = vx_web_html::f_htmlstring_from_string(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_htmlstring_from_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_htmlstring_from_string(text);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string-indent)
  vx_core::Type_string f_string_indent(vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_string_repeat(vx_core::vx_new_string("  "), indent);
    vx_core::vx_release_except(indent, output);
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
      vx_web_html::Func_string_indent output = vx_web_html::e_string_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_indent output = vx_web_html::e_string_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string-indent", // name
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

    vx_core::Type_any Class_string_indent::vx_empty() const {return vx_web_html::e_string_indent();}
    vx_core::Type_any Class_string_indent::vx_type() const {return vx_web_html::t_string_indent();}
    vx_core::Type_msgblock Class_string_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_string_indent::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_string_indent::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_int inputval = vx_core::vx_any_from_any(vx_core::t_int(), val);
      output = vx_web_html::f_string_indent(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_string_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_string_indent(indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-body-indent)
  vx_core::Type_string f_string_from_body_indent(vx_web_html::Type_body body, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({body, indent}, [body, indent]() {
        vx_web_html::Type_divchildlist nodes = body->nodes();
        vx_core::vx_ref_plus(nodes);
        vx_core::Type_string output_1 = vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, vx_core::vx_new_string("body"), vx_core::vx_new_string(""), indent);
        vx_core::vx_release_one_except(nodes, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_except({body, indent}, output);
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
      vx_web_html::Func_string_from_body_indent output = vx_web_html::e_string_from_body_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_body_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_body_indent output = vx_web_html::e_string_from_body_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_body_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-body-indent", // name
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

    vx_core::Type_any Class_string_from_body_indent::vx_empty() const {return vx_web_html::e_string_from_body_indent();}
    vx_core::Type_any Class_string_from_body_indent::vx_type() const {return vx_web_html::t_string_from_body_indent();}
    vx_core::Type_msgblock Class_string_from_body_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_body_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_body_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_body body = vx_core::vx_any_from_any(vx_web_html::t_body(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_body_indent(body, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-details-indent)
  vx_core::Type_string f_string_from_details_indent(vx_web_html::Type_details details, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({indent, details}, [indent, details]() {
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
          vx_core::t_string(),
          vx_core::vx_new(vx_core::t_anylist(), {
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
    vx_core::vx_release_except({details, indent}, output);
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
      vx_web_html::Func_string_from_details_indent output = vx_web_html::e_string_from_details_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_details_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_details_indent output = vx_web_html::e_string_from_details_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_details_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-details-indent", // name
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

    vx_core::Type_any Class_string_from_details_indent::vx_empty() const {return vx_web_html::e_string_from_details_indent();}
    vx_core::Type_any Class_string_from_details_indent::vx_type() const {return vx_web_html::t_string_from_details_indent();}
    vx_core::Type_msgblock Class_string_from_details_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_details_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_details_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_details details = vx_core::vx_any_from_any(vx_web_html::t_details(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_details_indent(details, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-div-indent)
  vx_core::Type_string f_string_from_div_indent(vx_web_html::Type_div div, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({div, indent}, [div, indent]() {
        vx_web_html::Type_divchildlist nodes = div->nodes();
        vx_core::vx_ref_plus(nodes);
        vx_core::Type_string sid = vx_web_html::f_string_from_propname_val(
          vx_core::vx_new_string("id"),
          div->id()
        );
        vx_core::vx_ref_plus(sid);
        vx_core::Type_string sstyle = vx_web_html::f_string_from_propstyle(
          div->style()
        );
        vx_core::vx_ref_plus(sstyle);
        vx_core::Type_string output_1 = vx_web_html::f_string_from_nodelist_tag_prop_indent(
          nodes,
          vx_core::vx_new_string("div"),
          vx_core::f_new(
            vx_core::t_string(),
            vx_core::vx_new(vx_core::t_anylist(), {
              sid,
              sstyle
            })
          ),
          indent
        );
        vx_core::vx_release_one_except({nodes, sid, sstyle}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_except({div, indent}, output);
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
      vx_web_html::Func_string_from_div_indent output = vx_web_html::e_string_from_div_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_div_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_div_indent output = vx_web_html::e_string_from_div_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_div_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-div-indent", // name
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

    vx_core::Type_any Class_string_from_div_indent::vx_empty() const {return vx_web_html::e_string_from_div_indent();}
    vx_core::Type_any Class_string_from_div_indent::vx_type() const {return vx_web_html::t_string_from_div_indent();}
    vx_core::Type_msgblock Class_string_from_div_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_div_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_div_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_div div = vx_core::vx_any_from_any(vx_web_html::t_div(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_div_indent(div, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-footer-indent)
  vx_core::Type_string f_string_from_footer_indent(vx_web_html::Type_footer footer, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({footer, indent}, [footer, indent]() {
        vx_web_html::Type_divchildlist nodes = footer->nodes();
        vx_core::vx_ref_plus(nodes);
        vx_core::Type_string output_1 = vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, vx_core::vx_new_string("footer"), vx_core::vx_new_string(""), indent);
        vx_core::vx_release_one_except(nodes, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_except({footer, indent}, output);
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
      vx_web_html::Func_string_from_footer_indent output = vx_web_html::e_string_from_footer_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_footer_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_footer_indent output = vx_web_html::e_string_from_footer_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_footer_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-footer-indent", // name
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

    vx_core::Type_any Class_string_from_footer_indent::vx_empty() const {return vx_web_html::e_string_from_footer_indent();}
    vx_core::Type_any Class_string_from_footer_indent::vx_type() const {return vx_web_html::t_string_from_footer_indent();}
    vx_core::Type_msgblock Class_string_from_footer_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_footer_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_footer_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_footer footer = vx_core::vx_any_from_any(vx_web_html::t_footer(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_footer_indent(footer, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-h1-indent)
  vx_core::Type_string f_string_from_h1_indent(vx_web_html::Type_h1 h1, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({indent, h1}, [indent, h1]() {
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
          vx_core::t_string(),
          vx_core::vx_new(vx_core::t_anylist(), {
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
    vx_core::vx_release_except({h1, indent}, output);
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
      vx_web_html::Func_string_from_h1_indent output = vx_web_html::e_string_from_h1_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_h1_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_h1_indent output = vx_web_html::e_string_from_h1_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_h1_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-h1-indent", // name
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

    vx_core::Type_any Class_string_from_h1_indent::vx_empty() const {return vx_web_html::e_string_from_h1_indent();}
    vx_core::Type_any Class_string_from_h1_indent::vx_type() const {return vx_web_html::t_string_from_h1_indent();}
    vx_core::Type_msgblock Class_string_from_h1_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_h1_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_h1_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_h1 h1 = vx_core::vx_any_from_any(vx_web_html::t_h1(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_h1_indent(h1, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-h2-indent)
  vx_core::Type_string f_string_from_h2_indent(vx_web_html::Type_h2 h2, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({h2, indent}, [h2, indent]() {
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
          vx_core::t_string(),
          vx_core::vx_new(vx_core::t_anylist(), {
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
    vx_core::vx_release_except({h2, indent}, output);
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
      vx_web_html::Func_string_from_h2_indent output = vx_web_html::e_string_from_h2_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_h2_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_h2_indent output = vx_web_html::e_string_from_h2_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_h2_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-h2-indent", // name
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

    vx_core::Type_any Class_string_from_h2_indent::vx_empty() const {return vx_web_html::e_string_from_h2_indent();}
    vx_core::Type_any Class_string_from_h2_indent::vx_type() const {return vx_web_html::t_string_from_h2_indent();}
    vx_core::Type_msgblock Class_string_from_h2_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_h2_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_h2_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_h2 h2 = vx_core::vx_any_from_any(vx_web_html::t_h2(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_h2_indent(h2, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-h3-indent)
  vx_core::Type_string f_string_from_h3_indent(vx_web_html::Type_h3 h3, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({h3, indent}, [h3, indent]() {
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
          vx_core::t_string(),
          vx_core::vx_new(vx_core::t_anylist(), {
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
    vx_core::vx_release_except({h3, indent}, output);
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
      vx_web_html::Func_string_from_h3_indent output = vx_web_html::e_string_from_h3_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_h3_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_h3_indent output = vx_web_html::e_string_from_h3_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_h3_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-h3-indent", // name
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

    vx_core::Type_any Class_string_from_h3_indent::vx_empty() const {return vx_web_html::e_string_from_h3_indent();}
    vx_core::Type_any Class_string_from_h3_indent::vx_type() const {return vx_web_html::t_string_from_h3_indent();}
    vx_core::Type_msgblock Class_string_from_h3_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_h3_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_h3_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_h3 h3 = vx_core::vx_any_from_any(vx_web_html::t_h3(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_h3_indent(h3, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-head-indent)
  vx_core::Type_string f_string_from_head_indent(vx_web_html::Type_head head, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({head, indent}, [head, indent]() {
        vx_web_html::Type_headchildlist nodes = head->nodes();
        vx_core::vx_ref_plus(nodes);
        vx_core::Type_string output_1 = vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, vx_core::vx_new_string("head"), vx_core::vx_new_string(""), indent);
        vx_core::vx_release_one_except(nodes, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_except({head, indent}, output);
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
      vx_web_html::Func_string_from_head_indent output = vx_web_html::e_string_from_head_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_head_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_head_indent output = vx_web_html::e_string_from_head_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_head_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-head-indent", // name
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

    vx_core::Type_any Class_string_from_head_indent::vx_empty() const {return vx_web_html::e_string_from_head_indent();}
    vx_core::Type_any Class_string_from_head_indent::vx_type() const {return vx_web_html::t_string_from_head_indent();}
    vx_core::Type_msgblock Class_string_from_head_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_head_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_head_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_head head = vx_core::vx_any_from_any(vx_web_html::t_head(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_head_indent(head, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-html)
  vx_core::Type_string f_string_from_html(vx_web_html::Type_html html) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({html}, [html]() {
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
          vx_core::t_string(),
          vx_core::vx_new(vx_core::t_anylist(), {
            vx_core::vx_new_string("<!DOCTYPE html>"),
            vx_core::c_newline(),
            vx_core::vx_new_string("<html"),
            lang,
            vx_core::vx_new_string(">"),
            shead,
            sbody,
            sfooter,
            vx_core::c_newline(),
            vx_core::vx_new_string("</html>")
          })
        );
        vx_core::vx_release_one_except({lang, head, body, footer, shead, sbody, sfooter}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_except(html, output);
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
      vx_web_html::Func_string_from_html output = vx_web_html::e_string_from_html();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_html::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_html output = vx_web_html::e_string_from_html();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_html::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-html", // name
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

    vx_core::Type_any Class_string_from_html::vx_empty() const {return vx_web_html::e_string_from_html();}
    vx_core::Type_any Class_string_from_html::vx_type() const {return vx_web_html::t_string_from_html();}
    vx_core::Type_msgblock Class_string_from_html::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_html::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_string_from_html::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_string_from_html::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_html inputval = vx_core::vx_any_from_any(vx_web_html::t_html(), val);
      output = vx_web_html::f_string_from_html(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_string_from_html::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_html html = vx_core::vx_any_from_any(vx_web_html::t_html(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_string_from_html(html);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-indent)
  vx_core::Type_string f_string_from_indent(vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_if_1(
      vx_core::t_string(),
      vx_core::f_eq(indent, vx_core::vx_new_int(0)),
      vx_core::vx_new_string(""),
      vx_core::f_new(
        vx_core::t_string(),
        vx_core::vx_new(vx_core::t_anylist(), {
          vx_core::c_newline(),
          vx_web_html::f_string_indent(indent)
        })
      )
    );
    vx_core::vx_release_except(indent, output);
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
      vx_web_html::Func_string_from_indent output = vx_web_html::e_string_from_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_indent output = vx_web_html::e_string_from_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-indent", // name
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

    vx_core::Type_any Class_string_from_indent::vx_empty() const {return vx_web_html::e_string_from_indent();}
    vx_core::Type_any Class_string_from_indent::vx_type() const {return vx_web_html::t_string_from_indent();}
    vx_core::Type_msgblock Class_string_from_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_string_from_indent::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_string_from_indent::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_int inputval = vx_core::vx_any_from_any(vx_core::t_int(), val);
      output = vx_web_html::f_string_from_indent(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_string_from_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_string_from_indent(indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-meta-indent)
  vx_core::Type_string f_string_from_meta_indent(vx_web_html::Type_meta meta, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({indent, meta}, [indent, meta]() {
        vx_core::Type_string sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::vx_ref_plus(sindent);
        vx_core::Type_string charset = vx_web_html::f_string_from_propname_val(
          vx_core::vx_new_string("charset"),
          meta->charset()
        );
        vx_core::vx_ref_plus(charset);
        vx_core::Type_string output_1 = vx_core::f_new(
          vx_core::t_string(),
          vx_core::vx_new(vx_core::t_anylist(), {
            sindent,
            vx_core::vx_new_string("<meta"),
            charset,
            vx_core::vx_new_string(" />")
          })
        );
        vx_core::vx_release_one_except({sindent, charset}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_except({meta, indent}, output);
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
      vx_web_html::Func_string_from_meta_indent output = vx_web_html::e_string_from_meta_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_meta_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_meta_indent output = vx_web_html::e_string_from_meta_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_meta_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-meta-indent", // name
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

    vx_core::Type_any Class_string_from_meta_indent::vx_empty() const {return vx_web_html::e_string_from_meta_indent();}
    vx_core::Type_any Class_string_from_meta_indent::vx_type() const {return vx_web_html::t_string_from_meta_indent();}
    vx_core::Type_msgblock Class_string_from_meta_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_meta_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_meta_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_meta meta = vx_core::vx_any_from_any(vx_web_html::t_meta(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_meta_indent(meta, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-node-indent)
  vx_core::Type_string f_string_from_node_indent(vx_core::Type_any node, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_switch(
      vx_core::t_string(),
      vx_core::f_type_from_any(node),
      vx_core::vx_new(vx_core::t_thenelselist(), {
        vx_core::f_case_1(
          vx_web_html::t_body(),
          vx_core::t_any_from_func()->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_body_indent(
              vx_core::f_any_from_any(vx_web_html::t_body(), node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_details(),
          vx_core::t_any_from_func()->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_details_indent(
              vx_core::f_any_from_any(vx_web_html::t_details(), node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_div(),
          vx_core::t_any_from_func()->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_div_indent(
              vx_core::f_any_from_any(vx_web_html::t_div(), node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_h1(),
          vx_core::t_any_from_func()->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_h1_indent(
              vx_core::f_any_from_any(vx_web_html::t_h1(), node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_h2(),
          vx_core::t_any_from_func()->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_h2_indent(
              vx_core::f_any_from_any(vx_web_html::t_h2(), node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_h3(),
          vx_core::t_any_from_func()->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_h3_indent(
              vx_core::f_any_from_any(vx_web_html::t_h3(), node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_head(),
          vx_core::t_any_from_func()->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_head_indent(
              vx_core::f_any_from_any(vx_web_html::t_head(), node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_footer(),
          vx_core::t_any_from_func()->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_footer_indent(
              vx_core::f_any_from_any(vx_web_html::t_footer(), node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_meta(),
          vx_core::t_any_from_func()->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_meta_indent(
              vx_core::f_any_from_any(vx_web_html::t_meta(), node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_p(),
          vx_core::t_any_from_func()->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_p_indent(
              vx_core::f_any_from_any(vx_web_html::t_p(), node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_stylesheet(),
          vx_core::t_any_from_func()->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_stylesheet_indent(
              vx_core::f_any_from_any(vx_web_html::t_stylesheet(), node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_table(),
          vx_core::t_any_from_func()->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_table_indent(
              vx_core::f_any_from_any(vx_web_html::t_table(), node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_title(),
          vx_core::t_any_from_func()->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_title_indent(
              vx_core::f_any_from_any(vx_web_html::t_title(), node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_tbody(),
          vx_core::t_any_from_func()->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_tbody_indent(
              vx_core::f_any_from_any(vx_web_html::t_tbody(), node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_thead(),
          vx_core::t_any_from_func()->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_thead_indent(
              vx_core::f_any_from_any(vx_web_html::t_thead(), node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_td(),
          vx_core::t_any_from_func()->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_td_indent(
              vx_core::f_any_from_any(vx_web_html::t_td(), node),
              indent
            );
            return output_1;
          })
        ),
        vx_core::f_case_1(
          vx_web_html::t_tr(),
          vx_core::t_any_from_func()->vx_fn_new({node, indent}, [node, indent]() {
            vx_core::Type_string output_1 = vx_web_html::f_string_from_tr_indent(
              vx_core::f_any_from_any(vx_web_html::t_tr(), node),
              indent
            );
            return output_1;
          })
        )
      })
    );
    vx_core::vx_release_except({node, indent}, output);
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
      vx_web_html::Func_string_from_node_indent output = vx_web_html::e_string_from_node_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_node_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_node_indent output = vx_web_html::e_string_from_node_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_node_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-node-indent", // name
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

    vx_core::Type_any Class_string_from_node_indent::vx_empty() const {return vx_web_html::e_string_from_node_indent();}
    vx_core::Type_any Class_string_from_node_indent::vx_type() const {return vx_web_html::t_string_from_node_indent();}
    vx_core::Type_msgblock Class_string_from_node_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_node_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_node_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any node = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_node_indent(node, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-nodelist-indent)
  vx_core::Type_string f_string_from_nodelist_indent(vx_core::Type_list nodelist, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({nodelist, indent}, [nodelist, indent]() {
        vx_core::Type_stringlist textlist = vx_core::f_list_from_list(
          vx_core::t_stringlist(),
          nodelist,
          vx_core::t_any_from_any()->vx_fn_new({indent}, [indent](vx_core::Type_any node_any) {
            vx_web_html::Type_node node = vx_core::vx_any_from_any(vx_web_html::t_node(), node_any);
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
    vx_core::vx_release_except({nodelist, indent}, output);
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
      vx_web_html::Func_string_from_nodelist_indent output = vx_web_html::e_string_from_nodelist_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_nodelist_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_nodelist_indent output = vx_web_html::e_string_from_nodelist_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_nodelist_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-nodelist-indent", // name
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

    vx_core::Type_any Class_string_from_nodelist_indent::vx_empty() const {return vx_web_html::e_string_from_nodelist_indent();}
    vx_core::Type_any Class_string_from_nodelist_indent::vx_type() const {return vx_web_html::t_string_from_nodelist_indent();}
    vx_core::Type_msgblock Class_string_from_nodelist_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_nodelist_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_nodelist_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_list nodelist = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_nodelist_indent(nodelist, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-nodelist-tag-prop-indent)
  vx_core::Type_string f_string_from_nodelist_tag_prop_indent(vx_core::Type_list nodes, vx_core::Type_string tag, vx_core::Type_string prop, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({nodes, indent, tag, prop}, [nodes, indent, tag, prop]() {
        vx_core::Type_string text = vx_web_html::f_string_from_nodelist_indent(
          nodes,
          vx_core::f_plus1(indent)
        );
        vx_core::vx_ref_plus(text);
        vx_core::Type_string sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::vx_ref_plus(sindent);
        vx_core::Type_string eindent = vx_core::f_if_2(
          vx_core::t_string(),
          vx_core::vx_new(vx_core::t_thenelselist(), {
            vx_core::f_then(
              vx_core::t_boolean_from_func()->vx_fn_new({text}, [text]() {
                vx_core::Type_boolean output_1 = vx_core::f_is_empty(text);
                return output_1;
              }),
              vx_core::t_any_from_func()->vx_fn_new({}, []() {
                vx_core::Type_string output_1 = vx_core::vx_new_string("");
                return output_1;
              })
            ),
            vx_core::f_then(
              vx_core::t_boolean_from_func()->vx_fn_new({sindent}, [sindent]() {
                vx_core::Type_boolean output_1 = vx_core::f_is_empty(sindent);
                return output_1;
              }),
              vx_core::t_any_from_func()->vx_fn_new({}, []() {
                vx_core::Type_string output_1 = vx_core::c_newline();
                return output_1;
              })
            ),
            vx_core::f_else(
              vx_core::t_any_from_func()->vx_fn_new({sindent}, [sindent]() {
                vx_core::Type_any output_1 = sindent;
                return output_1;
              })
            )
          })
        );
        vx_core::vx_ref_plus(eindent);
        vx_core::Type_string output_1 = vx_core::f_new(
          vx_core::t_string(),
          vx_core::vx_new(vx_core::t_anylist(), {
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
    vx_core::vx_release_except({nodes, tag, prop, indent}, output);
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
      vx_web_html::Func_string_from_nodelist_tag_prop_indent output = vx_web_html::e_string_from_nodelist_tag_prop_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_nodelist_tag_prop_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_nodelist_tag_prop_indent output = vx_web_html::e_string_from_nodelist_tag_prop_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_nodelist_tag_prop_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-nodelist-tag-prop-indent", // name
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

    vx_core::Type_any Class_string_from_nodelist_tag_prop_indent::vx_empty() const {return vx_web_html::e_string_from_nodelist_tag_prop_indent();}
    vx_core::Type_any Class_string_from_nodelist_tag_prop_indent::vx_type() const {return vx_web_html::t_string_from_nodelist_tag_prop_indent();}
    vx_core::Type_msgblock Class_string_from_nodelist_tag_prop_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_nodelist_tag_prop_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_nodelist_tag_prop_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_list nodes = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string tag = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_string prop = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(2)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(3)));
      output = vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, tag, prop, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-p-indent)
  vx_core::Type_string f_string_from_p_indent(vx_web_html::Type_p p, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({indent, p}, [indent, p]() {
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
        vx_core::Type_string sstyle = vx_web_html::f_string_from_propstyle(
          p->style()
        );
        vx_core::vx_ref_plus(sstyle);
        vx_core::Type_string output_1 = vx_core::f_new(
          vx_core::t_string(),
          vx_core::vx_new(vx_core::t_anylist(), {
            sindent,
            vx_core::vx_new_string("<p"),
            sid,
            sstyle,
            vx_core::vx_new_string(">"),
            text,
            vx_core::vx_new_string("</p>")
          })
        );
        vx_core::vx_release_one_except({sindent, text, sid, sstyle}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_except({p, indent}, output);
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
      vx_web_html::Func_string_from_p_indent output = vx_web_html::e_string_from_p_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_p_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_p_indent output = vx_web_html::e_string_from_p_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_p_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-p-indent", // name
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

    vx_core::Type_any Class_string_from_p_indent::vx_empty() const {return vx_web_html::e_string_from_p_indent();}
    vx_core::Type_any Class_string_from_p_indent::vx_type() const {return vx_web_html::t_string_from_p_indent();}
    vx_core::Type_msgblock Class_string_from_p_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_p_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_p_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_p p = vx_core::vx_any_from_any(vx_web_html::t_p(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_p_indent(p, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-propname-val)
  vx_core::Type_string f_string_from_propname_val(vx_core::Type_string key, vx_core::Type_string val) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_if(
      vx_core::t_string(),
      vx_core::f_notempty(val),
      vx_core::f_new(
        vx_core::t_string(),
        vx_core::vx_new(vx_core::t_anylist(), {
          vx_core::vx_new_string(" "),
          key,
          vx_core::vx_new_string("="),
          vx_core::c_quote(),
          val,
          vx_core::c_quote()
        })
      )
    );
    vx_core::vx_release_except({key, val}, output);
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
      vx_web_html::Func_string_from_propname_val output = vx_web_html::e_string_from_propname_val();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_propname_val::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_propname_val output = vx_web_html::e_string_from_propname_val();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_propname_val::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-propname-val", // name
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

    vx_core::Type_any Class_string_from_propname_val::vx_empty() const {return vx_web_html::e_string_from_propname_val();}
    vx_core::Type_any Class_string_from_propname_val::vx_type() const {return vx_web_html::t_string_from_propname_val();}
    vx_core::Type_msgblock Class_string_from_propname_val::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_propname_val::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_propname_val::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string key = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string val = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_propname_val(key, val);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-propstyle)
  vx_core::Type_string f_string_from_propstyle(vx_web_html::Type_style style) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_if(
      vx_core::t_string(),
      vx_core::f_notempty_1(style),
      vx_core::f_new(
        vx_core::t_string(),
        vx_core::vx_new(vx_core::t_anylist(), {
          vx_core::vx_new_string(" class="),
          vx_core::c_quote(),
          vx_type::f_string_from_string_start(
            style->name(),
            vx_core::vx_new_int(1)
          ),
          vx_core::c_quote()
        })
      )
    );
    vx_core::vx_release_except(style, output);
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
      vx_web_html::Func_string_from_propstyle output = vx_web_html::e_string_from_propstyle();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_propstyle::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_propstyle output = vx_web_html::e_string_from_propstyle();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_propstyle::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-propstyle", // name
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

    vx_core::Type_any Class_string_from_propstyle::vx_empty() const {return vx_web_html::e_string_from_propstyle();}
    vx_core::Type_any Class_string_from_propstyle::vx_type() const {return vx_web_html::t_string_from_propstyle();}
    vx_core::Type_msgblock Class_string_from_propstyle::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_propstyle::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_string_from_propstyle::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_string_from_propstyle::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_style inputval = vx_core::vx_any_from_any(vx_web_html::t_style(), val);
      output = vx_web_html::f_string_from_propstyle(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_string_from_propstyle::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_style style = vx_core::vx_any_from_any(vx_web_html::t_style(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_string_from_propstyle(style);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-style-indent)
  vx_core::Type_string f_string_from_style_indent(vx_web_html::Type_style style, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({indent, style}, [indent, style]() {
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
          vx_core::t_string(),
          vx_core::vx_new(vx_core::t_anylist(), {
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
    vx_core::vx_release_except({style, indent}, output);
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
      vx_web_html::Func_string_from_style_indent output = vx_web_html::e_string_from_style_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_style_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_style_indent output = vx_web_html::e_string_from_style_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_style_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-style-indent", // name
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

    vx_core::Type_any Class_string_from_style_indent::vx_empty() const {return vx_web_html::e_string_from_style_indent();}
    vx_core::Type_any Class_string_from_style_indent::vx_type() const {return vx_web_html::t_string_from_style_indent();}
    vx_core::Type_msgblock Class_string_from_style_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_style_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_style_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_style style = vx_core::vx_any_from_any(vx_web_html::t_style(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_style_indent(style, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-stylelist-indent)
  vx_core::Type_string f_string_from_stylelist_indent(vx_web_html::Type_stylelist stylelist, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({stylelist, indent}, [stylelist, indent]() {
        vx_core::Type_stringlist sstyles = vx_core::f_list_from_list(
          vx_core::t_stringlist(),
          stylelist,
          vx_core::t_any_from_any()->vx_fn_new({indent}, [indent](vx_core::Type_any substyle_any) {
            vx_web_html::Type_style substyle = vx_core::vx_any_from_any(vx_web_html::t_style(), substyle_any);
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
    vx_core::vx_release_except({stylelist, indent}, output);
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
      vx_web_html::Func_string_from_stylelist_indent output = vx_web_html::e_string_from_stylelist_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_stylelist_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_stylelist_indent output = vx_web_html::e_string_from_stylelist_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_stylelist_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-stylelist-indent", // name
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

    vx_core::Type_any Class_string_from_stylelist_indent::vx_empty() const {return vx_web_html::e_string_from_stylelist_indent();}
    vx_core::Type_any Class_string_from_stylelist_indent::vx_type() const {return vx_web_html::t_string_from_stylelist_indent();}
    vx_core::Type_msgblock Class_string_from_stylelist_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_stylelist_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_stylelist_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_stylelist stylelist = vx_core::vx_any_from_any(vx_web_html::t_stylelist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_stylelist_indent(stylelist, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-stylepropmap-indent)
  vx_core::Type_string f_string_from_stylepropmap_indent(vx_web_html::Type_propmap propmap, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({indent, propmap}, [indent, propmap]() {
        vx_core::Type_string sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::vx_ref_plus(sindent);
        vx_core::Type_stringlist sprops = vx_core::f_list_from_map(
          vx_core::t_stringlist(),
          propmap,
          vx_core::t_any_from_key_value()->vx_fn_new({sindent}, [sindent](vx_core::Type_any key_any, vx_core::Type_any val_any) {
            vx_core::Type_string key = vx_core::vx_any_from_any(vx_core::t_string(), key_any);
            vx_core::Type_string val = vx_core::vx_any_from_any(vx_core::t_string(), val_any);
            vx_core::Type_any output_1 = 
              vx_core::f_new(
                vx_core::t_string(),
                vx_core::vx_new(vx_core::t_anylist(), {
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
    vx_core::vx_release_except({propmap, indent}, output);
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
      vx_web_html::Func_string_from_stylepropmap_indent output = vx_web_html::e_string_from_stylepropmap_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_stylepropmap_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_stylepropmap_indent output = vx_web_html::e_string_from_stylepropmap_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_stylepropmap_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-stylepropmap-indent", // name
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

    vx_core::Type_any Class_string_from_stylepropmap_indent::vx_empty() const {return vx_web_html::e_string_from_stylepropmap_indent();}
    vx_core::Type_any Class_string_from_stylepropmap_indent::vx_type() const {return vx_web_html::t_string_from_stylepropmap_indent();}
    vx_core::Type_msgblock Class_string_from_stylepropmap_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_stylepropmap_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_stylepropmap_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_propmap propmap = vx_core::vx_any_from_any(vx_web_html::t_propmap(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_stylepropmap_indent(propmap, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-stylesheet-indent)
  vx_core::Type_string f_string_from_stylesheet_indent(vx_web_html::Type_stylesheet stylesheet, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({stylesheet, indent}, [stylesheet, indent]() {
        vx_core::Type_string text = vx_web_html::f_string_from_stylelist_indent(
          stylesheet->styles(),
          vx_core::f_plus1(indent)
        );
        vx_core::vx_ref_plus(text);
        vx_core::Type_string sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::vx_ref_plus(sindent);
        vx_core::Type_string eindent = vx_core::f_if(
          vx_core::t_string(),
          vx_core::f_notempty(text),
          sindent
        );
        vx_core::vx_ref_plus(eindent);
        vx_core::Type_string output_1 = vx_core::f_new(
          vx_core::t_string(),
          vx_core::vx_new(vx_core::t_anylist(), {
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
    vx_core::vx_release_except({stylesheet, indent}, output);
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
      vx_web_html::Func_string_from_stylesheet_indent output = vx_web_html::e_string_from_stylesheet_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_stylesheet_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_stylesheet_indent output = vx_web_html::e_string_from_stylesheet_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_stylesheet_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-stylesheet-indent", // name
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

    vx_core::Type_any Class_string_from_stylesheet_indent::vx_empty() const {return vx_web_html::e_string_from_stylesheet_indent();}
    vx_core::Type_any Class_string_from_stylesheet_indent::vx_type() const {return vx_web_html::t_string_from_stylesheet_indent();}
    vx_core::Type_msgblock Class_string_from_stylesheet_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_stylesheet_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_stylesheet_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_stylesheet stylesheet = vx_core::vx_any_from_any(vx_web_html::t_stylesheet(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_stylesheet_indent(stylesheet, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-table-indent)
  vx_core::Type_string f_string_from_table_indent(vx_web_html::Type_table table, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({indent, table}, [indent, table]() {
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
          vx_core::t_string(),
          vx_core::vx_new(vx_core::t_anylist(), {
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
    vx_core::vx_release_except({table, indent}, output);
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
      vx_web_html::Func_string_from_table_indent output = vx_web_html::e_string_from_table_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_table_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_table_indent output = vx_web_html::e_string_from_table_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_table_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-table-indent", // name
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

    vx_core::Type_any Class_string_from_table_indent::vx_empty() const {return vx_web_html::e_string_from_table_indent();}
    vx_core::Type_any Class_string_from_table_indent::vx_type() const {return vx_web_html::t_string_from_table_indent();}
    vx_core::Type_msgblock Class_string_from_table_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_table_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_table_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_table table = vx_core::vx_any_from_any(vx_web_html::t_table(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_table_indent(table, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-tbody-indent)
  vx_core::Type_string f_string_from_tbody_indent(vx_web_html::Type_tbody tbody, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({tbody, indent}, [tbody, indent]() {
        vx_web_html::Type_trlist nodes = tbody->nodes();
        vx_core::vx_ref_plus(nodes);
        vx_core::Type_string output_1 = vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, vx_core::vx_new_string("tbody"), vx_core::vx_new_string(""), indent);
        vx_core::vx_release_one_except(nodes, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_except({tbody, indent}, output);
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
      vx_web_html::Func_string_from_tbody_indent output = vx_web_html::e_string_from_tbody_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_tbody_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_tbody_indent output = vx_web_html::e_string_from_tbody_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_tbody_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-tbody-indent", // name
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

    vx_core::Type_any Class_string_from_tbody_indent::vx_empty() const {return vx_web_html::e_string_from_tbody_indent();}
    vx_core::Type_any Class_string_from_tbody_indent::vx_type() const {return vx_web_html::t_string_from_tbody_indent();}
    vx_core::Type_msgblock Class_string_from_tbody_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_tbody_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_tbody_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_tbody tbody = vx_core::vx_any_from_any(vx_web_html::t_tbody(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_tbody_indent(tbody, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-td-indent)
  vx_core::Type_string f_string_from_td_indent(vx_web_html::Type_td td, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({td, indent}, [td, indent]() {
        vx_web_html::Type_divchildlist nodes = td->nodes();
        vx_core::vx_ref_plus(nodes);
        vx_core::Type_string output_1 = vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, vx_core::vx_new_string("td"), vx_core::vx_new_string(""), indent);
        vx_core::vx_release_one_except(nodes, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_except({td, indent}, output);
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
      vx_web_html::Func_string_from_td_indent output = vx_web_html::e_string_from_td_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_td_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_td_indent output = vx_web_html::e_string_from_td_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_td_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-td-indent", // name
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

    vx_core::Type_any Class_string_from_td_indent::vx_empty() const {return vx_web_html::e_string_from_td_indent();}
    vx_core::Type_any Class_string_from_td_indent::vx_type() const {return vx_web_html::t_string_from_td_indent();}
    vx_core::Type_msgblock Class_string_from_td_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_td_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_td_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_td td = vx_core::vx_any_from_any(vx_web_html::t_td(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_td_indent(td, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-thead-indent)
  vx_core::Type_string f_string_from_thead_indent(vx_web_html::Type_thead thead, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({thead, indent}, [thead, indent]() {
        vx_web_html::Type_trlist nodes = thead->nodes();
        vx_core::vx_ref_plus(nodes);
        vx_core::Type_string output_1 = vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, vx_core::vx_new_string("thead"), vx_core::vx_new_string(""), indent);
        vx_core::vx_release_one_except(nodes, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_except({thead, indent}, output);
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
      vx_web_html::Func_string_from_thead_indent output = vx_web_html::e_string_from_thead_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_thead_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_thead_indent output = vx_web_html::e_string_from_thead_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_thead_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-thead-indent", // name
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

    vx_core::Type_any Class_string_from_thead_indent::vx_empty() const {return vx_web_html::e_string_from_thead_indent();}
    vx_core::Type_any Class_string_from_thead_indent::vx_type() const {return vx_web_html::t_string_from_thead_indent();}
    vx_core::Type_msgblock Class_string_from_thead_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_thead_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_thead_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_thead thead = vx_core::vx_any_from_any(vx_web_html::t_thead(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_thead_indent(thead, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-title-indent)
  vx_core::Type_string f_string_from_title_indent(vx_web_html::Type_title title, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({indent, title}, [indent, title]() {
        vx_core::Type_string sindent = vx_web_html::f_string_from_indent(indent);
        vx_core::vx_ref_plus(sindent);
        vx_core::Type_string text = title->text();
        vx_core::vx_ref_plus(text);
        vx_core::Type_string output_1 = vx_core::f_new(
          vx_core::t_string(),
          vx_core::vx_new(vx_core::t_anylist(), {
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
    vx_core::vx_release_except({title, indent}, output);
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
      vx_web_html::Func_string_from_title_indent output = vx_web_html::e_string_from_title_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_title_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_title_indent output = vx_web_html::e_string_from_title_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_title_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-title-indent", // name
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

    vx_core::Type_any Class_string_from_title_indent::vx_empty() const {return vx_web_html::e_string_from_title_indent();}
    vx_core::Type_any Class_string_from_title_indent::vx_type() const {return vx_web_html::t_string_from_title_indent();}
    vx_core::Type_msgblock Class_string_from_title_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_title_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_title_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_title title = vx_core::vx_any_from_any(vx_web_html::t_title(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_title_indent(title, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-tr-indent)
  vx_core::Type_string f_string_from_tr_indent(vx_web_html::Type_tr tr, vx_core::Type_int indent) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_let(
      vx_core::t_string(),
      vx_core::t_any_from_func()->vx_fn_new({tr, indent}, [tr, indent]() {
        vx_web_html::Type_tdlist nodes = tr->nodes();
        vx_core::vx_ref_plus(nodes);
        vx_core::Type_string output_1 = vx_web_html::f_string_from_nodelist_tag_prop_indent(nodes, vx_core::vx_new_string("tr"), vx_core::vx_new_string(""), indent);
        vx_core::vx_release_one_except(nodes, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_except({tr, indent}, output);
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
      vx_web_html::Func_string_from_tr_indent output = vx_web_html::e_string_from_tr_indent();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_tr_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_tr_indent output = vx_web_html::e_string_from_tr_indent();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_tr_indent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-tr-indent", // name
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

    vx_core::Type_any Class_string_from_tr_indent::vx_empty() const {return vx_web_html::e_string_from_tr_indent();}
    vx_core::Type_any Class_string_from_tr_indent::vx_type() const {return vx_web_html::t_string_from_tr_indent();}
    vx_core::Type_msgblock Class_string_from_tr_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_tr_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_tr_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_tr tr = vx_core::vx_any_from_any(vx_web_html::t_tr(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_string_from_tr_indent(tr, indent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func string<-uri)
  vx_core::Type_string f_string_from_uri(vx_core::Type_string uri) {
    vx_core::Type_string output = vx_core::e_string();
    vx_core::vx_release_except(uri, output);
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
      vx_web_html::Func_string_from_uri output = vx_web_html::e_string_from_uri();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_from_uri::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_string_from_uri output = vx_web_html::e_string_from_uri();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_from_uri::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "string<-uri", // name
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

    vx_core::Type_any Class_string_from_uri::vx_empty() const {return vx_web_html::e_string_from_uri();}
    vx_core::Type_any Class_string_from_uri::vx_type() const {return vx_web_html::t_string_from_uri();}
    vx_core::Type_msgblock Class_string_from_uri::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_uri::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_string_from_uri::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_string_from_uri::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string(), val);
      output = vx_web_html::f_string_from_uri(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_string_from_uri::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string uri = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_string_from_uri(uri);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func style<-stylesheet-name)
  vx_web_html::Type_style f_style_from_stylesheet_name(vx_web_html::Type_stylesheet stylesheet, vx_core::Type_string name) {
    vx_web_html::Type_style output = vx_web_html::e_style();
    output = vx_core::f_any_from_map(
      vx_web_html::t_style(),
      vx_web_html::f_stylemap_from_stylesheet(stylesheet),
      name
    );
    vx_core::vx_release_except({stylesheet, name}, output);
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
      vx_web_html::Func_style_from_stylesheet_name output = vx_web_html::e_style_from_stylesheet_name();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_style_from_stylesheet_name::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_style_from_stylesheet_name output = vx_web_html::e_style_from_stylesheet_name();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_style_from_stylesheet_name::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "style<-stylesheet-name", // name
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

    vx_core::Type_any Class_style_from_stylesheet_name::vx_empty() const {return vx_web_html::e_style_from_stylesheet_name();}
    vx_core::Type_any Class_style_from_stylesheet_name::vx_type() const {return vx_web_html::t_style_from_stylesheet_name();}
    vx_core::Type_msgblock Class_style_from_stylesheet_name::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_style_from_stylesheet_name::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_style_from_stylesheet_name::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_stylesheet stylesheet = vx_core::vx_any_from_any(vx_web_html::t_stylesheet(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string name = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_web_html::f_style_from_stylesheet_name(stylesheet, name);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func stylemap<-stylelist)
  vx_web_html::Type_stylemap f_stylemap_from_stylelist(vx_web_html::Type_stylelist stylelist) {
    vx_web_html::Type_stylemap output = vx_web_html::e_stylemap();
    output = vx_core::f_map_from_list(
      vx_web_html::t_stylemap(),
      stylelist,
      vx_core::t_any_from_any()->vx_fn_new({}, [](vx_core::Type_any style_any) {
        vx_web_html::Type_style style = vx_core::vx_any_from_any(vx_web_html::t_style(), style_any);
        vx_core::Type_any output_1 = 
          style->name();
        return output_1;
      })
    );
    vx_core::vx_release_except(stylelist, output);
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
      vx_web_html::Func_stylemap_from_stylelist output = vx_web_html::e_stylemap_from_stylelist();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_stylemap_from_stylelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_stylemap_from_stylelist output = vx_web_html::e_stylemap_from_stylelist();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_stylemap_from_stylelist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "stylemap<-stylelist", // name
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

    vx_core::Type_any Class_stylemap_from_stylelist::vx_empty() const {return vx_web_html::e_stylemap_from_stylelist();}
    vx_core::Type_any Class_stylemap_from_stylelist::vx_type() const {return vx_web_html::t_stylemap_from_stylelist();}
    vx_core::Type_msgblock Class_stylemap_from_stylelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stylemap_from_stylelist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_stylemap_from_stylelist::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_stylemap_from_stylelist::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_stylelist inputval = vx_core::vx_any_from_any(vx_web_html::t_stylelist(), val);
      output = vx_web_html::f_stylemap_from_stylelist(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_stylemap_from_stylelist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_stylelist stylelist = vx_core::vx_any_from_any(vx_web_html::t_stylelist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_stylemap_from_stylelist(stylelist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func stylemap<-stylesheet)
  vx_web_html::Type_stylemap f_stylemap_from_stylesheet(vx_web_html::Type_stylesheet stylesheet) {
    vx_web_html::Type_stylemap output = vx_web_html::e_stylemap();
    output = stylesheet->stylemap();
    vx_core::vx_release_except(stylesheet, output);
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
      vx_web_html::Func_stylemap_from_stylesheet output = vx_web_html::e_stylemap_from_stylesheet();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_stylemap_from_stylesheet::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_stylemap_from_stylesheet output = vx_web_html::e_stylemap_from_stylesheet();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_stylemap_from_stylesheet::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "stylemap<-stylesheet", // name
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

    vx_core::Type_any Class_stylemap_from_stylesheet::vx_empty() const {return vx_web_html::e_stylemap_from_stylesheet();}
    vx_core::Type_any Class_stylemap_from_stylesheet::vx_type() const {return vx_web_html::t_stylemap_from_stylesheet();}
    vx_core::Type_msgblock Class_stylemap_from_stylesheet::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stylemap_from_stylesheet::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_stylemap_from_stylesheet::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_stylemap_from_stylesheet::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_stylesheet inputval = vx_core::vx_any_from_any(vx_web_html::t_stylesheet(), val);
      output = vx_web_html::f_stylemap_from_stylesheet(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_stylemap_from_stylesheet::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_stylesheet stylesheet = vx_core::vx_any_from_any(vx_web_html::t_stylesheet(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_stylemap_from_stylesheet(stylesheet);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func styles<-stylesheet)
  vx_web_html::Type_stylelist f_styles_from_stylesheet(vx_web_html::Type_stylesheet stylesheet) {
    vx_web_html::Type_stylelist output = vx_web_html::e_stylelist();
    output = stylesheet->styles();
    vx_core::vx_release_except(stylesheet, output);
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
      vx_web_html::Func_styles_from_stylesheet output = vx_web_html::e_styles_from_stylesheet();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_styles_from_stylesheet::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_styles_from_stylesheet output = vx_web_html::e_styles_from_stylesheet();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_styles_from_stylesheet::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "styles<-stylesheet", // name
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

    vx_core::Type_any Class_styles_from_stylesheet::vx_empty() const {return vx_web_html::e_styles_from_stylesheet();}
    vx_core::Type_any Class_styles_from_stylesheet::vx_type() const {return vx_web_html::t_styles_from_stylesheet();}
    vx_core::Type_msgblock Class_styles_from_stylesheet::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_styles_from_stylesheet::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_styles_from_stylesheet::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_styles_from_stylesheet::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_stylesheet inputval = vx_core::vx_any_from_any(vx_web_html::t_stylesheet(), val);
      output = vx_web_html::f_styles_from_stylesheet(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_styles_from_stylesheet::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_stylesheet stylesheet = vx_core::vx_any_from_any(vx_web_html::t_stylesheet(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_styles_from_stylesheet(stylesheet);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func stylesheet-loadmap)
  vx_web_html::Type_stylesheet f_stylesheet_loadmap(vx_web_html::Type_stylesheet stylesheet) {
    vx_web_html::Type_stylesheet output = vx_web_html::e_stylesheet();
    output = vx_core::f_copy(
      stylesheet,
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":stylemap"),
        vx_web_html::f_stylemap_from_stylelist(
          stylesheet->styles()
        )
      })
    );
    vx_core::vx_release_except(stylesheet, output);
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
      vx_web_html::Func_stylesheet_loadmap output = vx_web_html::e_stylesheet_loadmap();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_stylesheet_loadmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_stylesheet_loadmap output = vx_web_html::e_stylesheet_loadmap();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_stylesheet_loadmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "stylesheet-loadmap", // name
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

    vx_core::Type_any Class_stylesheet_loadmap::vx_empty() const {return vx_web_html::e_stylesheet_loadmap();}
    vx_core::Type_any Class_stylesheet_loadmap::vx_type() const {return vx_web_html::t_stylesheet_loadmap();}
    vx_core::Type_msgblock Class_stylesheet_loadmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stylesheet_loadmap::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_stylesheet_loadmap::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_stylesheet_loadmap::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_stylesheet inputval = vx_core::vx_any_from_any(vx_web_html::t_stylesheet(), val);
      output = vx_web_html::f_stylesheet_loadmap(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_stylesheet_loadmap::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_web_html::Type_stylesheet stylesheet = vx_core::vx_any_from_any(vx_web_html::t_stylesheet(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_stylesheet_loadmap(stylesheet);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func uri<-string)
  vx_core::Type_string f_uri_from_string(vx_core::Type_string text) {
    vx_core::Type_string output = vx_core::e_string();
    vx_core::vx_release_except(text, output);
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
      vx_web_html::Func_uri_from_string output = vx_web_html::e_uri_from_string();
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_uri_from_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_web_html::Func_uri_from_string output = vx_web_html::e_uri_from_string();
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_uri_from_string::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/web/html", // pkgname
        "uri<-string", // name
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

    vx_core::Type_any Class_uri_from_string::vx_empty() const {return vx_web_html::e_uri_from_string();}
    vx_core::Type_any Class_uri_from_string::vx_type() const {return vx_web_html::t_uri_from_string();}
    vx_core::Type_msgblock Class_uri_from_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_uri_from_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_uri_from_string::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_uri_from_string::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string(), val);
      output = vx_web_html::f_uri_from_string(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_uri_from_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_web_html::f_uri_from_string(text);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_web_html::vx_Class_package* vx_package = new vx_web_html::vx_Class_package();

  vx_web_html::Type_node e_node() {
    vx_web_html::Type_node output = vx_web_html::vx_package->e_node;
    if (!output) {
      output = new Class_node();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_node = output;
    }
    return output;
  }
  vx_web_html::Type_node t_node() {
    vx_web_html::Type_node output = vx_web_html::vx_package->t_node;
    if (!output) {
      output = new Class_node();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_node = output;
    }
    return output;
  }

  vx_web_html::Type_divchild e_divchild() {
    vx_web_html::Type_divchild output = vx_web_html::vx_package->e_divchild;
    if (!output) {
      output = new Class_divchild();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_divchild = output;
    }
    return output;
  }
  vx_web_html::Type_divchild t_divchild() {
    vx_web_html::Type_divchild output = vx_web_html::vx_package->t_divchild;
    if (!output) {
      output = new Class_divchild();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_divchild = output;
    }
    return output;
  }

  vx_web_html::Type_body e_body() {
    vx_web_html::Type_body output = vx_web_html::vx_package->e_body;
    if (!output) {
      output = new Class_body();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_body = output;
    }
    return output;
  }
  vx_web_html::Type_body t_body() {
    vx_web_html::Type_body output = vx_web_html::vx_package->t_body;
    if (!output) {
      output = new Class_body();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_body = output;
    }
    return output;
  }

  vx_web_html::Type_details e_details() {
    vx_web_html::Type_details output = vx_web_html::vx_package->e_details;
    if (!output) {
      output = new Class_details();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_details = output;
    }
    return output;
  }
  vx_web_html::Type_details t_details() {
    vx_web_html::Type_details output = vx_web_html::vx_package->t_details;
    if (!output) {
      output = new Class_details();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_details = output;
    }
    return output;
  }

  vx_web_html::Type_div e_div() {
    vx_web_html::Type_div output = vx_web_html::vx_package->e_div;
    if (!output) {
      output = new Class_div();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_div = output;
    }
    return output;
  }
  vx_web_html::Type_div t_div() {
    vx_web_html::Type_div output = vx_web_html::vx_package->t_div;
    if (!output) {
      output = new Class_div();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_div = output;
    }
    return output;
  }

  vx_web_html::Type_divchildlist e_divchildlist() {
    vx_web_html::Type_divchildlist output = vx_web_html::vx_package->e_divchildlist;
    if (!output) {
      output = new Class_divchildlist();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_divchildlist = output;
    }
    return output;
  }
  vx_web_html::Type_divchildlist t_divchildlist() {
    vx_web_html::Type_divchildlist output = vx_web_html::vx_package->t_divchildlist;
    if (!output) {
      output = new Class_divchildlist();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_divchildlist = output;
    }
    return output;
  }

  vx_web_html::Type_divlist e_divlist() {
    vx_web_html::Type_divlist output = vx_web_html::vx_package->e_divlist;
    if (!output) {
      output = new Class_divlist();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_divlist = output;
    }
    return output;
  }
  vx_web_html::Type_divlist t_divlist() {
    vx_web_html::Type_divlist output = vx_web_html::vx_package->t_divlist;
    if (!output) {
      output = new Class_divlist();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_divlist = output;
    }
    return output;
  }

  vx_web_html::Type_footer e_footer() {
    vx_web_html::Type_footer output = vx_web_html::vx_package->e_footer;
    if (!output) {
      output = new Class_footer();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_footer = output;
    }
    return output;
  }
  vx_web_html::Type_footer t_footer() {
    vx_web_html::Type_footer output = vx_web_html::vx_package->t_footer;
    if (!output) {
      output = new Class_footer();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_footer = output;
    }
    return output;
  }

  vx_web_html::Type_h1 e_h1() {
    vx_web_html::Type_h1 output = vx_web_html::vx_package->e_h1;
    if (!output) {
      output = new Class_h1();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_h1 = output;
    }
    return output;
  }
  vx_web_html::Type_h1 t_h1() {
    vx_web_html::Type_h1 output = vx_web_html::vx_package->t_h1;
    if (!output) {
      output = new Class_h1();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_h1 = output;
    }
    return output;
  }

  vx_web_html::Type_h2 e_h2() {
    vx_web_html::Type_h2 output = vx_web_html::vx_package->e_h2;
    if (!output) {
      output = new Class_h2();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_h2 = output;
    }
    return output;
  }
  vx_web_html::Type_h2 t_h2() {
    vx_web_html::Type_h2 output = vx_web_html::vx_package->t_h2;
    if (!output) {
      output = new Class_h2();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_h2 = output;
    }
    return output;
  }

  vx_web_html::Type_h3 e_h3() {
    vx_web_html::Type_h3 output = vx_web_html::vx_package->e_h3;
    if (!output) {
      output = new Class_h3();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_h3 = output;
    }
    return output;
  }
  vx_web_html::Type_h3 t_h3() {
    vx_web_html::Type_h3 output = vx_web_html::vx_package->t_h3;
    if (!output) {
      output = new Class_h3();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_h3 = output;
    }
    return output;
  }

  vx_web_html::Type_head e_head() {
    vx_web_html::Type_head output = vx_web_html::vx_package->e_head;
    if (!output) {
      output = new Class_head();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_head = output;
    }
    return output;
  }
  vx_web_html::Type_head t_head() {
    vx_web_html::Type_head output = vx_web_html::vx_package->t_head;
    if (!output) {
      output = new Class_head();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_head = output;
    }
    return output;
  }

  vx_web_html::Type_headchild e_headchild() {
    vx_web_html::Type_headchild output = vx_web_html::vx_package->e_headchild;
    if (!output) {
      output = new Class_headchild();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_headchild = output;
    }
    return output;
  }
  vx_web_html::Type_headchild t_headchild() {
    vx_web_html::Type_headchild output = vx_web_html::vx_package->t_headchild;
    if (!output) {
      output = new Class_headchild();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_headchild = output;
    }
    return output;
  }

  vx_web_html::Type_headchildlist e_headchildlist() {
    vx_web_html::Type_headchildlist output = vx_web_html::vx_package->e_headchildlist;
    if (!output) {
      output = new Class_headchildlist();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_headchildlist = output;
    }
    return output;
  }
  vx_web_html::Type_headchildlist t_headchildlist() {
    vx_web_html::Type_headchildlist output = vx_web_html::vx_package->t_headchildlist;
    if (!output) {
      output = new Class_headchildlist();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_headchildlist = output;
    }
    return output;
  }

  vx_web_html::Type_html e_html() {
    vx_web_html::Type_html output = vx_web_html::vx_package->e_html;
    if (!output) {
      output = new Class_html();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_html = output;
    }
    return output;
  }
  vx_web_html::Type_html t_html() {
    vx_web_html::Type_html output = vx_web_html::vx_package->t_html;
    if (!output) {
      output = new Class_html();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_html = output;
    }
    return output;
  }

  vx_web_html::Type_meta e_meta() {
    vx_web_html::Type_meta output = vx_web_html::vx_package->e_meta;
    if (!output) {
      output = new Class_meta();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_meta = output;
    }
    return output;
  }
  vx_web_html::Type_meta t_meta() {
    vx_web_html::Type_meta output = vx_web_html::vx_package->t_meta;
    if (!output) {
      output = new Class_meta();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_meta = output;
    }
    return output;
  }

  vx_web_html::Type_nodelist e_nodelist() {
    vx_web_html::Type_nodelist output = vx_web_html::vx_package->e_nodelist;
    if (!output) {
      output = new Class_nodelist();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_nodelist = output;
    }
    return output;
  }
  vx_web_html::Type_nodelist t_nodelist() {
    vx_web_html::Type_nodelist output = vx_web_html::vx_package->t_nodelist;
    if (!output) {
      output = new Class_nodelist();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_nodelist = output;
    }
    return output;
  }

  vx_web_html::Type_p e_p() {
    vx_web_html::Type_p output = vx_web_html::vx_package->e_p;
    if (!output) {
      output = new Class_p();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_p = output;
    }
    return output;
  }
  vx_web_html::Type_p t_p() {
    vx_web_html::Type_p output = vx_web_html::vx_package->t_p;
    if (!output) {
      output = new Class_p();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_p = output;
    }
    return output;
  }

  vx_web_html::Type_propmap e_propmap() {
    vx_web_html::Type_propmap output = vx_web_html::vx_package->e_propmap;
    if (!output) {
      output = new Class_propmap();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_propmap = output;
    }
    return output;
  }
  vx_web_html::Type_propmap t_propmap() {
    vx_web_html::Type_propmap output = vx_web_html::vx_package->t_propmap;
    if (!output) {
      output = new Class_propmap();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_propmap = output;
    }
    return output;
  }

  vx_web_html::Type_style e_style() {
    vx_web_html::Type_style output = vx_web_html::vx_package->e_style;
    if (!output) {
      output = new Class_style();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_style = output;
    }
    return output;
  }
  vx_web_html::Type_style t_style() {
    vx_web_html::Type_style output = vx_web_html::vx_package->t_style;
    if (!output) {
      output = new Class_style();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_style = output;
    }
    return output;
  }

  vx_web_html::Type_stylelist e_stylelist() {
    vx_web_html::Type_stylelist output = vx_web_html::vx_package->e_stylelist;
    if (!output) {
      output = new Class_stylelist();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_stylelist = output;
    }
    return output;
  }
  vx_web_html::Type_stylelist t_stylelist() {
    vx_web_html::Type_stylelist output = vx_web_html::vx_package->t_stylelist;
    if (!output) {
      output = new Class_stylelist();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_stylelist = output;
    }
    return output;
  }

  vx_web_html::Type_stylemap e_stylemap() {
    vx_web_html::Type_stylemap output = vx_web_html::vx_package->e_stylemap;
    if (!output) {
      output = new Class_stylemap();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_stylemap = output;
    }
    return output;
  }
  vx_web_html::Type_stylemap t_stylemap() {
    vx_web_html::Type_stylemap output = vx_web_html::vx_package->t_stylemap;
    if (!output) {
      output = new Class_stylemap();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_stylemap = output;
    }
    return output;
  }

  vx_web_html::Type_stylesheet e_stylesheet() {
    vx_web_html::Type_stylesheet output = vx_web_html::vx_package->e_stylesheet;
    if (!output) {
      output = new Class_stylesheet();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_stylesheet = output;
    }
    return output;
  }
  vx_web_html::Type_stylesheet t_stylesheet() {
    vx_web_html::Type_stylesheet output = vx_web_html::vx_package->t_stylesheet;
    if (!output) {
      output = new Class_stylesheet();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_stylesheet = output;
    }
    return output;
  }

  vx_web_html::Type_table e_table() {
    vx_web_html::Type_table output = vx_web_html::vx_package->e_table;
    if (!output) {
      output = new Class_table();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_table = output;
    }
    return output;
  }
  vx_web_html::Type_table t_table() {
    vx_web_html::Type_table output = vx_web_html::vx_package->t_table;
    if (!output) {
      output = new Class_table();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_table = output;
    }
    return output;
  }

  vx_web_html::Type_tbody e_tbody() {
    vx_web_html::Type_tbody output = vx_web_html::vx_package->e_tbody;
    if (!output) {
      output = new Class_tbody();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_tbody = output;
    }
    return output;
  }
  vx_web_html::Type_tbody t_tbody() {
    vx_web_html::Type_tbody output = vx_web_html::vx_package->t_tbody;
    if (!output) {
      output = new Class_tbody();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_tbody = output;
    }
    return output;
  }

  vx_web_html::Type_td e_td() {
    vx_web_html::Type_td output = vx_web_html::vx_package->e_td;
    if (!output) {
      output = new Class_td();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_td = output;
    }
    return output;
  }
  vx_web_html::Type_td t_td() {
    vx_web_html::Type_td output = vx_web_html::vx_package->t_td;
    if (!output) {
      output = new Class_td();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_td = output;
    }
    return output;
  }

  vx_web_html::Type_tdlist e_tdlist() {
    vx_web_html::Type_tdlist output = vx_web_html::vx_package->e_tdlist;
    if (!output) {
      output = new Class_tdlist();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_tdlist = output;
    }
    return output;
  }
  vx_web_html::Type_tdlist t_tdlist() {
    vx_web_html::Type_tdlist output = vx_web_html::vx_package->t_tdlist;
    if (!output) {
      output = new Class_tdlist();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_tdlist = output;
    }
    return output;
  }

  vx_web_html::Type_thead e_thead() {
    vx_web_html::Type_thead output = vx_web_html::vx_package->e_thead;
    if (!output) {
      output = new Class_thead();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_thead = output;
    }
    return output;
  }
  vx_web_html::Type_thead t_thead() {
    vx_web_html::Type_thead output = vx_web_html::vx_package->t_thead;
    if (!output) {
      output = new Class_thead();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_thead = output;
    }
    return output;
  }

  vx_web_html::Type_title e_title() {
    vx_web_html::Type_title output = vx_web_html::vx_package->e_title;
    if (!output) {
      output = new Class_title();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_title = output;
    }
    return output;
  }
  vx_web_html::Type_title t_title() {
    vx_web_html::Type_title output = vx_web_html::vx_package->t_title;
    if (!output) {
      output = new Class_title();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_title = output;
    }
    return output;
  }

  vx_web_html::Type_tr e_tr() {
    vx_web_html::Type_tr output = vx_web_html::vx_package->e_tr;
    if (!output) {
      output = new Class_tr();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_tr = output;
    }
    return output;
  }
  vx_web_html::Type_tr t_tr() {
    vx_web_html::Type_tr output = vx_web_html::vx_package->t_tr;
    if (!output) {
      output = new Class_tr();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_tr = output;
    }
    return output;
  }

  vx_web_html::Type_trlist e_trlist() {
    vx_web_html::Type_trlist output = vx_web_html::vx_package->e_trlist;
    if (!output) {
      output = new Class_trlist();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_trlist = output;
    }
    return output;
  }
  vx_web_html::Type_trlist t_trlist() {
    vx_web_html::Type_trlist output = vx_web_html::vx_package->t_trlist;
    if (!output) {
      output = new Class_trlist();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_trlist = output;
    }
    return output;
  }

  // (func boolean-write<-id-htmltext)
  vx_web_html::Func_boolean_write_from_id_htmltext e_boolean_write_from_id_htmltext() {
    vx_web_html::Func_boolean_write_from_id_htmltext output = vx_web_html::vx_package->e_boolean_write_from_id_htmltext;
    if (!output) {
      output = new vx_web_html::Class_boolean_write_from_id_htmltext();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_boolean_write_from_id_htmltext = output;
    }
    return output;
  }
  vx_web_html::Func_boolean_write_from_id_htmltext t_boolean_write_from_id_htmltext() {
    vx_web_html::Func_boolean_write_from_id_htmltext output = vx_web_html::vx_package->t_boolean_write_from_id_htmltext;
    if (!output) {
      output = new vx_web_html::Class_boolean_write_from_id_htmltext();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_boolean_write_from_id_htmltext = output;
    }
    return output;
  }

  // (func boolean-write<-stylesheet)
  vx_web_html::Func_boolean_write_from_stylesheet e_boolean_write_from_stylesheet() {
    vx_web_html::Func_boolean_write_from_stylesheet output = vx_web_html::vx_package->e_boolean_write_from_stylesheet;
    if (!output) {
      output = new vx_web_html::Class_boolean_write_from_stylesheet();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_boolean_write_from_stylesheet = output;
    }
    return output;
  }
  vx_web_html::Func_boolean_write_from_stylesheet t_boolean_write_from_stylesheet() {
    vx_web_html::Func_boolean_write_from_stylesheet output = vx_web_html::vx_package->t_boolean_write_from_stylesheet;
    if (!output) {
      output = new vx_web_html::Class_boolean_write_from_stylesheet();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_boolean_write_from_stylesheet = output;
    }
    return output;
  }

  // (func htmlstring<-string)
  vx_web_html::Func_htmlstring_from_string e_htmlstring_from_string() {
    vx_web_html::Func_htmlstring_from_string output = vx_web_html::vx_package->e_htmlstring_from_string;
    if (!output) {
      output = new vx_web_html::Class_htmlstring_from_string();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_htmlstring_from_string = output;
    }
    return output;
  }
  vx_web_html::Func_htmlstring_from_string t_htmlstring_from_string() {
    vx_web_html::Func_htmlstring_from_string output = vx_web_html::vx_package->t_htmlstring_from_string;
    if (!output) {
      output = new vx_web_html::Class_htmlstring_from_string();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_htmlstring_from_string = output;
    }
    return output;
  }

  // (func string-indent)
  vx_web_html::Func_string_indent e_string_indent() {
    vx_web_html::Func_string_indent output = vx_web_html::vx_package->e_string_indent;
    if (!output) {
      output = new vx_web_html::Class_string_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_indent t_string_indent() {
    vx_web_html::Func_string_indent output = vx_web_html::vx_package->t_string_indent;
    if (!output) {
      output = new vx_web_html::Class_string_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_indent = output;
    }
    return output;
  }

  // (func string<-body-indent)
  vx_web_html::Func_string_from_body_indent e_string_from_body_indent() {
    vx_web_html::Func_string_from_body_indent output = vx_web_html::vx_package->e_string_from_body_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_body_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_body_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_body_indent t_string_from_body_indent() {
    vx_web_html::Func_string_from_body_indent output = vx_web_html::vx_package->t_string_from_body_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_body_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_body_indent = output;
    }
    return output;
  }

  // (func string<-details-indent)
  vx_web_html::Func_string_from_details_indent e_string_from_details_indent() {
    vx_web_html::Func_string_from_details_indent output = vx_web_html::vx_package->e_string_from_details_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_details_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_details_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_details_indent t_string_from_details_indent() {
    vx_web_html::Func_string_from_details_indent output = vx_web_html::vx_package->t_string_from_details_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_details_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_details_indent = output;
    }
    return output;
  }

  // (func string<-div-indent)
  vx_web_html::Func_string_from_div_indent e_string_from_div_indent() {
    vx_web_html::Func_string_from_div_indent output = vx_web_html::vx_package->e_string_from_div_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_div_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_div_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_div_indent t_string_from_div_indent() {
    vx_web_html::Func_string_from_div_indent output = vx_web_html::vx_package->t_string_from_div_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_div_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_div_indent = output;
    }
    return output;
  }

  // (func string<-footer-indent)
  vx_web_html::Func_string_from_footer_indent e_string_from_footer_indent() {
    vx_web_html::Func_string_from_footer_indent output = vx_web_html::vx_package->e_string_from_footer_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_footer_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_footer_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_footer_indent t_string_from_footer_indent() {
    vx_web_html::Func_string_from_footer_indent output = vx_web_html::vx_package->t_string_from_footer_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_footer_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_footer_indent = output;
    }
    return output;
  }

  // (func string<-h1-indent)
  vx_web_html::Func_string_from_h1_indent e_string_from_h1_indent() {
    vx_web_html::Func_string_from_h1_indent output = vx_web_html::vx_package->e_string_from_h1_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_h1_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_h1_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_h1_indent t_string_from_h1_indent() {
    vx_web_html::Func_string_from_h1_indent output = vx_web_html::vx_package->t_string_from_h1_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_h1_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_h1_indent = output;
    }
    return output;
  }

  // (func string<-h2-indent)
  vx_web_html::Func_string_from_h2_indent e_string_from_h2_indent() {
    vx_web_html::Func_string_from_h2_indent output = vx_web_html::vx_package->e_string_from_h2_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_h2_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_h2_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_h2_indent t_string_from_h2_indent() {
    vx_web_html::Func_string_from_h2_indent output = vx_web_html::vx_package->t_string_from_h2_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_h2_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_h2_indent = output;
    }
    return output;
  }

  // (func string<-h3-indent)
  vx_web_html::Func_string_from_h3_indent e_string_from_h3_indent() {
    vx_web_html::Func_string_from_h3_indent output = vx_web_html::vx_package->e_string_from_h3_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_h3_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_h3_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_h3_indent t_string_from_h3_indent() {
    vx_web_html::Func_string_from_h3_indent output = vx_web_html::vx_package->t_string_from_h3_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_h3_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_h3_indent = output;
    }
    return output;
  }

  // (func string<-head-indent)
  vx_web_html::Func_string_from_head_indent e_string_from_head_indent() {
    vx_web_html::Func_string_from_head_indent output = vx_web_html::vx_package->e_string_from_head_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_head_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_head_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_head_indent t_string_from_head_indent() {
    vx_web_html::Func_string_from_head_indent output = vx_web_html::vx_package->t_string_from_head_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_head_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_head_indent = output;
    }
    return output;
  }

  // (func string<-html)
  vx_web_html::Func_string_from_html e_string_from_html() {
    vx_web_html::Func_string_from_html output = vx_web_html::vx_package->e_string_from_html;
    if (!output) {
      output = new vx_web_html::Class_string_from_html();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_html = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_html t_string_from_html() {
    vx_web_html::Func_string_from_html output = vx_web_html::vx_package->t_string_from_html;
    if (!output) {
      output = new vx_web_html::Class_string_from_html();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_html = output;
    }
    return output;
  }

  // (func string<-indent)
  vx_web_html::Func_string_from_indent e_string_from_indent() {
    vx_web_html::Func_string_from_indent output = vx_web_html::vx_package->e_string_from_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_indent t_string_from_indent() {
    vx_web_html::Func_string_from_indent output = vx_web_html::vx_package->t_string_from_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_indent = output;
    }
    return output;
  }

  // (func string<-meta-indent)
  vx_web_html::Func_string_from_meta_indent e_string_from_meta_indent() {
    vx_web_html::Func_string_from_meta_indent output = vx_web_html::vx_package->e_string_from_meta_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_meta_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_meta_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_meta_indent t_string_from_meta_indent() {
    vx_web_html::Func_string_from_meta_indent output = vx_web_html::vx_package->t_string_from_meta_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_meta_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_meta_indent = output;
    }
    return output;
  }

  // (func string<-node-indent)
  vx_web_html::Func_string_from_node_indent e_string_from_node_indent() {
    vx_web_html::Func_string_from_node_indent output = vx_web_html::vx_package->e_string_from_node_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_node_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_node_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_node_indent t_string_from_node_indent() {
    vx_web_html::Func_string_from_node_indent output = vx_web_html::vx_package->t_string_from_node_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_node_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_node_indent = output;
    }
    return output;
  }

  // (func string<-nodelist-indent)
  vx_web_html::Func_string_from_nodelist_indent e_string_from_nodelist_indent() {
    vx_web_html::Func_string_from_nodelist_indent output = vx_web_html::vx_package->e_string_from_nodelist_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_nodelist_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_nodelist_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_nodelist_indent t_string_from_nodelist_indent() {
    vx_web_html::Func_string_from_nodelist_indent output = vx_web_html::vx_package->t_string_from_nodelist_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_nodelist_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_nodelist_indent = output;
    }
    return output;
  }

  // (func string<-nodelist-tag-prop-indent)
  vx_web_html::Func_string_from_nodelist_tag_prop_indent e_string_from_nodelist_tag_prop_indent() {
    vx_web_html::Func_string_from_nodelist_tag_prop_indent output = vx_web_html::vx_package->e_string_from_nodelist_tag_prop_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_nodelist_tag_prop_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_nodelist_tag_prop_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_nodelist_tag_prop_indent t_string_from_nodelist_tag_prop_indent() {
    vx_web_html::Func_string_from_nodelist_tag_prop_indent output = vx_web_html::vx_package->t_string_from_nodelist_tag_prop_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_nodelist_tag_prop_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_nodelist_tag_prop_indent = output;
    }
    return output;
  }

  // (func string<-p-indent)
  vx_web_html::Func_string_from_p_indent e_string_from_p_indent() {
    vx_web_html::Func_string_from_p_indent output = vx_web_html::vx_package->e_string_from_p_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_p_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_p_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_p_indent t_string_from_p_indent() {
    vx_web_html::Func_string_from_p_indent output = vx_web_html::vx_package->t_string_from_p_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_p_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_p_indent = output;
    }
    return output;
  }

  // (func string<-propname-val)
  vx_web_html::Func_string_from_propname_val e_string_from_propname_val() {
    vx_web_html::Func_string_from_propname_val output = vx_web_html::vx_package->e_string_from_propname_val;
    if (!output) {
      output = new vx_web_html::Class_string_from_propname_val();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_propname_val = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_propname_val t_string_from_propname_val() {
    vx_web_html::Func_string_from_propname_val output = vx_web_html::vx_package->t_string_from_propname_val;
    if (!output) {
      output = new vx_web_html::Class_string_from_propname_val();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_propname_val = output;
    }
    return output;
  }

  // (func string<-propstyle)
  vx_web_html::Func_string_from_propstyle e_string_from_propstyle() {
    vx_web_html::Func_string_from_propstyle output = vx_web_html::vx_package->e_string_from_propstyle;
    if (!output) {
      output = new vx_web_html::Class_string_from_propstyle();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_propstyle = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_propstyle t_string_from_propstyle() {
    vx_web_html::Func_string_from_propstyle output = vx_web_html::vx_package->t_string_from_propstyle;
    if (!output) {
      output = new vx_web_html::Class_string_from_propstyle();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_propstyle = output;
    }
    return output;
  }

  // (func string<-style-indent)
  vx_web_html::Func_string_from_style_indent e_string_from_style_indent() {
    vx_web_html::Func_string_from_style_indent output = vx_web_html::vx_package->e_string_from_style_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_style_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_style_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_style_indent t_string_from_style_indent() {
    vx_web_html::Func_string_from_style_indent output = vx_web_html::vx_package->t_string_from_style_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_style_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_style_indent = output;
    }
    return output;
  }

  // (func string<-stylelist-indent)
  vx_web_html::Func_string_from_stylelist_indent e_string_from_stylelist_indent() {
    vx_web_html::Func_string_from_stylelist_indent output = vx_web_html::vx_package->e_string_from_stylelist_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_stylelist_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_stylelist_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_stylelist_indent t_string_from_stylelist_indent() {
    vx_web_html::Func_string_from_stylelist_indent output = vx_web_html::vx_package->t_string_from_stylelist_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_stylelist_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_stylelist_indent = output;
    }
    return output;
  }

  // (func string<-stylepropmap-indent)
  vx_web_html::Func_string_from_stylepropmap_indent e_string_from_stylepropmap_indent() {
    vx_web_html::Func_string_from_stylepropmap_indent output = vx_web_html::vx_package->e_string_from_stylepropmap_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_stylepropmap_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_stylepropmap_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_stylepropmap_indent t_string_from_stylepropmap_indent() {
    vx_web_html::Func_string_from_stylepropmap_indent output = vx_web_html::vx_package->t_string_from_stylepropmap_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_stylepropmap_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_stylepropmap_indent = output;
    }
    return output;
  }

  // (func string<-stylesheet-indent)
  vx_web_html::Func_string_from_stylesheet_indent e_string_from_stylesheet_indent() {
    vx_web_html::Func_string_from_stylesheet_indent output = vx_web_html::vx_package->e_string_from_stylesheet_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_stylesheet_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_stylesheet_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_stylesheet_indent t_string_from_stylesheet_indent() {
    vx_web_html::Func_string_from_stylesheet_indent output = vx_web_html::vx_package->t_string_from_stylesheet_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_stylesheet_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_stylesheet_indent = output;
    }
    return output;
  }

  // (func string<-table-indent)
  vx_web_html::Func_string_from_table_indent e_string_from_table_indent() {
    vx_web_html::Func_string_from_table_indent output = vx_web_html::vx_package->e_string_from_table_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_table_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_table_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_table_indent t_string_from_table_indent() {
    vx_web_html::Func_string_from_table_indent output = vx_web_html::vx_package->t_string_from_table_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_table_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_table_indent = output;
    }
    return output;
  }

  // (func string<-tbody-indent)
  vx_web_html::Func_string_from_tbody_indent e_string_from_tbody_indent() {
    vx_web_html::Func_string_from_tbody_indent output = vx_web_html::vx_package->e_string_from_tbody_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_tbody_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_tbody_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_tbody_indent t_string_from_tbody_indent() {
    vx_web_html::Func_string_from_tbody_indent output = vx_web_html::vx_package->t_string_from_tbody_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_tbody_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_tbody_indent = output;
    }
    return output;
  }

  // (func string<-td-indent)
  vx_web_html::Func_string_from_td_indent e_string_from_td_indent() {
    vx_web_html::Func_string_from_td_indent output = vx_web_html::vx_package->e_string_from_td_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_td_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_td_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_td_indent t_string_from_td_indent() {
    vx_web_html::Func_string_from_td_indent output = vx_web_html::vx_package->t_string_from_td_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_td_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_td_indent = output;
    }
    return output;
  }

  // (func string<-thead-indent)
  vx_web_html::Func_string_from_thead_indent e_string_from_thead_indent() {
    vx_web_html::Func_string_from_thead_indent output = vx_web_html::vx_package->e_string_from_thead_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_thead_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_thead_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_thead_indent t_string_from_thead_indent() {
    vx_web_html::Func_string_from_thead_indent output = vx_web_html::vx_package->t_string_from_thead_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_thead_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_thead_indent = output;
    }
    return output;
  }

  // (func string<-title-indent)
  vx_web_html::Func_string_from_title_indent e_string_from_title_indent() {
    vx_web_html::Func_string_from_title_indent output = vx_web_html::vx_package->e_string_from_title_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_title_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_title_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_title_indent t_string_from_title_indent() {
    vx_web_html::Func_string_from_title_indent output = vx_web_html::vx_package->t_string_from_title_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_title_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_title_indent = output;
    }
    return output;
  }

  // (func string<-tr-indent)
  vx_web_html::Func_string_from_tr_indent e_string_from_tr_indent() {
    vx_web_html::Func_string_from_tr_indent output = vx_web_html::vx_package->e_string_from_tr_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_tr_indent();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_tr_indent = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_tr_indent t_string_from_tr_indent() {
    vx_web_html::Func_string_from_tr_indent output = vx_web_html::vx_package->t_string_from_tr_indent;
    if (!output) {
      output = new vx_web_html::Class_string_from_tr_indent();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_tr_indent = output;
    }
    return output;
  }

  // (func string<-uri)
  vx_web_html::Func_string_from_uri e_string_from_uri() {
    vx_web_html::Func_string_from_uri output = vx_web_html::vx_package->e_string_from_uri;
    if (!output) {
      output = new vx_web_html::Class_string_from_uri();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_string_from_uri = output;
    }
    return output;
  }
  vx_web_html::Func_string_from_uri t_string_from_uri() {
    vx_web_html::Func_string_from_uri output = vx_web_html::vx_package->t_string_from_uri;
    if (!output) {
      output = new vx_web_html::Class_string_from_uri();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_string_from_uri = output;
    }
    return output;
  }

  // (func style<-stylesheet-name)
  vx_web_html::Func_style_from_stylesheet_name e_style_from_stylesheet_name() {
    vx_web_html::Func_style_from_stylesheet_name output = vx_web_html::vx_package->e_style_from_stylesheet_name;
    if (!output) {
      output = new vx_web_html::Class_style_from_stylesheet_name();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_style_from_stylesheet_name = output;
    }
    return output;
  }
  vx_web_html::Func_style_from_stylesheet_name t_style_from_stylesheet_name() {
    vx_web_html::Func_style_from_stylesheet_name output = vx_web_html::vx_package->t_style_from_stylesheet_name;
    if (!output) {
      output = new vx_web_html::Class_style_from_stylesheet_name();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_style_from_stylesheet_name = output;
    }
    return output;
  }

  // (func stylemap<-stylelist)
  vx_web_html::Func_stylemap_from_stylelist e_stylemap_from_stylelist() {
    vx_web_html::Func_stylemap_from_stylelist output = vx_web_html::vx_package->e_stylemap_from_stylelist;
    if (!output) {
      output = new vx_web_html::Class_stylemap_from_stylelist();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_stylemap_from_stylelist = output;
    }
    return output;
  }
  vx_web_html::Func_stylemap_from_stylelist t_stylemap_from_stylelist() {
    vx_web_html::Func_stylemap_from_stylelist output = vx_web_html::vx_package->t_stylemap_from_stylelist;
    if (!output) {
      output = new vx_web_html::Class_stylemap_from_stylelist();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_stylemap_from_stylelist = output;
    }
    return output;
  }

  // (func stylemap<-stylesheet)
  vx_web_html::Func_stylemap_from_stylesheet e_stylemap_from_stylesheet() {
    vx_web_html::Func_stylemap_from_stylesheet output = vx_web_html::vx_package->e_stylemap_from_stylesheet;
    if (!output) {
      output = new vx_web_html::Class_stylemap_from_stylesheet();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_stylemap_from_stylesheet = output;
    }
    return output;
  }
  vx_web_html::Func_stylemap_from_stylesheet t_stylemap_from_stylesheet() {
    vx_web_html::Func_stylemap_from_stylesheet output = vx_web_html::vx_package->t_stylemap_from_stylesheet;
    if (!output) {
      output = new vx_web_html::Class_stylemap_from_stylesheet();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_stylemap_from_stylesheet = output;
    }
    return output;
  }

  // (func styles<-stylesheet)
  vx_web_html::Func_styles_from_stylesheet e_styles_from_stylesheet() {
    vx_web_html::Func_styles_from_stylesheet output = vx_web_html::vx_package->e_styles_from_stylesheet;
    if (!output) {
      output = new vx_web_html::Class_styles_from_stylesheet();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_styles_from_stylesheet = output;
    }
    return output;
  }
  vx_web_html::Func_styles_from_stylesheet t_styles_from_stylesheet() {
    vx_web_html::Func_styles_from_stylesheet output = vx_web_html::vx_package->t_styles_from_stylesheet;
    if (!output) {
      output = new vx_web_html::Class_styles_from_stylesheet();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_styles_from_stylesheet = output;
    }
    return output;
  }

  // (func stylesheet-loadmap)
  vx_web_html::Func_stylesheet_loadmap e_stylesheet_loadmap() {
    vx_web_html::Func_stylesheet_loadmap output = vx_web_html::vx_package->e_stylesheet_loadmap;
    if (!output) {
      output = new vx_web_html::Class_stylesheet_loadmap();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_stylesheet_loadmap = output;
    }
    return output;
  }
  vx_web_html::Func_stylesheet_loadmap t_stylesheet_loadmap() {
    vx_web_html::Func_stylesheet_loadmap output = vx_web_html::vx_package->t_stylesheet_loadmap;
    if (!output) {
      output = new vx_web_html::Class_stylesheet_loadmap();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_stylesheet_loadmap = output;
    }
    return output;
  }

  // (func uri<-string)
  vx_web_html::Func_uri_from_string e_uri_from_string() {
    vx_web_html::Func_uri_from_string output = vx_web_html::vx_package->e_uri_from_string;
    if (!output) {
      output = new vx_web_html::Class_uri_from_string();
      vx_core::vx_reserve_empty(output);
      vx_web_html::vx_package->e_uri_from_string = output;
    }
    return output;
  }
  vx_web_html::Func_uri_from_string t_uri_from_string() {
    vx_web_html::Func_uri_from_string output = vx_web_html::vx_package->t_uri_from_string;
    if (!output) {
      output = new vx_web_html::Class_uri_from_string();
      vx_core::vx_reserve_type(output);
      vx_web_html::vx_package->t_uri_from_string = output;
    }
    return output;
  }

}
