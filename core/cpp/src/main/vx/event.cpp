#include <map>
#include <string>
#include <vector>
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
        this->vx_p_datamap,
        this->vx_p_event_from_event
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

    // datamap()
    vx_core::Type_anymap Class_event::datamap() const {
      vx_core::Type_anymap output = this->vx_p_datamap;
      if (!output) {
        output = vx_core::e_anymap;
      }
      return output;
    }

    // event_from_event()
    vx_event::Func_event_from_event Class_event::event_from_event() const {
      vx_event::Func_event_from_event output = this->vx_p_event_from_event;
      if (!output) {
        output = vx_event::e_event_from_event;
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
      } else if (skey == ":datamap") {
        output = this->datamap();
      } else if (skey == ":event<-event") {
        output = this->event_from_event();
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
      output[":datamap"] = this->datamap();
      output[":event<-event"] = this->event_from_event();
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
      vx_core::Type_anymap vx_p_datamap = val->datamap();
      vx_event::Func_event_from_event vx_p_event_from_event = val->event_from_event();
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
          } else if (testkey == ":datamap") {
            key = testkey;
          } else if (testkey == ":event<-event") {
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
          } else if (key == ":datamap") {
            if (vx_p_datamap == valsub) {
            } else if (valsubtype == vx_core::t_anymap) {
              ischanged = true;
              vx_p_datamap = vx_core::vx_any_from_any(vx_core::t_anymap, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new event :datamap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":event<-event") {
            if (vx_p_event_from_event == valsub) {
            } else if (valsubtype == vx_event::t_event_from_event) {
              ischanged = true;
              vx_p_event_from_event = vx_core::vx_any_from_any(vx_event::t_event_from_event, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new event :event<-event " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
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
        if (output->vx_p_datamap != vx_p_datamap) {
          if (output->vx_p_datamap) {
            vx_core::vx_release_one(output->vx_p_datamap);
          }
          output->vx_p_datamap = vx_p_datamap;
          vx_core::vx_reserve(vx_p_datamap);
        }
        if (output->vx_p_event_from_event != vx_p_event_from_event) {
          if (output->vx_p_event_from_event) {
            vx_core::vx_release_one(output->vx_p_event_from_event);
          }
          output->vx_p_event_from_event = vx_p_event_from_event;
          vx_core::vx_reserve(vx_p_event_from_event);
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
            "datamap", // name
            vx_core::t_anymap // type
          ),
          vx_core::vx_new_arg(
            "event<-event", // name
            vx_event::t_event_from_event // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_event::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type eventlist)
  // class Class_eventlist {
    Abstract_eventlist::~Abstract_eventlist() {}

    Class_eventlist::Class_eventlist() : Abstract_eventlist::Abstract_eventlist() {
      vx_core::refcount += 1;
    }

    Class_eventlist::~Class_eventlist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_eventlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_event::Type_event Class_eventlist::vx_get_event(vx_core::Type_int index) const {
      vx_event::Type_event output = vx_event::e_event;
      long iindex = index->vx_int();
      std::vector<vx_event::Type_event> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_event::Type_event> Class_eventlist::vx_listevent() const {return vx_p_list;}

    vx_core::Type_any vx_event::Class_eventlist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_event(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_eventlist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_event::Type_eventlist output = vx_event::e_eventlist;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_event::Type_event> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_event::t_event) {
          vx_event::Type_event castval = vx_core::vx_any_from_any(vx_event::t_event, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_event::t_event)) {
          vx_event::Type_event castval = vx_core::vx_any_from_any(vx_event::t_event, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(eventlist) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_event::Class_eventlist();
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

    vx_core::Type_any Class_eventlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_event::e_eventlist, vals);
    }

    vx_core::Type_any Class_eventlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_event::Type_eventlist output = vx_event::e_eventlist;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_event::Type_eventlist val = vx_core::vx_any_from_any(vx_event::t_eventlist, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_event::Type_event> listval = val->vx_listevent();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_event::t_event) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_event::t_event, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_event::t_event)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_event::t_event, valsub));
        } else if (valsubtype == vx_event::t_eventlist) {
          ischanged = true;
          vx_event::Type_eventlist multi = vx_core::vx_any_from_any(vx_event::t_eventlist, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listevent());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new eventlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_event::Class_eventlist();
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

    vx_core::Type_msgblock Class_eventlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_event::Class_eventlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_eventlist::vx_empty() const {return vx_event::e_eventlist;}
    vx_core::Type_any Class_eventlist::vx_type() const {return vx_event::t_eventlist;}

    vx_core::Type_typedef Class_eventlist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/event", // pkgname
        "eventlist", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_event::t_event}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_eventlist::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type eventmap)
  // class Class_eventmap {
    Abstract_eventmap::~Abstract_eventmap() {}

    Class_eventmap::Class_eventmap() : Abstract_eventmap::Abstract_eventmap() {
      vx_core::refcount += 1;
    }

    Class_eventmap::~Class_eventmap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (auto const& [key, val] : this->vx_p_map) {
        vx_core::vx_release_one(val);
      }
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_eventmap::vx_map() const {
      vx_core::vx_Type_mapany output = vx_core::vx_map_from_map(vx_core::t_any, this->vx_p_map);
      return output;
    }

    // vx_get_event(key)
    vx_event::Type_event Class_eventmap::vx_get_event(vx_core::Type_string key) const {
      vx_event::Type_event output = vx_event::e_event;
      const vx_event::Class_eventmap* map = this;
      std::string skey = key->vx_string();
      if (vx_core::vx_boolean_from_string_starts(skey, ":")) {
        skey = vx_core::vx_string_from_string_start(skey, 2);
      }
      std::map<std::string, vx_event::Type_event> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_event::e_event);
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_eventmap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_event(key);
    }

    // vx_mapevent()
    std::map<std::string, vx_event::Type_event> Class_eventmap::vx_mapevent() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_eventmap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_event::Type_eventmap output = vx_event::e_eventmap;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_event::Type_event> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_event::t_event) {
          vx_event::Type_event castval = vx_core::vx_any_from_any(vx_event::t_event, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(eventmap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((map.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_event::Class_eventmap();
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

    vx_core::Type_any Class_eventmap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_event::e_eventmap, vals);
    }

    vx_core::Type_any Class_eventmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_event::Type_eventmap output = vx_event::e_eventmap;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_event::Type_eventmap valmap = vx_core::vx_any_from_any(vx_event::t_eventmap, copyval);
      output = valmap;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_event::Type_event> mapval = valmap->vx_mapevent();
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
          vx_event::Type_event valany = NULL;
          if (valsubtype == vx_event::t_event) {
            valany = vx_core::vx_any_from_any(vx_event::t_event, valsub);
          } else if (valsubtype == vx_event::t_event) {
            valany = vx_core::vx_any_from_any(vx_event::t_event, valsub);
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
        output = new vx_event::Class_eventmap();
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

    vx_core::Type_msgblock Class_eventmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_event::Class_eventmap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_eventmap::vx_empty() const {return vx_event::e_eventmap;}
    vx_core::Type_any Class_eventmap::vx_type() const {return vx_event::t_eventmap;}

    vx_core::Type_typedef Class_eventmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/event", // pkgname
        "eventmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_event::t_event}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_eventmap::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (const event-change)
  // class Class_event_change {
    // vx_const_new()
    void vx_event::Class_event_change::vx_const_new(vx_event::Const_event_change output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/event", "event-change");
      long irefcount = vx_core::refcount;
      vx_event::Type_event val = vx_core::f_new(
        vx_event::t_event,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("change")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_from = val->from();
      vx_core::vx_reserve(output->vx_p_from);
      output->vx_p_to = val->to();
      vx_core::vx_reserve(output->vx_p_to);
      output->vx_p_datamap = val->datamap();
      vx_core::vx_reserve(output->vx_p_datamap);
      output->vx_p_event_from_event = val->event_from_event();
      vx_core::vx_reserve(output->vx_p_event_from_event);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


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
          vx_core::vx_new_string("click")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_from = val->from();
      vx_core::vx_reserve(output->vx_p_from);
      output->vx_p_to = val->to();
      vx_core::vx_reserve(output->vx_p_to);
      output->vx_p_datamap = val->datamap();
      vx_core::vx_reserve(output->vx_p_datamap);
      output->vx_p_event_from_event = val->event_from_event();
      vx_core::vx_reserve(output->vx_p_event_from_event);
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
          vx_core::vx_new_string("move")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_from = val->from();
      vx_core::vx_reserve(output->vx_p_from);
      output->vx_p_to = val->to();
      vx_core::vx_reserve(output->vx_p_to);
      output->vx_p_datamap = val->datamap();
      vx_core::vx_reserve(output->vx_p_datamap);
      output->vx_p_event_from_event = val->event_from_event();
      vx_core::vx_reserve(output->vx_p_event_from_event);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (const event-select)
  // class Class_event_select {
    // vx_const_new()
    void vx_event::Class_event_select::vx_const_new(vx_event::Const_event_select output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/event", "event-select");
      long irefcount = vx_core::refcount;
      vx_event::Type_event val = vx_core::f_new(
        vx_event::t_event,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("move")
        })
      );
      output->vx_p_name = val->name();
      vx_core::vx_reserve(output->vx_p_name);
      output->vx_p_from = val->from();
      vx_core::vx_reserve(output->vx_p_from);
      output->vx_p_to = val->to();
      vx_core::vx_reserve(output->vx_p_to);
      output->vx_p_datamap = val->datamap();
      vx_core::vx_reserve(output->vx_p_datamap);
      output->vx_p_event_from_event = val->event_from_event();
      vx_core::vx_reserve(output->vx_p_event_from_event);
      vx_core::vx_release(val);
      vx_core::refcount = irefcount;
      vx_core::vx_reserve_type(output);
    }


  //}

  // (func event<-event)
  vx_event::Type_event f_event_from_event(vx_event::Type_event event) {
    vx_event::Type_event output = vx_event::e_event;
    vx_core::vx_reserve(event);
    output = event;
    vx_core::vx_release_one_except(event, output);
    return output;
  }

  // (func event<-event)
  // class Class_event_from_event {
    Abstract_event_from_event::~Abstract_event_from_event() {}

    Class_event_from_event::Class_event_from_event() : Abstract_event_from_event::Abstract_event_from_event() {
      vx_core::refcount += 1;
    }

    Class_event_from_event::~Class_event_from_event() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_event_from_event::vx_new(vx_core::vx_Type_listany vals) const {
      vx_event::Func_event_from_event output = vx_event::e_event_from_event;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_event_from_event::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_event::Func_event_from_event output = vx_event::e_event_from_event;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_event_from_event::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/event", // pkgname
        "event<-event", // name
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

    vx_core::Type_constdef Class_event_from_event::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_event_from_event::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/event", // pkgname
        "event<-event", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_event_from_event::vx_empty() const {return vx_event::e_event_from_event;}
    vx_core::Type_any Class_event_from_event::vx_type() const {return vx_event::t_event_from_event;}
    vx_core::Type_msgblock Class_event_from_event::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_event_from_event::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_event_from_event::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_event_from_event::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_event::Type_event inputval = vx_core::vx_any_from_any(vx_event::t_event, val);
      output = vx_event::f_event_from_event(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_event_from_event::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_event::Type_event event = vx_core::vx_any_from_any(vx_event::t_event, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_event::f_event_from_event(event);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func eventmap<-eventlist)
  vx_event::Type_eventmap f_eventmap_from_eventlist(vx_event::Type_eventlist eventlist) {
    vx_event::Type_eventmap output = vx_event::e_eventmap;
    vx_core::vx_reserve(eventlist);
    output = vx_core::f_map_from_list(
      vx_event::t_eventmap,
      eventlist,
      vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any event_any) {
        vx_event::Type_event event = vx_core::vx_any_from_any(vx_event::t_event, event_any);
        vx_core::Type_any output_1 = 
          event->name();
        return output_1;
      })
    );
    vx_core::vx_release_one_except(eventlist, output);
    return output;
  }

  // (func eventmap<-eventlist)
  // class Class_eventmap_from_eventlist {
    Abstract_eventmap_from_eventlist::~Abstract_eventmap_from_eventlist() {}

    Class_eventmap_from_eventlist::Class_eventmap_from_eventlist() : Abstract_eventmap_from_eventlist::Abstract_eventmap_from_eventlist() {
      vx_core::refcount += 1;
    }

    Class_eventmap_from_eventlist::~Class_eventmap_from_eventlist() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_eventmap_from_eventlist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_event::Func_eventmap_from_eventlist output = vx_event::e_eventmap_from_eventlist;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_eventmap_from_eventlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_event::Func_eventmap_from_eventlist output = vx_event::e_eventmap_from_eventlist;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_eventmap_from_eventlist::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/event", // pkgname
        "eventmap<-eventlist", // name
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

    vx_core::Type_constdef Class_eventmap_from_eventlist::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_eventmap_from_eventlist::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/event", // pkgname
        "eventmap<-eventlist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_eventmap_from_eventlist::vx_empty() const {return vx_event::e_eventmap_from_eventlist;}
    vx_core::Type_any Class_eventmap_from_eventlist::vx_type() const {return vx_event::t_eventmap_from_eventlist;}
    vx_core::Type_msgblock Class_eventmap_from_eventlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_eventmap_from_eventlist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_eventmap_from_eventlist::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_eventmap_from_eventlist::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_event::Type_eventlist inputval = vx_core::vx_any_from_any(vx_event::t_eventlist, val);
      output = vx_event::f_eventmap_from_eventlist(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_eventmap_from_eventlist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_event::Type_eventlist eventlist = vx_core::vx_any_from_any(vx_event::t_eventlist, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_event::f_eventmap_from_eventlist(eventlist);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_event::Type_event e_event = NULL;
  vx_event::Type_event t_event = NULL;
  vx_event::Type_eventlist e_eventlist = NULL;
  vx_event::Type_eventlist t_eventlist = NULL;
  vx_event::Type_eventmap e_eventmap = NULL;
  vx_event::Type_eventmap t_eventmap = NULL;
  vx_event::Const_event_change c_event_change = NULL;
  vx_event::Const_event_click c_event_click = NULL;
  vx_event::Const_event_move c_event_move = NULL;
  vx_event::Const_event_select c_event_select = NULL;
  vx_event::Func_event_from_event e_event_from_event = NULL;
  vx_event::Func_event_from_event t_event_from_event = NULL;
  vx_event::Func_eventmap_from_eventlist e_eventmap_from_eventlist = NULL;
  vx_event::Func_eventmap_from_eventlist t_eventmap_from_eventlist = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_event::c_event_change = new vx_event::Class_event_change();
      vx_event::c_event_click = new vx_event::Class_event_click();
      vx_event::c_event_move = new vx_event::Class_event_move();
      vx_event::c_event_select = new vx_event::Class_event_select();
      vx_event::e_event = new Class_event();
      vx_core::vx_reserve_empty(vx_event::e_event);
      vx_event::t_event = new Class_event();
      vx_core::vx_reserve_type(vx_event::t_event);
      vx_event::e_eventlist = new Class_eventlist();
      vx_core::vx_reserve_empty(vx_event::e_eventlist);
      vx_event::t_eventlist = new Class_eventlist();
      vx_core::vx_reserve_type(vx_event::t_eventlist);
      vx_event::e_eventmap = new Class_eventmap();
      vx_core::vx_reserve_empty(vx_event::e_eventmap);
      vx_event::t_eventmap = new Class_eventmap();
      vx_core::vx_reserve_type(vx_event::t_eventmap);
      vx_event::e_event_from_event = new vx_event::Class_event_from_event();
      vx_core::vx_reserve_empty(vx_event::e_event_from_event);
      vx_event::t_event_from_event = new vx_event::Class_event_from_event();
      vx_core::vx_reserve_type(vx_event::t_event_from_event);
      vx_event::e_eventmap_from_eventlist = new vx_event::Class_eventmap_from_eventlist();
      vx_core::vx_reserve_empty(vx_event::e_eventmap_from_eventlist);
      vx_event::t_eventmap_from_eventlist = new vx_event::Class_eventmap_from_eventlist();
      vx_core::vx_reserve_type(vx_event::t_eventmap_from_eventlist);
      vx_event::Class_event_change::vx_const_new(vx_event::c_event_change);
      vx_event::Class_event_click::vx_const_new(vx_event::c_event_click);
      vx_event::Class_event_move::vx_const_new(vx_event::c_event_move);
      vx_event::Class_event_select::vx_const_new(vx_event::c_event_select);
      vx_core::vx_Type_mapany maptype;
      vx_core::vx_Type_mapany mapconst;
      vx_core::vx_Type_mapfunc mapfunc;
      vx_core::vx_Type_mapany mapempty;
      maptype["event"] = vx_event::t_event;
      maptype["eventlist"] = vx_event::t_eventlist;
      maptype["eventmap"] = vx_event::t_eventmap;
      mapconst["event-change"] = vx_event::c_event_change;
      mapconst["event-click"] = vx_event::c_event_click;
      mapconst["event-move"] = vx_event::c_event_move;
      mapconst["event-select"] = vx_event::c_event_select;
      mapfunc["event<-event"] = vx_event::t_event_from_event;
      mapfunc["eventmap<-eventlist"] = vx_event::t_eventmap_from_eventlist;
      vx_core::vx_global_package_set("vx/event", maptype, mapconst, mapfunc);
	   }
  // }

}
