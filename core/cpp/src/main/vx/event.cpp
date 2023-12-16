#include <string>
#include "../vx/core.hpp"
#include "event.hpp"

namespace vx_event {


  // (type event)
  // class Class_event {
    Abstract_event::~Abstract_event() {}

    Class_event::Class_event() : Abstract_event::Abstract_event() {
      vx_core::refcount += 1;
    }

    Class_event::~Class_event() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_name,
        this->vx_p_from,
        this->vx_p_to,
        this->vx_p_fn_any_from_any,
        this->vx_p_fn_any_from_from_to
      });
    }

    // name()
    vx_core::Type_string Class_event::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (!output) {
        output = vx_core::e_string;
      }
      return output;
    }

    // from()
    vx_core::Type_any Class_event::from() const {
      vx_core::Type_any output = this->vx_p_from;
      if (!output) {
        output = vx_core::e_any;
      }
      return output;
    }

    // to()
    vx_core::Type_any Class_event::to() const {
      vx_core::Type_any output = this->vx_p_to;
      if (!output) {
        output = vx_core::e_any;
      }
      return output;
    }

    // fn_any_from_any()
    vx_core::Func_any_from_any Class_event::fn_any_from_any() const {
      vx_core::Func_any_from_any output = this->vx_p_fn_any_from_any;
      if (!output) {
        output = vx_core::e_any_from_any;
      }
      return output;
    }

    // fn_any_from_from_to()
    vx_event::Func_any_from_from_to Class_event::fn_any_from_from_to() const {
      vx_event::Func_any_from_from_to output = this->vx_p_fn_any_from_from_to;
      if (!output) {
        output = vx_event::e_any_from_from_to;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_event::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":from") {
        output = this->from();
      } else if (skey == ":to") {
        output = this->to();
      } else if (skey == ":fn-any<-any") {
        output = this->fn_any_from_any();
      } else if (skey == ":fn-any<-from-to") {
        output = this->fn_any_from_from_to();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_event::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":name"] = this->name();
      output[":from"] = this->from();
      output[":to"] = this->to();
      output[":fn-any<-any"] = this->fn_any_from_any();
      output[":fn-any<-from-to"] = this->fn_any_from_from_to();
      return output;
    }

    vx_core::Type_any Class_event::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_event::e_event, vals);
    }

    vx_core::Type_any Class_event::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_event::Type_event output = vx_event::e_event;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_event::Type_event val = vx_core::vx_any_from_any(vx_event::t_event, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_name = val->name();
      vx_core::Type_any vx_p_from = val->from();
      vx_core::Type_any vx_p_to = val->to();
      vx_core::Func_any_from_any vx_p_fn_any_from_any = val->fn_any_from_any();
      vx_event::Func_any_from_from_to vx_p_fn_any_from_from_to = val->fn_any_from_from_to();
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
          } else if (testkey == ":from") {
            key = testkey;
          } else if (testkey == ":to") {
            key = testkey;
          } else if (testkey == ":fn-any<-any") {
            key = testkey;
          } else if (testkey == ":fn-any<-from-to") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new event) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
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
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new event :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":from") {
            if (vx_p_from != valsub) {
              ischanged = true;
              vx_p_from = valsub;
            }
          } else if (key == ":to") {
            if (vx_p_to != valsub) {
              ischanged = true;
              vx_p_to = valsub;
            }
          } else if (key == ":fn-any<-any") {
            if (vx_p_fn_any_from_any == valsub) {
            } else if (valsubtype == vx_core::t_any_from_any) {
              ischanged = true;
              vx_p_fn_any_from_any = vx_core::vx_any_from_any(vx_core::t_any_from_any, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new event :fn-any<-any " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":fn-any<-from-to") {
            if (vx_p_fn_any_from_from_to == valsub) {
            } else if (valsubtype == vx_event::t_any_from_from_to) {
              ischanged = true;
              vx_p_fn_any_from_from_to = vx_core::vx_any_from_any(vx_event::t_any_from_from_to, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new event :fn-any<-from-to " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new event) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_event::Class_event();
        if (output->vx_p_name != vx_p_name) {
          if (output->vx_p_name) {
            vx_core::vx_release_one(output->vx_p_name);
          }
          output->vx_p_name = vx_p_name;
          vx_core::vx_reserve(vx_p_name);
        }
        if (output->vx_p_from != vx_p_from) {
          if (output->vx_p_from) {
            vx_core::vx_release_one(output->vx_p_from);
          }
          output->vx_p_from = vx_p_from;
          vx_core::vx_reserve(vx_p_from);
        }
        if (output->vx_p_to != vx_p_to) {
          if (output->vx_p_to) {
            vx_core::vx_release_one(output->vx_p_to);
          }
          output->vx_p_to = vx_p_to;
          vx_core::vx_reserve(vx_p_to);
        }
        if (output->vx_p_fn_any_from_any != vx_p_fn_any_from_any) {
          if (output->vx_p_fn_any_from_any) {
            vx_core::vx_release_one(output->vx_p_fn_any_from_any);
          }
          output->vx_p_fn_any_from_any = vx_p_fn_any_from_any;
          vx_core::vx_reserve(vx_p_fn_any_from_any);
        }
        if (output->vx_p_fn_any_from_from_to != vx_p_fn_any_from_from_to) {
          if (output->vx_p_fn_any_from_from_to) {
            vx_core::vx_release_one(output->vx_p_fn_any_from_from_to);
          }
          output->vx_p_fn_any_from_from_to = vx_p_fn_any_from_from_to;
          vx_core::vx_reserve(vx_p_fn_any_from_from_to);
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

    vx_core::Type_msgblock Class_event::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_event::Class_event::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_event::vx_empty() const {return vx_event::e_event;}
    vx_core::Type_any Class_event::vx_type() const {return vx_event::t_event;}

    vx_core::Type_typedef Class_event::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/event", // pkgname
        "event", // name
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
            "from", // name
            vx_core::t_any // type
          ),
          vx_core::vx_new_arg(
            "to", // name
            vx_core::t_any // type
          ),
          vx_core::vx_new_arg(
            "fn-any<-any", // name
            vx_core::t_any_from_any // type
          ),
          vx_core::vx_new_arg(
            "fn-any<-from-to", // name
            vx_event::t_any_from_from_to // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_event::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (const event-click)
  // class Class_event_click {
    // vx_const_new()
    void vx_event::Class_event_click::vx_const_new(vx_event::Const_event_click output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/event", "event-click");
      long irefcount = vx_core::refcount;
      vx_event::Type_event val = vx_core::f_new(
        vx_event::t_event,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string(":click")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_from = val->from();
      vx_core::vx_reserve(output->vx_p_from);
      output->vx_p_to = val->to();
      vx_core::vx_reserve(output->vx_p_to);
      output->vx_p_fn_any_from_any = val->fn_any_from_any();
      vx_core::vx_reserve(output->vx_p_fn_any_from_any);
      output->vx_p_fn_any_from_from_to = val->fn_any_from_from_to();
      vx_core::vx_reserve(output->vx_p_fn_any_from_from_to);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const event-move)
  // class Class_event_move {
    // vx_const_new()
    void vx_event::Class_event_move::vx_const_new(vx_event::Const_event_move output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/event", "event-move");
      long irefcount = vx_core::refcount;
      vx_event::Type_event val = vx_core::f_new(
        vx_event::t_event,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string(":move")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_from = val->from();
      vx_core::vx_reserve(output->vx_p_from);
      output->vx_p_to = val->to();
      vx_core::vx_reserve(output->vx_p_to);
      output->vx_p_fn_any_from_any = val->fn_any_from_any();
      vx_core::vx_reserve(output->vx_p_fn_any_from_any);
      output->vx_p_fn_any_from_from_to = val->fn_any_from_from_to();
      vx_core::vx_reserve(output->vx_p_fn_any_from_from_to);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (func any<-from-to)
  // class Class_any_from_from_to {
    Abstract_any_from_from_to::~Abstract_any_from_from_to() {}

    Class_any_from_from_to::Class_any_from_from_to() : Abstract_any_from_from_to::Abstract_any_from_from_to() {
      vx_core::refcount += 1;
    }

    Class_any_from_from_to::~Class_any_from_from_to() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_any_from_from_to::vx_new(vx_core::vx_Type_listany vals) const {
      vx_event::Func_any_from_from_to output = vx_event::e_any_from_from_to;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_any_from_from_to::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_event::Func_any_from_from_to output = vx_event::e_any_from_from_to;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_any_from_from_to::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/event", // pkgname
        "any<-from-to", // name
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

    vx_core::Type_constdef Class_any_from_from_to::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_any_from_from_to::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/event", // pkgname
        "any<-from-to", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_any_from_from_to::vx_empty() const {return vx_event::e_any_from_from_to;}
    vx_core::Type_any Class_any_from_from_to::vx_type() const {return vx_event::t_any_from_from_to;}
    vx_core::Type_msgblock Class_any_from_from_to::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_from_to::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_any_from_from_to::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any from = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any to = vx_core::vx_any_from_any(vx_core::t_any, arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_event::f_any_from_from_to(generic_any_1, from, to);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_event::Type_event e_event = NULL;
  vx_event::Type_event t_event = NULL;
  vx_event::Const_event_click c_event_click = NULL;
  vx_event::Const_event_move c_event_move = NULL;
  vx_event::Func_any_from_from_to e_any_from_from_to = NULL;
  vx_event::Func_any_from_from_to t_any_from_from_to = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_event::c_event_click = new vx_event::Class_event_click();
      vx_event::c_event_move = new vx_event::Class_event_move();
      vx_event::e_event = new Class_event();
      vx_core::vx_reserve_empty(vx_event::e_event);
      vx_event::t_event = new Class_event();
      vx_core::vx_reserve_type(vx_event::t_event);
      vx_event::e_any_from_from_to = new vx_event::Class_any_from_from_to();
      vx_core::vx_reserve_empty(vx_event::e_any_from_from_to);
      vx_event::t_any_from_from_to = new vx_event::Class_any_from_from_to();
      vx_core::vx_reserve_type(vx_event::t_any_from_from_to);
      vx_event::Class_event_click::vx_const_new(vx_event::c_event_click);
      vx_event::Class_event_move::vx_const_new(vx_event::c_event_move);
      vx_core::vx_Type_mapany maptype;
      vx_core::vx_Type_mapany mapconst;
      vx_core::vx_Type_mapfunc mapfunc;
      vx_core::vx_Type_mapany mapempty;
      maptype["event"] = vx_event::t_event;
      mapconst["event-click"] = vx_event::c_event_click;
      mapconst["event-move"] = vx_event::c_event_move;
      mapfunc["any<-from-to"] = vx_event::t_any_from_from_to;
      vx_core::vx_global_package_set("vx/event", maptype, mapconst, mapfunc);
	   }
  // }

}
