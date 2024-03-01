#include <map>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/event.hpp"
#include "../../vx/data/file.hpp"
#include "../../vx/state.hpp"
#include "ui.hpp"

namespace vx_ui_ui {



  // (type bounds)
  // class Class_bounds {
    Abstract_bounds::~Abstract_bounds() {}

    Class_bounds::Class_bounds() : Abstract_bounds::Abstract_bounds() {
      vx_core::refcount += 1;
    }

    Class_bounds::~Class_bounds() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_left,
        this->vx_p_right,
        this->vx_p_top,
        this->vx_p_bottom
      });
    }

    // left()
    vx_core::Type_int Class_bounds::left() const {
      vx_core::Type_int output = this->vx_p_left;
      if (!output) {
        output = vx_core::e_int;
      }
      return output;
    }

    // right()
    vx_core::Type_int Class_bounds::right() const {
      vx_core::Type_int output = this->vx_p_right;
      if (!output) {
        output = vx_core::e_int;
      }
      return output;
    }

    // top()
    vx_core::Type_int Class_bounds::top() const {
      vx_core::Type_int output = this->vx_p_top;
      if (!output) {
        output = vx_core::e_int;
      }
      return output;
    }

    // bottom()
    vx_core::Type_int Class_bounds::bottom() const {
      vx_core::Type_int output = this->vx_p_bottom;
      if (!output) {
        output = vx_core::e_int;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_bounds::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":left") {
        output = this->left();
      } else if (skey == ":right") {
        output = this->right();
      } else if (skey == ":top") {
        output = this->top();
      } else if (skey == ":bottom") {
        output = this->bottom();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_bounds::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":left"] = this->left();
      output[":right"] = this->right();
      output[":top"] = this->top();
      output[":bottom"] = this->bottom();
      return output;
    }

    vx_core::Type_any Class_bounds::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_bounds, vals);
    }

    vx_core::Type_any Class_bounds::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_bounds output = vx_ui_ui::e_bounds;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_bounds val = vx_core::vx_any_from_any(vx_ui_ui::t_bounds, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_int vx_p_left = val->left();
      vx_core::Type_int vx_p_right = val->right();
      vx_core::Type_int vx_p_top = val->top();
      vx_core::Type_int vx_p_bottom = val->bottom();
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
          } else if (testkey == ":left") {
            key = testkey;
          } else if (testkey == ":right") {
            key = testkey;
          } else if (testkey == ":top") {
            key = testkey;
          } else if (testkey == ":bottom") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new bounds) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":left") {
            if (vx_p_left == valsub) {
            } else if (valsubtype == vx_core::t_int) {
              ischanged = true;
              vx_p_left = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new bounds :left " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":right") {
            if (vx_p_right == valsub) {
            } else if (valsubtype == vx_core::t_int) {
              ischanged = true;
              vx_p_right = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new bounds :right " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":top") {
            if (vx_p_top == valsub) {
            } else if (valsubtype == vx_core::t_int) {
              ischanged = true;
              vx_p_top = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new bounds :top " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":bottom") {
            if (vx_p_bottom == valsub) {
            } else if (valsubtype == vx_core::t_int) {
              ischanged = true;
              vx_p_bottom = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new bounds :bottom " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new bounds) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_bounds();
        if (output->vx_p_left != vx_p_left) {
          if (output->vx_p_left) {
            vx_core::vx_release_one(output->vx_p_left);
          }
          output->vx_p_left = vx_p_left;
          vx_core::vx_reserve(vx_p_left);
        }
        if (output->vx_p_right != vx_p_right) {
          if (output->vx_p_right) {
            vx_core::vx_release_one(output->vx_p_right);
          }
          output->vx_p_right = vx_p_right;
          vx_core::vx_reserve(vx_p_right);
        }
        if (output->vx_p_top != vx_p_top) {
          if (output->vx_p_top) {
            vx_core::vx_release_one(output->vx_p_top);
          }
          output->vx_p_top = vx_p_top;
          vx_core::vx_reserve(vx_p_top);
        }
        if (output->vx_p_bottom != vx_p_bottom) {
          if (output->vx_p_bottom) {
            vx_core::vx_release_one(output->vx_p_bottom);
          }
          output->vx_p_bottom = vx_p_bottom;
          vx_core::vx_reserve(vx_p_bottom);
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

    vx_core::Type_msgblock Class_bounds::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_bounds::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_bounds::vx_empty() const {return vx_ui_ui::e_bounds;}
    vx_core::Type_any Class_bounds::vx_type() const {return vx_ui_ui::t_bounds;}

    vx_core::Type_typedef Class_bounds::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "bounds", // name
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
            "left", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "right", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "top", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "bottom", // name
            vx_core::t_int // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_bounds::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type cursor)
  // class Class_cursor {
    Abstract_cursor::~Abstract_cursor() {}

    Class_cursor::Class_cursor() : Abstract_cursor::Abstract_cursor() {
      vx_core::refcount += 1;
    }

    Class_cursor::~Class_cursor() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        
      });
    }

    // vx_get_any(key)
    vx_core::Type_any Class_cursor::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_cursor::vx_map() const {
      vx_core::vx_Type_mapany output;
      return output;
    }

    vx_core::Type_any Class_cursor::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_cursor, vals);
    }

    vx_core::Type_any Class_cursor::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_cursor output = vx_ui_ui::e_cursor;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_cursor val = vx_core::vx_any_from_any(vx_ui_ui::t_cursor, copyval);
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

    vx_core::Type_msgblock Class_cursor::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_cursor::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_cursor::vx_empty() const {return vx_ui_ui::e_cursor;}
    vx_core::Type_any Class_cursor::vx_type() const {return vx_ui_ui::t_cursor;}

    vx_core::Type_typedef Class_cursor::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "cursor", // name
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

    vx_core::Type_constdef Class_cursor::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type cursor-pointer)
  // class Class_cursor_pointer {
    Abstract_cursor_pointer::~Abstract_cursor_pointer() {}

    Class_cursor_pointer::Class_cursor_pointer() : Abstract_cursor_pointer::Abstract_cursor_pointer() {
      vx_core::refcount += 1;
    }

    Class_cursor_pointer::~Class_cursor_pointer() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_cursor_pointer::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_cursor_pointer, vals);
    }

    vx_core::Type_any Class_cursor_pointer::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_cursor_pointer output = vx_ui_ui::e_cursor_pointer;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_msgblock Class_cursor_pointer::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_cursor_pointer::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_cursor_pointer::vx_empty() const {return vx_ui_ui::e_cursor_pointer;}
    vx_core::Type_any Class_cursor_pointer::vx_type() const {return vx_ui_ui::t_cursor_pointer;}

    vx_core::Type_typedef Class_cursor_pointer::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "cursor-pointer", // name
        ":cursor", // extends
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

    vx_core::Type_constdef Class_cursor_pointer::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type layout)
  // class Class_layout {
    Abstract_layout::~Abstract_layout() {}

    Class_layout::Class_layout() : Abstract_layout::Abstract_layout() {
      vx_core::refcount += 1;
    }

    Class_layout::~Class_layout() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_name,
        this->vx_p_fn_layout
      });
    }

    // name()
    vx_core::Type_string Class_layout::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // fn_layout()
    vx_ui_ui::Func_ui_render_from_ui_orig_parent Class_layout::fn_layout() const {
      vx_ui_ui::Func_ui_render_from_ui_orig_parent output = this->vx_p_fn_layout;
      if (!output) {
        output = vx_ui_ui::e_ui_render_from_ui_orig_parent;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_layout::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":fn-layout") {
        output = this->fn_layout();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_layout::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":name"] = this->name();
      output[":fn-layout"] = this->fn_layout();
      return output;
    }

    vx_core::Type_any Class_layout::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_layout, vals);
    }

    vx_core::Type_any Class_layout::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_layout output = vx_ui_ui::e_layout;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_layout val = vx_core::vx_any_from_any(vx_ui_ui::t_layout, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_name = val->name();
      vx_ui_ui::Func_ui_render_from_ui_orig_parent vx_p_fn_layout = val->fn_layout();
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
          } else if (testkey == ":fn-layout") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new layout) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
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
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new layout :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":fn-layout") {
            if (vx_p_fn_layout == valsub) {
            } else if (valsubtype == vx_ui_ui::t_ui_render_from_ui_orig_parent) {
              ischanged = true;
              vx_p_fn_layout = vx_core::vx_any_from_any(vx_ui_ui::t_ui_render_from_ui_orig_parent, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new layout :fn-layout " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new layout) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_layout();
        if (output->vx_p_name != vx_p_name) {
          if (output->vx_p_name) {
            vx_core::vx_release_one(output->vx_p_name);
          }
          output->vx_p_name = vx_p_name;
          vx_core::vx_reserve(vx_p_name);
        }
        if (output->vx_p_fn_layout != vx_p_fn_layout) {
          if (output->vx_p_fn_layout) {
            vx_core::vx_release_one(output->vx_p_fn_layout);
          }
          output->vx_p_fn_layout = vx_p_fn_layout;
          vx_core::vx_reserve(vx_p_fn_layout);
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

    vx_core::Type_msgblock Class_layout::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_layout::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_layout::vx_empty() const {return vx_ui_ui::e_layout;}
    vx_core::Type_any Class_layout::vx_type() const {return vx_ui_ui::t_layout;}

    vx_core::Type_typedef Class_layout::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "layout", // name
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
            "fn-layout", // name
            vx_ui_ui::t_ui_render_from_ui_orig_parent // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_layout::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type layoutengine)
  // class Class_layoutengine {
    Abstract_layoutengine::~Abstract_layoutengine() {}

    Class_layoutengine::Class_layoutengine() : Abstract_layoutengine::Abstract_layoutengine() {
      vx_core::refcount += 1;
    }

    Class_layoutengine::~Class_layoutengine() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_name,
        this->vx_p_layoutmap,
        this->vx_p_layoutelse,
        this->vx_p_stylesheetrender
      });
    }

    // name()
    vx_core::Type_string Class_layoutengine::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // layoutmap()
    vx_ui_ui::Type_layoutmap Class_layoutengine::layoutmap() const {
      vx_ui_ui::Type_layoutmap output = this->vx_p_layoutmap;
      if (!output) {
        output = vx_ui_ui::e_layoutmap;
      }
      return output;
    }

    // layoutelse()
    vx_ui_ui::Type_layout Class_layoutengine::layoutelse() const {
      vx_ui_ui::Type_layout output = this->vx_p_layoutelse;
      if (!output) {
        output = vx_ui_ui::e_layout;
      }
      return output;
    }

    // stylesheetrender()
    vx_ui_ui::Func_stylesheet_render Class_layoutengine::stylesheetrender() const {
      vx_ui_ui::Func_stylesheet_render output = this->vx_p_stylesheetrender;
      if (!output) {
        output = vx_ui_ui::e_stylesheet_render;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_layoutengine::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":layoutmap") {
        output = this->layoutmap();
      } else if (skey == ":layoutelse") {
        output = this->layoutelse();
      } else if (skey == ":stylesheetrender") {
        output = this->stylesheetrender();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_layoutengine::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":name"] = this->name();
      output[":layoutmap"] = this->layoutmap();
      output[":layoutelse"] = this->layoutelse();
      output[":stylesheetrender"] = this->stylesheetrender();
      return output;
    }

    vx_core::Type_any Class_layoutengine::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_layoutengine, vals);
    }

    vx_core::Type_any Class_layoutengine::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_layoutengine output = vx_ui_ui::e_layoutengine;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_layoutengine val = vx_core::vx_any_from_any(vx_ui_ui::t_layoutengine, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_name = val->name();
      vx_ui_ui::Type_layoutmap vx_p_layoutmap = val->layoutmap();
      vx_ui_ui::Type_layout vx_p_layoutelse = val->layoutelse();
      vx_ui_ui::Func_stylesheet_render vx_p_stylesheetrender = val->stylesheetrender();
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
          } else if (testkey == ":layoutmap") {
            key = testkey;
          } else if (testkey == ":layoutelse") {
            key = testkey;
          } else if (testkey == ":stylesheetrender") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new layoutengine) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
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
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new layoutengine :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":layoutmap") {
            if (vx_p_layoutmap == valsub) {
            } else if (valsubtype == vx_ui_ui::t_layoutmap) {
              ischanged = true;
              vx_p_layoutmap = vx_core::vx_any_from_any(vx_ui_ui::t_layoutmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new layoutengine :layoutmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":layoutelse") {
            if (vx_p_layoutelse == valsub) {
            } else if (valsubtype == vx_ui_ui::t_layout) {
              ischanged = true;
              vx_p_layoutelse = vx_core::vx_any_from_any(vx_ui_ui::t_layout, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new layoutengine :layoutelse " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":stylesheetrender") {
            if (vx_p_stylesheetrender == valsub) {
            } else if (valsubtype == vx_ui_ui::t_stylesheet_render) {
              ischanged = true;
              vx_p_stylesheetrender = vx_core::vx_any_from_any(vx_ui_ui::t_stylesheet_render, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new layoutengine :stylesheetrender " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new layoutengine) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_layoutengine();
        if (output->vx_p_name != vx_p_name) {
          if (output->vx_p_name) {
            vx_core::vx_release_one(output->vx_p_name);
          }
          output->vx_p_name = vx_p_name;
          vx_core::vx_reserve(vx_p_name);
        }
        if (output->vx_p_layoutmap != vx_p_layoutmap) {
          if (output->vx_p_layoutmap) {
            vx_core::vx_release_one(output->vx_p_layoutmap);
          }
          output->vx_p_layoutmap = vx_p_layoutmap;
          vx_core::vx_reserve(vx_p_layoutmap);
        }
        if (output->vx_p_layoutelse != vx_p_layoutelse) {
          if (output->vx_p_layoutelse) {
            vx_core::vx_release_one(output->vx_p_layoutelse);
          }
          output->vx_p_layoutelse = vx_p_layoutelse;
          vx_core::vx_reserve(vx_p_layoutelse);
        }
        if (output->vx_p_stylesheetrender != vx_p_stylesheetrender) {
          if (output->vx_p_stylesheetrender) {
            vx_core::vx_release_one(output->vx_p_stylesheetrender);
          }
          output->vx_p_stylesheetrender = vx_p_stylesheetrender;
          vx_core::vx_reserve(vx_p_stylesheetrender);
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

    vx_core::Type_msgblock Class_layoutengine::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_layoutengine::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_layoutengine::vx_empty() const {return vx_ui_ui::e_layoutengine;}
    vx_core::Type_any Class_layoutengine::vx_type() const {return vx_ui_ui::t_layoutengine;}

    vx_core::Type_typedef Class_layoutengine::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "layoutengine", // name
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
            "layoutmap", // name
            vx_ui_ui::t_layoutmap // type
          ),
          vx_core::vx_new_arg(
            "layoutelse", // name
            vx_ui_ui::t_layout // type
          ),
          vx_core::vx_new_arg(
            "stylesheetrender", // name
            vx_ui_ui::t_stylesheet_render // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_layoutengine::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type layoutlist)
  // class Class_layoutlist {
    Abstract_layoutlist::~Abstract_layoutlist() {}

    Class_layoutlist::Class_layoutlist() : Abstract_layoutlist::Abstract_layoutlist() {
      vx_core::refcount += 1;
    }

    Class_layoutlist::~Class_layoutlist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_layoutlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_ui_ui::Type_layout Class_layoutlist::vx_get_layout(vx_core::Type_int index) const {
      vx_ui_ui::Type_layout output = vx_ui_ui::e_layout;
      long iindex = index->vx_int();
      std::vector<vx_ui_ui::Type_layout> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_ui_ui::Type_layout> Class_layoutlist::vx_listlayout() const {return vx_p_list;}

    vx_core::Type_any vx_ui_ui::Class_layoutlist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_layout(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_layoutlist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_ui_ui::Type_layoutlist output = vx_ui_ui::e_layoutlist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_ui_ui::Type_layout> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_ui_ui::t_layout) {
          vx_ui_ui::Type_layout castval = vx_core::vx_any_from_any(vx_ui_ui::t_layout, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_ui_ui::t_layout)) {
          vx_ui_ui::Type_layout castval = vx_core::vx_any_from_any(vx_ui_ui::t_layout, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(layoutlist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_layoutlist();
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

    vx_core::Type_any Class_layoutlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_layoutlist, vals);
    }

    vx_core::Type_any Class_layoutlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_layoutlist output = vx_ui_ui::e_layoutlist;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_layoutlist val = vx_core::vx_any_from_any(vx_ui_ui::t_layoutlist, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_ui_ui::Type_layout> listval = val->vx_listlayout();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_ui_ui::t_layout) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_ui_ui::t_layout, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_ui_ui::t_layout)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_ui_ui::t_layout, valsub));
        } else if (valsubtype == vx_ui_ui::t_layoutlist) {
          ischanged = true;
          vx_ui_ui::Type_layoutlist multi = vx_core::vx_any_from_any(vx_ui_ui::t_layoutlist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listlayout());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new layoutlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_layoutlist();
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

    vx_core::Type_msgblock Class_layoutlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_layoutlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_layoutlist::vx_empty() const {return vx_ui_ui::e_layoutlist;}
    vx_core::Type_any Class_layoutlist::vx_type() const {return vx_ui_ui::t_layoutlist;}

    vx_core::Type_typedef Class_layoutlist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "layoutlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_ui_ui::t_layout}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_layoutlist::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type layoutmap)
  // class Class_layoutmap {
    Abstract_layoutmap::~Abstract_layoutmap() {}

    Class_layoutmap::Class_layoutmap() : Abstract_layoutmap::Abstract_layoutmap() {
      vx_core::refcount += 1;
    }

    Class_layoutmap::~Class_layoutmap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (auto const& [key, val] : this->vx_p_map) {
        vx_core::vx_release_one(val);
      }
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_layoutmap::vx_map() const {
      vx_core::vx_Type_mapany output = vx_core::vx_map_from_map(vx_core::t_any, this->vx_p_map);
      return output;
    }

    // vx_get_layout(key)
    vx_ui_ui::Type_layout Class_layoutmap::vx_get_layout(vx_core::Type_string key) const {
      vx_ui_ui::Type_layout output = vx_ui_ui::e_layout;
      const vx_ui_ui::Class_layoutmap* map = this;
      std::string skey = key->vx_string();
      if (vx_core::vx_boolean_from_string_starts(skey, ":")) {
        skey = vx_core::vx_string_from_string_start(skey, 2);
      }
      std::map<std::string, vx_ui_ui::Type_layout> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_ui_ui::e_layout);
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_layoutmap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_layout(key);
    }

    // vx_maplayout()
    std::map<std::string, vx_ui_ui::Type_layout> Class_layoutmap::vx_maplayout() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_layoutmap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_ui_ui::Type_layoutmap output = vx_ui_ui::e_layoutmap;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_ui_ui::Type_layout> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_ui_ui::t_layout) {
          vx_ui_ui::Type_layout castval = vx_core::vx_any_from_any(vx_ui_ui::t_layout, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(layoutmap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((map.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_layoutmap();
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

    vx_core::Type_any Class_layoutmap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_layoutmap, vals);
    }

    vx_core::Type_any Class_layoutmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_layoutmap output = vx_ui_ui::e_layoutmap;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_layoutmap valmap = vx_core::vx_any_from_any(vx_ui_ui::t_layoutmap, copyval);
      output = valmap;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_ui_ui::Type_layout> mapval = valmap->vx_maplayout();
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
          vx_ui_ui::Type_layout valany = NULL;
          if (valsubtype == vx_ui_ui::t_layout) {
            valany = vx_core::vx_any_from_any(vx_ui_ui::t_layout, valsub);
          } else if (valsubtype == vx_ui_ui::t_layout) {
            valany = vx_core::vx_any_from_any(vx_ui_ui::t_layout, valsub);
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
        output = new vx_ui_ui::Class_layoutmap();
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

    vx_core::Type_msgblock Class_layoutmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_layoutmap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_layoutmap::vx_empty() const {return vx_ui_ui::e_layoutmap;}
    vx_core::Type_any Class_layoutmap::vx_type() const {return vx_ui_ui::t_layoutmap;}

    vx_core::Type_typedef Class_layoutmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "layoutmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_ui_ui::t_layout}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_layoutmap::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type pin)
  // class Class_pin {
    Abstract_pin::~Abstract_pin() {}

    Class_pin::Class_pin() : Abstract_pin::Abstract_pin() {
      vx_core::refcount += 1;
    }

    Class_pin::~Class_pin() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_name
      });
    }

    // name()
    vx_core::Type_string Class_pin::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_pin::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":name") {
        output = this->name();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_pin::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":name"] = this->name();
      return output;
    }

    vx_core::Type_any Class_pin::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_pin, vals);
    }

    vx_core::Type_any Class_pin::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_pin output = vx_ui_ui::e_pin;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_pin val = vx_core::vx_any_from_any(vx_ui_ui::t_pin, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_name = val->name();
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
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new pin) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
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
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new pin :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new pin) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_pin();
        if (output->vx_p_name != vx_p_name) {
          if (output->vx_p_name) {
            vx_core::vx_release_one(output->vx_p_name);
          }
          output->vx_p_name = vx_p_name;
          vx_core::vx_reserve(vx_p_name);
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

    vx_core::Type_msgblock Class_pin::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_pin::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_pin::vx_empty() const {return vx_ui_ui::e_pin;}
    vx_core::Type_any Class_pin::vx_type() const {return vx_ui_ui::t_pin;}

    vx_core::Type_typedef Class_pin::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "pin", // name
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
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_pin::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type point)
  // class Class_point {
    Abstract_point::~Abstract_point() {}

    Class_point::Class_point() : Abstract_point::Abstract_point() {
      vx_core::refcount += 1;
    }

    Class_point::~Class_point() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_x,
        this->vx_p_y,
        this->vx_p_z,
        this->vx_p_t,
        this->vx_p_i,
        this->vx_p_ispercent,
        this->vx_p_pointstyle
      });
    }

    // x()
    vx_core::Type_int Class_point::x() const {
      vx_core::Type_int output = this->vx_p_x;
      if (!output) {
        output = vx_core::e_int;
      }
      return output;
    }

    // y()
    vx_core::Type_int Class_point::y() const {
      vx_core::Type_int output = this->vx_p_y;
      if (!output) {
        output = vx_core::e_int;
      }
      return output;
    }

    // z()
    vx_core::Type_int Class_point::z() const {
      vx_core::Type_int output = this->vx_p_z;
      if (!output) {
        output = vx_core::e_int;
      }
      return output;
    }

    // t()
    vx_core::Type_int Class_point::t() const {
      vx_core::Type_int output = this->vx_p_t;
      if (!output) {
        output = vx_core::e_int;
      }
      return output;
    }

    // i()
    vx_core::Type_int Class_point::i() const {
      vx_core::Type_int output = this->vx_p_i;
      if (!output) {
        output = vx_core::e_int;
      }
      return output;
    }

    // ispercent()
    vx_core::Type_boolean Class_point::ispercent() const {
      vx_core::Type_boolean output = this->vx_p_ispercent;
      if (!output) {
        output = vx_core::e_boolean;
      }
      return output;
    }

    // pointstyle()
    vx_ui_ui::Type_pointstyle Class_point::pointstyle() const {
      vx_ui_ui::Type_pointstyle output = this->vx_p_pointstyle;
      if (!output) {
        output = vx_ui_ui::e_pointstyle;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_point::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":x") {
        output = this->x();
      } else if (skey == ":y") {
        output = this->y();
      } else if (skey == ":z") {
        output = this->z();
      } else if (skey == ":t") {
        output = this->t();
      } else if (skey == ":i") {
        output = this->i();
      } else if (skey == ":ispercent") {
        output = this->ispercent();
      } else if (skey == ":pointstyle") {
        output = this->pointstyle();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_point::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":x"] = this->x();
      output[":y"] = this->y();
      output[":z"] = this->z();
      output[":t"] = this->t();
      output[":i"] = this->i();
      output[":ispercent"] = this->ispercent();
      output[":pointstyle"] = this->pointstyle();
      return output;
    }

    vx_core::Type_any Class_point::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_point, vals);
    }

    vx_core::Type_any Class_point::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_point output = vx_ui_ui::e_point;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_point val = vx_core::vx_any_from_any(vx_ui_ui::t_point, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_int vx_p_x = val->x();
      vx_core::Type_int vx_p_y = val->y();
      vx_core::Type_int vx_p_z = val->z();
      vx_core::Type_int vx_p_t = val->t();
      vx_core::Type_int vx_p_i = val->i();
      vx_core::Type_boolean vx_p_ispercent = val->ispercent();
      vx_ui_ui::Type_pointstyle vx_p_pointstyle = val->pointstyle();
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
          } else if (testkey == ":x") {
            key = testkey;
          } else if (testkey == ":y") {
            key = testkey;
          } else if (testkey == ":z") {
            key = testkey;
          } else if (testkey == ":t") {
            key = testkey;
          } else if (testkey == ":i") {
            key = testkey;
          } else if (testkey == ":ispercent") {
            key = testkey;
          } else if (testkey == ":pointstyle") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new point) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":x") {
            if (vx_p_x == valsub) {
            } else if (valsubtype == vx_core::t_int) {
              ischanged = true;
              vx_p_x = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new point :x " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":y") {
            if (vx_p_y == valsub) {
            } else if (valsubtype == vx_core::t_int) {
              ischanged = true;
              vx_p_y = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new point :y " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":z") {
            if (vx_p_z == valsub) {
            } else if (valsubtype == vx_core::t_int) {
              ischanged = true;
              vx_p_z = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new point :z " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":t") {
            if (vx_p_t == valsub) {
            } else if (valsubtype == vx_core::t_int) {
              ischanged = true;
              vx_p_t = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new point :t " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":i") {
            if (vx_p_i == valsub) {
            } else if (valsubtype == vx_core::t_int) {
              ischanged = true;
              vx_p_i = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new point :i " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":ispercent") {
            if (vx_p_ispercent == valsub) {
            } else if (valsubtype == vx_core::t_boolean) {
              ischanged = true;
              vx_p_ispercent = vx_core::vx_any_from_any(vx_core::t_boolean, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new point :ispercent " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":pointstyle") {
            if (vx_p_pointstyle == valsub) {
            } else if (valsubtype == vx_ui_ui::t_pointstyle) {
              ischanged = true;
              vx_p_pointstyle = vx_core::vx_any_from_any(vx_ui_ui::t_pointstyle, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new point :pointstyle " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new point) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_point();
        if (output->vx_p_x != vx_p_x) {
          if (output->vx_p_x) {
            vx_core::vx_release_one(output->vx_p_x);
          }
          output->vx_p_x = vx_p_x;
          vx_core::vx_reserve(vx_p_x);
        }
        if (output->vx_p_y != vx_p_y) {
          if (output->vx_p_y) {
            vx_core::vx_release_one(output->vx_p_y);
          }
          output->vx_p_y = vx_p_y;
          vx_core::vx_reserve(vx_p_y);
        }
        if (output->vx_p_z != vx_p_z) {
          if (output->vx_p_z) {
            vx_core::vx_release_one(output->vx_p_z);
          }
          output->vx_p_z = vx_p_z;
          vx_core::vx_reserve(vx_p_z);
        }
        if (output->vx_p_t != vx_p_t) {
          if (output->vx_p_t) {
            vx_core::vx_release_one(output->vx_p_t);
          }
          output->vx_p_t = vx_p_t;
          vx_core::vx_reserve(vx_p_t);
        }
        if (output->vx_p_i != vx_p_i) {
          if (output->vx_p_i) {
            vx_core::vx_release_one(output->vx_p_i);
          }
          output->vx_p_i = vx_p_i;
          vx_core::vx_reserve(vx_p_i);
        }
        if (output->vx_p_ispercent != vx_p_ispercent) {
          if (output->vx_p_ispercent) {
            vx_core::vx_release_one(output->vx_p_ispercent);
          }
          output->vx_p_ispercent = vx_p_ispercent;
          vx_core::vx_reserve(vx_p_ispercent);
        }
        if (output->vx_p_pointstyle != vx_p_pointstyle) {
          if (output->vx_p_pointstyle) {
            vx_core::vx_release_one(output->vx_p_pointstyle);
          }
          output->vx_p_pointstyle = vx_p_pointstyle;
          vx_core::vx_reserve(vx_p_pointstyle);
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

    vx_core::Type_msgblock Class_point::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_point::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_point::vx_empty() const {return vx_ui_ui::e_point;}
    vx_core::Type_any Class_point::vx_type() const {return vx_ui_ui::t_point;}

    vx_core::Type_typedef Class_point::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "point", // name
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
            "x", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "y", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "z", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "t", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "i", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "ispercent", // name
            vx_core::t_boolean // type
          ),
          vx_core::vx_new_arg(
            "pointstyle", // name
            vx_ui_ui::t_pointstyle // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_point::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type pointstyle)
  // class Class_pointstyle {
    Abstract_pointstyle::~Abstract_pointstyle() {}

    Class_pointstyle::Class_pointstyle() : Abstract_pointstyle::Abstract_pointstyle() {
      vx_core::refcount += 1;
    }

    Class_pointstyle::~Class_pointstyle() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        
      });
    }

    // vx_get_any(key)
    vx_core::Type_any Class_pointstyle::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_pointstyle::vx_map() const {
      vx_core::vx_Type_mapany output;
      return output;
    }

    vx_core::Type_any Class_pointstyle::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_pointstyle, vals);
    }

    vx_core::Type_any Class_pointstyle::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_pointstyle output = vx_ui_ui::e_pointstyle;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_pointstyle val = vx_core::vx_any_from_any(vx_ui_ui::t_pointstyle, copyval);
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

    vx_core::Type_msgblock Class_pointstyle::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_pointstyle::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_pointstyle::vx_empty() const {return vx_ui_ui::e_pointstyle;}
    vx_core::Type_any Class_pointstyle::vx_type() const {return vx_ui_ui::t_pointstyle;}

    vx_core::Type_typedef Class_pointstyle::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "pointstyle", // name
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

    vx_core::Type_constdef Class_pointstyle::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type render)
  // class Class_render {
    Abstract_render::~Abstract_render() {}

    Class_render::Class_render() : Abstract_render::Abstract_render() {
      vx_core::refcount += 1;
    }

    Class_render::~Class_render() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        
      });
    }

    // vx_get_any(key)
    vx_core::Type_any Class_render::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_render::vx_map() const {
      vx_core::vx_Type_mapany output;
      return output;
    }

    vx_core::Type_any Class_render::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_render, vals);
    }

    vx_core::Type_any Class_render::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_render output = vx_ui_ui::e_render;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_render val = vx_core::vx_any_from_any(vx_ui_ui::t_render, copyval);
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

    vx_core::Type_msgblock Class_render::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_render::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_render::vx_empty() const {return vx_ui_ui::e_render;}
    vx_core::Type_any Class_render::vx_type() const {return vx_ui_ui::t_render;}

    vx_core::Type_typedef Class_render::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "render", // name
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

    vx_core::Type_constdef Class_render::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type rendermap)
  // class Class_rendermap {
    Abstract_rendermap::~Abstract_rendermap() {}

    Class_rendermap::Class_rendermap() : Abstract_rendermap::Abstract_rendermap() {
      vx_core::refcount += 1;
    }

    Class_rendermap::~Class_rendermap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (auto const& [key, val] : this->vx_p_map) {
        vx_core::vx_release_one(val);
      }
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_rendermap::vx_map() const {
      vx_core::vx_Type_mapany output = vx_core::vx_map_from_map(vx_core::t_any, this->vx_p_map);
      return output;
    }

    // vx_get_render(key)
    vx_ui_ui::Type_render Class_rendermap::vx_get_render(vx_core::Type_string key) const {
      vx_ui_ui::Type_render output = vx_ui_ui::e_render;
      const vx_ui_ui::Class_rendermap* map = this;
      std::string skey = key->vx_string();
      if (vx_core::vx_boolean_from_string_starts(skey, ":")) {
        skey = vx_core::vx_string_from_string_start(skey, 2);
      }
      std::map<std::string, vx_ui_ui::Type_render> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_ui_ui::e_render);
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_rendermap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_render(key);
    }

    // vx_maprender()
    std::map<std::string, vx_ui_ui::Type_render> Class_rendermap::vx_maprender() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_rendermap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_ui_ui::Type_rendermap output = vx_ui_ui::e_rendermap;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_ui_ui::Type_render> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_ui_ui::t_render) {
          vx_ui_ui::Type_render castval = vx_core::vx_any_from_any(vx_ui_ui::t_render, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(rendermap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((map.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_rendermap();
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

    vx_core::Type_any Class_rendermap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_rendermap, vals);
    }

    vx_core::Type_any Class_rendermap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_rendermap output = vx_ui_ui::e_rendermap;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_rendermap valmap = vx_core::vx_any_from_any(vx_ui_ui::t_rendermap, copyval);
      output = valmap;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_ui_ui::Type_render> mapval = valmap->vx_maprender();
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
          vx_ui_ui::Type_render valany = NULL;
          if (valsubtype == vx_ui_ui::t_render) {
            valany = vx_core::vx_any_from_any(vx_ui_ui::t_render, valsub);
          } else if (valsubtype == vx_ui_ui::t_render) {
            valany = vx_core::vx_any_from_any(vx_ui_ui::t_render, valsub);
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
        output = new vx_ui_ui::Class_rendermap();
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

    vx_core::Type_msgblock Class_rendermap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_rendermap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_rendermap::vx_empty() const {return vx_ui_ui::e_rendermap;}
    vx_core::Type_any Class_rendermap::vx_type() const {return vx_ui_ui::t_rendermap;}

    vx_core::Type_typedef Class_rendermap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "rendermap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_ui_ui::t_render}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_rendermap::vx_constdef() const {return this->vx_p_constdef;}


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
        this->vx_p_boundsmargin,
        this->vx_p_boundspadding,
        this->vx_p_color_background,
        this->vx_p_color_hoverbkgrd,
        this->vx_p_cursor,
        this->vx_p_image_background,
        this->vx_p_layout,
        this->vx_p_type,
        this->vx_p_pin,
        this->vx_p_pointpos,
        this->vx_p_pointsize
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

    // boundsmargin()
    vx_ui_ui::Type_bounds Class_style::boundsmargin() const {
      vx_ui_ui::Type_bounds output = this->vx_p_boundsmargin;
      if (!output) {
        output = vx_ui_ui::e_bounds;
      }
      return output;
    }

    // boundspadding()
    vx_ui_ui::Type_bounds Class_style::boundspadding() const {
      vx_ui_ui::Type_bounds output = this->vx_p_boundspadding;
      if (!output) {
        output = vx_ui_ui::e_bounds;
      }
      return output;
    }

    // color_background()
    vx_core::Type_string Class_style::color_background() const {
      vx_core::Type_string output = this->vx_p_color_background;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // color_hoverbkgrd()
    vx_core::Type_string Class_style::color_hoverbkgrd() const {
      vx_core::Type_string output = this->vx_p_color_hoverbkgrd;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // cursor()
    vx_ui_ui::Type_cursor Class_style::cursor() const {
      vx_ui_ui::Type_cursor output = this->vx_p_cursor;
      if (!output) {
        output = vx_ui_ui::e_cursor;
      }
      return output;
    }

    // image_background()
    vx_data_file::Type_file Class_style::image_background() const {
      vx_data_file::Type_file output = this->vx_p_image_background;
      if (!output) {
        output = vx_data_file::e_file;
      }
      return output;
    }

    // layout()
    vx_ui_ui::Type_layout Class_style::layout() const {
      vx_ui_ui::Type_layout output = this->vx_p_layout;
      if (!output) {
        output = vx_ui_ui::e_layout;
      }
      return output;
    }

    // type()
    vx_ui_ui::Type_styletype Class_style::type() const {
      vx_ui_ui::Type_styletype output = this->vx_p_type;
      if (!output) {
        output = vx_ui_ui::e_styletype;
      }
      return output;
    }

    // pin()
    vx_ui_ui::Type_pin Class_style::pin() const {
      vx_ui_ui::Type_pin output = this->vx_p_pin;
      if (!output) {
        output = vx_ui_ui::e_pin;
      }
      return output;
    }

    // pointpos()
    vx_ui_ui::Type_point Class_style::pointpos() const {
      vx_ui_ui::Type_point output = this->vx_p_pointpos;
      if (!output) {
        output = vx_ui_ui::e_point;
      }
      return output;
    }

    // pointsize()
    vx_ui_ui::Type_point Class_style::pointsize() const {
      vx_ui_ui::Type_point output = this->vx_p_pointsize;
      if (!output) {
        output = vx_ui_ui::e_point;
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
      } else if (skey == ":boundsmargin") {
        output = this->boundsmargin();
      } else if (skey == ":boundspadding") {
        output = this->boundspadding();
      } else if (skey == ":color-background") {
        output = this->color_background();
      } else if (skey == ":color-hoverbkgrd") {
        output = this->color_hoverbkgrd();
      } else if (skey == ":cursor") {
        output = this->cursor();
      } else if (skey == ":image-background") {
        output = this->image_background();
      } else if (skey == ":layout") {
        output = this->layout();
      } else if (skey == ":type") {
        output = this->type();
      } else if (skey == ":pin") {
        output = this->pin();
      } else if (skey == ":pointpos") {
        output = this->pointpos();
      } else if (skey == ":pointsize") {
        output = this->pointsize();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_style::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":name"] = this->name();
      output[":boundsmargin"] = this->boundsmargin();
      output[":boundspadding"] = this->boundspadding();
      output[":color-background"] = this->color_background();
      output[":color-hoverbkgrd"] = this->color_hoverbkgrd();
      output[":cursor"] = this->cursor();
      output[":image-background"] = this->image_background();
      output[":layout"] = this->layout();
      output[":type"] = this->type();
      output[":pin"] = this->pin();
      output[":pointpos"] = this->pointpos();
      output[":pointsize"] = this->pointsize();
      return output;
    }

    vx_core::Type_any Class_style::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_style, vals);
    }

    vx_core::Type_any Class_style::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_style output = vx_ui_ui::e_style;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_style val = vx_core::vx_any_from_any(vx_ui_ui::t_style, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_name = val->name();
      vx_ui_ui::Type_bounds vx_p_boundsmargin = val->boundsmargin();
      vx_ui_ui::Type_bounds vx_p_boundspadding = val->boundspadding();
      vx_core::Type_string vx_p_color_background = val->color_background();
      vx_core::Type_string vx_p_color_hoverbkgrd = val->color_hoverbkgrd();
      vx_ui_ui::Type_cursor vx_p_cursor = val->cursor();
      vx_data_file::Type_file vx_p_image_background = val->image_background();
      vx_ui_ui::Type_layout vx_p_layout = val->layout();
      vx_ui_ui::Type_styletype vx_p_type = val->type();
      vx_ui_ui::Type_pin vx_p_pin = val->pin();
      vx_ui_ui::Type_point vx_p_pointpos = val->pointpos();
      vx_ui_ui::Type_point vx_p_pointsize = val->pointsize();
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
          } else if (testkey == ":boundsmargin") {
            key = testkey;
          } else if (testkey == ":boundspadding") {
            key = testkey;
          } else if (testkey == ":color-background") {
            key = testkey;
          } else if (testkey == ":color-hoverbkgrd") {
            key = testkey;
          } else if (testkey == ":cursor") {
            key = testkey;
          } else if (testkey == ":image-background") {
            key = testkey;
          } else if (testkey == ":layout") {
            key = testkey;
          } else if (testkey == ":type") {
            key = testkey;
          } else if (testkey == ":pin") {
            key = testkey;
          } else if (testkey == ":pointpos") {
            key = testkey;
          } else if (testkey == ":pointsize") {
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
          } else if (key == ":boundsmargin") {
            if (vx_p_boundsmargin == valsub) {
            } else if (valsubtype == vx_ui_ui::t_bounds) {
              ischanged = true;
              vx_p_boundsmargin = vx_core::vx_any_from_any(vx_ui_ui::t_bounds, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new style :boundsmargin " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":boundspadding") {
            if (vx_p_boundspadding == valsub) {
            } else if (valsubtype == vx_ui_ui::t_bounds) {
              ischanged = true;
              vx_p_boundspadding = vx_core::vx_any_from_any(vx_ui_ui::t_bounds, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new style :boundspadding " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":color-background") {
            if (vx_p_color_background == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_color_background = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new style :color-background " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":color-hoverbkgrd") {
            if (vx_p_color_hoverbkgrd == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_color_hoverbkgrd = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new style :color-hoverbkgrd " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":cursor") {
            if (vx_p_cursor == valsub) {
            } else if (valsubtype == vx_ui_ui::t_cursor) {
              ischanged = true;
              vx_p_cursor = vx_core::vx_any_from_any(vx_ui_ui::t_cursor, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new style :cursor " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":image-background") {
            if (vx_p_image_background == valsub) {
            } else if (valsubtype == vx_data_file::t_file) {
              ischanged = true;
              vx_p_image_background = vx_core::vx_any_from_any(vx_data_file::t_file, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new style :image-background " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":layout") {
            if (vx_p_layout == valsub) {
            } else if (valsubtype == vx_ui_ui::t_layout) {
              ischanged = true;
              vx_p_layout = vx_core::vx_any_from_any(vx_ui_ui::t_layout, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new style :layout " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":type") {
            if (vx_p_type == valsub) {
            } else if (valsubtype == vx_ui_ui::t_styletype) {
              ischanged = true;
              vx_p_type = vx_core::vx_any_from_any(vx_ui_ui::t_styletype, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new style :type " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":pin") {
            if (vx_p_pin == valsub) {
            } else if (valsubtype == vx_ui_ui::t_pin) {
              ischanged = true;
              vx_p_pin = vx_core::vx_any_from_any(vx_ui_ui::t_pin, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new style :pin " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":pointpos") {
            if (vx_p_pointpos == valsub) {
            } else if (valsubtype == vx_ui_ui::t_point) {
              ischanged = true;
              vx_p_pointpos = vx_core::vx_any_from_any(vx_ui_ui::t_point, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new style :pointpos " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":pointsize") {
            if (vx_p_pointsize == valsub) {
            } else if (valsubtype == vx_ui_ui::t_point) {
              ischanged = true;
              vx_p_pointsize = vx_core::vx_any_from_any(vx_ui_ui::t_point, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new style :pointsize " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
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
        output = new vx_ui_ui::Class_style();
        if (output->vx_p_name != vx_p_name) {
          if (output->vx_p_name) {
            vx_core::vx_release_one(output->vx_p_name);
          }
          output->vx_p_name = vx_p_name;
          vx_core::vx_reserve(vx_p_name);
        }
        if (output->vx_p_boundsmargin != vx_p_boundsmargin) {
          if (output->vx_p_boundsmargin) {
            vx_core::vx_release_one(output->vx_p_boundsmargin);
          }
          output->vx_p_boundsmargin = vx_p_boundsmargin;
          vx_core::vx_reserve(vx_p_boundsmargin);
        }
        if (output->vx_p_boundspadding != vx_p_boundspadding) {
          if (output->vx_p_boundspadding) {
            vx_core::vx_release_one(output->vx_p_boundspadding);
          }
          output->vx_p_boundspadding = vx_p_boundspadding;
          vx_core::vx_reserve(vx_p_boundspadding);
        }
        if (output->vx_p_color_background != vx_p_color_background) {
          if (output->vx_p_color_background) {
            vx_core::vx_release_one(output->vx_p_color_background);
          }
          output->vx_p_color_background = vx_p_color_background;
          vx_core::vx_reserve(vx_p_color_background);
        }
        if (output->vx_p_color_hoverbkgrd != vx_p_color_hoverbkgrd) {
          if (output->vx_p_color_hoverbkgrd) {
            vx_core::vx_release_one(output->vx_p_color_hoverbkgrd);
          }
          output->vx_p_color_hoverbkgrd = vx_p_color_hoverbkgrd;
          vx_core::vx_reserve(vx_p_color_hoverbkgrd);
        }
        if (output->vx_p_cursor != vx_p_cursor) {
          if (output->vx_p_cursor) {
            vx_core::vx_release_one(output->vx_p_cursor);
          }
          output->vx_p_cursor = vx_p_cursor;
          vx_core::vx_reserve(vx_p_cursor);
        }
        if (output->vx_p_image_background != vx_p_image_background) {
          if (output->vx_p_image_background) {
            vx_core::vx_release_one(output->vx_p_image_background);
          }
          output->vx_p_image_background = vx_p_image_background;
          vx_core::vx_reserve(vx_p_image_background);
        }
        if (output->vx_p_layout != vx_p_layout) {
          if (output->vx_p_layout) {
            vx_core::vx_release_one(output->vx_p_layout);
          }
          output->vx_p_layout = vx_p_layout;
          vx_core::vx_reserve(vx_p_layout);
        }
        if (output->vx_p_type != vx_p_type) {
          if (output->vx_p_type) {
            vx_core::vx_release_one(output->vx_p_type);
          }
          output->vx_p_type = vx_p_type;
          vx_core::vx_reserve(vx_p_type);
        }
        if (output->vx_p_pin != vx_p_pin) {
          if (output->vx_p_pin) {
            vx_core::vx_release_one(output->vx_p_pin);
          }
          output->vx_p_pin = vx_p_pin;
          vx_core::vx_reserve(vx_p_pin);
        }
        if (output->vx_p_pointpos != vx_p_pointpos) {
          if (output->vx_p_pointpos) {
            vx_core::vx_release_one(output->vx_p_pointpos);
          }
          output->vx_p_pointpos = vx_p_pointpos;
          vx_core::vx_reserve(vx_p_pointpos);
        }
        if (output->vx_p_pointsize != vx_p_pointsize) {
          if (output->vx_p_pointsize) {
            vx_core::vx_release_one(output->vx_p_pointsize);
          }
          output->vx_p_pointsize = vx_p_pointsize;
          vx_core::vx_reserve(vx_p_pointsize);
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
    vx_core::vx_Type_listany vx_ui_ui::Class_style::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_style::vx_empty() const {return vx_ui_ui::e_style;}
    vx_core::Type_any Class_style::vx_type() const {return vx_ui_ui::t_style;}

    vx_core::Type_typedef Class_style::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
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
            "boundsmargin", // name
            vx_ui_ui::t_bounds // type
          ),
          vx_core::vx_new_arg(
            "boundspadding", // name
            vx_ui_ui::t_bounds // type
          ),
          vx_core::vx_new_arg(
            "color-background", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "color-hoverbkgrd", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "cursor", // name
            vx_ui_ui::t_cursor // type
          ),
          vx_core::vx_new_arg(
            "image-background", // name
            vx_data_file::t_file // type
          ),
          vx_core::vx_new_arg(
            "layout", // name
            vx_ui_ui::t_layout // type
          ),
          vx_core::vx_new_arg(
            "type", // name
            vx_ui_ui::t_styletype // type
          ),
          vx_core::vx_new_arg(
            "pin", // name
            vx_ui_ui::t_pin // type
          ),
          vx_core::vx_new_arg(
            "pointpos", // name
            vx_ui_ui::t_point // type
          ),
          vx_core::vx_new_arg(
            "pointsize", // name
            vx_ui_ui::t_point // type
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

    vx_ui_ui::Type_style Class_stylelist::vx_get_style(vx_core::Type_int index) const {
      vx_ui_ui::Type_style output = vx_ui_ui::e_style;
      long iindex = index->vx_int();
      std::vector<vx_ui_ui::Type_style> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_ui_ui::Type_style> Class_stylelist::vx_liststyle() const {return vx_p_list;}

    vx_core::Type_any vx_ui_ui::Class_stylelist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_style(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_stylelist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_ui_ui::Type_stylelist output = vx_ui_ui::e_stylelist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_ui_ui::Type_style> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_ui_ui::t_style) {
          vx_ui_ui::Type_style castval = vx_core::vx_any_from_any(vx_ui_ui::t_style, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_ui_ui::t_style)) {
          vx_ui_ui::Type_style castval = vx_core::vx_any_from_any(vx_ui_ui::t_style, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(stylelist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_stylelist();
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
      return this->vx_copy(vx_ui_ui::e_stylelist, vals);
    }

    vx_core::Type_any Class_stylelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_stylelist output = vx_ui_ui::e_stylelist;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_stylelist val = vx_core::vx_any_from_any(vx_ui_ui::t_stylelist, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_ui_ui::Type_style> listval = val->vx_liststyle();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_ui_ui::t_style) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_ui_ui::t_style, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_ui_ui::t_style)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_ui_ui::t_style, valsub));
        } else if (valsubtype == vx_ui_ui::t_stylelist) {
          ischanged = true;
          vx_ui_ui::Type_stylelist multi = vx_core::vx_any_from_any(vx_ui_ui::t_stylelist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_liststyle());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new stylelist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_stylelist();
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
    vx_core::vx_Type_listany vx_ui_ui::Class_stylelist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_stylelist::vx_empty() const {return vx_ui_ui::e_stylelist;}
    vx_core::Type_any Class_stylelist::vx_type() const {return vx_ui_ui::t_stylelist;}

    vx_core::Type_typedef Class_stylelist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "stylelist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_ui_ui::t_style}), // allowtypes
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
    vx_ui_ui::Type_style Class_stylemap::vx_get_style(vx_core::Type_string key) const {
      vx_ui_ui::Type_style output = vx_ui_ui::e_style;
      const vx_ui_ui::Class_stylemap* map = this;
      std::string skey = key->vx_string();
      if (vx_core::vx_boolean_from_string_starts(skey, ":")) {
        skey = vx_core::vx_string_from_string_start(skey, 2);
      }
      std::map<std::string, vx_ui_ui::Type_style> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_ui_ui::e_style);
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_stylemap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_style(key);
    }

    // vx_mapstyle()
    std::map<std::string, vx_ui_ui::Type_style> Class_stylemap::vx_mapstyle() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_stylemap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_ui_ui::Type_stylemap output = vx_ui_ui::e_stylemap;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_ui_ui::Type_style> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_ui_ui::t_style) {
          vx_ui_ui::Type_style castval = vx_core::vx_any_from_any(vx_ui_ui::t_style, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(stylemap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((map.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_stylemap();
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
      return this->vx_copy(vx_ui_ui::e_stylemap, vals);
    }

    vx_core::Type_any Class_stylemap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_stylemap output = vx_ui_ui::e_stylemap;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_stylemap valmap = vx_core::vx_any_from_any(vx_ui_ui::t_stylemap, copyval);
      output = valmap;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_ui_ui::Type_style> mapval = valmap->vx_mapstyle();
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
          vx_ui_ui::Type_style valany = NULL;
          if (valsubtype == vx_ui_ui::t_style) {
            valany = vx_core::vx_any_from_any(vx_ui_ui::t_style, valsub);
          } else if (valsubtype == vx_ui_ui::t_style) {
            valany = vx_core::vx_any_from_any(vx_ui_ui::t_style, valsub);
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
        output = new vx_ui_ui::Class_stylemap();
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
    vx_core::vx_Type_listany vx_ui_ui::Class_stylemap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_stylemap::vx_empty() const {return vx_ui_ui::e_stylemap;}
    vx_core::Type_any Class_stylemap::vx_type() const {return vx_ui_ui::t_stylemap;}

    vx_core::Type_typedef Class_stylemap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "stylemap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_ui_ui::t_style}), // allowtypes
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
        this->vx_p_stylemap
      });
    }

    // stylemap()
    vx_ui_ui::Type_stylemap Class_stylesheet::stylemap() const {
      vx_ui_ui::Type_stylemap output = this->vx_p_stylemap;
      if (!output) {
        output = vx_ui_ui::e_stylemap;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_stylesheet::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":stylemap") {
        output = this->stylemap();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_stylesheet::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":stylemap"] = this->stylemap();
      return output;
    }

    vx_core::Type_any Class_stylesheet::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_stylesheet, vals);
    }

    vx_core::Type_any Class_stylesheet::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_stylesheet output = vx_ui_ui::e_stylesheet;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_stylesheet val = vx_core::vx_any_from_any(vx_ui_ui::t_stylesheet, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_ui_ui::Type_stylemap vx_p_stylemap = val->stylemap();
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
          } else if (testkey == ":stylemap") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new stylesheet) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":stylemap") {
            if (vx_p_stylemap == valsub) {
            } else if (valsubtype == vx_ui_ui::t_stylemap) {
              ischanged = true;
              vx_p_stylemap = vx_core::vx_any_from_any(vx_ui_ui::t_stylemap, valsub);
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
        output = new vx_ui_ui::Class_stylesheet();
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
    vx_core::vx_Type_listany vx_ui_ui::Class_stylesheet::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_stylesheet::vx_empty() const {return vx_ui_ui::e_stylesheet;}
    vx_core::Type_any Class_stylesheet::vx_type() const {return vx_ui_ui::t_stylesheet;}

    vx_core::Type_typedef Class_stylesheet::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "stylesheet", // name
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
            "stylemap", // name
            vx_ui_ui::t_stylemap // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_stylesheet::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type styletype)
  // class Class_styletype {
    Abstract_styletype::~Abstract_styletype() {}

    Class_styletype::Class_styletype() : Abstract_styletype::Abstract_styletype() {
      vx_core::refcount += 1;
    }

    Class_styletype::~Class_styletype() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        
      });
    }

    // vx_get_any(key)
    vx_core::Type_any Class_styletype::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_styletype::vx_map() const {
      vx_core::vx_Type_mapany output;
      return output;
    }

    vx_core::Type_any Class_styletype::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_styletype, vals);
    }

    vx_core::Type_any Class_styletype::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_styletype output = vx_ui_ui::e_styletype;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_styletype val = vx_core::vx_any_from_any(vx_ui_ui::t_styletype, copyval);
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

    vx_core::Type_msgblock Class_styletype::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_styletype::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_styletype::vx_empty() const {return vx_ui_ui::e_styletype;}
    vx_core::Type_any Class_styletype::vx_type() const {return vx_ui_ui::t_styletype;}

    vx_core::Type_typedef Class_styletype::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "styletype", // name
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

    vx_core::Type_constdef Class_styletype::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type ui)
  // class Class_ui {
    Abstract_ui::~Abstract_ui() {}

    Class_ui::Class_ui() : Abstract_ui::Abstract_ui() {
      vx_core::refcount += 1;
    }

    Class_ui::~Class_ui() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_data,
        this->vx_p_eventmap,
        this->vx_p_fn_uimap_data,
        this->vx_p_parent,
        this->vx_p_path,
        this->vx_p_render,
        this->vx_p_renderer,
        this->vx_p_style,
        this->vx_p_stylelist,
        this->vx_p_stylesheet,
        this->vx_p_uid,
        this->vx_p_uimap
      });
    }

    // data()
    vx_core::Type_any Class_ui::data() const {
      vx_core::Type_any output = this->vx_p_data;
      if (!output) {
        output = vx_core::e_any;
      }
      return output;
    }

    // eventmap()
    vx_event::Type_eventmap Class_ui::eventmap() const {
      vx_event::Type_eventmap output = this->vx_p_eventmap;
      if (!output) {
        output = vx_event::e_eventmap;
      }
      return output;
    }

    // fn_uimap_data()
    vx_ui_ui::Func_uimap_from_uimap_data Class_ui::fn_uimap_data() const {
      vx_ui_ui::Func_uimap_from_uimap_data output = this->vx_p_fn_uimap_data;
      if (!output) {
        output = vx_ui_ui::e_uimap_from_uimap_data;
      }
      return output;
    }

    // parent()
    vx_core::Type_string Class_ui::parent() const {
      vx_core::Type_string output = this->vx_p_parent;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // path()
    vx_core::Type_string Class_ui::path() const {
      vx_core::Type_string output = this->vx_p_path;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // render()
    vx_ui_ui::Type_render Class_ui::render() const {
      vx_ui_ui::Type_render output = this->vx_p_render;
      if (!output) {
        output = vx_ui_ui::e_render;
      }
      return output;
    }

    // renderer()
    vx_ui_ui::Type_layout Class_ui::renderer() const {
      vx_ui_ui::Type_layout output = this->vx_p_renderer;
      if (!output) {
        output = vx_ui_ui::e_layout;
      }
      return output;
    }

    // style()
    vx_ui_ui::Type_style Class_ui::style() const {
      vx_ui_ui::Type_style output = this->vx_p_style;
      if (!output) {
        output = vx_ui_ui::e_style;
      }
      return output;
    }

    // stylelist()
    vx_ui_ui::Type_stylelist Class_ui::stylelist() const {
      vx_ui_ui::Type_stylelist output = this->vx_p_stylelist;
      if (!output) {
        output = vx_ui_ui::e_stylelist;
      }
      return output;
    }

    // stylesheet()
    vx_ui_ui::Type_stylesheet Class_ui::stylesheet() const {
      vx_ui_ui::Type_stylesheet output = this->vx_p_stylesheet;
      if (!output) {
        output = vx_ui_ui::e_stylesheet;
      }
      return output;
    }

    // uid()
    vx_core::Type_string Class_ui::uid() const {
      vx_core::Type_string output = this->vx_p_uid;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // uimap()
    vx_ui_ui::Type_uimap Class_ui::uimap() const {
      vx_ui_ui::Type_uimap output = this->vx_p_uimap;
      if (!output) {
        output = vx_ui_ui::e_uimap;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_ui::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":data") {
        output = this->data();
      } else if (skey == ":eventmap") {
        output = this->eventmap();
      } else if (skey == ":fn-uimap-data") {
        output = this->fn_uimap_data();
      } else if (skey == ":parent") {
        output = this->parent();
      } else if (skey == ":path") {
        output = this->path();
      } else if (skey == ":render") {
        output = this->render();
      } else if (skey == ":renderer") {
        output = this->renderer();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":stylelist") {
        output = this->stylelist();
      } else if (skey == ":stylesheet") {
        output = this->stylesheet();
      } else if (skey == ":uid") {
        output = this->uid();
      } else if (skey == ":uimap") {
        output = this->uimap();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_ui::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":data"] = this->data();
      output[":eventmap"] = this->eventmap();
      output[":fn-uimap-data"] = this->fn_uimap_data();
      output[":parent"] = this->parent();
      output[":path"] = this->path();
      output[":render"] = this->render();
      output[":renderer"] = this->renderer();
      output[":style"] = this->style();
      output[":stylelist"] = this->stylelist();
      output[":stylesheet"] = this->stylesheet();
      output[":uid"] = this->uid();
      output[":uimap"] = this->uimap();
      return output;
    }

    vx_core::Type_any Class_ui::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_ui, vals);
    }

    vx_core::Type_any Class_ui::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_ui val = vx_core::vx_any_from_any(vx_ui_ui::t_ui, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_any vx_p_data = val->data();
      vx_event::Type_eventmap vx_p_eventmap = val->eventmap();
      vx_ui_ui::Func_uimap_from_uimap_data vx_p_fn_uimap_data = val->fn_uimap_data();
      vx_core::Type_string vx_p_parent = val->parent();
      vx_core::Type_string vx_p_path = val->path();
      vx_ui_ui::Type_render vx_p_render = val->render();
      vx_ui_ui::Type_layout vx_p_renderer = val->renderer();
      vx_ui_ui::Type_style vx_p_style = val->style();
      vx_ui_ui::Type_stylelist vx_p_stylelist = val->stylelist();
      vx_ui_ui::Type_stylesheet vx_p_stylesheet = val->stylesheet();
      vx_core::Type_string vx_p_uid = val->uid();
      vx_ui_ui::Type_uimap vx_p_uimap = val->uimap();
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
          } else if (testkey == ":data") {
            key = testkey;
          } else if (testkey == ":eventmap") {
            key = testkey;
          } else if (testkey == ":fn-uimap-data") {
            key = testkey;
          } else if (testkey == ":parent") {
            key = testkey;
          } else if (testkey == ":path") {
            key = testkey;
          } else if (testkey == ":render") {
            key = testkey;
          } else if (testkey == ":renderer") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":stylelist") {
            key = testkey;
          } else if (testkey == ":stylesheet") {
            key = testkey;
          } else if (testkey == ":uid") {
            key = testkey;
          } else if (testkey == ":uimap") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new ui) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":data") {
            if (vx_p_data != valsub) {
              ischanged = true;
              vx_p_data = valsub;
            }
          } else if (key == ":eventmap") {
            if (vx_p_eventmap == valsub) {
            } else if (valsubtype == vx_event::t_eventmap) {
              ischanged = true;
              vx_p_eventmap = vx_core::vx_any_from_any(vx_event::t_eventmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new ui :eventmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":fn-uimap-data") {
            if (vx_p_fn_uimap_data == valsub) {
            } else if (valsubtype == vx_ui_ui::t_uimap_from_uimap_data) {
              ischanged = true;
              vx_p_fn_uimap_data = vx_core::vx_any_from_any(vx_ui_ui::t_uimap_from_uimap_data, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new ui :fn-uimap-data " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":parent") {
            if (vx_p_parent == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_parent = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new ui :parent " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":path") {
            if (vx_p_path == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_path = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new ui :path " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":render") {
            if (vx_p_render == valsub) {
            } else if (valsubtype == vx_ui_ui::t_render) {
              ischanged = true;
              vx_p_render = vx_core::vx_any_from_any(vx_ui_ui::t_render, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new ui :render " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":renderer") {
            if (vx_p_renderer == valsub) {
            } else if (valsubtype == vx_ui_ui::t_layout) {
              ischanged = true;
              vx_p_renderer = vx_core::vx_any_from_any(vx_ui_ui::t_layout, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new ui :renderer " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":style") {
            if (vx_p_style == valsub) {
            } else if (valsubtype == vx_ui_ui::t_style) {
              ischanged = true;
              vx_p_style = vx_core::vx_any_from_any(vx_ui_ui::t_style, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new ui :style " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":stylelist") {
            if (vx_p_stylelist == valsub) {
            } else if (valsubtype == vx_ui_ui::t_stylelist) {
              ischanged = true;
              vx_p_stylelist = vx_core::vx_any_from_any(vx_ui_ui::t_stylelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new ui :stylelist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":stylesheet") {
            if (vx_p_stylesheet == valsub) {
            } else if (valsubtype == vx_ui_ui::t_stylesheet) {
              ischanged = true;
              vx_p_stylesheet = vx_core::vx_any_from_any(vx_ui_ui::t_stylesheet, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new ui :stylesheet " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":uid") {
            if (vx_p_uid == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_uid = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new ui :uid " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":uimap") {
            if (vx_p_uimap == valsub) {
            } else if (valsubtype == vx_ui_ui::t_uimap) {
              ischanged = true;
              vx_p_uimap = vx_core::vx_any_from_any(vx_ui_ui::t_uimap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new ui :uimap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new ui) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_ui();
        if (output->vx_p_data != vx_p_data) {
          if (output->vx_p_data) {
            vx_core::vx_release_one(output->vx_p_data);
          }
          output->vx_p_data = vx_p_data;
          vx_core::vx_reserve(vx_p_data);
        }
        if (output->vx_p_eventmap != vx_p_eventmap) {
          if (output->vx_p_eventmap) {
            vx_core::vx_release_one(output->vx_p_eventmap);
          }
          output->vx_p_eventmap = vx_p_eventmap;
          vx_core::vx_reserve(vx_p_eventmap);
        }
        if (output->vx_p_fn_uimap_data != vx_p_fn_uimap_data) {
          if (output->vx_p_fn_uimap_data) {
            vx_core::vx_release_one(output->vx_p_fn_uimap_data);
          }
          output->vx_p_fn_uimap_data = vx_p_fn_uimap_data;
          vx_core::vx_reserve(vx_p_fn_uimap_data);
        }
        if (output->vx_p_parent != vx_p_parent) {
          if (output->vx_p_parent) {
            vx_core::vx_release_one(output->vx_p_parent);
          }
          output->vx_p_parent = vx_p_parent;
          vx_core::vx_reserve(vx_p_parent);
        }
        if (output->vx_p_path != vx_p_path) {
          if (output->vx_p_path) {
            vx_core::vx_release_one(output->vx_p_path);
          }
          output->vx_p_path = vx_p_path;
          vx_core::vx_reserve(vx_p_path);
        }
        if (output->vx_p_render != vx_p_render) {
          if (output->vx_p_render) {
            vx_core::vx_release_one(output->vx_p_render);
          }
          output->vx_p_render = vx_p_render;
          vx_core::vx_reserve(vx_p_render);
        }
        if (output->vx_p_renderer != vx_p_renderer) {
          if (output->vx_p_renderer) {
            vx_core::vx_release_one(output->vx_p_renderer);
          }
          output->vx_p_renderer = vx_p_renderer;
          vx_core::vx_reserve(vx_p_renderer);
        }
        if (output->vx_p_style != vx_p_style) {
          if (output->vx_p_style) {
            vx_core::vx_release_one(output->vx_p_style);
          }
          output->vx_p_style = vx_p_style;
          vx_core::vx_reserve(vx_p_style);
        }
        if (output->vx_p_stylelist != vx_p_stylelist) {
          if (output->vx_p_stylelist) {
            vx_core::vx_release_one(output->vx_p_stylelist);
          }
          output->vx_p_stylelist = vx_p_stylelist;
          vx_core::vx_reserve(vx_p_stylelist);
        }
        if (output->vx_p_stylesheet != vx_p_stylesheet) {
          if (output->vx_p_stylesheet) {
            vx_core::vx_release_one(output->vx_p_stylesheet);
          }
          output->vx_p_stylesheet = vx_p_stylesheet;
          vx_core::vx_reserve(vx_p_stylesheet);
        }
        if (output->vx_p_uid != vx_p_uid) {
          if (output->vx_p_uid) {
            vx_core::vx_release_one(output->vx_p_uid);
          }
          output->vx_p_uid = vx_p_uid;
          vx_core::vx_reserve(vx_p_uid);
        }
        if (output->vx_p_uimap != vx_p_uimap) {
          if (output->vx_p_uimap) {
            vx_core::vx_release_one(output->vx_p_uimap);
          }
          output->vx_p_uimap = vx_p_uimap;
          vx_core::vx_reserve(vx_p_uimap);
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

    vx_core::Type_msgblock Class_ui::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_ui::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_ui::vx_empty() const {return vx_ui_ui::e_ui;}
    vx_core::Type_any Class_ui::vx_type() const {return vx_ui_ui::t_ui;}

    vx_core::Type_typedef Class_ui::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "ui", // name
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
            "data", // name
            vx_core::t_any // type
          ),
          vx_core::vx_new_arg(
            "eventmap", // name
            vx_event::t_eventmap // type
          ),
          vx_core::vx_new_arg(
            "fn-uimap-data", // name
            vx_ui_ui::t_uimap_from_uimap_data // type
          ),
          vx_core::vx_new_arg(
            "parent", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "path", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "render", // name
            vx_ui_ui::t_render // type
          ),
          vx_core::vx_new_arg(
            "renderer", // name
            vx_ui_ui::t_layout // type
          ),
          vx_core::vx_new_arg(
            "style", // name
            vx_ui_ui::t_style // type
          ),
          vx_core::vx_new_arg(
            "stylelist", // name
            vx_ui_ui::t_stylelist // type
          ),
          vx_core::vx_new_arg(
            "stylesheet", // name
            vx_ui_ui::t_stylesheet // type
          ),
          vx_core::vx_new_arg(
            "uid", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "uimap", // name
            vx_ui_ui::t_uimap // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_ui::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type uiengine)
  // class Class_uiengine {
    Abstract_uiengine::~Abstract_uiengine() {}

    Class_uiengine::Class_uiengine() : Abstract_uiengine::Abstract_uiengine() {
      vx_core::refcount += 1;
    }

    Class_uiengine::~Class_uiengine() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_parentmap,
        this->vx_p_layoutengine,
        this->vx_p_stylesheet,
        this->vx_p_ui
      });
    }

    // parentmap()
    vx_ui_ui::Type_uimap Class_uiengine::parentmap() const {
      vx_ui_ui::Type_uimap output = this->vx_p_parentmap;
      if (!output) {
        output = vx_ui_ui::e_uimap;
      }
      return output;
    }

    // layoutengine()
    vx_ui_ui::Type_layoutengine Class_uiengine::layoutengine() const {
      vx_ui_ui::Type_layoutengine output = this->vx_p_layoutengine;
      if (!output) {
        output = vx_ui_ui::e_layoutengine;
      }
      return output;
    }

    // stylesheet()
    vx_ui_ui::Type_stylesheet Class_uiengine::stylesheet() const {
      vx_ui_ui::Type_stylesheet output = this->vx_p_stylesheet;
      if (!output) {
        output = vx_ui_ui::e_stylesheet;
      }
      return output;
    }

    // ui()
    vx_ui_ui::Type_ui Class_uiengine::ui() const {
      vx_ui_ui::Type_ui output = this->vx_p_ui;
      if (!output) {
        output = vx_ui_ui::e_ui;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_uiengine::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":parentmap") {
        output = this->parentmap();
      } else if (skey == ":layoutengine") {
        output = this->layoutengine();
      } else if (skey == ":stylesheet") {
        output = this->stylesheet();
      } else if (skey == ":ui") {
        output = this->ui();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_uiengine::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":parentmap"] = this->parentmap();
      output[":layoutengine"] = this->layoutengine();
      output[":stylesheet"] = this->stylesheet();
      output[":ui"] = this->ui();
      return output;
    }

    vx_core::Type_any Class_uiengine::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_uiengine, vals);
    }

    vx_core::Type_any Class_uiengine::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_uiengine output = vx_ui_ui::e_uiengine;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_uiengine val = vx_core::vx_any_from_any(vx_ui_ui::t_uiengine, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_ui_ui::Type_uimap vx_p_parentmap = val->parentmap();
      vx_ui_ui::Type_layoutengine vx_p_layoutengine = val->layoutengine();
      vx_ui_ui::Type_stylesheet vx_p_stylesheet = val->stylesheet();
      vx_ui_ui::Type_ui vx_p_ui = val->ui();
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
          } else if (testkey == ":parentmap") {
            key = testkey;
          } else if (testkey == ":layoutengine") {
            key = testkey;
          } else if (testkey == ":stylesheet") {
            key = testkey;
          } else if (testkey == ":ui") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new uiengine) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":parentmap") {
            if (vx_p_parentmap == valsub) {
            } else if (valsubtype == vx_ui_ui::t_uimap) {
              ischanged = true;
              vx_p_parentmap = vx_core::vx_any_from_any(vx_ui_ui::t_uimap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new uiengine :parentmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":layoutengine") {
            if (vx_p_layoutengine == valsub) {
            } else if (valsubtype == vx_ui_ui::t_layoutengine) {
              ischanged = true;
              vx_p_layoutengine = vx_core::vx_any_from_any(vx_ui_ui::t_layoutengine, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new uiengine :layoutengine " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":stylesheet") {
            if (vx_p_stylesheet == valsub) {
            } else if (valsubtype == vx_ui_ui::t_stylesheet) {
              ischanged = true;
              vx_p_stylesheet = vx_core::vx_any_from_any(vx_ui_ui::t_stylesheet, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new uiengine :stylesheet " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":ui") {
            if (vx_p_ui == valsub) {
            } else if (valsubtype == vx_ui_ui::t_ui) {
              ischanged = true;
              vx_p_ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new uiengine :ui " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new uiengine) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_uiengine();
        if (output->vx_p_parentmap != vx_p_parentmap) {
          if (output->vx_p_parentmap) {
            vx_core::vx_release_one(output->vx_p_parentmap);
          }
          output->vx_p_parentmap = vx_p_parentmap;
          vx_core::vx_reserve(vx_p_parentmap);
        }
        if (output->vx_p_layoutengine != vx_p_layoutengine) {
          if (output->vx_p_layoutengine) {
            vx_core::vx_release_one(output->vx_p_layoutengine);
          }
          output->vx_p_layoutengine = vx_p_layoutengine;
          vx_core::vx_reserve(vx_p_layoutengine);
        }
        if (output->vx_p_stylesheet != vx_p_stylesheet) {
          if (output->vx_p_stylesheet) {
            vx_core::vx_release_one(output->vx_p_stylesheet);
          }
          output->vx_p_stylesheet = vx_p_stylesheet;
          vx_core::vx_reserve(vx_p_stylesheet);
        }
        if (output->vx_p_ui != vx_p_ui) {
          if (output->vx_p_ui) {
            vx_core::vx_release_one(output->vx_p_ui);
          }
          output->vx_p_ui = vx_p_ui;
          vx_core::vx_reserve(vx_p_ui);
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

    vx_core::Type_msgblock Class_uiengine::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_uiengine::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_uiengine::vx_empty() const {return vx_ui_ui::e_uiengine;}
    vx_core::Type_any Class_uiengine::vx_type() const {return vx_ui_ui::t_uiengine;}

    vx_core::Type_typedef Class_uiengine::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "uiengine", // name
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
            "parentmap", // name
            vx_ui_ui::t_uimap // type
          ),
          vx_core::vx_new_arg(
            "layoutengine", // name
            vx_ui_ui::t_layoutengine // type
          ),
          vx_core::vx_new_arg(
            "stylesheet", // name
            vx_ui_ui::t_stylesheet // type
          ),
          vx_core::vx_new_arg(
            "ui", // name
            vx_ui_ui::t_ui // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_uiengine::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type uilist)
  // class Class_uilist {
    Abstract_uilist::~Abstract_uilist() {}

    Class_uilist::Class_uilist() : Abstract_uilist::Abstract_uilist() {
      vx_core::refcount += 1;
    }

    Class_uilist::~Class_uilist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_uilist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_ui_ui::Type_ui Class_uilist::vx_get_ui(vx_core::Type_int index) const {
      vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
      long iindex = index->vx_int();
      std::vector<vx_ui_ui::Type_ui> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_ui_ui::Type_ui> Class_uilist::vx_listui() const {return vx_p_list;}

    vx_core::Type_any vx_ui_ui::Class_uilist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_ui(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_uilist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_ui_ui::Type_uilist output = vx_ui_ui::e_uilist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_ui_ui::Type_ui> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_ui_ui::t_ui) {
          vx_ui_ui::Type_ui castval = vx_core::vx_any_from_any(vx_ui_ui::t_ui, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_ui_ui::t_ui)) {
          vx_ui_ui::Type_ui castval = vx_core::vx_any_from_any(vx_ui_ui::t_ui, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(uilist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_uilist();
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

    vx_core::Type_any Class_uilist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_uilist, vals);
    }

    vx_core::Type_any Class_uilist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_uilist output = vx_ui_ui::e_uilist;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_uilist val = vx_core::vx_any_from_any(vx_ui_ui::t_uilist, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_ui_ui::Type_ui> listval = val->vx_listui();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_ui_ui::t_ui) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_ui_ui::t_ui, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_ui_ui::t_ui)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_ui_ui::t_ui, valsub));
        } else if (valsubtype == vx_ui_ui::t_uilist) {
          ischanged = true;
          vx_ui_ui::Type_uilist multi = vx_core::vx_any_from_any(vx_ui_ui::t_uilist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listui());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new uilist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_uilist();
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

    vx_core::Type_msgblock Class_uilist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_uilist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_uilist::vx_empty() const {return vx_ui_ui::e_uilist;}
    vx_core::Type_any Class_uilist::vx_type() const {return vx_ui_ui::t_uilist;}

    vx_core::Type_typedef Class_uilist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "uilist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_ui_ui::t_ui}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_uilist::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type uimap)
  // class Class_uimap {
    Abstract_uimap::~Abstract_uimap() {}

    Class_uimap::Class_uimap() : Abstract_uimap::Abstract_uimap() {
      vx_core::refcount += 1;
    }

    Class_uimap::~Class_uimap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (auto const& [key, val] : this->vx_p_map) {
        vx_core::vx_release_one(val);
      }
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_uimap::vx_map() const {
      vx_core::vx_Type_mapany output = vx_core::vx_map_from_map(vx_core::t_any, this->vx_p_map);
      return output;
    }

    // vx_get_ui(key)
    vx_ui_ui::Type_ui Class_uimap::vx_get_ui(vx_core::Type_string key) const {
      vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
      const vx_ui_ui::Class_uimap* map = this;
      std::string skey = key->vx_string();
      if (vx_core::vx_boolean_from_string_starts(skey, ":")) {
        skey = vx_core::vx_string_from_string_start(skey, 2);
      }
      std::map<std::string, vx_ui_ui::Type_ui> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_ui_ui::e_ui);
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_uimap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_ui(key);
    }

    // vx_mapui()
    std::map<std::string, vx_ui_ui::Type_ui> Class_uimap::vx_mapui() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_uimap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_ui_ui::Type_uimap output = vx_ui_ui::e_uimap;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_ui_ui::Type_ui> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_ui_ui::t_ui) {
          vx_ui_ui::Type_ui castval = vx_core::vx_any_from_any(vx_ui_ui::t_ui, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(uimap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((map.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_uimap();
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

    vx_core::Type_any Class_uimap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_uimap, vals);
    }

    vx_core::Type_any Class_uimap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_uimap output = vx_ui_ui::e_uimap;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_uimap valmap = vx_core::vx_any_from_any(vx_ui_ui::t_uimap, copyval);
      output = valmap;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_ui_ui::Type_ui> mapval = valmap->vx_mapui();
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
          vx_ui_ui::Type_ui valany = NULL;
          if (valsubtype == vx_ui_ui::t_ui) {
            valany = vx_core::vx_any_from_any(vx_ui_ui::t_ui, valsub);
          } else if (valsubtype == vx_ui_ui::t_ui) {
            valany = vx_core::vx_any_from_any(vx_ui_ui::t_ui, valsub);
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
        output = new vx_ui_ui::Class_uimap();
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

    vx_core::Type_msgblock Class_uimap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_uimap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_uimap::vx_empty() const {return vx_ui_ui::e_uimap;}
    vx_core::Type_any Class_uimap::vx_type() const {return vx_ui_ui::t_uimap;}

    vx_core::Type_typedef Class_uimap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "uimap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_ui_ui::t_ui}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_uimap::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (const layout-app)
  // class Class_layout_app {
    // vx_const_new()
    void vx_ui_ui::Class_layout_app::vx_const_new(vx_ui_ui::Const_layout_app output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-app");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-app")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layout-background)
  // class Class_layout_background {
    // vx_const_new()
    void vx_ui_ui::Class_layout_background::vx_const_new(vx_ui_ui::Const_layout_background output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-background");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-background")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layout-combobox)
  // class Class_layout_combobox {
    // vx_const_new()
    void vx_ui_ui::Class_layout_combobox::vx_const_new(vx_ui_ui::Const_layout_combobox output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-combobox");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-combobox")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layout-else)
  // class Class_layout_else {
    // vx_const_new()
    void vx_ui_ui::Class_layout_else::vx_const_new(vx_ui_ui::Const_layout_else output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-else");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-else")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layout-flow-columns)
  // class Class_layout_flow_columns {
    // vx_const_new()
    void vx_ui_ui::Class_layout_flow_columns::vx_const_new(vx_ui_ui::Const_layout_flow_columns output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-flow-columns");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-flow-columns")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layout-flow-rows)
  // class Class_layout_flow_rows {
    // vx_const_new()
    void vx_ui_ui::Class_layout_flow_rows::vx_const_new(vx_ui_ui::Const_layout_flow_rows output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-flow-rows");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-flow-rows")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layout-image)
  // class Class_layout_image {
    // vx_const_new()
    void vx_ui_ui::Class_layout_image::vx_const_new(vx_ui_ui::Const_layout_image output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-image");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-image")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layout-label)
  // class Class_layout_label {
    // vx_const_new()
    void vx_ui_ui::Class_layout_label::vx_const_new(vx_ui_ui::Const_layout_label output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-label");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-label")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layout-main)
  // class Class_layout_main {
    // vx_const_new()
    void vx_ui_ui::Class_layout_main::vx_const_new(vx_ui_ui::Const_layout_main output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-main");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-main")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layout-maxpanel)
  // class Class_layout_maxpanel {
    // vx_const_new()
    void vx_ui_ui::Class_layout_maxpanel::vx_const_new(vx_ui_ui::Const_layout_maxpanel output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-maxpanel");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-maxpanel")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layout-menubar)
  // class Class_layout_menubar {
    // vx_const_new()
    void vx_ui_ui::Class_layout_menubar::vx_const_new(vx_ui_ui::Const_layout_menubar output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-menubar");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-menubar")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layout-menudrawer)
  // class Class_layout_menudrawer {
    // vx_const_new()
    void vx_ui_ui::Class_layout_menudrawer::vx_const_new(vx_ui_ui::Const_layout_menudrawer output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-menudrawer");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-menudrawer")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layout-msgbox)
  // class Class_layout_msgbox {
    // vx_const_new()
    void vx_ui_ui::Class_layout_msgbox::vx_const_new(vx_ui_ui::Const_layout_msgbox output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-msgbox");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-msgbox")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layout-navbar)
  // class Class_layout_navbar {
    // vx_const_new()
    void vx_ui_ui::Class_layout_navbar::vx_const_new(vx_ui_ui::Const_layout_navbar output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-navbar");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-navbar")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layout-navdrawer)
  // class Class_layout_navdrawer {
    // vx_const_new()
    void vx_ui_ui::Class_layout_navdrawer::vx_const_new(vx_ui_ui::Const_layout_navdrawer output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-navdrawer");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-navdrawer")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layout-panel)
  // class Class_layout_panel {
    // vx_const_new()
    void vx_ui_ui::Class_layout_panel::vx_const_new(vx_ui_ui::Const_layout_panel output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-panel");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-panel")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layout-parallax)
  // class Class_layout_parallax {
    // vx_const_new()
    void vx_ui_ui::Class_layout_parallax::vx_const_new(vx_ui_ui::Const_layout_parallax output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-parallax");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-parallax")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layout-statusbar)
  // class Class_layout_statusbar {
    // vx_const_new()
    void vx_ui_ui::Class_layout_statusbar::vx_const_new(vx_ui_ui::Const_layout_statusbar output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-statusbar");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-statusbar")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layout-statusdrawer)
  // class Class_layout_statusdrawer {
    // vx_const_new()
    void vx_ui_ui::Class_layout_statusdrawer::vx_const_new(vx_ui_ui::Const_layout_statusdrawer output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-statusdrawer");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-statusdrawer")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layout-text)
  // class Class_layout_text {
    // vx_const_new()
    void vx_ui_ui::Class_layout_text::vx_const_new(vx_ui_ui::Const_layout_text output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-text");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-text")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const layout-textentry)
  // class Class_layout_textentry {
    // vx_const_new()
    void vx_ui_ui::Class_layout_textentry::vx_const_new(vx_ui_ui::Const_layout_textentry output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-textentry");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-textentry")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_fn_layout = val->fn_layout();
      vx_core::vx_reserve(output->vx_p_fn_layout);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const pin-bottom)
  // class Class_pin_bottom {
    // vx_const_new()
    void vx_ui_ui::Class_pin_bottom::vx_const_new(vx_ui_ui::Const_pin_bottom output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "pin-bottom");
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const pin-center)
  // class Class_pin_center {
    // vx_const_new()
    void vx_ui_ui::Class_pin_center::vx_const_new(vx_ui_ui::Const_pin_center output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "pin-center");
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const pin-center-h)
  // class Class_pin_center_h {
    // vx_const_new()
    void vx_ui_ui::Class_pin_center_h::vx_const_new(vx_ui_ui::Const_pin_center_h output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "pin-center-h");
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const pin-center-v)
  // class Class_pin_center_v {
    // vx_const_new()
    void vx_ui_ui::Class_pin_center_v::vx_const_new(vx_ui_ui::Const_pin_center_v output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "pin-center-v");
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const pin-expand)
  // class Class_pin_expand {
    // vx_const_new()
    void vx_ui_ui::Class_pin_expand::vx_const_new(vx_ui_ui::Const_pin_expand output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "pin-expand");
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const pin-left)
  // class Class_pin_left {
    // vx_const_new()
    void vx_ui_ui::Class_pin_left::vx_const_new(vx_ui_ui::Const_pin_left output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "pin-left");
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const pin-right)
  // class Class_pin_right {
    // vx_const_new()
    void vx_ui_ui::Class_pin_right::vx_const_new(vx_ui_ui::Const_pin_right output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "pin-right");
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const pin-top)
  // class Class_pin_top {
    // vx_const_new()
    void vx_ui_ui::Class_pin_top::vx_const_new(vx_ui_ui::Const_pin_top output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "pin-top");
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const styletype-custom)
  // class Class_styletype_custom {
    // vx_const_new()
    void vx_ui_ui::Class_styletype_custom::vx_const_new(vx_ui_ui::Const_styletype_custom output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "styletype-custom");
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const styletype-shared)
  // class Class_styletype_shared {
    // vx_const_new()
    void vx_ui_ui::Class_styletype_shared::vx_const_new(vx_ui_ui::Const_styletype_shared output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "styletype-shared");
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const styletype-system)
  // class Class_styletype_system {
    // vx_const_new()
    void vx_ui_ui::Class_styletype_system::vx_const_new(vx_ui_ui::Const_styletype_system output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "styletype-system");
      vx_core::vx_reserve_type(output);
    }


  //}

  // (func boolean-writestate<-ui)
  vx_core::Type_boolean f_boolean_writestate_from_ui(vx_core::Type_context context, vx_ui_ui::Type_ui ui) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve(ui);
    output = vx_core::f_let(
      vx_core::t_boolean,
      vx_core::t_any_from_func->vx_fn_new({ui, context}, [ui, context]() {
        vx_core::Type_string uid = ui->uid();
        vx_core::vx_ref_plus(uid);
        vx_core::Type_boolean output_1 = vx_state::f_boolean_writestate_from_mapname_name_value(
          context,
          vx_core::vx_new_string(":uimap"),
          uid,
          vx_core::t_value
        );
        vx_core::vx_release_one_except(uid, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(ui, output);
    return output;
  }

  // (func boolean-writestate<-ui)
  // class Class_boolean_writestate_from_ui {
    Abstract_boolean_writestate_from_ui::~Abstract_boolean_writestate_from_ui() {}

    Class_boolean_writestate_from_ui::Class_boolean_writestate_from_ui() : Abstract_boolean_writestate_from_ui::Abstract_boolean_writestate_from_ui() {
      vx_core::refcount += 1;
    }

    Class_boolean_writestate_from_ui::~Class_boolean_writestate_from_ui() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_boolean_writestate_from_ui::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_boolean_writestate_from_ui output = vx_ui_ui::e_boolean_writestate_from_ui;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_boolean_writestate_from_ui::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_boolean_writestate_from_ui output = vx_ui_ui::e_boolean_writestate_from_ui;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_boolean_writestate_from_ui::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "boolean-writestate<-ui", // name
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

    vx_core::Type_constdef Class_boolean_writestate_from_ui::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_boolean_writestate_from_ui::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-writestate<-ui", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_boolean_writestate_from_ui::vx_empty() const {return vx_ui_ui::e_boolean_writestate_from_ui;}
    vx_core::Type_any Class_boolean_writestate_from_ui::vx_type() const {return vx_ui_ui::t_boolean_writestate_from_ui;}
    vx_core::Type_msgblock Class_boolean_writestate_from_ui::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_writestate_from_ui::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_boolean_writestate_from_ui::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_boolean_writestate_from_ui::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui inputval = vx_core::vx_any_from_any(vx_ui_ui::t_ui, val);
      output = vx_ui_ui::f_boolean_writestate_from_ui(context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_boolean_writestate_from_ui::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_boolean_writestate_from_ui(context, ui);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func boolean-writestate<-uiengine)
  vx_core::Type_boolean f_boolean_writestate_from_uiengine(vx_core::Type_context context, vx_ui_ui::Type_uiengine uiengine) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve(uiengine);
    output = vx_state::f_boolean_writestate_from_name_value(context, vx_core::vx_new_string(":uiengine"), uiengine);
    vx_core::vx_release_one_except(uiengine, output);
    return output;
  }

  // (func boolean-writestate<-uiengine)
  // class Class_boolean_writestate_from_uiengine {
    Abstract_boolean_writestate_from_uiengine::~Abstract_boolean_writestate_from_uiengine() {}

    Class_boolean_writestate_from_uiengine::Class_boolean_writestate_from_uiengine() : Abstract_boolean_writestate_from_uiengine::Abstract_boolean_writestate_from_uiengine() {
      vx_core::refcount += 1;
    }

    Class_boolean_writestate_from_uiengine::~Class_boolean_writestate_from_uiengine() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_boolean_writestate_from_uiengine::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_boolean_writestate_from_uiengine output = vx_ui_ui::e_boolean_writestate_from_uiengine;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_boolean_writestate_from_uiengine::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_boolean_writestate_from_uiengine output = vx_ui_ui::e_boolean_writestate_from_uiengine;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_boolean_writestate_from_uiengine::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "boolean-writestate<-uiengine", // name
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

    vx_core::Type_constdef Class_boolean_writestate_from_uiengine::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_boolean_writestate_from_uiengine::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-writestate<-uiengine", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_boolean_writestate_from_uiengine::vx_empty() const {return vx_ui_ui::e_boolean_writestate_from_uiengine;}
    vx_core::Type_any Class_boolean_writestate_from_uiengine::vx_type() const {return vx_ui_ui::t_boolean_writestate_from_uiengine;}
    vx_core::Type_msgblock Class_boolean_writestate_from_uiengine::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_writestate_from_uiengine::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_boolean_writestate_from_uiengine::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_boolean_writestate_from_uiengine::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_uiengine inputval = vx_core::vx_any_from_any(vx_ui_ui::t_uiengine, val);
      output = vx_ui_ui::f_boolean_writestate_from_uiengine(context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_boolean_writestate_from_uiengine::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_uiengine uiengine = vx_core::vx_any_from_any(vx_ui_ui::t_uiengine, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_boolean_writestate_from_uiengine(context, uiengine);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func layout<-style)
  vx_ui_ui::Type_layout f_layout_from_style(vx_ui_ui::Type_style style) {
    vx_ui_ui::Type_layout output = vx_ui_ui::e_layout;
    vx_core::vx_reserve(style);
    output = style->layout();
    vx_core::vx_release_one_except(style, output);
    return output;
  }

  // (func layout<-style)
  // class Class_layout_from_style {
    Abstract_layout_from_style::~Abstract_layout_from_style() {}

    Class_layout_from_style::Class_layout_from_style() : Abstract_layout_from_style::Abstract_layout_from_style() {
      vx_core::refcount += 1;
    }

    Class_layout_from_style::~Class_layout_from_style() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_layout_from_style::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_layout_from_style output = vx_ui_ui::e_layout_from_style;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_layout_from_style::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_layout_from_style output = vx_ui_ui::e_layout_from_style;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_layout_from_style::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "layout<-style", // name
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

    vx_core::Type_constdef Class_layout_from_style::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_layout_from_style::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "layout<-style", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_layout_from_style::vx_empty() const {return vx_ui_ui::e_layout_from_style;}
    vx_core::Type_any Class_layout_from_style::vx_type() const {return vx_ui_ui::t_layout_from_style;}
    vx_core::Type_msgblock Class_layout_from_style::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_layout_from_style::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_layout_from_style::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_layout_from_style::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_style inputval = vx_core::vx_any_from_any(vx_ui_ui::t_style, val);
      output = vx_ui_ui::f_layout_from_style(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_layout_from_style::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_style style = vx_core::vx_any_from_any(vx_ui_ui::t_style, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_layout_from_style(style);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func layoutmap<-layoutlist)
  vx_ui_ui::Type_layoutmap f_layoutmap_from_layoutlist(vx_ui_ui::Type_layoutlist layoutlist) {
    vx_ui_ui::Type_layoutmap output = vx_ui_ui::e_layoutmap;
    vx_core::vx_reserve(layoutlist);
    output = vx_core::f_map_from_list(
      vx_ui_ui::t_layoutmap,
      layoutlist,
      vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any layout_any) {
        vx_ui_ui::Type_layout layout = vx_core::vx_any_from_any(vx_ui_ui::t_layout, layout_any);
        vx_core::Type_any output_1 = 
          layout->name();
        return output_1;
      })
    );
    vx_core::vx_release_one_except(layoutlist, output);
    return output;
  }

  // (func layoutmap<-layoutlist)
  // class Class_layoutmap_from_layoutlist {
    Abstract_layoutmap_from_layoutlist::~Abstract_layoutmap_from_layoutlist() {}

    Class_layoutmap_from_layoutlist::Class_layoutmap_from_layoutlist() : Abstract_layoutmap_from_layoutlist::Abstract_layoutmap_from_layoutlist() {
      vx_core::refcount += 1;
    }

    Class_layoutmap_from_layoutlist::~Class_layoutmap_from_layoutlist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_layoutmap_from_layoutlist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_layoutmap_from_layoutlist output = vx_ui_ui::e_layoutmap_from_layoutlist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_layoutmap_from_layoutlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_layoutmap_from_layoutlist output = vx_ui_ui::e_layoutmap_from_layoutlist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_layoutmap_from_layoutlist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "layoutmap<-layoutlist", // name
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

    vx_core::Type_constdef Class_layoutmap_from_layoutlist::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_layoutmap_from_layoutlist::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "layoutmap<-layoutlist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_layoutmap_from_layoutlist::vx_empty() const {return vx_ui_ui::e_layoutmap_from_layoutlist;}
    vx_core::Type_any Class_layoutmap_from_layoutlist::vx_type() const {return vx_ui_ui::t_layoutmap_from_layoutlist;}
    vx_core::Type_msgblock Class_layoutmap_from_layoutlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_layoutmap_from_layoutlist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_layoutmap_from_layoutlist::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_layoutmap_from_layoutlist::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_layoutlist inputval = vx_core::vx_any_from_any(vx_ui_ui::t_layoutlist, val);
      output = vx_ui_ui::f_layoutmap_from_layoutlist(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_layoutmap_from_layoutlist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_layoutlist layoutlist = vx_core::vx_any_from_any(vx_ui_ui::t_layoutlist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_layoutmap_from_layoutlist(layoutlist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func stylemap<-stylelist)
  vx_ui_ui::Type_stylemap f_stylemap_from_stylelist(vx_ui_ui::Type_stylelist stylelist) {
    vx_ui_ui::Type_stylemap output = vx_ui_ui::e_stylemap;
    vx_core::vx_reserve(stylelist);
    output = vx_core::f_map_from_list(
      vx_ui_ui::t_stylemap,
      stylelist,
      vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any style_any) {
        vx_ui_ui::Type_style style = vx_core::vx_any_from_any(vx_ui_ui::t_style, style_any);
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
      vx_ui_ui::Func_stylemap_from_stylelist output = vx_ui_ui::e_stylemap_from_stylelist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_stylemap_from_stylelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_stylemap_from_stylelist output = vx_ui_ui::e_stylemap_from_stylelist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_stylemap_from_stylelist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
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
        "vx/ui/ui", // pkgname
        "stylemap<-stylelist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_stylemap_from_stylelist::vx_empty() const {return vx_ui_ui::e_stylemap_from_stylelist;}
    vx_core::Type_any Class_stylemap_from_stylelist::vx_type() const {return vx_ui_ui::t_stylemap_from_stylelist;}
    vx_core::Type_msgblock Class_stylemap_from_stylelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stylemap_from_stylelist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_stylemap_from_stylelist::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_stylemap_from_stylelist::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_stylelist inputval = vx_core::vx_any_from_any(vx_ui_ui::t_stylelist, val);
      output = vx_ui_ui::f_stylemap_from_stylelist(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_stylemap_from_stylelist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_stylelist stylelist = vx_core::vx_any_from_any(vx_ui_ui::t_stylelist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_stylemap_from_stylelist(stylelist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func stylesheet-render)
  vx_ui_ui::Type_stylesheet f_stylesheet_render(vx_ui_ui::Type_stylesheet stylesheetui) {
    vx_ui_ui::Type_stylesheet output = vx_ui_ui::e_stylesheet;
    vx_core::vx_reserve(stylesheetui);
    vx_core::vx_release_one_except(stylesheetui, output);
    return output;
  }

  // (func stylesheet-render)
  // class Class_stylesheet_render {
    Abstract_stylesheet_render::~Abstract_stylesheet_render() {}

    Class_stylesheet_render::Class_stylesheet_render() : Abstract_stylesheet_render::Abstract_stylesheet_render() {
      vx_core::refcount += 1;
    }

    Class_stylesheet_render::~Class_stylesheet_render() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_stylesheet_render::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_stylesheet_render output = vx_ui_ui::e_stylesheet_render;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_stylesheet_render::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_stylesheet_render output = vx_ui_ui::e_stylesheet_render;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_stylesheet_render::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "stylesheet-render", // name
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

    vx_core::Type_constdef Class_stylesheet_render::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_stylesheet_render::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "stylesheet-render", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_stylesheet_render::vx_empty() const {return vx_ui_ui::e_stylesheet_render;}
    vx_core::Type_any Class_stylesheet_render::vx_type() const {return vx_ui_ui::t_stylesheet_render;}
    vx_core::Type_msgblock Class_stylesheet_render::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stylesheet_render::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_stylesheet_render::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_stylesheet_render::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_stylesheet inputval = vx_core::vx_any_from_any(vx_ui_ui::t_stylesheet, val);
      output = vx_ui_ui::f_stylesheet_render(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_stylesheet_render::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_stylesheet stylesheetui = vx_core::vx_any_from_any(vx_ui_ui::t_stylesheet, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_stylesheet_render(stylesheetui);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func ui-data<-ui)
  vx_ui_ui::Type_ui f_ui_data_from_ui(vx_ui_ui::Type_ui ui) {
    vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
    vx_core::vx_reserve(ui);
    output = vx_core::f_let(
      vx_ui_ui::t_ui,
      vx_core::t_any_from_func->vx_fn_new({ui}, [ui]() {
        vx_core::Type_any data = ui->data();
        vx_core::vx_ref_plus(data);
        vx_ui_ui::Type_ui output_1 = vx_core::f_any_from_any(vx_ui_ui::t_ui, data);
        vx_core::vx_release_one_except(data, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(ui, output);
    return output;
  }

  // (func ui-data<-ui)
  // class Class_ui_data_from_ui {
    Abstract_ui_data_from_ui::~Abstract_ui_data_from_ui() {}

    Class_ui_data_from_ui::Class_ui_data_from_ui() : Abstract_ui_data_from_ui::Abstract_ui_data_from_ui() {
      vx_core::refcount += 1;
    }

    Class_ui_data_from_ui::~Class_ui_data_from_ui() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_data_from_ui::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_data_from_ui output = vx_ui_ui::e_ui_data_from_ui;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_data_from_ui::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_data_from_ui output = vx_ui_ui::e_ui_data_from_ui;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_data_from_ui::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "ui-data<-ui", // name
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

    vx_core::Type_constdef Class_ui_data_from_ui::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_data_from_ui::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-data<-ui", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_data_from_ui::vx_empty() const {return vx_ui_ui::e_ui_data_from_ui;}
    vx_core::Type_any Class_ui_data_from_ui::vx_type() const {return vx_ui_ui::t_ui_data_from_ui;}
    vx_core::Type_msgblock Class_ui_data_from_ui::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_data_from_ui::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_ui_data_from_ui::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_ui_data_from_ui::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui inputval = vx_core::vx_any_from_any(vx_ui_ui::t_ui, val);
      output = vx_ui_ui::f_ui_data_from_ui(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_ui_data_from_ui::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_ui_data_from_ui(ui);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func ui-from<-event)
  vx_ui_ui::Type_ui f_ui_from_from_event(vx_event::Type_event event) {
    vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
    vx_core::vx_reserve(event);
    output = vx_event::f_any_from_from_event(vx_ui_ui::t_ui, event);
    vx_core::vx_release_one_except(event, output);
    return output;
  }

  // (func ui-from<-event)
  // class Class_ui_from_from_event {
    Abstract_ui_from_from_event::~Abstract_ui_from_from_event() {}

    Class_ui_from_from_event::Class_ui_from_from_event() : Abstract_ui_from_from_event::Abstract_ui_from_from_event() {
      vx_core::refcount += 1;
    }

    Class_ui_from_from_event::~Class_ui_from_from_event() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_from_from_event::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_from_from_event output = vx_ui_ui::e_ui_from_from_event;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_from_from_event::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_from_from_event output = vx_ui_ui::e_ui_from_from_event;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_from_from_event::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "ui-from<-event", // name
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

    vx_core::Type_constdef Class_ui_from_from_event::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_from_from_event::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-from<-event", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_from_from_event::vx_empty() const {return vx_ui_ui::e_ui_from_from_event;}
    vx_core::Type_any Class_ui_from_from_event::vx_type() const {return vx_ui_ui::t_ui_from_from_event;}
    vx_core::Type_msgblock Class_ui_from_from_event::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_from_from_event::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_ui_from_from_event::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_ui_from_from_event::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_event::Type_event inputval = vx_core::vx_any_from_any(vx_event::t_event, val);
      output = vx_ui_ui::f_ui_from_from_event(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_ui_from_from_event::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_event::Type_event event = vx_core::vx_any_from_any(vx_event::t_event, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_ui_from_from_event(event);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func ui-layout<-ui-layoutmap-else)
  vx_ui_ui::Type_ui f_ui_layout_from_ui_layoutmap_else(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_layoutmap layoutmap, vx_ui_ui::Type_layout layoutelse) {
    vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
    vx_core::vx_reserve({ui, layoutmap, layoutelse});
    output = vx_core::f_let(
      vx_ui_ui::t_ui,
      vx_core::t_any_from_func->vx_fn_new({ui, layoutmap, layoutelse}, [ui, layoutmap, layoutelse]() {
        vx_ui_ui::Type_style style = ui->style();
        vx_core::vx_ref_plus(style);
        vx_ui_ui::Type_uimap uimap = ui->uimap();
        vx_core::vx_ref_plus(uimap);
        vx_ui_ui::Type_layout layout = vx_ui_ui::f_layout_from_style(style);
        vx_core::vx_ref_plus(layout);
        vx_core::Type_string layname = layout->name();
        vx_core::vx_ref_plus(layname);
        vx_ui_ui::Type_layout renderer1 = vx_core::f_any_from_map(vx_ui_ui::t_layout, layoutmap, layname);
        vx_core::vx_ref_plus(renderer1);
        vx_ui_ui::Type_layout renderer = vx_core::f_if_1(
          vx_ui_ui::t_layout,
          vx_core::f_notempty_1(renderer1),
          renderer1,
          layoutelse
        );
        vx_core::vx_ref_plus(renderer);
        vx_ui_ui::Type_uimap uimaprend = vx_ui_ui::f_uimap_layout_from_uimap_layoutmap_else(uimap, layoutmap, layoutelse);
        vx_core::vx_ref_plus(uimaprend);
        vx_ui_ui::Type_ui output_1 = vx_core::f_copy(
          vx_ui_ui::t_ui,
          ui,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":renderer"),
            renderer,
            vx_core::vx_new_string(":uimap"),
            uimaprend
          })
        );
        vx_core::vx_release_one_except({style, uimap, layout, layname, renderer1, renderer, uimaprend}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({ui, layoutmap, layoutelse}, output);
    return output;
  }

  // (func ui-layout<-ui-layoutmap-else)
  // class Class_ui_layout_from_ui_layoutmap_else {
    Abstract_ui_layout_from_ui_layoutmap_else::~Abstract_ui_layout_from_ui_layoutmap_else() {}

    Class_ui_layout_from_ui_layoutmap_else::Class_ui_layout_from_ui_layoutmap_else() : Abstract_ui_layout_from_ui_layoutmap_else::Abstract_ui_layout_from_ui_layoutmap_else() {
      vx_core::refcount += 1;
    }

    Class_ui_layout_from_ui_layoutmap_else::~Class_ui_layout_from_ui_layoutmap_else() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_layout_from_ui_layoutmap_else::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_layout_from_ui_layoutmap_else output = vx_ui_ui::e_ui_layout_from_ui_layoutmap_else;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_layout_from_ui_layoutmap_else::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_layout_from_ui_layoutmap_else output = vx_ui_ui::e_ui_layout_from_ui_layoutmap_else;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_layout_from_ui_layoutmap_else::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-ui-layoutmap-else", // name
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

    vx_core::Type_constdef Class_ui_layout_from_ui_layoutmap_else::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_layout_from_ui_layoutmap_else::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-ui-layoutmap-else", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_layout_from_ui_layoutmap_else::vx_empty() const {return vx_ui_ui::e_ui_layout_from_ui_layoutmap_else;}
    vx_core::Type_any Class_ui_layout_from_ui_layoutmap_else::vx_type() const {return vx_ui_ui::t_ui_layout_from_ui_layoutmap_else;}
    vx_core::Type_msgblock Class_ui_layout_from_ui_layoutmap_else::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_layout_from_ui_layoutmap_else::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_ui_layout_from_ui_layoutmap_else::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_layoutmap layoutmap = vx_core::vx_any_from_any(vx_ui_ui::t_layoutmap, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_ui_ui::Type_layout layoutelse = vx_core::vx_any_from_any(vx_ui_ui::t_layout, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_ui_ui::f_ui_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func ui-readstate<-uid)
  vx_ui_ui::Type_ui f_ui_readstate_from_uid(vx_core::Type_context context, vx_core::Type_string uid) {
    vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
    vx_core::vx_reserve(uid);
    output = vx_state::f_any_readstate_from_mapname_name(vx_ui_ui::t_ui, context, vx_core::vx_new_string(":uimap"), uid);
    vx_core::vx_release_one_except(uid, output);
    return output;
  }

  // (func ui-readstate<-uid)
  // class Class_ui_readstate_from_uid {
    Abstract_ui_readstate_from_uid::~Abstract_ui_readstate_from_uid() {}

    Class_ui_readstate_from_uid::Class_ui_readstate_from_uid() : Abstract_ui_readstate_from_uid::Abstract_ui_readstate_from_uid() {
      vx_core::refcount += 1;
    }

    Class_ui_readstate_from_uid::~Class_ui_readstate_from_uid() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_readstate_from_uid::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_readstate_from_uid output = vx_ui_ui::e_ui_readstate_from_uid;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_readstate_from_uid::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_readstate_from_uid output = vx_ui_ui::e_ui_readstate_from_uid;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_readstate_from_uid::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "ui-readstate<-uid", // name
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

    vx_core::Type_constdef Class_ui_readstate_from_uid::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_readstate_from_uid::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-readstate<-uid", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_readstate_from_uid::vx_empty() const {return vx_ui_ui::e_ui_readstate_from_uid;}
    vx_core::Type_any Class_ui_readstate_from_uid::vx_type() const {return vx_ui_ui::t_ui_readstate_from_uid;}
    vx_core::Type_msgblock Class_ui_readstate_from_uid::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_readstate_from_uid::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_ui_readstate_from_uid::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_ui_readstate_from_uid::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_ui_ui::f_ui_readstate_from_uid(context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_ui_readstate_from_uid::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string uid = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_ui_readstate_from_uid(context, uid);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func ui-render)
  vx_ui_ui::Type_ui f_ui_render(vx_ui_ui::Type_ui uiarg) {
    vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
    vx_core::vx_reserve(uiarg);
    output = vx_ui_ui::f_ui_render_from_ui_orig_parent(
      uiarg,
      vx_core::f_empty(
        vx_ui_ui::t_ui
      ),
      vx_core::f_empty(
        vx_ui_ui::t_ui
      )
    );
    vx_core::vx_release_one_except(uiarg, output);
    return output;
  }

  // (func ui-render)
  // class Class_ui_render {
    Abstract_ui_render::~Abstract_ui_render() {}

    Class_ui_render::Class_ui_render() : Abstract_ui_render::Abstract_ui_render() {
      vx_core::refcount += 1;
    }

    Class_ui_render::~Class_ui_render() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_render::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_render output = vx_ui_ui::e_ui_render;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_render::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_render output = vx_ui_ui::e_ui_render;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_render::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "ui-render", // name
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

    vx_core::Type_constdef Class_ui_render::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_render::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-render", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_render::vx_empty() const {return vx_ui_ui::e_ui_render;}
    vx_core::Type_any Class_ui_render::vx_type() const {return vx_ui_ui::t_ui_render;}
    vx_core::Type_msgblock Class_ui_render::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_render::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_ui_render::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_ui_render::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui inputval = vx_core::vx_any_from_any(vx_ui_ui::t_ui, val);
      output = vx_ui_ui::f_ui_render(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_ui_render::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui uiarg = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_ui_render(uiarg);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func ui-render<-fn-render-ui-orig-parent)
  vx_ui_ui::Type_render f_ui_render_from_fn_render_ui_orig_parent(vx_ui_ui::Func_ui_render_from_ui_orig_parent fn_render, vx_ui_ui::Type_ui ui, vx_ui_ui::Type_ui orig, vx_ui_ui::Type_ui parent) {
    vx_ui_ui::Type_render output = vx_ui_ui::e_render;
    vx_core::vx_reserve({fn_render, ui, orig, parent});
    output = vx_core::vx_any_from_func(vx_ui_ui::t_render, fn_render, {ui, orig, parent});
    vx_core::vx_release_one_except({fn_render, ui, orig, parent}, output);
    return output;
  }

  // (func ui-render<-fn-render-ui-orig-parent)
  // class Class_ui_render_from_fn_render_ui_orig_parent {
    Abstract_ui_render_from_fn_render_ui_orig_parent::~Abstract_ui_render_from_fn_render_ui_orig_parent() {}

    Class_ui_render_from_fn_render_ui_orig_parent::Class_ui_render_from_fn_render_ui_orig_parent() : Abstract_ui_render_from_fn_render_ui_orig_parent::Abstract_ui_render_from_fn_render_ui_orig_parent() {
      vx_core::refcount += 1;
    }

    Class_ui_render_from_fn_render_ui_orig_parent::~Class_ui_render_from_fn_render_ui_orig_parent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_render_from_fn_render_ui_orig_parent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_render_from_fn_render_ui_orig_parent output = vx_ui_ui::e_ui_render_from_fn_render_ui_orig_parent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_render_from_fn_render_ui_orig_parent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_render_from_fn_render_ui_orig_parent output = vx_ui_ui::e_ui_render_from_fn_render_ui_orig_parent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_render_from_fn_render_ui_orig_parent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "ui-render<-fn-render-ui-orig-parent", // name
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

    vx_core::Type_constdef Class_ui_render_from_fn_render_ui_orig_parent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_render_from_fn_render_ui_orig_parent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-render<-fn-render-ui-orig-parent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_render_from_fn_render_ui_orig_parent::vx_empty() const {return vx_ui_ui::e_ui_render_from_fn_render_ui_orig_parent;}
    vx_core::Type_any Class_ui_render_from_fn_render_ui_orig_parent::vx_type() const {return vx_ui_ui::t_ui_render_from_fn_render_ui_orig_parent;}
    vx_core::Type_msgblock Class_ui_render_from_fn_render_ui_orig_parent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_render_from_fn_render_ui_orig_parent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_ui_render_from_fn_render_ui_orig_parent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Func_ui_render_from_ui_orig_parent fn_render = vx_core::vx_any_from_any(vx_ui_ui::t_ui_render_from_ui_orig_parent, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_ui_ui::Type_ui orig = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(2)));
      vx_ui_ui::Type_ui parent = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(3)));
      output = vx_ui_ui::f_ui_render_from_fn_render_ui_orig_parent(fn_render, ui, orig, parent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func ui-render<-ui-orig-parent)
  vx_ui_ui::Type_ui f_ui_render_from_ui_orig_parent(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_ui orig, vx_ui_ui::Type_ui parent) {
    vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
    vx_core::vx_reserve({ui, orig, parent});
    output = vx_core::f_if_2(
      vx_ui_ui::t_ui,
      vx_core::vx_new(vx_core::t_thenelselist, {
        vx_core::f_then(
          vx_core::t_boolean_from_func->vx_fn_new({ui, orig}, [ui, orig]() {
            vx_core::Type_boolean output_1 = vx_core::f_eqeq(ui, orig);
            return output_1;
          }),
          vx_core::t_any_from_func->vx_fn_new({orig}, [orig]() {
            vx_core::Type_any output_1 = orig;
            return output_1;
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func->vx_fn_new({ui, orig, parent}, [ui, orig, parent]() {
            vx_ui_ui::Type_ui output_1 = vx_core::f_let(
              vx_ui_ui::t_ui,
              vx_core::t_any_from_func->vx_fn_new({ui, orig, parent}, [ui, orig, parent]() {
                vx_ui_ui::Type_uimap uimap = ui->uimap();
                vx_core::vx_ref_plus(uimap);
                vx_ui_ui::Type_layout renderer = ui->renderer();
                vx_core::vx_ref_plus(renderer);
                vx_ui_ui::Type_ui uiout = vx_ui_ui::f_ui_from_renderer_ui_orig_parent(renderer, ui, orig, parent);
                vx_core::vx_ref_plus(uiout);
                vx_ui_ui::Type_ui output_1 = uiout;
                vx_core::vx_release_one_except({uimap, renderer, uiout}, output_1);
                return output_1;
              })
            );
            return output_1;
          })
        )
      })
    );
    vx_core::vx_release_one_except({ui, orig, parent}, output);
    return output;
  }

  // (func ui-render<-ui-orig-parent)
  // class Class_ui_render_from_ui_orig_parent {
    Abstract_ui_render_from_ui_orig_parent::~Abstract_ui_render_from_ui_orig_parent() {}

    Class_ui_render_from_ui_orig_parent::Class_ui_render_from_ui_orig_parent() : Abstract_ui_render_from_ui_orig_parent::Abstract_ui_render_from_ui_orig_parent() {
      vx_core::refcount += 1;
    }

    Class_ui_render_from_ui_orig_parent::~Class_ui_render_from_ui_orig_parent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_render_from_ui_orig_parent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_render_from_ui_orig_parent output = vx_ui_ui::e_ui_render_from_ui_orig_parent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_render_from_ui_orig_parent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_render_from_ui_orig_parent output = vx_ui_ui::e_ui_render_from_ui_orig_parent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_render_from_ui_orig_parent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "ui-render<-ui-orig-parent", // name
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

    vx_core::Type_constdef Class_ui_render_from_ui_orig_parent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_render_from_ui_orig_parent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-render<-ui-orig-parent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_render_from_ui_orig_parent::vx_empty() const {return vx_ui_ui::e_ui_render_from_ui_orig_parent;}
    vx_core::Type_any Class_ui_render_from_ui_orig_parent::vx_type() const {return vx_ui_ui::t_ui_render_from_ui_orig_parent;}
    vx_core::Type_msgblock Class_ui_render_from_ui_orig_parent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_render_from_ui_orig_parent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_ui_render_from_ui_orig_parent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_ui orig = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_ui_ui::Type_ui parent = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_ui_ui::f_ui_render_from_ui_orig_parent(ui, orig, parent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func ui<-renderer-ui-orig-parent)
  vx_ui_ui::Type_ui f_ui_from_renderer_ui_orig_parent(vx_ui_ui::Type_layout renderer, vx_ui_ui::Type_ui uiarg, vx_ui_ui::Type_ui uiorig, vx_ui_ui::Type_ui parent) {
    vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
    vx_core::vx_reserve({renderer, uiarg, uiorig, parent});
    output = vx_core::f_let(
      vx_ui_ui::t_ui,
      vx_core::t_any_from_func->vx_fn_new({renderer, uiarg, uiorig, parent}, [renderer, uiarg, uiorig, parent]() {
        vx_ui_ui::Func_ui_render_from_ui_orig_parent fn_layout = renderer->fn_layout();
        vx_core::vx_ref_plus(fn_layout);
        vx_ui_ui::Type_ui uichg = vx_core::vx_any_from_func(vx_ui_ui::t_ui, fn_layout, {uiarg, uiorig, parent});
        vx_core::vx_ref_plus(uichg);
        vx_ui_ui::Type_ui output_1 = uichg;
        vx_core::vx_release_one_except({fn_layout, uichg}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({renderer, uiarg, uiorig, parent}, output);
    return output;
  }

  // (func ui<-renderer-ui-orig-parent)
  // class Class_ui_from_renderer_ui_orig_parent {
    Abstract_ui_from_renderer_ui_orig_parent::~Abstract_ui_from_renderer_ui_orig_parent() {}

    Class_ui_from_renderer_ui_orig_parent::Class_ui_from_renderer_ui_orig_parent() : Abstract_ui_from_renderer_ui_orig_parent::Abstract_ui_from_renderer_ui_orig_parent() {
      vx_core::refcount += 1;
    }

    Class_ui_from_renderer_ui_orig_parent::~Class_ui_from_renderer_ui_orig_parent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_from_renderer_ui_orig_parent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_from_renderer_ui_orig_parent output = vx_ui_ui::e_ui_from_renderer_ui_orig_parent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_from_renderer_ui_orig_parent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_from_renderer_ui_orig_parent output = vx_ui_ui::e_ui_from_renderer_ui_orig_parent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_from_renderer_ui_orig_parent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "ui<-renderer-ui-orig-parent", // name
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

    vx_core::Type_constdef Class_ui_from_renderer_ui_orig_parent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_from_renderer_ui_orig_parent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "ui<-renderer-ui-orig-parent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_from_renderer_ui_orig_parent::vx_empty() const {return vx_ui_ui::e_ui_from_renderer_ui_orig_parent;}
    vx_core::Type_any Class_ui_from_renderer_ui_orig_parent::vx_type() const {return vx_ui_ui::t_ui_from_renderer_ui_orig_parent;}
    vx_core::Type_msgblock Class_ui_from_renderer_ui_orig_parent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_from_renderer_ui_orig_parent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_ui_from_renderer_ui_orig_parent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_layout renderer = vx_core::vx_any_from_any(vx_ui_ui::t_layout, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_ui uiarg = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_ui_ui::Type_ui uiorig = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(2)));
      vx_ui_ui::Type_ui parent = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(3)));
      output = vx_ui_ui::f_ui_from_renderer_ui_orig_parent(renderer, uiarg, uiorig, parent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func uiengine-readstate)
  vx_ui_ui::Type_uiengine f_uiengine_readstate(vx_core::Type_context context) {
    vx_ui_ui::Type_uiengine output = vx_ui_ui::e_uiengine;
    output = vx_state::f_any_readstate_from_name(vx_ui_ui::t_uiengine, context, vx_core::vx_new_string(":uiengine"));
    return output;
  }

  // (func uiengine-readstate)
  // class Class_uiengine_readstate {
    Abstract_uiengine_readstate::~Abstract_uiengine_readstate() {}

    Class_uiengine_readstate::Class_uiengine_readstate() : Abstract_uiengine_readstate::Abstract_uiengine_readstate() {
      vx_core::refcount += 1;
    }

    Class_uiengine_readstate::~Class_uiengine_readstate() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_uiengine_readstate::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_uiengine_readstate output = vx_ui_ui::e_uiengine_readstate;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_uiengine_readstate::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_uiengine_readstate output = vx_ui_ui::e_uiengine_readstate;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_uiengine_readstate::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "uiengine-readstate", // name
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

    vx_core::Type_constdef Class_uiengine_readstate::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_uiengine_readstate::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "uiengine-readstate", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_uiengine_readstate::vx_empty() const {return vx_ui_ui::e_uiengine_readstate;}
    vx_core::Type_any Class_uiengine_readstate::vx_type() const {return vx_ui_ui::t_uiengine_readstate;}
    vx_core::Type_msgblock Class_uiengine_readstate::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_uiengine_readstate::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_uiengine_readstate::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_uiengine_readstate(context);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func uiengine-render)
  vx_ui_ui::Type_uiengine f_uiengine_render(vx_core::Type_context context, vx_ui_ui::Type_uiengine uiengine) {
    vx_ui_ui::Type_uiengine output = vx_ui_ui::e_uiengine;
    vx_core::vx_reserve(uiengine);
    output = vx_core::f_let(
      vx_ui_ui::t_uiengine,
      vx_core::t_any_from_func->vx_fn_new({uiengine}, [uiengine]() {
        vx_ui_ui::Type_stylesheet stylesheet = uiengine->stylesheet();
        vx_core::vx_ref_plus(stylesheet);
        vx_ui_ui::Type_ui ui = uiengine->ui();
        vx_core::vx_ref_plus(ui);
        vx_ui_ui::Type_layoutengine layoutengine = uiengine->layoutengine();
        vx_core::vx_ref_plus(layoutengine);
        vx_ui_ui::Type_layoutmap layoutmap = layoutengine->layoutmap();
        vx_core::vx_ref_plus(layoutmap);
        vx_ui_ui::Type_layout layoutelse = layoutengine->layoutelse();
        vx_core::vx_ref_plus(layoutelse);
        vx_ui_ui::Func_stylesheet_render stylesheetrender = layoutengine->stylesheetrender();
        vx_core::vx_ref_plus(stylesheetrender);
        vx_ui_ui::Type_stylesheet stylesheetrend = vx_core::vx_any_from_func(vx_ui_ui::t_stylesheet, stylesheetrender, {stylesheet});
        vx_core::vx_ref_plus(stylesheetrend);
        vx_ui_ui::Type_ui uirenderer = vx_ui_ui::f_ui_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
        vx_core::vx_ref_plus(uirenderer);
        vx_ui_ui::Type_ui uirendered = vx_ui_ui::f_ui_render(uirenderer);
        vx_core::vx_ref_plus(uirendered);
        vx_ui_ui::Type_uiengine output_1 = vx_core::f_copy(
          vx_ui_ui::t_uiengine,
          uiengine,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":ui"),
            uirendered
          })
        );
        vx_core::vx_release_one_except({stylesheet, ui, layoutengine, layoutmap, layoutelse, stylesheetrender, stylesheetrend, uirenderer, uirendered}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(uiengine, output);
    return output;
  }

  // (func uiengine-render)
  // class Class_uiengine_render {
    Abstract_uiengine_render::~Abstract_uiengine_render() {}

    Class_uiengine_render::Class_uiengine_render() : Abstract_uiengine_render::Abstract_uiengine_render() {
      vx_core::refcount += 1;
    }

    Class_uiengine_render::~Class_uiengine_render() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_uiengine_render::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_uiengine_render output = vx_ui_ui::e_uiengine_render;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_uiengine_render::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_uiengine_render output = vx_ui_ui::e_uiengine_render;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_uiengine_render::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "uiengine-render", // name
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

    vx_core::Type_constdef Class_uiengine_render::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_uiengine_render::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "uiengine-render", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_uiengine_render::vx_empty() const {return vx_ui_ui::e_uiengine_render;}
    vx_core::Type_any Class_uiengine_render::vx_type() const {return vx_ui_ui::t_uiengine_render;}
    vx_core::Type_msgblock Class_uiengine_render::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_uiengine_render::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_uiengine_render::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_uiengine_render::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_uiengine inputval = vx_core::vx_any_from_any(vx_ui_ui::t_uiengine, val);
      output = vx_ui_ui::f_uiengine_render(context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_uiengine_render::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_uiengine uiengine = vx_core::vx_any_from_any(vx_ui_ui::t_uiengine, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_uiengine_render(context, uiengine);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func uimap-layout<-uimap-layoutmap-else)
  vx_ui_ui::Type_uimap f_uimap_layout_from_uimap_layoutmap_else(vx_ui_ui::Type_uimap uimap, vx_ui_ui::Type_layoutmap layoutmap, vx_ui_ui::Type_layout layoutelse) {
    vx_ui_ui::Type_uimap output = vx_ui_ui::e_uimap;
    vx_core::vx_reserve({uimap, layoutmap, layoutelse});
    output = vx_core::f_map_from_map(
      vx_ui_ui::t_uimap,
      uimap,
      vx_core::t_any_from_key_value->vx_fn_new({layoutmap, layoutelse}, [layoutmap, layoutelse](vx_core::Type_any key_any, vx_core::Type_any ui_any) {
        vx_core::Type_string key = vx_core::vx_any_from_any(vx_core::t_string, key_any);
        vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, ui_any);
        vx_core::Type_any output_1 = 
          vx_ui_ui::f_ui_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({uimap, layoutmap, layoutelse}, output);
    return output;
  }

  // (func uimap-layout<-uimap-layoutmap-else)
  // class Class_uimap_layout_from_uimap_layoutmap_else {
    Abstract_uimap_layout_from_uimap_layoutmap_else::~Abstract_uimap_layout_from_uimap_layoutmap_else() {}

    Class_uimap_layout_from_uimap_layoutmap_else::Class_uimap_layout_from_uimap_layoutmap_else() : Abstract_uimap_layout_from_uimap_layoutmap_else::Abstract_uimap_layout_from_uimap_layoutmap_else() {
      vx_core::refcount += 1;
    }

    Class_uimap_layout_from_uimap_layoutmap_else::~Class_uimap_layout_from_uimap_layoutmap_else() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_uimap_layout_from_uimap_layoutmap_else::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_uimap_layout_from_uimap_layoutmap_else output = vx_ui_ui::e_uimap_layout_from_uimap_layoutmap_else;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_uimap_layout_from_uimap_layoutmap_else::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_uimap_layout_from_uimap_layoutmap_else output = vx_ui_ui::e_uimap_layout_from_uimap_layoutmap_else;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_uimap_layout_from_uimap_layoutmap_else::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "uimap-layout<-uimap-layoutmap-else", // name
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

    vx_core::Type_constdef Class_uimap_layout_from_uimap_layoutmap_else::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_uimap_layout_from_uimap_layoutmap_else::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "uimap-layout<-uimap-layoutmap-else", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_uimap_layout_from_uimap_layoutmap_else::vx_empty() const {return vx_ui_ui::e_uimap_layout_from_uimap_layoutmap_else;}
    vx_core::Type_any Class_uimap_layout_from_uimap_layoutmap_else::vx_type() const {return vx_ui_ui::t_uimap_layout_from_uimap_layoutmap_else;}
    vx_core::Type_msgblock Class_uimap_layout_from_uimap_layoutmap_else::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_uimap_layout_from_uimap_layoutmap_else::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_uimap_layout_from_uimap_layoutmap_else::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_uimap uimap = vx_core::vx_any_from_any(vx_ui_ui::t_uimap, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_layoutmap layoutmap = vx_core::vx_any_from_any(vx_ui_ui::t_layoutmap, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_ui_ui::Type_layout layoutelse = vx_core::vx_any_from_any(vx_ui_ui::t_layout, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_ui_ui::f_uimap_layout_from_uimap_layoutmap_else(uimap, layoutmap, layoutelse);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func uimap-render<-uimap-parent)
  vx_ui_ui::Type_uimap f_uimap_render_from_uimap_parent(vx_ui_ui::Type_uimap uimap, vx_ui_ui::Type_ui parent) {
    vx_ui_ui::Type_uimap output = vx_ui_ui::e_uimap;
    vx_core::vx_reserve({uimap, parent});
    output = vx_core::f_map_from_map(
      vx_ui_ui::t_uimap,
      uimap,
      vx_core::t_any_from_key_value->vx_fn_new({parent}, [parent](vx_core::Type_any key_any, vx_core::Type_any val_any) {
        vx_core::Type_string key = vx_core::vx_any_from_any(vx_core::t_string, key_any);
        vx_ui_ui::Type_ui val = vx_core::vx_any_from_any(vx_ui_ui::t_ui, val_any);
        vx_core::Type_any output_1 = 
          vx_ui_ui::f_ui_render_from_ui_orig_parent(
            val,
            vx_core::f_empty(
              vx_ui_ui::t_ui
            ),
            parent
          );
        return output_1;
      })
    );
    vx_core::vx_release_one_except({uimap, parent}, output);
    return output;
  }

  // (func uimap-render<-uimap-parent)
  // class Class_uimap_render_from_uimap_parent {
    Abstract_uimap_render_from_uimap_parent::~Abstract_uimap_render_from_uimap_parent() {}

    Class_uimap_render_from_uimap_parent::Class_uimap_render_from_uimap_parent() : Abstract_uimap_render_from_uimap_parent::Abstract_uimap_render_from_uimap_parent() {
      vx_core::refcount += 1;
    }

    Class_uimap_render_from_uimap_parent::~Class_uimap_render_from_uimap_parent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_uimap_render_from_uimap_parent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_uimap_render_from_uimap_parent output = vx_ui_ui::e_uimap_render_from_uimap_parent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_uimap_render_from_uimap_parent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_uimap_render_from_uimap_parent output = vx_ui_ui::e_uimap_render_from_uimap_parent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_uimap_render_from_uimap_parent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "uimap-render<-uimap-parent", // name
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

    vx_core::Type_constdef Class_uimap_render_from_uimap_parent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_uimap_render_from_uimap_parent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "uimap-render<-uimap-parent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_uimap_render_from_uimap_parent::vx_empty() const {return vx_ui_ui::e_uimap_render_from_uimap_parent;}
    vx_core::Type_any Class_uimap_render_from_uimap_parent::vx_type() const {return vx_ui_ui::t_uimap_render_from_uimap_parent;}
    vx_core::Type_msgblock Class_uimap_render_from_uimap_parent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_uimap_render_from_uimap_parent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_uimap_render_from_uimap_parent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_uimap uimap = vx_core::vx_any_from_any(vx_ui_ui::t_uimap, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_ui parent = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_ui_ui::f_uimap_render_from_uimap_parent(uimap, parent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func uimap<-uilist)
  vx_ui_ui::Type_uimap f_uimap_from_uilist(vx_ui_ui::Type_uilist uilist) {
    vx_ui_ui::Type_uimap output = vx_ui_ui::e_uimap;
    vx_core::vx_reserve(uilist);
    output = vx_core::f_map_from_list(
      vx_ui_ui::t_uimap,
      uilist,
      vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any ui_any) {
        vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, ui_any);
        vx_core::Type_any output_1 = 
          ui->uid();
        return output_1;
      })
    );
    vx_core::vx_release_one_except(uilist, output);
    return output;
  }

  // (func uimap<-uilist)
  // class Class_uimap_from_uilist {
    Abstract_uimap_from_uilist::~Abstract_uimap_from_uilist() {}

    Class_uimap_from_uilist::Class_uimap_from_uilist() : Abstract_uimap_from_uilist::Abstract_uimap_from_uilist() {
      vx_core::refcount += 1;
    }

    Class_uimap_from_uilist::~Class_uimap_from_uilist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_uimap_from_uilist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_uimap_from_uilist output = vx_ui_ui::e_uimap_from_uilist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_uimap_from_uilist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_uimap_from_uilist output = vx_ui_ui::e_uimap_from_uilist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_uimap_from_uilist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "uimap<-uilist", // name
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

    vx_core::Type_constdef Class_uimap_from_uilist::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_uimap_from_uilist::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "uimap<-uilist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_uimap_from_uilist::vx_empty() const {return vx_ui_ui::e_uimap_from_uilist;}
    vx_core::Type_any Class_uimap_from_uilist::vx_type() const {return vx_ui_ui::t_uimap_from_uilist;}
    vx_core::Type_msgblock Class_uimap_from_uilist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_uimap_from_uilist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_uimap_from_uilist::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_uimap_from_uilist::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_uilist inputval = vx_core::vx_any_from_any(vx_ui_ui::t_uilist, val);
      output = vx_ui_ui::f_uimap_from_uilist(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_uimap_from_uilist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_uilist uilist = vx_core::vx_any_from_any(vx_ui_ui::t_uilist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_uimap_from_uilist(uilist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func uimap<-uimap-data)
  vx_ui_ui::Type_uimap f_uimap_from_uimap_data(vx_ui_ui::Type_uimap uimap, vx_core::Type_any data) {
    vx_ui_ui::Type_uimap output = vx_ui_ui::e_uimap;
    vx_core::vx_reserve({uimap, data});
    vx_core::vx_release_one_except({uimap, data}, output);
    return output;
  }

  // (func uimap<-uimap-data)
  // class Class_uimap_from_uimap_data {
    Abstract_uimap_from_uimap_data::~Abstract_uimap_from_uimap_data() {}

    Class_uimap_from_uimap_data::Class_uimap_from_uimap_data() : Abstract_uimap_from_uimap_data::Abstract_uimap_from_uimap_data() {
      vx_core::refcount += 1;
    }

    Class_uimap_from_uimap_data::~Class_uimap_from_uimap_data() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_uimap_from_uimap_data::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_uimap_from_uimap_data output = vx_ui_ui::e_uimap_from_uimap_data;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_uimap_from_uimap_data::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_uimap_from_uimap_data output = vx_ui_ui::e_uimap_from_uimap_data;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_uimap_from_uimap_data::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "uimap<-uimap-data", // name
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

    vx_core::Type_constdef Class_uimap_from_uimap_data::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_uimap_from_uimap_data::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "uimap<-uimap-data", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_uimap_from_uimap_data::vx_empty() const {return vx_ui_ui::e_uimap_from_uimap_data;}
    vx_core::Type_any Class_uimap_from_uimap_data::vx_type() const {return vx_ui_ui::t_uimap_from_uimap_data;}
    vx_core::Type_msgblock Class_uimap_from_uimap_data::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_uimap_from_uimap_data::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_uimap_from_uimap_data::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_uimap uimap = vx_core::vx_any_from_any(vx_ui_ui::t_uimap, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any data = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_ui_ui::f_uimap_from_uimap_data(uimap, data);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_ui_ui::Type_bounds e_bounds = NULL;
  vx_ui_ui::Type_bounds t_bounds = NULL;
  vx_ui_ui::Type_cursor e_cursor = NULL;
  vx_ui_ui::Type_cursor t_cursor = NULL;
  vx_ui_ui::Type_cursor_pointer e_cursor_pointer = NULL;
  vx_ui_ui::Type_cursor_pointer t_cursor_pointer = NULL;
  vx_ui_ui::Type_layout e_layout = NULL;
  vx_ui_ui::Type_layout t_layout = NULL;
  vx_ui_ui::Type_layoutengine e_layoutengine = NULL;
  vx_ui_ui::Type_layoutengine t_layoutengine = NULL;
  vx_ui_ui::Type_layoutlist e_layoutlist = NULL;
  vx_ui_ui::Type_layoutlist t_layoutlist = NULL;
  vx_ui_ui::Type_layoutmap e_layoutmap = NULL;
  vx_ui_ui::Type_layoutmap t_layoutmap = NULL;
  vx_ui_ui::Type_pin e_pin = NULL;
  vx_ui_ui::Type_pin t_pin = NULL;
  vx_ui_ui::Type_point e_point = NULL;
  vx_ui_ui::Type_point t_point = NULL;
  vx_ui_ui::Type_pointstyle e_pointstyle = NULL;
  vx_ui_ui::Type_pointstyle t_pointstyle = NULL;
  vx_ui_ui::Type_render e_render = NULL;
  vx_ui_ui::Type_render t_render = NULL;
  vx_ui_ui::Type_rendermap e_rendermap = NULL;
  vx_ui_ui::Type_rendermap t_rendermap = NULL;
  vx_ui_ui::Type_style e_style = NULL;
  vx_ui_ui::Type_style t_style = NULL;
  vx_ui_ui::Type_stylelist e_stylelist = NULL;
  vx_ui_ui::Type_stylelist t_stylelist = NULL;
  vx_ui_ui::Type_stylemap e_stylemap = NULL;
  vx_ui_ui::Type_stylemap t_stylemap = NULL;
  vx_ui_ui::Type_stylesheet e_stylesheet = NULL;
  vx_ui_ui::Type_stylesheet t_stylesheet = NULL;
  vx_ui_ui::Type_styletype e_styletype = NULL;
  vx_ui_ui::Type_styletype t_styletype = NULL;
  vx_ui_ui::Type_ui e_ui = NULL;
  vx_ui_ui::Type_ui t_ui = NULL;
  vx_ui_ui::Type_uiengine e_uiengine = NULL;
  vx_ui_ui::Type_uiengine t_uiengine = NULL;
  vx_ui_ui::Type_uilist e_uilist = NULL;
  vx_ui_ui::Type_uilist t_uilist = NULL;
  vx_ui_ui::Type_uimap e_uimap = NULL;
  vx_ui_ui::Type_uimap t_uimap = NULL;
  vx_ui_ui::Const_layout_app c_layout_app = NULL;
  vx_ui_ui::Const_layout_background c_layout_background = NULL;
  vx_ui_ui::Const_layout_combobox c_layout_combobox = NULL;
  vx_ui_ui::Const_layout_else c_layout_else = NULL;
  vx_ui_ui::Const_layout_flow_columns c_layout_flow_columns = NULL;
  vx_ui_ui::Const_layout_flow_rows c_layout_flow_rows = NULL;
  vx_ui_ui::Const_layout_image c_layout_image = NULL;
  vx_ui_ui::Const_layout_label c_layout_label = NULL;
  vx_ui_ui::Const_layout_main c_layout_main = NULL;
  vx_ui_ui::Const_layout_maxpanel c_layout_maxpanel = NULL;
  vx_ui_ui::Const_layout_menubar c_layout_menubar = NULL;
  vx_ui_ui::Const_layout_menudrawer c_layout_menudrawer = NULL;
  vx_ui_ui::Const_layout_msgbox c_layout_msgbox = NULL;
  vx_ui_ui::Const_layout_navbar c_layout_navbar = NULL;
  vx_ui_ui::Const_layout_navdrawer c_layout_navdrawer = NULL;
  vx_ui_ui::Const_layout_panel c_layout_panel = NULL;
  vx_ui_ui::Const_layout_parallax c_layout_parallax = NULL;
  vx_ui_ui::Const_layout_statusbar c_layout_statusbar = NULL;
  vx_ui_ui::Const_layout_statusdrawer c_layout_statusdrawer = NULL;
  vx_ui_ui::Const_layout_text c_layout_text = NULL;
  vx_ui_ui::Const_layout_textentry c_layout_textentry = NULL;
  vx_ui_ui::Const_pin_bottom c_pin_bottom = NULL;
  vx_ui_ui::Const_pin_center c_pin_center = NULL;
  vx_ui_ui::Const_pin_center_h c_pin_center_h = NULL;
  vx_ui_ui::Const_pin_center_v c_pin_center_v = NULL;
  vx_ui_ui::Const_pin_expand c_pin_expand = NULL;
  vx_ui_ui::Const_pin_left c_pin_left = NULL;
  vx_ui_ui::Const_pin_right c_pin_right = NULL;
  vx_ui_ui::Const_pin_top c_pin_top = NULL;
  vx_ui_ui::Const_styletype_custom c_styletype_custom = NULL;
  vx_ui_ui::Const_styletype_shared c_styletype_shared = NULL;
  vx_ui_ui::Const_styletype_system c_styletype_system = NULL;
  vx_ui_ui::Func_boolean_writestate_from_ui e_boolean_writestate_from_ui = NULL;
  vx_ui_ui::Func_boolean_writestate_from_ui t_boolean_writestate_from_ui = NULL;
  vx_ui_ui::Func_boolean_writestate_from_uiengine e_boolean_writestate_from_uiengine = NULL;
  vx_ui_ui::Func_boolean_writestate_from_uiengine t_boolean_writestate_from_uiengine = NULL;
  vx_ui_ui::Func_layout_from_style e_layout_from_style = NULL;
  vx_ui_ui::Func_layout_from_style t_layout_from_style = NULL;
  vx_ui_ui::Func_layoutmap_from_layoutlist e_layoutmap_from_layoutlist = NULL;
  vx_ui_ui::Func_layoutmap_from_layoutlist t_layoutmap_from_layoutlist = NULL;
  vx_ui_ui::Func_stylemap_from_stylelist e_stylemap_from_stylelist = NULL;
  vx_ui_ui::Func_stylemap_from_stylelist t_stylemap_from_stylelist = NULL;
  vx_ui_ui::Func_stylesheet_render e_stylesheet_render = NULL;
  vx_ui_ui::Func_stylesheet_render t_stylesheet_render = NULL;
  vx_ui_ui::Func_ui_data_from_ui e_ui_data_from_ui = NULL;
  vx_ui_ui::Func_ui_data_from_ui t_ui_data_from_ui = NULL;
  vx_ui_ui::Func_ui_from_from_event e_ui_from_from_event = NULL;
  vx_ui_ui::Func_ui_from_from_event t_ui_from_from_event = NULL;
  vx_ui_ui::Func_ui_layout_from_ui_layoutmap_else e_ui_layout_from_ui_layoutmap_else = NULL;
  vx_ui_ui::Func_ui_layout_from_ui_layoutmap_else t_ui_layout_from_ui_layoutmap_else = NULL;
  vx_ui_ui::Func_ui_readstate_from_uid e_ui_readstate_from_uid = NULL;
  vx_ui_ui::Func_ui_readstate_from_uid t_ui_readstate_from_uid = NULL;
  vx_ui_ui::Func_ui_render e_ui_render = NULL;
  vx_ui_ui::Func_ui_render t_ui_render = NULL;
  vx_ui_ui::Func_ui_render_from_fn_render_ui_orig_parent e_ui_render_from_fn_render_ui_orig_parent = NULL;
  vx_ui_ui::Func_ui_render_from_fn_render_ui_orig_parent t_ui_render_from_fn_render_ui_orig_parent = NULL;
  vx_ui_ui::Func_ui_render_from_ui_orig_parent e_ui_render_from_ui_orig_parent = NULL;
  vx_ui_ui::Func_ui_render_from_ui_orig_parent t_ui_render_from_ui_orig_parent = NULL;
  vx_ui_ui::Func_ui_from_renderer_ui_orig_parent e_ui_from_renderer_ui_orig_parent = NULL;
  vx_ui_ui::Func_ui_from_renderer_ui_orig_parent t_ui_from_renderer_ui_orig_parent = NULL;
  vx_ui_ui::Func_uiengine_readstate e_uiengine_readstate = NULL;
  vx_ui_ui::Func_uiengine_readstate t_uiengine_readstate = NULL;
  vx_ui_ui::Func_uiengine_render e_uiengine_render = NULL;
  vx_ui_ui::Func_uiengine_render t_uiengine_render = NULL;
  vx_ui_ui::Func_uimap_layout_from_uimap_layoutmap_else e_uimap_layout_from_uimap_layoutmap_else = NULL;
  vx_ui_ui::Func_uimap_layout_from_uimap_layoutmap_else t_uimap_layout_from_uimap_layoutmap_else = NULL;
  vx_ui_ui::Func_uimap_render_from_uimap_parent e_uimap_render_from_uimap_parent = NULL;
  vx_ui_ui::Func_uimap_render_from_uimap_parent t_uimap_render_from_uimap_parent = NULL;
  vx_ui_ui::Func_uimap_from_uilist e_uimap_from_uilist = NULL;
  vx_ui_ui::Func_uimap_from_uilist t_uimap_from_uilist = NULL;
  vx_ui_ui::Func_uimap_from_uimap_data e_uimap_from_uimap_data = NULL;
  vx_ui_ui::Func_uimap_from_uimap_data t_uimap_from_uimap_data = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_ui_ui::c_layout_app = new vx_ui_ui::Class_layout_app();
      vx_ui_ui::c_layout_background = new vx_ui_ui::Class_layout_background();
      vx_ui_ui::c_layout_combobox = new vx_ui_ui::Class_layout_combobox();
      vx_ui_ui::c_layout_else = new vx_ui_ui::Class_layout_else();
      vx_ui_ui::c_layout_flow_columns = new vx_ui_ui::Class_layout_flow_columns();
      vx_ui_ui::c_layout_flow_rows = new vx_ui_ui::Class_layout_flow_rows();
      vx_ui_ui::c_layout_image = new vx_ui_ui::Class_layout_image();
      vx_ui_ui::c_layout_label = new vx_ui_ui::Class_layout_label();
      vx_ui_ui::c_layout_main = new vx_ui_ui::Class_layout_main();
      vx_ui_ui::c_layout_maxpanel = new vx_ui_ui::Class_layout_maxpanel();
      vx_ui_ui::c_layout_menubar = new vx_ui_ui::Class_layout_menubar();
      vx_ui_ui::c_layout_menudrawer = new vx_ui_ui::Class_layout_menudrawer();
      vx_ui_ui::c_layout_msgbox = new vx_ui_ui::Class_layout_msgbox();
      vx_ui_ui::c_layout_navbar = new vx_ui_ui::Class_layout_navbar();
      vx_ui_ui::c_layout_navdrawer = new vx_ui_ui::Class_layout_navdrawer();
      vx_ui_ui::c_layout_panel = new vx_ui_ui::Class_layout_panel();
      vx_ui_ui::c_layout_parallax = new vx_ui_ui::Class_layout_parallax();
      vx_ui_ui::c_layout_statusbar = new vx_ui_ui::Class_layout_statusbar();
      vx_ui_ui::c_layout_statusdrawer = new vx_ui_ui::Class_layout_statusdrawer();
      vx_ui_ui::c_layout_text = new vx_ui_ui::Class_layout_text();
      vx_ui_ui::c_layout_textentry = new vx_ui_ui::Class_layout_textentry();
      vx_ui_ui::c_pin_bottom = new vx_ui_ui::Class_pin_bottom();
      vx_ui_ui::c_pin_center = new vx_ui_ui::Class_pin_center();
      vx_ui_ui::c_pin_center_h = new vx_ui_ui::Class_pin_center_h();
      vx_ui_ui::c_pin_center_v = new vx_ui_ui::Class_pin_center_v();
      vx_ui_ui::c_pin_expand = new vx_ui_ui::Class_pin_expand();
      vx_ui_ui::c_pin_left = new vx_ui_ui::Class_pin_left();
      vx_ui_ui::c_pin_right = new vx_ui_ui::Class_pin_right();
      vx_ui_ui::c_pin_top = new vx_ui_ui::Class_pin_top();
      vx_ui_ui::c_styletype_custom = new vx_ui_ui::Class_styletype_custom();
      vx_ui_ui::c_styletype_shared = new vx_ui_ui::Class_styletype_shared();
      vx_ui_ui::c_styletype_system = new vx_ui_ui::Class_styletype_system();
      vx_ui_ui::e_bounds = new Class_bounds();
      vx_core::vx_reserve_empty(vx_ui_ui::e_bounds);
      vx_ui_ui::t_bounds = new Class_bounds();
      vx_core::vx_reserve_type(vx_ui_ui::t_bounds);
      vx_ui_ui::e_cursor = new Class_cursor();
      vx_core::vx_reserve_empty(vx_ui_ui::e_cursor);
      vx_ui_ui::t_cursor = new Class_cursor();
      vx_core::vx_reserve_type(vx_ui_ui::t_cursor);
      vx_ui_ui::e_cursor_pointer = new Class_cursor_pointer();
      vx_core::vx_reserve_empty(vx_ui_ui::e_cursor_pointer);
      vx_ui_ui::t_cursor_pointer = new Class_cursor_pointer();
      vx_core::vx_reserve_type(vx_ui_ui::t_cursor_pointer);
      vx_ui_ui::e_layout = new Class_layout();
      vx_core::vx_reserve_empty(vx_ui_ui::e_layout);
      vx_ui_ui::t_layout = new Class_layout();
      vx_core::vx_reserve_type(vx_ui_ui::t_layout);
      vx_ui_ui::e_layoutengine = new Class_layoutengine();
      vx_core::vx_reserve_empty(vx_ui_ui::e_layoutengine);
      vx_ui_ui::t_layoutengine = new Class_layoutengine();
      vx_core::vx_reserve_type(vx_ui_ui::t_layoutengine);
      vx_ui_ui::e_layoutlist = new Class_layoutlist();
      vx_core::vx_reserve_empty(vx_ui_ui::e_layoutlist);
      vx_ui_ui::t_layoutlist = new Class_layoutlist();
      vx_core::vx_reserve_type(vx_ui_ui::t_layoutlist);
      vx_ui_ui::e_layoutmap = new Class_layoutmap();
      vx_core::vx_reserve_empty(vx_ui_ui::e_layoutmap);
      vx_ui_ui::t_layoutmap = new Class_layoutmap();
      vx_core::vx_reserve_type(vx_ui_ui::t_layoutmap);
      vx_ui_ui::e_pin = new Class_pin();
      vx_core::vx_reserve_empty(vx_ui_ui::e_pin);
      vx_ui_ui::t_pin = new Class_pin();
      vx_core::vx_reserve_type(vx_ui_ui::t_pin);
      vx_ui_ui::e_point = new Class_point();
      vx_core::vx_reserve_empty(vx_ui_ui::e_point);
      vx_ui_ui::t_point = new Class_point();
      vx_core::vx_reserve_type(vx_ui_ui::t_point);
      vx_ui_ui::e_pointstyle = new Class_pointstyle();
      vx_core::vx_reserve_empty(vx_ui_ui::e_pointstyle);
      vx_ui_ui::t_pointstyle = new Class_pointstyle();
      vx_core::vx_reserve_type(vx_ui_ui::t_pointstyle);
      vx_ui_ui::e_render = new Class_render();
      vx_core::vx_reserve_empty(vx_ui_ui::e_render);
      vx_ui_ui::t_render = new Class_render();
      vx_core::vx_reserve_type(vx_ui_ui::t_render);
      vx_ui_ui::e_rendermap = new Class_rendermap();
      vx_core::vx_reserve_empty(vx_ui_ui::e_rendermap);
      vx_ui_ui::t_rendermap = new Class_rendermap();
      vx_core::vx_reserve_type(vx_ui_ui::t_rendermap);
      vx_ui_ui::e_style = new Class_style();
      vx_core::vx_reserve_empty(vx_ui_ui::e_style);
      vx_ui_ui::t_style = new Class_style();
      vx_core::vx_reserve_type(vx_ui_ui::t_style);
      vx_ui_ui::e_stylelist = new Class_stylelist();
      vx_core::vx_reserve_empty(vx_ui_ui::e_stylelist);
      vx_ui_ui::t_stylelist = new Class_stylelist();
      vx_core::vx_reserve_type(vx_ui_ui::t_stylelist);
      vx_ui_ui::e_stylemap = new Class_stylemap();
      vx_core::vx_reserve_empty(vx_ui_ui::e_stylemap);
      vx_ui_ui::t_stylemap = new Class_stylemap();
      vx_core::vx_reserve_type(vx_ui_ui::t_stylemap);
      vx_ui_ui::e_stylesheet = new Class_stylesheet();
      vx_core::vx_reserve_empty(vx_ui_ui::e_stylesheet);
      vx_ui_ui::t_stylesheet = new Class_stylesheet();
      vx_core::vx_reserve_type(vx_ui_ui::t_stylesheet);
      vx_ui_ui::e_styletype = new Class_styletype();
      vx_core::vx_reserve_empty(vx_ui_ui::e_styletype);
      vx_ui_ui::t_styletype = new Class_styletype();
      vx_core::vx_reserve_type(vx_ui_ui::t_styletype);
      vx_ui_ui::e_ui = new Class_ui();
      vx_core::vx_reserve_empty(vx_ui_ui::e_ui);
      vx_ui_ui::t_ui = new Class_ui();
      vx_core::vx_reserve_type(vx_ui_ui::t_ui);
      vx_ui_ui::e_uiengine = new Class_uiengine();
      vx_core::vx_reserve_empty(vx_ui_ui::e_uiengine);
      vx_ui_ui::t_uiengine = new Class_uiengine();
      vx_core::vx_reserve_type(vx_ui_ui::t_uiengine);
      vx_ui_ui::e_uilist = new Class_uilist();
      vx_core::vx_reserve_empty(vx_ui_ui::e_uilist);
      vx_ui_ui::t_uilist = new Class_uilist();
      vx_core::vx_reserve_type(vx_ui_ui::t_uilist);
      vx_ui_ui::e_uimap = new Class_uimap();
      vx_core::vx_reserve_empty(vx_ui_ui::e_uimap);
      vx_ui_ui::t_uimap = new Class_uimap();
      vx_core::vx_reserve_type(vx_ui_ui::t_uimap);
      vx_ui_ui::e_boolean_writestate_from_ui = new vx_ui_ui::Class_boolean_writestate_from_ui();
      vx_core::vx_reserve_empty(vx_ui_ui::e_boolean_writestate_from_ui);
      vx_ui_ui::t_boolean_writestate_from_ui = new vx_ui_ui::Class_boolean_writestate_from_ui();
      vx_core::vx_reserve_type(vx_ui_ui::t_boolean_writestate_from_ui);
      vx_ui_ui::e_boolean_writestate_from_uiengine = new vx_ui_ui::Class_boolean_writestate_from_uiengine();
      vx_core::vx_reserve_empty(vx_ui_ui::e_boolean_writestate_from_uiengine);
      vx_ui_ui::t_boolean_writestate_from_uiengine = new vx_ui_ui::Class_boolean_writestate_from_uiengine();
      vx_core::vx_reserve_type(vx_ui_ui::t_boolean_writestate_from_uiengine);
      vx_ui_ui::e_layout_from_style = new vx_ui_ui::Class_layout_from_style();
      vx_core::vx_reserve_empty(vx_ui_ui::e_layout_from_style);
      vx_ui_ui::t_layout_from_style = new vx_ui_ui::Class_layout_from_style();
      vx_core::vx_reserve_type(vx_ui_ui::t_layout_from_style);
      vx_ui_ui::e_layoutmap_from_layoutlist = new vx_ui_ui::Class_layoutmap_from_layoutlist();
      vx_core::vx_reserve_empty(vx_ui_ui::e_layoutmap_from_layoutlist);
      vx_ui_ui::t_layoutmap_from_layoutlist = new vx_ui_ui::Class_layoutmap_from_layoutlist();
      vx_core::vx_reserve_type(vx_ui_ui::t_layoutmap_from_layoutlist);
      vx_ui_ui::e_stylemap_from_stylelist = new vx_ui_ui::Class_stylemap_from_stylelist();
      vx_core::vx_reserve_empty(vx_ui_ui::e_stylemap_from_stylelist);
      vx_ui_ui::t_stylemap_from_stylelist = new vx_ui_ui::Class_stylemap_from_stylelist();
      vx_core::vx_reserve_type(vx_ui_ui::t_stylemap_from_stylelist);
      vx_ui_ui::e_stylesheet_render = new vx_ui_ui::Class_stylesheet_render();
      vx_core::vx_reserve_empty(vx_ui_ui::e_stylesheet_render);
      vx_ui_ui::t_stylesheet_render = new vx_ui_ui::Class_stylesheet_render();
      vx_core::vx_reserve_type(vx_ui_ui::t_stylesheet_render);
      vx_ui_ui::e_ui_data_from_ui = new vx_ui_ui::Class_ui_data_from_ui();
      vx_core::vx_reserve_empty(vx_ui_ui::e_ui_data_from_ui);
      vx_ui_ui::t_ui_data_from_ui = new vx_ui_ui::Class_ui_data_from_ui();
      vx_core::vx_reserve_type(vx_ui_ui::t_ui_data_from_ui);
      vx_ui_ui::e_ui_from_from_event = new vx_ui_ui::Class_ui_from_from_event();
      vx_core::vx_reserve_empty(vx_ui_ui::e_ui_from_from_event);
      vx_ui_ui::t_ui_from_from_event = new vx_ui_ui::Class_ui_from_from_event();
      vx_core::vx_reserve_type(vx_ui_ui::t_ui_from_from_event);
      vx_ui_ui::e_ui_layout_from_ui_layoutmap_else = new vx_ui_ui::Class_ui_layout_from_ui_layoutmap_else();
      vx_core::vx_reserve_empty(vx_ui_ui::e_ui_layout_from_ui_layoutmap_else);
      vx_ui_ui::t_ui_layout_from_ui_layoutmap_else = new vx_ui_ui::Class_ui_layout_from_ui_layoutmap_else();
      vx_core::vx_reserve_type(vx_ui_ui::t_ui_layout_from_ui_layoutmap_else);
      vx_ui_ui::e_ui_readstate_from_uid = new vx_ui_ui::Class_ui_readstate_from_uid();
      vx_core::vx_reserve_empty(vx_ui_ui::e_ui_readstate_from_uid);
      vx_ui_ui::t_ui_readstate_from_uid = new vx_ui_ui::Class_ui_readstate_from_uid();
      vx_core::vx_reserve_type(vx_ui_ui::t_ui_readstate_from_uid);
      vx_ui_ui::e_ui_render = new vx_ui_ui::Class_ui_render();
      vx_core::vx_reserve_empty(vx_ui_ui::e_ui_render);
      vx_ui_ui::t_ui_render = new vx_ui_ui::Class_ui_render();
      vx_core::vx_reserve_type(vx_ui_ui::t_ui_render);
      vx_ui_ui::e_ui_render_from_fn_render_ui_orig_parent = new vx_ui_ui::Class_ui_render_from_fn_render_ui_orig_parent();
      vx_core::vx_reserve_empty(vx_ui_ui::e_ui_render_from_fn_render_ui_orig_parent);
      vx_ui_ui::t_ui_render_from_fn_render_ui_orig_parent = new vx_ui_ui::Class_ui_render_from_fn_render_ui_orig_parent();
      vx_core::vx_reserve_type(vx_ui_ui::t_ui_render_from_fn_render_ui_orig_parent);
      vx_ui_ui::e_ui_render_from_ui_orig_parent = new vx_ui_ui::Class_ui_render_from_ui_orig_parent();
      vx_core::vx_reserve_empty(vx_ui_ui::e_ui_render_from_ui_orig_parent);
      vx_ui_ui::t_ui_render_from_ui_orig_parent = new vx_ui_ui::Class_ui_render_from_ui_orig_parent();
      vx_core::vx_reserve_type(vx_ui_ui::t_ui_render_from_ui_orig_parent);
      vx_ui_ui::e_ui_from_renderer_ui_orig_parent = new vx_ui_ui::Class_ui_from_renderer_ui_orig_parent();
      vx_core::vx_reserve_empty(vx_ui_ui::e_ui_from_renderer_ui_orig_parent);
      vx_ui_ui::t_ui_from_renderer_ui_orig_parent = new vx_ui_ui::Class_ui_from_renderer_ui_orig_parent();
      vx_core::vx_reserve_type(vx_ui_ui::t_ui_from_renderer_ui_orig_parent);
      vx_ui_ui::e_uiengine_readstate = new vx_ui_ui::Class_uiengine_readstate();
      vx_core::vx_reserve_empty(vx_ui_ui::e_uiengine_readstate);
      vx_ui_ui::t_uiengine_readstate = new vx_ui_ui::Class_uiengine_readstate();
      vx_core::vx_reserve_type(vx_ui_ui::t_uiengine_readstate);
      vx_ui_ui::e_uiengine_render = new vx_ui_ui::Class_uiengine_render();
      vx_core::vx_reserve_empty(vx_ui_ui::e_uiengine_render);
      vx_ui_ui::t_uiengine_render = new vx_ui_ui::Class_uiengine_render();
      vx_core::vx_reserve_type(vx_ui_ui::t_uiengine_render);
      vx_ui_ui::e_uimap_layout_from_uimap_layoutmap_else = new vx_ui_ui::Class_uimap_layout_from_uimap_layoutmap_else();
      vx_core::vx_reserve_empty(vx_ui_ui::e_uimap_layout_from_uimap_layoutmap_else);
      vx_ui_ui::t_uimap_layout_from_uimap_layoutmap_else = new vx_ui_ui::Class_uimap_layout_from_uimap_layoutmap_else();
      vx_core::vx_reserve_type(vx_ui_ui::t_uimap_layout_from_uimap_layoutmap_else);
      vx_ui_ui::e_uimap_render_from_uimap_parent = new vx_ui_ui::Class_uimap_render_from_uimap_parent();
      vx_core::vx_reserve_empty(vx_ui_ui::e_uimap_render_from_uimap_parent);
      vx_ui_ui::t_uimap_render_from_uimap_parent = new vx_ui_ui::Class_uimap_render_from_uimap_parent();
      vx_core::vx_reserve_type(vx_ui_ui::t_uimap_render_from_uimap_parent);
      vx_ui_ui::e_uimap_from_uilist = new vx_ui_ui::Class_uimap_from_uilist();
      vx_core::vx_reserve_empty(vx_ui_ui::e_uimap_from_uilist);
      vx_ui_ui::t_uimap_from_uilist = new vx_ui_ui::Class_uimap_from_uilist();
      vx_core::vx_reserve_type(vx_ui_ui::t_uimap_from_uilist);
      vx_ui_ui::e_uimap_from_uimap_data = new vx_ui_ui::Class_uimap_from_uimap_data();
      vx_core::vx_reserve_empty(vx_ui_ui::e_uimap_from_uimap_data);
      vx_ui_ui::t_uimap_from_uimap_data = new vx_ui_ui::Class_uimap_from_uimap_data();
      vx_core::vx_reserve_type(vx_ui_ui::t_uimap_from_uimap_data);
      vx_ui_ui::Class_layout_app::vx_const_new(vx_ui_ui::c_layout_app);
      vx_ui_ui::Class_layout_background::vx_const_new(vx_ui_ui::c_layout_background);
      vx_ui_ui::Class_layout_combobox::vx_const_new(vx_ui_ui::c_layout_combobox);
      vx_ui_ui::Class_layout_else::vx_const_new(vx_ui_ui::c_layout_else);
      vx_ui_ui::Class_layout_flow_columns::vx_const_new(vx_ui_ui::c_layout_flow_columns);
      vx_ui_ui::Class_layout_flow_rows::vx_const_new(vx_ui_ui::c_layout_flow_rows);
      vx_ui_ui::Class_layout_image::vx_const_new(vx_ui_ui::c_layout_image);
      vx_ui_ui::Class_layout_label::vx_const_new(vx_ui_ui::c_layout_label);
      vx_ui_ui::Class_layout_main::vx_const_new(vx_ui_ui::c_layout_main);
      vx_ui_ui::Class_layout_maxpanel::vx_const_new(vx_ui_ui::c_layout_maxpanel);
      vx_ui_ui::Class_layout_menubar::vx_const_new(vx_ui_ui::c_layout_menubar);
      vx_ui_ui::Class_layout_menudrawer::vx_const_new(vx_ui_ui::c_layout_menudrawer);
      vx_ui_ui::Class_layout_msgbox::vx_const_new(vx_ui_ui::c_layout_msgbox);
      vx_ui_ui::Class_layout_navbar::vx_const_new(vx_ui_ui::c_layout_navbar);
      vx_ui_ui::Class_layout_navdrawer::vx_const_new(vx_ui_ui::c_layout_navdrawer);
      vx_ui_ui::Class_layout_panel::vx_const_new(vx_ui_ui::c_layout_panel);
      vx_ui_ui::Class_layout_parallax::vx_const_new(vx_ui_ui::c_layout_parallax);
      vx_ui_ui::Class_layout_statusbar::vx_const_new(vx_ui_ui::c_layout_statusbar);
      vx_ui_ui::Class_layout_statusdrawer::vx_const_new(vx_ui_ui::c_layout_statusdrawer);
      vx_ui_ui::Class_layout_text::vx_const_new(vx_ui_ui::c_layout_text);
      vx_ui_ui::Class_layout_textentry::vx_const_new(vx_ui_ui::c_layout_textentry);
      vx_ui_ui::Class_pin_bottom::vx_const_new(vx_ui_ui::c_pin_bottom);
      vx_ui_ui::Class_pin_center::vx_const_new(vx_ui_ui::c_pin_center);
      vx_ui_ui::Class_pin_center_h::vx_const_new(vx_ui_ui::c_pin_center_h);
      vx_ui_ui::Class_pin_center_v::vx_const_new(vx_ui_ui::c_pin_center_v);
      vx_ui_ui::Class_pin_expand::vx_const_new(vx_ui_ui::c_pin_expand);
      vx_ui_ui::Class_pin_left::vx_const_new(vx_ui_ui::c_pin_left);
      vx_ui_ui::Class_pin_right::vx_const_new(vx_ui_ui::c_pin_right);
      vx_ui_ui::Class_pin_top::vx_const_new(vx_ui_ui::c_pin_top);
      vx_ui_ui::Class_styletype_custom::vx_const_new(vx_ui_ui::c_styletype_custom);
      vx_ui_ui::Class_styletype_shared::vx_const_new(vx_ui_ui::c_styletype_shared);
      vx_ui_ui::Class_styletype_system::vx_const_new(vx_ui_ui::c_styletype_system);
      vx_core::vx_Type_mapany maptype;
      vx_core::vx_Type_mapany mapconst;
      vx_core::vx_Type_mapfunc mapfunc;
      vx_core::vx_Type_mapany mapempty;
      maptype["bounds"] = vx_ui_ui::t_bounds;
      maptype["cursor"] = vx_ui_ui::t_cursor;
      maptype["cursor-pointer"] = vx_ui_ui::t_cursor_pointer;
      maptype["layout"] = vx_ui_ui::t_layout;
      maptype["layoutengine"] = vx_ui_ui::t_layoutengine;
      maptype["layoutlist"] = vx_ui_ui::t_layoutlist;
      maptype["layoutmap"] = vx_ui_ui::t_layoutmap;
      maptype["pin"] = vx_ui_ui::t_pin;
      maptype["point"] = vx_ui_ui::t_point;
      maptype["pointstyle"] = vx_ui_ui::t_pointstyle;
      maptype["render"] = vx_ui_ui::t_render;
      maptype["rendermap"] = vx_ui_ui::t_rendermap;
      maptype["style"] = vx_ui_ui::t_style;
      maptype["stylelist"] = vx_ui_ui::t_stylelist;
      maptype["stylemap"] = vx_ui_ui::t_stylemap;
      maptype["stylesheet"] = vx_ui_ui::t_stylesheet;
      maptype["styletype"] = vx_ui_ui::t_styletype;
      maptype["ui"] = vx_ui_ui::t_ui;
      maptype["uiengine"] = vx_ui_ui::t_uiengine;
      maptype["uilist"] = vx_ui_ui::t_uilist;
      maptype["uimap"] = vx_ui_ui::t_uimap;
      mapconst["layout-app"] = vx_ui_ui::c_layout_app;
      mapconst["layout-background"] = vx_ui_ui::c_layout_background;
      mapconst["layout-combobox"] = vx_ui_ui::c_layout_combobox;
      mapconst["layout-else"] = vx_ui_ui::c_layout_else;
      mapconst["layout-flow-columns"] = vx_ui_ui::c_layout_flow_columns;
      mapconst["layout-flow-rows"] = vx_ui_ui::c_layout_flow_rows;
      mapconst["layout-image"] = vx_ui_ui::c_layout_image;
      mapconst["layout-label"] = vx_ui_ui::c_layout_label;
      mapconst["layout-main"] = vx_ui_ui::c_layout_main;
      mapconst["layout-maxpanel"] = vx_ui_ui::c_layout_maxpanel;
      mapconst["layout-menubar"] = vx_ui_ui::c_layout_menubar;
      mapconst["layout-menudrawer"] = vx_ui_ui::c_layout_menudrawer;
      mapconst["layout-msgbox"] = vx_ui_ui::c_layout_msgbox;
      mapconst["layout-navbar"] = vx_ui_ui::c_layout_navbar;
      mapconst["layout-navdrawer"] = vx_ui_ui::c_layout_navdrawer;
      mapconst["layout-panel"] = vx_ui_ui::c_layout_panel;
      mapconst["layout-parallax"] = vx_ui_ui::c_layout_parallax;
      mapconst["layout-statusbar"] = vx_ui_ui::c_layout_statusbar;
      mapconst["layout-statusdrawer"] = vx_ui_ui::c_layout_statusdrawer;
      mapconst["layout-text"] = vx_ui_ui::c_layout_text;
      mapconst["layout-textentry"] = vx_ui_ui::c_layout_textentry;
      mapconst["pin-bottom"] = vx_ui_ui::c_pin_bottom;
      mapconst["pin-center"] = vx_ui_ui::c_pin_center;
      mapconst["pin-center-h"] = vx_ui_ui::c_pin_center_h;
      mapconst["pin-center-v"] = vx_ui_ui::c_pin_center_v;
      mapconst["pin-expand"] = vx_ui_ui::c_pin_expand;
      mapconst["pin-left"] = vx_ui_ui::c_pin_left;
      mapconst["pin-right"] = vx_ui_ui::c_pin_right;
      mapconst["pin-top"] = vx_ui_ui::c_pin_top;
      mapconst["styletype-custom"] = vx_ui_ui::c_styletype_custom;
      mapconst["styletype-shared"] = vx_ui_ui::c_styletype_shared;
      mapconst["styletype-system"] = vx_ui_ui::c_styletype_system;
      mapfunc["boolean-writestate<-ui"] = vx_ui_ui::t_boolean_writestate_from_ui;
      mapfunc["boolean-writestate<-uiengine"] = vx_ui_ui::t_boolean_writestate_from_uiengine;
      mapfunc["layout<-style"] = vx_ui_ui::t_layout_from_style;
      mapfunc["layoutmap<-layoutlist"] = vx_ui_ui::t_layoutmap_from_layoutlist;
      mapfunc["stylemap<-stylelist"] = vx_ui_ui::t_stylemap_from_stylelist;
      mapfunc["stylesheet-render"] = vx_ui_ui::t_stylesheet_render;
      mapfunc["ui-data<-ui"] = vx_ui_ui::t_ui_data_from_ui;
      mapfunc["ui-from<-event"] = vx_ui_ui::t_ui_from_from_event;
      mapfunc["ui-layout<-ui-layoutmap-else"] = vx_ui_ui::t_ui_layout_from_ui_layoutmap_else;
      mapfunc["ui-readstate<-uid"] = vx_ui_ui::t_ui_readstate_from_uid;
      mapfunc["ui-render"] = vx_ui_ui::t_ui_render;
      mapfunc["ui-render<-fn-render-ui-orig-parent"] = vx_ui_ui::t_ui_render_from_fn_render_ui_orig_parent;
      mapfunc["ui-render<-ui-orig-parent"] = vx_ui_ui::t_ui_render_from_ui_orig_parent;
      mapfunc["ui<-renderer-ui-orig-parent"] = vx_ui_ui::t_ui_from_renderer_ui_orig_parent;
      mapfunc["uiengine-readstate"] = vx_ui_ui::t_uiengine_readstate;
      mapfunc["uiengine-render"] = vx_ui_ui::t_uiengine_render;
      mapfunc["uimap-layout<-uimap-layoutmap-else"] = vx_ui_ui::t_uimap_layout_from_uimap_layoutmap_else;
      mapfunc["uimap-render<-uimap-parent"] = vx_ui_ui::t_uimap_render_from_uimap_parent;
      mapfunc["uimap<-uilist"] = vx_ui_ui::t_uimap_from_uilist;
      mapfunc["uimap<-uimap-data"] = vx_ui_ui::t_uimap_from_uimap_data;
      vx_core::vx_global_package_set("vx/ui/ui", maptype, mapconst, mapfunc);
	   }
  // }

}
