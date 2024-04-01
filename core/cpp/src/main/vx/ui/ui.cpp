#include <map>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/collection.hpp"
#include "../../vx/event.hpp"
#include "../../vx/data/file.hpp"
#include "../../vx/state.hpp"
#include "ui.hpp"

namespace vx_ui_ui {



  // (type align)
  // class Class_align {
    Abstract_align::~Abstract_align() {}

    Class_align::Class_align() : Abstract_align::Abstract_align() {
      vx_core::refcount += 1;
    }

    Class_align::~Class_align() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        
      });
    }

    // vx_get_any(key)
    vx_core::Type_any Class_align::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_align::vx_map() const {
      vx_core::vx_Type_mapany output;
      return output;
    }

    vx_core::Type_any Class_align::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_align, vals);
    }

    vx_core::Type_any Class_align::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_align output = vx_ui_ui::e_align;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_align val = vx_core::vx_any_from_any(vx_ui_ui::t_align, copyval);
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

    vx_core::Type_msgblock Class_align::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_align::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_align::vx_empty() const {return vx_ui_ui::e_align;}
    vx_core::Type_any Class_align::vx_type() const {return vx_ui_ui::t_align;}

    vx_core::Type_typedef Class_align::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "align", // name
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

    vx_core::Type_constdef Class_align::vx_constdef() const {return this->vx_p_constdef;}


  //}

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

  // (type font)
  // class Class_font {
    Abstract_font::~Abstract_font() {}

    Class_font::Class_font() : Abstract_font::Abstract_font() {
      vx_core::refcount += 1;
    }

    Class_font::~Class_font() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_name,
        this->vx_p_fontface,
        this->vx_p_fontsize,
        this->vx_p_fontstyle
      });
    }

    // name()
    vx_core::Type_string Class_font::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // fontface()
    vx_ui_ui::Type_fontface Class_font::fontface() const {
      vx_ui_ui::Type_fontface output = this->vx_p_fontface;
      if (!output) {
        output = vx_ui_ui::e_fontface;
      }
      return output;
    }

    // fontsize()
    vx_core::Type_int Class_font::fontsize() const {
      vx_core::Type_int output = this->vx_p_fontsize;
      if (!output) {
        output = vx_core::e_int;
      }
      return output;
    }

    // fontstyle()
    vx_ui_ui::Type_fontstyle Class_font::fontstyle() const {
      vx_ui_ui::Type_fontstyle output = this->vx_p_fontstyle;
      if (!output) {
        output = vx_ui_ui::e_fontstyle;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_font::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":fontface") {
        output = this->fontface();
      } else if (skey == ":fontsize") {
        output = this->fontsize();
      } else if (skey == ":fontstyle") {
        output = this->fontstyle();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_font::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":name"] = this->name();
      output[":fontface"] = this->fontface();
      output[":fontsize"] = this->fontsize();
      output[":fontstyle"] = this->fontstyle();
      return output;
    }

    vx_core::Type_any Class_font::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_font, vals);
    }

    vx_core::Type_any Class_font::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_font output = vx_ui_ui::e_font;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_font val = vx_core::vx_any_from_any(vx_ui_ui::t_font, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_name = val->name();
      vx_ui_ui::Type_fontface vx_p_fontface = val->fontface();
      vx_core::Type_int vx_p_fontsize = val->fontsize();
      vx_ui_ui::Type_fontstyle vx_p_fontstyle = val->fontstyle();
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
          } else if (testkey == ":fontface") {
            key = testkey;
          } else if (testkey == ":fontsize") {
            key = testkey;
          } else if (testkey == ":fontstyle") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new font) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
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
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new font :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":fontface") {
            if (vx_p_fontface == valsub) {
            } else if (valsubtype == vx_ui_ui::t_fontface) {
              ischanged = true;
              vx_p_fontface = vx_core::vx_any_from_any(vx_ui_ui::t_fontface, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new font :fontface " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":fontsize") {
            if (vx_p_fontsize == valsub) {
            } else if (valsubtype == vx_core::t_int) {
              ischanged = true;
              vx_p_fontsize = vx_core::vx_any_from_any(vx_core::t_int, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new font :fontsize " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":fontstyle") {
            if (vx_p_fontstyle == valsub) {
            } else if (valsubtype == vx_ui_ui::t_fontstyle) {
              ischanged = true;
              vx_p_fontstyle = vx_core::vx_any_from_any(vx_ui_ui::t_fontstyle, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new font :fontstyle " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new font) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_font();
        if (output->vx_p_name != vx_p_name) {
          if (output->vx_p_name) {
            vx_core::vx_release_one(output->vx_p_name);
          }
          output->vx_p_name = vx_p_name;
          vx_core::vx_reserve(vx_p_name);
        }
        if (output->vx_p_fontface != vx_p_fontface) {
          if (output->vx_p_fontface) {
            vx_core::vx_release_one(output->vx_p_fontface);
          }
          output->vx_p_fontface = vx_p_fontface;
          vx_core::vx_reserve(vx_p_fontface);
        }
        if (output->vx_p_fontsize != vx_p_fontsize) {
          if (output->vx_p_fontsize) {
            vx_core::vx_release_one(output->vx_p_fontsize);
          }
          output->vx_p_fontsize = vx_p_fontsize;
          vx_core::vx_reserve(vx_p_fontsize);
        }
        if (output->vx_p_fontstyle != vx_p_fontstyle) {
          if (output->vx_p_fontstyle) {
            vx_core::vx_release_one(output->vx_p_fontstyle);
          }
          output->vx_p_fontstyle = vx_p_fontstyle;
          vx_core::vx_reserve(vx_p_fontstyle);
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

    vx_core::Type_msgblock Class_font::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_font::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_font::vx_empty() const {return vx_ui_ui::e_font;}
    vx_core::Type_any Class_font::vx_type() const {return vx_ui_ui::t_font;}

    vx_core::Type_typedef Class_font::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "font", // name
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
            "fontface", // name
            vx_ui_ui::t_fontface // type
          ),
          vx_core::vx_new_arg(
            "fontsize", // name
            vx_core::t_int // type
          ),
          vx_core::vx_new_arg(
            "fontstyle", // name
            vx_ui_ui::t_fontstyle // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_font::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type fontface)
  // class Class_fontface {
    Abstract_fontface::~Abstract_fontface() {}

    Class_fontface::Class_fontface() : Abstract_fontface::Abstract_fontface() {
      vx_core::refcount += 1;
    }

    Class_fontface::~Class_fontface() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_name,
        this->vx_p_weight,
        this->vx_p_unicode,
        this->vx_p_filelist
      });
    }

    // name()
    vx_core::Type_string Class_fontface::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // weight()
    vx_core::Type_string Class_fontface::weight() const {
      vx_core::Type_string output = this->vx_p_weight;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // unicode()
    vx_core::Type_string Class_fontface::unicode() const {
      vx_core::Type_string output = this->vx_p_unicode;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // filelist()
    vx_data_file::Type_filelist Class_fontface::filelist() const {
      vx_data_file::Type_filelist output = this->vx_p_filelist;
      if (!output) {
        output = vx_data_file::e_filelist;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_fontface::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":weight") {
        output = this->weight();
      } else if (skey == ":unicode") {
        output = this->unicode();
      } else if (skey == ":filelist") {
        output = this->filelist();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_fontface::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":name"] = this->name();
      output[":weight"] = this->weight();
      output[":unicode"] = this->unicode();
      output[":filelist"] = this->filelist();
      return output;
    }

    vx_core::Type_any Class_fontface::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_fontface, vals);
    }

    vx_core::Type_any Class_fontface::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_fontface output = vx_ui_ui::e_fontface;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_fontface val = vx_core::vx_any_from_any(vx_ui_ui::t_fontface, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_name = val->name();
      vx_core::Type_string vx_p_weight = val->weight();
      vx_core::Type_string vx_p_unicode = val->unicode();
      vx_data_file::Type_filelist vx_p_filelist = val->filelist();
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
          } else if (testkey == ":weight") {
            key = testkey;
          } else if (testkey == ":unicode") {
            key = testkey;
          } else if (testkey == ":filelist") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new fontface) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
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
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new fontface :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":weight") {
            if (vx_p_weight == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_weight = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new fontface :weight " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":unicode") {
            if (vx_p_unicode == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_unicode = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new fontface :unicode " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":filelist") {
            if (vx_p_filelist == valsub) {
            } else if (valsubtype == vx_data_file::t_filelist) {
              ischanged = true;
              vx_p_filelist = vx_core::vx_any_from_any(vx_data_file::t_filelist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new fontface :filelist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new fontface) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_fontface();
        if (output->vx_p_name != vx_p_name) {
          if (output->vx_p_name) {
            vx_core::vx_release_one(output->vx_p_name);
          }
          output->vx_p_name = vx_p_name;
          vx_core::vx_reserve(vx_p_name);
        }
        if (output->vx_p_weight != vx_p_weight) {
          if (output->vx_p_weight) {
            vx_core::vx_release_one(output->vx_p_weight);
          }
          output->vx_p_weight = vx_p_weight;
          vx_core::vx_reserve(vx_p_weight);
        }
        if (output->vx_p_unicode != vx_p_unicode) {
          if (output->vx_p_unicode) {
            vx_core::vx_release_one(output->vx_p_unicode);
          }
          output->vx_p_unicode = vx_p_unicode;
          vx_core::vx_reserve(vx_p_unicode);
        }
        if (output->vx_p_filelist != vx_p_filelist) {
          if (output->vx_p_filelist) {
            vx_core::vx_release_one(output->vx_p_filelist);
          }
          output->vx_p_filelist = vx_p_filelist;
          vx_core::vx_reserve(vx_p_filelist);
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

    vx_core::Type_msgblock Class_fontface::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_fontface::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_fontface::vx_empty() const {return vx_ui_ui::e_fontface;}
    vx_core::Type_any Class_fontface::vx_type() const {return vx_ui_ui::t_fontface;}

    vx_core::Type_typedef Class_fontface::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "fontface", // name
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
            "weight", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "unicode", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "filelist", // name
            vx_data_file::t_filelist // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_fontface::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type fontfacelist)
  // class Class_fontfacelist {
    Abstract_fontfacelist::~Abstract_fontfacelist() {}

    Class_fontfacelist::Class_fontfacelist() : Abstract_fontfacelist::Abstract_fontfacelist() {
      vx_core::refcount += 1;
    }

    Class_fontfacelist::~Class_fontfacelist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_fontfacelist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_ui_ui::Type_fontface Class_fontfacelist::vx_get_fontface(vx_core::Type_int index) const {
      vx_ui_ui::Type_fontface output = vx_ui_ui::e_fontface;
      long iindex = index->vx_int();
      std::vector<vx_ui_ui::Type_fontface> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_ui_ui::Type_fontface> Class_fontfacelist::vx_listfontface() const {return vx_p_list;}

    vx_core::Type_any vx_ui_ui::Class_fontfacelist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_fontface(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_fontfacelist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_ui_ui::Type_fontfacelist output = vx_ui_ui::e_fontfacelist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_ui_ui::Type_fontface> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_ui_ui::t_fontface) {
          vx_ui_ui::Type_fontface castval = vx_core::vx_any_from_any(vx_ui_ui::t_fontface, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_ui_ui::t_fontface)) {
          vx_ui_ui::Type_fontface castval = vx_core::vx_any_from_any(vx_ui_ui::t_fontface, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(fontfacelist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_fontfacelist();
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

    vx_core::Type_any Class_fontfacelist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_fontfacelist, vals);
    }

    vx_core::Type_any Class_fontfacelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_fontfacelist output = vx_ui_ui::e_fontfacelist;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_fontfacelist val = vx_core::vx_any_from_any(vx_ui_ui::t_fontfacelist, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_ui_ui::Type_fontface> listval = val->vx_listfontface();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_ui_ui::t_fontface) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_ui_ui::t_fontface, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_ui_ui::t_fontface)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_ui_ui::t_fontface, valsub));
        } else if (valsubtype == vx_ui_ui::t_fontfacelist) {
          ischanged = true;
          vx_ui_ui::Type_fontfacelist multi = vx_core::vx_any_from_any(vx_ui_ui::t_fontfacelist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listfontface());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new fontfacelist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_fontfacelist();
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

    vx_core::Type_msgblock Class_fontfacelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_fontfacelist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_fontfacelist::vx_empty() const {return vx_ui_ui::e_fontfacelist;}
    vx_core::Type_any Class_fontfacelist::vx_type() const {return vx_ui_ui::t_fontfacelist;}

    vx_core::Type_typedef Class_fontfacelist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "fontfacelist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_ui_ui::t_fontface}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_fontfacelist::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type fontfacemap)
  // class Class_fontfacemap {
    Abstract_fontfacemap::~Abstract_fontfacemap() {}

    Class_fontfacemap::Class_fontfacemap() : Abstract_fontfacemap::Abstract_fontfacemap() {
      vx_core::refcount += 1;
    }

    Class_fontfacemap::~Class_fontfacemap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (auto const& [key, val] : this->vx_p_map) {
        vx_core::vx_release_one(val);
      }
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_fontfacemap::vx_map() const {
      vx_core::vx_Type_mapany output = vx_core::vx_map_from_map(vx_core::t_any, this->vx_p_map);
      return output;
    }

    // vx_get_fontface(key)
    vx_ui_ui::Type_fontface Class_fontfacemap::vx_get_fontface(vx_core::Type_string key) const {
      vx_ui_ui::Type_fontface output = vx_ui_ui::e_fontface;
      const vx_ui_ui::Class_fontfacemap* map = this;
      std::string skey = key->vx_string();
      if (vx_core::vx_boolean_from_string_starts(skey, ":")) {
        skey = vx_core::vx_string_from_string_start(skey, 2);
      }
      std::map<std::string, vx_ui_ui::Type_fontface> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_ui_ui::e_fontface);
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_fontfacemap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_fontface(key);
    }

    // vx_mapfontface()
    std::map<std::string, vx_ui_ui::Type_fontface> Class_fontfacemap::vx_mapfontface() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_fontfacemap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_ui_ui::Type_fontfacemap output = vx_ui_ui::e_fontfacemap;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_ui_ui::Type_fontface> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_ui_ui::t_fontface) {
          vx_ui_ui::Type_fontface castval = vx_core::vx_any_from_any(vx_ui_ui::t_fontface, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(fontfacemap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((map.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_fontfacemap();
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

    vx_core::Type_any Class_fontfacemap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_fontfacemap, vals);
    }

    vx_core::Type_any Class_fontfacemap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_fontfacemap output = vx_ui_ui::e_fontfacemap;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_fontfacemap valmap = vx_core::vx_any_from_any(vx_ui_ui::t_fontfacemap, copyval);
      output = valmap;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_ui_ui::Type_fontface> mapval = valmap->vx_mapfontface();
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
          vx_ui_ui::Type_fontface valany = NULL;
          if (valsubtype == vx_ui_ui::t_fontface) {
            valany = vx_core::vx_any_from_any(vx_ui_ui::t_fontface, valsub);
          } else if (valsubtype == vx_ui_ui::t_fontface) {
            valany = vx_core::vx_any_from_any(vx_ui_ui::t_fontface, valsub);
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
        output = new vx_ui_ui::Class_fontfacemap();
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

    vx_core::Type_msgblock Class_fontfacemap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_fontfacemap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_fontfacemap::vx_empty() const {return vx_ui_ui::e_fontfacemap;}
    vx_core::Type_any Class_fontfacemap::vx_type() const {return vx_ui_ui::t_fontfacemap;}

    vx_core::Type_typedef Class_fontfacemap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "fontfacemap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_ui_ui::t_fontface}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_fontfacemap::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type fontmap)
  // class Class_fontmap {
    Abstract_fontmap::~Abstract_fontmap() {}

    Class_fontmap::Class_fontmap() : Abstract_fontmap::Abstract_fontmap() {
      vx_core::refcount += 1;
    }

    Class_fontmap::~Class_fontmap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (auto const& [key, val] : this->vx_p_map) {
        vx_core::vx_release_one(val);
      }
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_fontmap::vx_map() const {
      vx_core::vx_Type_mapany output = vx_core::vx_map_from_map(vx_core::t_any, this->vx_p_map);
      return output;
    }

    // vx_get_font(key)
    vx_ui_ui::Type_font Class_fontmap::vx_get_font(vx_core::Type_string key) const {
      vx_ui_ui::Type_font output = vx_ui_ui::e_font;
      const vx_ui_ui::Class_fontmap* map = this;
      std::string skey = key->vx_string();
      if (vx_core::vx_boolean_from_string_starts(skey, ":")) {
        skey = vx_core::vx_string_from_string_start(skey, 2);
      }
      std::map<std::string, vx_ui_ui::Type_font> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_ui_ui::e_font);
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_fontmap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_font(key);
    }

    // vx_mapfont()
    std::map<std::string, vx_ui_ui::Type_font> Class_fontmap::vx_mapfont() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_fontmap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_ui_ui::Type_fontmap output = vx_ui_ui::e_fontmap;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_ui_ui::Type_font> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_ui_ui::t_font) {
          vx_ui_ui::Type_font castval = vx_core::vx_any_from_any(vx_ui_ui::t_font, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(fontmap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((map.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_fontmap();
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

    vx_core::Type_any Class_fontmap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_fontmap, vals);
    }

    vx_core::Type_any Class_fontmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_fontmap output = vx_ui_ui::e_fontmap;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_fontmap valmap = vx_core::vx_any_from_any(vx_ui_ui::t_fontmap, copyval);
      output = valmap;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_ui_ui::Type_font> mapval = valmap->vx_mapfont();
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
          vx_ui_ui::Type_font valany = NULL;
          if (valsubtype == vx_ui_ui::t_font) {
            valany = vx_core::vx_any_from_any(vx_ui_ui::t_font, valsub);
          } else if (valsubtype == vx_ui_ui::t_font) {
            valany = vx_core::vx_any_from_any(vx_ui_ui::t_font, valsub);
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
        output = new vx_ui_ui::Class_fontmap();
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

    vx_core::Type_msgblock Class_fontmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_fontmap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_fontmap::vx_empty() const {return vx_ui_ui::e_fontmap;}
    vx_core::Type_any Class_fontmap::vx_type() const {return vx_ui_ui::t_fontmap;}

    vx_core::Type_typedef Class_fontmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "fontmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_ui_ui::t_font}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_fontmap::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type fontstyle)
  // class Class_fontstyle {
    Abstract_fontstyle::~Abstract_fontstyle() {}

    Class_fontstyle::Class_fontstyle() : Abstract_fontstyle::Abstract_fontstyle() {
      vx_core::refcount += 1;
    }

    Class_fontstyle::~Class_fontstyle() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_name
      });
    }

    // name()
    vx_core::Type_string Class_fontstyle::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_fontstyle::vx_get_any(vx_core::Type_string key) const {
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
    vx_core::vx_Type_mapany Class_fontstyle::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":name"] = this->name();
      return output;
    }

    vx_core::Type_any Class_fontstyle::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_fontstyle, vals);
    }

    vx_core::Type_any Class_fontstyle::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_fontstyle output = vx_ui_ui::e_fontstyle;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_fontstyle val = vx_core::vx_any_from_any(vx_ui_ui::t_fontstyle, copyval);
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
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new fontstyle) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
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
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new fontstyle :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new fontstyle) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_fontstyle();
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

    vx_core::Type_msgblock Class_fontstyle::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_fontstyle::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_fontstyle::vx_empty() const {return vx_ui_ui::e_fontstyle;}
    vx_core::Type_any Class_fontstyle::vx_type() const {return vx_ui_ui::t_fontstyle;}

    vx_core::Type_typedef Class_fontstyle::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "fontstyle", // name
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

    vx_core::Type_constdef Class_fontstyle::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type fontstylemap)
  // class Class_fontstylemap {
    Abstract_fontstylemap::~Abstract_fontstylemap() {}

    Class_fontstylemap::Class_fontstylemap() : Abstract_fontstylemap::Abstract_fontstylemap() {
      vx_core::refcount += 1;
    }

    Class_fontstylemap::~Class_fontstylemap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (auto const& [key, val] : this->vx_p_map) {
        vx_core::vx_release_one(val);
      }
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_fontstylemap::vx_map() const {
      vx_core::vx_Type_mapany output = vx_core::vx_map_from_map(vx_core::t_any, this->vx_p_map);
      return output;
    }

    // vx_get_fontstyle(key)
    vx_ui_ui::Type_fontstyle Class_fontstylemap::vx_get_fontstyle(vx_core::Type_string key) const {
      vx_ui_ui::Type_fontstyle output = vx_ui_ui::e_fontstyle;
      const vx_ui_ui::Class_fontstylemap* map = this;
      std::string skey = key->vx_string();
      if (vx_core::vx_boolean_from_string_starts(skey, ":")) {
        skey = vx_core::vx_string_from_string_start(skey, 2);
      }
      std::map<std::string, vx_ui_ui::Type_fontstyle> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_ui_ui::e_fontstyle);
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_fontstylemap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_fontstyle(key);
    }

    // vx_mapfontstyle()
    std::map<std::string, vx_ui_ui::Type_fontstyle> Class_fontstylemap::vx_mapfontstyle() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_fontstylemap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_ui_ui::Type_fontstylemap output = vx_ui_ui::e_fontstylemap;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_ui_ui::Type_fontstyle> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_ui_ui::t_fontstyle) {
          vx_ui_ui::Type_fontstyle castval = vx_core::vx_any_from_any(vx_ui_ui::t_fontstyle, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(fontstylemap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((map.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_fontstylemap();
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

    vx_core::Type_any Class_fontstylemap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_fontstylemap, vals);
    }

    vx_core::Type_any Class_fontstylemap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_fontstylemap output = vx_ui_ui::e_fontstylemap;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_fontstylemap valmap = vx_core::vx_any_from_any(vx_ui_ui::t_fontstylemap, copyval);
      output = valmap;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_ui_ui::Type_fontstyle> mapval = valmap->vx_mapfontstyle();
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
          vx_ui_ui::Type_fontstyle valany = NULL;
          if (valsubtype == vx_ui_ui::t_fontstyle) {
            valany = vx_core::vx_any_from_any(vx_ui_ui::t_fontstyle, valsub);
          } else if (valsubtype == vx_ui_ui::t_fontstyle) {
            valany = vx_core::vx_any_from_any(vx_ui_ui::t_fontstyle, valsub);
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
        output = new vx_ui_ui::Class_fontstylemap();
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

    vx_core::Type_msgblock Class_fontstylemap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_fontstylemap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_fontstylemap::vx_empty() const {return vx_ui_ui::e_fontstylemap;}
    vx_core::Type_any Class_fontstylemap::vx_type() const {return vx_ui_ui::t_fontstylemap;}

    vx_core::Type_typedef Class_fontstylemap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "fontstylemap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_ui_ui::t_fontstyle}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_fontstylemap::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type image)
  // class Class_image {
    Abstract_image::~Abstract_image() {}

    Class_image::Class_image() : Abstract_image::Abstract_image() {
      vx_core::refcount += 1;
    }

    Class_image::~Class_image() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_name,
        this->vx_p_label,
        this->vx_p_file
      });
    }

    // name()
    vx_core::Type_string Class_image::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // label()
    vx_core::Type_string Class_image::label() const {
      vx_core::Type_string output = this->vx_p_label;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // file()
    vx_data_file::Type_file Class_image::file() const {
      vx_data_file::Type_file output = this->vx_p_file;
      if (!output) {
        output = vx_data_file::e_file;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_image::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":label") {
        output = this->label();
      } else if (skey == ":file") {
        output = this->file();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_image::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":name"] = this->name();
      output[":label"] = this->label();
      output[":file"] = this->file();
      return output;
    }

    vx_core::Type_any Class_image::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_ui_ui::e_image, vals);
    }

    vx_core::Type_any Class_image::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Type_image output = vx_ui_ui::e_image;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_ui_ui::Type_image val = vx_core::vx_any_from_any(vx_ui_ui::t_image, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_name = val->name();
      vx_core::Type_string vx_p_label = val->label();
      vx_data_file::Type_file vx_p_file = val->file();
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
          } else if (testkey == ":label") {
            key = testkey;
          } else if (testkey == ":file") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new image) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
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
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new image :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":label") {
            if (vx_p_label == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_label = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new image :label " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":file") {
            if (vx_p_file == valsub) {
            } else if (valsubtype == vx_data_file::t_file) {
              ischanged = true;
              vx_p_file = vx_core::vx_any_from_any(vx_data_file::t_file, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new image :file " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new image) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_ui_ui::Class_image();
        if (output->vx_p_name != vx_p_name) {
          if (output->vx_p_name) {
            vx_core::vx_release_one(output->vx_p_name);
          }
          output->vx_p_name = vx_p_name;
          vx_core::vx_reserve(vx_p_name);
        }
        if (output->vx_p_label != vx_p_label) {
          if (output->vx_p_label) {
            vx_core::vx_release_one(output->vx_p_label);
          }
          output->vx_p_label = vx_p_label;
          vx_core::vx_reserve(vx_p_label);
        }
        if (output->vx_p_file != vx_p_file) {
          if (output->vx_p_file) {
            vx_core::vx_release_one(output->vx_p_file);
          }
          output->vx_p_file = vx_p_file;
          vx_core::vx_reserve(vx_p_file);
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

    vx_core::Type_msgblock Class_image::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_ui_ui::Class_image::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_image::vx_empty() const {return vx_ui_ui::e_image;}
    vx_core::Type_any Class_image::vx_type() const {return vx_ui_ui::t_image;}

    vx_core::Type_typedef Class_image::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "image", // name
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
            "label", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "file", // name
            vx_data_file::t_file // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_image::vx_constdef() const {return this->vx_p_constdef;}


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
        this->vx_p_boolean_print,
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

    // boolean_print()
    vx_ui_ui::Func_boolean_print Class_layoutengine::boolean_print() const {
      vx_ui_ui::Func_boolean_print output = this->vx_p_boolean_print;
      if (!output) {
        output = vx_ui_ui::e_boolean_print;
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
      } else if (skey == ":boolean-print") {
        output = this->boolean_print();
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
      output[":boolean-print"] = this->boolean_print();
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
      vx_ui_ui::Func_boolean_print vx_p_boolean_print = val->boolean_print();
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
          } else if (testkey == ":boolean-print") {
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
          } else if (key == ":boolean-print") {
            if (vx_p_boolean_print == valsub) {
            } else if (valsubtype == vx_ui_ui::t_boolean_print) {
              ischanged = true;
              vx_p_boolean_print = vx_core::vx_any_from_any(vx_ui_ui::t_boolean_print, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new layoutengine :boolean-print " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
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
        if (output->vx_p_boolean_print != vx_p_boolean_print) {
          if (output->vx_p_boolean_print) {
            vx_core::vx_release_one(output->vx_p_boolean_print);
          }
          output->vx_p_boolean_print = vx_p_boolean_print;
          vx_core::vx_reserve(vx_p_boolean_print);
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
            "boolean-print", // name
            vx_ui_ui::t_boolean_print // type
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
        this->vx_p_align,
        this->vx_p_boundsmargin,
        this->vx_p_boundspadding,
        this->vx_p_color_background,
        this->vx_p_color_hoverbkgrd,
        this->vx_p_cursor,
        this->vx_p_font,
        this->vx_p_hidden,
        this->vx_p_image_background,
        this->vx_p_layout,
        this->vx_p_type,
        this->vx_p_pin,
        this->vx_p_pointpos,
        this->vx_p_pointrotate,
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

    // align()
    vx_ui_ui::Type_align Class_style::align() const {
      vx_ui_ui::Type_align output = this->vx_p_align;
      if (!output) {
        output = vx_ui_ui::e_align;
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

    // font()
    vx_ui_ui::Type_font Class_style::font() const {
      vx_ui_ui::Type_font output = this->vx_p_font;
      if (!output) {
        output = vx_ui_ui::e_font;
      }
      return output;
    }

    // hidden()
    vx_core::Type_boolean Class_style::hidden() const {
      vx_core::Type_boolean output = this->vx_p_hidden;
      if (!output) {
        output = vx_core::e_boolean;
      }
      return output;
    }

    // image_background()
    vx_ui_ui::Type_image Class_style::image_background() const {
      vx_ui_ui::Type_image output = this->vx_p_image_background;
      if (!output) {
        output = vx_ui_ui::e_image;
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

    // pointrotate()
    vx_ui_ui::Type_point Class_style::pointrotate() const {
      vx_ui_ui::Type_point output = this->vx_p_pointrotate;
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
      } else if (skey == ":align") {
        output = this->align();
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
      } else if (skey == ":font") {
        output = this->font();
      } else if (skey == ":hidden") {
        output = this->hidden();
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
      } else if (skey == ":pointrotate") {
        output = this->pointrotate();
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
      output[":align"] = this->align();
      output[":boundsmargin"] = this->boundsmargin();
      output[":boundspadding"] = this->boundspadding();
      output[":color-background"] = this->color_background();
      output[":color-hoverbkgrd"] = this->color_hoverbkgrd();
      output[":cursor"] = this->cursor();
      output[":font"] = this->font();
      output[":hidden"] = this->hidden();
      output[":image-background"] = this->image_background();
      output[":layout"] = this->layout();
      output[":type"] = this->type();
      output[":pin"] = this->pin();
      output[":pointpos"] = this->pointpos();
      output[":pointrotate"] = this->pointrotate();
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
      vx_ui_ui::Type_align vx_p_align = val->align();
      vx_ui_ui::Type_bounds vx_p_boundsmargin = val->boundsmargin();
      vx_ui_ui::Type_bounds vx_p_boundspadding = val->boundspadding();
      vx_core::Type_string vx_p_color_background = val->color_background();
      vx_core::Type_string vx_p_color_hoverbkgrd = val->color_hoverbkgrd();
      vx_ui_ui::Type_cursor vx_p_cursor = val->cursor();
      vx_ui_ui::Type_font vx_p_font = val->font();
      vx_core::Type_boolean vx_p_hidden = val->hidden();
      vx_ui_ui::Type_image vx_p_image_background = val->image_background();
      vx_ui_ui::Type_layout vx_p_layout = val->layout();
      vx_ui_ui::Type_styletype vx_p_type = val->type();
      vx_ui_ui::Type_pin vx_p_pin = val->pin();
      vx_ui_ui::Type_point vx_p_pointpos = val->pointpos();
      vx_ui_ui::Type_point vx_p_pointrotate = val->pointrotate();
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
          } else if (testkey == ":align") {
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
          } else if (testkey == ":font") {
            key = testkey;
          } else if (testkey == ":hidden") {
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
          } else if (testkey == ":pointrotate") {
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
          } else if (key == ":align") {
            if (vx_p_align == valsub) {
            } else if (valsubtype == vx_ui_ui::t_align) {
              ischanged = true;
              vx_p_align = vx_core::vx_any_from_any(vx_ui_ui::t_align, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new style :align " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
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
          } else if (key == ":font") {
            if (vx_p_font == valsub) {
            } else if (valsubtype == vx_ui_ui::t_font) {
              ischanged = true;
              vx_p_font = vx_core::vx_any_from_any(vx_ui_ui::t_font, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new style :font " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":hidden") {
            if (vx_p_hidden == valsub) {
            } else if (valsubtype == vx_core::t_boolean) {
              ischanged = true;
              vx_p_hidden = vx_core::vx_any_from_any(vx_core::t_boolean, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new style :hidden " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":image-background") {
            if (vx_p_image_background == valsub) {
            } else if (valsubtype == vx_ui_ui::t_image) {
              ischanged = true;
              vx_p_image_background = vx_core::vx_any_from_any(vx_ui_ui::t_image, valsub);
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
          } else if (key == ":pointrotate") {
            if (vx_p_pointrotate == valsub) {
            } else if (valsubtype == vx_ui_ui::t_point) {
              ischanged = true;
              vx_p_pointrotate = vx_core::vx_any_from_any(vx_ui_ui::t_point, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new style :pointrotate " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
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
        if (output->vx_p_align != vx_p_align) {
          if (output->vx_p_align) {
            vx_core::vx_release_one(output->vx_p_align);
          }
          output->vx_p_align = vx_p_align;
          vx_core::vx_reserve(vx_p_align);
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
        if (output->vx_p_font != vx_p_font) {
          if (output->vx_p_font) {
            vx_core::vx_release_one(output->vx_p_font);
          }
          output->vx_p_font = vx_p_font;
          vx_core::vx_reserve(vx_p_font);
        }
        if (output->vx_p_hidden != vx_p_hidden) {
          if (output->vx_p_hidden) {
            vx_core::vx_release_one(output->vx_p_hidden);
          }
          output->vx_p_hidden = vx_p_hidden;
          vx_core::vx_reserve(vx_p_hidden);
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
        if (output->vx_p_pointrotate != vx_p_pointrotate) {
          if (output->vx_p_pointrotate) {
            vx_core::vx_release_one(output->vx_p_pointrotate);
          }
          output->vx_p_pointrotate = vx_p_pointrotate;
          vx_core::vx_reserve(vx_p_pointrotate);
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
            "align", // name
            vx_ui_ui::t_align // type
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
            "font", // name
            vx_ui_ui::t_font // type
          ),
          vx_core::vx_new_arg(
            "hidden", // name
            vx_core::t_boolean // type
          ),
          vx_core::vx_new_arg(
            "image-background", // name
            vx_ui_ui::t_image // type
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
            "pointrotate", // name
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
        this->vx_p_fontfacemap,
        this->vx_p_stylemap
      });
    }

    // fontfacemap()
    vx_ui_ui::Type_fontfacemap Class_stylesheet::fontfacemap() const {
      vx_ui_ui::Type_fontfacemap output = this->vx_p_fontfacemap;
      if (!output) {
        output = vx_ui_ui::e_fontfacemap;
      }
      return output;
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
      } else if (skey == ":fontfacemap") {
        output = this->fontfacemap();
      } else if (skey == ":stylemap") {
        output = this->stylemap();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_stylesheet::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":fontfacemap"] = this->fontfacemap();
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
      vx_ui_ui::Type_fontfacemap vx_p_fontfacemap = val->fontfacemap();
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
          } else if (testkey == ":fontfacemap") {
            key = testkey;
          } else if (testkey == ":stylemap") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new stylesheet) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":fontfacemap") {
            if (vx_p_fontfacemap == valsub) {
            } else if (valsubtype == vx_ui_ui::t_fontfacemap) {
              ischanged = true;
              vx_p_fontfacemap = vx_core::vx_any_from_any(vx_ui_ui::t_fontfacemap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new stylesheet :fontfacemap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
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
        if (output->vx_p_fontfacemap != vx_p_fontfacemap) {
          if (output->vx_p_fontfacemap) {
            vx_core::vx_release_one(output->vx_p_fontfacemap);
          }
          output->vx_p_fontfacemap = vx_p_fontfacemap;
          vx_core::vx_reserve(vx_p_fontfacemap);
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
            "fontfacemap", // name
            vx_ui_ui::t_fontfacemap // type
          ),
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
        this->vx_p_uid,
        this->vx_p_name,
        this->vx_p_layout,
        this->vx_p_parent,
        this->vx_p_path,
        this->vx_p_hidden,
        this->vx_p_selected,
        this->vx_p_selectmulti,
        this->vx_p_style,
        this->vx_p_stylelist,
        this->vx_p_eventmap,
        this->vx_p_data,
        this->vx_p_uimap
      });
    }

    // uid()
    vx_core::Type_string Class_ui::uid() const {
      vx_core::Type_string output = this->vx_p_uid;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // name()
    vx_core::Type_string Class_ui::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // layout()
    vx_ui_ui::Type_layout Class_ui::layout() const {
      vx_ui_ui::Type_layout output = this->vx_p_layout;
      if (!output) {
        output = vx_ui_ui::e_layout;
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

    // hidden()
    vx_core::Type_boolean Class_ui::hidden() const {
      vx_core::Type_boolean output = this->vx_p_hidden;
      if (!output) {
        output = vx_core::e_boolean;
      }
      return output;
    }

    // selected()
    vx_core::Type_boolean Class_ui::selected() const {
      vx_core::Type_boolean output = this->vx_p_selected;
      if (!output) {
        output = vx_core::e_boolean;
      }
      return output;
    }

    // selectmulti()
    vx_core::Type_boolean Class_ui::selectmulti() const {
      vx_core::Type_boolean output = this->vx_p_selectmulti;
      if (!output) {
        output = vx_core::e_boolean;
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

    // eventmap()
    vx_event::Type_eventmap Class_ui::eventmap() const {
      vx_event::Type_eventmap output = this->vx_p_eventmap;
      if (!output) {
        output = vx_event::e_eventmap;
      }
      return output;
    }

    // data()
    vx_core::Type_any Class_ui::data() const {
      vx_core::Type_any output = this->vx_p_data;
      if (!output) {
        output = vx_core::e_any;
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
      } else if (skey == ":uid") {
        output = this->uid();
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":layout") {
        output = this->layout();
      } else if (skey == ":parent") {
        output = this->parent();
      } else if (skey == ":path") {
        output = this->path();
      } else if (skey == ":hidden") {
        output = this->hidden();
      } else if (skey == ":selected") {
        output = this->selected();
      } else if (skey == ":selectmulti") {
        output = this->selectmulti();
      } else if (skey == ":style") {
        output = this->style();
      } else if (skey == ":stylelist") {
        output = this->stylelist();
      } else if (skey == ":eventmap") {
        output = this->eventmap();
      } else if (skey == ":data") {
        output = this->data();
      } else if (skey == ":uimap") {
        output = this->uimap();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_ui::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":uid"] = this->uid();
      output[":name"] = this->name();
      output[":layout"] = this->layout();
      output[":parent"] = this->parent();
      output[":path"] = this->path();
      output[":hidden"] = this->hidden();
      output[":selected"] = this->selected();
      output[":selectmulti"] = this->selectmulti();
      output[":style"] = this->style();
      output[":stylelist"] = this->stylelist();
      output[":eventmap"] = this->eventmap();
      output[":data"] = this->data();
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
      vx_core::Type_string vx_p_uid = val->uid();
      vx_core::Type_string vx_p_name = val->name();
      vx_ui_ui::Type_layout vx_p_layout = val->layout();
      vx_core::Type_string vx_p_parent = val->parent();
      vx_core::Type_string vx_p_path = val->path();
      vx_core::Type_boolean vx_p_hidden = val->hidden();
      vx_core::Type_boolean vx_p_selected = val->selected();
      vx_core::Type_boolean vx_p_selectmulti = val->selectmulti();
      vx_ui_ui::Type_style vx_p_style = val->style();
      vx_ui_ui::Type_stylelist vx_p_stylelist = val->stylelist();
      vx_event::Type_eventmap vx_p_eventmap = val->eventmap();
      vx_core::Type_any vx_p_data = val->data();
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
          } else if (testkey == ":uid") {
            key = testkey;
          } else if (testkey == ":name") {
            key = testkey;
          } else if (testkey == ":layout") {
            key = testkey;
          } else if (testkey == ":parent") {
            key = testkey;
          } else if (testkey == ":path") {
            key = testkey;
          } else if (testkey == ":hidden") {
            key = testkey;
          } else if (testkey == ":selected") {
            key = testkey;
          } else if (testkey == ":selectmulti") {
            key = testkey;
          } else if (testkey == ":style") {
            key = testkey;
          } else if (testkey == ":stylelist") {
            key = testkey;
          } else if (testkey == ":eventmap") {
            key = testkey;
          } else if (testkey == ":data") {
            key = testkey;
          } else if (testkey == ":uimap") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new ui) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":uid") {
            if (vx_p_uid == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_uid = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new ui :uid " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":name") {
            if (vx_p_name == valsub) {
            } else if (valsubtype == vx_core::t_string) {
              ischanged = true;
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new ui :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":layout") {
            if (vx_p_layout == valsub) {
            } else if (valsubtype == vx_ui_ui::t_layout) {
              ischanged = true;
              vx_p_layout = vx_core::vx_any_from_any(vx_ui_ui::t_layout, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new ui :layout " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
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
          } else if (key == ":hidden") {
            if (vx_p_hidden == valsub) {
            } else if (valsubtype == vx_core::t_boolean) {
              ischanged = true;
              vx_p_hidden = vx_core::vx_any_from_any(vx_core::t_boolean, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new ui :hidden " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":selected") {
            if (vx_p_selected == valsub) {
            } else if (valsubtype == vx_core::t_boolean) {
              ischanged = true;
              vx_p_selected = vx_core::vx_any_from_any(vx_core::t_boolean, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new ui :selected " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":selectmulti") {
            if (vx_p_selectmulti == valsub) {
            } else if (valsubtype == vx_core::t_boolean) {
              ischanged = true;
              vx_p_selectmulti = vx_core::vx_any_from_any(vx_core::t_boolean, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new ui :selectmulti " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
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
          } else if (key == ":eventmap") {
            if (vx_p_eventmap == valsub) {
            } else if (valsubtype == vx_event::t_eventmap) {
              ischanged = true;
              vx_p_eventmap = vx_core::vx_any_from_any(vx_event::t_eventmap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new ui :eventmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":data") {
            if (vx_p_data != valsub) {
              ischanged = true;
              vx_p_data = valsub;
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
        if (output->vx_p_uid != vx_p_uid) {
          if (output->vx_p_uid) {
            vx_core::vx_release_one(output->vx_p_uid);
          }
          output->vx_p_uid = vx_p_uid;
          vx_core::vx_reserve(vx_p_uid);
        }
        if (output->vx_p_name != vx_p_name) {
          if (output->vx_p_name) {
            vx_core::vx_release_one(output->vx_p_name);
          }
          output->vx_p_name = vx_p_name;
          vx_core::vx_reserve(vx_p_name);
        }
        if (output->vx_p_layout != vx_p_layout) {
          if (output->vx_p_layout) {
            vx_core::vx_release_one(output->vx_p_layout);
          }
          output->vx_p_layout = vx_p_layout;
          vx_core::vx_reserve(vx_p_layout);
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
        if (output->vx_p_hidden != vx_p_hidden) {
          if (output->vx_p_hidden) {
            vx_core::vx_release_one(output->vx_p_hidden);
          }
          output->vx_p_hidden = vx_p_hidden;
          vx_core::vx_reserve(vx_p_hidden);
        }
        if (output->vx_p_selected != vx_p_selected) {
          if (output->vx_p_selected) {
            vx_core::vx_release_one(output->vx_p_selected);
          }
          output->vx_p_selected = vx_p_selected;
          vx_core::vx_reserve(vx_p_selected);
        }
        if (output->vx_p_selectmulti != vx_p_selectmulti) {
          if (output->vx_p_selectmulti) {
            vx_core::vx_release_one(output->vx_p_selectmulti);
          }
          output->vx_p_selectmulti = vx_p_selectmulti;
          vx_core::vx_reserve(vx_p_selectmulti);
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
        if (output->vx_p_eventmap != vx_p_eventmap) {
          if (output->vx_p_eventmap) {
            vx_core::vx_release_one(output->vx_p_eventmap);
          }
          output->vx_p_eventmap = vx_p_eventmap;
          vx_core::vx_reserve(vx_p_eventmap);
        }
        if (output->vx_p_data != vx_p_data) {
          if (output->vx_p_data) {
            vx_core::vx_release_one(output->vx_p_data);
          }
          output->vx_p_data = vx_p_data;
          vx_core::vx_reserve(vx_p_data);
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
            "uid", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "name", // name
            vx_core::t_string // type
          ),
          vx_core::vx_new_arg(
            "layout", // name
            vx_ui_ui::t_layout // type
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
            "hidden", // name
            vx_core::t_boolean // type
          ),
          vx_core::vx_new_arg(
            "selected", // name
            vx_core::t_boolean // type
          ),
          vx_core::vx_new_arg(
            "selectmulti", // name
            vx_core::t_boolean // type
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
            "eventmap", // name
            vx_event::t_eventmap // type
          ),
          vx_core::vx_new_arg(
            "data", // name
            vx_core::t_any // type
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

  // (const align-center)
  // class Class_align_center {
    // vx_const_new()
    void vx_ui_ui::Class_align_center::vx_const_new(vx_ui_ui::Const_align_center output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "align-center");
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const align-left)
  // class Class_align_left {
    // vx_const_new()
    void vx_ui_ui::Class_align_left::vx_const_new(vx_ui_ui::Const_align_left output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "align-left");
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const align-right)
  // class Class_align_right {
    // vx_const_new()
    void vx_ui_ui::Class_align_right::vx_const_new(vx_ui_ui::Const_align_right output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "align-right");
      vx_core::vx_reserve_type(output);
    }


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

  // (const layout-button)
  // class Class_layout_button {
    // vx_const_new()
    void vx_ui_ui::Class_layout_button::vx_const_new(vx_ui_ui::Const_layout_button output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-button");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-button")
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

  // (const layout-flow-item)
  // class Class_layout_flow_item {
    // vx_const_new()
    void vx_ui_ui::Class_layout_flow_item::vx_const_new(vx_ui_ui::Const_layout_flow_item output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-flow-item");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-flow-item")
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

  // (const layout-titlebar)
  // class Class_layout_titlebar {
    // vx_const_new()
    void vx_ui_ui::Class_layout_titlebar::vx_const_new(vx_ui_ui::Const_layout_titlebar output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/ui/ui", "layout-titlebar");
      long irefcount = vx_core::refcount;
      vx_ui_ui::Type_layout val = vx_core::f_new(
        vx_ui_ui::t_layout,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("layout-titlebar")
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

  // (func boolean-print)
  vx_core::Type_boolean f_boolean_print(vx_core::Type_context context, vx_ui_ui::Type_ui ui) {
    vx_core::Type_boolean output = vx_core::e_boolean;
    vx_core::vx_reserve(ui);
    output = vx_core::f_let(
      vx_core::t_boolean,
      vx_core::t_any_from_func->vx_fn_new({context, ui}, [context, ui]() {
        vx_ui_ui::Type_layoutengine layoutengine = vx_ui_ui::f_layoutengine_readstate(context);
        vx_core::vx_ref_plus(layoutengine);
        vx_ui_ui::Func_boolean_print fn_print = layoutengine->boolean_print();
        vx_core::vx_ref_plus(fn_print);
        vx_core::Type_boolean output_1 = vx_core::vx_any_from_func(vx_core::t_boolean, fn_print, {context, ui});
        vx_core::vx_release_one_except({layoutengine, fn_print}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(ui, output);
    return output;
  }
  /**
   * @function boolean_print
   * Create a print ready version of ui
   * @param  {ui} ui
   * @return {boolean}
   * (func boolean-print)
   */
  // (func boolean-print)
  // class Class_boolean_print {
    Abstract_boolean_print::~Abstract_boolean_print() {}

    Class_boolean_print::Class_boolean_print() : Abstract_boolean_print::Abstract_boolean_print() {
      vx_core::refcount += 1;
    }

    Class_boolean_print::~Class_boolean_print() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_boolean_print::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_boolean_print output = vx_ui_ui::e_boolean_print;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_boolean_print::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_boolean_print output = vx_ui_ui::e_boolean_print;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_boolean_print::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "boolean-print", // name
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

    vx_core::Type_constdef Class_boolean_print::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_boolean_print::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "boolean-print", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_boolean_print::vx_empty() const {return vx_ui_ui::e_boolean_print;}
    vx_core::Type_any Class_boolean_print::vx_type() const {return vx_ui_ui::t_boolean_print;}
    vx_core::Type_msgblock Class_boolean_print::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_print::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_boolean_print::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_boolean_print::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui inputval = vx_core::vx_any_from_any(vx_ui_ui::t_ui, val);
      output = vx_ui_ui::f_boolean_print(context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_boolean_print::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_boolean_print(context, ui);
      vx_core::vx_release_except(arglist, output);
      return output;
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
        vx_core::Type_boolean output_1 = vx_state::f_boolean_writestate_from_mapname_name_value(context, vx_core::vx_new_string(":uimap"), uid, ui);
        vx_core::vx_release_one_except(uid, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(ui, output);
    return output;
  }
  /**
   * @function boolean_writestate_from_ui
   * @param  {ui} ui
   * @return {boolean}
   * (func boolean-writestate<-ui)
   */
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
  /**
   * @function boolean_writestate_from_uiengine
   * Writes the uiengine to state
   * @param  {uiengine} uiengine
   * @return {boolean}
   * (func boolean-writestate<-uiengine)
   */
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

  // (func fontfacemap<-fontfacelist)
  vx_ui_ui::Type_fontfacemap f_fontfacemap_from_fontfacelist(vx_ui_ui::Type_fontfacelist fontfacelist) {
    vx_ui_ui::Type_fontfacemap output = vx_ui_ui::e_fontfacemap;
    vx_core::vx_reserve(fontfacelist);
    output = vx_core::f_map_from_list(
      vx_ui_ui::t_fontfacemap,
      fontfacelist,
      vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any fontface_any) {
        vx_ui_ui::Type_fontface fontface = vx_core::vx_any_from_any(vx_ui_ui::t_fontface, fontface_any);
        vx_core::Type_any output_1 = 
          fontface->name();
        return output_1;
      })
    );
    vx_core::vx_release_one_except(fontfacelist, output);
    return output;
  }
  /**
   * @function fontfacemap_from_fontfacelist
   * Returns a fontfacemap from a fontfacelist
   * @param  {fontfacelist} fontfacelist
   * @return {fontfacemap}
   * (func fontfacemap<-fontfacelist)
   */
  // (func fontfacemap<-fontfacelist)
  // class Class_fontfacemap_from_fontfacelist {
    Abstract_fontfacemap_from_fontfacelist::~Abstract_fontfacemap_from_fontfacelist() {}

    Class_fontfacemap_from_fontfacelist::Class_fontfacemap_from_fontfacelist() : Abstract_fontfacemap_from_fontfacelist::Abstract_fontfacemap_from_fontfacelist() {
      vx_core::refcount += 1;
    }

    Class_fontfacemap_from_fontfacelist::~Class_fontfacemap_from_fontfacelist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_fontfacemap_from_fontfacelist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_fontfacemap_from_fontfacelist output = vx_ui_ui::e_fontfacemap_from_fontfacelist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_fontfacemap_from_fontfacelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_fontfacemap_from_fontfacelist output = vx_ui_ui::e_fontfacemap_from_fontfacelist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_fontfacemap_from_fontfacelist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "fontfacemap<-fontfacelist", // name
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

    vx_core::Type_constdef Class_fontfacemap_from_fontfacelist::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_fontfacemap_from_fontfacelist::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "fontfacemap<-fontfacelist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_fontfacemap_from_fontfacelist::vx_empty() const {return vx_ui_ui::e_fontfacemap_from_fontfacelist;}
    vx_core::Type_any Class_fontfacemap_from_fontfacelist::vx_type() const {return vx_ui_ui::t_fontfacemap_from_fontfacelist;}
    vx_core::Type_msgblock Class_fontfacemap_from_fontfacelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_fontfacemap_from_fontfacelist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_fontfacemap_from_fontfacelist::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_fontfacemap_from_fontfacelist::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_fontfacelist inputval = vx_core::vx_any_from_any(vx_ui_ui::t_fontfacelist, val);
      output = vx_ui_ui::f_fontfacemap_from_fontfacelist(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_fontfacemap_from_fontfacelist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_fontfacelist fontfacelist = vx_core::vx_any_from_any(vx_ui_ui::t_fontfacelist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_fontfacemap_from_fontfacelist(fontfacelist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func int-selected<-ui)
  vx_core::Type_int f_int_selected_from_ui(vx_ui_ui::Type_ui ui) {
    vx_core::Type_int output = vx_core::e_int;
    vx_core::vx_reserve(ui);
    output = vx_core::f_let(
      vx_core::t_int,
      vx_core::t_any_from_func->vx_fn_new({ui}, [ui]() {
        vx_core::Type_string uid = vx_ui_ui::f_string_selected_from_ui(ui);
        vx_core::vx_ref_plus(uid);
        vx_core::Type_stringlist uidlist = vx_ui_ui::f_stringlist_from_ui(ui);
        vx_core::vx_ref_plus(uidlist);
        vx_core::Type_int output_1 = vx_collection::f_int_from_stringlist_find(uidlist, uid);
        vx_core::vx_release_one_except({uid, uidlist}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(ui, output);
    return output;
  }
  /**
   * @function int_selected_from_ui
   * Returns the position of the currently selected subui
   * @param  {ui} ui
   * @return {int}
   * (func int-selected<-ui)
   */
  // (func int-selected<-ui)
  // class Class_int_selected_from_ui {
    Abstract_int_selected_from_ui::~Abstract_int_selected_from_ui() {}

    Class_int_selected_from_ui::Class_int_selected_from_ui() : Abstract_int_selected_from_ui::Abstract_int_selected_from_ui() {
      vx_core::refcount += 1;
    }

    Class_int_selected_from_ui::~Class_int_selected_from_ui() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_int_selected_from_ui::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_int_selected_from_ui output = vx_ui_ui::e_int_selected_from_ui;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_int_selected_from_ui::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_int_selected_from_ui output = vx_ui_ui::e_int_selected_from_ui;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_int_selected_from_ui::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "int-selected<-ui", // name
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

    vx_core::Type_constdef Class_int_selected_from_ui::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_int_selected_from_ui::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "int-selected<-ui", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_int_selected_from_ui::vx_empty() const {return vx_ui_ui::e_int_selected_from_ui;}
    vx_core::Type_any Class_int_selected_from_ui::vx_type() const {return vx_ui_ui::t_int_selected_from_ui;}
    vx_core::Type_msgblock Class_int_selected_from_ui::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_int_selected_from_ui::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_int_selected_from_ui::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_int_selected_from_ui::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui inputval = vx_core::vx_any_from_any(vx_ui_ui::t_ui, val);
      output = vx_ui_ui::f_int_selected_from_ui(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_int_selected_from_ui::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_int_selected_from_ui(ui);
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
  /**
   * @function layout_from_style
   * @param  {style} style
   * @return {layout}
   * (func layout<-style)
   */
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

  // (func layout<-ui)
  vx_ui_ui::Type_layout f_layout_from_ui(vx_core::Type_context context, vx_ui_ui::Type_ui ui) {
    vx_ui_ui::Type_layout output = vx_ui_ui::e_layout;
    vx_core::vx_reserve(ui);
    output = vx_core::f_let(
      vx_ui_ui::t_layout,
      vx_core::t_any_from_func->vx_fn_new({context, ui}, [context, ui]() {
        vx_ui_ui::Type_layoutengine layoutengine = vx_ui_ui::f_layoutengine_readstate(context);
        vx_core::vx_ref_plus(layoutengine);
        vx_ui_ui::Type_layout output_1 = vx_ui_ui::f_layout_from_ui_layoutengine(ui, layoutengine);
        vx_core::vx_release_one_except(layoutengine, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(ui, output);
    return output;
  }
  /**
   * @function layout_from_ui
   * Returns the layout from layoutengine that matches the ui
   * @param  {ui} ui
   * @return {layout}
   * (func layout<-ui)
   */
  // (func layout<-ui)
  // class Class_layout_from_ui {
    Abstract_layout_from_ui::~Abstract_layout_from_ui() {}

    Class_layout_from_ui::Class_layout_from_ui() : Abstract_layout_from_ui::Abstract_layout_from_ui() {
      vx_core::refcount += 1;
    }

    Class_layout_from_ui::~Class_layout_from_ui() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_layout_from_ui::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_layout_from_ui output = vx_ui_ui::e_layout_from_ui;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_layout_from_ui::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_layout_from_ui output = vx_ui_ui::e_layout_from_ui;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_layout_from_ui::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "layout<-ui", // name
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

    vx_core::Type_constdef Class_layout_from_ui::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_layout_from_ui::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "layout<-ui", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_layout_from_ui::vx_empty() const {return vx_ui_ui::e_layout_from_ui;}
    vx_core::Type_any Class_layout_from_ui::vx_type() const {return vx_ui_ui::t_layout_from_ui;}
    vx_core::Type_msgblock Class_layout_from_ui::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_layout_from_ui::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_layout_from_ui::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_layout_from_ui::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui inputval = vx_core::vx_any_from_any(vx_ui_ui::t_ui, val);
      output = vx_ui_ui::f_layout_from_ui(context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_layout_from_ui::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_layout_from_ui(context, ui);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func layout<-ui-layoutengine)
  vx_ui_ui::Type_layout f_layout_from_ui_layoutengine(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_layoutengine layoutengine) {
    vx_ui_ui::Type_layout output = vx_ui_ui::e_layout;
    vx_core::vx_reserve({ui, layoutengine});
    output = vx_core::f_let(
      vx_ui_ui::t_layout,
      vx_core::t_any_from_func->vx_fn_new({layoutengine, ui}, [layoutengine, ui]() {
        vx_ui_ui::Type_layoutmap layoutmap = layoutengine->layoutmap();
        vx_core::vx_ref_plus(layoutmap);
        vx_ui_ui::Type_layout layoutelse = layoutengine->layoutelse();
        vx_core::vx_ref_plus(layoutelse);
        vx_ui_ui::Type_layout output_1 = vx_ui_ui::f_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
        vx_core::vx_release_one_except({layoutmap, layoutelse}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({ui, layoutengine}, output);
    return output;
  }
  /**
   * @function layout_from_ui_layoutengine
   * Returns the layout from layoutengine that matches the ui
   * @param  {ui} ui
   * @param  {layoutengine} layoutengine
   * @return {layout}
   * (func layout<-ui-layoutengine)
   */
  // (func layout<-ui-layoutengine)
  // class Class_layout_from_ui_layoutengine {
    Abstract_layout_from_ui_layoutengine::~Abstract_layout_from_ui_layoutengine() {}

    Class_layout_from_ui_layoutengine::Class_layout_from_ui_layoutengine() : Abstract_layout_from_ui_layoutengine::Abstract_layout_from_ui_layoutengine() {
      vx_core::refcount += 1;
    }

    Class_layout_from_ui_layoutengine::~Class_layout_from_ui_layoutengine() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_layout_from_ui_layoutengine::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_layout_from_ui_layoutengine output = vx_ui_ui::e_layout_from_ui_layoutengine;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_layout_from_ui_layoutengine::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_layout_from_ui_layoutengine output = vx_ui_ui::e_layout_from_ui_layoutengine;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_layout_from_ui_layoutengine::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "layout<-ui-layoutengine", // name
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

    vx_core::Type_constdef Class_layout_from_ui_layoutengine::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_layout_from_ui_layoutengine::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "layout<-ui-layoutengine", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_layout_from_ui_layoutengine::vx_empty() const {return vx_ui_ui::e_layout_from_ui_layoutengine;}
    vx_core::Type_any Class_layout_from_ui_layoutengine::vx_type() const {return vx_ui_ui::t_layout_from_ui_layoutengine;}
    vx_core::Type_msgblock Class_layout_from_ui_layoutengine::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_layout_from_ui_layoutengine::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_layout_from_ui_layoutengine::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_layoutengine layoutengine = vx_core::vx_any_from_any(vx_ui_ui::t_layoutengine, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_ui_ui::f_layout_from_ui_layoutengine(ui, layoutengine);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func layout<-ui-layoutmap-else)
  vx_ui_ui::Type_layout f_layout_from_ui_layoutmap_else(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_layoutmap layoutmap, vx_ui_ui::Type_layout layoutelse) {
    vx_ui_ui::Type_layout output = vx_ui_ui::e_layout;
    vx_core::vx_reserve({ui, layoutmap, layoutelse});
    output = vx_core::f_let(
      vx_ui_ui::t_layout,
      vx_core::t_any_from_func->vx_fn_new({ui, layoutmap, layoutelse}, [ui, layoutmap, layoutelse]() {
        vx_ui_ui::Type_style style = ui->style();
        vx_core::vx_ref_plus(style);
        vx_ui_ui::Type_layout layout = vx_ui_ui::f_layout_from_style(style);
        vx_core::vx_ref_plus(layout);
        vx_core::Type_string layname = layout->name();
        vx_core::vx_ref_plus(layname);
        vx_ui_ui::Type_layout layout1 = vx_core::f_any_from_map(vx_ui_ui::t_layout, layoutmap, layname);
        vx_core::vx_ref_plus(layout1);
        vx_ui_ui::Type_layout layout2 = vx_core::f_if_1(
          vx_ui_ui::t_layout,
          vx_core::f_notempty_1(layout1),
          layout1,
          layoutelse
        );
        vx_core::vx_ref_plus(layout2);
        vx_ui_ui::Type_layout output_1 = layout2;
        vx_core::vx_release_one_except({style, layout, layname, layout1, layout2}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({ui, layoutmap, layoutelse}, output);
    return output;
  }
  /**
   * @function layout_from_ui_layoutmap_else
   * Returns a layout from a given ui, layoutmap, and layoutelse
   * @param  {ui} ui
   * @param  {layoutmap} layoutmap
   * @param  {layout} layoutelse
   * @return {layout}
   * (func layout<-ui-layoutmap-else)
   */
  // (func layout<-ui-layoutmap-else)
  // class Class_layout_from_ui_layoutmap_else {
    Abstract_layout_from_ui_layoutmap_else::~Abstract_layout_from_ui_layoutmap_else() {}

    Class_layout_from_ui_layoutmap_else::Class_layout_from_ui_layoutmap_else() : Abstract_layout_from_ui_layoutmap_else::Abstract_layout_from_ui_layoutmap_else() {
      vx_core::refcount += 1;
    }

    Class_layout_from_ui_layoutmap_else::~Class_layout_from_ui_layoutmap_else() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_layout_from_ui_layoutmap_else::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_layout_from_ui_layoutmap_else output = vx_ui_ui::e_layout_from_ui_layoutmap_else;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_layout_from_ui_layoutmap_else::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_layout_from_ui_layoutmap_else output = vx_ui_ui::e_layout_from_ui_layoutmap_else;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_layout_from_ui_layoutmap_else::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "layout<-ui-layoutmap-else", // name
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

    vx_core::Type_constdef Class_layout_from_ui_layoutmap_else::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_layout_from_ui_layoutmap_else::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "layout<-ui-layoutmap-else", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_layout_from_ui_layoutmap_else::vx_empty() const {return vx_ui_ui::e_layout_from_ui_layoutmap_else;}
    vx_core::Type_any Class_layout_from_ui_layoutmap_else::vx_type() const {return vx_ui_ui::t_layout_from_ui_layoutmap_else;}
    vx_core::Type_msgblock Class_layout_from_ui_layoutmap_else::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_layout_from_ui_layoutmap_else::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_layout_from_ui_layoutmap_else::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_layoutmap layoutmap = vx_core::vx_any_from_any(vx_ui_ui::t_layoutmap, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_ui_ui::Type_layout layoutelse = vx_core::vx_any_from_any(vx_ui_ui::t_layout, arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_ui_ui::f_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func layoutengine-readstate)
  vx_ui_ui::Type_layoutengine f_layoutengine_readstate(vx_core::Type_context context) {
    vx_ui_ui::Type_layoutengine output = vx_ui_ui::e_layoutengine;
    output = vx_core::f_let(
      vx_ui_ui::t_layoutengine,
      vx_core::t_any_from_func->vx_fn_new({context}, [context]() {
        vx_ui_ui::Type_uiengine uiengine = vx_ui_ui::f_uiengine_readstate(context);
        vx_core::vx_ref_plus(uiengine);
        vx_ui_ui::Type_layoutengine output_1 = uiengine->layoutengine();
        vx_core::vx_release_one_except(uiengine, output_1);
        return output_1;
      })
    );
    return output;
  }
  /**
   * @function layoutengine_readstate
   * Returns the current layoutengine from state
   * @return {layoutengine}
   * (func layoutengine-readstate)
   */
  // (func layoutengine-readstate)
  // class Class_layoutengine_readstate {
    Abstract_layoutengine_readstate::~Abstract_layoutengine_readstate() {}

    Class_layoutengine_readstate::Class_layoutengine_readstate() : Abstract_layoutengine_readstate::Abstract_layoutengine_readstate() {
      vx_core::refcount += 1;
    }

    Class_layoutengine_readstate::~Class_layoutengine_readstate() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_layoutengine_readstate::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_layoutengine_readstate output = vx_ui_ui::e_layoutengine_readstate;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_layoutengine_readstate::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_layoutengine_readstate output = vx_ui_ui::e_layoutengine_readstate;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_layoutengine_readstate::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "layoutengine-readstate", // name
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

    vx_core::Type_constdef Class_layoutengine_readstate::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_layoutengine_readstate::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "layoutengine-readstate", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_layoutengine_readstate::vx_empty() const {return vx_ui_ui::e_layoutengine_readstate;}
    vx_core::Type_any Class_layoutengine_readstate::vx_type() const {return vx_ui_ui::t_layoutengine_readstate;}
    vx_core::Type_msgblock Class_layoutengine_readstate::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_layoutengine_readstate::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_layoutengine_readstate::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_layoutengine_readstate(context);
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
  /**
   * @function layoutmap_from_layoutlist
   * Returns an layoutmap from an layoutlist
   * @param  {layoutlist} layoutlist
   * @return {layoutmap}
   * (func layoutmap<-layoutlist)
   */
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

  // (func string-selected<-ui)
  vx_core::Type_string f_string_selected_from_ui(vx_ui_ui::Type_ui ui) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(ui);
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({ui}, [ui]() {
        vx_ui_ui::Type_ui selectedui = vx_ui_ui::f_ui_selected_from_ui(ui);
        vx_core::vx_ref_plus(selectedui);
        vx_core::Type_string output_1 = selectedui->uid();
        vx_core::vx_release_one_except(selectedui, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(ui, output);
    return output;
  }
  /**
   * @function string_selected_from_ui
   * @param  {ui} ui
   * @return {string}
   * (func string-selected<-ui)
   */
  // (func string-selected<-ui)
  // class Class_string_selected_from_ui {
    Abstract_string_selected_from_ui::~Abstract_string_selected_from_ui() {}

    Class_string_selected_from_ui::Class_string_selected_from_ui() : Abstract_string_selected_from_ui::Abstract_string_selected_from_ui() {
      vx_core::refcount += 1;
    }

    Class_string_selected_from_ui::~Class_string_selected_from_ui() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_string_selected_from_ui::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_string_selected_from_ui output = vx_ui_ui::e_string_selected_from_ui;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_string_selected_from_ui::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_string_selected_from_ui output = vx_ui_ui::e_string_selected_from_ui;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_string_selected_from_ui::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "string-selected<-ui", // name
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

    vx_core::Type_constdef Class_string_selected_from_ui::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_string_selected_from_ui::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "string-selected<-ui", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_string_selected_from_ui::vx_empty() const {return vx_ui_ui::e_string_selected_from_ui;}
    vx_core::Type_any Class_string_selected_from_ui::vx_type() const {return vx_ui_ui::t_string_selected_from_ui;}
    vx_core::Type_msgblock Class_string_selected_from_ui::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_selected_from_ui::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_string_selected_from_ui::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_string_selected_from_ui::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui inputval = vx_core::vx_any_from_any(vx_ui_ui::t_ui, val);
      output = vx_ui_ui::f_string_selected_from_ui(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_string_selected_from_ui::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_string_selected_from_ui(ui);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func stringlist-selected<-ui)
  vx_core::Type_stringlist f_stringlist_selected_from_ui(vx_ui_ui::Type_ui ui) {
    vx_core::Type_stringlist output = vx_core::e_stringlist;
    vx_core::vx_reserve(ui);
    output = vx_core::f_let(
      vx_core::t_stringlist,
      vx_core::t_any_from_func->vx_fn_new({ui}, [ui]() {
        vx_ui_ui::Type_uimap uimap = ui->uimap();
        vx_core::vx_ref_plus(uimap);
        vx_ui_ui::Type_uilist uilist = vx_ui_ui::f_uilist_from_uimap(uimap);
        vx_core::vx_ref_plus(uilist);
        vx_core::Type_stringlist output_1 = vx_core::f_list_from_list_1(
          vx_core::t_stringlist,
          uilist,
          vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any item_any) {
            vx_ui_ui::Type_ui item = vx_core::vx_any_from_any(vx_ui_ui::t_ui, item_any);
            vx_core::Type_any output_1 = 
              vx_core::f_if_1(
                vx_core::t_string,
                item->selected(),
                item->uid(),
                vx_core::vx_new_string("")
              );
            return output_1;
          })
        );
        vx_core::vx_release_one_except({uimap, uilist}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(ui, output);
    return output;
  }
  /**
   * @function stringlist_selected_from_ui
   * Return a list of uid of the ui with selected=true
   * @param  {ui} ui
   * @return {stringlist}
   * (func stringlist-selected<-ui)
   */
  // (func stringlist-selected<-ui)
  // class Class_stringlist_selected_from_ui {
    Abstract_stringlist_selected_from_ui::~Abstract_stringlist_selected_from_ui() {}

    Class_stringlist_selected_from_ui::Class_stringlist_selected_from_ui() : Abstract_stringlist_selected_from_ui::Abstract_stringlist_selected_from_ui() {
      vx_core::refcount += 1;
    }

    Class_stringlist_selected_from_ui::~Class_stringlist_selected_from_ui() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_stringlist_selected_from_ui::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_stringlist_selected_from_ui output = vx_ui_ui::e_stringlist_selected_from_ui;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_stringlist_selected_from_ui::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_stringlist_selected_from_ui output = vx_ui_ui::e_stringlist_selected_from_ui;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_stringlist_selected_from_ui::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "stringlist-selected<-ui", // name
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

    vx_core::Type_constdef Class_stringlist_selected_from_ui::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_stringlist_selected_from_ui::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "stringlist-selected<-ui", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_stringlist_selected_from_ui::vx_empty() const {return vx_ui_ui::e_stringlist_selected_from_ui;}
    vx_core::Type_any Class_stringlist_selected_from_ui::vx_type() const {return vx_ui_ui::t_stringlist_selected_from_ui;}
    vx_core::Type_msgblock Class_stringlist_selected_from_ui::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stringlist_selected_from_ui::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_stringlist_selected_from_ui::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_stringlist_selected_from_ui::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui inputval = vx_core::vx_any_from_any(vx_ui_ui::t_ui, val);
      output = vx_ui_ui::f_stringlist_selected_from_ui(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_stringlist_selected_from_ui::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_stringlist_selected_from_ui(ui);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func stringlist<-ui)
  vx_core::Type_stringlist f_stringlist_from_ui(vx_ui_ui::Type_ui ui) {
    vx_core::Type_stringlist output = vx_core::e_stringlist;
    vx_core::vx_reserve(ui);
    output = vx_core::f_let(
      vx_core::t_stringlist,
      vx_core::t_any_from_func->vx_fn_new({ui}, [ui]() {
        vx_ui_ui::Type_uimap uimap = ui->uimap();
        vx_core::vx_ref_plus(uimap);
        vx_core::Type_stringlist output_1 = vx_collection::f_stringlist_from_map(uimap);
        vx_core::vx_release_one_except(uimap, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(ui, output);
    return output;
  }
  /**
   * @function stringlist_from_ui
   * Return a list of uid of the ui with selected=true
   * @param  {ui} ui
   * @return {stringlist}
   * (func stringlist<-ui)
   */
  // (func stringlist<-ui)
  // class Class_stringlist_from_ui {
    Abstract_stringlist_from_ui::~Abstract_stringlist_from_ui() {}

    Class_stringlist_from_ui::Class_stringlist_from_ui() : Abstract_stringlist_from_ui::Abstract_stringlist_from_ui() {
      vx_core::refcount += 1;
    }

    Class_stringlist_from_ui::~Class_stringlist_from_ui() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_stringlist_from_ui::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_stringlist_from_ui output = vx_ui_ui::e_stringlist_from_ui;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_stringlist_from_ui::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_stringlist_from_ui output = vx_ui_ui::e_stringlist_from_ui;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_stringlist_from_ui::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "stringlist<-ui", // name
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

    vx_core::Type_constdef Class_stringlist_from_ui::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_stringlist_from_ui::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "stringlist<-ui", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_stringlist_from_ui::vx_empty() const {return vx_ui_ui::e_stringlist_from_ui;}
    vx_core::Type_any Class_stringlist_from_ui::vx_type() const {return vx_ui_ui::t_stringlist_from_ui;}
    vx_core::Type_msgblock Class_stringlist_from_ui::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stringlist_from_ui::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_stringlist_from_ui::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_stringlist_from_ui::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui inputval = vx_core::vx_any_from_any(vx_ui_ui::t_ui, val);
      output = vx_ui_ui::f_stringlist_from_ui(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_stringlist_from_ui::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_stringlist_from_ui(ui);
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
  /**
   * @function stylemap_from_stylelist
   * @param  {stylelist} stylelist
   * @return {stylemap}
   * (func stylemap<-stylelist)
   */
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

  // (func stylesheet-readstate)
  vx_ui_ui::Type_stylesheet f_stylesheet_readstate(vx_core::Type_context context) {
    vx_ui_ui::Type_stylesheet output = vx_ui_ui::e_stylesheet;
    output = vx_core::f_let(
      vx_ui_ui::t_stylesheet,
      vx_core::t_any_from_func->vx_fn_new({context}, [context]() {
        vx_ui_ui::Type_uiengine uiengine = vx_ui_ui::f_uiengine_readstate(context);
        vx_core::vx_ref_plus(uiengine);
        vx_ui_ui::Type_stylesheet output_1 = uiengine->stylesheet();
        vx_core::vx_release_one_except(uiengine, output_1);
        return output_1;
      })
    );
    return output;
  }
  /**
   * @function stylesheet_readstate
   * Returns the current uiengine from state
   * @return {stylesheet}
   * (func stylesheet-readstate)
   */
  // (func stylesheet-readstate)
  // class Class_stylesheet_readstate {
    Abstract_stylesheet_readstate::~Abstract_stylesheet_readstate() {}

    Class_stylesheet_readstate::Class_stylesheet_readstate() : Abstract_stylesheet_readstate::Abstract_stylesheet_readstate() {
      vx_core::refcount += 1;
    }

    Class_stylesheet_readstate::~Class_stylesheet_readstate() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_stylesheet_readstate::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_stylesheet_readstate output = vx_ui_ui::e_stylesheet_readstate;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_stylesheet_readstate::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_stylesheet_readstate output = vx_ui_ui::e_stylesheet_readstate;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_stylesheet_readstate::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "stylesheet-readstate", // name
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

    vx_core::Type_constdef Class_stylesheet_readstate::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_stylesheet_readstate::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "stylesheet-readstate", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_stylesheet_readstate::vx_empty() const {return vx_ui_ui::e_stylesheet_readstate;}
    vx_core::Type_any Class_stylesheet_readstate::vx_type() const {return vx_ui_ui::t_stylesheet_readstate;}
    vx_core::Type_msgblock Class_stylesheet_readstate::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stylesheet_readstate::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_stylesheet_readstate::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_stylesheet_readstate(context);
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
  /**
   * @function stylesheet_render
   * Template for rendering stylesheet
   * @param  {stylesheet} stylesheetui
   * @return {stylesheet}
   * (func stylesheet-render)
   */
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

  // (func ui-child<-ui-uid)
  vx_ui_ui::Type_ui f_ui_child_from_ui_uid(vx_ui_ui::Type_ui ui, vx_core::Type_string uid) {
    vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
    vx_core::vx_reserve({ui, uid});
    output = vx_core::f_let(
      vx_ui_ui::t_ui,
      vx_core::t_any_from_func->vx_fn_new({ui, uid}, [ui, uid]() {
        vx_ui_ui::Type_uimap childmap = ui->uimap();
        vx_core::vx_ref_plus(childmap);
        vx_ui_ui::Type_ui output_1 = vx_core::f_any_from_map(vx_ui_ui::t_ui, childmap, uid);
        vx_core::vx_release_one_except(childmap, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({ui, uid}, output);
    return output;
  }
  /**
   * @function ui_child_from_ui_uid
   * Returns then named child from a ui.
   * @param  {ui} ui
   * @param  {string} uid
   * @return {ui}
   * (func ui-child<-ui-uid)
   */
  // (func ui-child<-ui-uid)
  // class Class_ui_child_from_ui_uid {
    Abstract_ui_child_from_ui_uid::~Abstract_ui_child_from_ui_uid() {}

    Class_ui_child_from_ui_uid::Class_ui_child_from_ui_uid() : Abstract_ui_child_from_ui_uid::Abstract_ui_child_from_ui_uid() {
      vx_core::refcount += 1;
    }

    Class_ui_child_from_ui_uid::~Class_ui_child_from_ui_uid() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_child_from_ui_uid::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_child_from_ui_uid output = vx_ui_ui::e_ui_child_from_ui_uid;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_child_from_ui_uid::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_child_from_ui_uid output = vx_ui_ui::e_ui_child_from_ui_uid;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_child_from_ui_uid::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "ui-child<-ui-uid", // name
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

    vx_core::Type_constdef Class_ui_child_from_ui_uid::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_child_from_ui_uid::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-child<-ui-uid", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_child_from_ui_uid::vx_empty() const {return vx_ui_ui::e_ui_child_from_ui_uid;}
    vx_core::Type_any Class_ui_child_from_ui_uid::vx_type() const {return vx_ui_ui::t_ui_child_from_ui_uid;}
    vx_core::Type_msgblock Class_ui_child_from_ui_uid::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_child_from_ui_uid::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_ui_child_from_ui_uid::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string uid = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_ui_ui::f_ui_child_from_ui_uid(ui, uid);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func ui-from<-event)
  vx_ui_ui::Type_ui f_ui_from_from_event(vx_core::Type_context context, vx_event::Type_event event) {
    vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
    vx_core::vx_reserve(event);
    output = vx_core::f_let(
      vx_ui_ui::t_ui,
      vx_core::t_any_from_func->vx_fn_new({event, context}, [event, context]() {
        vx_core::Type_string uid = event->from();
        vx_core::vx_ref_plus(uid);
        vx_ui_ui::Type_ui output_1 = vx_ui_ui::f_ui_readstate_from_uid(context, uid);
        vx_core::vx_release_one_except(uid, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(event, output);
    return output;
  }
  /**
   * @function ui_from_from_event
   * Returns (:from event) cast as ui
   * @param  {event} event
   * @return {ui}
   * (func ui-from<-event)
   */
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

    vx_core::Func_any_from_any_context Class_ui_from_from_event::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_ui_from_from_event::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_event::Type_event inputval = vx_core::vx_any_from_any(vx_event::t_event, val);
      output = vx_ui_ui::f_ui_from_from_event(context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_ui_from_from_event::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_event::Type_event event = vx_core::vx_any_from_any(vx_event::t_event, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_ui_from_from_event(context, event);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func ui-layout<-ui)
  vx_ui_ui::Type_ui f_ui_layout_from_ui(vx_core::Type_context context, vx_ui_ui::Type_ui ui) {
    vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
    vx_core::vx_reserve(ui);
    output = vx_core::f_let(
      vx_ui_ui::t_ui,
      vx_core::t_any_from_func->vx_fn_new({context, ui}, [context, ui]() {
        vx_ui_ui::Type_uiengine uiengine = vx_ui_ui::f_uiengine_readstate(context);
        vx_core::vx_ref_plus(uiengine);
        vx_ui_ui::Type_ui output_1 = vx_ui_ui::f_ui_layout_from_ui_uiengine(ui, uiengine);
        vx_core::vx_release_one_except(uiengine, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(ui, output);
    return output;
  }
  /**
   * @function ui_layout_from_ui
   * Returns a ui with a layout added to each ui.
   * @param  {ui} ui
   * @return {ui}
   * (func ui-layout<-ui)
   */
  // (func ui-layout<-ui)
  // class Class_ui_layout_from_ui {
    Abstract_ui_layout_from_ui::~Abstract_ui_layout_from_ui() {}

    Class_ui_layout_from_ui::Class_ui_layout_from_ui() : Abstract_ui_layout_from_ui::Abstract_ui_layout_from_ui() {
      vx_core::refcount += 1;
    }

    Class_ui_layout_from_ui::~Class_ui_layout_from_ui() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_layout_from_ui::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_layout_from_ui output = vx_ui_ui::e_ui_layout_from_ui;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_layout_from_ui::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_layout_from_ui output = vx_ui_ui::e_ui_layout_from_ui;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_layout_from_ui::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-ui", // name
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

    vx_core::Type_constdef Class_ui_layout_from_ui::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_layout_from_ui::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-ui", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_layout_from_ui::vx_empty() const {return vx_ui_ui::e_ui_layout_from_ui;}
    vx_core::Type_any Class_ui_layout_from_ui::vx_type() const {return vx_ui_ui::t_ui_layout_from_ui;}
    vx_core::Type_msgblock Class_ui_layout_from_ui::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_layout_from_ui::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_ui_layout_from_ui::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_ui_layout_from_ui::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui inputval = vx_core::vx_any_from_any(vx_ui_ui::t_ui, val);
      output = vx_ui_ui::f_ui_layout_from_ui(context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_ui_layout_from_ui::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_ui_layout_from_ui(context, ui);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func ui-layout<-ui-layoutengine)
  vx_ui_ui::Type_ui f_ui_layout_from_ui_layoutengine(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_layoutengine layoutengine) {
    vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
    vx_core::vx_reserve({ui, layoutengine});
    output = vx_core::f_let(
      vx_ui_ui::t_ui,
      vx_core::t_any_from_func->vx_fn_new({layoutengine, ui}, [layoutengine, ui]() {
        vx_ui_ui::Type_layoutmap layoutmap = layoutengine->layoutmap();
        vx_core::vx_ref_plus(layoutmap);
        vx_ui_ui::Type_layout layoutelse = layoutengine->layoutelse();
        vx_core::vx_ref_plus(layoutelse);
        vx_ui_ui::Type_ui output_1 = vx_ui_ui::f_ui_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
        vx_core::vx_release_one_except({layoutmap, layoutelse}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({ui, layoutengine}, output);
    return output;
  }
  /**
   * @function ui_layout_from_ui_layoutengine
   * Returns a ui with a layout added to each ui.
   * @param  {ui} ui
   * @param  {layoutengine} layoutengine
   * @return {ui}
   * (func ui-layout<-ui-layoutengine)
   */
  // (func ui-layout<-ui-layoutengine)
  // class Class_ui_layout_from_ui_layoutengine {
    Abstract_ui_layout_from_ui_layoutengine::~Abstract_ui_layout_from_ui_layoutengine() {}

    Class_ui_layout_from_ui_layoutengine::Class_ui_layout_from_ui_layoutengine() : Abstract_ui_layout_from_ui_layoutengine::Abstract_ui_layout_from_ui_layoutengine() {
      vx_core::refcount += 1;
    }

    Class_ui_layout_from_ui_layoutengine::~Class_ui_layout_from_ui_layoutengine() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_layout_from_ui_layoutengine::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_layout_from_ui_layoutengine output = vx_ui_ui::e_ui_layout_from_ui_layoutengine;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_layout_from_ui_layoutengine::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_layout_from_ui_layoutengine output = vx_ui_ui::e_ui_layout_from_ui_layoutengine;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_layout_from_ui_layoutengine::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-ui-layoutengine", // name
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

    vx_core::Type_constdef Class_ui_layout_from_ui_layoutengine::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_layout_from_ui_layoutengine::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-ui-layoutengine", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_layout_from_ui_layoutengine::vx_empty() const {return vx_ui_ui::e_ui_layout_from_ui_layoutengine;}
    vx_core::Type_any Class_ui_layout_from_ui_layoutengine::vx_type() const {return vx_ui_ui::t_ui_layout_from_ui_layoutengine;}
    vx_core::Type_msgblock Class_ui_layout_from_ui_layoutengine::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_layout_from_ui_layoutengine::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_ui_layout_from_ui_layoutengine::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_layoutengine layoutengine = vx_core::vx_any_from_any(vx_ui_ui::t_layoutengine, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_ui_ui::f_ui_layout_from_ui_layoutengine(ui, layoutengine);
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
        vx_ui_ui::Type_uimap uimap = ui->uimap();
        vx_core::vx_ref_plus(uimap);
        vx_ui_ui::Type_layout layout1 = vx_ui_ui::f_layout_from_ui_layoutmap_else(ui, layoutmap, layoutelse);
        vx_core::vx_ref_plus(layout1);
        vx_ui_ui::Type_uimap uimap2 = vx_ui_ui::f_uimap_layout_from_uimap_layoutmap_else(uimap, layoutmap, layoutelse);
        vx_core::vx_ref_plus(uimap2);
        vx_ui_ui::Type_ui output_1 = vx_core::f_copy(
          vx_ui_ui::t_ui,
          ui,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":layout"),
            layout1,
            vx_core::vx_new_string(":uimap"),
            uimap2
          })
        );
        vx_core::vx_release_one_except({uimap, layout1, uimap2}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({ui, layoutmap, layoutelse}, output);
    return output;
  }
  /**
   * @function ui_layout_from_ui_layoutmap_else
   * Returns a ui with a layout added to each ui.
   * @param  {ui} ui
   * @param  {layoutmap} layoutmap
   * @param  {layout} layoutelse
   * @return {ui}
   * (func ui-layout<-ui-layoutmap-else)
   */
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

  // (func ui-layout<-ui-uiengine)
  vx_ui_ui::Type_ui f_ui_layout_from_ui_uiengine(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_uiengine uiengine) {
    vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
    vx_core::vx_reserve({ui, uiengine});
    output = vx_core::f_let(
      vx_ui_ui::t_ui,
      vx_core::t_any_from_func->vx_fn_new({uiengine, ui}, [uiengine, ui]() {
        vx_ui_ui::Type_layoutengine layoutengine = uiengine->layoutengine();
        vx_core::vx_ref_plus(layoutengine);
        vx_ui_ui::Type_ui output_1 = vx_ui_ui::f_ui_layout_from_ui_layoutengine(ui, layoutengine);
        vx_core::vx_release_one_except(layoutengine, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({ui, uiengine}, output);
    return output;
  }
  /**
   * @function ui_layout_from_ui_uiengine
   * Returns a ui with a layout added to each ui.
   * @param  {ui} ui
   * @param  {uiengine} uiengine
   * @return {ui}
   * (func ui-layout<-ui-uiengine)
   */
  // (func ui-layout<-ui-uiengine)
  // class Class_ui_layout_from_ui_uiengine {
    Abstract_ui_layout_from_ui_uiengine::~Abstract_ui_layout_from_ui_uiengine() {}

    Class_ui_layout_from_ui_uiengine::Class_ui_layout_from_ui_uiengine() : Abstract_ui_layout_from_ui_uiengine::Abstract_ui_layout_from_ui_uiengine() {
      vx_core::refcount += 1;
    }

    Class_ui_layout_from_ui_uiengine::~Class_ui_layout_from_ui_uiengine() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_layout_from_ui_uiengine::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_layout_from_ui_uiengine output = vx_ui_ui::e_ui_layout_from_ui_uiengine;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_layout_from_ui_uiengine::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_layout_from_ui_uiengine output = vx_ui_ui::e_ui_layout_from_ui_uiengine;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_layout_from_ui_uiengine::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-ui-uiengine", // name
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

    vx_core::Type_constdef Class_ui_layout_from_ui_uiengine::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_layout_from_ui_uiengine::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-layout<-ui-uiengine", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_layout_from_ui_uiengine::vx_empty() const {return vx_ui_ui::e_ui_layout_from_ui_uiengine;}
    vx_core::Type_any Class_ui_layout_from_ui_uiengine::vx_type() const {return vx_ui_ui::t_ui_layout_from_ui_uiengine;}
    vx_core::Type_msgblock Class_ui_layout_from_ui_uiengine::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_layout_from_ui_uiengine::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_ui_layout_from_ui_uiengine::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_uiengine uiengine = vx_core::vx_any_from_any(vx_ui_ui::t_uiengine, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_ui_ui::f_ui_layout_from_ui_uiengine(ui, uiengine);
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
  /**
   * @function ui_readstate_from_uid
   * Returns the named ui from state
   * @param  {string} uid
   * @return {ui}
   * (func ui-readstate<-uid)
   */
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
  /**
   * @function ui_render
   * @param  {ui} uiarg
   * @return {ui}
   * (func ui-render)
   */
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
  vx_ui_ui::Type_ui f_ui_render_from_fn_render_ui_orig_parent(vx_ui_ui::Func_ui_render_from_ui_orig_parent fn_render, vx_ui_ui::Type_ui ui, vx_ui_ui::Type_ui orig, vx_ui_ui::Type_ui parent) {
    vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
    vx_core::vx_reserve({fn_render, ui, orig, parent});
    output = vx_core::vx_any_from_func(vx_ui_ui::t_ui, fn_render, {ui, orig, parent});
    vx_core::vx_release_one_except({fn_render, ui, orig, parent}, output);
    return output;
  }
  /**
   * @function ui_render_from_fn_render_ui_orig_parent
   * Returns a rendered ui
   * @param  {ui-render<-ui-orig-parent} fn-render
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {ui}
   * (func ui-render<-fn-render-ui-orig-parent)
   */
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
                vx_ui_ui::Type_layout layout = ui->layout();
                vx_core::vx_ref_plus(layout);
                vx_ui_ui::Type_ui uiout = vx_ui_ui::f_ui_from_layout_ui_orig_parent(layout, ui, orig, parent);
                vx_core::vx_ref_plus(uiout);
                vx_ui_ui::Type_ui output_1 = uiout;
                vx_core::vx_release_one_except({uimap, layout, uiout}, output_1);
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
  /**
   * @function ui_render_from_ui_orig_parent
   * Returns a rendered object from a UI Element.
   * @param  {ui} ui
   * @param  {ui} orig
   * @param  {ui} parent
   * @return {ui}
   * (func ui-render<-ui-orig-parent)
   */
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

  // (func ui-selected<-ui)
  vx_ui_ui::Type_ui f_ui_selected_from_ui(vx_ui_ui::Type_ui ui) {
    vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
    vx_core::vx_reserve(ui);
    output = vx_core::f_let(
      vx_ui_ui::t_ui,
      vx_core::t_any_from_func->vx_fn_new({ui}, [ui]() {
        vx_ui_ui::Type_uilist uilist = vx_ui_ui::f_uilist_selected_from_ui(ui);
        vx_core::vx_ref_plus(uilist);
        vx_ui_ui::Type_ui output_1 = vx_core::f_first_from_list(vx_ui_ui::t_ui, uilist);
        vx_core::vx_release_one_except(uilist, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(ui, output);
    return output;
  }
  /**
   * @function ui_selected_from_ui
   * Returns the ui of the first ui with selected=true
   * @param  {ui} ui
   * @return {ui}
   * (func ui-selected<-ui)
   */
  // (func ui-selected<-ui)
  // class Class_ui_selected_from_ui {
    Abstract_ui_selected_from_ui::~Abstract_ui_selected_from_ui() {}

    Class_ui_selected_from_ui::Class_ui_selected_from_ui() : Abstract_ui_selected_from_ui::Abstract_ui_selected_from_ui() {
      vx_core::refcount += 1;
    }

    Class_ui_selected_from_ui::~Class_ui_selected_from_ui() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_selected_from_ui::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_selected_from_ui output = vx_ui_ui::e_ui_selected_from_ui;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_selected_from_ui::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_selected_from_ui output = vx_ui_ui::e_ui_selected_from_ui;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_selected_from_ui::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "ui-selected<-ui", // name
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

    vx_core::Type_constdef Class_ui_selected_from_ui::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_selected_from_ui::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-selected<-ui", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_selected_from_ui::vx_empty() const {return vx_ui_ui::e_ui_selected_from_ui;}
    vx_core::Type_any Class_ui_selected_from_ui::vx_type() const {return vx_ui_ui::t_ui_selected_from_ui;}
    vx_core::Type_msgblock Class_ui_selected_from_ui::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_selected_from_ui::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_ui_selected_from_ui::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_ui_selected_from_ui::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui inputval = vx_core::vx_any_from_any(vx_ui_ui::t_ui, val);
      output = vx_ui_ui::f_ui_selected_from_ui(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_ui_selected_from_ui::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_ui_selected_from_ui(ui);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func ui-writechild<-ui-child)
  vx_ui_ui::Type_ui f_ui_writechild_from_ui_child(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_ui child) {
    vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
    vx_core::vx_reserve({ui, child});
    output = vx_core::f_let(
      vx_ui_ui::t_ui,
      vx_core::t_any_from_func->vx_fn_new({child, ui}, [child, ui]() {
        vx_core::Type_string childid = child->uid();
        vx_core::vx_ref_plus(childid);
        vx_ui_ui::Type_uimap uimap = ui->uimap();
        vx_core::vx_ref_plus(uimap);
        vx_core::Type_boolean write = vx_core::f_boolean_write_from_map_name_value(uimap, childid, child);
        vx_core::vx_ref_plus(write);
        vx_ui_ui::Type_ui output_1 = ui;
        vx_core::vx_release_one_except({childid, uimap, write}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({ui, child}, output);
    return output;
  }
  /**
   * @function ui_writechild_from_ui_child
   * Returns the given ui with the child added to uimap
   * @param  {ui} ui
   * @param  {ui} child
   * @return {ui}
   * (func ui-writechild<-ui-child)
   */
  // (func ui-writechild<-ui-child)
  // class Class_ui_writechild_from_ui_child {
    Abstract_ui_writechild_from_ui_child::~Abstract_ui_writechild_from_ui_child() {}

    Class_ui_writechild_from_ui_child::Class_ui_writechild_from_ui_child() : Abstract_ui_writechild_from_ui_child::Abstract_ui_writechild_from_ui_child() {
      vx_core::refcount += 1;
    }

    Class_ui_writechild_from_ui_child::~Class_ui_writechild_from_ui_child() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_writechild_from_ui_child::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_writechild_from_ui_child output = vx_ui_ui::e_ui_writechild_from_ui_child;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_writechild_from_ui_child::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_writechild_from_ui_child output = vx_ui_ui::e_ui_writechild_from_ui_child;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_writechild_from_ui_child::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "ui-writechild<-ui-child", // name
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

    vx_core::Type_constdef Class_ui_writechild_from_ui_child::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_writechild_from_ui_child::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-writechild<-ui-child", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_writechild_from_ui_child::vx_empty() const {return vx_ui_ui::e_ui_writechild_from_ui_child;}
    vx_core::Type_any Class_ui_writechild_from_ui_child::vx_type() const {return vx_ui_ui::t_ui_writechild_from_ui_child;}
    vx_core::Type_msgblock Class_ui_writechild_from_ui_child::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_writechild_from_ui_child::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_ui_writechild_from_ui_child::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_ui child = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_ui_ui::f_ui_writechild_from_ui_child(ui, child);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func ui-writechildmap<-ui-childmap)
  vx_ui_ui::Type_ui f_ui_writechildmap_from_ui_childmap(vx_ui_ui::Type_ui ui, vx_ui_ui::Type_uimap childmap) {
    vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
    vx_core::vx_reserve({ui, childmap});
    output = vx_core::f_let(
      vx_ui_ui::t_ui,
      vx_core::t_any_from_func->vx_fn_new({childmap, ui}, [childmap, ui]() {
        vx_ui_ui::Type_uimap workmap = vx_core::f_map_from_map_1(
          vx_ui_ui::t_uimap,
          childmap,
          vx_core::t_any_from_key_value->vx_fn_new({ui}, [ui](vx_core::Type_any key_any, vx_core::Type_any value_any) {
            vx_core::Type_string key = vx_core::vx_any_from_any(vx_core::t_string, key_any);
            vx_ui_ui::Type_ui value = vx_core::vx_any_from_any(vx_ui_ui::t_ui, value_any);
            vx_core::Type_any output_1 = 
              vx_ui_ui::f_ui_writechild_from_ui_child(ui, value);
            return output_1;
          })
        );
        vx_core::vx_ref_plus(workmap);
        vx_ui_ui::Type_ui output_1 = ui;
        vx_core::vx_release_one_except(workmap, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({ui, childmap}, output);
    return output;
  }
  /**
   * @function ui_writechildmap_from_ui_childmap
   * Returns the given ui with the members of childmap added to uimap
   * @param  {ui} ui
   * @param  {uimap} childmap
   * @return {ui}
   * (func ui-writechildmap<-ui-childmap)
   */
  // (func ui-writechildmap<-ui-childmap)
  // class Class_ui_writechildmap_from_ui_childmap {
    Abstract_ui_writechildmap_from_ui_childmap::~Abstract_ui_writechildmap_from_ui_childmap() {}

    Class_ui_writechildmap_from_ui_childmap::Class_ui_writechildmap_from_ui_childmap() : Abstract_ui_writechildmap_from_ui_childmap::Abstract_ui_writechildmap_from_ui_childmap() {
      vx_core::refcount += 1;
    }

    Class_ui_writechildmap_from_ui_childmap::~Class_ui_writechildmap_from_ui_childmap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_writechildmap_from_ui_childmap::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_writechildmap_from_ui_childmap output = vx_ui_ui::e_ui_writechildmap_from_ui_childmap;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_writechildmap_from_ui_childmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_writechildmap_from_ui_childmap output = vx_ui_ui::e_ui_writechildmap_from_ui_childmap;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_writechildmap_from_ui_childmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "ui-writechildmap<-ui-childmap", // name
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

    vx_core::Type_constdef Class_ui_writechildmap_from_ui_childmap::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_writechildmap_from_ui_childmap::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "ui-writechildmap<-ui-childmap", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_writechildmap_from_ui_childmap::vx_empty() const {return vx_ui_ui::e_ui_writechildmap_from_ui_childmap;}
    vx_core::Type_any Class_ui_writechildmap_from_ui_childmap::vx_type() const {return vx_ui_ui::t_ui_writechildmap_from_ui_childmap;}
    vx_core::Type_msgblock Class_ui_writechildmap_from_ui_childmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_writechildmap_from_ui_childmap::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_ui_writechildmap_from_ui_childmap::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_uimap childmap = vx_core::vx_any_from_any(vx_ui_ui::t_uimap, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_ui_ui::f_ui_writechildmap_from_ui_childmap(ui, childmap);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func ui<-layout-ui-orig-parent)
  vx_ui_ui::Type_ui f_ui_from_layout_ui_orig_parent(vx_ui_ui::Type_layout layout, vx_ui_ui::Type_ui uiarg, vx_ui_ui::Type_ui uiorig, vx_ui_ui::Type_ui parent) {
    vx_ui_ui::Type_ui output = vx_ui_ui::e_ui;
    vx_core::vx_reserve({layout, uiarg, uiorig, parent});
    output = vx_core::f_let(
      vx_ui_ui::t_ui,
      vx_core::t_any_from_func->vx_fn_new({layout, uiarg, uiorig, parent}, [layout, uiarg, uiorig, parent]() {
        vx_core::Type_string name = layout->name();
        vx_core::vx_ref_plus(name);
        vx_ui_ui::Func_ui_render_from_ui_orig_parent fn_layout = layout->fn_layout();
        vx_core::vx_ref_plus(fn_layout);
        vx_ui_ui::Type_ui uichg = vx_core::vx_any_from_func(vx_ui_ui::t_ui, fn_layout, {uiarg, uiorig, parent});
        vx_core::vx_ref_plus(uichg);
        vx_ui_ui::Type_ui output_1 = uichg;
        vx_core::vx_release_one_except({name, fn_layout, uichg}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({layout, uiarg, uiorig, parent}, output);
    return output;
  }
  /**
   * @function ui_from_layout_ui_orig_parent
   * @param  {layout} layout
   * @param  {ui} uiarg
   * @param  {ui} uiorig
   * @param  {ui} parent
   * @return {ui}
   * (func ui<-layout-ui-orig-parent)
   */
  // (func ui<-layout-ui-orig-parent)
  // class Class_ui_from_layout_ui_orig_parent {
    Abstract_ui_from_layout_ui_orig_parent::~Abstract_ui_from_layout_ui_orig_parent() {}

    Class_ui_from_layout_ui_orig_parent::Class_ui_from_layout_ui_orig_parent() : Abstract_ui_from_layout_ui_orig_parent::Abstract_ui_from_layout_ui_orig_parent() {
      vx_core::refcount += 1;
    }

    Class_ui_from_layout_ui_orig_parent::~Class_ui_from_layout_ui_orig_parent() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_ui_from_layout_ui_orig_parent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_from_layout_ui_orig_parent output = vx_ui_ui::e_ui_from_layout_ui_orig_parent;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_ui_from_layout_ui_orig_parent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_ui_from_layout_ui_orig_parent output = vx_ui_ui::e_ui_from_layout_ui_orig_parent;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_ui_from_layout_ui_orig_parent::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "ui<-layout-ui-orig-parent", // name
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

    vx_core::Type_constdef Class_ui_from_layout_ui_orig_parent::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_ui_from_layout_ui_orig_parent::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "ui<-layout-ui-orig-parent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_ui_from_layout_ui_orig_parent::vx_empty() const {return vx_ui_ui::e_ui_from_layout_ui_orig_parent;}
    vx_core::Type_any Class_ui_from_layout_ui_orig_parent::vx_type() const {return vx_ui_ui::t_ui_from_layout_ui_orig_parent;}
    vx_core::Type_msgblock Class_ui_from_layout_ui_orig_parent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ui_from_layout_ui_orig_parent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_ui_from_layout_ui_orig_parent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_layout layout = vx_core::vx_any_from_any(vx_ui_ui::t_layout, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_ui_ui::Type_ui uiarg = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_ui_ui::Type_ui uiorig = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(2)));
      vx_ui_ui::Type_ui parent = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(3)));
      output = vx_ui_ui::f_ui_from_layout_ui_orig_parent(layout, uiarg, uiorig, parent);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func uid-selected<-ui)
  vx_core::Type_string f_uid_selected_from_ui(vx_ui_ui::Type_ui ui) {
    vx_core::Type_string output = vx_core::e_string;
    vx_core::vx_reserve(ui);
    output = vx_core::f_let(
      vx_core::t_string,
      vx_core::t_any_from_func->vx_fn_new({ui}, [ui]() {
        vx_core::Type_stringlist uidlist = vx_ui_ui::f_stringlist_selected_from_ui(ui);
        vx_core::vx_ref_plus(uidlist);
        vx_core::Type_string output_1 = vx_core::f_first_from_list(vx_core::t_string, uidlist);
        vx_core::vx_release_one_except(uidlist, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(ui, output);
    return output;
  }
  /**
   * @function uid_selected_from_ui
   * Returns the uid of the first ui with selected=true
   * @param  {ui} ui
   * @return {string}
   * (func uid-selected<-ui)
   */
  // (func uid-selected<-ui)
  // class Class_uid_selected_from_ui {
    Abstract_uid_selected_from_ui::~Abstract_uid_selected_from_ui() {}

    Class_uid_selected_from_ui::Class_uid_selected_from_ui() : Abstract_uid_selected_from_ui::Abstract_uid_selected_from_ui() {
      vx_core::refcount += 1;
    }

    Class_uid_selected_from_ui::~Class_uid_selected_from_ui() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_uid_selected_from_ui::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_uid_selected_from_ui output = vx_ui_ui::e_uid_selected_from_ui;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_uid_selected_from_ui::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_uid_selected_from_ui output = vx_ui_ui::e_uid_selected_from_ui;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_uid_selected_from_ui::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "uid-selected<-ui", // name
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

    vx_core::Type_constdef Class_uid_selected_from_ui::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_uid_selected_from_ui::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "uid-selected<-ui", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_uid_selected_from_ui::vx_empty() const {return vx_ui_ui::e_uid_selected_from_ui;}
    vx_core::Type_any Class_uid_selected_from_ui::vx_type() const {return vx_ui_ui::t_uid_selected_from_ui;}
    vx_core::Type_msgblock Class_uid_selected_from_ui::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_uid_selected_from_ui::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_uid_selected_from_ui::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_uid_selected_from_ui::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui inputval = vx_core::vx_any_from_any(vx_ui_ui::t_ui, val);
      output = vx_ui_ui::f_uid_selected_from_ui(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_uid_selected_from_ui::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui ui = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_uid_selected_from_ui(ui);
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
  /**
   * @function uiengine_readstate
   * Returns the current uiengine from state
   * @return {uiengine}
   * (func uiengine-readstate)
   */
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
        vx_ui_ui::Func_stylesheet_render stylesheetrender = layoutengine->stylesheetrender();
        vx_core::vx_ref_plus(stylesheetrender);
        vx_ui_ui::Type_stylesheet stylesheetrend = vx_core::vx_any_from_func(vx_ui_ui::t_stylesheet, stylesheetrender, {stylesheet});
        vx_core::vx_ref_plus(stylesheetrend);
        vx_ui_ui::Type_ui uirenderer = vx_ui_ui::f_ui_layout_from_ui_layoutengine(ui, layoutengine);
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
        vx_core::vx_release_one_except({stylesheet, ui, layoutengine, stylesheetrender, stylesheetrend, uirenderer, uirendered}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(uiengine, output);
    return output;
  }
  /**
   * @function uiengine_render
   * Returns a fully rendered ui for a given engine.
   * @param  {uiengine} uiengine
   * @return {uiengine}
   * (func uiengine-render)
   */
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

  // (func uilist-selected<-ui)
  vx_ui_ui::Type_uilist f_uilist_selected_from_ui(vx_ui_ui::Type_ui uiarg) {
    vx_ui_ui::Type_uilist output = vx_ui_ui::e_uilist;
    vx_core::vx_reserve(uiarg);
    output = vx_core::f_let(
      vx_ui_ui::t_uilist,
      vx_core::t_any_from_func->vx_fn_new({uiarg}, [uiarg]() {
        vx_ui_ui::Type_uimap uimap = uiarg->uimap();
        vx_core::vx_ref_plus(uimap);
        vx_ui_ui::Type_uilist uilist = vx_ui_ui::f_uilist_from_uimap(uimap);
        vx_core::vx_ref_plus(uilist);
        vx_ui_ui::Type_uilist output_1 = vx_core::f_list_from_list_1(
          vx_ui_ui::t_uilist,
          uilist,
          vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any item_any) {
            vx_ui_ui::Type_ui item = vx_core::vx_any_from_any(vx_ui_ui::t_ui, item_any);
            vx_core::Type_any output_1 = 
              vx_core::f_if(
                vx_ui_ui::t_ui,
                item->selected(),
                item
              );
            return output_1;
          })
        );
        vx_core::vx_release_one_except({uimap, uilist}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(uiarg, output);
    return output;
  }
  /**
   * @function uilist_selected_from_ui
   * Return a uilist of the ui with selected=true
   * @param  {ui} uiarg
   * @return {uilist}
   * (func uilist-selected<-ui)
   */
  // (func uilist-selected<-ui)
  // class Class_uilist_selected_from_ui {
    Abstract_uilist_selected_from_ui::~Abstract_uilist_selected_from_ui() {}

    Class_uilist_selected_from_ui::Class_uilist_selected_from_ui() : Abstract_uilist_selected_from_ui::Abstract_uilist_selected_from_ui() {
      vx_core::refcount += 1;
    }

    Class_uilist_selected_from_ui::~Class_uilist_selected_from_ui() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_uilist_selected_from_ui::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_uilist_selected_from_ui output = vx_ui_ui::e_uilist_selected_from_ui;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_uilist_selected_from_ui::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_uilist_selected_from_ui output = vx_ui_ui::e_uilist_selected_from_ui;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_uilist_selected_from_ui::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "uilist-selected<-ui", // name
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

    vx_core::Type_constdef Class_uilist_selected_from_ui::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_uilist_selected_from_ui::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "uilist-selected<-ui", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_uilist_selected_from_ui::vx_empty() const {return vx_ui_ui::e_uilist_selected_from_ui;}
    vx_core::Type_any Class_uilist_selected_from_ui::vx_type() const {return vx_ui_ui::t_uilist_selected_from_ui;}
    vx_core::Type_msgblock Class_uilist_selected_from_ui::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_uilist_selected_from_ui::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_uilist_selected_from_ui::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_uilist_selected_from_ui::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui inputval = vx_core::vx_any_from_any(vx_ui_ui::t_ui, val);
      output = vx_ui_ui::f_uilist_selected_from_ui(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_uilist_selected_from_ui::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_ui uiarg = vx_core::vx_any_from_any(vx_ui_ui::t_ui, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_uilist_selected_from_ui(uiarg);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func uilist<-uimap)
  vx_ui_ui::Type_uilist f_uilist_from_uimap(vx_ui_ui::Type_uimap uimap) {
    vx_ui_ui::Type_uilist output = vx_ui_ui::e_uilist;
    vx_core::vx_reserve(uimap);
    output = vx_core::f_list_from_map_1(
      vx_ui_ui::t_uilist,
      uimap,
      vx_core::t_any_from_key_value->vx_fn_new({}, [](vx_core::Type_any key_any, vx_core::Type_any item_any) {
        vx_core::Type_string key = vx_core::vx_any_from_any(vx_core::t_string, key_any);
        vx_ui_ui::Type_ui item = vx_core::vx_any_from_any(vx_ui_ui::t_ui, item_any);
        vx_core::Type_any output_1 = item;
        return output_1;
      })
    );
    vx_core::vx_release_one_except(uimap, output);
    return output;
  }
  /**
   * @function uilist_from_uimap
   * @param  {uimap} uimap
   * @return {uilist}
   * (func uilist<-uimap)
   */
  // (func uilist<-uimap)
  // class Class_uilist_from_uimap {
    Abstract_uilist_from_uimap::~Abstract_uilist_from_uimap() {}

    Class_uilist_from_uimap::Class_uilist_from_uimap() : Abstract_uilist_from_uimap::Abstract_uilist_from_uimap() {
      vx_core::refcount += 1;
    }

    Class_uilist_from_uimap::~Class_uilist_from_uimap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_uilist_from_uimap::vx_new(vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_uilist_from_uimap output = vx_ui_ui::e_uilist_from_uimap;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_uilist_from_uimap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_ui_ui::Func_uilist_from_uimap output = vx_ui_ui::e_uilist_from_uimap;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_uilist_from_uimap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/ui/ui", // pkgname
        "uilist<-uimap", // name
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

    vx_core::Type_constdef Class_uilist_from_uimap::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_uilist_from_uimap::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/ui/ui", // pkgname
        "uilist<-uimap", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_uilist_from_uimap::vx_empty() const {return vx_ui_ui::e_uilist_from_uimap;}
    vx_core::Type_any Class_uilist_from_uimap::vx_type() const {return vx_ui_ui::t_uilist_from_uimap;}
    vx_core::Type_msgblock Class_uilist_from_uimap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_uilist_from_uimap::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_uilist_from_uimap::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_uilist_from_uimap::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_uimap inputval = vx_core::vx_any_from_any(vx_ui_ui::t_uimap, val);
      output = vx_ui_ui::f_uilist_from_uimap(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_uilist_from_uimap::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_ui_ui::Type_uimap uimap = vx_core::vx_any_from_any(vx_ui_ui::t_uimap, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_ui_ui::f_uilist_from_uimap(uimap);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func uimap-layout<-uimap-layoutmap-else)
  vx_ui_ui::Type_uimap f_uimap_layout_from_uimap_layoutmap_else(vx_ui_ui::Type_uimap uimap, vx_ui_ui::Type_layoutmap layoutmap, vx_ui_ui::Type_layout layoutelse) {
    vx_ui_ui::Type_uimap output = vx_ui_ui::e_uimap;
    vx_core::vx_reserve({uimap, layoutmap, layoutelse});
    output = vx_core::f_map_from_map_1(
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
  /**
   * @function uimap_layout_from_uimap_layoutmap_else
   * Returns a uimap with a renderer added to each ui.
   * @param  {uimap} uimap
   * @param  {layoutmap} layoutmap
   * @param  {layout} layoutelse
   * @return {uimap}
   * (func uimap-layout<-uimap-layoutmap-else)
   */
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
    output = vx_core::f_map_from_map_1(
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
  /**
   * @function uimap_render_from_uimap_parent
   * Renders a uimap and returns a rendered uimap.
   * @param  {uimap} uimap
   * @param  {ui} parent
   * @return {uimap}
   * (func uimap-render<-uimap-parent)
   */
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
  /**
   * @function uimap_from_uilist
   * @param  {uilist} uilist
   * @return {uimap}
   * (func uimap<-uilist)
   */
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
  /**
   * @function uimap_from_uimap_data
   * Template for creating uimap dynamically
   * @param  {uimap} uimap
   * @param  {any} data
   * @return {uimap}
   * (func uimap<-uimap-data)
   */
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

  vx_ui_ui::Type_align e_align = NULL;
  vx_ui_ui::Type_align t_align = NULL;
  vx_ui_ui::Type_bounds e_bounds = NULL;
  vx_ui_ui::Type_bounds t_bounds = NULL;
  vx_ui_ui::Type_cursor e_cursor = NULL;
  vx_ui_ui::Type_cursor t_cursor = NULL;
  vx_ui_ui::Type_cursor_pointer e_cursor_pointer = NULL;
  vx_ui_ui::Type_cursor_pointer t_cursor_pointer = NULL;
  vx_ui_ui::Type_font e_font = NULL;
  vx_ui_ui::Type_font t_font = NULL;
  vx_ui_ui::Type_fontface e_fontface = NULL;
  vx_ui_ui::Type_fontface t_fontface = NULL;
  vx_ui_ui::Type_fontfacelist e_fontfacelist = NULL;
  vx_ui_ui::Type_fontfacelist t_fontfacelist = NULL;
  vx_ui_ui::Type_fontfacemap e_fontfacemap = NULL;
  vx_ui_ui::Type_fontfacemap t_fontfacemap = NULL;
  vx_ui_ui::Type_fontmap e_fontmap = NULL;
  vx_ui_ui::Type_fontmap t_fontmap = NULL;
  vx_ui_ui::Type_fontstyle e_fontstyle = NULL;
  vx_ui_ui::Type_fontstyle t_fontstyle = NULL;
  vx_ui_ui::Type_fontstylemap e_fontstylemap = NULL;
  vx_ui_ui::Type_fontstylemap t_fontstylemap = NULL;
  vx_ui_ui::Type_image e_image = NULL;
  vx_ui_ui::Type_image t_image = NULL;
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
  vx_ui_ui::Const_align_center c_align_center = NULL;
  vx_ui_ui::Const_align_left c_align_left = NULL;
  vx_ui_ui::Const_align_right c_align_right = NULL;
  vx_ui_ui::Const_layout_app c_layout_app = NULL;
  vx_ui_ui::Const_layout_background c_layout_background = NULL;
  vx_ui_ui::Const_layout_button c_layout_button = NULL;
  vx_ui_ui::Const_layout_combobox c_layout_combobox = NULL;
  vx_ui_ui::Const_layout_else c_layout_else = NULL;
  vx_ui_ui::Const_layout_flow_columns c_layout_flow_columns = NULL;
  vx_ui_ui::Const_layout_flow_item c_layout_flow_item = NULL;
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
  vx_ui_ui::Const_layout_titlebar c_layout_titlebar = NULL;
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
  vx_ui_ui::Func_boolean_print e_boolean_print = NULL;
  vx_ui_ui::Func_boolean_print t_boolean_print = NULL;
  vx_ui_ui::Func_boolean_writestate_from_ui e_boolean_writestate_from_ui = NULL;
  vx_ui_ui::Func_boolean_writestate_from_ui t_boolean_writestate_from_ui = NULL;
  vx_ui_ui::Func_boolean_writestate_from_uiengine e_boolean_writestate_from_uiengine = NULL;
  vx_ui_ui::Func_boolean_writestate_from_uiengine t_boolean_writestate_from_uiengine = NULL;
  vx_ui_ui::Func_fontfacemap_from_fontfacelist e_fontfacemap_from_fontfacelist = NULL;
  vx_ui_ui::Func_fontfacemap_from_fontfacelist t_fontfacemap_from_fontfacelist = NULL;
  vx_ui_ui::Func_int_selected_from_ui e_int_selected_from_ui = NULL;
  vx_ui_ui::Func_int_selected_from_ui t_int_selected_from_ui = NULL;
  vx_ui_ui::Func_layout_from_style e_layout_from_style = NULL;
  vx_ui_ui::Func_layout_from_style t_layout_from_style = NULL;
  vx_ui_ui::Func_layout_from_ui e_layout_from_ui = NULL;
  vx_ui_ui::Func_layout_from_ui t_layout_from_ui = NULL;
  vx_ui_ui::Func_layout_from_ui_layoutengine e_layout_from_ui_layoutengine = NULL;
  vx_ui_ui::Func_layout_from_ui_layoutengine t_layout_from_ui_layoutengine = NULL;
  vx_ui_ui::Func_layout_from_ui_layoutmap_else e_layout_from_ui_layoutmap_else = NULL;
  vx_ui_ui::Func_layout_from_ui_layoutmap_else t_layout_from_ui_layoutmap_else = NULL;
  vx_ui_ui::Func_layoutengine_readstate e_layoutengine_readstate = NULL;
  vx_ui_ui::Func_layoutengine_readstate t_layoutengine_readstate = NULL;
  vx_ui_ui::Func_layoutmap_from_layoutlist e_layoutmap_from_layoutlist = NULL;
  vx_ui_ui::Func_layoutmap_from_layoutlist t_layoutmap_from_layoutlist = NULL;
  vx_ui_ui::Func_string_selected_from_ui e_string_selected_from_ui = NULL;
  vx_ui_ui::Func_string_selected_from_ui t_string_selected_from_ui = NULL;
  vx_ui_ui::Func_stringlist_selected_from_ui e_stringlist_selected_from_ui = NULL;
  vx_ui_ui::Func_stringlist_selected_from_ui t_stringlist_selected_from_ui = NULL;
  vx_ui_ui::Func_stringlist_from_ui e_stringlist_from_ui = NULL;
  vx_ui_ui::Func_stringlist_from_ui t_stringlist_from_ui = NULL;
  vx_ui_ui::Func_stylemap_from_stylelist e_stylemap_from_stylelist = NULL;
  vx_ui_ui::Func_stylemap_from_stylelist t_stylemap_from_stylelist = NULL;
  vx_ui_ui::Func_stylesheet_readstate e_stylesheet_readstate = NULL;
  vx_ui_ui::Func_stylesheet_readstate t_stylesheet_readstate = NULL;
  vx_ui_ui::Func_stylesheet_render e_stylesheet_render = NULL;
  vx_ui_ui::Func_stylesheet_render t_stylesheet_render = NULL;
  vx_ui_ui::Func_ui_child_from_ui_uid e_ui_child_from_ui_uid = NULL;
  vx_ui_ui::Func_ui_child_from_ui_uid t_ui_child_from_ui_uid = NULL;
  vx_ui_ui::Func_ui_from_from_event e_ui_from_from_event = NULL;
  vx_ui_ui::Func_ui_from_from_event t_ui_from_from_event = NULL;
  vx_ui_ui::Func_ui_layout_from_ui e_ui_layout_from_ui = NULL;
  vx_ui_ui::Func_ui_layout_from_ui t_ui_layout_from_ui = NULL;
  vx_ui_ui::Func_ui_layout_from_ui_layoutengine e_ui_layout_from_ui_layoutengine = NULL;
  vx_ui_ui::Func_ui_layout_from_ui_layoutengine t_ui_layout_from_ui_layoutengine = NULL;
  vx_ui_ui::Func_ui_layout_from_ui_layoutmap_else e_ui_layout_from_ui_layoutmap_else = NULL;
  vx_ui_ui::Func_ui_layout_from_ui_layoutmap_else t_ui_layout_from_ui_layoutmap_else = NULL;
  vx_ui_ui::Func_ui_layout_from_ui_uiengine e_ui_layout_from_ui_uiengine = NULL;
  vx_ui_ui::Func_ui_layout_from_ui_uiengine t_ui_layout_from_ui_uiengine = NULL;
  vx_ui_ui::Func_ui_readstate_from_uid e_ui_readstate_from_uid = NULL;
  vx_ui_ui::Func_ui_readstate_from_uid t_ui_readstate_from_uid = NULL;
  vx_ui_ui::Func_ui_render e_ui_render = NULL;
  vx_ui_ui::Func_ui_render t_ui_render = NULL;
  vx_ui_ui::Func_ui_render_from_fn_render_ui_orig_parent e_ui_render_from_fn_render_ui_orig_parent = NULL;
  vx_ui_ui::Func_ui_render_from_fn_render_ui_orig_parent t_ui_render_from_fn_render_ui_orig_parent = NULL;
  vx_ui_ui::Func_ui_render_from_ui_orig_parent e_ui_render_from_ui_orig_parent = NULL;
  vx_ui_ui::Func_ui_render_from_ui_orig_parent t_ui_render_from_ui_orig_parent = NULL;
  vx_ui_ui::Func_ui_selected_from_ui e_ui_selected_from_ui = NULL;
  vx_ui_ui::Func_ui_selected_from_ui t_ui_selected_from_ui = NULL;
  vx_ui_ui::Func_ui_writechild_from_ui_child e_ui_writechild_from_ui_child = NULL;
  vx_ui_ui::Func_ui_writechild_from_ui_child t_ui_writechild_from_ui_child = NULL;
  vx_ui_ui::Func_ui_writechildmap_from_ui_childmap e_ui_writechildmap_from_ui_childmap = NULL;
  vx_ui_ui::Func_ui_writechildmap_from_ui_childmap t_ui_writechildmap_from_ui_childmap = NULL;
  vx_ui_ui::Func_ui_from_layout_ui_orig_parent e_ui_from_layout_ui_orig_parent = NULL;
  vx_ui_ui::Func_ui_from_layout_ui_orig_parent t_ui_from_layout_ui_orig_parent = NULL;
  vx_ui_ui::Func_uid_selected_from_ui e_uid_selected_from_ui = NULL;
  vx_ui_ui::Func_uid_selected_from_ui t_uid_selected_from_ui = NULL;
  vx_ui_ui::Func_uiengine_readstate e_uiengine_readstate = NULL;
  vx_ui_ui::Func_uiengine_readstate t_uiengine_readstate = NULL;
  vx_ui_ui::Func_uiengine_render e_uiengine_render = NULL;
  vx_ui_ui::Func_uiengine_render t_uiengine_render = NULL;
  vx_ui_ui::Func_uilist_selected_from_ui e_uilist_selected_from_ui = NULL;
  vx_ui_ui::Func_uilist_selected_from_ui t_uilist_selected_from_ui = NULL;
  vx_ui_ui::Func_uilist_from_uimap e_uilist_from_uimap = NULL;
  vx_ui_ui::Func_uilist_from_uimap t_uilist_from_uimap = NULL;
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
      vx_ui_ui::c_align_center = new vx_ui_ui::Class_align_center();
      vx_ui_ui::c_align_left = new vx_ui_ui::Class_align_left();
      vx_ui_ui::c_align_right = new vx_ui_ui::Class_align_right();
      vx_ui_ui::c_layout_app = new vx_ui_ui::Class_layout_app();
      vx_ui_ui::c_layout_background = new vx_ui_ui::Class_layout_background();
      vx_ui_ui::c_layout_button = new vx_ui_ui::Class_layout_button();
      vx_ui_ui::c_layout_combobox = new vx_ui_ui::Class_layout_combobox();
      vx_ui_ui::c_layout_else = new vx_ui_ui::Class_layout_else();
      vx_ui_ui::c_layout_flow_columns = new vx_ui_ui::Class_layout_flow_columns();
      vx_ui_ui::c_layout_flow_item = new vx_ui_ui::Class_layout_flow_item();
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
      vx_ui_ui::c_layout_titlebar = new vx_ui_ui::Class_layout_titlebar();
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
      vx_ui_ui::e_align = new Class_align();
      vx_core::vx_reserve_empty(vx_ui_ui::e_align);
      vx_ui_ui::t_align = new Class_align();
      vx_core::vx_reserve_type(vx_ui_ui::t_align);
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
      vx_ui_ui::e_font = new Class_font();
      vx_core::vx_reserve_empty(vx_ui_ui::e_font);
      vx_ui_ui::t_font = new Class_font();
      vx_core::vx_reserve_type(vx_ui_ui::t_font);
      vx_ui_ui::e_fontface = new Class_fontface();
      vx_core::vx_reserve_empty(vx_ui_ui::e_fontface);
      vx_ui_ui::t_fontface = new Class_fontface();
      vx_core::vx_reserve_type(vx_ui_ui::t_fontface);
      vx_ui_ui::e_fontfacelist = new Class_fontfacelist();
      vx_core::vx_reserve_empty(vx_ui_ui::e_fontfacelist);
      vx_ui_ui::t_fontfacelist = new Class_fontfacelist();
      vx_core::vx_reserve_type(vx_ui_ui::t_fontfacelist);
      vx_ui_ui::e_fontfacemap = new Class_fontfacemap();
      vx_core::vx_reserve_empty(vx_ui_ui::e_fontfacemap);
      vx_ui_ui::t_fontfacemap = new Class_fontfacemap();
      vx_core::vx_reserve_type(vx_ui_ui::t_fontfacemap);
      vx_ui_ui::e_fontmap = new Class_fontmap();
      vx_core::vx_reserve_empty(vx_ui_ui::e_fontmap);
      vx_ui_ui::t_fontmap = new Class_fontmap();
      vx_core::vx_reserve_type(vx_ui_ui::t_fontmap);
      vx_ui_ui::e_fontstyle = new Class_fontstyle();
      vx_core::vx_reserve_empty(vx_ui_ui::e_fontstyle);
      vx_ui_ui::t_fontstyle = new Class_fontstyle();
      vx_core::vx_reserve_type(vx_ui_ui::t_fontstyle);
      vx_ui_ui::e_fontstylemap = new Class_fontstylemap();
      vx_core::vx_reserve_empty(vx_ui_ui::e_fontstylemap);
      vx_ui_ui::t_fontstylemap = new Class_fontstylemap();
      vx_core::vx_reserve_type(vx_ui_ui::t_fontstylemap);
      vx_ui_ui::e_image = new Class_image();
      vx_core::vx_reserve_empty(vx_ui_ui::e_image);
      vx_ui_ui::t_image = new Class_image();
      vx_core::vx_reserve_type(vx_ui_ui::t_image);
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
      vx_ui_ui::e_boolean_print = new vx_ui_ui::Class_boolean_print();
      vx_core::vx_reserve_empty(vx_ui_ui::e_boolean_print);
      vx_ui_ui::t_boolean_print = new vx_ui_ui::Class_boolean_print();
      vx_core::vx_reserve_type(vx_ui_ui::t_boolean_print);
      vx_ui_ui::e_boolean_writestate_from_ui = new vx_ui_ui::Class_boolean_writestate_from_ui();
      vx_core::vx_reserve_empty(vx_ui_ui::e_boolean_writestate_from_ui);
      vx_ui_ui::t_boolean_writestate_from_ui = new vx_ui_ui::Class_boolean_writestate_from_ui();
      vx_core::vx_reserve_type(vx_ui_ui::t_boolean_writestate_from_ui);
      vx_ui_ui::e_boolean_writestate_from_uiengine = new vx_ui_ui::Class_boolean_writestate_from_uiengine();
      vx_core::vx_reserve_empty(vx_ui_ui::e_boolean_writestate_from_uiengine);
      vx_ui_ui::t_boolean_writestate_from_uiengine = new vx_ui_ui::Class_boolean_writestate_from_uiengine();
      vx_core::vx_reserve_type(vx_ui_ui::t_boolean_writestate_from_uiengine);
      vx_ui_ui::e_fontfacemap_from_fontfacelist = new vx_ui_ui::Class_fontfacemap_from_fontfacelist();
      vx_core::vx_reserve_empty(vx_ui_ui::e_fontfacemap_from_fontfacelist);
      vx_ui_ui::t_fontfacemap_from_fontfacelist = new vx_ui_ui::Class_fontfacemap_from_fontfacelist();
      vx_core::vx_reserve_type(vx_ui_ui::t_fontfacemap_from_fontfacelist);
      vx_ui_ui::e_int_selected_from_ui = new vx_ui_ui::Class_int_selected_from_ui();
      vx_core::vx_reserve_empty(vx_ui_ui::e_int_selected_from_ui);
      vx_ui_ui::t_int_selected_from_ui = new vx_ui_ui::Class_int_selected_from_ui();
      vx_core::vx_reserve_type(vx_ui_ui::t_int_selected_from_ui);
      vx_ui_ui::e_layout_from_style = new vx_ui_ui::Class_layout_from_style();
      vx_core::vx_reserve_empty(vx_ui_ui::e_layout_from_style);
      vx_ui_ui::t_layout_from_style = new vx_ui_ui::Class_layout_from_style();
      vx_core::vx_reserve_type(vx_ui_ui::t_layout_from_style);
      vx_ui_ui::e_layout_from_ui = new vx_ui_ui::Class_layout_from_ui();
      vx_core::vx_reserve_empty(vx_ui_ui::e_layout_from_ui);
      vx_ui_ui::t_layout_from_ui = new vx_ui_ui::Class_layout_from_ui();
      vx_core::vx_reserve_type(vx_ui_ui::t_layout_from_ui);
      vx_ui_ui::e_layout_from_ui_layoutengine = new vx_ui_ui::Class_layout_from_ui_layoutengine();
      vx_core::vx_reserve_empty(vx_ui_ui::e_layout_from_ui_layoutengine);
      vx_ui_ui::t_layout_from_ui_layoutengine = new vx_ui_ui::Class_layout_from_ui_layoutengine();
      vx_core::vx_reserve_type(vx_ui_ui::t_layout_from_ui_layoutengine);
      vx_ui_ui::e_layout_from_ui_layoutmap_else = new vx_ui_ui::Class_layout_from_ui_layoutmap_else();
      vx_core::vx_reserve_empty(vx_ui_ui::e_layout_from_ui_layoutmap_else);
      vx_ui_ui::t_layout_from_ui_layoutmap_else = new vx_ui_ui::Class_layout_from_ui_layoutmap_else();
      vx_core::vx_reserve_type(vx_ui_ui::t_layout_from_ui_layoutmap_else);
      vx_ui_ui::e_layoutengine_readstate = new vx_ui_ui::Class_layoutengine_readstate();
      vx_core::vx_reserve_empty(vx_ui_ui::e_layoutengine_readstate);
      vx_ui_ui::t_layoutengine_readstate = new vx_ui_ui::Class_layoutengine_readstate();
      vx_core::vx_reserve_type(vx_ui_ui::t_layoutengine_readstate);
      vx_ui_ui::e_layoutmap_from_layoutlist = new vx_ui_ui::Class_layoutmap_from_layoutlist();
      vx_core::vx_reserve_empty(vx_ui_ui::e_layoutmap_from_layoutlist);
      vx_ui_ui::t_layoutmap_from_layoutlist = new vx_ui_ui::Class_layoutmap_from_layoutlist();
      vx_core::vx_reserve_type(vx_ui_ui::t_layoutmap_from_layoutlist);
      vx_ui_ui::e_string_selected_from_ui = new vx_ui_ui::Class_string_selected_from_ui();
      vx_core::vx_reserve_empty(vx_ui_ui::e_string_selected_from_ui);
      vx_ui_ui::t_string_selected_from_ui = new vx_ui_ui::Class_string_selected_from_ui();
      vx_core::vx_reserve_type(vx_ui_ui::t_string_selected_from_ui);
      vx_ui_ui::e_stringlist_selected_from_ui = new vx_ui_ui::Class_stringlist_selected_from_ui();
      vx_core::vx_reserve_empty(vx_ui_ui::e_stringlist_selected_from_ui);
      vx_ui_ui::t_stringlist_selected_from_ui = new vx_ui_ui::Class_stringlist_selected_from_ui();
      vx_core::vx_reserve_type(vx_ui_ui::t_stringlist_selected_from_ui);
      vx_ui_ui::e_stringlist_from_ui = new vx_ui_ui::Class_stringlist_from_ui();
      vx_core::vx_reserve_empty(vx_ui_ui::e_stringlist_from_ui);
      vx_ui_ui::t_stringlist_from_ui = new vx_ui_ui::Class_stringlist_from_ui();
      vx_core::vx_reserve_type(vx_ui_ui::t_stringlist_from_ui);
      vx_ui_ui::e_stylemap_from_stylelist = new vx_ui_ui::Class_stylemap_from_stylelist();
      vx_core::vx_reserve_empty(vx_ui_ui::e_stylemap_from_stylelist);
      vx_ui_ui::t_stylemap_from_stylelist = new vx_ui_ui::Class_stylemap_from_stylelist();
      vx_core::vx_reserve_type(vx_ui_ui::t_stylemap_from_stylelist);
      vx_ui_ui::e_stylesheet_readstate = new vx_ui_ui::Class_stylesheet_readstate();
      vx_core::vx_reserve_empty(vx_ui_ui::e_stylesheet_readstate);
      vx_ui_ui::t_stylesheet_readstate = new vx_ui_ui::Class_stylesheet_readstate();
      vx_core::vx_reserve_type(vx_ui_ui::t_stylesheet_readstate);
      vx_ui_ui::e_stylesheet_render = new vx_ui_ui::Class_stylesheet_render();
      vx_core::vx_reserve_empty(vx_ui_ui::e_stylesheet_render);
      vx_ui_ui::t_stylesheet_render = new vx_ui_ui::Class_stylesheet_render();
      vx_core::vx_reserve_type(vx_ui_ui::t_stylesheet_render);
      vx_ui_ui::e_ui_child_from_ui_uid = new vx_ui_ui::Class_ui_child_from_ui_uid();
      vx_core::vx_reserve_empty(vx_ui_ui::e_ui_child_from_ui_uid);
      vx_ui_ui::t_ui_child_from_ui_uid = new vx_ui_ui::Class_ui_child_from_ui_uid();
      vx_core::vx_reserve_type(vx_ui_ui::t_ui_child_from_ui_uid);
      vx_ui_ui::e_ui_from_from_event = new vx_ui_ui::Class_ui_from_from_event();
      vx_core::vx_reserve_empty(vx_ui_ui::e_ui_from_from_event);
      vx_ui_ui::t_ui_from_from_event = new vx_ui_ui::Class_ui_from_from_event();
      vx_core::vx_reserve_type(vx_ui_ui::t_ui_from_from_event);
      vx_ui_ui::e_ui_layout_from_ui = new vx_ui_ui::Class_ui_layout_from_ui();
      vx_core::vx_reserve_empty(vx_ui_ui::e_ui_layout_from_ui);
      vx_ui_ui::t_ui_layout_from_ui = new vx_ui_ui::Class_ui_layout_from_ui();
      vx_core::vx_reserve_type(vx_ui_ui::t_ui_layout_from_ui);
      vx_ui_ui::e_ui_layout_from_ui_layoutengine = new vx_ui_ui::Class_ui_layout_from_ui_layoutengine();
      vx_core::vx_reserve_empty(vx_ui_ui::e_ui_layout_from_ui_layoutengine);
      vx_ui_ui::t_ui_layout_from_ui_layoutengine = new vx_ui_ui::Class_ui_layout_from_ui_layoutengine();
      vx_core::vx_reserve_type(vx_ui_ui::t_ui_layout_from_ui_layoutengine);
      vx_ui_ui::e_ui_layout_from_ui_layoutmap_else = new vx_ui_ui::Class_ui_layout_from_ui_layoutmap_else();
      vx_core::vx_reserve_empty(vx_ui_ui::e_ui_layout_from_ui_layoutmap_else);
      vx_ui_ui::t_ui_layout_from_ui_layoutmap_else = new vx_ui_ui::Class_ui_layout_from_ui_layoutmap_else();
      vx_core::vx_reserve_type(vx_ui_ui::t_ui_layout_from_ui_layoutmap_else);
      vx_ui_ui::e_ui_layout_from_ui_uiengine = new vx_ui_ui::Class_ui_layout_from_ui_uiengine();
      vx_core::vx_reserve_empty(vx_ui_ui::e_ui_layout_from_ui_uiengine);
      vx_ui_ui::t_ui_layout_from_ui_uiengine = new vx_ui_ui::Class_ui_layout_from_ui_uiengine();
      vx_core::vx_reserve_type(vx_ui_ui::t_ui_layout_from_ui_uiengine);
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
      vx_ui_ui::e_ui_selected_from_ui = new vx_ui_ui::Class_ui_selected_from_ui();
      vx_core::vx_reserve_empty(vx_ui_ui::e_ui_selected_from_ui);
      vx_ui_ui::t_ui_selected_from_ui = new vx_ui_ui::Class_ui_selected_from_ui();
      vx_core::vx_reserve_type(vx_ui_ui::t_ui_selected_from_ui);
      vx_ui_ui::e_ui_writechild_from_ui_child = new vx_ui_ui::Class_ui_writechild_from_ui_child();
      vx_core::vx_reserve_empty(vx_ui_ui::e_ui_writechild_from_ui_child);
      vx_ui_ui::t_ui_writechild_from_ui_child = new vx_ui_ui::Class_ui_writechild_from_ui_child();
      vx_core::vx_reserve_type(vx_ui_ui::t_ui_writechild_from_ui_child);
      vx_ui_ui::e_ui_writechildmap_from_ui_childmap = new vx_ui_ui::Class_ui_writechildmap_from_ui_childmap();
      vx_core::vx_reserve_empty(vx_ui_ui::e_ui_writechildmap_from_ui_childmap);
      vx_ui_ui::t_ui_writechildmap_from_ui_childmap = new vx_ui_ui::Class_ui_writechildmap_from_ui_childmap();
      vx_core::vx_reserve_type(vx_ui_ui::t_ui_writechildmap_from_ui_childmap);
      vx_ui_ui::e_ui_from_layout_ui_orig_parent = new vx_ui_ui::Class_ui_from_layout_ui_orig_parent();
      vx_core::vx_reserve_empty(vx_ui_ui::e_ui_from_layout_ui_orig_parent);
      vx_ui_ui::t_ui_from_layout_ui_orig_parent = new vx_ui_ui::Class_ui_from_layout_ui_orig_parent();
      vx_core::vx_reserve_type(vx_ui_ui::t_ui_from_layout_ui_orig_parent);
      vx_ui_ui::e_uid_selected_from_ui = new vx_ui_ui::Class_uid_selected_from_ui();
      vx_core::vx_reserve_empty(vx_ui_ui::e_uid_selected_from_ui);
      vx_ui_ui::t_uid_selected_from_ui = new vx_ui_ui::Class_uid_selected_from_ui();
      vx_core::vx_reserve_type(vx_ui_ui::t_uid_selected_from_ui);
      vx_ui_ui::e_uiengine_readstate = new vx_ui_ui::Class_uiengine_readstate();
      vx_core::vx_reserve_empty(vx_ui_ui::e_uiengine_readstate);
      vx_ui_ui::t_uiengine_readstate = new vx_ui_ui::Class_uiengine_readstate();
      vx_core::vx_reserve_type(vx_ui_ui::t_uiengine_readstate);
      vx_ui_ui::e_uiengine_render = new vx_ui_ui::Class_uiengine_render();
      vx_core::vx_reserve_empty(vx_ui_ui::e_uiengine_render);
      vx_ui_ui::t_uiengine_render = new vx_ui_ui::Class_uiengine_render();
      vx_core::vx_reserve_type(vx_ui_ui::t_uiengine_render);
      vx_ui_ui::e_uilist_selected_from_ui = new vx_ui_ui::Class_uilist_selected_from_ui();
      vx_core::vx_reserve_empty(vx_ui_ui::e_uilist_selected_from_ui);
      vx_ui_ui::t_uilist_selected_from_ui = new vx_ui_ui::Class_uilist_selected_from_ui();
      vx_core::vx_reserve_type(vx_ui_ui::t_uilist_selected_from_ui);
      vx_ui_ui::e_uilist_from_uimap = new vx_ui_ui::Class_uilist_from_uimap();
      vx_core::vx_reserve_empty(vx_ui_ui::e_uilist_from_uimap);
      vx_ui_ui::t_uilist_from_uimap = new vx_ui_ui::Class_uilist_from_uimap();
      vx_core::vx_reserve_type(vx_ui_ui::t_uilist_from_uimap);
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
      vx_ui_ui::Class_align_center::vx_const_new(vx_ui_ui::c_align_center);
      vx_ui_ui::Class_align_left::vx_const_new(vx_ui_ui::c_align_left);
      vx_ui_ui::Class_align_right::vx_const_new(vx_ui_ui::c_align_right);
      vx_ui_ui::Class_layout_app::vx_const_new(vx_ui_ui::c_layout_app);
      vx_ui_ui::Class_layout_background::vx_const_new(vx_ui_ui::c_layout_background);
      vx_ui_ui::Class_layout_button::vx_const_new(vx_ui_ui::c_layout_button);
      vx_ui_ui::Class_layout_combobox::vx_const_new(vx_ui_ui::c_layout_combobox);
      vx_ui_ui::Class_layout_else::vx_const_new(vx_ui_ui::c_layout_else);
      vx_ui_ui::Class_layout_flow_columns::vx_const_new(vx_ui_ui::c_layout_flow_columns);
      vx_ui_ui::Class_layout_flow_item::vx_const_new(vx_ui_ui::c_layout_flow_item);
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
      vx_ui_ui::Class_layout_titlebar::vx_const_new(vx_ui_ui::c_layout_titlebar);
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
      maptype["align"] = vx_ui_ui::t_align;
      maptype["bounds"] = vx_ui_ui::t_bounds;
      maptype["cursor"] = vx_ui_ui::t_cursor;
      maptype["cursor-pointer"] = vx_ui_ui::t_cursor_pointer;
      maptype["font"] = vx_ui_ui::t_font;
      maptype["fontface"] = vx_ui_ui::t_fontface;
      maptype["fontfacelist"] = vx_ui_ui::t_fontfacelist;
      maptype["fontfacemap"] = vx_ui_ui::t_fontfacemap;
      maptype["fontmap"] = vx_ui_ui::t_fontmap;
      maptype["fontstyle"] = vx_ui_ui::t_fontstyle;
      maptype["fontstylemap"] = vx_ui_ui::t_fontstylemap;
      maptype["image"] = vx_ui_ui::t_image;
      maptype["layout"] = vx_ui_ui::t_layout;
      maptype["layoutengine"] = vx_ui_ui::t_layoutengine;
      maptype["layoutlist"] = vx_ui_ui::t_layoutlist;
      maptype["layoutmap"] = vx_ui_ui::t_layoutmap;
      maptype["pin"] = vx_ui_ui::t_pin;
      maptype["point"] = vx_ui_ui::t_point;
      maptype["pointstyle"] = vx_ui_ui::t_pointstyle;
      maptype["style"] = vx_ui_ui::t_style;
      maptype["stylelist"] = vx_ui_ui::t_stylelist;
      maptype["stylemap"] = vx_ui_ui::t_stylemap;
      maptype["stylesheet"] = vx_ui_ui::t_stylesheet;
      maptype["styletype"] = vx_ui_ui::t_styletype;
      maptype["ui"] = vx_ui_ui::t_ui;
      maptype["uiengine"] = vx_ui_ui::t_uiengine;
      maptype["uilist"] = vx_ui_ui::t_uilist;
      maptype["uimap"] = vx_ui_ui::t_uimap;
      mapconst["align-center"] = vx_ui_ui::c_align_center;
      mapconst["align-left"] = vx_ui_ui::c_align_left;
      mapconst["align-right"] = vx_ui_ui::c_align_right;
      mapconst["layout-app"] = vx_ui_ui::c_layout_app;
      mapconst["layout-background"] = vx_ui_ui::c_layout_background;
      mapconst["layout-button"] = vx_ui_ui::c_layout_button;
      mapconst["layout-combobox"] = vx_ui_ui::c_layout_combobox;
      mapconst["layout-else"] = vx_ui_ui::c_layout_else;
      mapconst["layout-flow-columns"] = vx_ui_ui::c_layout_flow_columns;
      mapconst["layout-flow-item"] = vx_ui_ui::c_layout_flow_item;
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
      mapconst["layout-titlebar"] = vx_ui_ui::c_layout_titlebar;
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
      mapfunc["boolean-print"] = vx_ui_ui::t_boolean_print;
      mapfunc["boolean-writestate<-ui"] = vx_ui_ui::t_boolean_writestate_from_ui;
      mapfunc["boolean-writestate<-uiengine"] = vx_ui_ui::t_boolean_writestate_from_uiengine;
      mapfunc["fontfacemap<-fontfacelist"] = vx_ui_ui::t_fontfacemap_from_fontfacelist;
      mapfunc["int-selected<-ui"] = vx_ui_ui::t_int_selected_from_ui;
      mapfunc["layout<-style"] = vx_ui_ui::t_layout_from_style;
      mapfunc["layout<-ui"] = vx_ui_ui::t_layout_from_ui;
      mapfunc["layout<-ui-layoutengine"] = vx_ui_ui::t_layout_from_ui_layoutengine;
      mapfunc["layout<-ui-layoutmap-else"] = vx_ui_ui::t_layout_from_ui_layoutmap_else;
      mapfunc["layoutengine-readstate"] = vx_ui_ui::t_layoutengine_readstate;
      mapfunc["layoutmap<-layoutlist"] = vx_ui_ui::t_layoutmap_from_layoutlist;
      mapfunc["string-selected<-ui"] = vx_ui_ui::t_string_selected_from_ui;
      mapfunc["stringlist-selected<-ui"] = vx_ui_ui::t_stringlist_selected_from_ui;
      mapfunc["stringlist<-ui"] = vx_ui_ui::t_stringlist_from_ui;
      mapfunc["stylemap<-stylelist"] = vx_ui_ui::t_stylemap_from_stylelist;
      mapfunc["stylesheet-readstate"] = vx_ui_ui::t_stylesheet_readstate;
      mapfunc["stylesheet-render"] = vx_ui_ui::t_stylesheet_render;
      mapfunc["ui-child<-ui-uid"] = vx_ui_ui::t_ui_child_from_ui_uid;
      mapfunc["ui-from<-event"] = vx_ui_ui::t_ui_from_from_event;
      mapfunc["ui-layout<-ui"] = vx_ui_ui::t_ui_layout_from_ui;
      mapfunc["ui-layout<-ui-layoutengine"] = vx_ui_ui::t_ui_layout_from_ui_layoutengine;
      mapfunc["ui-layout<-ui-layoutmap-else"] = vx_ui_ui::t_ui_layout_from_ui_layoutmap_else;
      mapfunc["ui-layout<-ui-uiengine"] = vx_ui_ui::t_ui_layout_from_ui_uiengine;
      mapfunc["ui-readstate<-uid"] = vx_ui_ui::t_ui_readstate_from_uid;
      mapfunc["ui-render"] = vx_ui_ui::t_ui_render;
      mapfunc["ui-render<-fn-render-ui-orig-parent"] = vx_ui_ui::t_ui_render_from_fn_render_ui_orig_parent;
      mapfunc["ui-render<-ui-orig-parent"] = vx_ui_ui::t_ui_render_from_ui_orig_parent;
      mapfunc["ui-selected<-ui"] = vx_ui_ui::t_ui_selected_from_ui;
      mapfunc["ui-writechild<-ui-child"] = vx_ui_ui::t_ui_writechild_from_ui_child;
      mapfunc["ui-writechildmap<-ui-childmap"] = vx_ui_ui::t_ui_writechildmap_from_ui_childmap;
      mapfunc["ui<-layout-ui-orig-parent"] = vx_ui_ui::t_ui_from_layout_ui_orig_parent;
      mapfunc["uid-selected<-ui"] = vx_ui_ui::t_uid_selected_from_ui;
      mapfunc["uiengine-readstate"] = vx_ui_ui::t_uiengine_readstate;
      mapfunc["uiengine-render"] = vx_ui_ui::t_uiengine_render;
      mapfunc["uilist-selected<-ui"] = vx_ui_ui::t_uilist_selected_from_ui;
      mapfunc["uilist<-uimap"] = vx_ui_ui::t_uilist_from_uimap;
      mapfunc["uimap-layout<-uimap-layoutmap-else"] = vx_ui_ui::t_uimap_layout_from_uimap_layoutmap_else;
      mapfunc["uimap-render<-uimap-parent"] = vx_ui_ui::t_uimap_render_from_uimap_parent;
      mapfunc["uimap<-uilist"] = vx_ui_ui::t_uimap_from_uilist;
      mapfunc["uimap<-uimap-data"] = vx_ui_ui::t_uimap_from_uimap_data;
      vx_core::vx_global_package_set("vx/ui/ui", maptype, mapconst, mapfunc);
	   }
  // }

}
