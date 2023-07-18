#include <exception>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "core.hpp"

namespace vx_core {
// :body

  long refcount = 0;

  vx_core::vx_Type_listany emptylistany;
  vx_core::vx_Type_mapany emptymapany;

  // vx_boolean_contains_from_set_val(set<T>, val)
  template <class T> static bool vx_boolean_contains_from_set_val(std::set<T> set, T val) {
    const bool output = set.find(val) != set.end();
    return output;
  }

  // vx_boolean_from_string_ends(string, string)
  bool vx_boolean_from_string_ends(std::string text, std::string ends) {
    bool output = false;
    if (text.length() < ends.length()) {
    } else {
      output = text.substr(text.length() - ends.length()) == ends;
    }
    return output;
  }

  // vx_boolean_from_string_find(string, string)
  bool vx_boolean_from_string_find(std::string text, std::string find) {
    bool output = false;
    if (text.find(find) != std::string::npos) {
      output = true;
    }
    return output;
  }

  // vx_boolean_from_string_starts(string, string)
  bool vx_boolean_from_string_starts(std::string text, std::string starts) {
    bool output = false;
    if (text.rfind(starts, 0) == 0) {
      output = true;
    }
    return output;
  }

  // vx_debug(text)
  void vx_debug(std::string sval) {
    std::cout << sval << std::endl;
  }

  // vx_debug(any)
  void vx_debug(vx_core::Type_any val) {
    if (val == NULL) {
      vx_debug("null");
    } else {
      std::string sval = vx_core::vx_string_from_any(val);
      vx_debug(sval);
    }
  }

  // vx_list_from_array(arrayval)
  vx_core::vx_Type_listany vx_list_from_array(vx_core::vx_Type_listarg vals) {
    vx_core::vx_Type_listany output;
    output = vx_core::vx_Type_listany{vals};
    return output;
  }

  // vx_liststring_from_arraystring(long, array<string>)
  std::vector<std::string> vx_liststring_from_arraystring(long ilen, char* arraystring[]) {
    std::vector<std::string> output;
    output.reserve(ilen);
    if (ilen > 0) {
      output.assign(arraystring, arraystring + ilen);
    }
    return output;
  }

  // vx_new_boolean(boolean)
  vx_core::Type_boolean vx_new_boolean(bool isval) {
    vx_core::Type_boolean output = vx_core::c_false();
    if (isval) {
      output = vx_core::c_true();
    }
    return output;
  }

  // vx_new_decimal_from_float(float)
  vx_core::Type_decimal vx_new_decimal_from_float(float fval) {
    vx_core::Type_decimal output = new vx_core::Class_decimal();
    output->vx_p_decimal = std::to_string(fval);
    return output;
  }

  // vx_new_decimal_from_string(string)
  vx_core::Type_decimal vx_new_decimal_from_string(std::string sval) {
    vx_core::Type_decimal output = new vx_core::Class_decimal();
    output->vx_p_decimal = sval;
    return output;
  }

  // vx_new_float(float)
  vx_core::Type_float vx_new_float(float fval) {
    vx_core::Type_float output = new vx_core::Class_float();
    output->vx_p_float = fval;
    return output;
  }

  // vx_new_int(long)
  vx_core::Type_int vx_new_int(long ival) {
    vx_core::Type_int output = new vx_core::Class_int();
    output->vx_p_int = ival;
    return output;
  }

  // vx_new_string(string)
  vx_core::Type_string vx_new_string(std::string text) {
    vx_core::Type_string output;
    if (text == "") {
      output = vx_core::e_string();
    } else {
      output = new vx_core::Class_string();
      output->vx_p_string = text;
    }
    return output;
  }

  // vx_release(any)
  void vx_release(vx_core::Type_any any) {
    if (any == NULL) {
    } else if (any->vx_p_iref == 0) {
      delete any;
    }
  }

  // vx_release(any...)
  void vx_release(vx_core::vx_Type_listany listany) {
    for (vx_core::Type_any any : listany) {
      vx_core::vx_release(any);
    }
  }

  // vx_release_one(any)
  void vx_release_one(vx_core::Type_any any) {
    if (any != NULL) {
      long iref = any->vx_p_iref;
      if (iref > 0) {
        iref -= 1;
        any->vx_p_iref = iref;
        if (iref == 0) {
          delete any;
        }
      }
    }
  }

  // vx_release_one(any...)
  void vx_release_one(vx_core::vx_Type_listany listany) {
    for (vx_core::Type_any any : listany) {
      vx_release_one(any);
    }
  }

  // vx_release_one(map<string, any>)
  void vx_release_one(vx_core::vx_Type_mapany mapany) {
    for (auto const& [key, any] : mapany) {
      vx_release_one(any);
    }
  }

  // vx_reserve(any)
  void vx_reserve(vx_core::Type_any any) {
    if (any != NULL) {
      long iref = any->vx_p_iref;
      if (iref > 0) {
        iref += 1;
        any->vx_p_iref = iref;
      }
    }
  }

  // vx_reserve_empty(any)
  void vx_reserve_empty(vx_core::Type_any any) {
    if (any->vx_p_iref == 0) {
      any->vx_p_iref = -2;
      vx_core::refcount -= 1;
    }
  }

  // vx_reserve_type(any)
  void vx_reserve_type(vx_core::Type_any any) {
    if (any->vx_p_iref == 0) {
      any->vx_p_iref = -1;
      vx_core::refcount -= 1;
    }
  }

  // vx_string_from_any(val)
  std::string vx_string_from_any(vx_core::Type_any value) {
    return vx_core::vx_string_from_any_indent(value, 0, true);
  }

  // vx_string_from_any_indent(val, indent, linefeed)
  std::string vx_string_from_any_indent(vx_core::Type_any value, long indent, bool linefeed) {
    std::string output = "";
    std::string indenttext = vx_core::vx_string_from_string_repeat(" ", indent);
    std::string text = "";
    vx_core::Type_any type = value->vx_type();
    if (indent > 50) {
      text = "Error: Max Depth Exceeded";
    } else if (value == NULL) {
      text = "null";
    } else if (value == type) {
      vx_core::Type_typedef typdef = value->vx_typedef();
      text = typdef->pkgname()->vx_string() + "/" + typdef->name()->vx_string();
    } else if (type == vx_core::t_boolean()) {
      vx_core::Type_boolean valbool = vx_core::vx_any_from_any(vx_core::t_boolean(), value);
      if (valbool->vx_boolean()) {
        text = "true";
      } else {
        text = "false";
      }
    } else if (type == vx_core::t_decimal()) {
      vx_core::Type_decimal valdec = vx_core::vx_any_from_any(vx_core::t_decimal(), value);
      text = valdec->vx_string();
    } else if (type == vx_core::t_float()) {
      vx_core::Type_float valfloat = vx_core::vx_any_from_any(vx_core::t_float(), value);
      text = std::to_string(valfloat->vx_float());
      if (vx_core::vx_boolean_from_string_ends(text, ".0")) {
        text = vx_core::vx_string_from_string_start_end(text, 0, text.length() - 2);
      }
    } else if (type == vx_core::t_int()) {
      if (value == vx_core::c_notanumber()) {
        text = "notanumber";
      } else if (value == vx_core::c_infinity()) {
        text = "infinity";
      } else if (value == vx_core::c_neginfinity()) {
        text = "neginfinity";
      } else {
        vx_core::Type_int valint = vx_core::vx_any_from_any(vx_core::t_int(), value);
        text = std::to_string(valint->vx_int());
      }
    } else if (type == vx_core::t_string()) {
      vx_core::Type_string valstring = vx_core::vx_any_from_any(vx_core::t_string(), value);
      text = "\"" + valstring->vx_string() + "\"";
    } else if (value == type->vx_empty()) {
      vx_core::Type_typedef typdef = type->vx_typedef();
      text = "(" + typdef->name()->vx_string() + ")";
    } else {
      vx_core::Type_typedef typdef = value->vx_typedef();
      std::string extend = typdef->extend()->vx_string();
      if (extend == ":list") {
        vx_core::Type_list vallist = vx_core::vx_any_from_any(vx_core::t_list(), value);
        vx_core::Type_string typedefname = typdef->name();
        long indentint = indent;
        indentint += 1;
        std::vector<vx_core::Type_any> listval = vallist->vx_list();
        for (vx_core::Type_any valsub : listval) {
          std::string ssub = vx_core::vx_string_from_any_indent(valsub, indentint, linefeed);
          text += "\n " + indenttext + ssub;
        }
        if (vallist->vx_msgblock() != NULL) {
          std::string msgtext = vx_core::vx_string_from_any_indent(vallist->vx_msgblock(), indentint, linefeed);
          text += "\n" + indenttext + " :msgblock\n  " + indenttext + msgtext;
        }
        text = "(" + typedefname->vx_string() + text + ")";
      } else if (extend == ":map") {
        vx_core::Type_map valmap = vx_core::vx_any_from_any(vx_core::t_map(), value);
        vx_core::Type_string typedefname = typdef->name();
        long indentint = indent;
        indentint += 2;
        vx_core::vx_Type_mapany mapval = valmap->vx_map();
        for (auto const& [ckey, valsub] : mapval) {
          std::string key = ckey;
          if (!vx_boolean_from_string_starts(key, ":")) {
            key = ":" + key;
          }
          std::string strval = vx_core::vx_string_from_any_indent(valsub, indentint, linefeed);
          if (vx_boolean_from_string_find(strval, "\n")) {
            strval = "\n  " + indenttext + strval;
          } else {
            strval = " " + strval;
          }
          text += "\n" + indenttext + " " + key + strval;
        }
        if (valmap->vx_msgblock() != NULL) {
          std::string msgtext = vx_core::vx_string_from_any_indent(valmap->vx_msgblock(), indentint, linefeed);
          text += "\n" + indenttext + " :msgblock\n  " + indenttext + msgtext;
        }
        text = "(" + typedefname->vx_string() + text + ")";
      } else if (extend == ":struct") {
        vx_core::Type_struct valstruct = vx_core::vx_any_from_any(vx_core::t_struct(), value);
        vx_core::Type_string typedefname = typdef->name();
        vx_core::vx_Type_mapany mapval = valstruct->vx_map();
        long indentint = indent;
        indentint += 2;
        for (auto const& [ckey, valsub] : mapval) {
          std::string key = ckey;
          if (!vx_boolean_from_string_starts(key, ":")) {
            key = ":" + key;
          }
          std::string strval = vx_core::vx_string_from_any_indent(valsub, indentint, linefeed);
          if (vx_boolean_from_string_find(strval, "\n")) {
            strval = "\n  " + indenttext + strval;
          } else {
            strval = " " + strval;
          }
          text += "\n" + indenttext + " " + key + strval;
        }
        if (valstruct->vx_msgblock() != NULL) {
          std::string msgtext = vx_core::vx_string_from_any_indent(valstruct->vx_msgblock(), indentint, linefeed);
          text += "\n" + indenttext + " :msgblock\n  " + indenttext + msgtext;
        }
        text = "(" + typedefname->vx_string() + text + ")";
      } else if (extend == ":func") {
        vx_core::Type_func valfunc = vx_core::vx_any_from_any(vx_core::t_func(), value);
        vx_core::Type_funcdef funcdef = valfunc->vx_funcdef();
        text = funcdef->pkgname()->vx_string() + "/" + funcdef->name()->vx_string();
        if (valfunc->vx_msgblock() != NULL) {
          text = vx_core::vx_string_from_any_indent(valfunc->vx_msgblock(), indent, linefeed);
          text += "\n" + indenttext + " :msgblock\n  " + indenttext + text;
        }
        text = "(" + text + ")";
      }
    }
    output = text;
    return output;
  }

  // vx_string_from_liststring_pos(list<string>, long)
  std::string vx_string_from_liststring_pos(std::vector<std::string> liststring, long pos) {
    std::string output = "";
    if ((unsigned)pos < liststring.size()) {
      output = liststring[pos];
    }
    return output;
  }

  // vx_string_from_string_find_replace(string, string, string)
  std::string vx_string_from_string_find_replace(std::string text, std::string find, std::string replace) {
    std::string output = text;
    if (!find.empty()) {
      size_t start_pos = 0;
      while((start_pos = text.find(find, start_pos)) != std::string::npos) {
        output.replace(start_pos, find.length(), replace);
        start_pos += replace.length();
      }
    }
    return output;
  }

  // vx_string_from_string_find_replacefirst(string, string, string)
  std::string vx_string_from_string_find_replacefirst(std::string text, std::string find, std::string replacefirst) {
    std::string output = text;
    size_t start_pos = output.find(find);
    if (start_pos != std::string::npos) {
      output.replace(start_pos, find.length(), replacefirst);
    }
    return output;
  }

  // vx_string_from_string_repeat(string, int)
  std::string vx_string_from_string_repeat(std::string text, long repeat) {
    std::string output = "";
    for (int i = 0; i < repeat; i++) {
      output += text;
    }
    return output;
  }

  // vx_string_from_string_start_end(string, int, int)
  std::string vx_string_from_string_start_end(std::string text, long start, long end) {
    std::string output = text.substr(start, end);
    return output;
  }

  //class Abstract_replfunc {
    vx_core::Type_any Abstract_replfunc::vx_repl(vx_core::Type_anylist arglist) {return vx_core::t_any();}
  //}

  //class Abstract_replfunc_async {
    vx_core::vx_Type_async Abstract_replfunc_async::vx_repl(vx_core::Type_anylist arglist) {
      return vx_core::vx_async_new_from_val(vx_core::t_any());
    }
  //}

  //class Class_boolean {

    bool Class_boolean::vx_boolean() const {return this->vx_p_boolean;}

  //}

  //class Class_constdef {
    vx_core::Type_constdef Class_constdef::vx_constdef_new(
      std::string pkgname,
      std::string name,
      vx_core::Type_typedef typ
    ) {
      vx_core::Type_constdef output = new vx_core::Class_constdef();
      output->vx_p_pkgname = vx_core::vx_new_string(pkgname);
      output->vx_p_name = vx_core::vx_new_string(name);
      output->vx_p_type = typ;
      return output;
    }
  //}

  //class Class_decimal {
    float Class_decimal::vx_float() const {return std::stof(vx_p_decimal);}

    std::string Class_decimal::vx_string() const {return vx_p_decimal;}
  //}

  //class Class_float {
    float Class_float::vx_float() const {return vx_p_float;}
  //}

  //class Class_funcdef {
    vx_core::Type_funcdef Class_funcdef::vx_funcdef_new(
      std::string pkgname,
      std::string name,
      long idx,
      bool async,
      vx_core::Type_any typ
    ) {
      vx_core::Type_funcdef output = new vx_core::Class_funcdef();
      output->vx_p_pkgname = vx_core::vx_new_string(pkgname);
      output->vx_p_name = vx_core::vx_new_string(name);
      output->vx_p_idx = vx_core::vx_new_int(idx);
      output->vx_p_async = vx_core::vx_new_boolean(async);
      output->vx_p_type = typ;
      return output;
    }
  //}

  //class Class_int {
    long Class_int::vx_int() const {return vx_p_int;}
  //}

  //class Class_msg {
    vx_core::Type_msg Class_msg::vx_msg_from_errortext(const std::string errortext) const {
      vx_core::Type_msg output = new vx_core::Class_msg();
      output->vx_p_text = vx_core::vx_new_string(errortext);
      output->vx_p_severity = vx_core::c_msg_severe();
      return output;
    }

    vx_core::Type_msg Class_msg::vx_msg_from_exception(const std::string text, std::exception err) const {
      vx_core::Type_msg output = new vx_core::Class_msg();
      output->vx_p_text = vx_core::vx_new_string(text);
      output->vx_p_severity = vx_core::c_msg_severe();
      output->err = err;
      return output;
    }
  //}

  //class Class_msgblock {
    vx_core::Type_msgblock Class_msgblock::vx_msgblock_from_copy_listval(vx_core::Type_msgblock msgblock, vx_core::vx_Type_listany vals) const {
      vx_core::Type_msgblock output = vx_core::e_msgblock();
      std::vector<vx_core::Type_msgblock> listmsgblock;
      if (msgblock != NULL) {
        vx_core::Type_msgblock origmsgblock = msgblock->vx_msgblock();
        if (origmsgblock != NULL) {
          std::vector<vx_core::Type_msgblock> origlistmsgblock = origmsgblock->msgblocks()->vx_p_list;
          listmsgblock.insert(listmsgblock.end(), origlistmsgblock.begin(), origlistmsgblock.end());
        }
      }
      for (vx_core::Type_any subval : vals) {
        vx_core::Type_msgblock submsgblock = subval->vx_p_msgblock;
        if (submsgblock != NULL) {
          listmsgblock.push_back(submsgblock);
        }
      }
      vx_core::Type_msgblocklist msgblocks;
      if (listmsgblock.size() > 0) {
        msgblocks = new vx_core::Class_msgblocklist();
        msgblocks->vx_p_list = listmsgblock;
        if (msgblock == NULL) {
          output = vx_core::vx_new(vx_core::t_msgblock(), {msgblocks});
        } else {
          output = vx_core::vx_copy(msgblock, {msgblocks});
        }
      } else if (msgblock != NULL) {
        output = vx_core::vx_copy(msgblock, {});
      }
      return output;
    }
  //}

  //class Class_string {
    std::string Class_string::vx_string() const {
      return this->vx_p_string;
    }
  //}

  //class Class_typedef {
    vx_core::Type_typedef Class_typedef::vx_typedef_new(
      std::string pkgname,
      std::string name,
      std::string extend,
      vx_core::Type_typelist traits,
      vx_core::Type_typelist allowtypes,
      vx_core::Type_typelist disallowtypes,
      vx_core::Type_funclist allowfuncs,
      vx_core::Type_funclist disallowfuncs,
      vx_core::Type_anylist allowvalues,
      vx_core::Type_anylist disallowvalues,
      vx_core::Type_argmap properties
    ) {
      vx_core::Type_typedef output = new vx_core::Class_typedef();
      output->vx_p_pkgname = vx_core::vx_new_string(pkgname);
      output->vx_p_name = vx_core::vx_new_string(name);
      output->vx_p_extend = vx_core::vx_new_string(extend);
      output->vx_p_traits = traits;
      output->vx_p_allowtypes = allowtypes;
      output->vx_p_disallowtypes = disallowtypes;
      output->vx_p_allowfuncs = disallowfuncs;
      output->vx_p_disallowfuncs = disallowfuncs;
      output->vx_p_allowvalues = disallowvalues;
      output->vx_p_disallowvalues = disallowvalues;
      output->vx_p_properties = properties;
      return output;
    }

  //}


  // (type any)
  // class Class_any {
    Abstract_any::~Abstract_any() {}

    Class_any::Class_any() : Abstract_any::Abstract_any() {
      vx_core::refcount += 1;
    }
    Class_any::~Class_any() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_any::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_any(), vals);
    }
    vx_core::Type_any Class_any::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});
        }
      }
      output = new vx_core::Class_any();
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_any::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_any::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_any::vx_empty() const {return vx_core::e_any();}
    vx_core::Type_any Class_any::vx_type() const {return vx_core::t_any();}

    vx_core::Type_typedef Class_any::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type list)
  // class Class_list {
    Abstract_list::~Abstract_list() {}

    Class_list::Class_list() : Abstract_list::Abstract_list() {
      vx_core::refcount += 1;
    }
    Class_list::~Class_list() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_list::vx_list() const {
      return this->vx_p_list;
    }

    // vx_get_any(index)
    vx_core::Type_any Class_list::vx_get_any(vx_core::Type_int index) const {
      vx_core::Type_any output = vx_core::e_any();
      long iindex = index->vx_int();
      std::vector<vx_core::Type_any> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_list::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_core::Type_list output = vx_core::e_list();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_core::Type_any> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_any()) {
          vx_core::Type_any castval = vx_core::vx_any_from_any(vx_core::t_any(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(list) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_list();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_list::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_list(), vals);
    }
    vx_core::Type_any Class_list::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_list output = vx_core::e_list();
      vx_core::Type_list val = vx_core::vx_any_from_any(vx_core::t_list(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_core::Type_any> listval = val->vx_list();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_any()) {
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_any(), valsub));
        } else if (valsubtype == vx_core::t_list()) {
          vx_core::Type_list multi = vx_core::vx_any_from_any(vx_core::t_list(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_list());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new list) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_core::Class_list();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_list::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_list::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_list::vx_empty() const {return vx_core::e_list();}
    vx_core::Type_any Class_list::vx_type() const {return vx_core::t_list();}

    vx_core::Type_typedef Class_list::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "list", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_any()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type map)
  // class Class_map {
    Abstract_map::~Abstract_map() {}

    Class_map::Class_map() : Abstract_map::Abstract_map() {
      vx_core::refcount += 1;
    }
    Class_map::~Class_map() {
      vx_core::refcount -= 1;
    }
    // vx_map()
    vx_core::vx_Type_mapany Class_map::vx_map() const {
      vx_core::vx_Type_mapany output;
      return this->vx_p_map;
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_map::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      const vx_core::Class_map* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_any> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_core::e_any());
      return output;
    }

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_map::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_core::Type_map output = vx_core::e_map();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::map<std::string, vx_core::Type_any> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_any()) {
          vx_core::Type_any castval = vx_core::vx_any_from_any(vx_core::t_any(), val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(map) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_map();
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_map::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_map(), vals);
    }
    vx_core::Type_any Class_map::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_map output = vx_core::e_map();
      vx_core::Type_map valmap = vx_core::vx_any_from_any(vx_core::t_map(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_core::Type_any> mapval;
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
          vx_core::Type_any valany;
          if (valsubtype == vx_core::t_any()) {
            valany = vx_core::vx_any_from_any(vx_core::t_any(), valsub);
          } else if (valsubtype == vx_core::t_any()) {
            valany = vx_core::vx_any_from_any(vx_core::t_any(), valsub);
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("Invalid Key/Value: " + key + " "  + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          if (valany != NULL) {
            mapval[key] = valany;
            key = "";
          }
        }
      }
      output = new vx_core::Class_map();
      output->vx_p_map = mapval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_map::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_map::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_map::vx_empty() const {return vx_core::e_map();}
    vx_core::Type_any Class_map::vx_type() const {return vx_core::t_map();}

    vx_core::Type_typedef Class_map::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "map", // name
        ":map", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_any()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type struct)
  // class Class_struct {
    Abstract_struct::~Abstract_struct() {}

    Class_struct::Class_struct() : Abstract_struct::Abstract_struct() {
      vx_core::refcount += 1;
    }
    Class_struct::~Class_struct() {
      vx_core::refcount -= 1;
    }
    // vx_get_any(key)
    vx_core::Type_any Class_struct::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_struct::vx_map() const {
      vx_core::vx_Type_mapany output;
      return output;
    }

    vx_core::Type_any Class_struct::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_struct(), vals);
    }
    vx_core::Type_any Class_struct::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_struct output = vx_core::e_struct();
      vx_core::Type_struct val = vx_core::vx_any_from_any(vx_core::t_struct(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_struct::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_struct::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_struct::vx_empty() const {return vx_core::e_struct();}
    vx_core::Type_any Class_struct::vx_type() const {return vx_core::t_struct();}

    vx_core::Type_typedef Class_struct::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "struct", // name
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
    }

  //}

  // (type msg)
  // class Class_msg {
    Abstract_msg::~Abstract_msg() {}

    Class_msg::Class_msg() : Abstract_msg::Abstract_msg() {
      vx_core::refcount += 1;
    }
    Class_msg::~Class_msg() {
      vx_core::refcount -= 1;
    }
    // code()
    vx_core::Type_string Class_msg::code() const {
      vx_core::Type_string output = this->vx_p_code;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // severity()
    vx_core::Type_int Class_msg::severity() const {
      vx_core::Type_int output = this->vx_p_severity;
      if (output == NULL) {
        output = vx_core::e_int();
      }
      return output;
    }

    // text()
    vx_core::Type_string Class_msg::text() const {
      vx_core::Type_string output = this->vx_p_text;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_msg::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":code") {
        output = this->code();
      } else if (skey == ":severity") {
        output = this->severity();
      } else if (skey == ":text") {
        output = this->text();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_msg::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":code"] = this->code();
      output[":severity"] = this->severity();
      output[":text"] = this->text();
      return output;
    }

    vx_core::Type_any Class_msg::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_msg(), vals);
    }
    vx_core::Type_any Class_msg::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_msg output = vx_core::e_msg();
      vx_core::Type_msg val = vx_core::vx_any_from_any(vx_core::t_msg(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_code = val->code();
      vx_core::Type_int vx_p_severity = val->severity();
      vx_core::Type_string vx_p_text = val->text();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (key == "") {
          if (valsubtype == vx_core::t_string()) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            key = valstr->vx_string();
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new msg) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":code") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_code = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new msg :code " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":severity") {
            if (valsubtype == vx_core::t_int()) {
              vx_p_severity = vx_core::vx_any_from_any(vx_core::t_int(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new msg :severity " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":text") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_text = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new msg :text " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          }
          key = "";
        }
      }
      output = new vx_core::Class_msg();
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock vx_core::Class_msg::vx_msgblock() const {return vx_core::e_msgblock();}
    vx_core::vx_Type_listany vx_core::Class_msg::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_msg::vx_empty() const {return vx_core::e_msg();}
    vx_core::Type_any Class_msg::vx_type() const {return vx_core::t_msg();}

    vx_core::Type_typedef Class_msg::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "msg", // name
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
    }

  //}

  // (type msglist)
  // class Class_msglist {
    Abstract_msglist::~Abstract_msglist() {}

    Class_msglist::Class_msglist() : Abstract_msglist::Abstract_msglist() {
      vx_core::refcount += 1;
    }
    Class_msglist::~Class_msglist() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_msglist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_core::Type_msg Class_msglist::vx_get_msg(vx_core::Type_int index) const {
      vx_core::Type_msg output = vx_core::e_msg();
      long iindex = index->vx_int();
      std::vector<vx_core::Type_msg> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_msg> Class_msglist::vx_listmsg() const {return vx_p_list;}

    vx_core::Type_any vx_core::Class_msglist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_msg(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_msglist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_core::Type_msglist output = vx_core::e_msglist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_core::Type_msg> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_msg()) {
          vx_core::Type_msg castval = vx_core::vx_any_from_any(vx_core::t_msg(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(msglist) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_msglist();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_msglist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_msglist(), vals);
    }
    vx_core::Type_any Class_msglist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_msglist output = vx_core::e_msglist();
      vx_core::Type_msglist val = vx_core::vx_any_from_any(vx_core::t_msglist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_core::Type_msg> listval = val->vx_listmsg();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_msg(), valsub));
        } else if (valsubtype == vx_core::t_msglist()) {
          vx_core::Type_msglist multi = vx_core::vx_any_from_any(vx_core::t_msglist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listmsg());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new msglist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_core::Class_msglist();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_msglist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_msglist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_msglist::vx_empty() const {return vx_core::e_msglist();}
    vx_core::Type_any Class_msglist::vx_type() const {return vx_core::t_msglist();}

    vx_core::Type_typedef Class_msglist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "msglist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_msg()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type msgblock)
  // class Class_msgblock {
    Abstract_msgblock::~Abstract_msgblock() {}

    Class_msgblock::Class_msgblock() : Abstract_msgblock::Abstract_msgblock() {
      vx_core::refcount += 1;
    }
    Class_msgblock::~Class_msgblock() {
      vx_core::refcount -= 1;
    }
    // msgs()
    vx_core::Type_msglist Class_msgblock::msgs() const {
      vx_core::Type_msglist output = this->vx_p_msgs;
      if (output == NULL) {
        output = vx_core::e_msglist();
      }
      return output;
    }

    // msgblocks()
    vx_core::Type_msgblocklist Class_msgblock::msgblocks() const {
      vx_core::Type_msgblocklist output = this->vx_p_msgblocks;
      if (output == NULL) {
        output = vx_core::e_msgblocklist();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_msgblock::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":msgs") {
        output = this->msgs();
      } else if (skey == ":msgblocks") {
        output = this->msgblocks();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_msgblock::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":msgs"] = this->msgs();
      output[":msgblocks"] = this->msgblocks();
      return output;
    }

    vx_core::Type_any Class_msgblock::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_msgblock(), vals);
    }
    vx_core::Type_any Class_msgblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_msgblock output = vx_core::e_msgblock();
      vx_core::Type_msgblock val = vx_core::e_msgblock();
      if (copyval != NULL) {
        val = vx_core::vx_any_from_any(vx_core::t_msgblock(), copyval);
      }
      vx_core::Type_msgblock msgblock = new vx_core::Class_msgblock();
      vx_core::Type_msglist vx_p_msgs = val->msgs();
      vx_core::Type_msgblocklist vx_p_msgblocks = val->msgblocks();
      vx_core::Type_msgblocklist msgblocks = msgblock->msgblocks();
      vx_core::Type_msglist msgs = msgblock->msgs();
      std::string key = "";
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblocks = vx_core::vx_copy(msgblocks, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgs = vx_core::vx_copy(msgs, {valsub});
        } else if (valsubtype == vx_core::t_msgblocklist()) {
          msgblocks = vx_core::vx_copy(msgblocks, {valsub});
        } else if (valsubtype == vx_core::t_msglist()) {
          msgs = vx_core::vx_copy(msgs, {valsub});
        } else if (key == "") {
          if (valsubtype == vx_core::t_string()) {
            vx_core::Type_string valstr = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            key = valstr->vx_string();
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new msgblock) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgs = vx_core::vx_copy(msgs, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":msgs") {
            if (valsubtype == vx_core::t_msglist()) {
              vx_p_msgs = vx_core::vx_any_from_any(vx_core::t_msglist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new msgblock :msgs " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":msgblocks") {
            if (valsubtype == vx_core::t_msgblocklist()) {
              vx_p_msgblocks = vx_core::vx_any_from_any(vx_core::t_msgblocklist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new msgblock :msgblocks " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          }
          key = "";
        }
      }
      output = new vx_core::Class_msgblock();
      output->vx_p_msgs = msgs;
      output->vx_p_msgblocks = msgblocks;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock vx_core::Class_msgblock::vx_msgblock() const {return vx_core::e_msgblock();}
    vx_core::vx_Type_listany vx_core::Class_msgblock::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_msgblock::vx_empty() const {return vx_core::e_msgblock();}
    vx_core::Type_any Class_msgblock::vx_type() const {return vx_core::t_msgblock();}

    vx_core::Type_typedef Class_msgblock::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "msgblock", // name
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
    }

  //}

  // (type msgblocklist)
  // class Class_msgblocklist {
    Abstract_msgblocklist::~Abstract_msgblocklist() {}

    Class_msgblocklist::Class_msgblocklist() : Abstract_msgblocklist::Abstract_msgblocklist() {
      vx_core::refcount += 1;
    }
    Class_msgblocklist::~Class_msgblocklist() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_msgblocklist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_core::Type_msgblock Class_msgblocklist::vx_get_msgblock(vx_core::Type_int index) const {
      vx_core::Type_msgblock output = vx_core::e_msgblock();
      long iindex = index->vx_int();
      std::vector<vx_core::Type_msgblock> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_msgblock> Class_msgblocklist::vx_listmsgblock() const {return vx_p_list;}

    vx_core::Type_any vx_core::Class_msgblocklist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_msgblock(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_msgblocklist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_core::Type_msgblocklist output = vx_core::e_msgblocklist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_core::Type_msgblock> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_msgblock()) {
          vx_core::Type_msgblock castval = vx_core::vx_any_from_any(vx_core::t_msgblock(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(msgblocklist) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_msgblocklist();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_msgblocklist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_msgblocklist(), vals);
    }
    vx_core::Type_any Class_msgblocklist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_msgblocklist output = vx_core::e_msgblocklist();
      vx_core::Type_msgblocklist val = vx_core::vx_any_from_any(vx_core::t_msgblocklist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_core::Type_msgblock> listval = val->vx_listmsgblock();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msgblock()) {
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_msgblock(), valsub));
        } else if (valsubtype == vx_core::t_msgblocklist()) {
          vx_core::Type_msgblocklist multi = vx_core::vx_any_from_any(vx_core::t_msgblocklist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listmsgblock());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new msgblocklist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_core::Class_msgblocklist();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_msgblocklist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_msgblocklist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_msgblocklist::vx_empty() const {return vx_core::e_msgblocklist();}
    vx_core::Type_any Class_msgblocklist::vx_type() const {return vx_core::t_msgblocklist();}

    vx_core::Type_typedef Class_msgblocklist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "msgblocklist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_msgblock()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type boolean)
  // class Class_boolean {
    Abstract_boolean::~Abstract_boolean() {}

    Class_boolean::Class_boolean() : Abstract_boolean::Abstract_boolean() {
      vx_core::refcount += 1;
    }
    Class_boolean::~Class_boolean() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_boolean::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_boolean(), vals);
    }
    vx_core::Type_any Class_boolean::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_boolean output = vx_core::e_boolean();
      vx_core::Type_boolean val = vx_core::vx_any_from_any(vx_core::t_boolean(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      bool booleanval = val->vx_boolean();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});
        } else if (valsubtype == vx_core::t_boolean()) {
          vx_core::Type_boolean valboolean = vx_core::vx_any_from_any(vx_core::t_boolean(), valsub);
          booleanval = booleanval || valboolean->vx_boolean();
        }
      }
      output = new vx_core::Class_boolean();
      output->vx_p_boolean = booleanval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_boolean::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_boolean::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_boolean::vx_empty() const {return vx_core::e_boolean();}
    vx_core::Type_any Class_boolean::vx_type() const {return vx_core::t_boolean();}

    vx_core::Type_typedef Class_boolean::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type number)
  // class Class_number {
    Abstract_number::~Abstract_number() {}

    Class_number::Class_number() : Abstract_number::Abstract_number() {
      vx_core::refcount += 1;
    }
    Class_number::~Class_number() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_number::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_number(), vals);
    }
    vx_core::Type_any Class_number::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_number output = vx_core::e_number();
      return output;
    }

    vx_core::Type_msgblock Class_number::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_number::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_number::vx_empty() const {return vx_core::e_number();}
    vx_core::Type_any Class_number::vx_type() const {return vx_core::t_number();}

    vx_core::Type_typedef Class_number::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "number", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_int(), vx_core::t_float(), vx_core::t_decimal()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type decimal)
  // class Class_decimal {
    Abstract_decimal::~Abstract_decimal() {}

    Class_decimal::Class_decimal() : Abstract_decimal::Abstract_decimal() {
      vx_core::refcount += 1;
    }
    Class_decimal::~Class_decimal() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_decimal::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_decimal(), vals);
    }
    vx_core::Type_any Class_decimal::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_decimal output = vx_core::e_decimal();
      vx_core::Type_decimal val = vx_core::vx_any_from_any(vx_core::t_decimal(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::string sval = val->vx_string();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});
        } else if (valsubtype == vx_core::t_string()) {
          vx_core::Type_string valstring = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
          sval = valstring->vx_string();
        }
      }
      output = new vx_core::Class_decimal();
      output->vx_p_decimal = sval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_decimal::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_decimal::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_decimal::vx_empty() const {return vx_core::e_decimal();}
    vx_core::Type_any Class_decimal::vx_type() const {return vx_core::t_decimal();}

    vx_core::Type_typedef Class_decimal::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "decimal", // name
        "", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type float)
  // class Class_float {
    Abstract_float::~Abstract_float() {}

    Class_float::Class_float() : Abstract_float::Abstract_float() {
      vx_core::refcount += 1;
    }
    Class_float::~Class_float() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_float::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_float(), vals);
    }
    vx_core::Type_any Class_float::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_float output = vx_core::e_float();
      vx_core::Type_float val = vx_core::vx_any_from_any(vx_core::t_float(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      float floatval = val->vx_float();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});
        } else if (valsubtype == vx_core::t_decimal()) {
          vx_core::Type_decimal valnum = vx_core::vx_any_from_any(vx_core::t_decimal(), valsub);
          floatval += valnum->vx_float();
        } else if (valsubtype == vx_core::t_float()) {
          vx_core::Type_float valnum = vx_core::vx_any_from_any(vx_core::t_float(), valsub);
          floatval += valnum->vx_float();
        } else if (valsubtype == vx_core::t_int()) {
          vx_core::Type_int valnum = vx_core::vx_any_from_any(vx_core::t_int(), valsub);
          floatval += valnum->vx_int();
        } else if (valsubtype == vx_core::t_string()) {
          vx_core::Type_string valstring = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
          floatval += std::stof(valstring->vx_string());
        }
      }
      output = new vx_core::Class_float();
      output->vx_p_float = floatval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_float::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_float::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_float::vx_empty() const {return vx_core::e_float();}
    vx_core::Type_any Class_float::vx_type() const {return vx_core::t_float();}

    vx_core::Type_typedef Class_float::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "float", // name
        "", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type int)
  // class Class_int {
    Abstract_int::~Abstract_int() {}

    Class_int::Class_int() : Abstract_int::Abstract_int() {
      vx_core::refcount += 1;
    }
    Class_int::~Class_int() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_int::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_int(), vals);
    }
    vx_core::Type_any Class_int::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_int output = vx_core::e_int();
      vx_core::Type_int val = vx_core::vx_any_from_any(vx_core::t_int(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      long intval = val->vx_int();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});
        } else if (valsubtype == vx_core::t_int()) {
          vx_core::Type_int valnum = vx_core::vx_any_from_any(vx_core::t_int(), valsub);
          intval += valnum->vx_int();
        }
      }
      output = new vx_core::Class_int();
      output->vx_p_int = intval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_int::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_int::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_int::vx_empty() const {return vx_core::e_int();}
    vx_core::Type_any Class_int::vx_type() const {return vx_core::t_int();}

    vx_core::Type_typedef Class_int::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "int", // name
        "", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type string)
  // class Class_string {
    Abstract_string::~Abstract_string() {}

    Class_string::Class_string() : Abstract_string::Abstract_string() {
      vx_core::refcount += 1;
    }
    Class_string::~Class_string() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_string::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_string(), vals);
    }
    vx_core::Type_any Class_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_string output = vx_core::e_string();
      vx_core::Type_string val = vx_core::vx_any_from_any(vx_core::t_string(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::string sb = val->vx_string();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(vx_core::t_msgblock(), {valsub});
        } else if (valsubtype == vx_core::t_string()) {
          vx_core::Type_string valstring = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
          sb += valstring->vx_string();
        } else if (valsubtype == vx_core::t_int()) {
          vx_core::Type_int valint = vx_core::vx_any_from_any(vx_core::t_int(), valsub);
          sb += valint->vx_int();
        } else if (valsubtype == vx_core::t_float()) {
          vx_core::Type_float valfloat = vx_core::vx_any_from_any(vx_core::t_float(), valsub);
          sb += valfloat->vx_float();
        } else if (valsubtype == vx_core::t_decimal()) {
          vx_core::Type_decimal valdecimal = vx_core::vx_any_from_any(vx_core::t_decimal(), valsub);
          sb += valdecimal->vx_string();
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new string) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_core::Class_string();
      output->vx_p_string = sb;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_string::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_string::vx_empty() const {return vx_core::e_string();}
    vx_core::Type_any Class_string::vx_type() const {return vx_core::t_string();}

    vx_core::Type_typedef Class_string::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "string", // name
        "string", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type func)
  // class Class_func {
    Abstract_func::~Abstract_func() {}

    Class_func::Class_func() : Abstract_func::Abstract_func() {
      vx_core::refcount += 1;
    }
    Class_func::~Class_func() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_funcdef Class_func::vx_funcdef() const {
      return vx_core::e_funcdef();
    }
    vx_core::Type_any Class_func::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_func(), vals);
    }
    vx_core::Type_any Class_func::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_func output = vx_core::e_func();
      return output;
    }

    vx_core::Type_msgblock Class_func::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_func::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_func::vx_empty() const {return vx_core::e_func();}
    vx_core::Type_any Class_func::vx_type() const {return vx_core::t_func();}

    vx_core::Type_typedef Class_func::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "func", // name
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
    }

  //}

  // (type typedef)
  // class Class_typedef {
    Abstract_typedef::~Abstract_typedef() {}

    Class_typedef::Class_typedef() : Abstract_typedef::Abstract_typedef() {
      vx_core::refcount += 1;
    }
    Class_typedef::~Class_typedef() {
      vx_core::refcount -= 1;
    }
    // pkgname()
    vx_core::Type_string Class_typedef::pkgname() const {
      vx_core::Type_string output = this->vx_p_pkgname;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // name()
    vx_core::Type_string Class_typedef::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // extend()
    vx_core::Type_string Class_typedef::extend() const {
      vx_core::Type_string output = this->vx_p_extend;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // allowfuncs()
    vx_core::Type_funclist Class_typedef::allowfuncs() const {
      vx_core::Type_funclist output = this->vx_p_allowfuncs;
      if (output == NULL) {
        output = vx_core::e_funclist();
      }
      return output;
    }

    // allowtypes()
    vx_core::Type_typelist Class_typedef::allowtypes() const {
      vx_core::Type_typelist output = this->vx_p_allowtypes;
      if (output == NULL) {
        output = vx_core::e_typelist();
      }
      return output;
    }

    // allowvalues()
    vx_core::Type_anylist Class_typedef::allowvalues() const {
      vx_core::Type_anylist output = this->vx_p_allowvalues;
      if (output == NULL) {
        output = vx_core::e_anylist();
      }
      return output;
    }

    // disallowfuncs()
    vx_core::Type_funclist Class_typedef::disallowfuncs() const {
      vx_core::Type_funclist output = this->vx_p_disallowfuncs;
      if (output == NULL) {
        output = vx_core::e_funclist();
      }
      return output;
    }

    // disallowtypes()
    vx_core::Type_typelist Class_typedef::disallowtypes() const {
      vx_core::Type_typelist output = this->vx_p_disallowtypes;
      if (output == NULL) {
        output = vx_core::e_typelist();
      }
      return output;
    }

    // disallowvalues()
    vx_core::Type_anylist Class_typedef::disallowvalues() const {
      vx_core::Type_anylist output = this->vx_p_disallowvalues;
      if (output == NULL) {
        output = vx_core::e_anylist();
      }
      return output;
    }

    // properties()
    vx_core::Type_argmap Class_typedef::properties() const {
      vx_core::Type_argmap output = this->vx_p_properties;
      if (output == NULL) {
        output = vx_core::e_argmap();
      }
      return output;
    }

    // proplast()
    vx_core::Type_arg Class_typedef::proplast() const {
      vx_core::Type_arg output = this->vx_p_proplast;
      if (output == NULL) {
        output = vx_core::e_arg();
      }
      return output;
    }

    // traits()
    vx_core::Type_typelist Class_typedef::traits() const {
      vx_core::Type_typelist output = this->vx_p_traits;
      if (output == NULL) {
        output = vx_core::e_typelist();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_typedef::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":pkgname") {
        output = this->pkgname();
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":extends") {
        output = this->extend();
      } else if (skey == ":allowfuncs") {
        output = this->allowfuncs();
      } else if (skey == ":allowtypes") {
        output = this->allowtypes();
      } else if (skey == ":allowvalues") {
        output = this->allowvalues();
      } else if (skey == ":disallowfuncs") {
        output = this->disallowfuncs();
      } else if (skey == ":disallowtypes") {
        output = this->disallowtypes();
      } else if (skey == ":disallowvalues") {
        output = this->disallowvalues();
      } else if (skey == ":properties") {
        output = this->properties();
      } else if (skey == ":proplast") {
        output = this->proplast();
      } else if (skey == ":traits") {
        output = this->traits();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_typedef::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":pkgname"] = this->pkgname();
      output[":name"] = this->name();
      output[":extends"] = this->extend();
      output[":allowfuncs"] = this->allowfuncs();
      output[":allowtypes"] = this->allowtypes();
      output[":allowvalues"] = this->allowvalues();
      output[":disallowfuncs"] = this->disallowfuncs();
      output[":disallowtypes"] = this->disallowtypes();
      output[":disallowvalues"] = this->disallowvalues();
      output[":properties"] = this->properties();
      output[":proplast"] = this->proplast();
      output[":traits"] = this->traits();
      return output;
    }

    vx_core::Type_any Class_typedef::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_typedef(), vals);
    }
    vx_core::Type_any Class_typedef::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_typedef output = vx_core::e_typedef();
      vx_core::Type_typedef val = vx_core::vx_any_from_any(vx_core::t_typedef(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_pkgname = val->pkgname();
      vx_core::Type_string vx_p_name = val->name();
      vx_core::Type_string vx_p_extend = val->extend();
      vx_core::Type_funclist vx_p_allowfuncs = val->allowfuncs();
      vx_core::Type_typelist vx_p_allowtypes = val->allowtypes();
      vx_core::Type_anylist vx_p_allowvalues = val->allowvalues();
      vx_core::Type_funclist vx_p_disallowfuncs = val->disallowfuncs();
      vx_core::Type_typelist vx_p_disallowtypes = val->disallowtypes();
      vx_core::Type_anylist vx_p_disallowvalues = val->disallowvalues();
      vx_core::Type_argmap vx_p_properties = val->properties();
      vx_core::Type_arg vx_p_proplast = val->proplast();
      vx_core::Type_typelist vx_p_traits = val->traits();
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
          } else if (testkey == ":pkgname") {
            key = testkey;
          } else if (testkey == ":name") {
            key = testkey;
          } else if (testkey == ":extends") {
            key = testkey;
          } else if (testkey == ":allowfuncs") {
            key = testkey;
          } else if (testkey == ":allowtypes") {
            key = testkey;
          } else if (testkey == ":allowvalues") {
            key = testkey;
          } else if (testkey == ":disallowfuncs") {
            key = testkey;
          } else if (testkey == ":disallowtypes") {
            key = testkey;
          } else if (testkey == ":disallowvalues") {
            key = testkey;
          } else if (testkey == ":properties") {
            key = testkey;
          } else if (testkey == ":proplast") {
            key = testkey;
          } else if (testkey == ":traits") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new typedef) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":pkgname") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_pkgname = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new typedef :pkgname " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new typedef :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":extends") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_extend = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new typedef :extends " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":allowfuncs") {
            if (valsubtype == vx_core::t_funclist()) {
              vx_p_allowfuncs = vx_core::vx_any_from_any(vx_core::t_funclist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new typedef :allowfuncs " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":allowtypes") {
            if (valsubtype == vx_core::t_typelist()) {
              vx_p_allowtypes = vx_core::vx_any_from_any(vx_core::t_typelist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new typedef :allowtypes " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":allowvalues") {
            if (valsubtype == vx_core::t_anylist()) {
              vx_p_allowvalues = vx_core::vx_any_from_any(vx_core::t_anylist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new typedef :allowvalues " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":disallowfuncs") {
            if (valsubtype == vx_core::t_funclist()) {
              vx_p_disallowfuncs = vx_core::vx_any_from_any(vx_core::t_funclist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new typedef :disallowfuncs " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":disallowtypes") {
            if (valsubtype == vx_core::t_typelist()) {
              vx_p_disallowtypes = vx_core::vx_any_from_any(vx_core::t_typelist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new typedef :disallowtypes " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":disallowvalues") {
            if (valsubtype == vx_core::t_anylist()) {
              vx_p_disallowvalues = vx_core::vx_any_from_any(vx_core::t_anylist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new typedef :disallowvalues " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":properties") {
            if (valsubtype == vx_core::t_argmap()) {
              vx_p_properties = vx_core::vx_any_from_any(vx_core::t_argmap(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new typedef :properties " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":proplast") {
            if (valsubtype == vx_core::t_arg()) {
              vx_p_proplast = vx_core::vx_any_from_any(vx_core::t_arg(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new typedef :proplast " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":traits") {
            if (valsubtype == vx_core::t_typelist()) {
              vx_p_traits = vx_core::vx_any_from_any(vx_core::t_typelist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new typedef :traits " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new typedef) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_core::Class_typedef();
      output->vx_p_pkgname = vx_p_pkgname;
      output->vx_p_name = vx_p_name;
      output->vx_p_extend = vx_p_extend;
      output->vx_p_allowfuncs = vx_p_allowfuncs;
      output->vx_p_allowtypes = vx_p_allowtypes;
      output->vx_p_allowvalues = vx_p_allowvalues;
      output->vx_p_disallowfuncs = vx_p_disallowfuncs;
      output->vx_p_disallowtypes = vx_p_disallowtypes;
      output->vx_p_disallowvalues = vx_p_disallowvalues;
      output->vx_p_properties = vx_p_properties;
      output->vx_p_proplast = vx_p_proplast;
      output->vx_p_traits = vx_p_traits;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_typedef::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_typedef::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_typedef::vx_empty() const {return vx_core::e_typedef();}
    vx_core::Type_any Class_typedef::vx_type() const {return vx_core::t_typedef();}

    vx_core::Type_typedef Class_typedef::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "typedef", // name
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
    }

  //}

  // (type funcdef)
  // class Class_funcdef {
    Abstract_funcdef::~Abstract_funcdef() {}

    Class_funcdef::Class_funcdef() : Abstract_funcdef::Abstract_funcdef() {
      vx_core::refcount += 1;
    }
    Class_funcdef::~Class_funcdef() {
      vx_core::refcount -= 1;
    }
    // pkgname()
    vx_core::Type_string Class_funcdef::pkgname() const {
      vx_core::Type_string output = this->vx_p_pkgname;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // name()
    vx_core::Type_string Class_funcdef::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // idx()
    vx_core::Type_int Class_funcdef::idx() const {
      vx_core::Type_int output = this->vx_p_idx;
      if (output == NULL) {
        output = vx_core::e_int();
      }
      return output;
    }

    // type()
    vx_core::Type_any Class_funcdef::type() const {
      vx_core::Type_any output = this->vx_p_type;
      if (output == NULL) {
        output = vx_core::e_any();
      }
      return output;
    }

    // async()
    vx_core::Type_boolean Class_funcdef::async() const {
      vx_core::Type_boolean output = this->vx_p_async;
      if (output == NULL) {
        output = vx_core::e_boolean();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_funcdef::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":pkgname") {
        output = this->pkgname();
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":idx") {
        output = this->idx();
      } else if (skey == ":type") {
        output = this->type();
      } else if (skey == ":async") {
        output = this->async();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_funcdef::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":pkgname"] = this->pkgname();
      output[":name"] = this->name();
      output[":idx"] = this->idx();
      output[":type"] = this->type();
      output[":async"] = this->async();
      return output;
    }

    vx_core::Type_any Class_funcdef::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_funcdef(), vals);
    }
    vx_core::Type_any Class_funcdef::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_funcdef output = vx_core::e_funcdef();
      vx_core::Type_funcdef val = vx_core::vx_any_from_any(vx_core::t_funcdef(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_pkgname = val->pkgname();
      vx_core::Type_string vx_p_name = val->name();
      vx_core::Type_int vx_p_idx = val->idx();
      vx_core::Type_any vx_p_type = val->type();
      vx_core::Type_boolean vx_p_async = val->async();
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
          } else if (testkey == ":pkgname") {
            key = testkey;
          } else if (testkey == ":name") {
            key = testkey;
          } else if (testkey == ":idx") {
            key = testkey;
          } else if (testkey == ":type") {
            key = testkey;
          } else if (testkey == ":async") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new funcdef) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":pkgname") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_pkgname = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new funcdef :pkgname " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new funcdef :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":idx") {
            if (valsubtype == vx_core::t_int()) {
              vx_p_idx = vx_core::vx_any_from_any(vx_core::t_int(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new funcdef :idx " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":type") {
            if (valsubtype == vx_core::t_any()) {
              vx_p_type = vx_core::vx_any_from_any(vx_core::t_any(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new funcdef :type " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":async") {
            if (valsubtype == vx_core::t_boolean()) {
              vx_p_async = vx_core::vx_any_from_any(vx_core::t_boolean(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new funcdef :async " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new funcdef) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_core::Class_funcdef();
      output->vx_p_pkgname = vx_p_pkgname;
      output->vx_p_name = vx_p_name;
      output->vx_p_idx = vx_p_idx;
      output->vx_p_type = vx_p_type;
      output->vx_p_async = vx_p_async;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_funcdef::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_funcdef::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_funcdef::vx_empty() const {return vx_core::e_funcdef();}
    vx_core::Type_any Class_funcdef::vx_type() const {return vx_core::t_funcdef();}

    vx_core::Type_typedef Class_funcdef::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "funcdef", // name
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
    }

  //}

  // (type any-async<-func)
  // class Class_any_async_from_func {
    Abstract_any_async_from_func::~Abstract_any_async_from_func() {}

    Class_any_async_from_func::Class_any_async_from_func() : Abstract_any_async_from_func::Abstract_any_async_from_func() {
      vx_core::refcount += 1;
    }
    Class_any_async_from_func::~Class_any_async_from_func() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_any_async_from_func::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_any_async_from_func(), vals);
    }
    vx_core::Type_any Class_any_async_from_func::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_any_async_from_func output = vx_core::e_any_async_from_func();
      return output;
    }

    vx_core::Type_msgblock Class_any_async_from_func::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_any_async_from_func::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_any_async_from_func::vx_empty() const {return vx_core::e_any_async_from_func();}
    vx_core::Type_any Class_any_async_from_func::vx_type() const {return vx_core::t_any_async_from_func();}

    vx_core::Type_typedef Class_any_async_from_func::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-async<-func", // name
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
    }

  //}

  // (type any<-anylist)
  // class Class_any_from_anylist {
    Abstract_any_from_anylist::~Abstract_any_from_anylist() {}

    Class_any_from_anylist::Class_any_from_anylist() : Abstract_any_from_anylist::Abstract_any_from_anylist() {
      vx_core::refcount += 1;
    }
    Class_any_from_anylist::~Class_any_from_anylist() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_any_from_anylist::vx_list() const {
      return this->vx_p_list;
    }

    // vx_get_any(index)
    vx_core::Type_any Class_any_from_anylist::vx_get_any(vx_core::Type_int index) const {
      vx_core::Type_any output = vx_core::e_any();
      long iindex = index->vx_int();
      std::vector<vx_core::Type_any> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_any_from_anylist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_core::Type_any_from_anylist output = vx_core::e_any_from_anylist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_core::Type_any> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_any()) {
          vx_core::Type_any castval = vx_core::vx_any_from_any(vx_core::t_any(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(any_from_anylist) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_any_from_anylist();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_any_from_anylist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_any_from_anylist(), vals);
    }
    vx_core::Type_any Class_any_from_anylist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_any_from_anylist output = vx_core::e_any_from_anylist();
      vx_core::Type_any_from_anylist val = vx_core::vx_any_from_any(vx_core::t_any_from_anylist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_core::Type_any> listval = val->vx_list();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_any_from_anylist()) {
          vx_core::Type_any_from_anylist multi = vx_core::vx_any_from_any(vx_core::t_any_from_anylist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_list());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new any<-anylist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_core::Class_any_from_anylist();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_any_from_anylist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_any_from_anylist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_any_from_anylist::vx_empty() const {return vx_core::e_any_from_anylist();}
    vx_core::Type_any Class_any_from_anylist::vx_type() const {return vx_core::t_any_from_anylist();}

    vx_core::Type_typedef Class_any_from_anylist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any<-anylist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type anylist)
  // class Class_anylist {
    Abstract_anylist::~Abstract_anylist() {}

    Class_anylist::Class_anylist() : Abstract_anylist::Abstract_anylist() {
      vx_core::refcount += 1;
    }
    Class_anylist::~Class_anylist() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_anylist::vx_list() const {
      return this->vx_p_list;
    }

    // vx_get_any(index)
    vx_core::Type_any Class_anylist::vx_get_any(vx_core::Type_int index) const {
      vx_core::Type_any output = vx_core::e_any();
      long iindex = index->vx_int();
      std::vector<vx_core::Type_any> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_anylist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_core::Type_anylist output = vx_core::e_anylist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_core::Type_any> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_any()) {
          vx_core::Type_any castval = vx_core::vx_any_from_any(vx_core::t_any(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(anylist) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_anylist();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_anylist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_anylist(), vals);
    }
    vx_core::Type_any Class_anylist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_anylist output = vx_core::e_anylist();
      vx_core::Type_anylist val = vx_core::vx_any_from_any(vx_core::t_anylist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_core::Type_any> listval = val->vx_list();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_any()) {
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_any(), valsub));
        } else if (valsubtype == vx_core::t_anylist()) {
          vx_core::Type_anylist multi = vx_core::vx_any_from_any(vx_core::t_anylist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_list());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new anylist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_core::Class_anylist();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_anylist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_anylist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_anylist::vx_empty() const {return vx_core::e_anylist();}
    vx_core::Type_any Class_anylist::vx_type() const {return vx_core::t_anylist();}

    vx_core::Type_typedef Class_anylist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "anylist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_any()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type anytype)
  // class Class_anytype {
    Abstract_anytype::~Abstract_anytype() {}

    Class_anytype::Class_anytype() : Abstract_anytype::Abstract_anytype() {
      vx_core::refcount += 1;
    }
    Class_anytype::~Class_anytype() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_anytype::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_anytype(), vals);
    }
    vx_core::Type_any Class_anytype::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_anytype output = vx_core::e_anytype();
      return output;
    }

    vx_core::Type_msgblock Class_anytype::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_anytype::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_anytype::vx_empty() const {return vx_core::e_anytype();}
    vx_core::Type_any Class_anytype::vx_type() const {return vx_core::t_anytype();}

    vx_core::Type_typedef Class_anytype::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "anytype", // name
        ":type", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type arg)
  // class Class_arg {
    Abstract_arg::~Abstract_arg() {}

    Class_arg::Class_arg() : Abstract_arg::Abstract_arg() {
      vx_core::refcount += 1;
    }
    Class_arg::~Class_arg() {
      vx_core::refcount -= 1;
    }
    // name()
    vx_core::Type_string Class_arg::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // argtype()
    vx_core::Type_type Class_arg::argtype() const {
      vx_core::Type_type output = this->vx_p_argtype;
      if (output == NULL) {
        output = vx_core::e_type();
      }
      return output;
    }

    // fn_any()
    vx_core::Func_any_from_func Class_arg::fn_any() const {
      vx_core::Func_any_from_func output = this->vx_p_fn_any;
      if (output == NULL) {
        output = vx_core::e_any_from_func();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_arg::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":argtype") {
        output = this->argtype();
      } else if (skey == ":fn-any") {
        output = this->fn_any();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_arg::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":name"] = this->name();
      output[":argtype"] = this->argtype();
      output[":fn-any"] = this->fn_any();
      return output;
    }

    vx_core::Type_any Class_arg::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_arg(), vals);
    }
    vx_core::Type_any Class_arg::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_arg output = vx_core::e_arg();
      vx_core::Type_arg val = vx_core::vx_any_from_any(vx_core::t_arg(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_name = val->name();
      vx_core::Type_type vx_p_argtype = val->argtype();
      vx_core::Func_any_from_func vx_p_fn_any = val->fn_any();
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
          } else if (testkey == ":argtype") {
            key = testkey;
          } else if (testkey == ":fn-any") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new arg) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new arg :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":argtype") {
            if (valsubtype == vx_core::t_type()) {
              vx_p_argtype = vx_core::vx_any_from_any(vx_core::t_type(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new arg :argtype " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":fn-any") {
            if (valsubtype == vx_core::t_any_from_func()) {
              vx_p_fn_any = vx_core::vx_any_from_any(vx_core::t_any_from_func(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new arg :fn-any " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new arg) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_core::Class_arg();
      output->vx_p_name = vx_p_name;
      output->vx_p_argtype = vx_p_argtype;
      output->vx_p_fn_any = vx_p_fn_any;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_arg::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_arg::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_arg::vx_empty() const {return vx_core::e_arg();}
    vx_core::Type_any Class_arg::vx_type() const {return vx_core::t_arg();}

    vx_core::Type_typedef Class_arg::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "arg", // name
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
    }

  //}

  // (type arglist)
  // class Class_arglist {
    Abstract_arglist::~Abstract_arglist() {}

    Class_arglist::Class_arglist() : Abstract_arglist::Abstract_arglist() {
      vx_core::refcount += 1;
    }
    Class_arglist::~Class_arglist() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_arglist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_core::Type_arg Class_arglist::vx_get_arg(vx_core::Type_int index) const {
      vx_core::Type_arg output = vx_core::e_arg();
      long iindex = index->vx_int();
      std::vector<vx_core::Type_arg> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_arg> Class_arglist::vx_listarg() const {return vx_p_list;}

    vx_core::Type_any vx_core::Class_arglist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_arg(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_arglist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_core::Type_arglist output = vx_core::e_arglist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_core::Type_arg> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_arg()) {
          vx_core::Type_arg castval = vx_core::vx_any_from_any(vx_core::t_arg(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(arglist) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_arglist();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_arglist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_arglist(), vals);
    }
    vx_core::Type_any Class_arglist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_arglist output = vx_core::e_arglist();
      vx_core::Type_arglist val = vx_core::vx_any_from_any(vx_core::t_arglist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_core::Type_arg> listval = val->vx_listarg();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_arg()) {
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_arg(), valsub));
        } else if (valsubtype == vx_core::t_arglist()) {
          vx_core::Type_arglist multi = vx_core::vx_any_from_any(vx_core::t_arglist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listarg());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new arglist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_core::Class_arglist();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_arglist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_arglist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_arglist::vx_empty() const {return vx_core::e_arglist();}
    vx_core::Type_any Class_arglist::vx_type() const {return vx_core::t_arglist();}

    vx_core::Type_typedef Class_arglist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "arglist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_arg()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type argmap)
  // class Class_argmap {
    Abstract_argmap::~Abstract_argmap() {}

    Class_argmap::Class_argmap() : Abstract_argmap::Abstract_argmap() {
      vx_core::refcount += 1;
    }
    Class_argmap::~Class_argmap() {
      vx_core::refcount -= 1;
    }
    // vx_map()
    vx_core::vx_Type_mapany Class_argmap::vx_map() const {
      vx_core::vx_Type_mapany output;
      return vx_core::vx_map_from_map(vx_core::t_any(), this->vx_p_map);
      return output;
    }

    // vx_get_arg(key)
    vx_core::Type_arg Class_argmap::vx_get_arg(vx_core::Type_string key) const {
      vx_core::Type_arg output = vx_core::e_arg();
      const vx_core::Class_argmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_arg> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_core::e_arg());
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_argmap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_arg(key);
    }

    // vx_maparg()
    std::map<std::string, vx_core::Type_arg> Class_argmap::vx_maparg() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_argmap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_core::Type_argmap output = vx_core::e_argmap();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::map<std::string, vx_core::Type_arg> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_arg()) {
          vx_core::Type_arg castval = vx_core::vx_any_from_any(vx_core::t_arg(), val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(argmap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_argmap();
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_argmap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_argmap(), vals);
    }
    vx_core::Type_any Class_argmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_argmap output = vx_core::e_argmap();
      vx_core::Type_argmap valmap = vx_core::vx_any_from_any(vx_core::t_argmap(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_core::Type_arg> mapval;
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
          vx_core::Type_arg valany;
          if (valsubtype == vx_core::t_arg()) {
            valany = vx_core::vx_any_from_any(vx_core::t_arg(), valsub);
          } else if (valsubtype == vx_core::t_arg()) {
            valany = vx_core::vx_any_from_any(vx_core::t_arg(), valsub);
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("Invalid Key/Value: " + key + " "  + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          if (valany != NULL) {
            mapval[key] = valany;
            key = "";
          }
        }
      }
      output = new vx_core::Class_argmap();
      output->vx_p_map = mapval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_argmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_argmap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_argmap::vx_empty() const {return vx_core::e_argmap();}
    vx_core::Type_any Class_argmap::vx_type() const {return vx_core::t_argmap();}

    vx_core::Type_typedef Class_argmap::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "argmap", // name
        ":map", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_arg()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type booleanlist)
  // class Class_booleanlist {
    Abstract_booleanlist::~Abstract_booleanlist() {}

    Class_booleanlist::Class_booleanlist() : Abstract_booleanlist::Abstract_booleanlist() {
      vx_core::refcount += 1;
    }
    Class_booleanlist::~Class_booleanlist() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_booleanlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_core::Type_boolean Class_booleanlist::vx_get_boolean(vx_core::Type_int index) const {
      vx_core::Type_boolean output = vx_core::e_boolean();
      long iindex = index->vx_int();
      std::vector<vx_core::Type_boolean> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_boolean> Class_booleanlist::vx_listboolean() const {return vx_p_list;}

    vx_core::Type_any vx_core::Class_booleanlist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_boolean(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_booleanlist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_core::Type_booleanlist output = vx_core::e_booleanlist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_core::Type_boolean> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_boolean()) {
          vx_core::Type_boolean castval = vx_core::vx_any_from_any(vx_core::t_boolean(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(booleanlist) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_booleanlist();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_booleanlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_booleanlist(), vals);
    }
    vx_core::Type_any Class_booleanlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_booleanlist output = vx_core::e_booleanlist();
      vx_core::Type_booleanlist val = vx_core::vx_any_from_any(vx_core::t_booleanlist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_core::Type_boolean> listval = val->vx_listboolean();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_boolean()) {
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_boolean(), valsub));
        } else if (valsubtype == vx_core::t_booleanlist()) {
          vx_core::Type_booleanlist multi = vx_core::vx_any_from_any(vx_core::t_booleanlist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listboolean());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new booleanlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_core::Class_booleanlist();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_booleanlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_booleanlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_booleanlist::vx_empty() const {return vx_core::e_booleanlist();}
    vx_core::Type_any Class_booleanlist::vx_type() const {return vx_core::t_booleanlist();}

    vx_core::Type_typedef Class_booleanlist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "booleanlist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_boolean()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type collection)
  // class Class_collection {
    Abstract_collection::~Abstract_collection() {}

    Class_collection::Class_collection() : Abstract_collection::Abstract_collection() {
      vx_core::refcount += 1;
    }
    Class_collection::~Class_collection() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_collection::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_collection(), vals);
    }
    vx_core::Type_any Class_collection::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_collection output = vx_core::e_collection();
      return output;
    }

    vx_core::Type_msgblock Class_collection::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_collection::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_collection::vx_empty() const {return vx_core::e_collection();}
    vx_core::Type_any Class_collection::vx_type() const {return vx_core::t_collection();}

    vx_core::Type_typedef Class_collection::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "collection", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_list(), vx_core::t_map()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type compilelanguages)
  // class Class_compilelanguages {
    Abstract_compilelanguages::~Abstract_compilelanguages() {}

    Class_compilelanguages::Class_compilelanguages() : Abstract_compilelanguages::Abstract_compilelanguages() {
      vx_core::refcount += 1;
    }
    Class_compilelanguages::~Class_compilelanguages() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_compilelanguages::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_compilelanguages(), vals);
    }
    vx_core::Type_any Class_compilelanguages::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_compilelanguages output = vx_core::e_compilelanguages();
      return output;
    }

    vx_core::Type_msgblock Class_compilelanguages::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_compilelanguages::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_compilelanguages::vx_empty() const {return vx_core::e_compilelanguages();}
    vx_core::Type_any Class_compilelanguages::vx_type() const {return vx_core::t_compilelanguages();}

    vx_core::Type_typedef Class_compilelanguages::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "compilelanguages", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type connect)
  // class Class_connect {
    Abstract_connect::~Abstract_connect() {}

    Class_connect::Class_connect() : Abstract_connect::Abstract_connect() {
      vx_core::refcount += 1;
    }
    Class_connect::~Class_connect() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_connect::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_connect(), vals);
    }
    vx_core::Type_any Class_connect::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_connect output = vx_core::e_connect();
      return output;
    }

    vx_core::Type_msgblock Class_connect::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_connect::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_connect::vx_empty() const {return vx_core::e_connect();}
    vx_core::Type_any Class_connect::vx_type() const {return vx_core::t_connect();}

    vx_core::Type_typedef Class_connect::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "connect", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type connectlist)
  // class Class_connectlist {
    Abstract_connectlist::~Abstract_connectlist() {}

    Class_connectlist::Class_connectlist() : Abstract_connectlist::Abstract_connectlist() {
      vx_core::refcount += 1;
    }
    Class_connectlist::~Class_connectlist() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_connectlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_core::Type_connect Class_connectlist::vx_get_connect(vx_core::Type_int index) const {
      vx_core::Type_connect output = vx_core::e_connect();
      long iindex = index->vx_int();
      std::vector<vx_core::Type_connect> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_connect> Class_connectlist::vx_listconnect() const {return vx_p_list;}

    vx_core::Type_any vx_core::Class_connectlist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_connect(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_connectlist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_core::Type_connectlist output = vx_core::e_connectlist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_core::Type_connect> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_connect()) {
          vx_core::Type_connect castval = vx_core::vx_any_from_any(vx_core::t_connect(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(connectlist) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_connectlist();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_connectlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_connectlist(), vals);
    }
    vx_core::Type_any Class_connectlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_connectlist output = vx_core::e_connectlist();
      vx_core::Type_connectlist val = vx_core::vx_any_from_any(vx_core::t_connectlist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_core::Type_connect> listval = val->vx_listconnect();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_connect()) {
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_connect(), valsub));
        } else if (valsubtype == vx_core::t_connectlist()) {
          vx_core::Type_connectlist multi = vx_core::vx_any_from_any(vx_core::t_connectlist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listconnect());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new connectlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_core::Class_connectlist();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_connectlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_connectlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_connectlist::vx_empty() const {return vx_core::e_connectlist();}
    vx_core::Type_any Class_connectlist::vx_type() const {return vx_core::t_connectlist();}

    vx_core::Type_typedef Class_connectlist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "connectlist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_connect()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type connectmap)
  // class Class_connectmap {
    Abstract_connectmap::~Abstract_connectmap() {}

    Class_connectmap::Class_connectmap() : Abstract_connectmap::Abstract_connectmap() {
      vx_core::refcount += 1;
    }
    Class_connectmap::~Class_connectmap() {
      vx_core::refcount -= 1;
    }
    // vx_map()
    vx_core::vx_Type_mapany Class_connectmap::vx_map() const {
      vx_core::vx_Type_mapany output;
      return vx_core::vx_map_from_map(vx_core::t_any(), this->vx_p_map);
      return output;
    }

    // vx_get_connect(key)
    vx_core::Type_connect Class_connectmap::vx_get_connect(vx_core::Type_string key) const {
      vx_core::Type_connect output = vx_core::e_connect();
      const vx_core::Class_connectmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_connect> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_core::e_connect());
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_connectmap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_connect(key);
    }

    // vx_mapconnect()
    std::map<std::string, vx_core::Type_connect> Class_connectmap::vx_mapconnect() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_connectmap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_core::Type_connectmap output = vx_core::e_connectmap();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::map<std::string, vx_core::Type_connect> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_connect()) {
          vx_core::Type_connect castval = vx_core::vx_any_from_any(vx_core::t_connect(), val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(connectmap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_connectmap();
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_connectmap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_connectmap(), vals);
    }
    vx_core::Type_any Class_connectmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_connectmap output = vx_core::e_connectmap();
      vx_core::Type_connectmap valmap = vx_core::vx_any_from_any(vx_core::t_connectmap(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_core::Type_connect> mapval;
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
          vx_core::Type_connect valany;
          if (valsubtype == vx_core::t_connect()) {
            valany = vx_core::vx_any_from_any(vx_core::t_connect(), valsub);
          } else if (valsubtype == vx_core::t_connect()) {
            valany = vx_core::vx_any_from_any(vx_core::t_connect(), valsub);
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("Invalid Key/Value: " + key + " "  + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          if (valany != NULL) {
            mapval[key] = valany;
            key = "";
          }
        }
      }
      output = new vx_core::Class_connectmap();
      output->vx_p_map = mapval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_connectmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_connectmap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_connectmap::vx_empty() const {return vx_core::e_connectmap();}
    vx_core::Type_any Class_connectmap::vx_type() const {return vx_core::t_connectmap();}

    vx_core::Type_typedef Class_connectmap::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "connectmap", // name
        ":map", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_connect()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type const)
  // class Class_const {
    Abstract_const::~Abstract_const() {}

    Class_const::Class_const() : Abstract_const::Abstract_const() {
      vx_core::refcount += 1;
    }
    Class_const::~Class_const() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_const::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_const(), vals);
    }
    vx_core::Type_any Class_const::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_const output = vx_core::e_const();
      return output;
    }

    vx_core::Type_msgblock Class_const::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_const::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_const::vx_empty() const {return vx_core::e_const();}
    vx_core::Type_any Class_const::vx_type() const {return vx_core::t_const();}

    vx_core::Type_typedef Class_const::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "const", // name
        ":const", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type constdef)
  // class Class_constdef {
    Abstract_constdef::~Abstract_constdef() {}

    Class_constdef::Class_constdef() : Abstract_constdef::Abstract_constdef() {
      vx_core::refcount += 1;
    }
    Class_constdef::~Class_constdef() {
      vx_core::refcount -= 1;
    }
    // pkgname()
    vx_core::Type_string Class_constdef::pkgname() const {
      vx_core::Type_string output = this->vx_p_pkgname;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // name()
    vx_core::Type_string Class_constdef::name() const {
      vx_core::Type_string output = this->vx_p_name;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // type()
    vx_core::Type_any Class_constdef::type() const {
      vx_core::Type_any output = this->vx_p_type;
      if (output == NULL) {
        output = vx_core::e_any();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_constdef::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":pkgname") {
        output = this->pkgname();
      } else if (skey == ":name") {
        output = this->name();
      } else if (skey == ":type") {
        output = this->type();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_constdef::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":pkgname"] = this->pkgname();
      output[":name"] = this->name();
      output[":type"] = this->type();
      return output;
    }

    vx_core::Type_any Class_constdef::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_constdef(), vals);
    }
    vx_core::Type_any Class_constdef::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_constdef output = vx_core::e_constdef();
      vx_core::Type_constdef val = vx_core::vx_any_from_any(vx_core::t_constdef(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_pkgname = val->pkgname();
      vx_core::Type_string vx_p_name = val->name();
      vx_core::Type_any vx_p_type = val->type();
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
          } else if (testkey == ":pkgname") {
            key = testkey;
          } else if (testkey == ":name") {
            key = testkey;
          } else if (testkey == ":type") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new constdef) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":pkgname") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_pkgname = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new constdef :pkgname " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":name") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_name = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new constdef :name " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":type") {
            if (valsubtype == vx_core::t_any()) {
              vx_p_type = vx_core::vx_any_from_any(vx_core::t_any(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new constdef :type " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new constdef) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_core::Class_constdef();
      output->vx_p_pkgname = vx_p_pkgname;
      output->vx_p_name = vx_p_name;
      output->vx_p_type = vx_p_type;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_constdef::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_constdef::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_constdef::vx_empty() const {return vx_core::e_constdef();}
    vx_core::Type_any Class_constdef::vx_type() const {return vx_core::t_constdef();}

    vx_core::Type_typedef Class_constdef::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "constdef", // name
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
    }

  //}

  // (type constlist)
  // class Class_constlist {
    Abstract_constlist::~Abstract_constlist() {}

    Class_constlist::Class_constlist() : Abstract_constlist::Abstract_constlist() {
      vx_core::refcount += 1;
    }
    Class_constlist::~Class_constlist() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_constlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_core::Type_const Class_constlist::vx_get_const(vx_core::Type_int index) const {
      vx_core::Type_const output = vx_core::e_const();
      long iindex = index->vx_int();
      std::vector<vx_core::Type_const> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_const> Class_constlist::vx_listconst() const {return vx_p_list;}

    vx_core::Type_any vx_core::Class_constlist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_const(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_constlist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_core::Type_constlist output = vx_core::e_constlist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_core::Type_const> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_const()) {
          vx_core::Type_const castval = vx_core::vx_any_from_any(vx_core::t_const(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(constlist) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_constlist();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_constlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_constlist(), vals);
    }
    vx_core::Type_any Class_constlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_constlist output = vx_core::e_constlist();
      vx_core::Type_constlist val = vx_core::vx_any_from_any(vx_core::t_constlist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_core::Type_const> listval = val->vx_listconst();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_const()) {
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_const(), valsub));
        } else if (valsubtype == vx_core::t_constlist()) {
          vx_core::Type_constlist multi = vx_core::vx_any_from_any(vx_core::t_constlist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listconst());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new constlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_core::Class_constlist();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_constlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_constlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_constlist::vx_empty() const {return vx_core::e_constlist();}
    vx_core::Type_any Class_constlist::vx_type() const {return vx_core::t_constlist();}

    vx_core::Type_typedef Class_constlist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "constlist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_const()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type constmap)
  // class Class_constmap {
    Abstract_constmap::~Abstract_constmap() {}

    Class_constmap::Class_constmap() : Abstract_constmap::Abstract_constmap() {
      vx_core::refcount += 1;
    }
    Class_constmap::~Class_constmap() {
      vx_core::refcount -= 1;
    }
    // vx_map()
    vx_core::vx_Type_mapany Class_constmap::vx_map() const {
      vx_core::vx_Type_mapany output;
      return vx_core::vx_map_from_map(vx_core::t_any(), this->vx_p_map);
      return output;
    }

    // vx_get_const(key)
    vx_core::Type_const Class_constmap::vx_get_const(vx_core::Type_string key) const {
      vx_core::Type_const output = vx_core::e_const();
      const vx_core::Class_constmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_const> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_core::e_const());
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_constmap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_const(key);
    }

    // vx_mapconst()
    std::map<std::string, vx_core::Type_const> Class_constmap::vx_mapconst() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_constmap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_core::Type_constmap output = vx_core::e_constmap();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::map<std::string, vx_core::Type_const> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_const()) {
          vx_core::Type_const castval = vx_core::vx_any_from_any(vx_core::t_const(), val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(constmap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_constmap();
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_constmap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_constmap(), vals);
    }
    vx_core::Type_any Class_constmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_constmap output = vx_core::e_constmap();
      vx_core::Type_constmap valmap = vx_core::vx_any_from_any(vx_core::t_constmap(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_core::Type_const> mapval;
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
          vx_core::Type_const valany;
          if (valsubtype == vx_core::t_const()) {
            valany = vx_core::vx_any_from_any(vx_core::t_const(), valsub);
          } else if (valsubtype == vx_core::t_const()) {
            valany = vx_core::vx_any_from_any(vx_core::t_const(), valsub);
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("Invalid Key/Value: " + key + " "  + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          if (valany != NULL) {
            mapval[key] = valany;
            key = "";
          }
        }
      }
      output = new vx_core::Class_constmap();
      output->vx_p_map = mapval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_constmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_constmap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_constmap::vx_empty() const {return vx_core::e_constmap();}
    vx_core::Type_any Class_constmap::vx_type() const {return vx_core::t_constmap();}

    vx_core::Type_typedef Class_constmap::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "constmap", // name
        ":map", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_const()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type context)
  // class Class_context {
    Abstract_context::~Abstract_context() {}

    Class_context::Class_context() : Abstract_context::Abstract_context() {
      vx_core::refcount += 1;
    }
    Class_context::~Class_context() {
      vx_core::refcount -= 1;
    }
    // code()
    vx_core::Type_string Class_context::code() const {
      vx_core::Type_string output = this->vx_p_code;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // session()
    vx_core::Type_session Class_context::session() const {
      vx_core::Type_session output = this->vx_p_session;
      if (output == NULL) {
        output = vx_core::e_session();
      }
      return output;
    }

    // setting()
    vx_core::Type_setting Class_context::setting() const {
      vx_core::Type_setting output = this->vx_p_setting;
      if (output == NULL) {
        output = vx_core::e_setting();
      }
      return output;
    }

    // state()
    vx_core::Type_state Class_context::state() const {
      vx_core::Type_state output = this->vx_p_state;
      if (output == NULL) {
        output = vx_core::e_state();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_context::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":code") {
        output = this->code();
      } else if (skey == ":session") {
        output = this->session();
      } else if (skey == ":setting") {
        output = this->setting();
      } else if (skey == ":state") {
        output = this->state();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_context::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":code"] = this->code();
      output[":session"] = this->session();
      output[":setting"] = this->setting();
      output[":state"] = this->state();
      return output;
    }

    vx_core::Type_any Class_context::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_context(), vals);
    }
    vx_core::Type_any Class_context::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_context output = vx_core::e_context();
      vx_core::Type_context val = vx_core::vx_any_from_any(vx_core::t_context(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_code = val->code();
      vx_core::Type_session vx_p_session = val->session();
      vx_core::Type_setting vx_p_setting = val->setting();
      vx_core::Type_state vx_p_state = val->state();
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
          } else if (testkey == ":code") {
            key = testkey;
          } else if (testkey == ":session") {
            key = testkey;
          } else if (testkey == ":setting") {
            key = testkey;
          } else if (testkey == ":state") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new context) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":code") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_code = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new context :code " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":session") {
            if (valsubtype == vx_core::t_session()) {
              vx_p_session = vx_core::vx_any_from_any(vx_core::t_session(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new context :session " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":setting") {
            if (valsubtype == vx_core::t_setting()) {
              vx_p_setting = vx_core::vx_any_from_any(vx_core::t_setting(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new context :setting " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":state") {
            if (valsubtype == vx_core::t_state()) {
              vx_p_state = vx_core::vx_any_from_any(vx_core::t_state(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new context :state " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new context) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_core::Class_context();
      output->vx_p_code = vx_p_code;
      output->vx_p_session = vx_p_session;
      output->vx_p_setting = vx_p_setting;
      output->vx_p_state = vx_p_state;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_context::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_context::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_context::vx_empty() const {return vx_core::e_context();}
    vx_core::Type_any Class_context::vx_type() const {return vx_core::t_context();}

    vx_core::Type_typedef Class_context::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "context", // name
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
    }

  //}

  // (type error)
  // class Class_error {
    Abstract_error::~Abstract_error() {}

    Class_error::Class_error() : Abstract_error::Abstract_error() {
      vx_core::refcount += 1;
    }
    Class_error::~Class_error() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_error::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_error(), vals);
    }
    vx_core::Type_any Class_error::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_error output = vx_core::e_error();
      return output;
    }

    vx_core::Type_msgblock Class_error::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_error::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_error::vx_empty() const {return vx_core::e_error();}
    vx_core::Type_any Class_error::vx_type() const {return vx_core::t_error();}

    vx_core::Type_typedef Class_error::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "error", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type funclist)
  // class Class_funclist {
    Abstract_funclist::~Abstract_funclist() {}

    Class_funclist::Class_funclist() : Abstract_funclist::Abstract_funclist() {
      vx_core::refcount += 1;
    }
    Class_funclist::~Class_funclist() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_funclist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_core::Type_func Class_funclist::vx_get_func(vx_core::Type_int index) const {
      vx_core::Type_func output = vx_core::e_func();
      long iindex = index->vx_int();
      std::vector<vx_core::Type_func> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_func> Class_funclist::vx_listfunc() const {return vx_p_list;}

    vx_core::Type_any vx_core::Class_funclist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_func(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_funclist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_core::Type_funclist output = vx_core::e_funclist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_core::Type_func> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_func()) {
          vx_core::Type_func castval = vx_core::vx_any_from_any(vx_core::t_func(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(funclist) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_funclist();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_funclist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_funclist(), vals);
    }
    vx_core::Type_any Class_funclist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_funclist output = vx_core::e_funclist();
      vx_core::Type_funclist val = vx_core::vx_any_from_any(vx_core::t_funclist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_core::Type_func> listval = val->vx_listfunc();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_func()) {
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_func(), valsub));
        } else if (valsubtype == vx_core::t_funclist()) {
          vx_core::Type_funclist multi = vx_core::vx_any_from_any(vx_core::t_funclist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listfunc());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new funclist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_core::Class_funclist();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_funclist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_funclist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_funclist::vx_empty() const {return vx_core::e_funclist();}
    vx_core::Type_any Class_funclist::vx_type() const {return vx_core::t_funclist();}

    vx_core::Type_typedef Class_funclist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "funclist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_func()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type funcmap)
  // class Class_funcmap {
    Abstract_funcmap::~Abstract_funcmap() {}

    Class_funcmap::Class_funcmap() : Abstract_funcmap::Abstract_funcmap() {
      vx_core::refcount += 1;
    }
    Class_funcmap::~Class_funcmap() {
      vx_core::refcount -= 1;
    }
    // vx_map()
    vx_core::vx_Type_mapany Class_funcmap::vx_map() const {
      vx_core::vx_Type_mapany output;
      return vx_core::vx_map_from_map(vx_core::t_any(), this->vx_p_map);
      return output;
    }

    // vx_get_func(key)
    vx_core::Type_func Class_funcmap::vx_get_func(vx_core::Type_string key) const {
      vx_core::Type_func output = vx_core::e_func();
      const vx_core::Class_funcmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_func> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_core::e_func());
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_funcmap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_func(key);
    }

    // vx_mapfunc()
    std::map<std::string, vx_core::Type_func> Class_funcmap::vx_mapfunc() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_funcmap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_core::Type_funcmap output = vx_core::e_funcmap();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::map<std::string, vx_core::Type_func> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_func()) {
          vx_core::Type_func castval = vx_core::vx_any_from_any(vx_core::t_func(), val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(funcmap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_funcmap();
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_funcmap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_funcmap(), vals);
    }
    vx_core::Type_any Class_funcmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_funcmap output = vx_core::e_funcmap();
      vx_core::Type_funcmap valmap = vx_core::vx_any_from_any(vx_core::t_funcmap(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_core::Type_func> mapval;
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
          vx_core::Type_func valany;
          if (valsubtype == vx_core::t_func()) {
            valany = vx_core::vx_any_from_any(vx_core::t_func(), valsub);
          } else if (valsubtype == vx_core::t_func()) {
            valany = vx_core::vx_any_from_any(vx_core::t_func(), valsub);
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("Invalid Key/Value: " + key + " "  + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          if (valany != NULL) {
            mapval[key] = valany;
            key = "";
          }
        }
      }
      output = new vx_core::Class_funcmap();
      output->vx_p_map = mapval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_funcmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_funcmap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_funcmap::vx_empty() const {return vx_core::e_funcmap();}
    vx_core::Type_any Class_funcmap::vx_type() const {return vx_core::t_funcmap();}

    vx_core::Type_typedef Class_funcmap::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "funcmap", // name
        ":map", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_func()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type intlist)
  // class Class_intlist {
    Abstract_intlist::~Abstract_intlist() {}

    Class_intlist::Class_intlist() : Abstract_intlist::Abstract_intlist() {
      vx_core::refcount += 1;
    }
    Class_intlist::~Class_intlist() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_intlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_core::Type_int Class_intlist::vx_get_int(vx_core::Type_int index) const {
      vx_core::Type_int output = vx_core::e_int();
      long iindex = index->vx_int();
      std::vector<vx_core::Type_int> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_int> Class_intlist::vx_listint() const {return vx_p_list;}

    vx_core::Type_any vx_core::Class_intlist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_int(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_intlist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_core::Type_intlist output = vx_core::e_intlist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_core::Type_int> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_int()) {
          vx_core::Type_int castval = vx_core::vx_any_from_any(vx_core::t_int(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(intlist) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_intlist();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_intlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_intlist(), vals);
    }
    vx_core::Type_any Class_intlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_intlist output = vx_core::e_intlist();
      vx_core::Type_intlist val = vx_core::vx_any_from_any(vx_core::t_intlist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_core::Type_int> listval = val->vx_listint();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_int()) {
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_int(), valsub));
        } else if (valsubtype == vx_core::t_intlist()) {
          vx_core::Type_intlist multi = vx_core::vx_any_from_any(vx_core::t_intlist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listint());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new intlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_core::Class_intlist();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_intlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_intlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_intlist::vx_empty() const {return vx_core::e_intlist();}
    vx_core::Type_any Class_intlist::vx_type() const {return vx_core::t_intlist();}

    vx_core::Type_typedef Class_intlist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "intlist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_int()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type intmap)
  // class Class_intmap {
    Abstract_intmap::~Abstract_intmap() {}

    Class_intmap::Class_intmap() : Abstract_intmap::Abstract_intmap() {
      vx_core::refcount += 1;
    }
    Class_intmap::~Class_intmap() {
      vx_core::refcount -= 1;
    }
    // vx_map()
    vx_core::vx_Type_mapany Class_intmap::vx_map() const {
      vx_core::vx_Type_mapany output;
      return vx_core::vx_map_from_map(vx_core::t_any(), this->vx_p_map);
      return output;
    }

    // vx_get_int(key)
    vx_core::Type_int Class_intmap::vx_get_int(vx_core::Type_string key) const {
      vx_core::Type_int output = vx_core::e_int();
      const vx_core::Class_intmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_int> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_core::e_int());
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_intmap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_int(key);
    }

    // vx_mapint()
    std::map<std::string, vx_core::Type_int> Class_intmap::vx_mapint() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_intmap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_core::Type_intmap output = vx_core::e_intmap();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::map<std::string, vx_core::Type_int> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_int()) {
          vx_core::Type_int castval = vx_core::vx_any_from_any(vx_core::t_int(), val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(intmap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_intmap();
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_intmap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_intmap(), vals);
    }
    vx_core::Type_any Class_intmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_intmap output = vx_core::e_intmap();
      vx_core::Type_intmap valmap = vx_core::vx_any_from_any(vx_core::t_intmap(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_core::Type_int> mapval;
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
          vx_core::Type_int valany;
          if (valsubtype == vx_core::t_int()) {
            valany = vx_core::vx_any_from_any(vx_core::t_int(), valsub);
          } else if (valsubtype == vx_core::t_int()) {
            valany = vx_core::vx_any_from_any(vx_core::t_int(), valsub);
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("Invalid Key/Value: " + key + " "  + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          if (valany != NULL) {
            mapval[key] = valany;
            key = "";
          }
        }
      }
      output = new vx_core::Class_intmap();
      output->vx_p_map = mapval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_intmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_intmap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_intmap::vx_empty() const {return vx_core::e_intmap();}
    vx_core::Type_any Class_intmap::vx_type() const {return vx_core::t_intmap();}

    vx_core::Type_typedef Class_intmap::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "intmap", // name
        ":map", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_int()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type listtype)
  // class Class_listtype {
    Abstract_listtype::~Abstract_listtype() {}

    Class_listtype::Class_listtype() : Abstract_listtype::Abstract_listtype() {
      vx_core::refcount += 1;
    }
    Class_listtype::~Class_listtype() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_listtype::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_listtype(), vals);
    }
    vx_core::Type_any Class_listtype::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_listtype output = vx_core::e_listtype();
      return output;
    }

    vx_core::Type_msgblock Class_listtype::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_listtype::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_listtype::vx_empty() const {return vx_core::e_listtype();}
    vx_core::Type_any Class_listtype::vx_type() const {return vx_core::t_listtype();}

    vx_core::Type_typedef Class_listtype::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "listtype", // name
        ":type", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type maptype)
  // class Class_maptype {
    Abstract_maptype::~Abstract_maptype() {}

    Class_maptype::Class_maptype() : Abstract_maptype::Abstract_maptype() {
      vx_core::refcount += 1;
    }
    Class_maptype::~Class_maptype() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_maptype::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_maptype(), vals);
    }
    vx_core::Type_any Class_maptype::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_maptype output = vx_core::e_maptype();
      return output;
    }

    vx_core::Type_msgblock Class_maptype::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_maptype::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_maptype::vx_empty() const {return vx_core::e_maptype();}
    vx_core::Type_any Class_maptype::vx_type() const {return vx_core::t_maptype();}

    vx_core::Type_typedef Class_maptype::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "maptype", // name
        ":type", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type mempool)
  // class Class_mempool {
    Abstract_mempool::~Abstract_mempool() {}

    Class_mempool::Class_mempool() : Abstract_mempool::Abstract_mempool() {
      vx_core::refcount += 1;
    }
    Class_mempool::~Class_mempool() {
      vx_core::refcount -= 1;
    }
    // valuepool()
    vx_core::Type_value Class_mempool::valuepool() const {
      vx_core::Type_value output = this->vx_p_valuepool;
      if (output == NULL) {
        output = vx_core::e_value();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_mempool::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":valuepool") {
        output = this->valuepool();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_mempool::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":valuepool"] = this->valuepool();
      return output;
    }

    vx_core::Type_any Class_mempool::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_mempool(), vals);
    }
    vx_core::Type_any Class_mempool::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_mempool output = vx_core::e_mempool();
      vx_core::Type_mempool val = vx_core::vx_any_from_any(vx_core::t_mempool(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_value vx_p_valuepool = val->valuepool();
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
          } else if (testkey == ":valuepool") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new mempool) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":valuepool") {
            if (valsubtype == vx_core::t_value()) {
              vx_p_valuepool = vx_core::vx_any_from_any(vx_core::t_value(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new mempool :valuepool " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new mempool) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_core::Class_mempool();
      output->vx_p_valuepool = vx_p_valuepool;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_mempool::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_mempool::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_mempool::vx_empty() const {return vx_core::e_mempool();}
    vx_core::Type_any Class_mempool::vx_type() const {return vx_core::t_mempool();}

    vx_core::Type_typedef Class_mempool::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "mempool", // name
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
    }

  //}

  // (type none)
  // class Class_none {
    Abstract_none::~Abstract_none() {}

    Class_none::Class_none() : Abstract_none::Abstract_none() {
      vx_core::refcount += 1;
    }
    Class_none::~Class_none() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_none::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_none(), vals);
    }
    vx_core::Type_any Class_none::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_none output = vx_core::e_none();
      return output;
    }

    vx_core::Type_msgblock Class_none::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_none::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_none::vx_empty() const {return vx_core::e_none();}
    vx_core::Type_any Class_none::vx_type() const {return vx_core::t_none();}

    vx_core::Type_typedef Class_none::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "none", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type notype)
  // class Class_notype {
    Abstract_notype::~Abstract_notype() {}

    Class_notype::Class_notype() : Abstract_notype::Abstract_notype() {
      vx_core::refcount += 1;
    }
    Class_notype::~Class_notype() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_notype::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_notype(), vals);
    }
    vx_core::Type_any Class_notype::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_notype output = vx_core::e_notype();
      return output;
    }

    vx_core::Type_msgblock Class_notype::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_notype::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_notype::vx_empty() const {return vx_core::e_notype();}
    vx_core::Type_any Class_notype::vx_type() const {return vx_core::t_notype();}

    vx_core::Type_typedef Class_notype::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "notype", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type numberlist)
  // class Class_numberlist {
    Abstract_numberlist::~Abstract_numberlist() {}

    Class_numberlist::Class_numberlist() : Abstract_numberlist::Abstract_numberlist() {
      vx_core::refcount += 1;
    }
    Class_numberlist::~Class_numberlist() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_numberlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_core::Type_number Class_numberlist::vx_get_number(vx_core::Type_int index) const {
      vx_core::Type_number output = vx_core::e_number();
      long iindex = index->vx_int();
      std::vector<vx_core::Type_number> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_number> Class_numberlist::vx_listnumber() const {return vx_p_list;}

    vx_core::Type_any vx_core::Class_numberlist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_number(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_numberlist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_core::Type_numberlist output = vx_core::e_numberlist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_core::Type_number> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_number()) {
          vx_core::Type_number castval = vx_core::vx_any_from_any(vx_core::t_number(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(numberlist) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_numberlist();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_numberlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_numberlist(), vals);
    }
    vx_core::Type_any Class_numberlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_numberlist output = vx_core::e_numberlist();
      vx_core::Type_numberlist val = vx_core::vx_any_from_any(vx_core::t_numberlist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_core::Type_number> listval = val->vx_listnumber();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_number()) {
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_number(), valsub));
        } else if (valsubtype == vx_core::t_numberlist()) {
          vx_core::Type_numberlist multi = vx_core::vx_any_from_any(vx_core::t_numberlist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listnumber());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new numberlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_core::Class_numberlist();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_numberlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_numberlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_numberlist::vx_empty() const {return vx_core::e_numberlist();}
    vx_core::Type_any Class_numberlist::vx_type() const {return vx_core::t_numberlist();}

    vx_core::Type_typedef Class_numberlist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "numberlist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type numbermap)
  // class Class_numbermap {
    Abstract_numbermap::~Abstract_numbermap() {}

    Class_numbermap::Class_numbermap() : Abstract_numbermap::Abstract_numbermap() {
      vx_core::refcount += 1;
    }
    Class_numbermap::~Class_numbermap() {
      vx_core::refcount -= 1;
    }
    // vx_map()
    vx_core::vx_Type_mapany Class_numbermap::vx_map() const {
      vx_core::vx_Type_mapany output;
      return vx_core::vx_map_from_map(vx_core::t_any(), this->vx_p_map);
      return output;
    }

    // vx_get_number(key)
    vx_core::Type_number Class_numbermap::vx_get_number(vx_core::Type_string key) const {
      vx_core::Type_number output = vx_core::e_number();
      const vx_core::Class_numbermap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_number> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_core::e_number());
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_numbermap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_number(key);
    }

    // vx_mapnumber()
    std::map<std::string, vx_core::Type_number> Class_numbermap::vx_mapnumber() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_numbermap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_core::Type_numbermap output = vx_core::e_numbermap();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::map<std::string, vx_core::Type_number> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_number()) {
          vx_core::Type_number castval = vx_core::vx_any_from_any(vx_core::t_number(), val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(numbermap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_numbermap();
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_numbermap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_numbermap(), vals);
    }
    vx_core::Type_any Class_numbermap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_numbermap output = vx_core::e_numbermap();
      vx_core::Type_numbermap valmap = vx_core::vx_any_from_any(vx_core::t_numbermap(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_core::Type_number> mapval;
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
          vx_core::Type_number valany;
          if (valsubtype == vx_core::t_number()) {
            valany = vx_core::vx_any_from_any(vx_core::t_number(), valsub);
          } else if (valsubtype == vx_core::t_number()) {
            valany = vx_core::vx_any_from_any(vx_core::t_number(), valsub);
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("Invalid Key/Value: " + key + " "  + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          if (valany != NULL) {
            mapval[key] = valany;
            key = "";
          }
        }
      }
      output = new vx_core::Class_numbermap();
      output->vx_p_map = mapval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_numbermap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_numbermap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_numbermap::vx_empty() const {return vx_core::e_numbermap();}
    vx_core::Type_any Class_numbermap::vx_type() const {return vx_core::t_numbermap();}

    vx_core::Type_typedef Class_numbermap::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "numbermap", // name
        ":map", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type package)
  // class Class_package {
    Abstract_package::~Abstract_package() {}

    Class_package::Class_package() : Abstract_package::Abstract_package() {
      vx_core::refcount += 1;
    }
    Class_package::~Class_package() {
      vx_core::refcount -= 1;
    }
    // vx_get_any(key)
    vx_core::Type_any Class_package::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_package::vx_map() const {
      vx_core::vx_Type_mapany output;
      return output;
    }

    vx_core::Type_any Class_package::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_package(), vals);
    }
    vx_core::Type_any Class_package::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_package output = vx_core::e_package();
      vx_core::Type_package val = vx_core::vx_any_from_any(vx_core::t_package(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_package::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_package::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_package::vx_empty() const {return vx_core::e_package();}
    vx_core::Type_any Class_package::vx_type() const {return vx_core::t_package();}

    vx_core::Type_typedef Class_package::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "package", // name
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
    }

  //}

  // (type packagemap)
  // class Class_packagemap {
    Abstract_packagemap::~Abstract_packagemap() {}

    Class_packagemap::Class_packagemap() : Abstract_packagemap::Abstract_packagemap() {
      vx_core::refcount += 1;
    }
    Class_packagemap::~Class_packagemap() {
      vx_core::refcount -= 1;
    }
    // vx_map()
    vx_core::vx_Type_mapany Class_packagemap::vx_map() const {
      vx_core::vx_Type_mapany output;
      return vx_core::vx_map_from_map(vx_core::t_any(), this->vx_p_map);
      return output;
    }

    // vx_get_package(key)
    vx_core::Type_package Class_packagemap::vx_get_package(vx_core::Type_string key) const {
      vx_core::Type_package output = vx_core::e_package();
      const vx_core::Class_packagemap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_package> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_core::e_package());
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_packagemap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_package(key);
    }

    // vx_mappackage()
    std::map<std::string, vx_core::Type_package> Class_packagemap::vx_mappackage() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_packagemap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_core::Type_packagemap output = vx_core::e_packagemap();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::map<std::string, vx_core::Type_package> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_package()) {
          vx_core::Type_package castval = vx_core::vx_any_from_any(vx_core::t_package(), val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(packagemap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_packagemap();
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_packagemap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_packagemap(), vals);
    }
    vx_core::Type_any Class_packagemap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_packagemap output = vx_core::e_packagemap();
      vx_core::Type_packagemap valmap = vx_core::vx_any_from_any(vx_core::t_packagemap(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_core::Type_package> mapval;
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
          vx_core::Type_package valany;
          if (valsubtype == vx_core::t_package()) {
            valany = vx_core::vx_any_from_any(vx_core::t_package(), valsub);
          } else if (valsubtype == vx_core::t_package()) {
            valany = vx_core::vx_any_from_any(vx_core::t_package(), valsub);
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("Invalid Key/Value: " + key + " "  + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          if (valany != NULL) {
            mapval[key] = valany;
            key = "";
          }
        }
      }
      output = new vx_core::Class_packagemap();
      output->vx_p_map = mapval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_packagemap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_packagemap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_packagemap::vx_empty() const {return vx_core::e_packagemap();}
    vx_core::Type_any Class_packagemap::vx_type() const {return vx_core::t_packagemap();}

    vx_core::Type_typedef Class_packagemap::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "packagemap", // name
        ":map", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_package()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type permission)
  // class Class_permission {
    Abstract_permission::~Abstract_permission() {}

    Class_permission::Class_permission() : Abstract_permission::Abstract_permission() {
      vx_core::refcount += 1;
    }
    Class_permission::~Class_permission() {
      vx_core::refcount -= 1;
    }
    // id()
    vx_core::Type_string Class_permission::id() const {
      vx_core::Type_string output = this->vx_p_id;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_permission::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":id") {
        output = this->id();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_permission::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":id"] = this->id();
      return output;
    }

    vx_core::Type_any Class_permission::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_permission(), vals);
    }
    vx_core::Type_any Class_permission::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_permission output = vx_core::e_permission();
      vx_core::Type_permission val = vx_core::vx_any_from_any(vx_core::t_permission(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_id = val->id();
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
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new permission) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":id") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_id = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new permission :id " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new permission) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_core::Class_permission();
      output->vx_p_id = vx_p_id;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_permission::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_permission::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_permission::vx_empty() const {return vx_core::e_permission();}
    vx_core::Type_any Class_permission::vx_type() const {return vx_core::t_permission();}

    vx_core::Type_typedef Class_permission::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "permission", // name
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
    }

  //}

  // (type permissionlist)
  // class Class_permissionlist {
    Abstract_permissionlist::~Abstract_permissionlist() {}

    Class_permissionlist::Class_permissionlist() : Abstract_permissionlist::Abstract_permissionlist() {
      vx_core::refcount += 1;
    }
    Class_permissionlist::~Class_permissionlist() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_permissionlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_core::Type_permission Class_permissionlist::vx_get_permission(vx_core::Type_int index) const {
      vx_core::Type_permission output = vx_core::e_permission();
      long iindex = index->vx_int();
      std::vector<vx_core::Type_permission> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_permission> Class_permissionlist::vx_listpermission() const {return vx_p_list;}

    vx_core::Type_any vx_core::Class_permissionlist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_permission(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_permissionlist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_core::Type_permissionlist output = vx_core::e_permissionlist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_core::Type_permission> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_permission()) {
          vx_core::Type_permission castval = vx_core::vx_any_from_any(vx_core::t_permission(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(permissionlist) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_permissionlist();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_permissionlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_permissionlist(), vals);
    }
    vx_core::Type_any Class_permissionlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_permissionlist output = vx_core::e_permissionlist();
      vx_core::Type_permissionlist val = vx_core::vx_any_from_any(vx_core::t_permissionlist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_core::Type_permission> listval = val->vx_listpermission();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_permission()) {
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_permission(), valsub));
        } else if (valsubtype == vx_core::t_permissionlist()) {
          vx_core::Type_permissionlist multi = vx_core::vx_any_from_any(vx_core::t_permissionlist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listpermission());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new permissionlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_core::Class_permissionlist();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_permissionlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_permissionlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_permissionlist::vx_empty() const {return vx_core::e_permissionlist();}
    vx_core::Type_any Class_permissionlist::vx_type() const {return vx_core::t_permissionlist();}

    vx_core::Type_typedef Class_permissionlist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "permissionlist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_permission()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type permissionmap)
  // class Class_permissionmap {
    Abstract_permissionmap::~Abstract_permissionmap() {}

    Class_permissionmap::Class_permissionmap() : Abstract_permissionmap::Abstract_permissionmap() {
      vx_core::refcount += 1;
    }
    Class_permissionmap::~Class_permissionmap() {
      vx_core::refcount -= 1;
    }
    // vx_map()
    vx_core::vx_Type_mapany Class_permissionmap::vx_map() const {
      vx_core::vx_Type_mapany output;
      return vx_core::vx_map_from_map(vx_core::t_any(), this->vx_p_map);
      return output;
    }

    // vx_get_permission(key)
    vx_core::Type_permission Class_permissionmap::vx_get_permission(vx_core::Type_string key) const {
      vx_core::Type_permission output = vx_core::e_permission();
      const vx_core::Class_permissionmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_permission> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_core::e_permission());
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_permissionmap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_permission(key);
    }

    // vx_mappermission()
    std::map<std::string, vx_core::Type_permission> Class_permissionmap::vx_mappermission() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_permissionmap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_core::Type_permissionmap output = vx_core::e_permissionmap();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::map<std::string, vx_core::Type_permission> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_permission()) {
          vx_core::Type_permission castval = vx_core::vx_any_from_any(vx_core::t_permission(), val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(permissionmap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_permissionmap();
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_permissionmap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_permissionmap(), vals);
    }
    vx_core::Type_any Class_permissionmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_permissionmap output = vx_core::e_permissionmap();
      vx_core::Type_permissionmap valmap = vx_core::vx_any_from_any(vx_core::t_permissionmap(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_core::Type_permission> mapval;
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
          vx_core::Type_permission valany;
          if (valsubtype == vx_core::t_permission()) {
            valany = vx_core::vx_any_from_any(vx_core::t_permission(), valsub);
          } else if (valsubtype == vx_core::t_permission()) {
            valany = vx_core::vx_any_from_any(vx_core::t_permission(), valsub);
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("Invalid Key/Value: " + key + " "  + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          if (valany != NULL) {
            mapval[key] = valany;
            key = "";
          }
        }
      }
      output = new vx_core::Class_permissionmap();
      output->vx_p_map = mapval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_permissionmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_permissionmap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_permissionmap::vx_empty() const {return vx_core::e_permissionmap();}
    vx_core::Type_any Class_permissionmap::vx_type() const {return vx_core::t_permissionmap();}

    vx_core::Type_typedef Class_permissionmap::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "permissionmap", // name
        ":map", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_permission()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type security)
  // class Class_security {
    Abstract_security::~Abstract_security() {}

    Class_security::Class_security() : Abstract_security::Abstract_security() {
      vx_core::refcount += 1;
    }
    Class_security::~Class_security() {
      vx_core::refcount -= 1;
    }
    // permissions()
    vx_core::Type_permissionlist Class_security::permissions() const {
      vx_core::Type_permissionlist output = this->vx_p_permissions;
      if (output == NULL) {
        output = vx_core::e_permissionlist();
      }
      return output;
    }

    // permissionmap()
    vx_core::Type_permissionmap Class_security::permissionmap() const {
      vx_core::Type_permissionmap output = this->vx_p_permissionmap;
      if (output == NULL) {
        output = vx_core::e_permissionmap();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_security::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":permissions") {
        output = this->permissions();
      } else if (skey == ":permissionmap") {
        output = this->permissionmap();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_security::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":permissions"] = this->permissions();
      output[":permissionmap"] = this->permissionmap();
      return output;
    }

    vx_core::Type_any Class_security::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_security(), vals);
    }
    vx_core::Type_any Class_security::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_security output = vx_core::e_security();
      vx_core::Type_security val = vx_core::vx_any_from_any(vx_core::t_security(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_permissionlist vx_p_permissions = val->permissions();
      vx_core::Type_permissionmap vx_p_permissionmap = val->permissionmap();
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
          } else if (testkey == ":permissions") {
            key = testkey;
          } else if (testkey == ":permissionmap") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new security) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":permissions") {
            if (valsubtype == vx_core::t_permissionlist()) {
              vx_p_permissions = vx_core::vx_any_from_any(vx_core::t_permissionlist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new security :permissions " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":permissionmap") {
            if (valsubtype == vx_core::t_permissionmap()) {
              vx_p_permissionmap = vx_core::vx_any_from_any(vx_core::t_permissionmap(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new security :permissionmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new security) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_core::Class_security();
      output->vx_p_permissions = vx_p_permissions;
      output->vx_p_permissionmap = vx_p_permissionmap;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_security::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_security::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_security::vx_empty() const {return vx_core::e_security();}
    vx_core::Type_any Class_security::vx_type() const {return vx_core::t_security();}

    vx_core::Type_typedef Class_security::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "security", // name
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
    }

  //}

  // (type session)
  // class Class_session {
    Abstract_session::~Abstract_session() {}

    Class_session::Class_session() : Abstract_session::Abstract_session() {
      vx_core::refcount += 1;
    }
    Class_session::~Class_session() {
      vx_core::refcount -= 1;
    }
    // user()
    vx_core::Type_user Class_session::user() const {
      vx_core::Type_user output = this->vx_p_user;
      if (output == NULL) {
        output = vx_core::e_user();
      }
      return output;
    }

    // connectlist()
    vx_core::Type_connectlist Class_session::connectlist() const {
      vx_core::Type_connectlist output = this->vx_p_connectlist;
      if (output == NULL) {
        output = vx_core::e_connectlist();
      }
      return output;
    }

    // connectmap()
    vx_core::Type_connectmap Class_session::connectmap() const {
      vx_core::Type_connectmap output = this->vx_p_connectmap;
      if (output == NULL) {
        output = vx_core::e_connectmap();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_session::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":user") {
        output = this->user();
      } else if (skey == ":connectlist") {
        output = this->connectlist();
      } else if (skey == ":connectmap") {
        output = this->connectmap();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_session::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":user"] = this->user();
      output[":connectlist"] = this->connectlist();
      output[":connectmap"] = this->connectmap();
      return output;
    }

    vx_core::Type_any Class_session::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_session(), vals);
    }
    vx_core::Type_any Class_session::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_session output = vx_core::e_session();
      vx_core::Type_session val = vx_core::vx_any_from_any(vx_core::t_session(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_user vx_p_user = val->user();
      vx_core::Type_connectlist vx_p_connectlist = val->connectlist();
      vx_core::Type_connectmap vx_p_connectmap = val->connectmap();
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
          } else if (testkey == ":user") {
            key = testkey;
          } else if (testkey == ":connectlist") {
            key = testkey;
          } else if (testkey == ":connectmap") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new session) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":user") {
            if (valsubtype == vx_core::t_user()) {
              vx_p_user = vx_core::vx_any_from_any(vx_core::t_user(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new session :user " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":connectlist") {
            if (valsubtype == vx_core::t_connectlist()) {
              vx_p_connectlist = vx_core::vx_any_from_any(vx_core::t_connectlist(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new session :connectlist " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":connectmap") {
            if (valsubtype == vx_core::t_connectmap()) {
              vx_p_connectmap = vx_core::vx_any_from_any(vx_core::t_connectmap(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new session :connectmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new session) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_core::Class_session();
      output->vx_p_user = vx_p_user;
      output->vx_p_connectlist = vx_p_connectlist;
      output->vx_p_connectmap = vx_p_connectmap;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_session::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_session::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_session::vx_empty() const {return vx_core::e_session();}
    vx_core::Type_any Class_session::vx_type() const {return vx_core::t_session();}

    vx_core::Type_typedef Class_session::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "session", // name
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
    }

  //}

  // (type setting)
  // class Class_setting {
    Abstract_setting::~Abstract_setting() {}

    Class_setting::Class_setting() : Abstract_setting::Abstract_setting() {
      vx_core::refcount += 1;
    }
    Class_setting::~Class_setting() {
      vx_core::refcount -= 1;
    }
    // pathmap()
    vx_core::Type_stringmap Class_setting::pathmap() const {
      vx_core::Type_stringmap output = this->vx_p_pathmap;
      if (output == NULL) {
        output = vx_core::e_stringmap();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_setting::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":pathmap") {
        output = this->pathmap();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_setting::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":pathmap"] = this->pathmap();
      return output;
    }

    vx_core::Type_any Class_setting::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_setting(), vals);
    }
    vx_core::Type_any Class_setting::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_setting output = vx_core::e_setting();
      vx_core::Type_setting val = vx_core::vx_any_from_any(vx_core::t_setting(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_stringmap vx_p_pathmap = val->pathmap();
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
          } else if (testkey == ":pathmap") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new setting) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":pathmap") {
            if (valsubtype == vx_core::t_stringmap()) {
              vx_p_pathmap = vx_core::vx_any_from_any(vx_core::t_stringmap(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new setting :pathmap " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new setting) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_core::Class_setting();
      output->vx_p_pathmap = vx_p_pathmap;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_setting::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_setting::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_setting::vx_empty() const {return vx_core::e_setting();}
    vx_core::Type_any Class_setting::vx_type() const {return vx_core::t_setting();}

    vx_core::Type_typedef Class_setting::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "setting", // name
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
    }

  //}

  // (type state)
  // class Class_state {
    Abstract_state::~Abstract_state() {}

    Class_state::Class_state() : Abstract_state::Abstract_state() {
      vx_core::refcount += 1;
    }
    Class_state::~Class_state() {
      vx_core::refcount -= 1;
    }
    // vx_map()
    vx_core::vx_Type_mapany Class_state::vx_map() const {
      vx_core::vx_Type_mapany output;
      return vx_core::vx_map_from_map(vx_core::t_any(), this->vx_p_map);
      return output;
    }

    // vx_get_statelistener(key)
    vx_core::Type_statelistener Class_state::vx_get_statelistener(vx_core::Type_string key) const {
      vx_core::Type_statelistener output = vx_core::e_statelistener();
      const vx_core::Class_state* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_statelistener> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_core::e_statelistener());
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_state::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_statelistener(key);
    }

    // vx_mapstatelistener()
    std::map<std::string, vx_core::Type_statelistener> Class_state::vx_mapstatelistener() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_state::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_core::Type_state output = vx_core::e_state();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::map<std::string, vx_core::Type_statelistener> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_statelistener()) {
          vx_core::Type_statelistener castval = vx_core::vx_any_from_any(vx_core::t_statelistener(), val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(state) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_state();
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_state::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_state(), vals);
    }
    vx_core::Type_any Class_state::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_state output = vx_core::e_state();
      vx_core::Type_state valmap = vx_core::vx_any_from_any(vx_core::t_state(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_core::Type_statelistener> mapval;
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
          vx_core::Type_statelistener valany;
          if (valsubtype == vx_core::t_statelistener()) {
            valany = vx_core::vx_any_from_any(vx_core::t_statelistener(), valsub);
          } else if (valsubtype == vx_core::t_statelistener()) {
            valany = vx_core::vx_any_from_any(vx_core::t_statelistener(), valsub);
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("Invalid Key/Value: " + key + " "  + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          if (valany != NULL) {
            mapval[key] = valany;
            key = "";
          }
        }
      }
      output = new vx_core::Class_state();
      output->vx_p_map = mapval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_state::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_state::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_state::vx_empty() const {return vx_core::e_state();}
    vx_core::Type_any Class_state::vx_type() const {return vx_core::t_state();}

    vx_core::Type_typedef Class_state::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "state", // name
        ":map", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_statelistener()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type statelistener)
  // class Class_statelistener {
    Abstract_statelistener::~Abstract_statelistener() {}

    Class_statelistener::Class_statelistener() : Abstract_statelistener::Abstract_statelistener() {
      vx_core::refcount += 1;
    }
    Class_statelistener::~Class_statelistener() {
      vx_core::refcount -= 1;
    }
    // path()
    vx_core::Type_string Class_statelistener::path() const {
      vx_core::Type_string output = this->vx_p_path;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // value()
    vx_core::Type_any Class_statelistener::value() const {
      vx_core::Type_any output = this->vx_p_value;
      if (output == NULL) {
        output = vx_core::e_any();
      }
      return output;
    }

    // fn_boolean()
    vx_core::Func_boolean_from_none Class_statelistener::fn_boolean() const {
      vx_core::Func_boolean_from_none output = this->vx_p_fn_boolean;
      if (output == NULL) {
        output = vx_core::e_boolean_from_none();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_statelistener::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":path") {
        output = this->path();
      } else if (skey == ":value") {
        output = this->value();
      } else if (skey == ":fn-boolean") {
        output = this->fn_boolean();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_statelistener::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":path"] = this->path();
      output[":value"] = this->value();
      output[":fn-boolean"] = this->fn_boolean();
      return output;
    }

    vx_core::Type_any Class_statelistener::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_statelistener(), vals);
    }
    vx_core::Type_any Class_statelistener::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_statelistener output = vx_core::e_statelistener();
      vx_core::Type_statelistener val = vx_core::vx_any_from_any(vx_core::t_statelistener(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_path = val->path();
      vx_core::Type_any vx_p_value = val->value();
      vx_core::Func_boolean_from_none vx_p_fn_boolean = val->fn_boolean();
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
          } else if (testkey == ":path") {
            key = testkey;
          } else if (testkey == ":value") {
            key = testkey;
          } else if (testkey == ":fn-boolean") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new statelistener) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":path") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_path = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new statelistener :path " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":value") {
            if (valsubtype == vx_core::t_any()) {
              vx_p_value = vx_core::vx_any_from_any(vx_core::t_any(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new statelistener :value " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":fn-boolean") {
            if (valsubtype == vx_core::t_boolean_from_none()) {
              vx_p_fn_boolean = vx_core::vx_any_from_any(vx_core::t_boolean_from_none(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new statelistener :fn-boolean " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new statelistener) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_core::Class_statelistener();
      output->vx_p_path = vx_p_path;
      output->vx_p_value = vx_p_value;
      output->vx_p_fn_boolean = vx_p_fn_boolean;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_statelistener::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_statelistener::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_statelistener::vx_empty() const {return vx_core::e_statelistener();}
    vx_core::Type_any Class_statelistener::vx_type() const {return vx_core::t_statelistener();}

    vx_core::Type_typedef Class_statelistener::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "statelistener", // name
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
    }

  //}

  // (type stringlist)
  // class Class_stringlist {
    Abstract_stringlist::~Abstract_stringlist() {}

    Class_stringlist::Class_stringlist() : Abstract_stringlist::Abstract_stringlist() {
      vx_core::refcount += 1;
    }
    Class_stringlist::~Class_stringlist() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_stringlist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_core::Type_string Class_stringlist::vx_get_string(vx_core::Type_int index) const {
      vx_core::Type_string output = vx_core::e_string();
      long iindex = index->vx_int();
      std::vector<vx_core::Type_string> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_string> Class_stringlist::vx_liststring() const {return vx_p_list;}

    vx_core::Type_any vx_core::Class_stringlist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_string(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_stringlist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_core::Type_stringlist output = vx_core::e_stringlist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_core::Type_string> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_string()) {
          vx_core::Type_string castval = vx_core::vx_any_from_any(vx_core::t_string(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(stringlist) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_stringlist();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_stringlist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_stringlist(), vals);
    }
    vx_core::Type_any Class_stringlist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_stringlist output = vx_core::e_stringlist();
      vx_core::Type_stringlist val = vx_core::vx_any_from_any(vx_core::t_stringlist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_core::Type_string> listval = val->vx_liststring();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_string()) {
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_string(), valsub));
        } else if (valsubtype == vx_core::t_stringlist()) {
          vx_core::Type_stringlist multi = vx_core::vx_any_from_any(vx_core::t_stringlist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_liststring());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new stringlist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_core::Class_stringlist();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_stringlist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_stringlist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_stringlist::vx_empty() const {return vx_core::e_stringlist();}
    vx_core::Type_any Class_stringlist::vx_type() const {return vx_core::t_stringlist();}

    vx_core::Type_typedef Class_stringlist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "stringlist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_string()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type stringmap)
  // class Class_stringmap {
    Abstract_stringmap::~Abstract_stringmap() {}

    Class_stringmap::Class_stringmap() : Abstract_stringmap::Abstract_stringmap() {
      vx_core::refcount += 1;
    }
    Class_stringmap::~Class_stringmap() {
      vx_core::refcount -= 1;
    }
    // vx_map()
    vx_core::vx_Type_mapany Class_stringmap::vx_map() const {
      vx_core::vx_Type_mapany output;
      return vx_core::vx_map_from_map(vx_core::t_any(), this->vx_p_map);
      return output;
    }

    // vx_get_string(key)
    vx_core::Type_string Class_stringmap::vx_get_string(vx_core::Type_string key) const {
      vx_core::Type_string output = vx_core::e_string();
      const vx_core::Class_stringmap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_string> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_core::e_string());
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_stringmap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_string(key);
    }

    // vx_mapstring()
    std::map<std::string, vx_core::Type_string> Class_stringmap::vx_mapstring() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_stringmap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_core::Type_stringmap output = vx_core::e_stringmap();
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
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(stringmap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_stringmap();
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_stringmap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_stringmap(), vals);
    }
    vx_core::Type_any Class_stringmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_stringmap output = vx_core::e_stringmap();
      vx_core::Type_stringmap valmap = vx_core::vx_any_from_any(vx_core::t_stringmap(), copyval);
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
          vx_core::Type_string valany;
          if (valsubtype == vx_core::t_string()) {
            valany = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
          } else if (valsubtype == vx_core::t_string()) {
            valany = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("Invalid Key/Value: " + key + " "  + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          if (valany != NULL) {
            mapval[key] = valany;
            key = "";
          }
        }
      }
      output = new vx_core::Class_stringmap();
      output->vx_p_map = mapval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_stringmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_stringmap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_stringmap::vx_empty() const {return vx_core::e_stringmap();}
    vx_core::Type_any Class_stringmap::vx_type() const {return vx_core::t_stringmap();}

    vx_core::Type_typedef Class_stringmap::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "stringmap", // name
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
    }

  //}

  // (type thenelse)
  // class Class_thenelse {
    Abstract_thenelse::~Abstract_thenelse() {}

    Class_thenelse::Class_thenelse() : Abstract_thenelse::Abstract_thenelse() {
      vx_core::refcount += 1;
    }
    Class_thenelse::~Class_thenelse() {
      vx_core::refcount -= 1;
    }
    // code()
    vx_core::Type_string Class_thenelse::code() const {
      vx_core::Type_string output = this->vx_p_code;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // value()
    vx_core::Type_any Class_thenelse::value() const {
      vx_core::Type_any output = this->vx_p_value;
      if (output == NULL) {
        output = vx_core::e_any();
      }
      return output;
    }

    // values()
    vx_core::Type_list Class_thenelse::values() const {
      vx_core::Type_list output = this->vx_p_values;
      if (output == NULL) {
        output = vx_core::e_list();
      }
      return output;
    }

    // fn_cond()
    vx_core::Func_boolean_from_func Class_thenelse::fn_cond() const {
      vx_core::Func_boolean_from_func output = this->vx_p_fn_cond;
      if (output == NULL) {
        output = vx_core::e_boolean_from_func();
      }
      return output;
    }

    // fn_any()
    vx_core::Func_any_from_func Class_thenelse::fn_any() const {
      vx_core::Func_any_from_func output = this->vx_p_fn_any;
      if (output == NULL) {
        output = vx_core::e_any_from_func();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_thenelse::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":code") {
        output = this->code();
      } else if (skey == ":value") {
        output = this->value();
      } else if (skey == ":values") {
        output = this->values();
      } else if (skey == ":fn-cond") {
        output = this->fn_cond();
      } else if (skey == ":fn-any") {
        output = this->fn_any();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_thenelse::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":code"] = this->code();
      output[":value"] = this->value();
      output[":values"] = this->values();
      output[":fn-cond"] = this->fn_cond();
      output[":fn-any"] = this->fn_any();
      return output;
    }

    vx_core::Type_any Class_thenelse::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_thenelse(), vals);
    }
    vx_core::Type_any Class_thenelse::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_thenelse output = vx_core::e_thenelse();
      vx_core::Type_thenelse val = vx_core::vx_any_from_any(vx_core::t_thenelse(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_string vx_p_code = val->code();
      vx_core::Type_any vx_p_value = val->value();
      vx_core::Type_list vx_p_values = val->values();
      vx_core::Func_boolean_from_func vx_p_fn_cond = val->fn_cond();
      vx_core::Func_any_from_func vx_p_fn_any = val->fn_any();
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
          } else if (testkey == ":code") {
            key = testkey;
          } else if (testkey == ":value") {
            key = testkey;
          } else if (testkey == ":values") {
            key = testkey;
          } else if (testkey == ":fn-cond") {
            key = testkey;
          } else if (testkey == ":fn-any") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new thenelse) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":code") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_code = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new thenelse :code " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":value") {
            if (valsubtype == vx_core::t_any()) {
              vx_p_value = vx_core::vx_any_from_any(vx_core::t_any(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new thenelse :value " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":values") {
            if (valsubtype == vx_core::t_list()) {
              vx_p_values = vx_core::vx_any_from_any(vx_core::t_list(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new thenelse :values " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":fn-cond") {
            if (valsubtype == vx_core::t_boolean_from_func()) {
              vx_p_fn_cond = vx_core::vx_any_from_any(vx_core::t_boolean_from_func(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new thenelse :fn-cond " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":fn-any") {
            if (valsubtype == vx_core::t_any_from_func()) {
              vx_p_fn_any = vx_core::vx_any_from_any(vx_core::t_any_from_func(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new thenelse :fn-any " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new thenelse) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_core::Class_thenelse();
      output->vx_p_code = vx_p_code;
      output->vx_p_value = vx_p_value;
      output->vx_p_values = vx_p_values;
      output->vx_p_fn_cond = vx_p_fn_cond;
      output->vx_p_fn_any = vx_p_fn_any;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_thenelse::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_thenelse::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_thenelse::vx_empty() const {return vx_core::e_thenelse();}
    vx_core::Type_any Class_thenelse::vx_type() const {return vx_core::t_thenelse();}

    vx_core::Type_typedef Class_thenelse::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "thenelse", // name
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
    }

  //}

  // (type thenelselist)
  // class Class_thenelselist {
    Abstract_thenelselist::~Abstract_thenelselist() {}

    Class_thenelselist::Class_thenelselist() : Abstract_thenelselist::Abstract_thenelselist() {
      vx_core::refcount += 1;
    }
    Class_thenelselist::~Class_thenelselist() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_thenelselist::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any(), this->vx_p_list);
    }

    vx_core::Type_thenelse Class_thenelselist::vx_get_thenelse(vx_core::Type_int index) const {
      vx_core::Type_thenelse output = vx_core::e_thenelse();
      long iindex = index->vx_int();
      std::vector<vx_core::Type_thenelse> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    std::vector<vx_core::Type_thenelse> Class_thenelselist::vx_listthenelse() const {return vx_p_list;}

    vx_core::Type_any vx_core::Class_thenelselist::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_thenelse(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_thenelselist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_core::Type_thenelselist output = vx_core::e_thenelselist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_core::Type_thenelse> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_thenelse()) {
          vx_core::Type_thenelse castval = vx_core::vx_any_from_any(vx_core::t_thenelse(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(thenelselist) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_thenelselist();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_thenelselist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_thenelselist(), vals);
    }
    vx_core::Type_any Class_thenelselist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_thenelselist output = vx_core::e_thenelselist();
      vx_core::Type_thenelselist val = vx_core::vx_any_from_any(vx_core::t_thenelselist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_core::Type_thenelse> listval = val->vx_listthenelse();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_thenelse()) {
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_thenelse(), valsub));
        } else if (valsubtype == vx_core::t_thenelselist()) {
          vx_core::Type_thenelselist multi = vx_core::vx_any_from_any(vx_core::t_thenelselist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_listthenelse());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new thenelselist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_core::Class_thenelselist();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_thenelselist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_thenelselist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_thenelselist::vx_empty() const {return vx_core::e_thenelselist();}
    vx_core::Type_any Class_thenelselist::vx_type() const {return vx_core::t_thenelselist();}

    vx_core::Type_typedef Class_thenelselist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "thenelselist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_thenelse()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type type)
  // class Class_type {
    Abstract_type::~Abstract_type() {}

    Class_type::Class_type() : Abstract_type::Abstract_type() {
      vx_core::refcount += 1;
    }
    Class_type::~Class_type() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_type::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_type(), vals);
    }
    vx_core::Type_any Class_type::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_type output = vx_core::e_type();
      return output;
    }

    vx_core::Type_msgblock Class_type::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_type::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_type::vx_empty() const {return vx_core::e_type();}
    vx_core::Type_any Class_type::vx_type() const {return vx_core::t_type();}

    vx_core::Type_typedef Class_type::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "type", // name
        ":type", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type typelist)
  // class Class_typelist {
    Abstract_typelist::~Abstract_typelist() {}

    Class_typelist::Class_typelist() : Abstract_typelist::Abstract_typelist() {
      vx_core::refcount += 1;
    }
    Class_typelist::~Class_typelist() {
      vx_core::refcount -= 1;
    }
    // vx_list()
    vx_core::vx_Type_listany Class_typelist::vx_list() const {
      return this->vx_p_list;
    }

    // vx_get_any(index)
    vx_core::Type_any Class_typelist::vx_get_any(vx_core::Type_int index) const {
      vx_core::Type_any output = vx_core::e_any();
      long iindex = index->vx_int();
      std::vector<vx_core::Type_any> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      return output;
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_typelist::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_core::Type_typelist output = vx_core::e_typelist();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::vector<vx_core::Type_any> list;
      for (auto const& val : listval) {
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_any()) {
          vx_core::Type_any castval = vx_core::vx_any_from_any(vx_core::t_any(), val);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(typelist) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_typelist();
      output->vx_p_list = list;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_typelist::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_typelist(), vals);
    }
    vx_core::Type_any Class_typelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_typelist output = vx_core::e_typelist();
      vx_core::Type_typelist val = vx_core::vx_any_from_any(vx_core::t_typelist(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_core::Type_any> listval = val->vx_list();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg()) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_any()) {
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_any(), valsub));
        } else if (valsubtype == vx_core::t_typelist()) {
          vx_core::Type_typelist multi = vx_core::vx_any_from_any(vx_core::t_typelist(), valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_list());
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new typelist) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      output = new vx_core::Class_typelist();
      output->vx_p_list = listval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_typelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_typelist::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_typelist::vx_empty() const {return vx_core::e_typelist();}
    vx_core::Type_any Class_typelist::vx_type() const {return vx_core::t_typelist();}

    vx_core::Type_typedef Class_typelist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "typelist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_any()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type typemap)
  // class Class_typemap {
    Abstract_typemap::~Abstract_typemap() {}

    Class_typemap::Class_typemap() : Abstract_typemap::Abstract_typemap() {
      vx_core::refcount += 1;
    }
    Class_typemap::~Class_typemap() {
      vx_core::refcount -= 1;
    }
    // vx_map()
    vx_core::vx_Type_mapany Class_typemap::vx_map() const {
      vx_core::vx_Type_mapany output;
      return this->vx_p_map;
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_typemap::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      const vx_core::Class_typemap* map = this;
      std::string skey = key->vx_string();
      std::map<std::string, vx_core::Type_any> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_core::e_any());
      return output;
    }

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_typemap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_core::Type_typemap output = vx_core::e_typemap();
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock();
      std::map<std::string, vx_core::Type_any> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_any()) {
          vx_core::Type_any castval = vx_core::vx_any_from_any(vx_core::t_any(), val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(typemap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      output = new vx_core::Class_typemap();
      output->vx_p_map = map;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_any Class_typemap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_typemap(), vals);
    }
    vx_core::Type_any Class_typemap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_typemap output = vx_core::e_typemap();
      vx_core::Type_typemap valmap = vx_core::vx_any_from_any(vx_core::t_typemap(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_core::Type_any> mapval;
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
          vx_core::Type_any valany;
          if (valsubtype == vx_core::t_any()) {
            valany = vx_core::vx_any_from_any(vx_core::t_any(), valsub);
          } else if (valsubtype == vx_core::t_any()) {
            valany = vx_core::vx_any_from_any(vx_core::t_any(), valsub);
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("Invalid Key/Value: " + key + " "  + vx_core::vx_string_from_any(valsub) + "");
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          if (valany != NULL) {
            mapval[key] = valany;
            key = "";
          }
        }
      }
      output = new vx_core::Class_typemap();
      output->vx_p_map = mapval;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_typemap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_typemap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_typemap::vx_empty() const {return vx_core::e_typemap();}
    vx_core::Type_any Class_typemap::vx_type() const {return vx_core::t_typemap();}

    vx_core::Type_typedef Class_typemap::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "typemap", // name
        ":map", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_any()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

  //}

  // (type user)
  // class Class_user {
    Abstract_user::~Abstract_user() {}

    Class_user::Class_user() : Abstract_user::Abstract_user() {
      vx_core::refcount += 1;
    }
    Class_user::~Class_user() {
      vx_core::refcount -= 1;
    }
    // security()
    vx_core::Type_security Class_user::security() const {
      vx_core::Type_security output = this->vx_p_security;
      if (output == NULL) {
        output = vx_core::e_security();
      }
      return output;
    }

    // username()
    vx_core::Type_string Class_user::username() const {
      vx_core::Type_string output = this->vx_p_username;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // token()
    vx_core::Type_string Class_user::token() const {
      vx_core::Type_string output = this->vx_p_token;
      if (output == NULL) {
        output = vx_core::e_string();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_user::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":security") {
        output = this->security();
      } else if (skey == ":username") {
        output = this->username();
      } else if (skey == ":token") {
        output = this->token();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_user::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":security"] = this->security();
      output[":username"] = this->username();
      output[":token"] = this->token();
      return output;
    }

    vx_core::Type_any Class_user::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_user(), vals);
    }
    vx_core::Type_any Class_user::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_user output = vx_core::e_user();
      vx_core::Type_user val = vx_core::vx_any_from_any(vx_core::t_user(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_security vx_p_security = val->security();
      vx_core::Type_string vx_p_username = val->username();
      vx_core::Type_string vx_p_token = val->token();
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
          } else if (testkey == ":security") {
            key = testkey;
          } else if (testkey == ":username") {
            key = testkey;
          } else if (testkey == ":token") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new user) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":security") {
            if (valsubtype == vx_core::t_security()) {
              vx_p_security = vx_core::vx_any_from_any(vx_core::t_security(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new user :security " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":username") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_username = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new user :username " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":token") {
            if (valsubtype == vx_core::t_string()) {
              vx_p_token = vx_core::vx_any_from_any(vx_core::t_string(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new user :token " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new user) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_core::Class_user();
      output->vx_p_security = vx_p_security;
      output->vx_p_username = vx_p_username;
      output->vx_p_token = vx_p_token;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_user::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_user::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_user::vx_empty() const {return vx_core::e_user();}
    vx_core::Type_any Class_user::vx_type() const {return vx_core::t_user();}

    vx_core::Type_typedef Class_user::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "user", // name
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
    }

  //}

  // (type value)
  // class Class_value {
    Abstract_value::~Abstract_value() {}

    Class_value::Class_value() : Abstract_value::Abstract_value() {
      vx_core::refcount += 1;
    }
    Class_value::~Class_value() {
      vx_core::refcount -= 1;
    }
    // next()
    vx_core::Type_any Class_value::next() const {
      vx_core::Type_any output = this->vx_p_next;
      if (output == NULL) {
        output = vx_core::e_any();
      }
      return output;
    }

    // refs()
    vx_core::Type_int Class_value::refs() const {
      vx_core::Type_int output = this->vx_p_refs;
      if (output == NULL) {
        output = vx_core::e_int();
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_value::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any();
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":next") {
        output = this->next();
      } else if (skey == ":refs") {
        output = this->refs();
      }
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_value::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":next"] = this->next();
      output[":refs"] = this->refs();
      return output;
    }

    vx_core::Type_any Class_value::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_core::e_value(), vals);
    }
    vx_core::Type_any Class_value::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Type_value output = vx_core::e_value();
      vx_core::Type_value val = vx_core::vx_any_from_any(vx_core::t_value(), copyval);
      vx_core::Type_msgblock msgblock = vx_core::t_msgblock()->vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_any vx_p_next = val->next();
      vx_core::Type_int vx_p_refs = val->refs();
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
          } else if (testkey == ":next") {
            key = testkey;
          } else if (testkey == ":refs") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new value) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":next") {
            if (valsubtype == vx_core::t_any()) {
              vx_p_next = vx_core::vx_any_from_any(vx_core::t_any(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new value :next " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":refs") {
            if (valsubtype == vx_core::t_int()) {
              vx_p_refs = vx_core::vx_any_from_any(vx_core::t_int(), valsub);
            } else {
              vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new value :refs " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::t_msg()->vx_msg_from_errortext("(new value) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      output = new vx_core::Class_value();
      output->vx_p_next = vx_p_next;
      output->vx_p_refs = vx_p_refs;
      if (msgblock != vx_core::e_msgblock()) {
        output->vx_p_msgblock = msgblock;
      }
      return output;
    }

    vx_core::Type_msgblock Class_value::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_core::Class_value::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_value::vx_empty() const {return vx_core::e_value();}
    vx_core::Type_any Class_value::vx_type() const {return vx_core::t_value();}

    vx_core::Type_typedef Class_value::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "value", // name
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
    }

  //}

  // (const false)
  // class Class_false {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_false::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "false", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core::e_typelist(), // traits
          vx_core::e_typelist(), // allowtypes
          vx_core::e_typelist(), // disallowtypes
          vx_core::e_funclist(), // allowfuncs
          vx_core::e_funclist(), // disallowfuncs
          vx_core::e_anylist(), // allowvalues
          vx_core::e_anylist(), // disallowvalues
          vx_core::e_argmap() // properties
        )
      );
    }

    bool vx_core::Class_false::vx_boolean() {
      this->vx_p_boolean = false;
      return this->vx_p_boolean;
    }

  //}

  // (const globalpackagemap)
  // class Class_globalpackagemap {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_globalpackagemap::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "globalpackagemap", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "packagemap", // name
          ":map", // extends
          vx_core::e_typelist(), // traits
          vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_package()}), // allowtypes
          vx_core::e_typelist(), // disallowtypes
          vx_core::e_funclist(), // allowfuncs
          vx_core::e_funclist(), // disallowfuncs
          vx_core::e_anylist(), // allowvalues
          vx_core::e_anylist(), // disallowvalues
          vx_core::e_argmap() // properties
        )
      );
    }


  //}

  // (const infinity)
  // class Class_infinity {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_infinity::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "infinity", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
          vx_core::e_typelist(), // allowtypes
          vx_core::e_typelist(), // disallowtypes
          vx_core::e_funclist(), // allowfuncs
          vx_core::e_funclist(), // disallowfuncs
          vx_core::e_anylist(), // allowvalues
          vx_core::e_anylist(), // disallowvalues
          vx_core::e_argmap() // properties
        )
      );
    }

    long vx_core::Class_infinity::vx_int() {
      this->vx_p_int = 0;
      return this->vx_p_int;
    }

  //}

  // (const mempool-active)
  // class Class_mempool_active {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_mempool_active::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "mempool-active", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "mempool", // name
          ":struct", // extends
          vx_core::e_typelist(), // traits
          vx_core::e_typelist(), // allowtypes
          vx_core::e_typelist(), // disallowtypes
          vx_core::e_funclist(), // allowfuncs
          vx_core::e_funclist(), // disallowfuncs
          vx_core::e_anylist(), // allowvalues
          vx_core::e_anylist(), // disallowvalues
          vx_core::e_argmap() // properties
        )
      );
    }


  //}

  // (const msg-error)
  // class Class_msg_error {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_msg_error::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "msg-error", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
          vx_core::e_typelist(), // allowtypes
          vx_core::e_typelist(), // disallowtypes
          vx_core::e_funclist(), // allowfuncs
          vx_core::e_funclist(), // disallowfuncs
          vx_core::e_anylist(), // allowvalues
          vx_core::e_anylist(), // disallowvalues
          vx_core::e_argmap() // properties
        )
      );
    }

    long vx_core::Class_msg_error::vx_int() {
      this->vx_p_int = 2;
      return this->vx_p_int;
    }

  //}

  // (const msg-info)
  // class Class_msg_info {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_msg_info::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "msg-info", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
          vx_core::e_typelist(), // allowtypes
          vx_core::e_typelist(), // disallowtypes
          vx_core::e_funclist(), // allowfuncs
          vx_core::e_funclist(), // disallowfuncs
          vx_core::e_anylist(), // allowvalues
          vx_core::e_anylist(), // disallowvalues
          vx_core::e_argmap() // properties
        )
      );
    }

    long vx_core::Class_msg_info::vx_int() {
      this->vx_p_int = 0;
      return this->vx_p_int;
    }

  //}

  // (const msg-severe)
  // class Class_msg_severe {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_msg_severe::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "msg-severe", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
          vx_core::e_typelist(), // allowtypes
          vx_core::e_typelist(), // disallowtypes
          vx_core::e_funclist(), // allowfuncs
          vx_core::e_funclist(), // disallowfuncs
          vx_core::e_anylist(), // allowvalues
          vx_core::e_anylist(), // disallowvalues
          vx_core::e_argmap() // properties
        )
      );
    }

    long vx_core::Class_msg_severe::vx_int() {
      this->vx_p_int = 3;
      return this->vx_p_int;
    }

  //}

  // (const msg-warning)
  // class Class_msg_warning {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_msg_warning::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "msg-warning", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
          vx_core::e_typelist(), // allowtypes
          vx_core::e_typelist(), // disallowtypes
          vx_core::e_funclist(), // allowfuncs
          vx_core::e_funclist(), // disallowfuncs
          vx_core::e_anylist(), // allowvalues
          vx_core::e_anylist(), // disallowvalues
          vx_core::e_argmap() // properties
        )
      );
    }

    long vx_core::Class_msg_warning::vx_int() {
      this->vx_p_int = 1;
      return this->vx_p_int;
    }

  //}

  // (const neginfinity)
  // class Class_neginfinity {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_neginfinity::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "neginfinity", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
          vx_core::e_typelist(), // allowtypes
          vx_core::e_typelist(), // disallowtypes
          vx_core::e_funclist(), // allowfuncs
          vx_core::e_funclist(), // disallowfuncs
          vx_core::e_anylist(), // allowvalues
          vx_core::e_anylist(), // disallowvalues
          vx_core::e_argmap() // properties
        )
      );
    }

    long vx_core::Class_neginfinity::vx_int() {
      this->vx_p_int = 0;
      return this->vx_p_int;
    }

  //}

  // (const newline)
  // class Class_newline {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_newline::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "newline", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
          vx_core::e_typelist(), // traits
          vx_core::e_typelist(), // allowtypes
          vx_core::e_typelist(), // disallowtypes
          vx_core::e_funclist(), // allowfuncs
          vx_core::e_funclist(), // disallowfuncs
          vx_core::e_anylist(), // allowvalues
          vx_core::e_anylist(), // disallowvalues
          vx_core::e_argmap() // properties
        )
      );
    }

    std::string vx_core::Class_newline::vx_string() {
      this->vx_p_string = "\n";
      return this->vx_p_string;
    }

  //}

  // (const notanumber)
  // class Class_notanumber {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_notanumber::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "notanumber", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "int", // name
          "", // extends
          vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
          vx_core::e_typelist(), // allowtypes
          vx_core::e_typelist(), // disallowtypes
          vx_core::e_funclist(), // allowfuncs
          vx_core::e_funclist(), // disallowfuncs
          vx_core::e_anylist(), // allowvalues
          vx_core::e_anylist(), // disallowvalues
          vx_core::e_argmap() // properties
        )
      );
    }

    long vx_core::Class_notanumber::vx_int() {
      this->vx_p_int = 0;
      return this->vx_p_int;
    }

  //}

  // (const nothing)
  // class Class_nothing {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_nothing::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "nothing", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
          vx_core::e_typelist(), // traits
          vx_core::e_typelist(), // allowtypes
          vx_core::e_typelist(), // disallowtypes
          vx_core::e_funclist(), // allowfuncs
          vx_core::e_funclist(), // disallowfuncs
          vx_core::e_anylist(), // allowvalues
          vx_core::e_anylist(), // disallowvalues
          vx_core::e_argmap() // properties
        )
      );
    }

    std::string vx_core::Class_nothing::vx_string() {
      this->vx_p_string = "nothing";
      return this->vx_p_string;
    }

  //}

  // (const quote)
  // class Class_quote {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_quote::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "quote", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "string", // name
          "string", // extends
          vx_core::e_typelist(), // traits
          vx_core::e_typelist(), // allowtypes
          vx_core::e_typelist(), // disallowtypes
          vx_core::e_funclist(), // allowfuncs
          vx_core::e_funclist(), // disallowfuncs
          vx_core::e_anylist(), // allowvalues
          vx_core::e_anylist(), // disallowvalues
          vx_core::e_argmap() // properties
        )
      );
    }

    std::string vx_core::Class_quote::vx_string() {
      this->vx_p_string = "\"";
      return this->vx_p_string;
    }

  //}

  // (const true)
  // class Class_true {

    // vx_constdef()
    vx_core::Type_constdef vx_core::Class_true::vx_constdef() const {
      return vx_core::Class_constdef::vx_constdef_new(
        "vx/core", // pkgname
        "true", // name
        vx_core::Class_typedef::vx_typedef_new(
          "vx/core", // pkgname
          "boolean", // name
          "", // extends
          vx_core::e_typelist(), // traits
          vx_core::e_typelist(), // allowtypes
          vx_core::e_typelist(), // disallowtypes
          vx_core::e_funclist(), // allowfuncs
          vx_core::e_funclist(), // disallowfuncs
          vx_core::e_anylist(), // allowvalues
          vx_core::e_anylist(), // disallowvalues
          vx_core::e_argmap() // properties
        )
      );
    }

    bool vx_core::Class_true::vx_boolean() {
      this->vx_p_boolean = true;
      return this->vx_p_boolean;
    }

  //}

  // (func any<-any)
  // class Class_any_from_any {
    Abstract_any_from_any::~Abstract_any_from_any() {}

    Class_any_from_any::Class_any_from_any() : Abstract_any_from_any::Abstract_any_from_any() {
      vx_core::refcount += 1;
    }
    Class_any_from_any::~Class_any_from_any() {
      vx_core::refcount -= 1;
    }
    vx_core::Func_any_from_any Class_any_from_any::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      vx_core::Func_any_from_any output = new vx_core::Class_any_from_any();
      output->fn = fn;
      return output;
    }

    vx_core::Type_any Class_any_from_any::vx_any_from_any(vx_core::Type_any value) const {
      vx_core::Type_any output = vx_core::e_any();
      return output;
    }

    vx_core::Type_any Class_any_from_any::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_any output = vx_core::e_any_from_any();
      return output;
    }

    vx_core::Type_any Class_any_from_any::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_any output = vx_core::e_any_from_any();
      return output;
    }

    vx_core::Type_typedef Class_any_from_any::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_any_from_any::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-any", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_any_from_any::vx_empty() const {return vx_core::e_any_from_any();}
    vx_core::Type_any Class_any_from_any::vx_type() const {return vx_core::t_any_from_any();}
    vx_core::Type_msgblock Class_any_from_any::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_any::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_any_from_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_any_from_any(generic_any_1, value);
      return output;
    }

  //}

  // (func any<-any-async)
  // class Class_any_from_any_async {
    Abstract_any_from_any_async::~Abstract_any_from_any_async() {}

    Class_any_from_any_async::Class_any_from_any_async() : Abstract_any_from_any_async::Abstract_any_from_any_async() {
      vx_core::refcount += 1;
    }
    Class_any_from_any_async::~Class_any_from_any_async() {
      vx_core::refcount -= 1;
    }
    vx_core::Func_any_from_any_async Class_any_from_any_async::vx_fn_new(vx_core::Abstract_any_from_any_async::IFn fn) const {
      vx_core::Func_any_from_any_async output = new vx_core::Class_any_from_any_async();
      output->fn = fn;
      return output;
    }

    vx_core::vx_Type_async Class_any_from_any_async::vx_any_from_any_async(vx_core::Type_any value) const {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      return output;
    }

    vx_core::Type_any Class_any_from_any_async::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_any_async output = vx_core::e_any_from_any_async();
      return output;
    }

    vx_core::Type_any Class_any_from_any_async::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_any_async output = vx_core::e_any_from_any_async();
      return output;
    }

    vx_core::Type_typedef Class_any_from_any_async::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_any_from_any_async::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-any-async", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_any_from_any_async::vx_empty() const {return vx_core::e_any_from_any_async();}
    vx_core::Type_any Class_any_from_any_async::vx_type() const {return vx_core::t_any_from_any_async();}
    vx_core::Type_msgblock Class_any_from_any_async::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_any_async::vx_dispose() {return vx_core::emptylistany;}

    vx_core::vx_Type_async Class_any_from_any_async::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_any_from_any_async(generic_any_1, value);
      return output;
    }

  //}

  // (func any<-any-context)
  // class Class_any_from_any_context {
    Abstract_any_from_any_context::~Abstract_any_from_any_context() {}

    Class_any_from_any_context::Class_any_from_any_context() : Abstract_any_from_any_context::Abstract_any_from_any_context() {
      vx_core::refcount += 1;
    }
    Class_any_from_any_context::~Class_any_from_any_context() {
      vx_core::refcount -= 1;
    }
    vx_core::Func_any_from_any_context Class_any_from_any_context::vx_fn_new(vx_core::Abstract_any_from_any_context::IFn fn) const {
      vx_core::Func_any_from_any_context output = new vx_core::Class_any_from_any_context();
      output->fn = fn;
      return output;
    }

    vx_core::Type_any Class_any_from_any_context::vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const {
      vx_core::Type_any output = vx_core::e_any();
      return output;
    }

    vx_core::Type_any Class_any_from_any_context::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_any_context output = vx_core::e_any_from_any_context();
      return output;
    }

    vx_core::Type_any Class_any_from_any_context::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_any_context output = vx_core::e_any_from_any_context();
      return output;
    }

    vx_core::Type_typedef Class_any_from_any_context::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_any_from_any_context::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-any-context", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_any_from_any_context::vx_empty() const {return vx_core::e_any_from_any_context();}
    vx_core::Type_any Class_any_from_any_context::vx_type() const {return vx_core::t_any_from_any_context();}
    vx_core::Type_msgblock Class_any_from_any_context::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_any_context::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_any_from_any_context::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_any_from_any_context(generic_any_1, value, context);
      return output;
    }

  //}

  // (func any<-any-context-async)
  // class Class_any_from_any_context_async {
    Abstract_any_from_any_context_async::~Abstract_any_from_any_context_async() {}

    Class_any_from_any_context_async::Class_any_from_any_context_async() : Abstract_any_from_any_context_async::Abstract_any_from_any_context_async() {
      vx_core::refcount += 1;
    }
    Class_any_from_any_context_async::~Class_any_from_any_context_async() {
      vx_core::refcount -= 1;
    }
    vx_core::Func_any_from_any_context_async Class_any_from_any_context_async::vx_fn_new(vx_core::Abstract_any_from_any_context_async::IFn fn) const {
      vx_core::Func_any_from_any_context_async output = new vx_core::Class_any_from_any_context_async();
      output->fn = fn;
      return output;
    }

    vx_core::vx_Type_async Class_any_from_any_context_async::vx_any_from_any_context_async(vx_core::Type_any value, vx_core::Type_context context) const {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      return output;
    }

    vx_core::Type_any Class_any_from_any_context_async::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_any_context_async output = vx_core::e_any_from_any_context_async();
      return output;
    }

    vx_core::Type_any Class_any_from_any_context_async::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_any_context_async output = vx_core::e_any_from_any_context_async();
      return output;
    }

    vx_core::Type_typedef Class_any_from_any_context_async::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_any_from_any_context_async::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-any-context-async", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_any_from_any_context_async::vx_empty() const {return vx_core::e_any_from_any_context_async();}
    vx_core::Type_any Class_any_from_any_context_async::vx_type() const {return vx_core::t_any_from_any_context_async();}
    vx_core::Type_msgblock Class_any_from_any_context_async::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_any_context_async::vx_dispose() {return vx_core::emptylistany;}

    vx_core::vx_Type_async Class_any_from_any_context_async::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_any_from_any_context_async(generic_any_1, value, context);
      return output;
    }

  //}

  // (func any<-func)
  // class Class_any_from_func {
    Abstract_any_from_func::~Abstract_any_from_func() {}

    Class_any_from_func::Class_any_from_func() : Abstract_any_from_func::Abstract_any_from_func() {
      vx_core::refcount += 1;
    }
    Class_any_from_func::~Class_any_from_func() {
      vx_core::refcount -= 1;
    }
    vx_core::Func_any_from_func Class_any_from_func::vx_fn_new(vx_core::Abstract_any_from_func::IFn fn) const {
      vx_core::Func_any_from_func output = new vx_core::Class_any_from_func();
      output->fn = fn;
      return output;
    }

    vx_core::Type_any Class_any_from_func::vx_any_from_func() const {
      vx_core::Type_any output = vx_core::e_any();
      return output;
    }

    vx_core::Type_any Class_any_from_func::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_func output = vx_core::e_any_from_func();
      return output;
    }

    vx_core::Type_any Class_any_from_func::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_func output = vx_core::e_any_from_func();
      return output;
    }

    vx_core::Type_typedef Class_any_from_func::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_any_from_func::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-func", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_any_from_func::vx_empty() const {return vx_core::e_any_from_func();}
    vx_core::Type_any Class_any_from_func::vx_type() const {return vx_core::t_any_from_func();}
    vx_core::Type_msgblock Class_any_from_func::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_func::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_any_from_func::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_any_from_func(generic_any_1);
      return output;
    }

  //}

  // (func any<-func-async)
  // class Class_any_from_func_async {
    Abstract_any_from_func_async::~Abstract_any_from_func_async() {}

    Class_any_from_func_async::Class_any_from_func_async() : Abstract_any_from_func_async::Abstract_any_from_func_async() {
      vx_core::refcount += 1;
    }
    Class_any_from_func_async::~Class_any_from_func_async() {
      vx_core::refcount -= 1;
    }
    vx_core::Func_any_from_func_async Class_any_from_func_async::vx_fn_new(vx_core::Abstract_any_from_func_async::IFn fn) const {
      vx_core::Func_any_from_func_async output = new vx_core::Class_any_from_func_async();
      output->fn = fn;
      return output;
    }

    vx_core::vx_Type_async Class_any_from_func_async::vx_any_from_func_async() const {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      return output;
    }

    vx_core::Type_any Class_any_from_func_async::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_func_async output = vx_core::e_any_from_func_async();
      return output;
    }

    vx_core::Type_any Class_any_from_func_async::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_func_async output = vx_core::e_any_from_func_async();
      return output;
    }

    vx_core::Type_typedef Class_any_from_func_async::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_any_from_func_async::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-func-async", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_any_from_func_async::vx_empty() const {return vx_core::e_any_from_func_async();}
    vx_core::Type_any Class_any_from_func_async::vx_type() const {return vx_core::t_any_from_func_async();}
    vx_core::Type_msgblock Class_any_from_func_async::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_func_async::vx_dispose() {return vx_core::emptylistany;}

    vx_core::vx_Type_async Class_any_from_func_async::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_any_from_func_async(generic_any_1);
      return output;
    }

  //}

  // (func any<-key-value)
  // class Class_any_from_key_value {
    Abstract_any_from_key_value::~Abstract_any_from_key_value() {}

    Class_any_from_key_value::Class_any_from_key_value() : Abstract_any_from_key_value::Abstract_any_from_key_value() {
      vx_core::refcount += 1;
    }
    Class_any_from_key_value::~Class_any_from_key_value() {
      vx_core::refcount -= 1;
    }
    vx_core::Func_any_from_key_value Class_any_from_key_value::vx_fn_new(vx_core::Abstract_any_from_key_value::IFn fn) const {
      vx_core::Func_any_from_key_value output = new vx_core::Class_any_from_key_value();
      output->fn = fn;
      return output;
    }

    vx_core::Type_any Class_any_from_key_value::vx_any_from_key_value(vx_core::Type_string key, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      return output;
    }

    vx_core::Type_any Class_any_from_key_value::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_key_value output = vx_core::e_any_from_key_value();
      return output;
    }

    vx_core::Type_any Class_any_from_key_value::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_key_value output = vx_core::e_any_from_key_value();
      return output;
    }

    vx_core::Type_typedef Class_any_from_key_value::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_any_from_key_value::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-key-value", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_any_from_key_value::vx_empty() const {return vx_core::e_any_from_key_value();}
    vx_core::Type_any Class_any_from_key_value::vx_type() const {return vx_core::t_any_from_key_value();}
    vx_core::Type_msgblock Class_any_from_key_value::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_key_value::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_any_from_key_value::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string key = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any val = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_any_from_key_value(generic_any_1, key, val);
      return output;
    }

  //}

  // (func any<-key-value-async)
  // class Class_any_from_key_value_async {
    Abstract_any_from_key_value_async::~Abstract_any_from_key_value_async() {}

    Class_any_from_key_value_async::Class_any_from_key_value_async() : Abstract_any_from_key_value_async::Abstract_any_from_key_value_async() {
      vx_core::refcount += 1;
    }
    Class_any_from_key_value_async::~Class_any_from_key_value_async() {
      vx_core::refcount -= 1;
    }
    vx_core::Func_any_from_key_value_async Class_any_from_key_value_async::vx_fn_new(vx_core::Abstract_any_from_key_value_async::IFn fn) const {
      vx_core::Func_any_from_key_value_async output = new vx_core::Class_any_from_key_value_async();
      output->fn = fn;
      return output;
    }

    vx_core::vx_Type_async Class_any_from_key_value_async::vx_any_from_key_value_async(vx_core::Type_string key, vx_core::Type_any val) const {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      return output;
    }

    vx_core::Type_any Class_any_from_key_value_async::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_key_value_async output = vx_core::e_any_from_key_value_async();
      return output;
    }

    vx_core::Type_any Class_any_from_key_value_async::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_key_value_async output = vx_core::e_any_from_key_value_async();
      return output;
    }

    vx_core::Type_typedef Class_any_from_key_value_async::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_any_from_key_value_async::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-key-value-async", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_any_from_key_value_async::vx_empty() const {return vx_core::e_any_from_key_value_async();}
    vx_core::Type_any Class_any_from_key_value_async::vx_type() const {return vx_core::t_any_from_key_value_async();}
    vx_core::Type_msgblock Class_any_from_key_value_async::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_key_value_async::vx_dispose() {return vx_core::emptylistany;}

    vx_core::vx_Type_async Class_any_from_key_value_async::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string key = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any val = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_any_from_key_value_async(generic_any_1, key, val);
      return output;
    }

  //}

  // (func any<-list)
  // class Class_any_from_list {
    Abstract_any_from_list::~Abstract_any_from_list() {}

    Class_any_from_list::Class_any_from_list() : Abstract_any_from_list::Abstract_any_from_list() {
      vx_core::refcount += 1;
    }
    Class_any_from_list::~Class_any_from_list() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_any_from_list::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_list output = vx_core::e_any_from_list();
      return output;
    }

    vx_core::Type_any Class_any_from_list::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_list output = vx_core::e_any_from_list();
      return output;
    }

    vx_core::Type_typedef Class_any_from_list::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_any_from_list::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-list", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_any_from_list::vx_empty() const {return vx_core::e_any_from_list();}
    vx_core::Type_any Class_any_from_list::vx_type() const {return vx_core::t_any_from_list();}
    vx_core::Type_msgblock Class_any_from_list::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_list::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_any_from_list::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list values = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int index = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_any_from_list(generic_any_1, values, index);
      return output;
    }

  //}

  // (func any<-list-reduce)
  // class Class_any_from_list_reduce {
    Abstract_any_from_list_reduce::~Abstract_any_from_list_reduce() {}

    Class_any_from_list_reduce::Class_any_from_list_reduce() : Abstract_any_from_list_reduce::Abstract_any_from_list_reduce() {
      vx_core::refcount += 1;
    }
    Class_any_from_list_reduce::~Class_any_from_list_reduce() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_any_from_list_reduce::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_list_reduce output = vx_core::e_any_from_list_reduce();
      return output;
    }

    vx_core::Type_any Class_any_from_list_reduce::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_list_reduce output = vx_core::e_any_from_list_reduce();
      return output;
    }

    vx_core::Type_typedef Class_any_from_list_reduce::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_any_from_list_reduce::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-list-reduce", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_any_from_list_reduce::vx_empty() const {return vx_core::e_any_from_list_reduce();}
    vx_core::Type_any Class_any_from_list_reduce::vx_type() const {return vx_core::t_any_from_list_reduce();}
    vx_core::Type_msgblock Class_any_from_list_reduce::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_list_reduce::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_any_from_list_reduce::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list list = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any valstart = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Func_any_from_reduce fn_reduce = vx_core::vx_any_from_any(vx_core::t_any_from_reduce(), arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_core::f_any_from_list_reduce(generic_any_1, list, valstart, fn_reduce);
      return output;
    }

  //}

  // (func any<-list-reduce-next)
  // class Class_any_from_list_reduce_next {
    Abstract_any_from_list_reduce_next::~Abstract_any_from_list_reduce_next() {}

    Class_any_from_list_reduce_next::Class_any_from_list_reduce_next() : Abstract_any_from_list_reduce_next::Abstract_any_from_list_reduce_next() {
      vx_core::refcount += 1;
    }
    Class_any_from_list_reduce_next::~Class_any_from_list_reduce_next() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_any_from_list_reduce_next::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_list_reduce_next output = vx_core::e_any_from_list_reduce_next();
      return output;
    }

    vx_core::Type_any Class_any_from_list_reduce_next::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_list_reduce_next output = vx_core::e_any_from_list_reduce_next();
      return output;
    }

    vx_core::Type_typedef Class_any_from_list_reduce_next::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_any_from_list_reduce_next::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-list-reduce-next", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_any_from_list_reduce_next::vx_empty() const {return vx_core::e_any_from_list_reduce_next();}
    vx_core::Type_any Class_any_from_list_reduce_next::vx_type() const {return vx_core::t_any_from_list_reduce_next();}
    vx_core::Type_msgblock Class_any_from_list_reduce_next::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_list_reduce_next::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_any_from_list_reduce_next::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list list = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any valstart = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Func_any_from_reduce_next fn_reduce_next = vx_core::vx_any_from_any(vx_core::t_any_from_reduce_next(), arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_core::f_any_from_list_reduce_next(generic_any_1, list, valstart, fn_reduce_next);
      return output;
    }

  //}

  // (func any<-map)
  // class Class_any_from_map {
    Abstract_any_from_map::~Abstract_any_from_map() {}

    Class_any_from_map::Class_any_from_map() : Abstract_any_from_map::Abstract_any_from_map() {
      vx_core::refcount += 1;
    }
    Class_any_from_map::~Class_any_from_map() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_any_from_map::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_map output = vx_core::e_any_from_map();
      return output;
    }

    vx_core::Type_any Class_any_from_map::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_map output = vx_core::e_any_from_map();
      return output;
    }

    vx_core::Type_typedef Class_any_from_map::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_any_from_map::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-map", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_any_from_map::vx_empty() const {return vx_core::e_any_from_map();}
    vx_core::Type_any Class_any_from_map::vx_type() const {return vx_core::t_any_from_map();}
    vx_core::Type_msgblock Class_any_from_map::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_map::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_any_from_map::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_map valuemap = vx_core::vx_any_from_any(vx_core::t_map(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string key = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_any_from_map(generic_any_1, valuemap, key);
      return output;
    }

  //}

  // (func any<-none)
  // class Class_any_from_none {
    Abstract_any_from_none::~Abstract_any_from_none() {}

    Class_any_from_none::Class_any_from_none() : Abstract_any_from_none::Abstract_any_from_none() {
      vx_core::refcount += 1;
    }
    Class_any_from_none::~Class_any_from_none() {
      vx_core::refcount -= 1;
    }
    vx_core::Func_any_from_none Class_any_from_none::vx_fn_new(vx_core::Abstract_any_from_none::IFn fn) const {
      vx_core::Func_any_from_none output = new vx_core::Class_any_from_none();
      output->fn = fn;
      return output;
    }

    vx_core::Type_any Class_any_from_none::vx_any_from_none() const {
      vx_core::Type_any output = vx_core::e_any();
      return output;
    }

    vx_core::Type_any Class_any_from_none::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_none output = vx_core::e_any_from_none();
      return output;
    }

    vx_core::Type_any Class_any_from_none::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_none output = vx_core::e_any_from_none();
      return output;
    }

    vx_core::Type_typedef Class_any_from_none::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_any_from_none::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-none", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_any_from_none::vx_empty() const {return vx_core::e_any_from_none();}
    vx_core::Type_any Class_any_from_none::vx_type() const {return vx_core::t_any_from_none();}
    vx_core::Type_msgblock Class_any_from_none::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_none::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_any_from_none::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_any_from_none(generic_any_1);
      return output;
    }

  //}

  // (func any<-none-async)
  // class Class_any_from_none_async {
    Abstract_any_from_none_async::~Abstract_any_from_none_async() {}

    Class_any_from_none_async::Class_any_from_none_async() : Abstract_any_from_none_async::Abstract_any_from_none_async() {
      vx_core::refcount += 1;
    }
    Class_any_from_none_async::~Class_any_from_none_async() {
      vx_core::refcount -= 1;
    }
    vx_core::Func_any_from_none_async Class_any_from_none_async::vx_fn_new(vx_core::Abstract_any_from_none_async::IFn fn) const {
      vx_core::Func_any_from_none_async output = new vx_core::Class_any_from_none_async();
      output->fn = fn;
      return output;
    }

    vx_core::vx_Type_async Class_any_from_none_async::vx_any_from_none_async() const {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      return output;
    }

    vx_core::Type_any Class_any_from_none_async::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_none_async output = vx_core::e_any_from_none_async();
      return output;
    }

    vx_core::Type_any Class_any_from_none_async::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_none_async output = vx_core::e_any_from_none_async();
      return output;
    }

    vx_core::Type_typedef Class_any_from_none_async::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_any_from_none_async::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-none-async", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_any_from_none_async::vx_empty() const {return vx_core::e_any_from_none_async();}
    vx_core::Type_any Class_any_from_none_async::vx_type() const {return vx_core::t_any_from_none_async();}
    vx_core::Type_msgblock Class_any_from_none_async::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_none_async::vx_dispose() {return vx_core::emptylistany;}

    vx_core::vx_Type_async Class_any_from_none_async::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_any_from_none_async(generic_any_1);
      return output;
    }

  //}

  // (func any<-reduce)
  // class Class_any_from_reduce {
    Abstract_any_from_reduce::~Abstract_any_from_reduce() {}

    Class_any_from_reduce::Class_any_from_reduce() : Abstract_any_from_reduce::Abstract_any_from_reduce() {
      vx_core::refcount += 1;
    }
    Class_any_from_reduce::~Class_any_from_reduce() {
      vx_core::refcount -= 1;
    }
    vx_core::Func_any_from_reduce Class_any_from_reduce::vx_fn_new(vx_core::Abstract_any_from_reduce::IFn fn) const {
      vx_core::Func_any_from_reduce output = new vx_core::Class_any_from_reduce();
      output->fn = fn;
      return output;
    }

    vx_core::Type_any Class_any_from_reduce::vx_any_from_reduce(vx_core::Type_any result, vx_core::Type_any item) const {
      vx_core::Type_any output = vx_core::e_any();
      return output;
    }

    vx_core::Type_any Class_any_from_reduce::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_reduce output = vx_core::e_any_from_reduce();
      return output;
    }

    vx_core::Type_any Class_any_from_reduce::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_reduce output = vx_core::e_any_from_reduce();
      return output;
    }

    vx_core::Type_typedef Class_any_from_reduce::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_any_from_reduce::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-reduce", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_any_from_reduce::vx_empty() const {return vx_core::e_any_from_reduce();}
    vx_core::Type_any Class_any_from_reduce::vx_type() const {return vx_core::t_any_from_reduce();}
    vx_core::Type_msgblock Class_any_from_reduce::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_reduce::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_any_from_reduce::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any result = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any item = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_any_from_reduce(generic_any_1, result, item);
      return output;
    }

  //}

  // (func any<-reduce-async)
  // class Class_any_from_reduce_async {
    Abstract_any_from_reduce_async::~Abstract_any_from_reduce_async() {}

    Class_any_from_reduce_async::Class_any_from_reduce_async() : Abstract_any_from_reduce_async::Abstract_any_from_reduce_async() {
      vx_core::refcount += 1;
    }
    Class_any_from_reduce_async::~Class_any_from_reduce_async() {
      vx_core::refcount -= 1;
    }
    vx_core::Func_any_from_reduce_async Class_any_from_reduce_async::vx_fn_new(vx_core::Abstract_any_from_reduce_async::IFn fn) const {
      vx_core::Func_any_from_reduce_async output = new vx_core::Class_any_from_reduce_async();
      output->fn = fn;
      return output;
    }

    vx_core::vx_Type_async Class_any_from_reduce_async::vx_any_from_reduce_async(vx_core::Type_any result, vx_core::Type_any item) const {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      return output;
    }

    vx_core::Type_any Class_any_from_reduce_async::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_reduce_async output = vx_core::e_any_from_reduce_async();
      return output;
    }

    vx_core::Type_any Class_any_from_reduce_async::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_reduce_async output = vx_core::e_any_from_reduce_async();
      return output;
    }

    vx_core::Type_typedef Class_any_from_reduce_async::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_any_from_reduce_async::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-reduce-async", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_any_from_reduce_async::vx_empty() const {return vx_core::e_any_from_reduce_async();}
    vx_core::Type_any Class_any_from_reduce_async::vx_type() const {return vx_core::t_any_from_reduce_async();}
    vx_core::Type_msgblock Class_any_from_reduce_async::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_reduce_async::vx_dispose() {return vx_core::emptylistany;}

    vx_core::vx_Type_async Class_any_from_reduce_async::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any result = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any item = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_any_from_reduce_async(generic_any_1, result, item);
      return output;
    }

  //}

  // (func any<-reduce-next)
  // class Class_any_from_reduce_next {
    Abstract_any_from_reduce_next::~Abstract_any_from_reduce_next() {}

    Class_any_from_reduce_next::Class_any_from_reduce_next() : Abstract_any_from_reduce_next::Abstract_any_from_reduce_next() {
      vx_core::refcount += 1;
    }
    Class_any_from_reduce_next::~Class_any_from_reduce_next() {
      vx_core::refcount -= 1;
    }
    vx_core::Func_any_from_reduce_next Class_any_from_reduce_next::vx_fn_new(vx_core::Abstract_any_from_reduce_next::IFn fn) const {
      vx_core::Func_any_from_reduce_next output = new vx_core::Class_any_from_reduce_next();
      output->fn = fn;
      return output;
    }

    vx_core::Type_any Class_any_from_reduce_next::vx_any_from_reduce_next(vx_core::Type_any result, vx_core::Type_any current, vx_core::Type_any next) const {
      vx_core::Type_any output = vx_core::e_any();
      return output;
    }

    vx_core::Type_any Class_any_from_reduce_next::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_reduce_next output = vx_core::e_any_from_reduce_next();
      return output;
    }

    vx_core::Type_any Class_any_from_reduce_next::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_reduce_next output = vx_core::e_any_from_reduce_next();
      return output;
    }

    vx_core::Type_typedef Class_any_from_reduce_next::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_any_from_reduce_next::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-reduce-next", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_any_from_reduce_next::vx_empty() const {return vx_core::e_any_from_reduce_next();}
    vx_core::Type_any Class_any_from_reduce_next::vx_type() const {return vx_core::t_any_from_reduce_next();}
    vx_core::Type_msgblock Class_any_from_reduce_next::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_reduce_next::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_any_from_reduce_next::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any result = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any current = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_any next = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_core::f_any_from_reduce_next(generic_any_1, result, current, next);
      return output;
    }

  //}

  // (func any<-reduce-next-async)
  // class Class_any_from_reduce_next_async {
    Abstract_any_from_reduce_next_async::~Abstract_any_from_reduce_next_async() {}

    Class_any_from_reduce_next_async::Class_any_from_reduce_next_async() : Abstract_any_from_reduce_next_async::Abstract_any_from_reduce_next_async() {
      vx_core::refcount += 1;
    }
    Class_any_from_reduce_next_async::~Class_any_from_reduce_next_async() {
      vx_core::refcount -= 1;
    }
    vx_core::Func_any_from_reduce_next_async Class_any_from_reduce_next_async::vx_fn_new(vx_core::Abstract_any_from_reduce_next_async::IFn fn) const {
      vx_core::Func_any_from_reduce_next_async output = new vx_core::Class_any_from_reduce_next_async();
      output->fn = fn;
      return output;
    }

    vx_core::vx_Type_async Class_any_from_reduce_next_async::vx_any_from_reduce_next_async(vx_core::Type_any result, vx_core::Type_any current, vx_core::Type_any next) const {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      return output;
    }

    vx_core::Type_any Class_any_from_reduce_next_async::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_reduce_next_async output = vx_core::e_any_from_reduce_next_async();
      return output;
    }

    vx_core::Type_any Class_any_from_reduce_next_async::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_reduce_next_async output = vx_core::e_any_from_reduce_next_async();
      return output;
    }

    vx_core::Type_typedef Class_any_from_reduce_next_async::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_any_from_reduce_next_async::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-reduce-next-async", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_any_from_reduce_next_async::vx_empty() const {return vx_core::e_any_from_reduce_next_async();}
    vx_core::Type_any Class_any_from_reduce_next_async::vx_type() const {return vx_core::t_any_from_reduce_next_async();}
    vx_core::Type_msgblock Class_any_from_reduce_next_async::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_reduce_next_async::vx_dispose() {return vx_core::emptylistany;}

    vx_core::vx_Type_async Class_any_from_reduce_next_async::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any result = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any current = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_any next = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_core::f_any_from_reduce_next_async(generic_any_1, result, current, next);
      return output;
    }

  //}

  // (func any<-struct)
  // class Class_any_from_struct {
    Abstract_any_from_struct::~Abstract_any_from_struct() {}

    Class_any_from_struct::Class_any_from_struct() : Abstract_any_from_struct::Abstract_any_from_struct() {
      vx_core::refcount += 1;
    }
    Class_any_from_struct::~Class_any_from_struct() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_any_from_struct::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_struct output = vx_core::e_any_from_struct();
      return output;
    }

    vx_core::Type_any Class_any_from_struct::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_any_from_struct output = vx_core::e_any_from_struct();
      return output;
    }

    vx_core::Type_typedef Class_any_from_struct::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_any_from_struct::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "any<-struct", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_any_from_struct::vx_empty() const {return vx_core::e_any_from_struct();}
    vx_core::Type_any Class_any_from_struct::vx_type() const {return vx_core::t_any_from_struct();}
    vx_core::Type_msgblock Class_any_from_struct::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_any_from_struct::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_any_from_struct::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_struct vstruct = vx_core::vx_any_from_any(vx_core::t_struct(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string key = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_any_from_struct(generic_any_1, vstruct, key);
      return output;
    }

  //}

  // (func async)
  // class Class_async {
    Abstract_async::~Abstract_async() {}

    Class_async::Class_async() : Abstract_async::Abstract_async() {
      vx_core::refcount += 1;
    }
    Class_async::~Class_async() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_async::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_async output = vx_core::e_async();
      return output;
    }

    vx_core::Type_any Class_async::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_async output = vx_core::e_async();
      return output;
    }

    vx_core::Type_typedef Class_async::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_async::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "async", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_async::vx_empty() const {return vx_core::e_async();}
    vx_core::Type_any Class_async::vx_type() const {return vx_core::t_async();}
    vx_core::Type_msgblock Class_async::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_async::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_async::vx_fn_new(vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async();
    }

    vx_core::vx_Type_async Class_async::vx_any_from_any_async(vx_core::Type_any val) const {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(val);
      return output;
    }

    vx_core::vx_Type_async Class_async::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_async(generic_any_1, value);
      return output;
    }

  //}

  // (func boolean<-any)
  vx_core::Type_boolean f_boolean_from_any(vx_core::Type_any value) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    return output;
  }

  // (func boolean<-any)
  // class Class_boolean_from_any {
    Abstract_boolean_from_any::~Abstract_boolean_from_any() {}

    Class_boolean_from_any::Class_boolean_from_any() : Abstract_boolean_from_any::Abstract_boolean_from_any() {
      vx_core::refcount += 1;
    }
    Class_boolean_from_any::~Class_boolean_from_any() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_boolean_from_any::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_boolean_from_any output = vx_core::e_boolean_from_any();
      return output;
    }

    vx_core::Type_any Class_boolean_from_any::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_boolean_from_any output = vx_core::e_boolean_from_any();
      return output;
    }

    vx_core::Type_typedef Class_boolean_from_any::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_boolean_from_any::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "boolean<-any", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_boolean_from_any::vx_empty() const {return vx_core::e_boolean_from_any();}
    vx_core::Type_any Class_boolean_from_any::vx_type() const {return vx_core::t_boolean_from_any();}
    vx_core::Type_msgblock Class_boolean_from_any::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_from_any::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_boolean_from_any::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_boolean_from_any::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any(), val);
      output = vx_core::f_boolean_from_any(inputval);
      return output;
    }

    vx_core::Type_any Class_boolean_from_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_boolean_from_any(value);
      return output;
    }

  //}

  // (func boolean<-func)
  vx_core::Type_boolean f_boolean_from_func() {
    vx_core::Type_boolean output = vx_core::e_boolean();
    return output;
  }

  // (func boolean<-func)
  // class Class_boolean_from_func {
    Abstract_boolean_from_func::~Abstract_boolean_from_func() {}

    Class_boolean_from_func::Class_boolean_from_func() : Abstract_boolean_from_func::Abstract_boolean_from_func() {
      vx_core::refcount += 1;
    }
    Class_boolean_from_func::~Class_boolean_from_func() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_boolean_from_func::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_boolean_from_func output = vx_core::e_boolean_from_func();
      return output;
    }

    vx_core::Type_any Class_boolean_from_func::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_boolean_from_func output = vx_core::e_boolean_from_func();
      return output;
    }

    vx_core::Type_typedef Class_boolean_from_func::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_boolean_from_func::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "boolean<-func", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_boolean_from_func::vx_empty() const {return vx_core::e_boolean_from_func();}
    vx_core::Type_any Class_boolean_from_func::vx_type() const {return vx_core::t_boolean_from_func();}
    vx_core::Type_msgblock Class_boolean_from_func::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_from_func::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_boolean_from_func vx_core::Class_boolean_from_func::vx_fn_new(vx_core::Abstract_any_from_func::IFn fn) const {
      vx_core::Func_boolean_from_func output = new vx_core::Class_boolean_from_func();
      output->fn = fn;
      return output;
    }

    vx_core::Type_boolean Class_boolean_from_func::vx_boolean_from_func() const {
      vx_core::Type_boolean output = vx_core::e_boolean();
      return output;
    }

    vx_core::Type_any Class_boolean_from_func::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      output = vx_core::f_boolean_from_func();
      return output;
    }

  //}

  // (func boolean<-none)
  vx_core::Type_boolean f_boolean_from_none() {
    vx_core::Type_boolean output = vx_core::e_boolean();
    return output;
  }

  // (func boolean<-none)
  // class Class_boolean_from_none {
    Abstract_boolean_from_none::~Abstract_boolean_from_none() {}

    Class_boolean_from_none::Class_boolean_from_none() : Abstract_boolean_from_none::Abstract_boolean_from_none() {
      vx_core::refcount += 1;
    }
    Class_boolean_from_none::~Class_boolean_from_none() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_boolean_from_none::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_boolean_from_none output = vx_core::e_boolean_from_none();
      return output;
    }

    vx_core::Type_any Class_boolean_from_none::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_boolean_from_none output = vx_core::e_boolean_from_none();
      return output;
    }

    vx_core::Type_typedef Class_boolean_from_none::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_boolean_from_none::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "boolean<-none", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_boolean_from_none::vx_empty() const {return vx_core::e_boolean_from_none();}
    vx_core::Type_any Class_boolean_from_none::vx_type() const {return vx_core::t_boolean_from_none();}
    vx_core::Type_msgblock Class_boolean_from_none::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_boolean_from_none::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_boolean_from_none vx_core::Class_boolean_from_none::vx_fn_new(vx_core::Abstract_any_from_func::IFn fn) const {
      vx_core::Func_boolean_from_none output = new vx_core::Class_boolean_from_none();
      output->fn = fn;
      return output;
    }

    vx_core::Type_boolean Class_boolean_from_none::vx_boolean_from_none() const {
      vx_core::Type_boolean output = vx_core::e_boolean();
      return output;
    }

    vx_core::Type_any Class_boolean_from_none::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      output = vx_core::f_boolean_from_none();
      return output;
    }

  //}

  // (func empty)
  // class Class_empty {
    Abstract_empty::~Abstract_empty() {}

    Class_empty::Class_empty() : Abstract_empty::Abstract_empty() {
      vx_core::refcount += 1;
    }
    Class_empty::~Class_empty() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_empty::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_empty output = vx_core::e_empty();
      return output;
    }

    vx_core::Type_any Class_empty::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_empty output = vx_core::e_empty();
      return output;
    }

    vx_core::Type_typedef Class_empty::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_empty::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "empty", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_empty::vx_empty() const {return vx_core::e_empty();}
    vx_core::Type_any Class_empty::vx_type() const {return vx_core::t_empty();}
    vx_core::Type_msgblock Class_empty::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_empty::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_empty::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_empty::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any(), val);
      output = vx_core::f_empty(inputval);
      return output;
    }

    vx_core::Type_any Class_empty::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any type = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_empty(type);
      return output;
    }

  //}

  // (func new)
  // class Class_new {
    Abstract_new::~Abstract_new() {}

    Class_new::Class_new() : Abstract_new::Abstract_new() {
      vx_core::refcount += 1;
    }
    Class_new::~Class_new() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_new::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_new output = vx_core::e_new();
      return output;
    }

    vx_core::Type_any Class_new::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_new output = vx_core::e_new();
      return output;
    }

    vx_core::Type_typedef Class_new::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_new::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "new", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_new::vx_empty() const {return vx_core::e_new();}
    vx_core::Type_any Class_new::vx_type() const {return vx_core::t_new();}
    vx_core::Type_msgblock Class_new::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_new::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_new::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any type = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_anylist values = vx_core::vx_any_from_any(vx_core::t_anylist(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_new(type, values);
      return output;
    }

  //}

  // (func copy)
  // class Class_copy {
    Abstract_copy::~Abstract_copy() {}

    Class_copy::Class_copy() : Abstract_copy::Abstract_copy() {
      vx_core::refcount += 1;
    }
    Class_copy::~Class_copy() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_copy::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_copy output = vx_core::e_copy();
      return output;
    }

    vx_core::Type_any Class_copy::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_copy output = vx_core::e_copy();
      return output;
    }

    vx_core::Type_typedef Class_copy::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_copy::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "copy", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_copy::vx_empty() const {return vx_core::e_copy();}
    vx_core::Type_any Class_copy::vx_type() const {return vx_core::t_copy();}
    vx_core::Type_msgblock Class_copy::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_copy::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_copy::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_anylist values = vx_core::vx_any_from_any(vx_core::t_anylist(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_copy(value, values);
      return output;
    }

  //}

  // (func is-empty)
  vx_core::Type_boolean f_is_empty(vx_core::Type_string text) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    if (text->vx_string().length() == 0) {
     output = vx_core::c_true();
    };
    return output;
  }

  // (func is-empty)
  // class Class_is_empty {
    Abstract_is_empty::~Abstract_is_empty() {}

    Class_is_empty::Class_is_empty() : Abstract_is_empty::Abstract_is_empty() {
      vx_core::refcount += 1;
    }
    Class_is_empty::~Class_is_empty() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_is_empty::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_is_empty output = vx_core::e_is_empty();
      return output;
    }

    vx_core::Type_any Class_is_empty::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_is_empty output = vx_core::e_is_empty();
      return output;
    }

    vx_core::Type_typedef Class_is_empty::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_is_empty::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "is-empty", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_is_empty::vx_empty() const {return vx_core::e_is_empty();}
    vx_core::Type_any Class_is_empty::vx_type() const {return vx_core::t_is_empty();}
    vx_core::Type_msgblock Class_is_empty::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_is_empty::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_is_empty::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_is_empty::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string(), val);
      output = vx_core::f_is_empty(inputval);
      return output;
    }

    vx_core::Type_any Class_is_empty::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_is_empty(text);
      return output;
    }

  //}

  // (func is-empty)
  vx_core::Type_boolean f_is_empty_1(vx_core::Type_any value) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    if (value == value->vx_empty()) {
      output = vx_core::c_true();
    };
    return output;
  }

  // (func is-empty)
  // class Class_is_empty_1 {
    Abstract_is_empty_1::~Abstract_is_empty_1() {}

    Class_is_empty_1::Class_is_empty_1() : Abstract_is_empty_1::Abstract_is_empty_1() {
      vx_core::refcount += 1;
    }
    Class_is_empty_1::~Class_is_empty_1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_is_empty_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_is_empty_1 output = vx_core::e_is_empty_1();
      return output;
    }

    vx_core::Type_any Class_is_empty_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_is_empty_1 output = vx_core::e_is_empty_1();
      return output;
    }

    vx_core::Type_typedef Class_is_empty_1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_is_empty_1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "is-empty", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_is_empty_1::vx_empty() const {return vx_core::e_is_empty_1();}
    vx_core::Type_any Class_is_empty_1::vx_type() const {return vx_core::t_is_empty_1();}
    vx_core::Type_msgblock Class_is_empty_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_is_empty_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_is_empty_1::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_is_empty_1::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any(), val);
      output = vx_core::f_is_empty_1(inputval);
      return output;
    }

    vx_core::Type_any Class_is_empty_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_is_empty_1(value);
      return output;
    }

  //}

  // (func !)
  vx_core::Type_boolean f_not(vx_core::Type_boolean val) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    output = vx_core::vx_new_boolean(!val->vx_boolean());
    return output;
  }

  // (func !)
  // class Class_not {
    Abstract_not::~Abstract_not() {}

    Class_not::Class_not() : Abstract_not::Abstract_not() {
      vx_core::refcount += 1;
    }
    Class_not::~Class_not() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_not::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_not output = vx_core::e_not();
      return output;
    }

    vx_core::Type_any Class_not::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_not output = vx_core::e_not();
      return output;
    }

    vx_core::Type_typedef Class_not::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_not::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "!", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_not::vx_empty() const {return vx_core::e_not();}
    vx_core::Type_any Class_not::vx_type() const {return vx_core::t_not();}
    vx_core::Type_msgblock Class_not::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_not::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_not::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_not::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_boolean inputval = vx_core::vx_any_from_any(vx_core::t_boolean(), val);
      output = vx_core::f_not(inputval);
      return output;
    }

    vx_core::Type_any Class_not::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_boolean val = vx_core::vx_any_from_any(vx_core::t_boolean(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_not(val);
      return output;
    }

  //}

  // (func !-empty)
  vx_core::Type_boolean f_notempty(vx_core::Type_string text) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    output = vx_core::f_not(
      vx_core::f_is_empty(text)
    );
    return output;
  }

  // (func !-empty)
  // class Class_notempty {
    Abstract_notempty::~Abstract_notempty() {}

    Class_notempty::Class_notempty() : Abstract_notempty::Abstract_notempty() {
      vx_core::refcount += 1;
    }
    Class_notempty::~Class_notempty() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_notempty::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_notempty output = vx_core::e_notempty();
      return output;
    }

    vx_core::Type_any Class_notempty::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_notempty output = vx_core::e_notempty();
      return output;
    }

    vx_core::Type_typedef Class_notempty::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_notempty::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "!-empty", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_notempty::vx_empty() const {return vx_core::e_notempty();}
    vx_core::Type_any Class_notempty::vx_type() const {return vx_core::t_notempty();}
    vx_core::Type_msgblock Class_notempty::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_notempty::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_notempty::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_notempty::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string(), val);
      output = vx_core::f_notempty(inputval);
      return output;
    }

    vx_core::Type_any Class_notempty::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_notempty(text);
      return output;
    }

  //}

  // (func !-empty)
  vx_core::Type_boolean f_notempty_1(vx_core::Type_any val) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    output = vx_core::f_not(
      vx_core::f_is_empty_1(val)
    );
    return output;
  }

  // (func !-empty)
  // class Class_notempty_1 {
    Abstract_notempty_1::~Abstract_notempty_1() {}

    Class_notempty_1::Class_notempty_1() : Abstract_notempty_1::Abstract_notempty_1() {
      vx_core::refcount += 1;
    }
    Class_notempty_1::~Class_notempty_1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_notempty_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_notempty_1 output = vx_core::e_notempty_1();
      return output;
    }

    vx_core::Type_any Class_notempty_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_notempty_1 output = vx_core::e_notempty_1();
      return output;
    }

    vx_core::Type_typedef Class_notempty_1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_notempty_1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "!-empty", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_notempty_1::vx_empty() const {return vx_core::e_notempty_1();}
    vx_core::Type_any Class_notempty_1::vx_type() const {return vx_core::t_notempty_1();}
    vx_core::Type_msgblock Class_notempty_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_notempty_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_notempty_1::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_notempty_1::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any(), val);
      output = vx_core::f_notempty_1(inputval);
      return output;
    }

    vx_core::Type_any Class_notempty_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any val = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_notempty_1(val);
      return output;
    }

  //}

  // (func =)
  vx_core::Type_boolean f_eq(vx_core::Type_any val1, vx_core::Type_any val2) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    bool isequal = false;
    if (val1 == val2) {
      isequal = true;
    } else {
      std::string str1 = vx_core::vx_string_from_any(val1);
      std::string str2 = vx_core::vx_string_from_any(val2);
      if (str1 == str2) {
        isequal = true;
      }
    }
    output = vx_core::vx_new_boolean(isequal);
    return output;
  }

  // (func =)
  // class Class_eq {
    Abstract_eq::~Abstract_eq() {}

    Class_eq::Class_eq() : Abstract_eq::Abstract_eq() {
      vx_core::refcount += 1;
    }
    Class_eq::~Class_eq() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_eq::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_eq output = vx_core::e_eq();
      return output;
    }

    vx_core::Type_any Class_eq::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_eq output = vx_core::e_eq();
      return output;
    }

    vx_core::Type_typedef Class_eq::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_eq::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "=", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_eq::vx_empty() const {return vx_core::e_eq();}
    vx_core::Type_any Class_eq::vx_type() const {return vx_core::t_eq();}
    vx_core::Type_msgblock Class_eq::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_eq::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_eq::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any val1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any val2 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_eq(val1, val2);
      return output;
    }

  //}

  // (func =)
  vx_core::Type_boolean f_eq_1(vx_core::Type_anylist values) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    output = vx_core::f_any_from_list_reduce_next(
      vx_core::t_boolean(),
      values,
      vx_core::vx_new_boolean(false),
      vx_core::t_any_from_reduce_next()->vx_fn_new([](vx_core::Type_any reduce_any, vx_core::Type_any current_any, vx_core::Type_any next_any) {
        vx_core::Type_boolean reduce = vx_core::vx_any_from_any(vx_core::t_boolean(), reduce_any);
        vx_core::Type_any current = vx_core::vx_any_from_any(vx_core::t_any(), current_any);
        vx_core::Type_any next = vx_core::vx_any_from_any(vx_core::t_any(), next_any);
        return 
          vx_core::f_and(
            reduce,
            vx_core::f_eq(current, next)
          );
      })
    );
    return output;
  }

  // (func =)
  // class Class_eq_1 {
    Abstract_eq_1::~Abstract_eq_1() {}

    Class_eq_1::Class_eq_1() : Abstract_eq_1::Abstract_eq_1() {
      vx_core::refcount += 1;
    }
    Class_eq_1::~Class_eq_1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_eq_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_eq_1 output = vx_core::e_eq_1();
      return output;
    }

    vx_core::Type_any Class_eq_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_eq_1 output = vx_core::e_eq_1();
      return output;
    }

    vx_core::Type_typedef Class_eq_1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_eq_1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "=", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_eq_1::vx_empty() const {return vx_core::e_eq_1();}
    vx_core::Type_any Class_eq_1::vx_type() const {return vx_core::t_eq_1();}
    vx_core::Type_msgblock Class_eq_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_eq_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_eq_1::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_eq_1::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_anylist inputval = vx_core::vx_any_from_any(vx_core::t_anylist(), val);
      output = vx_core::f_eq_1(inputval);
      return output;
    }

    vx_core::Type_any Class_eq_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_anylist values = vx_core::vx_any_from_any(vx_core::t_anylist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_eq_1(values);
      return output;
    }

  //}

  // (func !=)
  vx_core::Type_boolean f_ne(vx_core::Type_any val1, vx_core::Type_any val2) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    output = vx_core::f_not(
      vx_core::f_eq(val1, val2)
    );
    return output;
  }

  // (func !=)
  // class Class_ne {
    Abstract_ne::~Abstract_ne() {}

    Class_ne::Class_ne() : Abstract_ne::Abstract_ne() {
      vx_core::refcount += 1;
    }
    Class_ne::~Class_ne() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_ne::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_ne output = vx_core::e_ne();
      return output;
    }

    vx_core::Type_any Class_ne::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_ne output = vx_core::e_ne();
      return output;
    }

    vx_core::Type_typedef Class_ne::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_ne::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "!=", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_ne::vx_empty() const {return vx_core::e_ne();}
    vx_core::Type_any Class_ne::vx_type() const {return vx_core::t_ne();}
    vx_core::Type_msgblock Class_ne::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ne::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_ne::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any val1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any val2 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_ne(val1, val2);
      return output;
    }

  //}

  // (func then)
  vx_core::Type_thenelse f_then(vx_core::Func_boolean_from_func fn_cond, vx_core::Func_any_from_func fn_any) {
    vx_core::Type_thenelse output = vx_core::e_thenelse();
    output = vx_core::f_new(
      vx_core::t_thenelse(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":code"),
        vx_core::vx_new_string(":then"),
        vx_core::vx_new_string(":fn-cond"),
        fn_cond,
        vx_core::vx_new_string(":fn-any"),
        fn_any
      })
    );
    return output;
  }

  // (func then)
  // class Class_then {
    Abstract_then::~Abstract_then() {}

    Class_then::Class_then() : Abstract_then::Abstract_then() {
      vx_core::refcount += 1;
    }
    Class_then::~Class_then() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_then::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_then output = vx_core::e_then();
      return output;
    }

    vx_core::Type_any Class_then::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_then output = vx_core::e_then();
      return output;
    }

    vx_core::Type_typedef Class_then::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "thenelse", // name
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
    }

    vx_core::Type_funcdef Class_then::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "then", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_then::vx_empty() const {return vx_core::e_then();}
    vx_core::Type_any Class_then::vx_type() const {return vx_core::t_then();}
    vx_core::Type_msgblock Class_then::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_then::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_then::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Func_boolean_from_func fn_cond = vx_core::vx_any_from_any(vx_core::t_boolean_from_func(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_func fn_any = vx_core::vx_any_from_any(vx_core::t_any_from_func(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_then(fn_cond, fn_any);
      return output;
    }

  //}

  // (func else)
  vx_core::Type_thenelse f_else(vx_core::Func_any_from_func fn_any) {
    vx_core::Type_thenelse output = vx_core::e_thenelse();
    output = vx_core::f_new(
      vx_core::t_thenelse(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":code"),
        vx_core::vx_new_string(":else"),
        vx_core::vx_new_string(":fn-any"),
        fn_any
      })
    );
    return output;
  }

  // (func else)
  // class Class_else {
    Abstract_else::~Abstract_else() {}

    Class_else::Class_else() : Abstract_else::Abstract_else() {
      vx_core::refcount += 1;
    }
    Class_else::~Class_else() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_else::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_else output = vx_core::e_else();
      return output;
    }

    vx_core::Type_any Class_else::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_else output = vx_core::e_else();
      return output;
    }

    vx_core::Type_typedef Class_else::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "thenelse", // name
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
    }

    vx_core::Type_funcdef Class_else::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "else", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_else::vx_empty() const {return vx_core::e_else();}
    vx_core::Type_any Class_else::vx_type() const {return vx_core::t_else();}
    vx_core::Type_msgblock Class_else::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_else::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_else::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_else::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Func_any_from_func inputval = vx_core::vx_any_from_any(vx_core::t_any_from_func(), val);
      output = vx_core::f_else(inputval);
      return output;
    }

    vx_core::Type_any Class_else::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Func_any_from_func fn_any = vx_core::vx_any_from_any(vx_core::t_any_from_func(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_else(fn_any);
      return output;
    }

  //}

  // (func if)
  // class Class_if {
    Abstract_if::~Abstract_if() {}

    Class_if::Class_if() : Abstract_if::Abstract_if() {
      vx_core::refcount += 1;
    }
    Class_if::~Class_if() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_if::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_if output = vx_core::e_if();
      return output;
    }

    vx_core::Type_any Class_if::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_if output = vx_core::e_if();
      return output;
    }

    vx_core::Type_typedef Class_if::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_if::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "if", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_if::vx_empty() const {return vx_core::e_if();}
    vx_core::Type_any Class_if::vx_type() const {return vx_core::t_if();}
    vx_core::Type_msgblock Class_if::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_if::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_if::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_boolean clause = vx_core::vx_any_from_any(vx_core::t_boolean(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any then = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_if(generic_any_1, clause, then);
      return output;
    }

  //}

  // (func if)
  // class Class_if_1 {
    Abstract_if_1::~Abstract_if_1() {}

    Class_if_1::Class_if_1() : Abstract_if_1::Abstract_if_1() {
      vx_core::refcount += 1;
    }
    Class_if_1::~Class_if_1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_if_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_if_1 output = vx_core::e_if_1();
      return output;
    }

    vx_core::Type_any Class_if_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_if_1 output = vx_core::e_if_1();
      return output;
    }

    vx_core::Type_typedef Class_if_1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_if_1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "if", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_if_1::vx_empty() const {return vx_core::e_if_1();}
    vx_core::Type_any Class_if_1::vx_type() const {return vx_core::t_if_1();}
    vx_core::Type_msgblock Class_if_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_if_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_if_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_boolean clause = vx_core::vx_any_from_any(vx_core::t_boolean(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any thenval = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_any elseval = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_core::f_if_1(generic_any_1, clause, thenval, elseval);
      return output;
    }

  //}

  // (func if)
  // class Class_if_2 {
    Abstract_if_2::~Abstract_if_2() {}

    Class_if_2::Class_if_2() : Abstract_if_2::Abstract_if_2() {
      vx_core::refcount += 1;
    }
    Class_if_2::~Class_if_2() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_if_2::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_if_2 output = vx_core::e_if_2();
      return output;
    }

    vx_core::Type_any Class_if_2::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_if_2 output = vx_core::e_if_2();
      return output;
    }

    vx_core::Type_typedef Class_if_2::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_if_2::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "if", // name
        2, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_if_2::vx_empty() const {return vx_core::e_if_2();}
    vx_core::Type_any Class_if_2::vx_type() const {return vx_core::t_if_2();}
    vx_core::Type_msgblock Class_if_2::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_if_2::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_if_2::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_if_2::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_thenelselist inputval = vx_core::vx_any_from_any(vx_core::t_thenelselist(), val);
      output = vx_core::f_if_2(vx_core::t_any(), inputval);
      return output;
    }

    vx_core::Type_any Class_if_2::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_thenelselist thenelselist = vx_core::vx_any_from_any(vx_core::t_thenelselist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_if_2(generic_any_1, thenelselist);
      return output;
    }

  //}

  // (func case)
  vx_core::Type_thenelse f_case(vx_core::Type_list values, vx_core::Func_any_from_func fn_any) {
    vx_core::Type_thenelse output = vx_core::e_thenelse();
    output = vx_core::f_new(
      vx_core::t_thenelse(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":code"),
        vx_core::vx_new_string(":casemany"),
        vx_core::vx_new_string(":values"),
        values,
        vx_core::vx_new_string(":fn-any"),
        fn_any
      })
    );
    return output;
  }

  // (func case)
  // class Class_case {
    Abstract_case::~Abstract_case() {}

    Class_case::Class_case() : Abstract_case::Abstract_case() {
      vx_core::refcount += 1;
    }
    Class_case::~Class_case() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_case::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_case output = vx_core::e_case();
      return output;
    }

    vx_core::Type_any Class_case::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_case output = vx_core::e_case();
      return output;
    }

    vx_core::Type_typedef Class_case::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "thenelse", // name
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
    }

    vx_core::Type_funcdef Class_case::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "case", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_case::vx_empty() const {return vx_core::e_case();}
    vx_core::Type_any Class_case::vx_type() const {return vx_core::t_case();}
    vx_core::Type_msgblock Class_case::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_case::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_case::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_list values = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_func fn_any = vx_core::vx_any_from_any(vx_core::t_any_from_func(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_case(values, fn_any);
      return output;
    }

  //}

  // (func case)
  vx_core::Type_thenelse f_case_1(vx_core::Type_any value, vx_core::Func_any_from_func fn_any) {
    vx_core::Type_thenelse output = vx_core::e_thenelse();
    output = vx_core::f_new(
      vx_core::t_thenelse(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":code"),
        vx_core::vx_new_string(":case"),
        vx_core::vx_new_string(":value"),
        value,
        vx_core::vx_new_string(":fn-any"),
        fn_any
      })
    );
    return output;
  }

  // (func case)
  // class Class_case_1 {
    Abstract_case_1::~Abstract_case_1() {}

    Class_case_1::Class_case_1() : Abstract_case_1::Abstract_case_1() {
      vx_core::refcount += 1;
    }
    Class_case_1::~Class_case_1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_case_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_case_1 output = vx_core::e_case_1();
      return output;
    }

    vx_core::Type_any Class_case_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_case_1 output = vx_core::e_case_1();
      return output;
    }

    vx_core::Type_typedef Class_case_1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "thenelse", // name
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
    }

    vx_core::Type_funcdef Class_case_1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "case", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_case_1::vx_empty() const {return vx_core::e_case_1();}
    vx_core::Type_any Class_case_1::vx_type() const {return vx_core::t_case_1();}
    vx_core::Type_msgblock Class_case_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_case_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_case_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_func fn_any = vx_core::vx_any_from_any(vx_core::t_any_from_func(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_case_1(value, fn_any);
      return output;
    }

  //}

  // (func switch)
  // class Class_switch {
    Abstract_switch::~Abstract_switch() {}

    Class_switch::Class_switch() : Abstract_switch::Abstract_switch() {
      vx_core::refcount += 1;
    }
    Class_switch::~Class_switch() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_switch::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_switch output = vx_core::e_switch();
      return output;
    }

    vx_core::Type_any Class_switch::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_switch output = vx_core::e_switch();
      return output;
    }

    vx_core::Type_typedef Class_switch::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_switch::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "switch", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_switch::vx_empty() const {return vx_core::e_switch();}
    vx_core::Type_any Class_switch::vx_type() const {return vx_core::t_switch();}
    vx_core::Type_msgblock Class_switch::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_switch::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_switch::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any val = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_thenelselist thenelselist = vx_core::vx_any_from_any(vx_core::t_thenelselist(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_switch(generic_any_1, val, thenelselist);
      return output;
    }

  //}

  // (func length<-list)
  vx_core::Type_int f_length_from_list(vx_core::Type_list values) {
    vx_core::Type_int output = vx_core::e_int();
    return output;
  }

  // (func length<-list)
  // class Class_length_from_list {
    Abstract_length_from_list::~Abstract_length_from_list() {}

    Class_length_from_list::Class_length_from_list() : Abstract_length_from_list::Abstract_length_from_list() {
      vx_core::refcount += 1;
    }
    Class_length_from_list::~Class_length_from_list() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_length_from_list::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_length_from_list output = vx_core::e_length_from_list();
      return output;
    }

    vx_core::Type_any Class_length_from_list::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_length_from_list output = vx_core::e_length_from_list();
      return output;
    }

    vx_core::Type_typedef Class_length_from_list::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "int", // name
        "", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_length_from_list::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "length<-list", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_length_from_list::vx_empty() const {return vx_core::e_length_from_list();}
    vx_core::Type_any Class_length_from_list::vx_type() const {return vx_core::t_length_from_list();}
    vx_core::Type_msgblock Class_length_from_list::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_length_from_list::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_length_from_list::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_length_from_list::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_list inputval = vx_core::vx_any_from_any(vx_core::t_list(), val);
      output = vx_core::f_length_from_list(inputval);
      return output;
    }

    vx_core::Type_any Class_length_from_list::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_list values = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_length_from_list(values);
      return output;
    }

  //}

  // (func and)
  vx_core::Type_boolean f_and(vx_core::Type_boolean val1, vx_core::Type_boolean val2) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    return output;
  }

  // (func and)
  // class Class_and {
    Abstract_and::~Abstract_and() {}

    Class_and::Class_and() : Abstract_and::Abstract_and() {
      vx_core::refcount += 1;
    }
    Class_and::~Class_and() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_and::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_and output = vx_core::e_and();
      return output;
    }

    vx_core::Type_any Class_and::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_and output = vx_core::e_and();
      return output;
    }

    vx_core::Type_typedef Class_and::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_and::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "and", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_and::vx_empty() const {return vx_core::e_and();}
    vx_core::Type_any Class_and::vx_type() const {return vx_core::t_and();}
    vx_core::Type_msgblock Class_and::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_and::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_and::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_boolean val1 = vx_core::vx_any_from_any(vx_core::t_boolean(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_boolean val2 = vx_core::vx_any_from_any(vx_core::t_boolean(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_and(val1, val2);
      return output;
    }

  //}

  // (func and)
  vx_core::Type_boolean f_and_1(vx_core::Type_booleanlist values) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    output = vx_core::f_switch(
      vx_core::t_boolean(),
      vx_core::f_length_from_list(values),
      vx_core::vx_new(vx_core::t_thenelselist(), {
        vx_core::f_case_1(
          vx_core::vx_new_int(0),
          vx_core::t_any_from_func()->vx_fn_new([]() {
            return vx_core::vx_new_boolean(true);
          })
        ),
        vx_core::f_case_1(
          vx_core::vx_new_int(1),
          vx_core::t_any_from_func()->vx_fn_new([values]() {
            return vx_core::f_any_from_list(vx_core::t_boolean(), values, vx_core::vx_new_int(0));
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func()->vx_fn_new([values]() {
            return vx_core::f_any_from_list_reduce_next(
              vx_core::t_boolean(),
              values,
              vx_core::vx_new_boolean(true),
              vx_core::t_any_from_reduce_next()->vx_fn_new([](vx_core::Type_any reduce_any, vx_core::Type_any current_any, vx_core::Type_any next_any) {
                vx_core::Type_boolean reduce = vx_core::vx_any_from_any(vx_core::t_boolean(), reduce_any);
                vx_core::Type_boolean current = vx_core::vx_any_from_any(vx_core::t_boolean(), current_any);
                vx_core::Type_boolean next = vx_core::vx_any_from_any(vx_core::t_boolean(), next_any);
                return 
                  vx_core::f_and(
                    reduce,
                    vx_core::f_and(current, next)
                  );
              })
            );
          })
        )
      })
    );
    return output;
  }

  // (func and)
  // class Class_and_1 {
    Abstract_and_1::~Abstract_and_1() {}

    Class_and_1::Class_and_1() : Abstract_and_1::Abstract_and_1() {
      vx_core::refcount += 1;
    }
    Class_and_1::~Class_and_1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_and_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_and_1 output = vx_core::e_and_1();
      return output;
    }

    vx_core::Type_any Class_and_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_and_1 output = vx_core::e_and_1();
      return output;
    }

    vx_core::Type_typedef Class_and_1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_and_1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "and", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_and_1::vx_empty() const {return vx_core::e_and_1();}
    vx_core::Type_any Class_and_1::vx_type() const {return vx_core::t_and_1();}
    vx_core::Type_msgblock Class_and_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_and_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_and_1::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_and_1::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_booleanlist inputval = vx_core::vx_any_from_any(vx_core::t_booleanlist(), val);
      output = vx_core::f_and_1(inputval);
      return output;
    }

    vx_core::Type_any Class_and_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_booleanlist values = vx_core::vx_any_from_any(vx_core::t_booleanlist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_and_1(values);
      return output;
    }

  //}

  // (func or)
  vx_core::Type_boolean f_or(vx_core::Type_boolean val1, vx_core::Type_boolean val2) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    return output;
  }

  // (func or)
  // class Class_or {
    Abstract_or::~Abstract_or() {}

    Class_or::Class_or() : Abstract_or::Abstract_or() {
      vx_core::refcount += 1;
    }
    Class_or::~Class_or() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_or::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_or output = vx_core::e_or();
      return output;
    }

    vx_core::Type_any Class_or::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_or output = vx_core::e_or();
      return output;
    }

    vx_core::Type_typedef Class_or::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_or::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "or", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_or::vx_empty() const {return vx_core::e_or();}
    vx_core::Type_any Class_or::vx_type() const {return vx_core::t_or();}
    vx_core::Type_msgblock Class_or::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_or::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_or::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_boolean val1 = vx_core::vx_any_from_any(vx_core::t_boolean(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_boolean val2 = vx_core::vx_any_from_any(vx_core::t_boolean(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_or(val1, val2);
      return output;
    }

  //}

  // (func or)
  vx_core::Type_boolean f_or_1(vx_core::Type_booleanlist values) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    output = vx_core::f_any_from_list_reduce_next(
      vx_core::t_boolean(),
      values,
      vx_core::vx_new_boolean(false),
      vx_core::t_any_from_reduce_next()->vx_fn_new([](vx_core::Type_any reduce_any, vx_core::Type_any current_any, vx_core::Type_any next_any) {
        vx_core::Type_boolean reduce = vx_core::vx_any_from_any(vx_core::t_boolean(), reduce_any);
        vx_core::Type_boolean current = vx_core::vx_any_from_any(vx_core::t_boolean(), current_any);
        vx_core::Type_boolean next = vx_core::vx_any_from_any(vx_core::t_boolean(), next_any);
        return 
          vx_core::f_or(
            reduce,
            vx_core::f_or(current, next)
          );
      })
    );
    return output;
  }

  // (func or)
  // class Class_or_1 {
    Abstract_or_1::~Abstract_or_1() {}

    Class_or_1::Class_or_1() : Abstract_or_1::Abstract_or_1() {
      vx_core::refcount += 1;
    }
    Class_or_1::~Class_or_1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_or_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_or_1 output = vx_core::e_or_1();
      return output;
    }

    vx_core::Type_any Class_or_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_or_1 output = vx_core::e_or_1();
      return output;
    }

    vx_core::Type_typedef Class_or_1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_or_1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "or", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_or_1::vx_empty() const {return vx_core::e_or_1();}
    vx_core::Type_any Class_or_1::vx_type() const {return vx_core::t_or_1();}
    vx_core::Type_msgblock Class_or_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_or_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_or_1::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_or_1::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_booleanlist inputval = vx_core::vx_any_from_any(vx_core::t_booleanlist(), val);
      output = vx_core::f_or_1(inputval);
      return output;
    }

    vx_core::Type_any Class_or_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_booleanlist values = vx_core::vx_any_from_any(vx_core::t_booleanlist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_or_1(values);
      return output;
    }

  //}

  // (func let)
  // class Class_let {
    Abstract_let::~Abstract_let() {}

    Class_let::Class_let() : Abstract_let::Abstract_let() {
      vx_core::refcount += 1;
    }
    Class_let::~Class_let() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_let::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_let output = vx_core::e_let();
      return output;
    }

    vx_core::Type_any Class_let::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_let output = vx_core::e_let();
      return output;
    }

    vx_core::Type_typedef Class_let::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_let::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "let", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_let::vx_empty() const {return vx_core::e_let();}
    vx_core::Type_any Class_let::vx_type() const {return vx_core::t_let();}
    vx_core::Type_msgblock Class_let::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_let::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_let::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_func fn_any = vx_core::vx_any_from_any(vx_core::t_any_from_func(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_let(generic_any_1, fn_any);
      return output;
    }

  //}

  // (func let-async)
  // class Class_let_async {
    Abstract_let_async::~Abstract_let_async() {}

    Class_let_async::Class_let_async() : Abstract_let_async::Abstract_let_async() {
      vx_core::refcount += 1;
    }
    Class_let_async::~Class_let_async() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_let_async::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_let_async output = vx_core::e_let_async();
      return output;
    }

    vx_core::Type_any Class_let_async::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_let_async output = vx_core::e_let_async();
      return output;
    }

    vx_core::Type_typedef Class_let_async::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_let_async::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "let-async", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_let_async::vx_empty() const {return vx_core::e_let_async();}
    vx_core::Type_any Class_let_async::vx_type() const {return vx_core::t_let_async();}
    vx_core::Type_msgblock Class_let_async::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_let_async::vx_dispose() {return vx_core::emptylistany;}

    vx_core::vx_Type_async Class_let_async::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_func_async fn_any_async = vx_core::vx_any_from_any(vx_core::t_any_from_func_async(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_let_async(generic_any_1, fn_any_async);
      return output;
    }

  //}

  // (func *)
  vx_core::Type_int f_multiply(vx_core::Type_int num1, vx_core::Type_int num2) {
    vx_core::Type_int output = vx_core::e_int();
    long result = num1->vx_int() * num2->vx_int();
    output = vx_core::vx_new_int(result);
    return output;
  }

  // (func *)
  // class Class_multiply {
    Abstract_multiply::~Abstract_multiply() {}

    Class_multiply::Class_multiply() : Abstract_multiply::Abstract_multiply() {
      vx_core::refcount += 1;
    }
    Class_multiply::~Class_multiply() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_multiply::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_multiply output = vx_core::e_multiply();
      return output;
    }

    vx_core::Type_any Class_multiply::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_multiply output = vx_core::e_multiply();
      return output;
    }

    vx_core::Type_typedef Class_multiply::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "int", // name
        "", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_multiply::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "*", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_multiply::vx_empty() const {return vx_core::e_multiply();}
    vx_core::Type_any Class_multiply::vx_type() const {return vx_core::t_multiply();}
    vx_core::Type_msgblock Class_multiply::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_multiply::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_multiply::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_int num1 = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int num2 = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_multiply(num1, num2);
      return output;
    }

  //}

  // (func *)
  vx_core::Type_number f_multiply_1(vx_core::Type_number num1, vx_core::Type_number num2) {
    vx_core::Type_number output = vx_core::e_number();
    return output;
  }

  // (func *)
  // class Class_multiply_1 {
    Abstract_multiply_1::~Abstract_multiply_1() {}

    Class_multiply_1::Class_multiply_1() : Abstract_multiply_1::Abstract_multiply_1() {
      vx_core::refcount += 1;
    }
    Class_multiply_1::~Class_multiply_1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_multiply_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_multiply_1 output = vx_core::e_multiply_1();
      return output;
    }

    vx_core::Type_any Class_multiply_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_multiply_1 output = vx_core::e_multiply_1();
      return output;
    }

    vx_core::Type_typedef Class_multiply_1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "number", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_int(), vx_core::t_float(), vx_core::t_decimal()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_multiply_1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "*", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_multiply_1::vx_empty() const {return vx_core::e_multiply_1();}
    vx_core::Type_any Class_multiply_1::vx_type() const {return vx_core::t_multiply_1();}
    vx_core::Type_msgblock Class_multiply_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_multiply_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_multiply_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_number num1 = vx_core::vx_any_from_any(vx_core::t_number(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_number num2 = vx_core::vx_any_from_any(vx_core::t_number(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_multiply_1(num1, num2);
      return output;
    }

  //}

  // (func *)
  vx_core::Type_int f_multiply_2(vx_core::Type_intlist nums) {
    vx_core::Type_int output = vx_core::e_int();
    output = vx_core::f_any_from_list_reduce(
      vx_core::t_int(),
      nums,
      vx_core::vx_new_int(1),
      vx_core::t_any_from_reduce()->vx_fn_new([](vx_core::Type_any total_any, vx_core::Type_any num_any) {
        vx_core::Type_int total = vx_core::vx_any_from_any(vx_core::t_int(), total_any);
        vx_core::Type_int num = vx_core::vx_any_from_any(vx_core::t_int(), num_any);
        return 
          vx_core::f_multiply(total, num);
      })
    );
    return output;
  }

  // (func *)
  // class Class_multiply_2 {
    Abstract_multiply_2::~Abstract_multiply_2() {}

    Class_multiply_2::Class_multiply_2() : Abstract_multiply_2::Abstract_multiply_2() {
      vx_core::refcount += 1;
    }
    Class_multiply_2::~Class_multiply_2() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_multiply_2::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_multiply_2 output = vx_core::e_multiply_2();
      return output;
    }

    vx_core::Type_any Class_multiply_2::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_multiply_2 output = vx_core::e_multiply_2();
      return output;
    }

    vx_core::Type_typedef Class_multiply_2::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "int", // name
        "", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_multiply_2::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "*", // name
        2, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_multiply_2::vx_empty() const {return vx_core::e_multiply_2();}
    vx_core::Type_any Class_multiply_2::vx_type() const {return vx_core::t_multiply_2();}
    vx_core::Type_msgblock Class_multiply_2::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_multiply_2::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_multiply_2::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_multiply_2::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_intlist inputval = vx_core::vx_any_from_any(vx_core::t_intlist(), val);
      output = vx_core::f_multiply_2(inputval);
      return output;
    }

    vx_core::Type_any Class_multiply_2::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_intlist nums = vx_core::vx_any_from_any(vx_core::t_intlist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_multiply_2(nums);
      return output;
    }

  //}

  // (func *)
  vx_core::Type_number f_multiply_3(vx_core::Type_numberlist nums) {
    vx_core::Type_number output = vx_core::e_number();
    output = vx_core::f_any_from_list_reduce(
      vx_core::t_number(),
      nums,
      (vx_core::Type_number)vx_core::vx_new_int(1),
      vx_core::t_any_from_reduce()->vx_fn_new([](vx_core::Type_any total_any, vx_core::Type_any num_any) {
        vx_core::Type_number total = vx_core::vx_any_from_any(vx_core::t_number(), total_any);
        vx_core::Type_number num = vx_core::vx_any_from_any(vx_core::t_number(), num_any);
        return 
          vx_core::f_multiply_1(total, num);
      })
    );
    return output;
  }

  // (func *)
  // class Class_multiply_3 {
    Abstract_multiply_3::~Abstract_multiply_3() {}

    Class_multiply_3::Class_multiply_3() : Abstract_multiply_3::Abstract_multiply_3() {
      vx_core::refcount += 1;
    }
    Class_multiply_3::~Class_multiply_3() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_multiply_3::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_multiply_3 output = vx_core::e_multiply_3();
      return output;
    }

    vx_core::Type_any Class_multiply_3::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_multiply_3 output = vx_core::e_multiply_3();
      return output;
    }

    vx_core::Type_typedef Class_multiply_3::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "number", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_int(), vx_core::t_float(), vx_core::t_decimal()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_multiply_3::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "*", // name
        3, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_multiply_3::vx_empty() const {return vx_core::e_multiply_3();}
    vx_core::Type_any Class_multiply_3::vx_type() const {return vx_core::t_multiply_3();}
    vx_core::Type_msgblock Class_multiply_3::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_multiply_3::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_multiply_3::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_multiply_3::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_numberlist inputval = vx_core::vx_any_from_any(vx_core::t_numberlist(), val);
      output = vx_core::f_multiply_3(inputval);
      return output;
    }

    vx_core::Type_any Class_multiply_3::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_numberlist nums = vx_core::vx_any_from_any(vx_core::t_numberlist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_multiply_3(nums);
      return output;
    }

  //}

  // (func +)
  vx_core::Type_int f_plus(vx_core::Type_int num1, vx_core::Type_int num2) {
    vx_core::Type_int output = vx_core::e_int();
    long result = num1->vx_int() + num2->vx_int();
    output = vx_core::vx_new_int(result);
    return output;
  }

  // (func +)
  // class Class_plus {
    Abstract_plus::~Abstract_plus() {}

    Class_plus::Class_plus() : Abstract_plus::Abstract_plus() {
      vx_core::refcount += 1;
    }
    Class_plus::~Class_plus() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_plus::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_plus output = vx_core::e_plus();
      return output;
    }

    vx_core::Type_any Class_plus::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_plus output = vx_core::e_plus();
      return output;
    }

    vx_core::Type_typedef Class_plus::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "int", // name
        "", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_plus::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "+", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_plus::vx_empty() const {return vx_core::e_plus();}
    vx_core::Type_any Class_plus::vx_type() const {return vx_core::t_plus();}
    vx_core::Type_msgblock Class_plus::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_plus::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_plus::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_int num1 = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int num2 = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_plus(num1, num2);
      return output;
    }

  //}

  // (func +)
  vx_core::Type_number f_plus_1(vx_core::Type_number num1, vx_core::Type_number num2) {
    vx_core::Type_number output = vx_core::e_number();
    return output;
  }

  // (func +)
  // class Class_plus_1 {
    Abstract_plus_1::~Abstract_plus_1() {}

    Class_plus_1::Class_plus_1() : Abstract_plus_1::Abstract_plus_1() {
      vx_core::refcount += 1;
    }
    Class_plus_1::~Class_plus_1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_plus_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_plus_1 output = vx_core::e_plus_1();
      return output;
    }

    vx_core::Type_any Class_plus_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_plus_1 output = vx_core::e_plus_1();
      return output;
    }

    vx_core::Type_typedef Class_plus_1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "number", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_int(), vx_core::t_float(), vx_core::t_decimal()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_plus_1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "+", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_plus_1::vx_empty() const {return vx_core::e_plus_1();}
    vx_core::Type_any Class_plus_1::vx_type() const {return vx_core::t_plus_1();}
    vx_core::Type_msgblock Class_plus_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_plus_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_plus_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_number num1 = vx_core::vx_any_from_any(vx_core::t_number(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_number num2 = vx_core::vx_any_from_any(vx_core::t_number(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_plus_1(num1, num2);
      return output;
    }

  //}

  // (func +)
  vx_core::Type_int f_plus_2(vx_core::Type_intlist nums) {
    vx_core::Type_int output = vx_core::e_int();
    output = vx_core::f_any_from_list_reduce(
      vx_core::t_int(),
      nums,
      vx_core::vx_new_int(0),
      vx_core::t_any_from_reduce()->vx_fn_new([](vx_core::Type_any total_any, vx_core::Type_any num_any) {
        vx_core::Type_int total = vx_core::vx_any_from_any(vx_core::t_int(), total_any);
        vx_core::Type_int num = vx_core::vx_any_from_any(vx_core::t_int(), num_any);
        return 
          vx_core::f_plus(total, num);
      })
    );
    return output;
  }

  // (func +)
  // class Class_plus_2 {
    Abstract_plus_2::~Abstract_plus_2() {}

    Class_plus_2::Class_plus_2() : Abstract_plus_2::Abstract_plus_2() {
      vx_core::refcount += 1;
    }
    Class_plus_2::~Class_plus_2() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_plus_2::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_plus_2 output = vx_core::e_plus_2();
      return output;
    }

    vx_core::Type_any Class_plus_2::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_plus_2 output = vx_core::e_plus_2();
      return output;
    }

    vx_core::Type_typedef Class_plus_2::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "int", // name
        "", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_plus_2::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "+", // name
        2, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_plus_2::vx_empty() const {return vx_core::e_plus_2();}
    vx_core::Type_any Class_plus_2::vx_type() const {return vx_core::t_plus_2();}
    vx_core::Type_msgblock Class_plus_2::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_plus_2::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_plus_2::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_plus_2::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_intlist inputval = vx_core::vx_any_from_any(vx_core::t_intlist(), val);
      output = vx_core::f_plus_2(inputval);
      return output;
    }

    vx_core::Type_any Class_plus_2::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_intlist nums = vx_core::vx_any_from_any(vx_core::t_intlist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_plus_2(nums);
      return output;
    }

  //}

  // (func +)
  vx_core::Type_number f_plus_3(vx_core::Type_numberlist nums) {
    vx_core::Type_number output = vx_core::e_number();
    output = vx_core::f_any_from_list_reduce(
      vx_core::t_number(),
      nums,
      (vx_core::Type_number)vx_core::vx_new_int(0),
      vx_core::t_any_from_reduce()->vx_fn_new([](vx_core::Type_any total_any, vx_core::Type_any num_any) {
        vx_core::Type_number total = vx_core::vx_any_from_any(vx_core::t_number(), total_any);
        vx_core::Type_number num = vx_core::vx_any_from_any(vx_core::t_number(), num_any);
        return 
          vx_core::f_plus_1(total, num);
      })
    );
    return output;
  }

  // (func +)
  // class Class_plus_3 {
    Abstract_plus_3::~Abstract_plus_3() {}

    Class_plus_3::Class_plus_3() : Abstract_plus_3::Abstract_plus_3() {
      vx_core::refcount += 1;
    }
    Class_plus_3::~Class_plus_3() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_plus_3::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_plus_3 output = vx_core::e_plus_3();
      return output;
    }

    vx_core::Type_any Class_plus_3::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_plus_3 output = vx_core::e_plus_3();
      return output;
    }

    vx_core::Type_typedef Class_plus_3::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "number", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_int(), vx_core::t_float(), vx_core::t_decimal()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_plus_3::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "+", // name
        3, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_plus_3::vx_empty() const {return vx_core::e_plus_3();}
    vx_core::Type_any Class_plus_3::vx_type() const {return vx_core::t_plus_3();}
    vx_core::Type_msgblock Class_plus_3::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_plus_3::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_plus_3::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_plus_3::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_numberlist inputval = vx_core::vx_any_from_any(vx_core::t_numberlist(), val);
      output = vx_core::f_plus_3(inputval);
      return output;
    }

    vx_core::Type_any Class_plus_3::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_numberlist nums = vx_core::vx_any_from_any(vx_core::t_numberlist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_plus_3(nums);
      return output;
    }

  //}

  // (func +1)
  vx_core::Type_int f_plus1(vx_core::Type_int num) {
    vx_core::Type_int output = vx_core::e_int();
    long result = num->vx_int() + 1;
    output = vx_core::vx_new_int(result);
    return output;
  }

  // (func +1)
  // class Class_plus1 {
    Abstract_plus1::~Abstract_plus1() {}

    Class_plus1::Class_plus1() : Abstract_plus1::Abstract_plus1() {
      vx_core::refcount += 1;
    }
    Class_plus1::~Class_plus1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_plus1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_plus1 output = vx_core::e_plus1();
      return output;
    }

    vx_core::Type_any Class_plus1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_plus1 output = vx_core::e_plus1();
      return output;
    }

    vx_core::Type_typedef Class_plus1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "int", // name
        "", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_plus1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "+1", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_plus1::vx_empty() const {return vx_core::e_plus1();}
    vx_core::Type_any Class_plus1::vx_type() const {return vx_core::t_plus1();}
    vx_core::Type_msgblock Class_plus1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_plus1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_plus1::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_plus1::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_int inputval = vx_core::vx_any_from_any(vx_core::t_int(), val);
      output = vx_core::f_plus1(inputval);
      return output;
    }

    vx_core::Type_any Class_plus1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_int num = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_plus1(num);
      return output;
    }

  //}

  // (func -)
  vx_core::Type_int f_minus(vx_core::Type_int num1, vx_core::Type_int num2) {
    vx_core::Type_int output = vx_core::e_int();
    long result = num1->vx_int() - num2->vx_int();
    output = vx_core::vx_new_int(result);
    return output;
  }

  // (func -)
  // class Class_minus {
    Abstract_minus::~Abstract_minus() {}

    Class_minus::Class_minus() : Abstract_minus::Abstract_minus() {
      vx_core::refcount += 1;
    }
    Class_minus::~Class_minus() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_minus::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_minus output = vx_core::e_minus();
      return output;
    }

    vx_core::Type_any Class_minus::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_minus output = vx_core::e_minus();
      return output;
    }

    vx_core::Type_typedef Class_minus::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "int", // name
        "", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_minus::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "-", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_minus::vx_empty() const {return vx_core::e_minus();}
    vx_core::Type_any Class_minus::vx_type() const {return vx_core::t_minus();}
    vx_core::Type_msgblock Class_minus::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_minus::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_minus::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_int num1 = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int num2 = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_minus(num1, num2);
      return output;
    }

  //}

  // (func -)
  vx_core::Type_number f_minus_1(vx_core::Type_number num1, vx_core::Type_number num2) {
    vx_core::Type_number output = vx_core::e_number();
    return output;
  }

  // (func -)
  // class Class_minus_1 {
    Abstract_minus_1::~Abstract_minus_1() {}

    Class_minus_1::Class_minus_1() : Abstract_minus_1::Abstract_minus_1() {
      vx_core::refcount += 1;
    }
    Class_minus_1::~Class_minus_1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_minus_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_minus_1 output = vx_core::e_minus_1();
      return output;
    }

    vx_core::Type_any Class_minus_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_minus_1 output = vx_core::e_minus_1();
      return output;
    }

    vx_core::Type_typedef Class_minus_1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "number", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_int(), vx_core::t_float(), vx_core::t_decimal()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_minus_1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "-", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_minus_1::vx_empty() const {return vx_core::e_minus_1();}
    vx_core::Type_any Class_minus_1::vx_type() const {return vx_core::t_minus_1();}
    vx_core::Type_msgblock Class_minus_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_minus_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_minus_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_number num1 = vx_core::vx_any_from_any(vx_core::t_number(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_number num2 = vx_core::vx_any_from_any(vx_core::t_number(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_minus_1(num1, num2);
      return output;
    }

  //}

  // (func -)
  vx_core::Type_int f_minus_2(vx_core::Type_intlist nums) {
    vx_core::Type_int output = vx_core::e_int();
    output = vx_core::f_any_from_list_reduce(
      vx_core::t_int(),
      nums,
      vx_core::vx_new_int(0),
      vx_core::t_any_from_reduce()->vx_fn_new([](vx_core::Type_any total_any, vx_core::Type_any num_any) {
        vx_core::Type_int total = vx_core::vx_any_from_any(vx_core::t_int(), total_any);
        vx_core::Type_int num = vx_core::vx_any_from_any(vx_core::t_int(), num_any);
        return 
          vx_core::f_minus(total, num);
      })
    );
    return output;
  }

  // (func -)
  // class Class_minus_2 {
    Abstract_minus_2::~Abstract_minus_2() {}

    Class_minus_2::Class_minus_2() : Abstract_minus_2::Abstract_minus_2() {
      vx_core::refcount += 1;
    }
    Class_minus_2::~Class_minus_2() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_minus_2::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_minus_2 output = vx_core::e_minus_2();
      return output;
    }

    vx_core::Type_any Class_minus_2::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_minus_2 output = vx_core::e_minus_2();
      return output;
    }

    vx_core::Type_typedef Class_minus_2::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "int", // name
        "", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_minus_2::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "-", // name
        2, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_minus_2::vx_empty() const {return vx_core::e_minus_2();}
    vx_core::Type_any Class_minus_2::vx_type() const {return vx_core::t_minus_2();}
    vx_core::Type_msgblock Class_minus_2::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_minus_2::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_minus_2::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_minus_2::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_intlist inputval = vx_core::vx_any_from_any(vx_core::t_intlist(), val);
      output = vx_core::f_minus_2(inputval);
      return output;
    }

    vx_core::Type_any Class_minus_2::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_intlist nums = vx_core::vx_any_from_any(vx_core::t_intlist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_minus_2(nums);
      return output;
    }

  //}

  // (func -)
  vx_core::Type_number f_minus_3(vx_core::Type_numberlist nums) {
    vx_core::Type_number output = vx_core::e_number();
    output = vx_core::f_any_from_list_reduce(
      vx_core::t_number(),
      nums,
      (vx_core::Type_number)vx_core::vx_new_int(0),
      vx_core::t_any_from_reduce()->vx_fn_new([](vx_core::Type_any total_any, vx_core::Type_any num_any) {
        vx_core::Type_number total = vx_core::vx_any_from_any(vx_core::t_number(), total_any);
        vx_core::Type_number num = vx_core::vx_any_from_any(vx_core::t_number(), num_any);
        return 
          vx_core::f_minus_1(total, num);
      })
    );
    return output;
  }

  // (func -)
  // class Class_minus_3 {
    Abstract_minus_3::~Abstract_minus_3() {}

    Class_minus_3::Class_minus_3() : Abstract_minus_3::Abstract_minus_3() {
      vx_core::refcount += 1;
    }
    Class_minus_3::~Class_minus_3() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_minus_3::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_minus_3 output = vx_core::e_minus_3();
      return output;
    }

    vx_core::Type_any Class_minus_3::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_minus_3 output = vx_core::e_minus_3();
      return output;
    }

    vx_core::Type_typedef Class_minus_3::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "number", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_int(), vx_core::t_float(), vx_core::t_decimal()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_minus_3::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "-", // name
        3, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_minus_3::vx_empty() const {return vx_core::e_minus_3();}
    vx_core::Type_any Class_minus_3::vx_type() const {return vx_core::t_minus_3();}
    vx_core::Type_msgblock Class_minus_3::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_minus_3::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_minus_3::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_minus_3::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_numberlist inputval = vx_core::vx_any_from_any(vx_core::t_numberlist(), val);
      output = vx_core::f_minus_3(inputval);
      return output;
    }

    vx_core::Type_any Class_minus_3::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_numberlist nums = vx_core::vx_any_from_any(vx_core::t_numberlist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_minus_3(nums);
      return output;
    }

  //}

  // (func .)
  vx_core::Type_any f_dotmethod(vx_core::Type_any object, vx_core::Type_string method, vx_core::Type_anylist params) {
    vx_core::Type_any output = vx_core::e_any();
    return output;
  }

  // (func .)
  // class Class_dotmethod {
    Abstract_dotmethod::~Abstract_dotmethod() {}

    Class_dotmethod::Class_dotmethod() : Abstract_dotmethod::Abstract_dotmethod() {
      vx_core::refcount += 1;
    }
    Class_dotmethod::~Class_dotmethod() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_dotmethod::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_dotmethod output = vx_core::e_dotmethod();
      return output;
    }

    vx_core::Type_any Class_dotmethod::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_dotmethod output = vx_core::e_dotmethod();
      return output;
    }

    vx_core::Type_typedef Class_dotmethod::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_dotmethod::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        ".", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_dotmethod::vx_empty() const {return vx_core::e_dotmethod();}
    vx_core::Type_any Class_dotmethod::vx_type() const {return vx_core::t_dotmethod();}
    vx_core::Type_msgblock Class_dotmethod::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_dotmethod::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_dotmethod::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any object = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string method = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_anylist params = vx_core::vx_any_from_any(vx_core::t_anylist(), arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_core::f_dotmethod(object, method, params);
      return output;
    }

  //}

  // (func /)
  vx_core::Type_number f_divide(vx_core::Type_number num1, vx_core::Type_number num2) {
    vx_core::Type_number output = vx_core::e_number();
    return output;
  }

  // (func /)
  // class Class_divide {
    Abstract_divide::~Abstract_divide() {}

    Class_divide::Class_divide() : Abstract_divide::Abstract_divide() {
      vx_core::refcount += 1;
    }
    Class_divide::~Class_divide() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_divide::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_divide output = vx_core::e_divide();
      return output;
    }

    vx_core::Type_any Class_divide::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_divide output = vx_core::e_divide();
      return output;
    }

    vx_core::Type_typedef Class_divide::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "number", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_int(), vx_core::t_float(), vx_core::t_decimal()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_divide::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "/", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_divide::vx_empty() const {return vx_core::e_divide();}
    vx_core::Type_any Class_divide::vx_type() const {return vx_core::t_divide();}
    vx_core::Type_msgblock Class_divide::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_divide::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_divide::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_number num1 = vx_core::vx_any_from_any(vx_core::t_number(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_number num2 = vx_core::vx_any_from_any(vx_core::t_number(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_divide(num1, num2);
      return output;
    }

  //}

  // (func <)
  vx_core::Type_boolean f_lt(vx_core::Type_any val1, vx_core::Type_any val2) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    output = vx_core::f_switch(
      vx_core::t_boolean(),
      vx_core::f_compare(val1, val2),
      vx_core::vx_new(vx_core::t_thenelselist(), {
        vx_core::f_case_1(
          vx_core::vx_new_int(-1),
          vx_core::t_any_from_func()->vx_fn_new([]() {
            return vx_core::vx_new_boolean(true);
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func()->vx_fn_new([]() {
            return vx_core::vx_new_boolean(false);
          })
        )
      })
    );
    return output;
  }

  // (func <)
  // class Class_lt {
    Abstract_lt::~Abstract_lt() {}

    Class_lt::Class_lt() : Abstract_lt::Abstract_lt() {
      vx_core::refcount += 1;
    }
    Class_lt::~Class_lt() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_lt::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_lt output = vx_core::e_lt();
      return output;
    }

    vx_core::Type_any Class_lt::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_lt output = vx_core::e_lt();
      return output;
    }

    vx_core::Type_typedef Class_lt::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_lt::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "<", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_lt::vx_empty() const {return vx_core::e_lt();}
    vx_core::Type_any Class_lt::vx_type() const {return vx_core::t_lt();}
    vx_core::Type_msgblock Class_lt::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_lt::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_lt::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any val1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any val2 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_lt(val1, val2);
      return output;
    }

  //}

  // (func <)
  vx_core::Type_boolean f_lt_1(vx_core::Type_anylist values) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    output = vx_core::f_any_from_list_reduce_next(
      vx_core::t_boolean(),
      values,
      vx_core::vx_new_boolean(true),
      vx_core::t_any_from_reduce_next()->vx_fn_new([](vx_core::Type_any reduce_any, vx_core::Type_any current_any, vx_core::Type_any next_any) {
        vx_core::Type_boolean reduce = vx_core::vx_any_from_any(vx_core::t_boolean(), reduce_any);
        vx_core::Type_any current = vx_core::vx_any_from_any(vx_core::t_any(), current_any);
        vx_core::Type_any next = vx_core::vx_any_from_any(vx_core::t_any(), next_any);
        return 
          vx_core::f_and(
            reduce,
            vx_core::f_lt(current, next)
          );
      })
    );
    return output;
  }

  // (func <)
  // class Class_lt_1 {
    Abstract_lt_1::~Abstract_lt_1() {}

    Class_lt_1::Class_lt_1() : Abstract_lt_1::Abstract_lt_1() {
      vx_core::refcount += 1;
    }
    Class_lt_1::~Class_lt_1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_lt_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_lt_1 output = vx_core::e_lt_1();
      return output;
    }

    vx_core::Type_any Class_lt_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_lt_1 output = vx_core::e_lt_1();
      return output;
    }

    vx_core::Type_typedef Class_lt_1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_lt_1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "<", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_lt_1::vx_empty() const {return vx_core::e_lt_1();}
    vx_core::Type_any Class_lt_1::vx_type() const {return vx_core::t_lt_1();}
    vx_core::Type_msgblock Class_lt_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_lt_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_lt_1::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_lt_1::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_anylist inputval = vx_core::vx_any_from_any(vx_core::t_anylist(), val);
      output = vx_core::f_lt_1(inputval);
      return output;
    }

    vx_core::Type_any Class_lt_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_anylist values = vx_core::vx_any_from_any(vx_core::t_anylist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_lt_1(values);
      return output;
    }

  //}

  // (func <-)
  // class Class_chainfirst {
    Abstract_chainfirst::~Abstract_chainfirst() {}

    Class_chainfirst::Class_chainfirst() : Abstract_chainfirst::Abstract_chainfirst() {
      vx_core::refcount += 1;
    }
    Class_chainfirst::~Class_chainfirst() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_chainfirst::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_chainfirst output = vx_core::e_chainfirst();
      return output;
    }

    vx_core::Type_any Class_chainfirst::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_chainfirst output = vx_core::e_chainfirst();
      return output;
    }

    vx_core::Type_typedef Class_chainfirst::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_chainfirst::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "<-", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_chainfirst::vx_empty() const {return vx_core::e_chainfirst();}
    vx_core::Type_any Class_chainfirst::vx_type() const {return vx_core::t_chainfirst();}
    vx_core::Type_msgblock Class_chainfirst::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_chainfirst::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_chainfirst::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any_from_anylist fnlist = vx_core::vx_any_from_any(vx_core::t_any_from_anylist(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_chainfirst(generic_any_1, value, fnlist);
      return output;
    }

  //}

  // (func <<-)
  // class Class_chainlast {
    Abstract_chainlast::~Abstract_chainlast() {}

    Class_chainlast::Class_chainlast() : Abstract_chainlast::Abstract_chainlast() {
      vx_core::refcount += 1;
    }
    Class_chainlast::~Class_chainlast() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_chainlast::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_chainlast output = vx_core::e_chainlast();
      return output;
    }

    vx_core::Type_any Class_chainlast::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_chainlast output = vx_core::e_chainlast();
      return output;
    }

    vx_core::Type_typedef Class_chainlast::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_chainlast::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "<<-", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_chainlast::vx_empty() const {return vx_core::e_chainlast();}
    vx_core::Type_any Class_chainlast::vx_type() const {return vx_core::t_chainlast();}
    vx_core::Type_msgblock Class_chainlast::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_chainlast::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_chainlast::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any_from_anylist fnlist = vx_core::vx_any_from_any(vx_core::t_any_from_anylist(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_chainlast(generic_any_1, value, fnlist);
      return output;
    }

  //}

  // (func <=)
  vx_core::Type_boolean f_le(vx_core::Type_any val1, vx_core::Type_any val2) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    output = vx_core::f_not(
      vx_core::f_gt(val1, val2)
    );
    return output;
  }

  // (func <=)
  // class Class_le {
    Abstract_le::~Abstract_le() {}

    Class_le::Class_le() : Abstract_le::Abstract_le() {
      vx_core::refcount += 1;
    }
    Class_le::~Class_le() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_le::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_le output = vx_core::e_le();
      return output;
    }

    vx_core::Type_any Class_le::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_le output = vx_core::e_le();
      return output;
    }

    vx_core::Type_typedef Class_le::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_le::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "<=", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_le::vx_empty() const {return vx_core::e_le();}
    vx_core::Type_any Class_le::vx_type() const {return vx_core::t_le();}
    vx_core::Type_msgblock Class_le::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_le::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_le::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any val1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any val2 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_le(val1, val2);
      return output;
    }

  //}

  // (func <=)
  vx_core::Type_boolean f_le_1(vx_core::Type_anylist args) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    output = vx_core::f_not(
      vx_core::f_gt_1(args)
    );
    return output;
  }

  // (func <=)
  // class Class_le_1 {
    Abstract_le_1::~Abstract_le_1() {}

    Class_le_1::Class_le_1() : Abstract_le_1::Abstract_le_1() {
      vx_core::refcount += 1;
    }
    Class_le_1::~Class_le_1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_le_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_le_1 output = vx_core::e_le_1();
      return output;
    }

    vx_core::Type_any Class_le_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_le_1 output = vx_core::e_le_1();
      return output;
    }

    vx_core::Type_typedef Class_le_1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_le_1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "<=", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_le_1::vx_empty() const {return vx_core::e_le_1();}
    vx_core::Type_any Class_le_1::vx_type() const {return vx_core::t_le_1();}
    vx_core::Type_msgblock Class_le_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_le_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_le_1::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_le_1::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_anylist inputval = vx_core::vx_any_from_any(vx_core::t_anylist(), val);
      output = vx_core::f_le_1(inputval);
      return output;
    }

    vx_core::Type_any Class_le_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_anylist args = vx_core::vx_any_from_any(vx_core::t_anylist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_le_1(args);
      return output;
    }

  //}

  // (func >)
  vx_core::Type_boolean f_gt(vx_core::Type_any val1, vx_core::Type_any val2) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    output = vx_core::f_switch(
      vx_core::t_boolean(),
      vx_core::f_compare(val1, val2),
      vx_core::vx_new(vx_core::t_thenelselist(), {
        vx_core::f_case_1(
          vx_core::vx_new_int(1),
          vx_core::t_any_from_func()->vx_fn_new([]() {
            return vx_core::vx_new_boolean(true);
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func()->vx_fn_new([]() {
            return vx_core::vx_new_boolean(false);
          })
        )
      })
    );
    return output;
  }

  // (func >)
  // class Class_gt {
    Abstract_gt::~Abstract_gt() {}

    Class_gt::Class_gt() : Abstract_gt::Abstract_gt() {
      vx_core::refcount += 1;
    }
    Class_gt::~Class_gt() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_gt::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_gt output = vx_core::e_gt();
      return output;
    }

    vx_core::Type_any Class_gt::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_gt output = vx_core::e_gt();
      return output;
    }

    vx_core::Type_typedef Class_gt::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_gt::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        ">", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_gt::vx_empty() const {return vx_core::e_gt();}
    vx_core::Type_any Class_gt::vx_type() const {return vx_core::t_gt();}
    vx_core::Type_msgblock Class_gt::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_gt::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_gt::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any val1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any val2 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_gt(val1, val2);
      return output;
    }

  //}

  // (func >)
  vx_core::Type_boolean f_gt_1(vx_core::Type_anylist values) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    output = vx_core::f_any_from_list_reduce_next(
      vx_core::t_boolean(),
      values,
      vx_core::vx_new_boolean(true),
      vx_core::t_any_from_reduce_next()->vx_fn_new([](vx_core::Type_any reduce_any, vx_core::Type_any current_any, vx_core::Type_any next_any) {
        vx_core::Type_boolean reduce = vx_core::vx_any_from_any(vx_core::t_boolean(), reduce_any);
        vx_core::Type_any current = vx_core::vx_any_from_any(vx_core::t_any(), current_any);
        vx_core::Type_any next = vx_core::vx_any_from_any(vx_core::t_any(), next_any);
        return 
          vx_core::f_and(
            reduce,
            vx_core::f_gt(current, next)
          );
      })
    );
    return output;
  }

  // (func >)
  // class Class_gt_1 {
    Abstract_gt_1::~Abstract_gt_1() {}

    Class_gt_1::Class_gt_1() : Abstract_gt_1::Abstract_gt_1() {
      vx_core::refcount += 1;
    }
    Class_gt_1::~Class_gt_1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_gt_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_gt_1 output = vx_core::e_gt_1();
      return output;
    }

    vx_core::Type_any Class_gt_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_gt_1 output = vx_core::e_gt_1();
      return output;
    }

    vx_core::Type_typedef Class_gt_1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_gt_1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        ">", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_gt_1::vx_empty() const {return vx_core::e_gt_1();}
    vx_core::Type_any Class_gt_1::vx_type() const {return vx_core::t_gt_1();}
    vx_core::Type_msgblock Class_gt_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_gt_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_gt_1::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_gt_1::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_anylist inputval = vx_core::vx_any_from_any(vx_core::t_anylist(), val);
      output = vx_core::f_gt_1(inputval);
      return output;
    }

    vx_core::Type_any Class_gt_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_anylist values = vx_core::vx_any_from_any(vx_core::t_anylist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_gt_1(values);
      return output;
    }

  //}

  // (func >=)
  vx_core::Type_boolean f_ge(vx_core::Type_any val1, vx_core::Type_any val2) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    output = vx_core::f_not(
      vx_core::f_lt(val1, val2)
    );
    return output;
  }

  // (func >=)
  // class Class_ge {
    Abstract_ge::~Abstract_ge() {}

    Class_ge::Class_ge() : Abstract_ge::Abstract_ge() {
      vx_core::refcount += 1;
    }
    Class_ge::~Class_ge() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_ge::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_ge output = vx_core::e_ge();
      return output;
    }

    vx_core::Type_any Class_ge::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_ge output = vx_core::e_ge();
      return output;
    }

    vx_core::Type_typedef Class_ge::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_ge::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        ">=", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_ge::vx_empty() const {return vx_core::e_ge();}
    vx_core::Type_any Class_ge::vx_type() const {return vx_core::t_ge();}
    vx_core::Type_msgblock Class_ge::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ge::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_ge::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any val1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any val2 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_ge(val1, val2);
      return output;
    }

  //}

  // (func >=)
  vx_core::Type_boolean f_ge_1(vx_core::Type_anylist args) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    output = vx_core::f_not(
      vx_core::f_lt_1(args)
    );
    return output;
  }

  // (func >=)
  // class Class_ge_1 {
    Abstract_ge_1::~Abstract_ge_1() {}

    Class_ge_1::Class_ge_1() : Abstract_ge_1::Abstract_ge_1() {
      vx_core::refcount += 1;
    }
    Class_ge_1::~Class_ge_1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_ge_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_ge_1 output = vx_core::e_ge_1();
      return output;
    }

    vx_core::Type_any Class_ge_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_ge_1 output = vx_core::e_ge_1();
      return output;
    }

    vx_core::Type_typedef Class_ge_1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_ge_1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        ">=", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_ge_1::vx_empty() const {return vx_core::e_ge_1();}
    vx_core::Type_any Class_ge_1::vx_type() const {return vx_core::t_ge_1();}
    vx_core::Type_msgblock Class_ge_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_ge_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_ge_1::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_ge_1::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_anylist inputval = vx_core::vx_any_from_any(vx_core::t_anylist(), val);
      output = vx_core::f_ge_1(inputval);
      return output;
    }

    vx_core::Type_any Class_ge_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_anylist args = vx_core::vx_any_from_any(vx_core::t_anylist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_ge_1(args);
      return output;
    }

  //}

  // (func allowtypenames<-typedef)
  vx_core::Type_stringlist f_allowtypenames_from_typedef(vx_core::Type_typedef vtypedef) {
    vx_core::Type_stringlist output = vx_core::e_stringlist();
    output = vx_core::f_typenames_from_typelist(
      vx_core::f_allowtypes_from_typedef(vtypedef)
    );
    return output;
  }

  // (func allowtypenames<-typedef)
  // class Class_allowtypenames_from_typedef {
    Abstract_allowtypenames_from_typedef::~Abstract_allowtypenames_from_typedef() {}

    Class_allowtypenames_from_typedef::Class_allowtypenames_from_typedef() : Abstract_allowtypenames_from_typedef::Abstract_allowtypenames_from_typedef() {
      vx_core::refcount += 1;
    }
    Class_allowtypenames_from_typedef::~Class_allowtypenames_from_typedef() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_allowtypenames_from_typedef::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_allowtypenames_from_typedef output = vx_core::e_allowtypenames_from_typedef();
      return output;
    }

    vx_core::Type_any Class_allowtypenames_from_typedef::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_allowtypenames_from_typedef output = vx_core::e_allowtypenames_from_typedef();
      return output;
    }

    vx_core::Type_typedef Class_allowtypenames_from_typedef::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "stringlist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_string()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_allowtypenames_from_typedef::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "allowtypenames<-typedef", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_allowtypenames_from_typedef::vx_empty() const {return vx_core::e_allowtypenames_from_typedef();}
    vx_core::Type_any Class_allowtypenames_from_typedef::vx_type() const {return vx_core::t_allowtypenames_from_typedef();}
    vx_core::Type_msgblock Class_allowtypenames_from_typedef::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_allowtypenames_from_typedef::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_allowtypenames_from_typedef::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_allowtypenames_from_typedef::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_typedef inputval = vx_core::vx_any_from_any(vx_core::t_typedef(), val);
      output = vx_core::f_allowtypenames_from_typedef(inputval);
      return output;
    }

    vx_core::Type_any Class_allowtypenames_from_typedef::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_typedef vtypedef = vx_core::vx_any_from_any(vx_core::t_typedef(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_allowtypenames_from_typedef(vtypedef);
      return output;
    }

  //}

  // (func allowtypes<-typedef)
  vx_core::Type_typelist f_allowtypes_from_typedef(vx_core::Type_typedef vtypedef) {
    vx_core::Type_typelist output = vx_core::e_typelist();
    return output;
  }

  // (func allowtypes<-typedef)
  // class Class_allowtypes_from_typedef {
    Abstract_allowtypes_from_typedef::~Abstract_allowtypes_from_typedef() {}

    Class_allowtypes_from_typedef::Class_allowtypes_from_typedef() : Abstract_allowtypes_from_typedef::Abstract_allowtypes_from_typedef() {
      vx_core::refcount += 1;
    }
    Class_allowtypes_from_typedef::~Class_allowtypes_from_typedef() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_allowtypes_from_typedef::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_allowtypes_from_typedef output = vx_core::e_allowtypes_from_typedef();
      return output;
    }

    vx_core::Type_any Class_allowtypes_from_typedef::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_allowtypes_from_typedef output = vx_core::e_allowtypes_from_typedef();
      return output;
    }

    vx_core::Type_typedef Class_allowtypes_from_typedef::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "typelist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_any()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_allowtypes_from_typedef::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "allowtypes<-typedef", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_allowtypes_from_typedef::vx_empty() const {return vx_core::e_allowtypes_from_typedef();}
    vx_core::Type_any Class_allowtypes_from_typedef::vx_type() const {return vx_core::t_allowtypes_from_typedef();}
    vx_core::Type_msgblock Class_allowtypes_from_typedef::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_allowtypes_from_typedef::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_allowtypes_from_typedef::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_allowtypes_from_typedef::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_typedef inputval = vx_core::vx_any_from_any(vx_core::t_typedef(), val);
      output = vx_core::f_allowtypes_from_typedef(inputval);
      return output;
    }

    vx_core::Type_any Class_allowtypes_from_typedef::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_typedef vtypedef = vx_core::vx_any_from_any(vx_core::t_typedef(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_allowtypes_from_typedef(vtypedef);
      return output;
    }

  //}

  // (func compare)
  vx_core::Type_int f_compare(vx_core::Type_any val1, vx_core::Type_any val2) {
    vx_core::Type_int output = vx_core::e_int();
    return output;
  }

  // (func compare)
  // class Class_compare {
    Abstract_compare::~Abstract_compare() {}

    Class_compare::Class_compare() : Abstract_compare::Abstract_compare() {
      vx_core::refcount += 1;
    }
    Class_compare::~Class_compare() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_compare::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_compare output = vx_core::e_compare();
      return output;
    }

    vx_core::Type_any Class_compare::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_compare output = vx_core::e_compare();
      return output;
    }

    vx_core::Type_typedef Class_compare::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "int", // name
        "", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_compare::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "compare", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_compare::vx_empty() const {return vx_core::e_compare();}
    vx_core::Type_any Class_compare::vx_type() const {return vx_core::t_compare();}
    vx_core::Type_msgblock Class_compare::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_compare::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_compare::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any val1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any val2 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_compare(val1, val2);
      return output;
    }

  //}

  // (func contains)
  vx_core::Type_boolean f_contains(vx_core::Type_string text, vx_core::Type_string find) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    return output;
  }

  // (func contains)
  // class Class_contains {
    Abstract_contains::~Abstract_contains() {}

    Class_contains::Class_contains() : Abstract_contains::Abstract_contains() {
      vx_core::refcount += 1;
    }
    Class_contains::~Class_contains() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_contains::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_contains output = vx_core::e_contains();
      return output;
    }

    vx_core::Type_any Class_contains::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_contains output = vx_core::e_contains();
      return output;
    }

    vx_core::Type_typedef Class_contains::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_contains::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "contains", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_contains::vx_empty() const {return vx_core::e_contains();}
    vx_core::Type_any Class_contains::vx_type() const {return vx_core::t_contains();}
    vx_core::Type_msgblock Class_contains::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_contains::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_contains::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string find = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_contains(text, find);
      return output;
    }

  //}

  // (func contains)
  vx_core::Type_boolean f_contains_1(vx_core::Type_list values, vx_core::Type_any find) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    return output;
  }

  // (func contains)
  // class Class_contains_1 {
    Abstract_contains_1::~Abstract_contains_1() {}

    Class_contains_1::Class_contains_1() : Abstract_contains_1::Abstract_contains_1() {
      vx_core::refcount += 1;
    }
    Class_contains_1::~Class_contains_1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_contains_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_contains_1 output = vx_core::e_contains_1();
      return output;
    }

    vx_core::Type_any Class_contains_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_contains_1 output = vx_core::e_contains_1();
      return output;
    }

    vx_core::Type_typedef Class_contains_1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_contains_1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "contains", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_contains_1::vx_empty() const {return vx_core::e_contains_1();}
    vx_core::Type_any Class_contains_1::vx_type() const {return vx_core::t_contains_1();}
    vx_core::Type_msgblock Class_contains_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_contains_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_contains_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_list values = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any find = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_contains_1(values, find);
      return output;
    }

  //}

  // (func extends<-any)
  vx_core::Type_string f_extends_from_any(vx_core::Type_any val) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_extends_from_typedef(
      vx_core::f_typedef_from_any(val)
    );
    return output;
  }

  // (func extends<-any)
  // class Class_extends_from_any {
    Abstract_extends_from_any::~Abstract_extends_from_any() {}

    Class_extends_from_any::Class_extends_from_any() : Abstract_extends_from_any::Abstract_extends_from_any() {
      vx_core::refcount += 1;
    }
    Class_extends_from_any::~Class_extends_from_any() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_extends_from_any::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_extends_from_any output = vx_core::e_extends_from_any();
      return output;
    }

    vx_core::Type_any Class_extends_from_any::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_extends_from_any output = vx_core::e_extends_from_any();
      return output;
    }

    vx_core::Type_typedef Class_extends_from_any::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "string", // name
        "string", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_extends_from_any::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "extends<-any", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_extends_from_any::vx_empty() const {return vx_core::e_extends_from_any();}
    vx_core::Type_any Class_extends_from_any::vx_type() const {return vx_core::t_extends_from_any();}
    vx_core::Type_msgblock Class_extends_from_any::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_extends_from_any::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_extends_from_any::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_extends_from_any::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any(), val);
      output = vx_core::f_extends_from_any(inputval);
      return output;
    }

    vx_core::Type_any Class_extends_from_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any val = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_extends_from_any(val);
      return output;
    }

  //}

  // (func extends<-typedef)
  vx_core::Type_string f_extends_from_typedef(vx_core::Type_typedef vtypedef) {
    vx_core::Type_string output = vx_core::e_string();
    output = vtypedef->extend();
    return output;
  }

  // (func extends<-typedef)
  // class Class_extends_from_typedef {
    Abstract_extends_from_typedef::~Abstract_extends_from_typedef() {}

    Class_extends_from_typedef::Class_extends_from_typedef() : Abstract_extends_from_typedef::Abstract_extends_from_typedef() {
      vx_core::refcount += 1;
    }
    Class_extends_from_typedef::~Class_extends_from_typedef() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_extends_from_typedef::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_extends_from_typedef output = vx_core::e_extends_from_typedef();
      return output;
    }

    vx_core::Type_any Class_extends_from_typedef::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_extends_from_typedef output = vx_core::e_extends_from_typedef();
      return output;
    }

    vx_core::Type_typedef Class_extends_from_typedef::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "string", // name
        "string", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_extends_from_typedef::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "extends<-typedef", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_extends_from_typedef::vx_empty() const {return vx_core::e_extends_from_typedef();}
    vx_core::Type_any Class_extends_from_typedef::vx_type() const {return vx_core::t_extends_from_typedef();}
    vx_core::Type_msgblock Class_extends_from_typedef::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_extends_from_typedef::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_extends_from_typedef::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_extends_from_typedef::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_typedef inputval = vx_core::vx_any_from_any(vx_core::t_typedef(), val);
      output = vx_core::f_extends_from_typedef(inputval);
      return output;
    }

    vx_core::Type_any Class_extends_from_typedef::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_typedef vtypedef = vx_core::vx_any_from_any(vx_core::t_typedef(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_extends_from_typedef(vtypedef);
      return output;
    }

  //}

  // (func first<-list)
  // class Class_first_from_list {
    Abstract_first_from_list::~Abstract_first_from_list() {}

    Class_first_from_list::Class_first_from_list() : Abstract_first_from_list::Abstract_first_from_list() {
      vx_core::refcount += 1;
    }
    Class_first_from_list::~Class_first_from_list() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_first_from_list::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_first_from_list output = vx_core::e_first_from_list();
      return output;
    }

    vx_core::Type_any Class_first_from_list::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_first_from_list output = vx_core::e_first_from_list();
      return output;
    }

    vx_core::Type_typedef Class_first_from_list::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_first_from_list::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "first<-list", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_first_from_list::vx_empty() const {return vx_core::e_first_from_list();}
    vx_core::Type_any Class_first_from_list::vx_type() const {return vx_core::t_first_from_list();}
    vx_core::Type_msgblock Class_first_from_list::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_first_from_list::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_first_from_list::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_first_from_list::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_list inputval = vx_core::vx_any_from_any(vx_core::t_list(), val);
      output = vx_core::f_first_from_list(vx_core::t_any(), inputval);
      return output;
    }

    vx_core::Type_any Class_first_from_list::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list values = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_first_from_list(generic_any_1, values);
      return output;
    }

  //}

  // (func first<-list-fn-any<-any)
  // class Class_first_from_list_fn_any_from_any {
    Abstract_first_from_list_fn_any_from_any::~Abstract_first_from_list_fn_any_from_any() {}

    Class_first_from_list_fn_any_from_any::Class_first_from_list_fn_any_from_any() : Abstract_first_from_list_fn_any_from_any::Abstract_first_from_list_fn_any_from_any() {
      vx_core::refcount += 1;
    }
    Class_first_from_list_fn_any_from_any::~Class_first_from_list_fn_any_from_any() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_first_from_list_fn_any_from_any::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_first_from_list_fn_any_from_any output = vx_core::e_first_from_list_fn_any_from_any();
      return output;
    }

    vx_core::Type_any Class_first_from_list_fn_any_from_any::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_first_from_list_fn_any_from_any output = vx_core::e_first_from_list_fn_any_from_any();
      return output;
    }

    vx_core::Type_typedef Class_first_from_list_fn_any_from_any::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_first_from_list_fn_any_from_any::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "first<-list-fn-any<-any", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_first_from_list_fn_any_from_any::vx_empty() const {return vx_core::e_first_from_list_fn_any_from_any();}
    vx_core::Type_any Class_first_from_list_fn_any_from_any::vx_type() const {return vx_core::t_first_from_list_fn_any_from_any();}
    vx_core::Type_msgblock Class_first_from_list_fn_any_from_any::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_first_from_list_fn_any_from_any::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_first_from_list_fn_any_from_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list values = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_any fn_any_from_any = vx_core::vx_any_from_any(vx_core::t_any_from_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_first_from_list_fn_any_from_any(generic_any_1, values, fn_any_from_any);
      return output;
    }

  //}

  // (func fn)
  // class Class_fn {
    Abstract_fn::~Abstract_fn() {}

    Class_fn::Class_fn() : Abstract_fn::Abstract_fn() {
      vx_core::refcount += 1;
    }
    Class_fn::~Class_fn() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_fn::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_fn output = vx_core::e_fn();
      return output;
    }

    vx_core::Type_any Class_fn::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_fn output = vx_core::e_fn();
      return output;
    }

    vx_core::Type_typedef Class_fn::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_fn::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "fn", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_fn::vx_empty() const {return vx_core::e_fn();}
    vx_core::Type_any Class_fn::vx_type() const {return vx_core::t_fn();}
    vx_core::Type_msgblock Class_fn::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_fn::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_fn::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_arglist params = vx_core::vx_any_from_any(vx_core::t_arglist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_func fn_any = vx_core::vx_any_from_any(vx_core::t_any_from_func(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_fn(generic_any_1, params, fn_any);
      return output;
    }

  //}

  // (func funcdef<-func)
  vx_core::Type_funcdef f_funcdef_from_func(vx_core::Type_func val) {
    vx_core::Type_funcdef output = vx_core::e_funcdef();
    return output;
  }

  // (func funcdef<-func)
  // class Class_funcdef_from_func {
    Abstract_funcdef_from_func::~Abstract_funcdef_from_func() {}

    Class_funcdef_from_func::Class_funcdef_from_func() : Abstract_funcdef_from_func::Abstract_funcdef_from_func() {
      vx_core::refcount += 1;
    }
    Class_funcdef_from_func::~Class_funcdef_from_func() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_funcdef_from_func::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_funcdef_from_func output = vx_core::e_funcdef_from_func();
      return output;
    }

    vx_core::Type_any Class_funcdef_from_func::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_funcdef_from_func output = vx_core::e_funcdef_from_func();
      return output;
    }

    vx_core::Type_typedef Class_funcdef_from_func::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "funcdef", // name
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
    }

    vx_core::Type_funcdef Class_funcdef_from_func::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "funcdef<-func", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_funcdef_from_func::vx_empty() const {return vx_core::e_funcdef_from_func();}
    vx_core::Type_any Class_funcdef_from_func::vx_type() const {return vx_core::t_funcdef_from_func();}
    vx_core::Type_msgblock Class_funcdef_from_func::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_funcdef_from_func::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_funcdef_from_func::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_funcdef_from_func::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_func inputval = vx_core::vx_any_from_any(vx_core::t_func(), val);
      output = vx_core::f_funcdef_from_func(inputval);
      return output;
    }

    vx_core::Type_any Class_funcdef_from_func::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_func val = vx_core::vx_any_from_any(vx_core::t_func(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_funcdef_from_func(val);
      return output;
    }

  //}

  // (func funcname<-funcdef)
  vx_core::Type_string f_funcname_from_funcdef(vx_core::Type_funcdef funcdef) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_new(
      vx_core::t_string(),
      vx_core::vx_new(vx_core::t_anylist(), {
        funcdef->pkgname(),
        vx_core::vx_new_string("/"),
        funcdef->name()
      })
    );
    return output;
  }

  // (func funcname<-funcdef)
  // class Class_funcname_from_funcdef {
    Abstract_funcname_from_funcdef::~Abstract_funcname_from_funcdef() {}

    Class_funcname_from_funcdef::Class_funcname_from_funcdef() : Abstract_funcname_from_funcdef::Abstract_funcname_from_funcdef() {
      vx_core::refcount += 1;
    }
    Class_funcname_from_funcdef::~Class_funcname_from_funcdef() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_funcname_from_funcdef::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_funcname_from_funcdef output = vx_core::e_funcname_from_funcdef();
      return output;
    }

    vx_core::Type_any Class_funcname_from_funcdef::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_funcname_from_funcdef output = vx_core::e_funcname_from_funcdef();
      return output;
    }

    vx_core::Type_typedef Class_funcname_from_funcdef::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "string", // name
        "string", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_funcname_from_funcdef::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "funcname<-funcdef", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_funcname_from_funcdef::vx_empty() const {return vx_core::e_funcname_from_funcdef();}
    vx_core::Type_any Class_funcname_from_funcdef::vx_type() const {return vx_core::t_funcname_from_funcdef();}
    vx_core::Type_msgblock Class_funcname_from_funcdef::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_funcname_from_funcdef::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_funcname_from_funcdef::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_funcname_from_funcdef::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_funcdef inputval = vx_core::vx_any_from_any(vx_core::t_funcdef(), val);
      output = vx_core::f_funcname_from_funcdef(inputval);
      return output;
    }

    vx_core::Type_any Class_funcname_from_funcdef::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_funcdef funcdef = vx_core::vx_any_from_any(vx_core::t_funcdef(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_funcname_from_funcdef(funcdef);
      return output;
    }

  //}

  // (func global-package-get)
  vx_core::Type_package f_global_package_get(vx_core::Type_string pkgname) {
    vx_core::Type_package output = vx_core::e_package();
    return output;
  }

  // (func global-package-get)
  // class Class_global_package_get {
    Abstract_global_package_get::~Abstract_global_package_get() {}

    Class_global_package_get::Class_global_package_get() : Abstract_global_package_get::Abstract_global_package_get() {
      vx_core::refcount += 1;
    }
    Class_global_package_get::~Class_global_package_get() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_global_package_get::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_global_package_get output = vx_core::e_global_package_get();
      return output;
    }

    vx_core::Type_any Class_global_package_get::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_global_package_get output = vx_core::e_global_package_get();
      return output;
    }

    vx_core::Type_typedef Class_global_package_get::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "package", // name
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
    }

    vx_core::Type_funcdef Class_global_package_get::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "global-package-get", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_global_package_get::vx_empty() const {return vx_core::e_global_package_get();}
    vx_core::Type_any Class_global_package_get::vx_type() const {return vx_core::t_global_package_get();}
    vx_core::Type_msgblock Class_global_package_get::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_global_package_get::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_global_package_get::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_global_package_get::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string(), val);
      output = vx_core::f_global_package_get(inputval);
      return output;
    }

    vx_core::Type_any Class_global_package_get::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string pkgname = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_global_package_get(pkgname);
      return output;
    }

  //}

  // (func global-package-set)
  void f_global_package_set(vx_core::Type_string pkgname, vx_core::Type_package pkg) {
  }

  // (func global-package-set)
  // class Class_global_package_set {
    Abstract_global_package_set::~Abstract_global_package_set() {}

    Class_global_package_set::Class_global_package_set() : Abstract_global_package_set::Abstract_global_package_set() {
      vx_core::refcount += 1;
    }
    Class_global_package_set::~Class_global_package_set() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_global_package_set::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_global_package_set output = vx_core::e_global_package_set();
      return output;
    }

    vx_core::Type_any Class_global_package_set::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_global_package_set output = vx_core::e_global_package_set();
      return output;
    }

    vx_core::Type_typedef Class_global_package_set::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "none", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_global_package_set::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "global-package-set", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_global_package_set::vx_empty() const {return vx_core::e_global_package_set();}
    vx_core::Type_any Class_global_package_set::vx_type() const {return vx_core::t_global_package_set();}
    vx_core::Type_msgblock Class_global_package_set::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_global_package_set::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_global_package_set::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string pkgname = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_package pkg = vx_core::vx_any_from_any(vx_core::t_package(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::f_global_package_set(pkgname, pkg);
      return output;
    }

  //}

  // (func int<-func)
  vx_core::Type_int f_int_from_func() {
    vx_core::Type_int output = vx_core::e_int();
    return output;
  }

  // (func int<-func)
  // class Class_int_from_func {
    Abstract_int_from_func::~Abstract_int_from_func() {}

    Class_int_from_func::Class_int_from_func() : Abstract_int_from_func::Abstract_int_from_func() {
      vx_core::refcount += 1;
    }
    Class_int_from_func::~Class_int_from_func() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_int_from_func::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_int_from_func output = vx_core::e_int_from_func();
      return output;
    }

    vx_core::Type_any Class_int_from_func::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_int_from_func output = vx_core::e_int_from_func();
      return output;
    }

    vx_core::Type_typedef Class_int_from_func::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "int", // name
        "", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_int_from_func::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "int<-func", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_int_from_func::vx_empty() const {return vx_core::e_int_from_func();}
    vx_core::Type_any Class_int_from_func::vx_type() const {return vx_core::t_int_from_func();}
    vx_core::Type_msgblock Class_int_from_func::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_int_from_func::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_int_from_func vx_core::Class_int_from_func::vx_fn_new(vx_core::Abstract_any_from_func::IFn fn) const {
      vx_core::Func_int_from_func output = new vx_core::Class_int_from_func();
      output->fn = fn;
      return output;
    }

    vx_core::Type_int Class_int_from_func::vx_int_from_func() const {
      vx_core::Type_int output = vx_core::e_int();
      return output;
    }

    vx_core::Type_any Class_int_from_func::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      output = vx_core::f_int_from_func();
      return output;
    }

  //}

  // (func int<-string)
  vx_core::Type_int f_int_from_string(vx_core::Type_string val) {
    vx_core::Type_int output = vx_core::e_int();
    output = vx_core::f_switch(
      vx_core::t_int(),
      val,
      vx_core::vx_new(vx_core::t_thenelselist(), {
        vx_core::f_case_1(
          vx_core::vx_new_string("notanumber"),
          vx_core::t_any_from_func()->vx_fn_new([]() {
            return vx_core::c_notanumber();
          })
        ),
        vx_core::f_case_1(
          vx_core::vx_new_string("infinity"),
          vx_core::t_any_from_func()->vx_fn_new([]() {
            return vx_core::c_infinity();
          })
        ),
        vx_core::f_case_1(
          vx_core::vx_new_string("neginfinity"),
          vx_core::t_any_from_func()->vx_fn_new([]() {
            return vx_core::c_neginfinity();
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func()->vx_fn_new([val]() {// :capture val
            vx_core::Type_int intresult = vx_core::e_int();
            try {
              std::string sval = val->vx_string();
              long ival = std::stoll(sval);
              intresult = vx_core::vx_new_int(ival);
            } catch (std::exception ex) {
              intresult = vx_core::c_notanumber();
            }
            return intresult;
          })
        )
      })
    );
    return output;
  }

  // (func int<-string)
  // class Class_int_from_string {
    Abstract_int_from_string::~Abstract_int_from_string() {}

    Class_int_from_string::Class_int_from_string() : Abstract_int_from_string::Abstract_int_from_string() {
      vx_core::refcount += 1;
    }
    Class_int_from_string::~Class_int_from_string() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_int_from_string::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_int_from_string output = vx_core::e_int_from_string();
      return output;
    }

    vx_core::Type_any Class_int_from_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_int_from_string output = vx_core::e_int_from_string();
      return output;
    }

    vx_core::Type_typedef Class_int_from_string::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "int", // name
        "", // extends
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_number()}), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_int_from_string::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "int<-string", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_int_from_string::vx_empty() const {return vx_core::e_int_from_string();}
    vx_core::Type_any Class_int_from_string::vx_type() const {return vx_core::t_int_from_string();}
    vx_core::Type_msgblock Class_int_from_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_int_from_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_int_from_string::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_int_from_string::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string(), val);
      output = vx_core::f_int_from_string(inputval);
      return output;
    }

    vx_core::Type_any Class_int_from_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string val = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_int_from_string(val);
      return output;
    }

  //}

  // (func is-endswith)
  vx_core::Type_boolean f_is_endswith(vx_core::Type_string text, vx_core::Type_string find) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    return output;
  }

  // (func is-endswith)
  // class Class_is_endswith {
    Abstract_is_endswith::~Abstract_is_endswith() {}

    Class_is_endswith::Class_is_endswith() : Abstract_is_endswith::Abstract_is_endswith() {
      vx_core::refcount += 1;
    }
    Class_is_endswith::~Class_is_endswith() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_is_endswith::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_is_endswith output = vx_core::e_is_endswith();
      return output;
    }

    vx_core::Type_any Class_is_endswith::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_is_endswith output = vx_core::e_is_endswith();
      return output;
    }

    vx_core::Type_typedef Class_is_endswith::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_is_endswith::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "is-endswith", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_is_endswith::vx_empty() const {return vx_core::e_is_endswith();}
    vx_core::Type_any Class_is_endswith::vx_type() const {return vx_core::t_is_endswith();}
    vx_core::Type_msgblock Class_is_endswith::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_is_endswith::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_is_endswith::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string find = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_is_endswith(text, find);
      return output;
    }

  //}

  // (func is-func)
  vx_core::Type_boolean f_is_func(vx_core::Type_any val) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    return output;
  }

  // (func is-func)
  // class Class_is_func {
    Abstract_is_func::~Abstract_is_func() {}

    Class_is_func::Class_is_func() : Abstract_is_func::Abstract_is_func() {
      vx_core::refcount += 1;
    }
    Class_is_func::~Class_is_func() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_is_func::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_is_func output = vx_core::e_is_func();
      return output;
    }

    vx_core::Type_any Class_is_func::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_is_func output = vx_core::e_is_func();
      return output;
    }

    vx_core::Type_typedef Class_is_func::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_is_func::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "is-func", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_is_func::vx_empty() const {return vx_core::e_is_func();}
    vx_core::Type_any Class_is_func::vx_type() const {return vx_core::t_is_func();}
    vx_core::Type_msgblock Class_is_func::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_is_func::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_is_func::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_is_func::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any(), val);
      output = vx_core::f_is_func(inputval);
      return output;
    }

    vx_core::Type_any Class_is_func::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any val = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_is_func(val);
      return output;
    }

  //}

  // (func is-int)
  vx_core::Type_boolean f_is_int(vx_core::Type_any value) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    return output;
  }

  // (func is-int)
  // class Class_is_int {
    Abstract_is_int::~Abstract_is_int() {}

    Class_is_int::Class_is_int() : Abstract_is_int::Abstract_is_int() {
      vx_core::refcount += 1;
    }
    Class_is_int::~Class_is_int() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_is_int::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_is_int output = vx_core::e_is_int();
      return output;
    }

    vx_core::Type_any Class_is_int::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_is_int output = vx_core::e_is_int();
      return output;
    }

    vx_core::Type_typedef Class_is_int::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_is_int::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "is-int", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_is_int::vx_empty() const {return vx_core::e_is_int();}
    vx_core::Type_any Class_is_int::vx_type() const {return vx_core::t_is_int();}
    vx_core::Type_msgblock Class_is_int::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_is_int::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_is_int::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_is_int::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any(), val);
      output = vx_core::f_is_int(inputval);
      return output;
    }

    vx_core::Type_any Class_is_int::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_is_int(value);
      return output;
    }

  //}

  // (func is-number)
  vx_core::Type_boolean f_is_number(vx_core::Type_any value) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    output = vx_core::f_switch(
      vx_core::t_boolean(),
      vx_core::f_typename_from_any(value),
      vx_core::vx_new(vx_core::t_thenelselist(), {
        vx_core::f_case(
          vx_core::f_new(
            vx_core::t_list(),
            vx_core::vx_new(vx_core::t_anylist(), {
              vx_core::vx_new_string("vx/core/decimal"),
              vx_core::vx_new_string("vx/core/float"),
              vx_core::vx_new_string("vx/core/int"),
              vx_core::vx_new_string("vx/core/number")
            })
          ),
          vx_core::t_any_from_func()->vx_fn_new([]() {
            return vx_core::vx_new_boolean(true);
          })
        ),
        vx_core::f_else(
          vx_core::t_any_from_func()->vx_fn_new([]() {
            return vx_core::vx_new_boolean(false);
          })
        )
      })
    );
    return output;
  }

  // (func is-number)
  // class Class_is_number {
    Abstract_is_number::~Abstract_is_number() {}

    Class_is_number::Class_is_number() : Abstract_is_number::Abstract_is_number() {
      vx_core::refcount += 1;
    }
    Class_is_number::~Class_is_number() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_is_number::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_is_number output = vx_core::e_is_number();
      return output;
    }

    vx_core::Type_any Class_is_number::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_is_number output = vx_core::e_is_number();
      return output;
    }

    vx_core::Type_typedef Class_is_number::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_is_number::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "is-number", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_is_number::vx_empty() const {return vx_core::e_is_number();}
    vx_core::Type_any Class_is_number::vx_type() const {return vx_core::t_is_number();}
    vx_core::Type_msgblock Class_is_number::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_is_number::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_is_number::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_is_number::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any(), val);
      output = vx_core::f_is_number(inputval);
      return output;
    }

    vx_core::Type_any Class_is_number::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_is_number(value);
      return output;
    }

  //}

  // (func is-pass<-permission)
  vx_core::Type_boolean f_is_pass_from_permission(vx_core::Type_permission permission, vx_core::Type_context context) {
    vx_core::Type_boolean output = vx_core::e_boolean();
    output = vx_core::f_let(
      vx_core::t_boolean(),
      vx_core::t_any_from_func()->vx_fn_new([permission, context]() {
        vx_core::Type_string id = permission->id();
        vx_core::Type_permission lookup = vx_core::f_permission_from_id_context(id, context);
        return vx_core::f_eq(lookup, permission);
      })
    );
    return output;
  }

  // (func is-pass<-permission)
  // class Class_is_pass_from_permission {
    Abstract_is_pass_from_permission::~Abstract_is_pass_from_permission() {}

    Class_is_pass_from_permission::Class_is_pass_from_permission() : Abstract_is_pass_from_permission::Abstract_is_pass_from_permission() {
      vx_core::refcount += 1;
    }
    Class_is_pass_from_permission::~Class_is_pass_from_permission() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_is_pass_from_permission::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_is_pass_from_permission output = vx_core::e_is_pass_from_permission();
      return output;
    }

    vx_core::Type_any Class_is_pass_from_permission::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_is_pass_from_permission output = vx_core::e_is_pass_from_permission();
      return output;
    }

    vx_core::Type_typedef Class_is_pass_from_permission::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "boolean", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_is_pass_from_permission::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "is-pass<-permission", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_is_pass_from_permission::vx_empty() const {return vx_core::e_is_pass_from_permission();}
    vx_core::Type_any Class_is_pass_from_permission::vx_type() const {return vx_core::t_is_pass_from_permission();}
    vx_core::Type_msgblock Class_is_pass_from_permission::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_is_pass_from_permission::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_is_pass_from_permission::vx_fn_new(vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context();
    }

    vx_core::Type_any Class_is_pass_from_permission::vx_any_from_any_context(vx_core::Type_any val, vx_core::Type_context context) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_permission inputval = vx_core::vx_any_from_any(vx_core::t_permission(), val);
      output = vx_core::f_is_pass_from_permission(inputval, context);
      return output;
    }

    vx_core::Type_any Class_is_pass_from_permission::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_permission permission = vx_core::vx_any_from_any(vx_core::t_permission(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_is_pass_from_permission(permission, context);
      return output;
    }

  //}

  // (func last<-list)
  // class Class_last_from_list {
    Abstract_last_from_list::~Abstract_last_from_list() {}

    Class_last_from_list::Class_last_from_list() : Abstract_last_from_list::Abstract_last_from_list() {
      vx_core::refcount += 1;
    }
    Class_last_from_list::~Class_last_from_list() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_last_from_list::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_last_from_list output = vx_core::e_last_from_list();
      return output;
    }

    vx_core::Type_any Class_last_from_list::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_last_from_list output = vx_core::e_last_from_list();
      return output;
    }

    vx_core::Type_typedef Class_last_from_list::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_last_from_list::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "last<-list", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_last_from_list::vx_empty() const {return vx_core::e_last_from_list();}
    vx_core::Type_any Class_last_from_list::vx_type() const {return vx_core::t_last_from_list();}
    vx_core::Type_msgblock Class_last_from_list::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_last_from_list::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_last_from_list::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_last_from_list::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_list inputval = vx_core::vx_any_from_any(vx_core::t_list(), val);
      output = vx_core::f_last_from_list(vx_core::t_any(), inputval);
      return output;
    }

    vx_core::Type_any Class_last_from_list::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list values = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_last_from_list(generic_any_1, values);
      return output;
    }

  //}

  // (func list-join<-list)
  // class Class_list_join_from_list {
    Abstract_list_join_from_list::~Abstract_list_join_from_list() {}

    Class_list_join_from_list::Class_list_join_from_list() : Abstract_list_join_from_list::Abstract_list_join_from_list() {
      vx_core::refcount += 1;
    }
    Class_list_join_from_list::~Class_list_join_from_list() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_list_join_from_list::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_list_join_from_list output = vx_core::e_list_join_from_list();
      return output;
    }

    vx_core::Type_any Class_list_join_from_list::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_list_join_from_list output = vx_core::e_list_join_from_list();
      return output;
    }

    vx_core::Type_typedef Class_list_join_from_list::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "list-1", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_any()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_list_join_from_list::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "list-join<-list", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_list_join_from_list::vx_empty() const {return vx_core::e_list_join_from_list();}
    vx_core::Type_any Class_list_join_from_list::vx_type() const {return vx_core::t_list_join_from_list();}
    vx_core::Type_msgblock Class_list_join_from_list::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_list_join_from_list::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_list_join_from_list::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_list generic_list_1 = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list values = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_any fn_any_from_any = vx_core::vx_any_from_any(vx_core::t_any_from_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_list_join_from_list(generic_list_1, values, fn_any_from_any);
      return output;
    }

  //}

  // (func list<-list)
  // class Class_list_from_list {
    Abstract_list_from_list::~Abstract_list_from_list() {}

    Class_list_from_list::Class_list_from_list() : Abstract_list_from_list::Abstract_list_from_list() {
      vx_core::refcount += 1;
    }
    Class_list_from_list::~Class_list_from_list() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_list_from_list::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_list_from_list output = vx_core::e_list_from_list();
      return output;
    }

    vx_core::Type_any Class_list_from_list::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_list_from_list output = vx_core::e_list_from_list();
      return output;
    }

    vx_core::Type_typedef Class_list_from_list::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "list-1", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_any()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_list_from_list::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "list<-list", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_list_from_list::vx_empty() const {return vx_core::e_list_from_list();}
    vx_core::Type_any Class_list_from_list::vx_type() const {return vx_core::t_list_from_list();}
    vx_core::Type_msgblock Class_list_from_list::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_list_from_list::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_list_from_list::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_list generic_list_1 = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list values = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_any fn_any_from_any = vx_core::vx_any_from_any(vx_core::t_any_from_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_list_from_list(generic_list_1, values, fn_any_from_any);
      return output;
    }

  //}

  // (func list<-list-async)
  // class Class_list_from_list_async {
    Abstract_list_from_list_async::~Abstract_list_from_list_async() {}

    Class_list_from_list_async::Class_list_from_list_async() : Abstract_list_from_list_async::Abstract_list_from_list_async() {
      vx_core::refcount += 1;
    }
    Class_list_from_list_async::~Class_list_from_list_async() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_list_from_list_async::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_list_from_list_async output = vx_core::e_list_from_list_async();
      return output;
    }

    vx_core::Type_any Class_list_from_list_async::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_list_from_list_async output = vx_core::e_list_from_list_async();
      return output;
    }

    vx_core::Type_typedef Class_list_from_list_async::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "list-1", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_any()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_list_from_list_async::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "list<-list-async", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_list_from_list_async::vx_empty() const {return vx_core::e_list_from_list_async();}
    vx_core::Type_any Class_list_from_list_async::vx_type() const {return vx_core::t_list_from_list_async();}
    vx_core::Type_msgblock Class_list_from_list_async::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_list_from_list_async::vx_dispose() {return vx_core::emptylistany;}

    vx_core::vx_Type_async Class_list_from_list_async::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      vx_core::Type_list generic_list_1 = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list values = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_any_async fn_any_from_any_async = vx_core::vx_any_from_any(vx_core::t_any_from_any_async(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_list_from_list_async(generic_list_1, values, fn_any_from_any_async);
      return output;
    }

  //}

  // (func list<-map)
  // class Class_list_from_map {
    Abstract_list_from_map::~Abstract_list_from_map() {}

    Class_list_from_map::Class_list_from_map() : Abstract_list_from_map::Abstract_list_from_map() {
      vx_core::refcount += 1;
    }
    Class_list_from_map::~Class_list_from_map() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_list_from_map::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_list_from_map output = vx_core::e_list_from_map();
      return output;
    }

    vx_core::Type_any Class_list_from_map::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_list_from_map output = vx_core::e_list_from_map();
      return output;
    }

    vx_core::Type_typedef Class_list_from_map::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "list-1", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_any()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_list_from_map::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "list<-map", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_list_from_map::vx_empty() const {return vx_core::e_list_from_map();}
    vx_core::Type_any Class_list_from_map::vx_type() const {return vx_core::t_list_from_map();}
    vx_core::Type_msgblock Class_list_from_map::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_list_from_map::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_list_from_map::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_list generic_list_1 = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_map valuemap = vx_core::vx_any_from_any(vx_core::t_map(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_key_value fn_any_from_key_value = vx_core::vx_any_from_any(vx_core::t_any_from_key_value(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_list_from_map(generic_list_1, valuemap, fn_any_from_key_value);
      return output;
    }

  //}

  // (func list<-map-async)
  // class Class_list_from_map_async {
    Abstract_list_from_map_async::~Abstract_list_from_map_async() {}

    Class_list_from_map_async::Class_list_from_map_async() : Abstract_list_from_map_async::Abstract_list_from_map_async() {
      vx_core::refcount += 1;
    }
    Class_list_from_map_async::~Class_list_from_map_async() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_list_from_map_async::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_list_from_map_async output = vx_core::e_list_from_map_async();
      return output;
    }

    vx_core::Type_any Class_list_from_map_async::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_list_from_map_async output = vx_core::e_list_from_map_async();
      return output;
    }

    vx_core::Type_typedef Class_list_from_map_async::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "list-1", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_any()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_list_from_map_async::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "list<-map-async", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_list_from_map_async::vx_empty() const {return vx_core::e_list_from_map_async();}
    vx_core::Type_any Class_list_from_map_async::vx_type() const {return vx_core::t_list_from_map_async();}
    vx_core::Type_msgblock Class_list_from_map_async::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_list_from_map_async::vx_dispose() {return vx_core::emptylistany;}

    vx_core::vx_Type_async Class_list_from_map_async::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      vx_core::Type_list generic_list_1 = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_map valuemap = vx_core::vx_any_from_any(vx_core::t_map(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_key_value_async fn_any_from_key_value_async = vx_core::vx_any_from_any(vx_core::t_any_from_key_value_async(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_list_from_map_async(generic_list_1, valuemap, fn_any_from_key_value_async);
      return output;
    }

  //}

  // (func list<-type)
  vx_core::Type_any f_list_from_type(vx_core::Type_any type) {
    vx_core::Type_any output = vx_core::e_any();
    return output;
  }

  // (func list<-type)
  // class Class_list_from_type {
    Abstract_list_from_type::~Abstract_list_from_type() {}

    Class_list_from_type::Class_list_from_type() : Abstract_list_from_type::Abstract_list_from_type() {
      vx_core::refcount += 1;
    }
    Class_list_from_type::~Class_list_from_type() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_list_from_type::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_list_from_type output = vx_core::e_list_from_type();
      return output;
    }

    vx_core::Type_any Class_list_from_type::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_list_from_type output = vx_core::e_list_from_type();
      return output;
    }

    vx_core::Type_typedef Class_list_from_type::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_list_from_type::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "list<-type", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_list_from_type::vx_empty() const {return vx_core::e_list_from_type();}
    vx_core::Type_any Class_list_from_type::vx_type() const {return vx_core::t_list_from_type();}
    vx_core::Type_msgblock Class_list_from_type::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_list_from_type::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_list_from_type::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_list_from_type::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any(), val);
      output = vx_core::f_list_from_type(inputval);
      return output;
    }

    vx_core::Type_any Class_list_from_type::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any type = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_list_from_type(type);
      return output;
    }

  //}

  // (func log)
  vx_core::Type_any f_log(vx_core::Type_any value) {
    vx_core::Type_any output = vx_core::e_any();
    return output;
  }

  // (func log)
  // class Class_log {
    Abstract_log::~Abstract_log() {}

    Class_log::Class_log() : Abstract_log::Abstract_log() {
      vx_core::refcount += 1;
    }
    Class_log::~Class_log() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_log::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_log output = vx_core::e_log();
      return output;
    }

    vx_core::Type_any Class_log::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_log output = vx_core::e_log();
      return output;
    }

    vx_core::Type_typedef Class_log::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_log::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "log", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_log::vx_empty() const {return vx_core::e_log();}
    vx_core::Type_any Class_log::vx_type() const {return vx_core::t_log();}
    vx_core::Type_msgblock Class_log::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_log::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_log::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_log::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any(), val);
      output = vx_core::f_log(inputval);
      return output;
    }

    vx_core::Type_any Class_log::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_log(value);
      return output;
    }

  //}

  // (func map<-list)
  // class Class_map_from_list {
    Abstract_map_from_list::~Abstract_map_from_list() {}

    Class_map_from_list::Class_map_from_list() : Abstract_map_from_list::Abstract_map_from_list() {
      vx_core::refcount += 1;
    }
    Class_map_from_list::~Class_map_from_list() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_map_from_list::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_map_from_list output = vx_core::e_map_from_list();
      return output;
    }

    vx_core::Type_any Class_map_from_list::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_map_from_list output = vx_core::e_map_from_list();
      return output;
    }

    vx_core::Type_typedef Class_map_from_list::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "map-1", // name
        ":map", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_any()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_map_from_list::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "map<-list", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_map_from_list::vx_empty() const {return vx_core::e_map_from_list();}
    vx_core::Type_any Class_map_from_list::vx_type() const {return vx_core::t_map_from_list();}
    vx_core::Type_msgblock Class_map_from_list::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_map_from_list::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_map_from_list::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_map generic_map_1 = vx_core::vx_any_from_any(vx_core::t_map(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list vallist = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_any fn_any_from_any = vx_core::vx_any_from_any(vx_core::t_any_from_any(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_map_from_list(generic_map_1, vallist, fn_any_from_any);
      return output;
    }

  //}

  // (func mempool-addref)
  void f_mempool_addref(vx_core::Type_anylist values) {
  }

  // (func mempool-addref)
  // class Class_mempool_addref {
    Abstract_mempool_addref::~Abstract_mempool_addref() {}

    Class_mempool_addref::Class_mempool_addref() : Abstract_mempool_addref::Abstract_mempool_addref() {
      vx_core::refcount += 1;
    }
    Class_mempool_addref::~Class_mempool_addref() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_mempool_addref::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_mempool_addref output = vx_core::e_mempool_addref();
      return output;
    }

    vx_core::Type_any Class_mempool_addref::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_mempool_addref output = vx_core::e_mempool_addref();
      return output;
    }

    vx_core::Type_typedef Class_mempool_addref::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "none", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_mempool_addref::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "mempool-addref", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_mempool_addref::vx_empty() const {return vx_core::e_mempool_addref();}
    vx_core::Type_any Class_mempool_addref::vx_type() const {return vx_core::t_mempool_addref();}
    vx_core::Type_msgblock Class_mempool_addref::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_mempool_addref::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_mempool_addref::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_anylist values = vx_core::vx_any_from_any(vx_core::t_anylist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::f_mempool_addref(values);
      return output;
    }

  //}

  // (func mempool-release)
  void f_mempool_release(vx_core::Type_value value) {
  }

  // (func mempool-release)
  // class Class_mempool_release {
    Abstract_mempool_release::~Abstract_mempool_release() {}

    Class_mempool_release::Class_mempool_release() : Abstract_mempool_release::Abstract_mempool_release() {
      vx_core::refcount += 1;
    }
    Class_mempool_release::~Class_mempool_release() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_mempool_release::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_mempool_release output = vx_core::e_mempool_release();
      return output;
    }

    vx_core::Type_any Class_mempool_release::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_mempool_release output = vx_core::e_mempool_release();
      return output;
    }

    vx_core::Type_typedef Class_mempool_release::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "none", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_mempool_release::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "mempool-release", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_mempool_release::vx_empty() const {return vx_core::e_mempool_release();}
    vx_core::Type_any Class_mempool_release::vx_type() const {return vx_core::t_mempool_release();}
    vx_core::Type_msgblock Class_mempool_release::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_mempool_release::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_mempool_release::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_value value = vx_core::vx_any_from_any(vx_core::t_value(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::f_mempool_release(value);
      return output;
    }

  //}

  // (func mempool-removeref)
  void f_mempool_removeref(vx_core::Type_anylist values) {
  }

  // (func mempool-removeref)
  // class Class_mempool_removeref {
    Abstract_mempool_removeref::~Abstract_mempool_removeref() {}

    Class_mempool_removeref::Class_mempool_removeref() : Abstract_mempool_removeref::Abstract_mempool_removeref() {
      vx_core::refcount += 1;
    }
    Class_mempool_removeref::~Class_mempool_removeref() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_mempool_removeref::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_mempool_removeref output = vx_core::e_mempool_removeref();
      return output;
    }

    vx_core::Type_any Class_mempool_removeref::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_mempool_removeref output = vx_core::e_mempool_removeref();
      return output;
    }

    vx_core::Type_typedef Class_mempool_removeref::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "none", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_mempool_removeref::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "mempool-removeref", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_mempool_removeref::vx_empty() const {return vx_core::e_mempool_removeref();}
    vx_core::Type_any Class_mempool_removeref::vx_type() const {return vx_core::t_mempool_removeref();}
    vx_core::Type_msgblock Class_mempool_removeref::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_mempool_removeref::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_mempool_removeref::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_anylist values = vx_core::vx_any_from_any(vx_core::t_anylist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::f_mempool_removeref(values);
      return output;
    }

  //}

  // (func mempool-removerefchildren)
  void f_mempool_removerefchildren(vx_core::Type_anylist values) {
  }

  // (func mempool-removerefchildren)
  // class Class_mempool_removerefchildren {
    Abstract_mempool_removerefchildren::~Abstract_mempool_removerefchildren() {}

    Class_mempool_removerefchildren::Class_mempool_removerefchildren() : Abstract_mempool_removerefchildren::Abstract_mempool_removerefchildren() {
      vx_core::refcount += 1;
    }
    Class_mempool_removerefchildren::~Class_mempool_removerefchildren() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_mempool_removerefchildren::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_mempool_removerefchildren output = vx_core::e_mempool_removerefchildren();
      return output;
    }

    vx_core::Type_any Class_mempool_removerefchildren::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_mempool_removerefchildren output = vx_core::e_mempool_removerefchildren();
      return output;
    }

    vx_core::Type_typedef Class_mempool_removerefchildren::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "none", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_mempool_removerefchildren::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "mempool-removerefchildren", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_mempool_removerefchildren::vx_empty() const {return vx_core::e_mempool_removerefchildren();}
    vx_core::Type_any Class_mempool_removerefchildren::vx_type() const {return vx_core::t_mempool_removerefchildren();}
    vx_core::Type_msgblock Class_mempool_removerefchildren::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_mempool_removerefchildren::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_mempool_removerefchildren::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_anylist values = vx_core::vx_any_from_any(vx_core::t_anylist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::f_mempool_removerefchildren(values);
      return output;
    }

  //}

  // (func mempool-reserve)
  vx_core::Type_value f_mempool_reserve() {
    vx_core::Type_value output = vx_core::e_value();
    return output;
  }

  // (func mempool-reserve)
  // class Class_mempool_reserve {
    Abstract_mempool_reserve::~Abstract_mempool_reserve() {}

    Class_mempool_reserve::Class_mempool_reserve() : Abstract_mempool_reserve::Abstract_mempool_reserve() {
      vx_core::refcount += 1;
    }
    Class_mempool_reserve::~Class_mempool_reserve() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_mempool_reserve::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_mempool_reserve output = vx_core::e_mempool_reserve();
      return output;
    }

    vx_core::Type_any Class_mempool_reserve::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_mempool_reserve output = vx_core::e_mempool_reserve();
      return output;
    }

    vx_core::Type_typedef Class_mempool_reserve::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "value", // name
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
    }

    vx_core::Type_funcdef Class_mempool_reserve::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "mempool-reserve", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_mempool_reserve::vx_empty() const {return vx_core::e_mempool_reserve();}
    vx_core::Type_any Class_mempool_reserve::vx_type() const {return vx_core::t_mempool_reserve();}
    vx_core::Type_msgblock Class_mempool_reserve::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_mempool_reserve::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_mempool_reserve::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      output = vx_core::f_mempool_reserve();
      return output;
    }

  //}

  // (func msg<-error)
  vx_core::Type_msg f_msg_from_error(vx_core::Type_string error) {
    vx_core::Type_msg output = vx_core::e_msg();
    output = vx_core::f_new(
      vx_core::t_msg(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vx_core::vx_new_string(":severity"),
        vx_core::c_msg_error(),
        vx_core::vx_new_string(":text"),
        error
      })
    );
    return output;
  }

  // (func msg<-error)
  // class Class_msg_from_error {
    Abstract_msg_from_error::~Abstract_msg_from_error() {}

    Class_msg_from_error::Class_msg_from_error() : Abstract_msg_from_error::Abstract_msg_from_error() {
      vx_core::refcount += 1;
    }
    Class_msg_from_error::~Class_msg_from_error() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_msg_from_error::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_msg_from_error output = vx_core::e_msg_from_error();
      return output;
    }

    vx_core::Type_any Class_msg_from_error::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_msg_from_error output = vx_core::e_msg_from_error();
      return output;
    }

    vx_core::Type_typedef Class_msg_from_error::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "msg", // name
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
    }

    vx_core::Type_funcdef Class_msg_from_error::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "msg<-error", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_msg_from_error::vx_empty() const {return vx_core::e_msg_from_error();}
    vx_core::Type_any Class_msg_from_error::vx_type() const {return vx_core::t_msg_from_error();}
    vx_core::Type_msgblock Class_msg_from_error::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_msg_from_error::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_msg_from_error::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_msg_from_error::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string(), val);
      output = vx_core::f_msg_from_error(inputval);
      return output;
    }

    vx_core::Type_any Class_msg_from_error::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string error = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_msg_from_error(error);
      return output;
    }

  //}

  // (func msgblock<-msgblock-msg)
  vx_core::Type_msgblock f_msgblock_from_msgblock_msg(vx_core::Type_msgblock origblock, vx_core::Type_msg addmsg) {
    vx_core::Type_msgblock output = vx_core::e_msgblock();
    output = vx_core::f_copy(origblock, vx_core::vx_new(vx_core::t_anylist(), {
      addmsg}));
    return output;
  }

  // (func msgblock<-msgblock-msg)
  // class Class_msgblock_from_msgblock_msg {
    Abstract_msgblock_from_msgblock_msg::~Abstract_msgblock_from_msgblock_msg() {}

    Class_msgblock_from_msgblock_msg::Class_msgblock_from_msgblock_msg() : Abstract_msgblock_from_msgblock_msg::Abstract_msgblock_from_msgblock_msg() {
      vx_core::refcount += 1;
    }
    Class_msgblock_from_msgblock_msg::~Class_msgblock_from_msgblock_msg() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_msgblock_from_msgblock_msg::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_msgblock_from_msgblock_msg output = vx_core::e_msgblock_from_msgblock_msg();
      return output;
    }

    vx_core::Type_any Class_msgblock_from_msgblock_msg::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_msgblock_from_msgblock_msg output = vx_core::e_msgblock_from_msgblock_msg();
      return output;
    }

    vx_core::Type_typedef Class_msgblock_from_msgblock_msg::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "msgblock", // name
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
    }

    vx_core::Type_funcdef Class_msgblock_from_msgblock_msg::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "msgblock<-msgblock-msg", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_msgblock_from_msgblock_msg::vx_empty() const {return vx_core::e_msgblock_from_msgblock_msg();}
    vx_core::Type_any Class_msgblock_from_msgblock_msg::vx_type() const {return vx_core::t_msgblock_from_msgblock_msg();}
    vx_core::Type_msgblock Class_msgblock_from_msgblock_msg::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_msgblock_from_msgblock_msg::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_msgblock_from_msgblock_msg::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_msgblock origblock = vx_core::vx_any_from_any(vx_core::t_msgblock(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_msg addmsg = vx_core::vx_any_from_any(vx_core::t_msg(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_msgblock_from_msgblock_msg(origblock, addmsg);
      return output;
    }

  //}

  // (func msgblock<-msgblock-msgblock)
  vx_core::Type_msgblock f_msgblock_from_msgblock_msgblock(vx_core::Type_msgblock origblock, vx_core::Type_msgblock addblock) {
    vx_core::Type_msgblock output = vx_core::e_msgblock();
    output = vx_core::f_new(
      vx_core::t_msgblock(),
      vx_core::vx_new(vx_core::t_anylist(), {
        origblock,
        addblock
      })
    );
    return output;
  }

  // (func msgblock<-msgblock-msgblock)
  // class Class_msgblock_from_msgblock_msgblock {
    Abstract_msgblock_from_msgblock_msgblock::~Abstract_msgblock_from_msgblock_msgblock() {}

    Class_msgblock_from_msgblock_msgblock::Class_msgblock_from_msgblock_msgblock() : Abstract_msgblock_from_msgblock_msgblock::Abstract_msgblock_from_msgblock_msgblock() {
      vx_core::refcount += 1;
    }
    Class_msgblock_from_msgblock_msgblock::~Class_msgblock_from_msgblock_msgblock() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_msgblock_from_msgblock_msgblock::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_msgblock_from_msgblock_msgblock output = vx_core::e_msgblock_from_msgblock_msgblock();
      return output;
    }

    vx_core::Type_any Class_msgblock_from_msgblock_msgblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_msgblock_from_msgblock_msgblock output = vx_core::e_msgblock_from_msgblock_msgblock();
      return output;
    }

    vx_core::Type_typedef Class_msgblock_from_msgblock_msgblock::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "msgblock", // name
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
    }

    vx_core::Type_funcdef Class_msgblock_from_msgblock_msgblock::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "msgblock<-msgblock-msgblock", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_msgblock_from_msgblock_msgblock::vx_empty() const {return vx_core::e_msgblock_from_msgblock_msgblock();}
    vx_core::Type_any Class_msgblock_from_msgblock_msgblock::vx_type() const {return vx_core::t_msgblock_from_msgblock_msgblock();}
    vx_core::Type_msgblock Class_msgblock_from_msgblock_msgblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_msgblock_from_msgblock_msgblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_msgblock_from_msgblock_msgblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_msgblock origblock = vx_core::vx_any_from_any(vx_core::t_msgblock(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_msgblock addblock = vx_core::vx_any_from_any(vx_core::t_msgblock(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_msgblock_from_msgblock_msgblock(origblock, addblock);
      return output;
    }

  //}

  // (func name<-typedef)
  vx_core::Type_string f_name_from_typedef(vx_core::Type_typedef vtypedef) {
    vx_core::Type_string output = vx_core::e_string();
    output = vtypedef->name();
    return output;
  }

  // (func name<-typedef)
  // class Class_name_from_typedef {
    Abstract_name_from_typedef::~Abstract_name_from_typedef() {}

    Class_name_from_typedef::Class_name_from_typedef() : Abstract_name_from_typedef::Abstract_name_from_typedef() {
      vx_core::refcount += 1;
    }
    Class_name_from_typedef::~Class_name_from_typedef() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_name_from_typedef::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_name_from_typedef output = vx_core::e_name_from_typedef();
      return output;
    }

    vx_core::Type_any Class_name_from_typedef::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_name_from_typedef output = vx_core::e_name_from_typedef();
      return output;
    }

    vx_core::Type_typedef Class_name_from_typedef::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "string", // name
        "string", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_name_from_typedef::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "name<-typedef", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_name_from_typedef::vx_empty() const {return vx_core::e_name_from_typedef();}
    vx_core::Type_any Class_name_from_typedef::vx_type() const {return vx_core::t_name_from_typedef();}
    vx_core::Type_msgblock Class_name_from_typedef::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_name_from_typedef::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_name_from_typedef::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_name_from_typedef::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_typedef inputval = vx_core::vx_any_from_any(vx_core::t_typedef(), val);
      output = vx_core::f_name_from_typedef(inputval);
      return output;
    }

    vx_core::Type_any Class_name_from_typedef::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_typedef vtypedef = vx_core::vx_any_from_any(vx_core::t_typedef(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_name_from_typedef(vtypedef);
      return output;
    }

  //}

  // (func native)
  // class Class_native {
    Abstract_native::~Abstract_native() {}

    Class_native::Class_native() : Abstract_native::Abstract_native() {
      vx_core::refcount += 1;
    }
    Class_native::~Class_native() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_native::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_native output = vx_core::e_native();
      return output;
    }

    vx_core::Type_any Class_native::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_native output = vx_core::e_native();
      return output;
    }

    vx_core::Type_typedef Class_native::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_native::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "native", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_native::vx_empty() const {return vx_core::e_native();}
    vx_core::Type_any Class_native::vx_type() const {return vx_core::t_native();}
    vx_core::Type_msgblock Class_native::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_native::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_native::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_native::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_anylist inputval = vx_core::vx_any_from_any(vx_core::t_anylist(), val);
      output = vx_core::f_native(vx_core::t_any(), inputval);
      return output;
    }

    vx_core::Type_any Class_native::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_anylist clauses = vx_core::vx_any_from_any(vx_core::t_anylist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_native(generic_any_1, clauses);
      return output;
    }

  //}

  // (func native<-any)
  vx_core::Type_any f_native_from_any(vx_core::Type_any value) {
    vx_core::Type_any output = vx_core::e_any();
    return output;
  }

  // (func native<-any)
  // class Class_native_from_any {
    Abstract_native_from_any::~Abstract_native_from_any() {}

    Class_native_from_any::Class_native_from_any() : Abstract_native_from_any::Abstract_native_from_any() {
      vx_core::refcount += 1;
    }
    Class_native_from_any::~Class_native_from_any() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_native_from_any::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_native_from_any output = vx_core::e_native_from_any();
      return output;
    }

    vx_core::Type_any Class_native_from_any::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_native_from_any output = vx_core::e_native_from_any();
      return output;
    }

    vx_core::Type_typedef Class_native_from_any::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_native_from_any::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "native<-any", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_native_from_any::vx_empty() const {return vx_core::e_native_from_any();}
    vx_core::Type_any Class_native_from_any::vx_type() const {return vx_core::t_native_from_any();}
    vx_core::Type_msgblock Class_native_from_any::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_native_from_any::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_native_from_any::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_native_from_any::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any(), val);
      output = vx_core::f_native_from_any(inputval);
      return output;
    }

    vx_core::Type_any Class_native_from_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_native_from_any(value);
      return output;
    }

  //}

  // (func number<-func)
  vx_core::Type_number f_number_from_func() {
    vx_core::Type_number output = vx_core::e_number();
    return output;
  }

  // (func number<-func)
  // class Class_number_from_func {
    Abstract_number_from_func::~Abstract_number_from_func() {}

    Class_number_from_func::Class_number_from_func() : Abstract_number_from_func::Abstract_number_from_func() {
      vx_core::refcount += 1;
    }
    Class_number_from_func::~Class_number_from_func() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_number_from_func::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_number_from_func output = vx_core::e_number_from_func();
      return output;
    }

    vx_core::Type_any Class_number_from_func::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_number_from_func output = vx_core::e_number_from_func();
      return output;
    }

    vx_core::Type_typedef Class_number_from_func::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "number", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_int(), vx_core::t_float(), vx_core::t_decimal()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_number_from_func::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "number<-func", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_number_from_func::vx_empty() const {return vx_core::e_number_from_func();}
    vx_core::Type_any Class_number_from_func::vx_type() const {return vx_core::t_number_from_func();}
    vx_core::Type_msgblock Class_number_from_func::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_number_from_func::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_number_from_func::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      output = vx_core::f_number_from_func();
      return output;
    }

  //}

  // (func packagename<-typedef)
  vx_core::Type_string f_packagename_from_typedef(vx_core::Type_typedef vtypedef) {
    vx_core::Type_string output = vx_core::e_string();
    output = vtypedef->pkgname();
    return output;
  }

  // (func packagename<-typedef)
  // class Class_packagename_from_typedef {
    Abstract_packagename_from_typedef::~Abstract_packagename_from_typedef() {}

    Class_packagename_from_typedef::Class_packagename_from_typedef() : Abstract_packagename_from_typedef::Abstract_packagename_from_typedef() {
      vx_core::refcount += 1;
    }
    Class_packagename_from_typedef::~Class_packagename_from_typedef() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_packagename_from_typedef::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_packagename_from_typedef output = vx_core::e_packagename_from_typedef();
      return output;
    }

    vx_core::Type_any Class_packagename_from_typedef::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_packagename_from_typedef output = vx_core::e_packagename_from_typedef();
      return output;
    }

    vx_core::Type_typedef Class_packagename_from_typedef::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "string", // name
        "string", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_packagename_from_typedef::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "packagename<-typedef", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_packagename_from_typedef::vx_empty() const {return vx_core::e_packagename_from_typedef();}
    vx_core::Type_any Class_packagename_from_typedef::vx_type() const {return vx_core::t_packagename_from_typedef();}
    vx_core::Type_msgblock Class_packagename_from_typedef::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_packagename_from_typedef::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_packagename_from_typedef::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_packagename_from_typedef::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_typedef inputval = vx_core::vx_any_from_any(vx_core::t_typedef(), val);
      output = vx_core::f_packagename_from_typedef(inputval);
      return output;
    }

    vx_core::Type_any Class_packagename_from_typedef::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_typedef vtypedef = vx_core::vx_any_from_any(vx_core::t_typedef(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_packagename_from_typedef(vtypedef);
      return output;
    }

  //}

  // (func path<-context-path)
  vx_core::Type_string f_path_from_context_path(vx_core::Type_string path, vx_core::Type_context context) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_path_from_setting_path(
      vx_core::f_setting_from_context(context),
      path
    );
    return output;
  }

  // (func path<-context-path)
  // class Class_path_from_context_path {
    Abstract_path_from_context_path::~Abstract_path_from_context_path() {}

    Class_path_from_context_path::Class_path_from_context_path() : Abstract_path_from_context_path::Abstract_path_from_context_path() {
      vx_core::refcount += 1;
    }
    Class_path_from_context_path::~Class_path_from_context_path() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_path_from_context_path::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_path_from_context_path output = vx_core::e_path_from_context_path();
      return output;
    }

    vx_core::Type_any Class_path_from_context_path::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_path_from_context_path output = vx_core::e_path_from_context_path();
      return output;
    }

    vx_core::Type_typedef Class_path_from_context_path::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "string", // name
        "string", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_path_from_context_path::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "path<-context-path", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_path_from_context_path::vx_empty() const {return vx_core::e_path_from_context_path();}
    vx_core::Type_any Class_path_from_context_path::vx_type() const {return vx_core::t_path_from_context_path();}
    vx_core::Type_msgblock Class_path_from_context_path::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_path_from_context_path::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_path_from_context_path::vx_fn_new(vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context();
    }

    vx_core::Type_any Class_path_from_context_path::vx_any_from_any_context(vx_core::Type_any val, vx_core::Type_context context) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string(), val);
      output = vx_core::f_path_from_context_path(inputval, context);
      return output;
    }

    vx_core::Type_any Class_path_from_context_path::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string path = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_path_from_context_path(path, context);
      return output;
    }

  //}

  // (func path<-setting-path)
  vx_core::Type_string f_path_from_setting_path(vx_core::Type_setting session, vx_core::Type_string path) {
    vx_core::Type_string output = vx_core::e_string();
    return output;
  }

  // (func path<-setting-path)
  // class Class_path_from_setting_path {
    Abstract_path_from_setting_path::~Abstract_path_from_setting_path() {}

    Class_path_from_setting_path::Class_path_from_setting_path() : Abstract_path_from_setting_path::Abstract_path_from_setting_path() {
      vx_core::refcount += 1;
    }
    Class_path_from_setting_path::~Class_path_from_setting_path() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_path_from_setting_path::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_path_from_setting_path output = vx_core::e_path_from_setting_path();
      return output;
    }

    vx_core::Type_any Class_path_from_setting_path::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_path_from_setting_path output = vx_core::e_path_from_setting_path();
      return output;
    }

    vx_core::Type_typedef Class_path_from_setting_path::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "string", // name
        "string", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_path_from_setting_path::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "path<-setting-path", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_path_from_setting_path::vx_empty() const {return vx_core::e_path_from_setting_path();}
    vx_core::Type_any Class_path_from_setting_path::vx_type() const {return vx_core::t_path_from_setting_path();}
    vx_core::Type_msgblock Class_path_from_setting_path::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_path_from_setting_path::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_path_from_setting_path::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_setting session = vx_core::vx_any_from_any(vx_core::t_setting(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_string path = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_path_from_setting_path(session, path);
      return output;
    }

  //}

  // (func permission<-id-context)
  vx_core::Type_permission f_permission_from_id_context(vx_core::Type_string id, vx_core::Type_context context) {
    vx_core::Type_permission output = vx_core::e_permission();
    output = vx_core::f_let(
      vx_core::t_permission(),
      vx_core::t_any_from_func()->vx_fn_new([context]() {
        vx_core::Type_user user = vx_core::f_user_from_context(context);
        vx_core::Type_security security = user->security();
        vx_core::Type_permissionmap permissionmap = security->permissionmap();
        return vx_core::f_any_from_map(vx_core::t_permission(), permissionmap, vx_core::vx_new_string(":id"));
      })
    );
    return output;
  }

  // (func permission<-id-context)
  // class Class_permission_from_id_context {
    Abstract_permission_from_id_context::~Abstract_permission_from_id_context() {}

    Class_permission_from_id_context::Class_permission_from_id_context() : Abstract_permission_from_id_context::Abstract_permission_from_id_context() {
      vx_core::refcount += 1;
    }
    Class_permission_from_id_context::~Class_permission_from_id_context() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_permission_from_id_context::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_permission_from_id_context output = vx_core::e_permission_from_id_context();
      return output;
    }

    vx_core::Type_any Class_permission_from_id_context::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_permission_from_id_context output = vx_core::e_permission_from_id_context();
      return output;
    }

    vx_core::Type_typedef Class_permission_from_id_context::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "permission", // name
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
    }

    vx_core::Type_funcdef Class_permission_from_id_context::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "permission<-id-context", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_permission_from_id_context::vx_empty() const {return vx_core::e_permission_from_id_context();}
    vx_core::Type_any Class_permission_from_id_context::vx_type() const {return vx_core::t_permission_from_id_context();}
    vx_core::Type_msgblock Class_permission_from_id_context::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_permission_from_id_context::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_permission_from_id_context::vx_fn_new(vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context();
    }

    vx_core::Type_any Class_permission_from_id_context::vx_any_from_any_context(vx_core::Type_any val, vx_core::Type_context context) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string(), val);
      output = vx_core::f_permission_from_id_context(inputval, context);
      return output;
    }

    vx_core::Type_any Class_permission_from_id_context::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string id = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_permission_from_id_context(id, context);
      return output;
    }

  //}

  // (func properties<-typedef)
  vx_core::Type_argmap f_properties_from_typedef(vx_core::Type_typedef vtypedef) {
    vx_core::Type_argmap output = vx_core::e_argmap();
    output = vtypedef->properties();
    return output;
  }

  // (func properties<-typedef)
  // class Class_properties_from_typedef {
    Abstract_properties_from_typedef::~Abstract_properties_from_typedef() {}

    Class_properties_from_typedef::Class_properties_from_typedef() : Abstract_properties_from_typedef::Abstract_properties_from_typedef() {
      vx_core::refcount += 1;
    }
    Class_properties_from_typedef::~Class_properties_from_typedef() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_properties_from_typedef::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_properties_from_typedef output = vx_core::e_properties_from_typedef();
      return output;
    }

    vx_core::Type_any Class_properties_from_typedef::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_properties_from_typedef output = vx_core::e_properties_from_typedef();
      return output;
    }

    vx_core::Type_typedef Class_properties_from_typedef::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "argmap", // name
        ":map", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_arg()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_properties_from_typedef::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "properties<-typedef", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_properties_from_typedef::vx_empty() const {return vx_core::e_properties_from_typedef();}
    vx_core::Type_any Class_properties_from_typedef::vx_type() const {return vx_core::t_properties_from_typedef();}
    vx_core::Type_msgblock Class_properties_from_typedef::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_properties_from_typedef::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_properties_from_typedef::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_properties_from_typedef::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_typedef inputval = vx_core::vx_any_from_any(vx_core::t_typedef(), val);
      output = vx_core::f_properties_from_typedef(inputval);
      return output;
    }

    vx_core::Type_any Class_properties_from_typedef::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_typedef vtypedef = vx_core::vx_any_from_any(vx_core::t_typedef(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_properties_from_typedef(vtypedef);
      return output;
    }

  //}

  // (func proplast<-typedef)
  vx_core::Type_arg f_proplast_from_typedef(vx_core::Type_typedef vtypedef) {
    vx_core::Type_arg output = vx_core::e_arg();
    output = vtypedef->proplast();
    return output;
  }

  // (func proplast<-typedef)
  // class Class_proplast_from_typedef {
    Abstract_proplast_from_typedef::~Abstract_proplast_from_typedef() {}

    Class_proplast_from_typedef::Class_proplast_from_typedef() : Abstract_proplast_from_typedef::Abstract_proplast_from_typedef() {
      vx_core::refcount += 1;
    }
    Class_proplast_from_typedef::~Class_proplast_from_typedef() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_proplast_from_typedef::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_proplast_from_typedef output = vx_core::e_proplast_from_typedef();
      return output;
    }

    vx_core::Type_any Class_proplast_from_typedef::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_proplast_from_typedef output = vx_core::e_proplast_from_typedef();
      return output;
    }

    vx_core::Type_typedef Class_proplast_from_typedef::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "arg", // name
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
    }

    vx_core::Type_funcdef Class_proplast_from_typedef::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "proplast<-typedef", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_proplast_from_typedef::vx_empty() const {return vx_core::e_proplast_from_typedef();}
    vx_core::Type_any Class_proplast_from_typedef::vx_type() const {return vx_core::t_proplast_from_typedef();}
    vx_core::Type_msgblock Class_proplast_from_typedef::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_proplast_from_typedef::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_proplast_from_typedef::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_proplast_from_typedef::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_typedef inputval = vx_core::vx_any_from_any(vx_core::t_typedef(), val);
      output = vx_core::f_proplast_from_typedef(inputval);
      return output;
    }

    vx_core::Type_any Class_proplast_from_typedef::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_typedef vtypedef = vx_core::vx_any_from_any(vx_core::t_typedef(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_proplast_from_typedef(vtypedef);
      return output;
    }

  //}

  // (func resolve)
  // class Class_resolve {
    Abstract_resolve::~Abstract_resolve() {}

    Class_resolve::Class_resolve() : Abstract_resolve::Abstract_resolve() {
      vx_core::refcount += 1;
    }
    Class_resolve::~Class_resolve() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_resolve::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_resolve output = vx_core::e_resolve();
      return output;
    }

    vx_core::Type_any Class_resolve::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_resolve output = vx_core::e_resolve();
      return output;
    }

    vx_core::Type_typedef Class_resolve::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_resolve::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "resolve", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_resolve::vx_empty() const {return vx_core::e_resolve();}
    vx_core::Type_any Class_resolve::vx_type() const {return vx_core::t_resolve();}
    vx_core::Type_msgblock Class_resolve::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_resolve::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_resolve::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_resolve::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any(), val);
      output = vx_core::f_resolve(vx_core::t_any(), inputval);
      return output;
    }

    vx_core::Type_any Class_resolve::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_resolve(generic_any_1, value);
      return output;
    }

  //}

  // (func resolve)
  // class Class_resolve_1 {
    Abstract_resolve_1::~Abstract_resolve_1() {}

    Class_resolve_1::Class_resolve_1() : Abstract_resolve_1::Abstract_resolve_1() {
      vx_core::refcount += 1;
    }
    Class_resolve_1::~Class_resolve_1() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_resolve_1::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_resolve_1 output = vx_core::e_resolve_1();
      return output;
    }

    vx_core::Type_any Class_resolve_1::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_resolve_1 output = vx_core::e_resolve_1();
      return output;
    }

    vx_core::Type_typedef Class_resolve_1::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_resolve_1::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "resolve", // name
        1, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_resolve_1::vx_empty() const {return vx_core::e_resolve_1();}
    vx_core::Type_any Class_resolve_1::vx_type() const {return vx_core::t_resolve_1();}
    vx_core::Type_msgblock Class_resolve_1::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_resolve_1::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_resolve_1::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_resolve_1::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Func_any_from_func inputval = vx_core::vx_any_from_any(vx_core::t_any_from_func(), val);
      output = vx_core::f_resolve_1(vx_core::t_any(), inputval);
      return output;
    }

    vx_core::Type_any Class_resolve_1::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_func fn_any = vx_core::vx_any_from_any(vx_core::t_any_from_func(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_resolve_1(generic_any_1, fn_any);
      return output;
    }

  //}

  // (func resolve-async)
  // class Class_resolve_async {
    Abstract_resolve_async::~Abstract_resolve_async() {}

    Class_resolve_async::Class_resolve_async() : Abstract_resolve_async::Abstract_resolve_async() {
      vx_core::refcount += 1;
    }
    Class_resolve_async::~Class_resolve_async() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_resolve_async::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_resolve_async output = vx_core::e_resolve_async();
      return output;
    }

    vx_core::Type_any Class_resolve_async::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_resolve_async output = vx_core::e_resolve_async();
      return output;
    }

    vx_core::Type_typedef Class_resolve_async::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_resolve_async::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "resolve-async", // name
        0, // idx
        true, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_resolve_async::vx_empty() const {return vx_core::e_resolve_async();}
    vx_core::Type_any Class_resolve_async::vx_type() const {return vx_core::t_resolve_async();}
    vx_core::Type_msgblock Class_resolve_async::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_resolve_async::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_async Class_resolve_async::vx_fn_new(vx_core::Abstract_any_from_any_async::IFn fn) const {
      return vx_core::e_any_from_any_async();
    }

    vx_core::vx_Type_async Class_resolve_async::vx_any_from_any_async(vx_core::Type_any val) const {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(val);
      return output;
    }

    vx_core::vx_Type_async Class_resolve_async::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::vx_Type_async output = vx_core::vx_async_new_from_val(vx_core::e_any());
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Func_any_from_func_async fn_any = vx_core::vx_any_from_any(vx_core::t_any_from_func_async(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_resolve_async(generic_any_1, fn_any);
      return output;
    }

  //}

  // (func resolve-first)
  // class Class_resolve_first {
    Abstract_resolve_first::~Abstract_resolve_first() {}

    Class_resolve_first::Class_resolve_first() : Abstract_resolve_first::Abstract_resolve_first() {
      vx_core::refcount += 1;
    }
    Class_resolve_first::~Class_resolve_first() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_resolve_first::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_resolve_first output = vx_core::e_resolve_first();
      return output;
    }

    vx_core::Type_any Class_resolve_first::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_resolve_first output = vx_core::e_resolve_first();
      return output;
    }

    vx_core::Type_typedef Class_resolve_first::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any-1", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_resolve_first::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "resolve-first", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_resolve_first::vx_empty() const {return vx_core::e_resolve_first();}
    vx_core::Type_any Class_resolve_first::vx_type() const {return vx_core::t_resolve_first();}
    vx_core::Type_msgblock Class_resolve_first::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_resolve_first::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_resolve_first::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_resolve_first::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_list inputval = vx_core::vx_any_from_any(vx_core::t_list(), val);
      output = vx_core::f_resolve_first(vx_core::t_any(), inputval);
      return output;
    }

    vx_core::Type_any Class_resolve_first::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any generic_any_1 = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list clauses = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_resolve_first(generic_any_1, clauses);
      return output;
    }

  //}

  // (func resolve-list)
  // class Class_resolve_list {
    Abstract_resolve_list::~Abstract_resolve_list() {}

    Class_resolve_list::Class_resolve_list() : Abstract_resolve_list::Abstract_resolve_list() {
      vx_core::refcount += 1;
    }
    Class_resolve_list::~Class_resolve_list() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_resolve_list::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_resolve_list output = vx_core::e_resolve_list();
      return output;
    }

    vx_core::Type_any Class_resolve_list::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_resolve_list output = vx_core::e_resolve_list();
      return output;
    }

    vx_core::Type_typedef Class_resolve_list::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "list-1", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_any()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_resolve_list::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "resolve-list", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_resolve_list::vx_empty() const {return vx_core::e_resolve_list();}
    vx_core::Type_any Class_resolve_list::vx_type() const {return vx_core::t_resolve_list();}
    vx_core::Type_msgblock Class_resolve_list::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_resolve_list::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_resolve_list::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_resolve_list::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_list inputval = vx_core::vx_any_from_any(vx_core::t_list(), val);
      output = vx_core::f_resolve_list(vx_core::t_list(), inputval);
      return output;
    }

    vx_core::Type_any Class_resolve_list::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_list generic_list_1 = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_list clauses = vx_core::vx_any_from_any(vx_core::t_list(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_resolve_list(generic_list_1, clauses);
      return output;
    }

  //}

  // (func session<-context)
  vx_core::Type_session f_session_from_context(vx_core::Type_context context) {
    vx_core::Type_session output = vx_core::e_session();
    output = vx_core::t_context()->session();
    return output;
  }

  // (func session<-context)
  // class Class_session_from_context {
    Abstract_session_from_context::~Abstract_session_from_context() {}

    Class_session_from_context::Class_session_from_context() : Abstract_session_from_context::Abstract_session_from_context() {
      vx_core::refcount += 1;
    }
    Class_session_from_context::~Class_session_from_context() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_session_from_context::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_session_from_context output = vx_core::e_session_from_context();
      return output;
    }

    vx_core::Type_any Class_session_from_context::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_session_from_context output = vx_core::e_session_from_context();
      return output;
    }

    vx_core::Type_typedef Class_session_from_context::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "session", // name
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
    }

    vx_core::Type_funcdef Class_session_from_context::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "session<-context", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_session_from_context::vx_empty() const {return vx_core::e_session_from_context();}
    vx_core::Type_any Class_session_from_context::vx_type() const {return vx_core::t_session_from_context();}
    vx_core::Type_msgblock Class_session_from_context::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_session_from_context::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_session_from_context::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_session_from_context(context);
      return output;
    }

  //}

  // (func setting<-context)
  vx_core::Type_setting f_setting_from_context(vx_core::Type_context context) {
    vx_core::Type_setting output = vx_core::e_setting();
    output = vx_core::t_context()->setting();
    return output;
  }

  // (func setting<-context)
  // class Class_setting_from_context {
    Abstract_setting_from_context::~Abstract_setting_from_context() {}

    Class_setting_from_context::Class_setting_from_context() : Abstract_setting_from_context::Abstract_setting_from_context() {
      vx_core::refcount += 1;
    }
    Class_setting_from_context::~Class_setting_from_context() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_setting_from_context::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_setting_from_context output = vx_core::e_setting_from_context();
      return output;
    }

    vx_core::Type_any Class_setting_from_context::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_setting_from_context output = vx_core::e_setting_from_context();
      return output;
    }

    vx_core::Type_typedef Class_setting_from_context::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "setting", // name
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
    }

    vx_core::Type_funcdef Class_setting_from_context::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "setting<-context", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_setting_from_context::vx_empty() const {return vx_core::e_setting_from_context();}
    vx_core::Type_any Class_setting_from_context::vx_type() const {return vx_core::t_setting_from_context();}
    vx_core::Type_msgblock Class_setting_from_context::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_setting_from_context::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_setting_from_context::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_setting_from_context(context);
      return output;
    }

  //}

  // (func string-repeat)
  vx_core::Type_string f_string_repeat(vx_core::Type_string text, vx_core::Type_int repeat) {
    vx_core::Type_string output = vx_core::e_string();
    return output;
  }

  // (func string-repeat)
  // class Class_string_repeat {
    Abstract_string_repeat::~Abstract_string_repeat() {}

    Class_string_repeat::Class_string_repeat() : Abstract_string_repeat::Abstract_string_repeat() {
      vx_core::refcount += 1;
    }
    Class_string_repeat::~Class_string_repeat() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_string_repeat::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_string_repeat output = vx_core::e_string_repeat();
      return output;
    }

    vx_core::Type_any Class_string_repeat::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_string_repeat output = vx_core::e_string_repeat();
      return output;
    }

    vx_core::Type_typedef Class_string_repeat::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "string", // name
        "string", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_string_repeat::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "string-repeat", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_string_repeat::vx_empty() const {return vx_core::e_string_repeat();}
    vx_core::Type_any Class_string_repeat::vx_type() const {return vx_core::t_string_repeat();}
    vx_core::Type_msgblock Class_string_repeat::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_repeat::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_repeat::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int repeat = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      output = vx_core::f_string_repeat(text, repeat);
      return output;
    }

  //}

  // (func string<-any)
  vx_core::Type_string f_string_from_any(vx_core::Type_any value) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_string_from_any_indent(
      value,
      vx_core::vx_new_int(0),
      vx_core::vx_new_boolean(true)
    );
    return output;
  }

  // (func string<-any)
  // class Class_string_from_any {
    Abstract_string_from_any::~Abstract_string_from_any() {}

    Class_string_from_any::Class_string_from_any() : Abstract_string_from_any::Abstract_string_from_any() {
      vx_core::refcount += 1;
    }
    Class_string_from_any::~Class_string_from_any() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_string_from_any::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_string_from_any output = vx_core::e_string_from_any();
      return output;
    }

    vx_core::Type_any Class_string_from_any::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_string_from_any output = vx_core::e_string_from_any();
      return output;
    }

    vx_core::Type_typedef Class_string_from_any::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "string", // name
        "string", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_string_from_any::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "string<-any", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_string_from_any::vx_empty() const {return vx_core::e_string_from_any();}
    vx_core::Type_any Class_string_from_any::vx_type() const {return vx_core::t_string_from_any();}
    vx_core::Type_msgblock Class_string_from_any::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_any::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_string_from_any::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_string_from_any::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any(), val);
      output = vx_core::f_string_from_any(inputval);
      return output;
    }

    vx_core::Type_any Class_string_from_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_string_from_any(value);
      return output;
    }

  //}

  // (func string<-any-indent)
  vx_core::Type_string f_string_from_any_indent(vx_core::Type_any value, vx_core::Type_int indent, vx_core::Type_boolean linefeed) {
    vx_core::Type_string output = vx_core::e_string();
    std::string soutput = vx_core::vx_string_from_any_indent(value, indent->vx_int(), linefeed->vx_boolean());
    output = vx_core::vx_new_string(soutput);
    return output;
  }

  // (func string<-any-indent)
  // class Class_string_from_any_indent {
    Abstract_string_from_any_indent::~Abstract_string_from_any_indent() {}

    Class_string_from_any_indent::Class_string_from_any_indent() : Abstract_string_from_any_indent::Abstract_string_from_any_indent() {
      vx_core::refcount += 1;
    }
    Class_string_from_any_indent::~Class_string_from_any_indent() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_string_from_any_indent::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_string_from_any_indent output = vx_core::e_string_from_any_indent();
      return output;
    }

    vx_core::Type_any Class_string_from_any_indent::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_string_from_any_indent output = vx_core::e_string_from_any_indent();
      return output;
    }

    vx_core::Type_typedef Class_string_from_any_indent::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "string", // name
        "string", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_string_from_any_indent::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "string<-any-indent", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_string_from_any_indent::vx_empty() const {return vx_core::e_string_from_any_indent();}
    vx_core::Type_any Class_string_from_any_indent::vx_type() const {return vx_core::t_string_from_any_indent();}
    vx_core::Type_msgblock Class_string_from_any_indent::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_any_indent::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_string_from_any_indent::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_core::Type_int indent = vx_core::vx_any_from_any(vx_core::t_int(), arglist->vx_get_any(vx_core::vx_new_int(1)));
      vx_core::Type_boolean linefeed = vx_core::vx_any_from_any(vx_core::t_boolean(), arglist->vx_get_any(vx_core::vx_new_int(2)));
      output = vx_core::f_string_from_any_indent(value, indent, linefeed);
      return output;
    }

  //}

  // (func string<-func)
  vx_core::Type_string f_string_from_func() {
    vx_core::Type_string output = vx_core::e_string();
    return output;
  }

  // (func string<-func)
  // class Class_string_from_func {
    Abstract_string_from_func::~Abstract_string_from_func() {}

    Class_string_from_func::Class_string_from_func() : Abstract_string_from_func::Abstract_string_from_func() {
      vx_core::refcount += 1;
    }
    Class_string_from_func::~Class_string_from_func() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_string_from_func::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_string_from_func output = vx_core::e_string_from_func();
      return output;
    }

    vx_core::Type_any Class_string_from_func::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_string_from_func output = vx_core::e_string_from_func();
      return output;
    }

    vx_core::Type_typedef Class_string_from_func::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "string", // name
        "string", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_string_from_func::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "string<-func", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_string_from_func::vx_empty() const {return vx_core::e_string_from_func();}
    vx_core::Type_any Class_string_from_func::vx_type() const {return vx_core::t_string_from_func();}
    vx_core::Type_msgblock Class_string_from_func::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_string_from_func::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_string_from_func vx_core::Class_string_from_func::vx_fn_new(vx_core::Abstract_any_from_func::IFn fn) const {
      vx_core::Func_string_from_func output = new vx_core::Class_string_from_func();
      output->fn = fn;
      return output;
    }

    vx_core::Type_string Class_string_from_func::vx_string_from_func() const {
      vx_core::Type_string output = vx_core::e_string();
      return output;
    }

    vx_core::Type_any Class_string_from_func::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      output = vx_core::f_string_from_func();
      return output;
    }

  //}

  // (func traits<-typedef)
  vx_core::Type_typelist f_traits_from_typedef(vx_core::Type_typedef vtypedef) {
    vx_core::Type_typelist output = vx_core::e_typelist();
    return output;
  }

  // (func traits<-typedef)
  // class Class_traits_from_typedef {
    Abstract_traits_from_typedef::~Abstract_traits_from_typedef() {}

    Class_traits_from_typedef::Class_traits_from_typedef() : Abstract_traits_from_typedef::Abstract_traits_from_typedef() {
      vx_core::refcount += 1;
    }
    Class_traits_from_typedef::~Class_traits_from_typedef() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_traits_from_typedef::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_traits_from_typedef output = vx_core::e_traits_from_typedef();
      return output;
    }

    vx_core::Type_any Class_traits_from_typedef::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_traits_from_typedef output = vx_core::e_traits_from_typedef();
      return output;
    }

    vx_core::Type_typedef Class_traits_from_typedef::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "typelist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_any()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_traits_from_typedef::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "traits<-typedef", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_traits_from_typedef::vx_empty() const {return vx_core::e_traits_from_typedef();}
    vx_core::Type_any Class_traits_from_typedef::vx_type() const {return vx_core::t_traits_from_typedef();}
    vx_core::Type_msgblock Class_traits_from_typedef::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_traits_from_typedef::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_traits_from_typedef::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_traits_from_typedef::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_typedef inputval = vx_core::vx_any_from_any(vx_core::t_typedef(), val);
      output = vx_core::f_traits_from_typedef(inputval);
      return output;
    }

    vx_core::Type_any Class_traits_from_typedef::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_typedef vtypedef = vx_core::vx_any_from_any(vx_core::t_typedef(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_traits_from_typedef(vtypedef);
      return output;
    }

  //}

  // (func type<-any)
  vx_core::Type_any f_type_from_any(vx_core::Type_any value) {
    vx_core::Type_any output = vx_core::e_any();
    return output;
  }

  // (func type<-any)
  // class Class_type_from_any {
    Abstract_type_from_any::~Abstract_type_from_any() {}

    Class_type_from_any::Class_type_from_any() : Abstract_type_from_any::Abstract_type_from_any() {
      vx_core::refcount += 1;
    }
    Class_type_from_any::~Class_type_from_any() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_type_from_any::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_type_from_any output = vx_core::e_type_from_any();
      return output;
    }

    vx_core::Type_any Class_type_from_any::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_type_from_any output = vx_core::e_type_from_any();
      return output;
    }

    vx_core::Type_typedef Class_type_from_any::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "any", // name
        "", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_type_from_any::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "type<-any", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_type_from_any::vx_empty() const {return vx_core::e_type_from_any();}
    vx_core::Type_any Class_type_from_any::vx_type() const {return vx_core::t_type_from_any();}
    vx_core::Type_msgblock Class_type_from_any::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_type_from_any::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_type_from_any::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_type_from_any::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any(), val);
      output = vx_core::f_type_from_any(inputval);
      return output;
    }

    vx_core::Type_any Class_type_from_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_type_from_any(value);
      return output;
    }

  //}

  // (func typedef<-any)
  vx_core::Type_typedef f_typedef_from_any(vx_core::Type_any val) {
    vx_core::Type_typedef output = vx_core::e_typedef();
    output = vx_core::f_typedef_from_type(
      vx_core::f_type_from_any(val)
    );
    return output;
  }

  // (func typedef<-any)
  // class Class_typedef_from_any {
    Abstract_typedef_from_any::~Abstract_typedef_from_any() {}

    Class_typedef_from_any::Class_typedef_from_any() : Abstract_typedef_from_any::Abstract_typedef_from_any() {
      vx_core::refcount += 1;
    }
    Class_typedef_from_any::~Class_typedef_from_any() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_typedef_from_any::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_typedef_from_any output = vx_core::e_typedef_from_any();
      return output;
    }

    vx_core::Type_any Class_typedef_from_any::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_typedef_from_any output = vx_core::e_typedef_from_any();
      return output;
    }

    vx_core::Type_typedef Class_typedef_from_any::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "typedef", // name
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
    }

    vx_core::Type_funcdef Class_typedef_from_any::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "typedef<-any", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_typedef_from_any::vx_empty() const {return vx_core::e_typedef_from_any();}
    vx_core::Type_any Class_typedef_from_any::vx_type() const {return vx_core::t_typedef_from_any();}
    vx_core::Type_msgblock Class_typedef_from_any::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_typedef_from_any::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_typedef_from_any::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_typedef_from_any::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any(), val);
      output = vx_core::f_typedef_from_any(inputval);
      return output;
    }

    vx_core::Type_any Class_typedef_from_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any val = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_typedef_from_any(val);
      return output;
    }

  //}

  // (func typedef<-type)
  vx_core::Type_typedef f_typedef_from_type(vx_core::Type_any val) {
    vx_core::Type_typedef output = vx_core::e_typedef();
    return output;
  }

  // (func typedef<-type)
  // class Class_typedef_from_type {
    Abstract_typedef_from_type::~Abstract_typedef_from_type() {}

    Class_typedef_from_type::Class_typedef_from_type() : Abstract_typedef_from_type::Abstract_typedef_from_type() {
      vx_core::refcount += 1;
    }
    Class_typedef_from_type::~Class_typedef_from_type() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_typedef_from_type::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_typedef_from_type output = vx_core::e_typedef_from_type();
      return output;
    }

    vx_core::Type_any Class_typedef_from_type::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_typedef_from_type output = vx_core::e_typedef_from_type();
      return output;
    }

    vx_core::Type_typedef Class_typedef_from_type::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "typedef", // name
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
    }

    vx_core::Type_funcdef Class_typedef_from_type::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "typedef<-type", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_typedef_from_type::vx_empty() const {return vx_core::e_typedef_from_type();}
    vx_core::Type_any Class_typedef_from_type::vx_type() const {return vx_core::t_typedef_from_type();}
    vx_core::Type_msgblock Class_typedef_from_type::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_typedef_from_type::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_typedef_from_type::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_typedef_from_type::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any(), val);
      output = vx_core::f_typedef_from_type(inputval);
      return output;
    }

    vx_core::Type_any Class_typedef_from_type::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any val = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_typedef_from_type(val);
      return output;
    }

  //}

  // (func typename<-any)
  vx_core::Type_string f_typename_from_any(vx_core::Type_any value) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_typename_from_type(
      vx_core::f_type_from_any(value)
    );
    return output;
  }

  // (func typename<-any)
  // class Class_typename_from_any {
    Abstract_typename_from_any::~Abstract_typename_from_any() {}

    Class_typename_from_any::Class_typename_from_any() : Abstract_typename_from_any::Abstract_typename_from_any() {
      vx_core::refcount += 1;
    }
    Class_typename_from_any::~Class_typename_from_any() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_typename_from_any::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_typename_from_any output = vx_core::e_typename_from_any();
      return output;
    }

    vx_core::Type_any Class_typename_from_any::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_typename_from_any output = vx_core::e_typename_from_any();
      return output;
    }

    vx_core::Type_typedef Class_typename_from_any::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "string", // name
        "string", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_typename_from_any::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "typename<-any", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_typename_from_any::vx_empty() const {return vx_core::e_typename_from_any();}
    vx_core::Type_any Class_typename_from_any::vx_type() const {return vx_core::t_typename_from_any();}
    vx_core::Type_msgblock Class_typename_from_any::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_typename_from_any::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_typename_from_any::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_typename_from_any::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any(), val);
      output = vx_core::f_typename_from_any(inputval);
      return output;
    }

    vx_core::Type_any Class_typename_from_any::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any value = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_typename_from_any(value);
      return output;
    }

  //}

  // (func typename<-type)
  vx_core::Type_string f_typename_from_type(vx_core::Type_any type) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_typename_from_typedef(
      vx_core::f_typedef_from_type(type)
    );
    return output;
  }

  // (func typename<-type)
  // class Class_typename_from_type {
    Abstract_typename_from_type::~Abstract_typename_from_type() {}

    Class_typename_from_type::Class_typename_from_type() : Abstract_typename_from_type::Abstract_typename_from_type() {
      vx_core::refcount += 1;
    }
    Class_typename_from_type::~Class_typename_from_type() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_typename_from_type::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_typename_from_type output = vx_core::e_typename_from_type();
      return output;
    }

    vx_core::Type_any Class_typename_from_type::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_typename_from_type output = vx_core::e_typename_from_type();
      return output;
    }

    vx_core::Type_typedef Class_typename_from_type::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "string", // name
        "string", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_typename_from_type::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "typename<-type", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_typename_from_type::vx_empty() const {return vx_core::e_typename_from_type();}
    vx_core::Type_any Class_typename_from_type::vx_type() const {return vx_core::t_typename_from_type();}
    vx_core::Type_msgblock Class_typename_from_type::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_typename_from_type::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_typename_from_type::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_typename_from_type::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any inputval = vx_core::vx_any_from_any(vx_core::t_any(), val);
      output = vx_core::f_typename_from_type(inputval);
      return output;
    }

    vx_core::Type_any Class_typename_from_type::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_any type = vx_core::vx_any_from_any(vx_core::t_any(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_typename_from_type(type);
      return output;
    }

  //}

  // (func typename<-typedef)
  vx_core::Type_string f_typename_from_typedef(vx_core::Type_typedef vtypedef) {
    vx_core::Type_string output = vx_core::e_string();
    output = vx_core::f_new(
      vx_core::t_string(),
      vx_core::vx_new(vx_core::t_anylist(), {
        vtypedef->pkgname(),
        vx_core::vx_new_string("/"),
        vtypedef->name()
      })
    );
    return output;
  }

  // (func typename<-typedef)
  // class Class_typename_from_typedef {
    Abstract_typename_from_typedef::~Abstract_typename_from_typedef() {}

    Class_typename_from_typedef::Class_typename_from_typedef() : Abstract_typename_from_typedef::Abstract_typename_from_typedef() {
      vx_core::refcount += 1;
    }
    Class_typename_from_typedef::~Class_typename_from_typedef() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_typename_from_typedef::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_typename_from_typedef output = vx_core::e_typename_from_typedef();
      return output;
    }

    vx_core::Type_any Class_typename_from_typedef::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_typename_from_typedef output = vx_core::e_typename_from_typedef();
      return output;
    }

    vx_core::Type_typedef Class_typename_from_typedef::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "string", // name
        "string", // extends
        vx_core::e_typelist(), // traits
        vx_core::e_typelist(), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_typename_from_typedef::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "typename<-typedef", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_typename_from_typedef::vx_empty() const {return vx_core::e_typename_from_typedef();}
    vx_core::Type_any Class_typename_from_typedef::vx_type() const {return vx_core::t_typename_from_typedef();}
    vx_core::Type_msgblock Class_typename_from_typedef::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_typename_from_typedef::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_typename_from_typedef::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_typename_from_typedef::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_typedef inputval = vx_core::vx_any_from_any(vx_core::t_typedef(), val);
      output = vx_core::f_typename_from_typedef(inputval);
      return output;
    }

    vx_core::Type_any Class_typename_from_typedef::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_typedef vtypedef = vx_core::vx_any_from_any(vx_core::t_typedef(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_typename_from_typedef(vtypedef);
      return output;
    }

  //}

  // (func typenames<-typelist)
  vx_core::Type_stringlist f_typenames_from_typelist(vx_core::Type_typelist typelist) {
    vx_core::Type_stringlist output = vx_core::e_stringlist();
    output = vx_core::f_list_from_list(
      vx_core::t_stringlist(),
      typelist,
      vx_core::t_any_from_any()->vx_fn_new([](vx_core::Type_any type_any) {
        vx_core::Type_any type = vx_core::vx_any_from_any(vx_core::t_any(), type_any);
        return 
          vx_core::f_typename_from_type(type);
      })
    );
    return output;
  }

  // (func typenames<-typelist)
  // class Class_typenames_from_typelist {
    Abstract_typenames_from_typelist::~Abstract_typenames_from_typelist() {}

    Class_typenames_from_typelist::Class_typenames_from_typelist() : Abstract_typenames_from_typelist::Abstract_typenames_from_typelist() {
      vx_core::refcount += 1;
    }
    Class_typenames_from_typelist::~Class_typenames_from_typelist() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_typenames_from_typelist::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_typenames_from_typelist output = vx_core::e_typenames_from_typelist();
      return output;
    }

    vx_core::Type_any Class_typenames_from_typelist::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_typenames_from_typelist output = vx_core::e_typenames_from_typelist();
      return output;
    }

    vx_core::Type_typedef Class_typenames_from_typelist::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "stringlist", // name
        ":list", // extends
        vx_core::e_typelist(), // traits
        vx_core::vx_new(vx_core::t_typelist(), {vx_core::t_string()}), // allowtypes
        vx_core::e_typelist(), // disallowtypes
        vx_core::e_funclist(), // allowfuncs
        vx_core::e_funclist(), // disallowfuncs
        vx_core::e_anylist(), // allowvalues
        vx_core::e_anylist(), // disallowvalues
        vx_core::e_argmap() // properties
      );
    }

    vx_core::Type_funcdef Class_typenames_from_typelist::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "typenames<-typelist", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_typenames_from_typelist::vx_empty() const {return vx_core::e_typenames_from_typelist();}
    vx_core::Type_any Class_typenames_from_typelist::vx_type() const {return vx_core::t_typenames_from_typelist();}
    vx_core::Type_msgblock Class_typenames_from_typelist::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_typenames_from_typelist::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_typenames_from_typelist::vx_fn_new(vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any();
    }

    vx_core::Type_any Class_typenames_from_typelist::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_typelist inputval = vx_core::vx_any_from_any(vx_core::t_typelist(), val);
      output = vx_core::f_typenames_from_typelist(inputval);
      return output;
    }

    vx_core::Type_any Class_typenames_from_typelist::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_typelist typelist = vx_core::vx_any_from_any(vx_core::t_typelist(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_typenames_from_typelist(typelist);
      return output;
    }

  //}

  // (func user<-context)
  vx_core::Type_user f_user_from_context(vx_core::Type_context context) {
    vx_core::Type_user output = vx_core::e_user();
    output = vx_core::f_session_from_context(context)->user();
    return output;
  }

  // (func user<-context)
  // class Class_user_from_context {
    Abstract_user_from_context::~Abstract_user_from_context() {}

    Class_user_from_context::Class_user_from_context() : Abstract_user_from_context::Abstract_user_from_context() {
      vx_core::refcount += 1;
    }
    Class_user_from_context::~Class_user_from_context() {
      vx_core::refcount -= 1;
    }
    vx_core::Type_any Class_user_from_context::vx_new(vx_core::vx_Type_listany vals) const {
      vx_core::Func_user_from_context output = vx_core::e_user_from_context();
      return output;
    }

    vx_core::Type_any Class_user_from_context::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_core::Func_user_from_context output = vx_core::e_user_from_context();
      return output;
    }

    vx_core::Type_typedef Class_user_from_context::vx_typedef() const {
      return vx_core::Class_typedef::vx_typedef_new(
        "vx/core", // pkgname
        "user", // name
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
    }

    vx_core::Type_funcdef Class_user_from_context::vx_funcdef() const {
      return vx_core::Class_funcdef::vx_funcdef_new(
        "vx/core", // pkgname
        "user<-context", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
    }

    vx_core::Type_any Class_user_from_context::vx_empty() const {return vx_core::e_user_from_context();}
    vx_core::Type_any Class_user_from_context::vx_type() const {return vx_core::t_user_from_context();}
    vx_core::Type_msgblock Class_user_from_context::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_user_from_context::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Type_any Class_user_from_context::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any();
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context(), arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_core::f_user_from_context(context);
      return output;
    }

  //}

  vx_core::vx_Class_package* vx_package = new vx_core::vx_Class_package();

  vx_core::Type_any e_any() {
    vx_core::Type_any output = vx_core::vx_package->e_any;
    if (output == NULL) {
      output = new Class_any();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_any = output;
    }
    return output;
  }
  vx_core::Type_any t_any() {
    vx_core::Type_any output = vx_core::vx_package->t_any;
    if (output == NULL) {
      output = new Class_any();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_any = output;
    }
    return output;
  }

  vx_core::Type_list e_list() {
    vx_core::Type_list output = vx_core::vx_package->e_list;
    if (output == NULL) {
      output = new Class_list();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_list = output;
    }
    return output;
  }
  vx_core::Type_list t_list() {
    vx_core::Type_list output = vx_core::vx_package->t_list;
    if (output == NULL) {
      output = new Class_list();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_list = output;
    }
    return output;
  }

  vx_core::Type_map e_map() {
    vx_core::Type_map output = vx_core::vx_package->e_map;
    if (output == NULL) {
      output = new Class_map();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_map = output;
    }
    return output;
  }
  vx_core::Type_map t_map() {
    vx_core::Type_map output = vx_core::vx_package->t_map;
    if (output == NULL) {
      output = new Class_map();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_map = output;
    }
    return output;
  }

  vx_core::Type_struct e_struct() {
    vx_core::Type_struct output = vx_core::vx_package->e_struct;
    if (output == NULL) {
      output = new Class_struct();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_struct = output;
    }
    return output;
  }
  vx_core::Type_struct t_struct() {
    vx_core::Type_struct output = vx_core::vx_package->t_struct;
    if (output == NULL) {
      output = new Class_struct();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_struct = output;
    }
    return output;
  }

  vx_core::Type_msg e_msg() {
    vx_core::Type_msg output = vx_core::vx_package->e_msg;
    if (output == NULL) {
      output = new Class_msg();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_msg = output;
    }
    return output;
  }
  vx_core::Type_msg t_msg() {
    vx_core::Type_msg output = vx_core::vx_package->t_msg;
    if (output == NULL) {
      output = new Class_msg();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_msg = output;
    }
    return output;
  }

  vx_core::Type_msglist e_msglist() {
    vx_core::Type_msglist output = vx_core::vx_package->e_msglist;
    if (output == NULL) {
      output = new Class_msglist();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_msglist = output;
    }
    return output;
  }
  vx_core::Type_msglist t_msglist() {
    vx_core::Type_msglist output = vx_core::vx_package->t_msglist;
    if (output == NULL) {
      output = new Class_msglist();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_msglist = output;
    }
    return output;
  }

  vx_core::Type_msgblock e_msgblock() {
    vx_core::Type_msgblock output = vx_core::vx_package->e_msgblock;
    if (output == NULL) {
      output = new Class_msgblock();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_msgblock = output;
    }
    return output;
  }
  vx_core::Type_msgblock t_msgblock() {
    vx_core::Type_msgblock output = vx_core::vx_package->t_msgblock;
    if (output == NULL) {
      output = new Class_msgblock();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_msgblock = output;
    }
    return output;
  }

  vx_core::Type_msgblocklist e_msgblocklist() {
    vx_core::Type_msgblocklist output = vx_core::vx_package->e_msgblocklist;
    if (output == NULL) {
      output = new Class_msgblocklist();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_msgblocklist = output;
    }
    return output;
  }
  vx_core::Type_msgblocklist t_msgblocklist() {
    vx_core::Type_msgblocklist output = vx_core::vx_package->t_msgblocklist;
    if (output == NULL) {
      output = new Class_msgblocklist();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_msgblocklist = output;
    }
    return output;
  }

  vx_core::Type_boolean e_boolean() {
    vx_core::Type_boolean output = vx_core::vx_package->e_boolean;
    if (output == NULL) {
      output = new Class_boolean();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_boolean = output;
    }
    return output;
  }
  vx_core::Type_boolean t_boolean() {
    vx_core::Type_boolean output = vx_core::vx_package->t_boolean;
    if (output == NULL) {
      output = new Class_boolean();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_boolean = output;
    }
    return output;
  }

  vx_core::Type_number e_number() {
    vx_core::Type_number output = vx_core::vx_package->e_number;
    if (output == NULL) {
      output = new Class_number();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_number = output;
    }
    return output;
  }
  vx_core::Type_number t_number() {
    vx_core::Type_number output = vx_core::vx_package->t_number;
    if (output == NULL) {
      output = new Class_number();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_number = output;
    }
    return output;
  }

  vx_core::Type_decimal e_decimal() {
    vx_core::Type_decimal output = vx_core::vx_package->e_decimal;
    if (output == NULL) {
      output = new Class_decimal();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_decimal = output;
    }
    return output;
  }
  vx_core::Type_decimal t_decimal() {
    vx_core::Type_decimal output = vx_core::vx_package->t_decimal;
    if (output == NULL) {
      output = new Class_decimal();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_decimal = output;
    }
    return output;
  }

  vx_core::Type_float e_float() {
    vx_core::Type_float output = vx_core::vx_package->e_float;
    if (output == NULL) {
      output = new Class_float();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_float = output;
    }
    return output;
  }
  vx_core::Type_float t_float() {
    vx_core::Type_float output = vx_core::vx_package->t_float;
    if (output == NULL) {
      output = new Class_float();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_float = output;
    }
    return output;
  }

  vx_core::Type_int e_int() {
    vx_core::Type_int output = vx_core::vx_package->e_int;
    if (output == NULL) {
      output = new Class_int();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_int = output;
    }
    return output;
  }
  vx_core::Type_int t_int() {
    vx_core::Type_int output = vx_core::vx_package->t_int;
    if (output == NULL) {
      output = new Class_int();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_int = output;
    }
    return output;
  }

  vx_core::Type_string e_string() {
    vx_core::Type_string output = vx_core::vx_package->e_string;
    if (output == NULL) {
      output = new Class_string();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_string = output;
    }
    return output;
  }
  vx_core::Type_string t_string() {
    vx_core::Type_string output = vx_core::vx_package->t_string;
    if (output == NULL) {
      output = new Class_string();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_string = output;
    }
    return output;
  }

  vx_core::Type_func e_func() {
    vx_core::Type_func output = vx_core::vx_package->e_func;
    if (output == NULL) {
      output = new Class_func();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_func = output;
    }
    return output;
  }
  vx_core::Type_func t_func() {
    vx_core::Type_func output = vx_core::vx_package->t_func;
    if (output == NULL) {
      output = new Class_func();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_func = output;
    }
    return output;
  }

  vx_core::Type_typedef e_typedef() {
    vx_core::Type_typedef output = vx_core::vx_package->e_typedef;
    if (output == NULL) {
      output = new Class_typedef();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_typedef = output;
    }
    return output;
  }
  vx_core::Type_typedef t_typedef() {
    vx_core::Type_typedef output = vx_core::vx_package->t_typedef;
    if (output == NULL) {
      output = new Class_typedef();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_typedef = output;
    }
    return output;
  }

  vx_core::Type_funcdef e_funcdef() {
    vx_core::Type_funcdef output = vx_core::vx_package->e_funcdef;
    if (output == NULL) {
      output = new Class_funcdef();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_funcdef = output;
    }
    return output;
  }
  vx_core::Type_funcdef t_funcdef() {
    vx_core::Type_funcdef output = vx_core::vx_package->t_funcdef;
    if (output == NULL) {
      output = new Class_funcdef();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_funcdef = output;
    }
    return output;
  }

  vx_core::Type_any_async_from_func e_any_async_from_func() {
    vx_core::Type_any_async_from_func output = vx_core::vx_package->e_any_async_from_func;
    if (output == NULL) {
      output = new Class_any_async_from_func();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_any_async_from_func = output;
    }
    return output;
  }
  vx_core::Type_any_async_from_func t_any_async_from_func() {
    vx_core::Type_any_async_from_func output = vx_core::vx_package->t_any_async_from_func;
    if (output == NULL) {
      output = new Class_any_async_from_func();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_any_async_from_func = output;
    }
    return output;
  }

  vx_core::Type_any_from_anylist e_any_from_anylist() {
    vx_core::Type_any_from_anylist output = vx_core::vx_package->e_any_from_anylist;
    if (output == NULL) {
      output = new Class_any_from_anylist();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_any_from_anylist = output;
    }
    return output;
  }
  vx_core::Type_any_from_anylist t_any_from_anylist() {
    vx_core::Type_any_from_anylist output = vx_core::vx_package->t_any_from_anylist;
    if (output == NULL) {
      output = new Class_any_from_anylist();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_any_from_anylist = output;
    }
    return output;
  }

  vx_core::Type_anylist e_anylist() {
    vx_core::Type_anylist output = vx_core::vx_package->e_anylist;
    if (output == NULL) {
      output = new Class_anylist();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_anylist = output;
    }
    return output;
  }
  vx_core::Type_anylist t_anylist() {
    vx_core::Type_anylist output = vx_core::vx_package->t_anylist;
    if (output == NULL) {
      output = new Class_anylist();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_anylist = output;
    }
    return output;
  }

  vx_core::Type_anytype e_anytype() {
    vx_core::Type_anytype output = vx_core::vx_package->e_anytype;
    if (output == NULL) {
      output = new Class_anytype();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_anytype = output;
    }
    return output;
  }
  vx_core::Type_anytype t_anytype() {
    vx_core::Type_anytype output = vx_core::vx_package->t_anytype;
    if (output == NULL) {
      output = new Class_anytype();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_anytype = output;
    }
    return output;
  }

  vx_core::Type_arg e_arg() {
    vx_core::Type_arg output = vx_core::vx_package->e_arg;
    if (output == NULL) {
      output = new Class_arg();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_arg = output;
    }
    return output;
  }
  vx_core::Type_arg t_arg() {
    vx_core::Type_arg output = vx_core::vx_package->t_arg;
    if (output == NULL) {
      output = new Class_arg();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_arg = output;
    }
    return output;
  }

  vx_core::Type_arglist e_arglist() {
    vx_core::Type_arglist output = vx_core::vx_package->e_arglist;
    if (output == NULL) {
      output = new Class_arglist();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_arglist = output;
    }
    return output;
  }
  vx_core::Type_arglist t_arglist() {
    vx_core::Type_arglist output = vx_core::vx_package->t_arglist;
    if (output == NULL) {
      output = new Class_arglist();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_arglist = output;
    }
    return output;
  }

  vx_core::Type_argmap e_argmap() {
    vx_core::Type_argmap output = vx_core::vx_package->e_argmap;
    if (output == NULL) {
      output = new Class_argmap();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_argmap = output;
    }
    return output;
  }
  vx_core::Type_argmap t_argmap() {
    vx_core::Type_argmap output = vx_core::vx_package->t_argmap;
    if (output == NULL) {
      output = new Class_argmap();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_argmap = output;
    }
    return output;
  }

  vx_core::Type_booleanlist e_booleanlist() {
    vx_core::Type_booleanlist output = vx_core::vx_package->e_booleanlist;
    if (output == NULL) {
      output = new Class_booleanlist();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_booleanlist = output;
    }
    return output;
  }
  vx_core::Type_booleanlist t_booleanlist() {
    vx_core::Type_booleanlist output = vx_core::vx_package->t_booleanlist;
    if (output == NULL) {
      output = new Class_booleanlist();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_booleanlist = output;
    }
    return output;
  }

  vx_core::Type_collection e_collection() {
    vx_core::Type_collection output = vx_core::vx_package->e_collection;
    if (output == NULL) {
      output = new Class_collection();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_collection = output;
    }
    return output;
  }
  vx_core::Type_collection t_collection() {
    vx_core::Type_collection output = vx_core::vx_package->t_collection;
    if (output == NULL) {
      output = new Class_collection();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_collection = output;
    }
    return output;
  }

  vx_core::Type_compilelanguages e_compilelanguages() {
    vx_core::Type_compilelanguages output = vx_core::vx_package->e_compilelanguages;
    if (output == NULL) {
      output = new Class_compilelanguages();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_compilelanguages = output;
    }
    return output;
  }
  vx_core::Type_compilelanguages t_compilelanguages() {
    vx_core::Type_compilelanguages output = vx_core::vx_package->t_compilelanguages;
    if (output == NULL) {
      output = new Class_compilelanguages();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_compilelanguages = output;
    }
    return output;
  }

  vx_core::Type_connect e_connect() {
    vx_core::Type_connect output = vx_core::vx_package->e_connect;
    if (output == NULL) {
      output = new Class_connect();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_connect = output;
    }
    return output;
  }
  vx_core::Type_connect t_connect() {
    vx_core::Type_connect output = vx_core::vx_package->t_connect;
    if (output == NULL) {
      output = new Class_connect();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_connect = output;
    }
    return output;
  }

  vx_core::Type_connectlist e_connectlist() {
    vx_core::Type_connectlist output = vx_core::vx_package->e_connectlist;
    if (output == NULL) {
      output = new Class_connectlist();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_connectlist = output;
    }
    return output;
  }
  vx_core::Type_connectlist t_connectlist() {
    vx_core::Type_connectlist output = vx_core::vx_package->t_connectlist;
    if (output == NULL) {
      output = new Class_connectlist();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_connectlist = output;
    }
    return output;
  }

  vx_core::Type_connectmap e_connectmap() {
    vx_core::Type_connectmap output = vx_core::vx_package->e_connectmap;
    if (output == NULL) {
      output = new Class_connectmap();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_connectmap = output;
    }
    return output;
  }
  vx_core::Type_connectmap t_connectmap() {
    vx_core::Type_connectmap output = vx_core::vx_package->t_connectmap;
    if (output == NULL) {
      output = new Class_connectmap();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_connectmap = output;
    }
    return output;
  }

  vx_core::Type_const e_const() {
    vx_core::Type_const output = vx_core::vx_package->e_const;
    if (output == NULL) {
      output = new Class_const();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_const = output;
    }
    return output;
  }
  vx_core::Type_const t_const() {
    vx_core::Type_const output = vx_core::vx_package->t_const;
    if (output == NULL) {
      output = new Class_const();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_const = output;
    }
    return output;
  }

  vx_core::Type_constdef e_constdef() {
    vx_core::Type_constdef output = vx_core::vx_package->e_constdef;
    if (output == NULL) {
      output = new Class_constdef();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_constdef = output;
    }
    return output;
  }
  vx_core::Type_constdef t_constdef() {
    vx_core::Type_constdef output = vx_core::vx_package->t_constdef;
    if (output == NULL) {
      output = new Class_constdef();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_constdef = output;
    }
    return output;
  }

  vx_core::Type_constlist e_constlist() {
    vx_core::Type_constlist output = vx_core::vx_package->e_constlist;
    if (output == NULL) {
      output = new Class_constlist();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_constlist = output;
    }
    return output;
  }
  vx_core::Type_constlist t_constlist() {
    vx_core::Type_constlist output = vx_core::vx_package->t_constlist;
    if (output == NULL) {
      output = new Class_constlist();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_constlist = output;
    }
    return output;
  }

  vx_core::Type_constmap e_constmap() {
    vx_core::Type_constmap output = vx_core::vx_package->e_constmap;
    if (output == NULL) {
      output = new Class_constmap();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_constmap = output;
    }
    return output;
  }
  vx_core::Type_constmap t_constmap() {
    vx_core::Type_constmap output = vx_core::vx_package->t_constmap;
    if (output == NULL) {
      output = new Class_constmap();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_constmap = output;
    }
    return output;
  }

  vx_core::Type_context e_context() {
    vx_core::Type_context output = vx_core::vx_package->e_context;
    if (output == NULL) {
      output = new Class_context();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_context = output;
    }
    return output;
  }
  vx_core::Type_context t_context() {
    vx_core::Type_context output = vx_core::vx_package->t_context;
    if (output == NULL) {
      output = new Class_context();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_context = output;
    }
    return output;
  }

  vx_core::Type_error e_error() {
    vx_core::Type_error output = vx_core::vx_package->e_error;
    if (output == NULL) {
      output = new Class_error();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_error = output;
    }
    return output;
  }
  vx_core::Type_error t_error() {
    vx_core::Type_error output = vx_core::vx_package->t_error;
    if (output == NULL) {
      output = new Class_error();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_error = output;
    }
    return output;
  }

  vx_core::Type_funclist e_funclist() {
    vx_core::Type_funclist output = vx_core::vx_package->e_funclist;
    if (output == NULL) {
      output = new Class_funclist();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_funclist = output;
    }
    return output;
  }
  vx_core::Type_funclist t_funclist() {
    vx_core::Type_funclist output = vx_core::vx_package->t_funclist;
    if (output == NULL) {
      output = new Class_funclist();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_funclist = output;
    }
    return output;
  }

  vx_core::Type_funcmap e_funcmap() {
    vx_core::Type_funcmap output = vx_core::vx_package->e_funcmap;
    if (output == NULL) {
      output = new Class_funcmap();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_funcmap = output;
    }
    return output;
  }
  vx_core::Type_funcmap t_funcmap() {
    vx_core::Type_funcmap output = vx_core::vx_package->t_funcmap;
    if (output == NULL) {
      output = new Class_funcmap();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_funcmap = output;
    }
    return output;
  }

  vx_core::Type_intlist e_intlist() {
    vx_core::Type_intlist output = vx_core::vx_package->e_intlist;
    if (output == NULL) {
      output = new Class_intlist();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_intlist = output;
    }
    return output;
  }
  vx_core::Type_intlist t_intlist() {
    vx_core::Type_intlist output = vx_core::vx_package->t_intlist;
    if (output == NULL) {
      output = new Class_intlist();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_intlist = output;
    }
    return output;
  }

  vx_core::Type_intmap e_intmap() {
    vx_core::Type_intmap output = vx_core::vx_package->e_intmap;
    if (output == NULL) {
      output = new Class_intmap();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_intmap = output;
    }
    return output;
  }
  vx_core::Type_intmap t_intmap() {
    vx_core::Type_intmap output = vx_core::vx_package->t_intmap;
    if (output == NULL) {
      output = new Class_intmap();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_intmap = output;
    }
    return output;
  }

  vx_core::Type_listtype e_listtype() {
    vx_core::Type_listtype output = vx_core::vx_package->e_listtype;
    if (output == NULL) {
      output = new Class_listtype();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_listtype = output;
    }
    return output;
  }
  vx_core::Type_listtype t_listtype() {
    vx_core::Type_listtype output = vx_core::vx_package->t_listtype;
    if (output == NULL) {
      output = new Class_listtype();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_listtype = output;
    }
    return output;
  }

  vx_core::Type_maptype e_maptype() {
    vx_core::Type_maptype output = vx_core::vx_package->e_maptype;
    if (output == NULL) {
      output = new Class_maptype();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_maptype = output;
    }
    return output;
  }
  vx_core::Type_maptype t_maptype() {
    vx_core::Type_maptype output = vx_core::vx_package->t_maptype;
    if (output == NULL) {
      output = new Class_maptype();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_maptype = output;
    }
    return output;
  }

  vx_core::Type_mempool e_mempool() {
    vx_core::Type_mempool output = vx_core::vx_package->e_mempool;
    if (output == NULL) {
      output = new Class_mempool();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_mempool = output;
    }
    return output;
  }
  vx_core::Type_mempool t_mempool() {
    vx_core::Type_mempool output = vx_core::vx_package->t_mempool;
    if (output == NULL) {
      output = new Class_mempool();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_mempool = output;
    }
    return output;
  }

  vx_core::Type_none e_none() {
    vx_core::Type_none output = vx_core::vx_package->e_none;
    if (output == NULL) {
      output = new Class_none();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_none = output;
    }
    return output;
  }
  vx_core::Type_none t_none() {
    vx_core::Type_none output = vx_core::vx_package->t_none;
    if (output == NULL) {
      output = new Class_none();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_none = output;
    }
    return output;
  }

  vx_core::Type_notype e_notype() {
    vx_core::Type_notype output = vx_core::vx_package->e_notype;
    if (output == NULL) {
      output = new Class_notype();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_notype = output;
    }
    return output;
  }
  vx_core::Type_notype t_notype() {
    vx_core::Type_notype output = vx_core::vx_package->t_notype;
    if (output == NULL) {
      output = new Class_notype();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_notype = output;
    }
    return output;
  }

  vx_core::Type_numberlist e_numberlist() {
    vx_core::Type_numberlist output = vx_core::vx_package->e_numberlist;
    if (output == NULL) {
      output = new Class_numberlist();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_numberlist = output;
    }
    return output;
  }
  vx_core::Type_numberlist t_numberlist() {
    vx_core::Type_numberlist output = vx_core::vx_package->t_numberlist;
    if (output == NULL) {
      output = new Class_numberlist();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_numberlist = output;
    }
    return output;
  }

  vx_core::Type_numbermap e_numbermap() {
    vx_core::Type_numbermap output = vx_core::vx_package->e_numbermap;
    if (output == NULL) {
      output = new Class_numbermap();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_numbermap = output;
    }
    return output;
  }
  vx_core::Type_numbermap t_numbermap() {
    vx_core::Type_numbermap output = vx_core::vx_package->t_numbermap;
    if (output == NULL) {
      output = new Class_numbermap();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_numbermap = output;
    }
    return output;
  }

  vx_core::Type_package e_package() {
    vx_core::Type_package output = vx_core::vx_package->e_package;
    if (output == NULL) {
      output = new Class_package();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_package = output;
    }
    return output;
  }
  vx_core::Type_package t_package() {
    vx_core::Type_package output = vx_core::vx_package->t_package;
    if (output == NULL) {
      output = new Class_package();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_package = output;
    }
    return output;
  }

  vx_core::Type_packagemap e_packagemap() {
    vx_core::Type_packagemap output = vx_core::vx_package->e_packagemap;
    if (output == NULL) {
      output = new Class_packagemap();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_packagemap = output;
    }
    return output;
  }
  vx_core::Type_packagemap t_packagemap() {
    vx_core::Type_packagemap output = vx_core::vx_package->t_packagemap;
    if (output == NULL) {
      output = new Class_packagemap();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_packagemap = output;
    }
    return output;
  }

  vx_core::Type_permission e_permission() {
    vx_core::Type_permission output = vx_core::vx_package->e_permission;
    if (output == NULL) {
      output = new Class_permission();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_permission = output;
    }
    return output;
  }
  vx_core::Type_permission t_permission() {
    vx_core::Type_permission output = vx_core::vx_package->t_permission;
    if (output == NULL) {
      output = new Class_permission();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_permission = output;
    }
    return output;
  }

  vx_core::Type_permissionlist e_permissionlist() {
    vx_core::Type_permissionlist output = vx_core::vx_package->e_permissionlist;
    if (output == NULL) {
      output = new Class_permissionlist();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_permissionlist = output;
    }
    return output;
  }
  vx_core::Type_permissionlist t_permissionlist() {
    vx_core::Type_permissionlist output = vx_core::vx_package->t_permissionlist;
    if (output == NULL) {
      output = new Class_permissionlist();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_permissionlist = output;
    }
    return output;
  }

  vx_core::Type_permissionmap e_permissionmap() {
    vx_core::Type_permissionmap output = vx_core::vx_package->e_permissionmap;
    if (output == NULL) {
      output = new Class_permissionmap();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_permissionmap = output;
    }
    return output;
  }
  vx_core::Type_permissionmap t_permissionmap() {
    vx_core::Type_permissionmap output = vx_core::vx_package->t_permissionmap;
    if (output == NULL) {
      output = new Class_permissionmap();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_permissionmap = output;
    }
    return output;
  }

  vx_core::Type_security e_security() {
    vx_core::Type_security output = vx_core::vx_package->e_security;
    if (output == NULL) {
      output = new Class_security();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_security = output;
    }
    return output;
  }
  vx_core::Type_security t_security() {
    vx_core::Type_security output = vx_core::vx_package->t_security;
    if (output == NULL) {
      output = new Class_security();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_security = output;
    }
    return output;
  }

  vx_core::Type_session e_session() {
    vx_core::Type_session output = vx_core::vx_package->e_session;
    if (output == NULL) {
      output = new Class_session();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_session = output;
    }
    return output;
  }
  vx_core::Type_session t_session() {
    vx_core::Type_session output = vx_core::vx_package->t_session;
    if (output == NULL) {
      output = new Class_session();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_session = output;
    }
    return output;
  }

  vx_core::Type_setting e_setting() {
    vx_core::Type_setting output = vx_core::vx_package->e_setting;
    if (output == NULL) {
      output = new Class_setting();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_setting = output;
    }
    return output;
  }
  vx_core::Type_setting t_setting() {
    vx_core::Type_setting output = vx_core::vx_package->t_setting;
    if (output == NULL) {
      output = new Class_setting();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_setting = output;
    }
    return output;
  }

  vx_core::Type_state e_state() {
    vx_core::Type_state output = vx_core::vx_package->e_state;
    if (output == NULL) {
      output = new Class_state();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_state = output;
    }
    return output;
  }
  vx_core::Type_state t_state() {
    vx_core::Type_state output = vx_core::vx_package->t_state;
    if (output == NULL) {
      output = new Class_state();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_state = output;
    }
    return output;
  }

  vx_core::Type_statelistener e_statelistener() {
    vx_core::Type_statelistener output = vx_core::vx_package->e_statelistener;
    if (output == NULL) {
      output = new Class_statelistener();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_statelistener = output;
    }
    return output;
  }
  vx_core::Type_statelistener t_statelistener() {
    vx_core::Type_statelistener output = vx_core::vx_package->t_statelistener;
    if (output == NULL) {
      output = new Class_statelistener();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_statelistener = output;
    }
    return output;
  }

  vx_core::Type_stringlist e_stringlist() {
    vx_core::Type_stringlist output = vx_core::vx_package->e_stringlist;
    if (output == NULL) {
      output = new Class_stringlist();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_stringlist = output;
    }
    return output;
  }
  vx_core::Type_stringlist t_stringlist() {
    vx_core::Type_stringlist output = vx_core::vx_package->t_stringlist;
    if (output == NULL) {
      output = new Class_stringlist();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_stringlist = output;
    }
    return output;
  }

  vx_core::Type_stringmap e_stringmap() {
    vx_core::Type_stringmap output = vx_core::vx_package->e_stringmap;
    if (output == NULL) {
      output = new Class_stringmap();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_stringmap = output;
    }
    return output;
  }
  vx_core::Type_stringmap t_stringmap() {
    vx_core::Type_stringmap output = vx_core::vx_package->t_stringmap;
    if (output == NULL) {
      output = new Class_stringmap();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_stringmap = output;
    }
    return output;
  }

  vx_core::Type_thenelse e_thenelse() {
    vx_core::Type_thenelse output = vx_core::vx_package->e_thenelse;
    if (output == NULL) {
      output = new Class_thenelse();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_thenelse = output;
    }
    return output;
  }
  vx_core::Type_thenelse t_thenelse() {
    vx_core::Type_thenelse output = vx_core::vx_package->t_thenelse;
    if (output == NULL) {
      output = new Class_thenelse();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_thenelse = output;
    }
    return output;
  }

  vx_core::Type_thenelselist e_thenelselist() {
    vx_core::Type_thenelselist output = vx_core::vx_package->e_thenelselist;
    if (output == NULL) {
      output = new Class_thenelselist();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_thenelselist = output;
    }
    return output;
  }
  vx_core::Type_thenelselist t_thenelselist() {
    vx_core::Type_thenelselist output = vx_core::vx_package->t_thenelselist;
    if (output == NULL) {
      output = new Class_thenelselist();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_thenelselist = output;
    }
    return output;
  }

  vx_core::Type_type e_type() {
    vx_core::Type_type output = vx_core::vx_package->e_type;
    if (output == NULL) {
      output = new Class_type();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_type = output;
    }
    return output;
  }
  vx_core::Type_type t_type() {
    vx_core::Type_type output = vx_core::vx_package->t_type;
    if (output == NULL) {
      output = new Class_type();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_type = output;
    }
    return output;
  }

  vx_core::Type_typelist e_typelist() {
    vx_core::Type_typelist output = vx_core::vx_package->e_typelist;
    if (output == NULL) {
      output = new Class_typelist();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_typelist = output;
    }
    return output;
  }
  vx_core::Type_typelist t_typelist() {
    vx_core::Type_typelist output = vx_core::vx_package->t_typelist;
    if (output == NULL) {
      output = new Class_typelist();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_typelist = output;
    }
    return output;
  }

  vx_core::Type_typemap e_typemap() {
    vx_core::Type_typemap output = vx_core::vx_package->e_typemap;
    if (output == NULL) {
      output = new Class_typemap();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_typemap = output;
    }
    return output;
  }
  vx_core::Type_typemap t_typemap() {
    vx_core::Type_typemap output = vx_core::vx_package->t_typemap;
    if (output == NULL) {
      output = new Class_typemap();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_typemap = output;
    }
    return output;
  }

  vx_core::Type_user e_user() {
    vx_core::Type_user output = vx_core::vx_package->e_user;
    if (output == NULL) {
      output = new Class_user();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_user = output;
    }
    return output;
  }
  vx_core::Type_user t_user() {
    vx_core::Type_user output = vx_core::vx_package->t_user;
    if (output == NULL) {
      output = new Class_user();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_user = output;
    }
    return output;
  }

  vx_core::Type_value e_value() {
    vx_core::Type_value output = vx_core::vx_package->e_value;
    if (output == NULL) {
      output = new Class_value();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_value = output;
    }
    return output;
  }
  vx_core::Type_value t_value() {
    vx_core::Type_value output = vx_core::vx_package->t_value;
    if (output == NULL) {
      output = new Class_value();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_value = output;
    }
    return output;
  }

  // (const false)
  vx_core::Const_false c_false() {
    vx_core::Const_false output = vx_core::vx_package->c_false;
    if (output == NULL) {
      output = new vx_core::Class_false();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->c_false = output;
    }
    return output;
  }

  // (const globalpackagemap)
  vx_core::Const_globalpackagemap c_globalpackagemap() {
    vx_core::Const_globalpackagemap output = vx_core::vx_package->c_globalpackagemap;
    if (output == NULL) {
      output = new vx_core::Class_globalpackagemap();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->c_globalpackagemap = output;
    }
    return output;
  }

  // (const infinity)
  vx_core::Const_infinity c_infinity() {
    vx_core::Const_infinity output = vx_core::vx_package->c_infinity;
    if (output == NULL) {
      output = new vx_core::Class_infinity();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->c_infinity = output;
    }
    return output;
  }

  // (const mempool-active)
  vx_core::Const_mempool_active c_mempool_active() {
    vx_core::Const_mempool_active output = vx_core::vx_package->c_mempool_active;
    if (output == NULL) {
      output = new vx_core::Class_mempool_active();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->c_mempool_active = output;
    }
    return output;
  }

  // (const msg-error)
  vx_core::Const_msg_error c_msg_error() {
    vx_core::Const_msg_error output = vx_core::vx_package->c_msg_error;
    if (output == NULL) {
      output = new vx_core::Class_msg_error();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->c_msg_error = output;
    }
    return output;
  }

  // (const msg-info)
  vx_core::Const_msg_info c_msg_info() {
    vx_core::Const_msg_info output = vx_core::vx_package->c_msg_info;
    if (output == NULL) {
      output = new vx_core::Class_msg_info();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->c_msg_info = output;
    }
    return output;
  }

  // (const msg-severe)
  vx_core::Const_msg_severe c_msg_severe() {
    vx_core::Const_msg_severe output = vx_core::vx_package->c_msg_severe;
    if (output == NULL) {
      output = new vx_core::Class_msg_severe();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->c_msg_severe = output;
    }
    return output;
  }

  // (const msg-warning)
  vx_core::Const_msg_warning c_msg_warning() {
    vx_core::Const_msg_warning output = vx_core::vx_package->c_msg_warning;
    if (output == NULL) {
      output = new vx_core::Class_msg_warning();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->c_msg_warning = output;
    }
    return output;
  }

  // (const neginfinity)
  vx_core::Const_neginfinity c_neginfinity() {
    vx_core::Const_neginfinity output = vx_core::vx_package->c_neginfinity;
    if (output == NULL) {
      output = new vx_core::Class_neginfinity();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->c_neginfinity = output;
    }
    return output;
  }

  // (const newline)
  vx_core::Const_newline c_newline() {
    vx_core::Const_newline output = vx_core::vx_package->c_newline;
    if (output == NULL) {
      output = new vx_core::Class_newline();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->c_newline = output;
    }
    return output;
  }

  // (const notanumber)
  vx_core::Const_notanumber c_notanumber() {
    vx_core::Const_notanumber output = vx_core::vx_package->c_notanumber;
    if (output == NULL) {
      output = new vx_core::Class_notanumber();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->c_notanumber = output;
    }
    return output;
  }

  // (const nothing)
  vx_core::Const_nothing c_nothing() {
    vx_core::Const_nothing output = vx_core::vx_package->c_nothing;
    if (output == NULL) {
      output = new vx_core::Class_nothing();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->c_nothing = output;
    }
    return output;
  }

  // (const quote)
  vx_core::Const_quote c_quote() {
    vx_core::Const_quote output = vx_core::vx_package->c_quote;
    if (output == NULL) {
      output = new vx_core::Class_quote();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->c_quote = output;
    }
    return output;
  }

  // (const true)
  vx_core::Const_true c_true() {
    vx_core::Const_true output = vx_core::vx_package->c_true;
    if (output == NULL) {
      output = new vx_core::Class_true();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->c_true = output;
    }
    return output;
  }

  // (func any<-any)
  vx_core::Func_any_from_any e_any_from_any() {
    vx_core::Func_any_from_any output = vx_core::vx_package->e_any_from_any;
    if (output == NULL) {
      output = new vx_core::Class_any_from_any();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_any_from_any = output;
    }
    return output;
  }
  vx_core::Func_any_from_any t_any_from_any() {
    vx_core::Func_any_from_any output = vx_core::vx_package->t_any_from_any;
    if (output == NULL) {
      output = new vx_core::Class_any_from_any();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_any_from_any = output;
    }
    return output;
  }

  // (func any<-any-async)
  vx_core::Func_any_from_any_async e_any_from_any_async() {
    vx_core::Func_any_from_any_async output = vx_core::vx_package->e_any_from_any_async;
    if (output == NULL) {
      output = new vx_core::Class_any_from_any_async();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_any_from_any_async = output;
    }
    return output;
  }
  vx_core::Func_any_from_any_async t_any_from_any_async() {
    vx_core::Func_any_from_any_async output = vx_core::vx_package->t_any_from_any_async;
    if (output == NULL) {
      output = new vx_core::Class_any_from_any_async();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_any_from_any_async = output;
    }
    return output;
  }

  // (func any<-any-context)
  vx_core::Func_any_from_any_context e_any_from_any_context() {
    vx_core::Func_any_from_any_context output = vx_core::vx_package->e_any_from_any_context;
    if (output == NULL) {
      output = new vx_core::Class_any_from_any_context();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_any_from_any_context = output;
    }
    return output;
  }
  vx_core::Func_any_from_any_context t_any_from_any_context() {
    vx_core::Func_any_from_any_context output = vx_core::vx_package->t_any_from_any_context;
    if (output == NULL) {
      output = new vx_core::Class_any_from_any_context();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_any_from_any_context = output;
    }
    return output;
  }

  // (func any<-any-context-async)
  vx_core::Func_any_from_any_context_async e_any_from_any_context_async() {
    vx_core::Func_any_from_any_context_async output = vx_core::vx_package->e_any_from_any_context_async;
    if (output == NULL) {
      output = new vx_core::Class_any_from_any_context_async();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_any_from_any_context_async = output;
    }
    return output;
  }
  vx_core::Func_any_from_any_context_async t_any_from_any_context_async() {
    vx_core::Func_any_from_any_context_async output = vx_core::vx_package->t_any_from_any_context_async;
    if (output == NULL) {
      output = new vx_core::Class_any_from_any_context_async();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_any_from_any_context_async = output;
    }
    return output;
  }

  // (func any<-func)
  vx_core::Func_any_from_func e_any_from_func() {
    vx_core::Func_any_from_func output = vx_core::vx_package->e_any_from_func;
    if (output == NULL) {
      output = new vx_core::Class_any_from_func();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_any_from_func = output;
    }
    return output;
  }
  vx_core::Func_any_from_func t_any_from_func() {
    vx_core::Func_any_from_func output = vx_core::vx_package->t_any_from_func;
    if (output == NULL) {
      output = new vx_core::Class_any_from_func();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_any_from_func = output;
    }
    return output;
  }

  // (func any<-func-async)
  vx_core::Func_any_from_func_async e_any_from_func_async() {
    vx_core::Func_any_from_func_async output = vx_core::vx_package->e_any_from_func_async;
    if (output == NULL) {
      output = new vx_core::Class_any_from_func_async();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_any_from_func_async = output;
    }
    return output;
  }
  vx_core::Func_any_from_func_async t_any_from_func_async() {
    vx_core::Func_any_from_func_async output = vx_core::vx_package->t_any_from_func_async;
    if (output == NULL) {
      output = new vx_core::Class_any_from_func_async();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_any_from_func_async = output;
    }
    return output;
  }

  // (func any<-key-value)
  vx_core::Func_any_from_key_value e_any_from_key_value() {
    vx_core::Func_any_from_key_value output = vx_core::vx_package->e_any_from_key_value;
    if (output == NULL) {
      output = new vx_core::Class_any_from_key_value();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_any_from_key_value = output;
    }
    return output;
  }
  vx_core::Func_any_from_key_value t_any_from_key_value() {
    vx_core::Func_any_from_key_value output = vx_core::vx_package->t_any_from_key_value;
    if (output == NULL) {
      output = new vx_core::Class_any_from_key_value();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_any_from_key_value = output;
    }
    return output;
  }

  // (func any<-key-value-async)
  vx_core::Func_any_from_key_value_async e_any_from_key_value_async() {
    vx_core::Func_any_from_key_value_async output = vx_core::vx_package->e_any_from_key_value_async;
    if (output == NULL) {
      output = new vx_core::Class_any_from_key_value_async();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_any_from_key_value_async = output;
    }
    return output;
  }
  vx_core::Func_any_from_key_value_async t_any_from_key_value_async() {
    vx_core::Func_any_from_key_value_async output = vx_core::vx_package->t_any_from_key_value_async;
    if (output == NULL) {
      output = new vx_core::Class_any_from_key_value_async();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_any_from_key_value_async = output;
    }
    return output;
  }

  // (func any<-list)
  vx_core::Func_any_from_list e_any_from_list() {
    vx_core::Func_any_from_list output = vx_core::vx_package->e_any_from_list;
    if (output == NULL) {
      output = new vx_core::Class_any_from_list();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_any_from_list = output;
    }
    return output;
  }
  vx_core::Func_any_from_list t_any_from_list() {
    vx_core::Func_any_from_list output = vx_core::vx_package->t_any_from_list;
    if (output == NULL) {
      output = new vx_core::Class_any_from_list();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_any_from_list = output;
    }
    return output;
  }

  // (func any<-list-reduce)
  vx_core::Func_any_from_list_reduce e_any_from_list_reduce() {
    vx_core::Func_any_from_list_reduce output = vx_core::vx_package->e_any_from_list_reduce;
    if (output == NULL) {
      output = new vx_core::Class_any_from_list_reduce();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_any_from_list_reduce = output;
    }
    return output;
  }
  vx_core::Func_any_from_list_reduce t_any_from_list_reduce() {
    vx_core::Func_any_from_list_reduce output = vx_core::vx_package->t_any_from_list_reduce;
    if (output == NULL) {
      output = new vx_core::Class_any_from_list_reduce();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_any_from_list_reduce = output;
    }
    return output;
  }

  // (func any<-list-reduce-next)
  vx_core::Func_any_from_list_reduce_next e_any_from_list_reduce_next() {
    vx_core::Func_any_from_list_reduce_next output = vx_core::vx_package->e_any_from_list_reduce_next;
    if (output == NULL) {
      output = new vx_core::Class_any_from_list_reduce_next();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_any_from_list_reduce_next = output;
    }
    return output;
  }
  vx_core::Func_any_from_list_reduce_next t_any_from_list_reduce_next() {
    vx_core::Func_any_from_list_reduce_next output = vx_core::vx_package->t_any_from_list_reduce_next;
    if (output == NULL) {
      output = new vx_core::Class_any_from_list_reduce_next();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_any_from_list_reduce_next = output;
    }
    return output;
  }

  // (func any<-map)
  vx_core::Func_any_from_map e_any_from_map() {
    vx_core::Func_any_from_map output = vx_core::vx_package->e_any_from_map;
    if (output == NULL) {
      output = new vx_core::Class_any_from_map();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_any_from_map = output;
    }
    return output;
  }
  vx_core::Func_any_from_map t_any_from_map() {
    vx_core::Func_any_from_map output = vx_core::vx_package->t_any_from_map;
    if (output == NULL) {
      output = new vx_core::Class_any_from_map();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_any_from_map = output;
    }
    return output;
  }

  // (func any<-none)
  vx_core::Func_any_from_none e_any_from_none() {
    vx_core::Func_any_from_none output = vx_core::vx_package->e_any_from_none;
    if (output == NULL) {
      output = new vx_core::Class_any_from_none();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_any_from_none = output;
    }
    return output;
  }
  vx_core::Func_any_from_none t_any_from_none() {
    vx_core::Func_any_from_none output = vx_core::vx_package->t_any_from_none;
    if (output == NULL) {
      output = new vx_core::Class_any_from_none();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_any_from_none = output;
    }
    return output;
  }

  // (func any<-none-async)
  vx_core::Func_any_from_none_async e_any_from_none_async() {
    vx_core::Func_any_from_none_async output = vx_core::vx_package->e_any_from_none_async;
    if (output == NULL) {
      output = new vx_core::Class_any_from_none_async();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_any_from_none_async = output;
    }
    return output;
  }
  vx_core::Func_any_from_none_async t_any_from_none_async() {
    vx_core::Func_any_from_none_async output = vx_core::vx_package->t_any_from_none_async;
    if (output == NULL) {
      output = new vx_core::Class_any_from_none_async();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_any_from_none_async = output;
    }
    return output;
  }

  // (func any<-reduce)
  vx_core::Func_any_from_reduce e_any_from_reduce() {
    vx_core::Func_any_from_reduce output = vx_core::vx_package->e_any_from_reduce;
    if (output == NULL) {
      output = new vx_core::Class_any_from_reduce();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_any_from_reduce = output;
    }
    return output;
  }
  vx_core::Func_any_from_reduce t_any_from_reduce() {
    vx_core::Func_any_from_reduce output = vx_core::vx_package->t_any_from_reduce;
    if (output == NULL) {
      output = new vx_core::Class_any_from_reduce();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_any_from_reduce = output;
    }
    return output;
  }

  // (func any<-reduce-async)
  vx_core::Func_any_from_reduce_async e_any_from_reduce_async() {
    vx_core::Func_any_from_reduce_async output = vx_core::vx_package->e_any_from_reduce_async;
    if (output == NULL) {
      output = new vx_core::Class_any_from_reduce_async();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_any_from_reduce_async = output;
    }
    return output;
  }
  vx_core::Func_any_from_reduce_async t_any_from_reduce_async() {
    vx_core::Func_any_from_reduce_async output = vx_core::vx_package->t_any_from_reduce_async;
    if (output == NULL) {
      output = new vx_core::Class_any_from_reduce_async();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_any_from_reduce_async = output;
    }
    return output;
  }

  // (func any<-reduce-next)
  vx_core::Func_any_from_reduce_next e_any_from_reduce_next() {
    vx_core::Func_any_from_reduce_next output = vx_core::vx_package->e_any_from_reduce_next;
    if (output == NULL) {
      output = new vx_core::Class_any_from_reduce_next();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_any_from_reduce_next = output;
    }
    return output;
  }
  vx_core::Func_any_from_reduce_next t_any_from_reduce_next() {
    vx_core::Func_any_from_reduce_next output = vx_core::vx_package->t_any_from_reduce_next;
    if (output == NULL) {
      output = new vx_core::Class_any_from_reduce_next();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_any_from_reduce_next = output;
    }
    return output;
  }

  // (func any<-reduce-next-async)
  vx_core::Func_any_from_reduce_next_async e_any_from_reduce_next_async() {
    vx_core::Func_any_from_reduce_next_async output = vx_core::vx_package->e_any_from_reduce_next_async;
    if (output == NULL) {
      output = new vx_core::Class_any_from_reduce_next_async();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_any_from_reduce_next_async = output;
    }
    return output;
  }
  vx_core::Func_any_from_reduce_next_async t_any_from_reduce_next_async() {
    vx_core::Func_any_from_reduce_next_async output = vx_core::vx_package->t_any_from_reduce_next_async;
    if (output == NULL) {
      output = new vx_core::Class_any_from_reduce_next_async();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_any_from_reduce_next_async = output;
    }
    return output;
  }

  // (func any<-struct)
  vx_core::Func_any_from_struct e_any_from_struct() {
    vx_core::Func_any_from_struct output = vx_core::vx_package->e_any_from_struct;
    if (output == NULL) {
      output = new vx_core::Class_any_from_struct();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_any_from_struct = output;
    }
    return output;
  }
  vx_core::Func_any_from_struct t_any_from_struct() {
    vx_core::Func_any_from_struct output = vx_core::vx_package->t_any_from_struct;
    if (output == NULL) {
      output = new vx_core::Class_any_from_struct();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_any_from_struct = output;
    }
    return output;
  }

  // (func async)
  vx_core::Func_async e_async() {
    vx_core::Func_async output = vx_core::vx_package->e_async;
    if (output == NULL) {
      output = new vx_core::Class_async();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_async = output;
    }
    return output;
  }
  vx_core::Func_async t_async() {
    vx_core::Func_async output = vx_core::vx_package->t_async;
    if (output == NULL) {
      output = new vx_core::Class_async();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_async = output;
    }
    return output;
  }

  // (func boolean<-any)
  vx_core::Func_boolean_from_any e_boolean_from_any() {
    vx_core::Func_boolean_from_any output = vx_core::vx_package->e_boolean_from_any;
    if (output == NULL) {
      output = new vx_core::Class_boolean_from_any();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_boolean_from_any = output;
    }
    return output;
  }
  vx_core::Func_boolean_from_any t_boolean_from_any() {
    vx_core::Func_boolean_from_any output = vx_core::vx_package->t_boolean_from_any;
    if (output == NULL) {
      output = new vx_core::Class_boolean_from_any();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_boolean_from_any = output;
    }
    return output;
  }

  // (func boolean<-func)
  vx_core::Func_boolean_from_func e_boolean_from_func() {
    vx_core::Func_boolean_from_func output = vx_core::vx_package->e_boolean_from_func;
    if (output == NULL) {
      output = new vx_core::Class_boolean_from_func();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_boolean_from_func = output;
    }
    return output;
  }
  vx_core::Func_boolean_from_func t_boolean_from_func() {
    vx_core::Func_boolean_from_func output = vx_core::vx_package->t_boolean_from_func;
    if (output == NULL) {
      output = new vx_core::Class_boolean_from_func();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_boolean_from_func = output;
    }
    return output;
  }

  // (func boolean<-none)
  vx_core::Func_boolean_from_none e_boolean_from_none() {
    vx_core::Func_boolean_from_none output = vx_core::vx_package->e_boolean_from_none;
    if (output == NULL) {
      output = new vx_core::Class_boolean_from_none();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_boolean_from_none = output;
    }
    return output;
  }
  vx_core::Func_boolean_from_none t_boolean_from_none() {
    vx_core::Func_boolean_from_none output = vx_core::vx_package->t_boolean_from_none;
    if (output == NULL) {
      output = new vx_core::Class_boolean_from_none();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_boolean_from_none = output;
    }
    return output;
  }

  // (func empty)
  vx_core::Func_empty e_empty() {
    vx_core::Func_empty output = vx_core::vx_package->e_empty;
    if (output == NULL) {
      output = new vx_core::Class_empty();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_empty = output;
    }
    return output;
  }
  vx_core::Func_empty t_empty() {
    vx_core::Func_empty output = vx_core::vx_package->t_empty;
    if (output == NULL) {
      output = new vx_core::Class_empty();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_empty = output;
    }
    return output;
  }

  // (func new)
  vx_core::Func_new e_new() {
    vx_core::Func_new output = vx_core::vx_package->e_new;
    if (output == NULL) {
      output = new vx_core::Class_new();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_new = output;
    }
    return output;
  }
  vx_core::Func_new t_new() {
    vx_core::Func_new output = vx_core::vx_package->t_new;
    if (output == NULL) {
      output = new vx_core::Class_new();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_new = output;
    }
    return output;
  }

  // (func copy)
  vx_core::Func_copy e_copy() {
    vx_core::Func_copy output = vx_core::vx_package->e_copy;
    if (output == NULL) {
      output = new vx_core::Class_copy();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_copy = output;
    }
    return output;
  }
  vx_core::Func_copy t_copy() {
    vx_core::Func_copy output = vx_core::vx_package->t_copy;
    if (output == NULL) {
      output = new vx_core::Class_copy();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_copy = output;
    }
    return output;
  }

  // (func is-empty)
  vx_core::Func_is_empty e_is_empty() {
    vx_core::Func_is_empty output = vx_core::vx_package->e_is_empty;
    if (output == NULL) {
      output = new vx_core::Class_is_empty();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_is_empty = output;
    }
    return output;
  }
  vx_core::Func_is_empty t_is_empty() {
    vx_core::Func_is_empty output = vx_core::vx_package->t_is_empty;
    if (output == NULL) {
      output = new vx_core::Class_is_empty();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_is_empty = output;
    }
    return output;
  }

  // (func is-empty)
  vx_core::Func_is_empty_1 e_is_empty_1() {
    vx_core::Func_is_empty_1 output = vx_core::vx_package->e_is_empty_1;
    if (output == NULL) {
      output = new vx_core::Class_is_empty_1();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_is_empty_1 = output;
    }
    return output;
  }
  vx_core::Func_is_empty_1 t_is_empty_1() {
    vx_core::Func_is_empty_1 output = vx_core::vx_package->t_is_empty_1;
    if (output == NULL) {
      output = new vx_core::Class_is_empty_1();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_is_empty_1 = output;
    }
    return output;
  }

  // (func !)
  vx_core::Func_not e_not() {
    vx_core::Func_not output = vx_core::vx_package->e_not;
    if (output == NULL) {
      output = new vx_core::Class_not();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_not = output;
    }
    return output;
  }
  vx_core::Func_not t_not() {
    vx_core::Func_not output = vx_core::vx_package->t_not;
    if (output == NULL) {
      output = new vx_core::Class_not();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_not = output;
    }
    return output;
  }

  // (func !-empty)
  vx_core::Func_notempty e_notempty() {
    vx_core::Func_notempty output = vx_core::vx_package->e_notempty;
    if (output == NULL) {
      output = new vx_core::Class_notempty();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_notempty = output;
    }
    return output;
  }
  vx_core::Func_notempty t_notempty() {
    vx_core::Func_notempty output = vx_core::vx_package->t_notempty;
    if (output == NULL) {
      output = new vx_core::Class_notempty();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_notempty = output;
    }
    return output;
  }

  // (func !-empty)
  vx_core::Func_notempty_1 e_notempty_1() {
    vx_core::Func_notempty_1 output = vx_core::vx_package->e_notempty_1;
    if (output == NULL) {
      output = new vx_core::Class_notempty_1();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_notempty_1 = output;
    }
    return output;
  }
  vx_core::Func_notempty_1 t_notempty_1() {
    vx_core::Func_notempty_1 output = vx_core::vx_package->t_notempty_1;
    if (output == NULL) {
      output = new vx_core::Class_notempty_1();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_notempty_1 = output;
    }
    return output;
  }

  // (func =)
  vx_core::Func_eq e_eq() {
    vx_core::Func_eq output = vx_core::vx_package->e_eq;
    if (output == NULL) {
      output = new vx_core::Class_eq();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_eq = output;
    }
    return output;
  }
  vx_core::Func_eq t_eq() {
    vx_core::Func_eq output = vx_core::vx_package->t_eq;
    if (output == NULL) {
      output = new vx_core::Class_eq();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_eq = output;
    }
    return output;
  }

  // (func =)
  vx_core::Func_eq_1 e_eq_1() {
    vx_core::Func_eq_1 output = vx_core::vx_package->e_eq_1;
    if (output == NULL) {
      output = new vx_core::Class_eq_1();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_eq_1 = output;
    }
    return output;
  }
  vx_core::Func_eq_1 t_eq_1() {
    vx_core::Func_eq_1 output = vx_core::vx_package->t_eq_1;
    if (output == NULL) {
      output = new vx_core::Class_eq_1();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_eq_1 = output;
    }
    return output;
  }

  // (func !=)
  vx_core::Func_ne e_ne() {
    vx_core::Func_ne output = vx_core::vx_package->e_ne;
    if (output == NULL) {
      output = new vx_core::Class_ne();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_ne = output;
    }
    return output;
  }
  vx_core::Func_ne t_ne() {
    vx_core::Func_ne output = vx_core::vx_package->t_ne;
    if (output == NULL) {
      output = new vx_core::Class_ne();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_ne = output;
    }
    return output;
  }

  // (func then)
  vx_core::Func_then e_then() {
    vx_core::Func_then output = vx_core::vx_package->e_then;
    if (output == NULL) {
      output = new vx_core::Class_then();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_then = output;
    }
    return output;
  }
  vx_core::Func_then t_then() {
    vx_core::Func_then output = vx_core::vx_package->t_then;
    if (output == NULL) {
      output = new vx_core::Class_then();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_then = output;
    }
    return output;
  }

  // (func else)
  vx_core::Func_else e_else() {
    vx_core::Func_else output = vx_core::vx_package->e_else;
    if (output == NULL) {
      output = new vx_core::Class_else();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_else = output;
    }
    return output;
  }
  vx_core::Func_else t_else() {
    vx_core::Func_else output = vx_core::vx_package->t_else;
    if (output == NULL) {
      output = new vx_core::Class_else();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_else = output;
    }
    return output;
  }

  // (func if)
  vx_core::Func_if e_if() {
    vx_core::Func_if output = vx_core::vx_package->e_if;
    if (output == NULL) {
      output = new vx_core::Class_if();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_if = output;
    }
    return output;
  }
  vx_core::Func_if t_if() {
    vx_core::Func_if output = vx_core::vx_package->t_if;
    if (output == NULL) {
      output = new vx_core::Class_if();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_if = output;
    }
    return output;
  }

  // (func if)
  vx_core::Func_if_1 e_if_1() {
    vx_core::Func_if_1 output = vx_core::vx_package->e_if_1;
    if (output == NULL) {
      output = new vx_core::Class_if_1();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_if_1 = output;
    }
    return output;
  }
  vx_core::Func_if_1 t_if_1() {
    vx_core::Func_if_1 output = vx_core::vx_package->t_if_1;
    if (output == NULL) {
      output = new vx_core::Class_if_1();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_if_1 = output;
    }
    return output;
  }

  // (func if)
  vx_core::Func_if_2 e_if_2() {
    vx_core::Func_if_2 output = vx_core::vx_package->e_if_2;
    if (output == NULL) {
      output = new vx_core::Class_if_2();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_if_2 = output;
    }
    return output;
  }
  vx_core::Func_if_2 t_if_2() {
    vx_core::Func_if_2 output = vx_core::vx_package->t_if_2;
    if (output == NULL) {
      output = new vx_core::Class_if_2();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_if_2 = output;
    }
    return output;
  }

  // (func case)
  vx_core::Func_case e_case() {
    vx_core::Func_case output = vx_core::vx_package->e_case;
    if (output == NULL) {
      output = new vx_core::Class_case();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_case = output;
    }
    return output;
  }
  vx_core::Func_case t_case() {
    vx_core::Func_case output = vx_core::vx_package->t_case;
    if (output == NULL) {
      output = new vx_core::Class_case();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_case = output;
    }
    return output;
  }

  // (func case)
  vx_core::Func_case_1 e_case_1() {
    vx_core::Func_case_1 output = vx_core::vx_package->e_case_1;
    if (output == NULL) {
      output = new vx_core::Class_case_1();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_case_1 = output;
    }
    return output;
  }
  vx_core::Func_case_1 t_case_1() {
    vx_core::Func_case_1 output = vx_core::vx_package->t_case_1;
    if (output == NULL) {
      output = new vx_core::Class_case_1();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_case_1 = output;
    }
    return output;
  }

  // (func switch)
  vx_core::Func_switch e_switch() {
    vx_core::Func_switch output = vx_core::vx_package->e_switch;
    if (output == NULL) {
      output = new vx_core::Class_switch();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_switch = output;
    }
    return output;
  }
  vx_core::Func_switch t_switch() {
    vx_core::Func_switch output = vx_core::vx_package->t_switch;
    if (output == NULL) {
      output = new vx_core::Class_switch();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_switch = output;
    }
    return output;
  }

  // (func length<-list)
  vx_core::Func_length_from_list e_length_from_list() {
    vx_core::Func_length_from_list output = vx_core::vx_package->e_length_from_list;
    if (output == NULL) {
      output = new vx_core::Class_length_from_list();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_length_from_list = output;
    }
    return output;
  }
  vx_core::Func_length_from_list t_length_from_list() {
    vx_core::Func_length_from_list output = vx_core::vx_package->t_length_from_list;
    if (output == NULL) {
      output = new vx_core::Class_length_from_list();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_length_from_list = output;
    }
    return output;
  }

  // (func and)
  vx_core::Func_and e_and() {
    vx_core::Func_and output = vx_core::vx_package->e_and;
    if (output == NULL) {
      output = new vx_core::Class_and();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_and = output;
    }
    return output;
  }
  vx_core::Func_and t_and() {
    vx_core::Func_and output = vx_core::vx_package->t_and;
    if (output == NULL) {
      output = new vx_core::Class_and();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_and = output;
    }
    return output;
  }

  // (func and)
  vx_core::Func_and_1 e_and_1() {
    vx_core::Func_and_1 output = vx_core::vx_package->e_and_1;
    if (output == NULL) {
      output = new vx_core::Class_and_1();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_and_1 = output;
    }
    return output;
  }
  vx_core::Func_and_1 t_and_1() {
    vx_core::Func_and_1 output = vx_core::vx_package->t_and_1;
    if (output == NULL) {
      output = new vx_core::Class_and_1();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_and_1 = output;
    }
    return output;
  }

  // (func or)
  vx_core::Func_or e_or() {
    vx_core::Func_or output = vx_core::vx_package->e_or;
    if (output == NULL) {
      output = new vx_core::Class_or();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_or = output;
    }
    return output;
  }
  vx_core::Func_or t_or() {
    vx_core::Func_or output = vx_core::vx_package->t_or;
    if (output == NULL) {
      output = new vx_core::Class_or();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_or = output;
    }
    return output;
  }

  // (func or)
  vx_core::Func_or_1 e_or_1() {
    vx_core::Func_or_1 output = vx_core::vx_package->e_or_1;
    if (output == NULL) {
      output = new vx_core::Class_or_1();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_or_1 = output;
    }
    return output;
  }
  vx_core::Func_or_1 t_or_1() {
    vx_core::Func_or_1 output = vx_core::vx_package->t_or_1;
    if (output == NULL) {
      output = new vx_core::Class_or_1();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_or_1 = output;
    }
    return output;
  }

  // (func let)
  vx_core::Func_let e_let() {
    vx_core::Func_let output = vx_core::vx_package->e_let;
    if (output == NULL) {
      output = new vx_core::Class_let();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_let = output;
    }
    return output;
  }
  vx_core::Func_let t_let() {
    vx_core::Func_let output = vx_core::vx_package->t_let;
    if (output == NULL) {
      output = new vx_core::Class_let();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_let = output;
    }
    return output;
  }

  // (func let-async)
  vx_core::Func_let_async e_let_async() {
    vx_core::Func_let_async output = vx_core::vx_package->e_let_async;
    if (output == NULL) {
      output = new vx_core::Class_let_async();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_let_async = output;
    }
    return output;
  }
  vx_core::Func_let_async t_let_async() {
    vx_core::Func_let_async output = vx_core::vx_package->t_let_async;
    if (output == NULL) {
      output = new vx_core::Class_let_async();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_let_async = output;
    }
    return output;
  }

  // (func *)
  vx_core::Func_multiply e_multiply() {
    vx_core::Func_multiply output = vx_core::vx_package->e_multiply;
    if (output == NULL) {
      output = new vx_core::Class_multiply();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_multiply = output;
    }
    return output;
  }
  vx_core::Func_multiply t_multiply() {
    vx_core::Func_multiply output = vx_core::vx_package->t_multiply;
    if (output == NULL) {
      output = new vx_core::Class_multiply();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_multiply = output;
    }
    return output;
  }

  // (func *)
  vx_core::Func_multiply_1 e_multiply_1() {
    vx_core::Func_multiply_1 output = vx_core::vx_package->e_multiply_1;
    if (output == NULL) {
      output = new vx_core::Class_multiply_1();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_multiply_1 = output;
    }
    return output;
  }
  vx_core::Func_multiply_1 t_multiply_1() {
    vx_core::Func_multiply_1 output = vx_core::vx_package->t_multiply_1;
    if (output == NULL) {
      output = new vx_core::Class_multiply_1();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_multiply_1 = output;
    }
    return output;
  }

  // (func *)
  vx_core::Func_multiply_2 e_multiply_2() {
    vx_core::Func_multiply_2 output = vx_core::vx_package->e_multiply_2;
    if (output == NULL) {
      output = new vx_core::Class_multiply_2();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_multiply_2 = output;
    }
    return output;
  }
  vx_core::Func_multiply_2 t_multiply_2() {
    vx_core::Func_multiply_2 output = vx_core::vx_package->t_multiply_2;
    if (output == NULL) {
      output = new vx_core::Class_multiply_2();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_multiply_2 = output;
    }
    return output;
  }

  // (func *)
  vx_core::Func_multiply_3 e_multiply_3() {
    vx_core::Func_multiply_3 output = vx_core::vx_package->e_multiply_3;
    if (output == NULL) {
      output = new vx_core::Class_multiply_3();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_multiply_3 = output;
    }
    return output;
  }
  vx_core::Func_multiply_3 t_multiply_3() {
    vx_core::Func_multiply_3 output = vx_core::vx_package->t_multiply_3;
    if (output == NULL) {
      output = new vx_core::Class_multiply_3();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_multiply_3 = output;
    }
    return output;
  }

  // (func +)
  vx_core::Func_plus e_plus() {
    vx_core::Func_plus output = vx_core::vx_package->e_plus;
    if (output == NULL) {
      output = new vx_core::Class_plus();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_plus = output;
    }
    return output;
  }
  vx_core::Func_plus t_plus() {
    vx_core::Func_plus output = vx_core::vx_package->t_plus;
    if (output == NULL) {
      output = new vx_core::Class_plus();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_plus = output;
    }
    return output;
  }

  // (func +)
  vx_core::Func_plus_1 e_plus_1() {
    vx_core::Func_plus_1 output = vx_core::vx_package->e_plus_1;
    if (output == NULL) {
      output = new vx_core::Class_plus_1();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_plus_1 = output;
    }
    return output;
  }
  vx_core::Func_plus_1 t_plus_1() {
    vx_core::Func_plus_1 output = vx_core::vx_package->t_plus_1;
    if (output == NULL) {
      output = new vx_core::Class_plus_1();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_plus_1 = output;
    }
    return output;
  }

  // (func +)
  vx_core::Func_plus_2 e_plus_2() {
    vx_core::Func_plus_2 output = vx_core::vx_package->e_plus_2;
    if (output == NULL) {
      output = new vx_core::Class_plus_2();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_plus_2 = output;
    }
    return output;
  }
  vx_core::Func_plus_2 t_plus_2() {
    vx_core::Func_plus_2 output = vx_core::vx_package->t_plus_2;
    if (output == NULL) {
      output = new vx_core::Class_plus_2();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_plus_2 = output;
    }
    return output;
  }

  // (func +)
  vx_core::Func_plus_3 e_plus_3() {
    vx_core::Func_plus_3 output = vx_core::vx_package->e_plus_3;
    if (output == NULL) {
      output = new vx_core::Class_plus_3();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_plus_3 = output;
    }
    return output;
  }
  vx_core::Func_plus_3 t_plus_3() {
    vx_core::Func_plus_3 output = vx_core::vx_package->t_plus_3;
    if (output == NULL) {
      output = new vx_core::Class_plus_3();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_plus_3 = output;
    }
    return output;
  }

  // (func +1)
  vx_core::Func_plus1 e_plus1() {
    vx_core::Func_plus1 output = vx_core::vx_package->e_plus1;
    if (output == NULL) {
      output = new vx_core::Class_plus1();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_plus1 = output;
    }
    return output;
  }
  vx_core::Func_plus1 t_plus1() {
    vx_core::Func_plus1 output = vx_core::vx_package->t_plus1;
    if (output == NULL) {
      output = new vx_core::Class_plus1();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_plus1 = output;
    }
    return output;
  }

  // (func -)
  vx_core::Func_minus e_minus() {
    vx_core::Func_minus output = vx_core::vx_package->e_minus;
    if (output == NULL) {
      output = new vx_core::Class_minus();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_minus = output;
    }
    return output;
  }
  vx_core::Func_minus t_minus() {
    vx_core::Func_minus output = vx_core::vx_package->t_minus;
    if (output == NULL) {
      output = new vx_core::Class_minus();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_minus = output;
    }
    return output;
  }

  // (func -)
  vx_core::Func_minus_1 e_minus_1() {
    vx_core::Func_minus_1 output = vx_core::vx_package->e_minus_1;
    if (output == NULL) {
      output = new vx_core::Class_minus_1();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_minus_1 = output;
    }
    return output;
  }
  vx_core::Func_minus_1 t_minus_1() {
    vx_core::Func_minus_1 output = vx_core::vx_package->t_minus_1;
    if (output == NULL) {
      output = new vx_core::Class_minus_1();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_minus_1 = output;
    }
    return output;
  }

  // (func -)
  vx_core::Func_minus_2 e_minus_2() {
    vx_core::Func_minus_2 output = vx_core::vx_package->e_minus_2;
    if (output == NULL) {
      output = new vx_core::Class_minus_2();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_minus_2 = output;
    }
    return output;
  }
  vx_core::Func_minus_2 t_minus_2() {
    vx_core::Func_minus_2 output = vx_core::vx_package->t_minus_2;
    if (output == NULL) {
      output = new vx_core::Class_minus_2();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_minus_2 = output;
    }
    return output;
  }

  // (func -)
  vx_core::Func_minus_3 e_minus_3() {
    vx_core::Func_minus_3 output = vx_core::vx_package->e_minus_3;
    if (output == NULL) {
      output = new vx_core::Class_minus_3();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_minus_3 = output;
    }
    return output;
  }
  vx_core::Func_minus_3 t_minus_3() {
    vx_core::Func_minus_3 output = vx_core::vx_package->t_minus_3;
    if (output == NULL) {
      output = new vx_core::Class_minus_3();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_minus_3 = output;
    }
    return output;
  }

  // (func .)
  vx_core::Func_dotmethod e_dotmethod() {
    vx_core::Func_dotmethod output = vx_core::vx_package->e_dotmethod;
    if (output == NULL) {
      output = new vx_core::Class_dotmethod();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_dotmethod = output;
    }
    return output;
  }
  vx_core::Func_dotmethod t_dotmethod() {
    vx_core::Func_dotmethod output = vx_core::vx_package->t_dotmethod;
    if (output == NULL) {
      output = new vx_core::Class_dotmethod();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_dotmethod = output;
    }
    return output;
  }

  // (func /)
  vx_core::Func_divide e_divide() {
    vx_core::Func_divide output = vx_core::vx_package->e_divide;
    if (output == NULL) {
      output = new vx_core::Class_divide();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_divide = output;
    }
    return output;
  }
  vx_core::Func_divide t_divide() {
    vx_core::Func_divide output = vx_core::vx_package->t_divide;
    if (output == NULL) {
      output = new vx_core::Class_divide();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_divide = output;
    }
    return output;
  }

  // (func <)
  vx_core::Func_lt e_lt() {
    vx_core::Func_lt output = vx_core::vx_package->e_lt;
    if (output == NULL) {
      output = new vx_core::Class_lt();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_lt = output;
    }
    return output;
  }
  vx_core::Func_lt t_lt() {
    vx_core::Func_lt output = vx_core::vx_package->t_lt;
    if (output == NULL) {
      output = new vx_core::Class_lt();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_lt = output;
    }
    return output;
  }

  // (func <)
  vx_core::Func_lt_1 e_lt_1() {
    vx_core::Func_lt_1 output = vx_core::vx_package->e_lt_1;
    if (output == NULL) {
      output = new vx_core::Class_lt_1();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_lt_1 = output;
    }
    return output;
  }
  vx_core::Func_lt_1 t_lt_1() {
    vx_core::Func_lt_1 output = vx_core::vx_package->t_lt_1;
    if (output == NULL) {
      output = new vx_core::Class_lt_1();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_lt_1 = output;
    }
    return output;
  }

  // (func <-)
  vx_core::Func_chainfirst e_chainfirst() {
    vx_core::Func_chainfirst output = vx_core::vx_package->e_chainfirst;
    if (output == NULL) {
      output = new vx_core::Class_chainfirst();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_chainfirst = output;
    }
    return output;
  }
  vx_core::Func_chainfirst t_chainfirst() {
    vx_core::Func_chainfirst output = vx_core::vx_package->t_chainfirst;
    if (output == NULL) {
      output = new vx_core::Class_chainfirst();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_chainfirst = output;
    }
    return output;
  }

  // (func <<-)
  vx_core::Func_chainlast e_chainlast() {
    vx_core::Func_chainlast output = vx_core::vx_package->e_chainlast;
    if (output == NULL) {
      output = new vx_core::Class_chainlast();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_chainlast = output;
    }
    return output;
  }
  vx_core::Func_chainlast t_chainlast() {
    vx_core::Func_chainlast output = vx_core::vx_package->t_chainlast;
    if (output == NULL) {
      output = new vx_core::Class_chainlast();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_chainlast = output;
    }
    return output;
  }

  // (func <=)
  vx_core::Func_le e_le() {
    vx_core::Func_le output = vx_core::vx_package->e_le;
    if (output == NULL) {
      output = new vx_core::Class_le();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_le = output;
    }
    return output;
  }
  vx_core::Func_le t_le() {
    vx_core::Func_le output = vx_core::vx_package->t_le;
    if (output == NULL) {
      output = new vx_core::Class_le();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_le = output;
    }
    return output;
  }

  // (func <=)
  vx_core::Func_le_1 e_le_1() {
    vx_core::Func_le_1 output = vx_core::vx_package->e_le_1;
    if (output == NULL) {
      output = new vx_core::Class_le_1();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_le_1 = output;
    }
    return output;
  }
  vx_core::Func_le_1 t_le_1() {
    vx_core::Func_le_1 output = vx_core::vx_package->t_le_1;
    if (output == NULL) {
      output = new vx_core::Class_le_1();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_le_1 = output;
    }
    return output;
  }

  // (func >)
  vx_core::Func_gt e_gt() {
    vx_core::Func_gt output = vx_core::vx_package->e_gt;
    if (output == NULL) {
      output = new vx_core::Class_gt();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_gt = output;
    }
    return output;
  }
  vx_core::Func_gt t_gt() {
    vx_core::Func_gt output = vx_core::vx_package->t_gt;
    if (output == NULL) {
      output = new vx_core::Class_gt();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_gt = output;
    }
    return output;
  }

  // (func >)
  vx_core::Func_gt_1 e_gt_1() {
    vx_core::Func_gt_1 output = vx_core::vx_package->e_gt_1;
    if (output == NULL) {
      output = new vx_core::Class_gt_1();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_gt_1 = output;
    }
    return output;
  }
  vx_core::Func_gt_1 t_gt_1() {
    vx_core::Func_gt_1 output = vx_core::vx_package->t_gt_1;
    if (output == NULL) {
      output = new vx_core::Class_gt_1();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_gt_1 = output;
    }
    return output;
  }

  // (func >=)
  vx_core::Func_ge e_ge() {
    vx_core::Func_ge output = vx_core::vx_package->e_ge;
    if (output == NULL) {
      output = new vx_core::Class_ge();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_ge = output;
    }
    return output;
  }
  vx_core::Func_ge t_ge() {
    vx_core::Func_ge output = vx_core::vx_package->t_ge;
    if (output == NULL) {
      output = new vx_core::Class_ge();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_ge = output;
    }
    return output;
  }

  // (func >=)
  vx_core::Func_ge_1 e_ge_1() {
    vx_core::Func_ge_1 output = vx_core::vx_package->e_ge_1;
    if (output == NULL) {
      output = new vx_core::Class_ge_1();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_ge_1 = output;
    }
    return output;
  }
  vx_core::Func_ge_1 t_ge_1() {
    vx_core::Func_ge_1 output = vx_core::vx_package->t_ge_1;
    if (output == NULL) {
      output = new vx_core::Class_ge_1();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_ge_1 = output;
    }
    return output;
  }

  // (func allowtypenames<-typedef)
  vx_core::Func_allowtypenames_from_typedef e_allowtypenames_from_typedef() {
    vx_core::Func_allowtypenames_from_typedef output = vx_core::vx_package->e_allowtypenames_from_typedef;
    if (output == NULL) {
      output = new vx_core::Class_allowtypenames_from_typedef();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_allowtypenames_from_typedef = output;
    }
    return output;
  }
  vx_core::Func_allowtypenames_from_typedef t_allowtypenames_from_typedef() {
    vx_core::Func_allowtypenames_from_typedef output = vx_core::vx_package->t_allowtypenames_from_typedef;
    if (output == NULL) {
      output = new vx_core::Class_allowtypenames_from_typedef();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_allowtypenames_from_typedef = output;
    }
    return output;
  }

  // (func allowtypes<-typedef)
  vx_core::Func_allowtypes_from_typedef e_allowtypes_from_typedef() {
    vx_core::Func_allowtypes_from_typedef output = vx_core::vx_package->e_allowtypes_from_typedef;
    if (output == NULL) {
      output = new vx_core::Class_allowtypes_from_typedef();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_allowtypes_from_typedef = output;
    }
    return output;
  }
  vx_core::Func_allowtypes_from_typedef t_allowtypes_from_typedef() {
    vx_core::Func_allowtypes_from_typedef output = vx_core::vx_package->t_allowtypes_from_typedef;
    if (output == NULL) {
      output = new vx_core::Class_allowtypes_from_typedef();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_allowtypes_from_typedef = output;
    }
    return output;
  }

  // (func compare)
  vx_core::Func_compare e_compare() {
    vx_core::Func_compare output = vx_core::vx_package->e_compare;
    if (output == NULL) {
      output = new vx_core::Class_compare();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_compare = output;
    }
    return output;
  }
  vx_core::Func_compare t_compare() {
    vx_core::Func_compare output = vx_core::vx_package->t_compare;
    if (output == NULL) {
      output = new vx_core::Class_compare();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_compare = output;
    }
    return output;
  }

  // (func contains)
  vx_core::Func_contains e_contains() {
    vx_core::Func_contains output = vx_core::vx_package->e_contains;
    if (output == NULL) {
      output = new vx_core::Class_contains();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_contains = output;
    }
    return output;
  }
  vx_core::Func_contains t_contains() {
    vx_core::Func_contains output = vx_core::vx_package->t_contains;
    if (output == NULL) {
      output = new vx_core::Class_contains();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_contains = output;
    }
    return output;
  }

  // (func contains)
  vx_core::Func_contains_1 e_contains_1() {
    vx_core::Func_contains_1 output = vx_core::vx_package->e_contains_1;
    if (output == NULL) {
      output = new vx_core::Class_contains_1();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_contains_1 = output;
    }
    return output;
  }
  vx_core::Func_contains_1 t_contains_1() {
    vx_core::Func_contains_1 output = vx_core::vx_package->t_contains_1;
    if (output == NULL) {
      output = new vx_core::Class_contains_1();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_contains_1 = output;
    }
    return output;
  }

  // (func extends<-any)
  vx_core::Func_extends_from_any e_extends_from_any() {
    vx_core::Func_extends_from_any output = vx_core::vx_package->e_extends_from_any;
    if (output == NULL) {
      output = new vx_core::Class_extends_from_any();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_extends_from_any = output;
    }
    return output;
  }
  vx_core::Func_extends_from_any t_extends_from_any() {
    vx_core::Func_extends_from_any output = vx_core::vx_package->t_extends_from_any;
    if (output == NULL) {
      output = new vx_core::Class_extends_from_any();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_extends_from_any = output;
    }
    return output;
  }

  // (func extends<-typedef)
  vx_core::Func_extends_from_typedef e_extends_from_typedef() {
    vx_core::Func_extends_from_typedef output = vx_core::vx_package->e_extends_from_typedef;
    if (output == NULL) {
      output = new vx_core::Class_extends_from_typedef();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_extends_from_typedef = output;
    }
    return output;
  }
  vx_core::Func_extends_from_typedef t_extends_from_typedef() {
    vx_core::Func_extends_from_typedef output = vx_core::vx_package->t_extends_from_typedef;
    if (output == NULL) {
      output = new vx_core::Class_extends_from_typedef();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_extends_from_typedef = output;
    }
    return output;
  }

  // (func first<-list)
  vx_core::Func_first_from_list e_first_from_list() {
    vx_core::Func_first_from_list output = vx_core::vx_package->e_first_from_list;
    if (output == NULL) {
      output = new vx_core::Class_first_from_list();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_first_from_list = output;
    }
    return output;
  }
  vx_core::Func_first_from_list t_first_from_list() {
    vx_core::Func_first_from_list output = vx_core::vx_package->t_first_from_list;
    if (output == NULL) {
      output = new vx_core::Class_first_from_list();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_first_from_list = output;
    }
    return output;
  }

  // (func first<-list-fn-any<-any)
  vx_core::Func_first_from_list_fn_any_from_any e_first_from_list_fn_any_from_any() {
    vx_core::Func_first_from_list_fn_any_from_any output = vx_core::vx_package->e_first_from_list_fn_any_from_any;
    if (output == NULL) {
      output = new vx_core::Class_first_from_list_fn_any_from_any();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_first_from_list_fn_any_from_any = output;
    }
    return output;
  }
  vx_core::Func_first_from_list_fn_any_from_any t_first_from_list_fn_any_from_any() {
    vx_core::Func_first_from_list_fn_any_from_any output = vx_core::vx_package->t_first_from_list_fn_any_from_any;
    if (output == NULL) {
      output = new vx_core::Class_first_from_list_fn_any_from_any();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_first_from_list_fn_any_from_any = output;
    }
    return output;
  }

  // (func fn)
  vx_core::Func_fn e_fn() {
    vx_core::Func_fn output = vx_core::vx_package->e_fn;
    if (output == NULL) {
      output = new vx_core::Class_fn();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_fn = output;
    }
    return output;
  }
  vx_core::Func_fn t_fn() {
    vx_core::Func_fn output = vx_core::vx_package->t_fn;
    if (output == NULL) {
      output = new vx_core::Class_fn();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_fn = output;
    }
    return output;
  }

  // (func funcdef<-func)
  vx_core::Func_funcdef_from_func e_funcdef_from_func() {
    vx_core::Func_funcdef_from_func output = vx_core::vx_package->e_funcdef_from_func;
    if (output == NULL) {
      output = new vx_core::Class_funcdef_from_func();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_funcdef_from_func = output;
    }
    return output;
  }
  vx_core::Func_funcdef_from_func t_funcdef_from_func() {
    vx_core::Func_funcdef_from_func output = vx_core::vx_package->t_funcdef_from_func;
    if (output == NULL) {
      output = new vx_core::Class_funcdef_from_func();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_funcdef_from_func = output;
    }
    return output;
  }

  // (func funcname<-funcdef)
  vx_core::Func_funcname_from_funcdef e_funcname_from_funcdef() {
    vx_core::Func_funcname_from_funcdef output = vx_core::vx_package->e_funcname_from_funcdef;
    if (output == NULL) {
      output = new vx_core::Class_funcname_from_funcdef();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_funcname_from_funcdef = output;
    }
    return output;
  }
  vx_core::Func_funcname_from_funcdef t_funcname_from_funcdef() {
    vx_core::Func_funcname_from_funcdef output = vx_core::vx_package->t_funcname_from_funcdef;
    if (output == NULL) {
      output = new vx_core::Class_funcname_from_funcdef();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_funcname_from_funcdef = output;
    }
    return output;
  }

  // (func global-package-get)
  vx_core::Func_global_package_get e_global_package_get() {
    vx_core::Func_global_package_get output = vx_core::vx_package->e_global_package_get;
    if (output == NULL) {
      output = new vx_core::Class_global_package_get();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_global_package_get = output;
    }
    return output;
  }
  vx_core::Func_global_package_get t_global_package_get() {
    vx_core::Func_global_package_get output = vx_core::vx_package->t_global_package_get;
    if (output == NULL) {
      output = new vx_core::Class_global_package_get();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_global_package_get = output;
    }
    return output;
  }

  // (func global-package-set)
  vx_core::Func_global_package_set e_global_package_set() {
    vx_core::Func_global_package_set output = vx_core::vx_package->e_global_package_set;
    if (output == NULL) {
      output = new vx_core::Class_global_package_set();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_global_package_set = output;
    }
    return output;
  }
  vx_core::Func_global_package_set t_global_package_set() {
    vx_core::Func_global_package_set output = vx_core::vx_package->t_global_package_set;
    if (output == NULL) {
      output = new vx_core::Class_global_package_set();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_global_package_set = output;
    }
    return output;
  }

  // (func int<-func)
  vx_core::Func_int_from_func e_int_from_func() {
    vx_core::Func_int_from_func output = vx_core::vx_package->e_int_from_func;
    if (output == NULL) {
      output = new vx_core::Class_int_from_func();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_int_from_func = output;
    }
    return output;
  }
  vx_core::Func_int_from_func t_int_from_func() {
    vx_core::Func_int_from_func output = vx_core::vx_package->t_int_from_func;
    if (output == NULL) {
      output = new vx_core::Class_int_from_func();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_int_from_func = output;
    }
    return output;
  }

  // (func int<-string)
  vx_core::Func_int_from_string e_int_from_string() {
    vx_core::Func_int_from_string output = vx_core::vx_package->e_int_from_string;
    if (output == NULL) {
      output = new vx_core::Class_int_from_string();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_int_from_string = output;
    }
    return output;
  }
  vx_core::Func_int_from_string t_int_from_string() {
    vx_core::Func_int_from_string output = vx_core::vx_package->t_int_from_string;
    if (output == NULL) {
      output = new vx_core::Class_int_from_string();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_int_from_string = output;
    }
    return output;
  }

  // (func is-endswith)
  vx_core::Func_is_endswith e_is_endswith() {
    vx_core::Func_is_endswith output = vx_core::vx_package->e_is_endswith;
    if (output == NULL) {
      output = new vx_core::Class_is_endswith();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_is_endswith = output;
    }
    return output;
  }
  vx_core::Func_is_endswith t_is_endswith() {
    vx_core::Func_is_endswith output = vx_core::vx_package->t_is_endswith;
    if (output == NULL) {
      output = new vx_core::Class_is_endswith();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_is_endswith = output;
    }
    return output;
  }

  // (func is-func)
  vx_core::Func_is_func e_is_func() {
    vx_core::Func_is_func output = vx_core::vx_package->e_is_func;
    if (output == NULL) {
      output = new vx_core::Class_is_func();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_is_func = output;
    }
    return output;
  }
  vx_core::Func_is_func t_is_func() {
    vx_core::Func_is_func output = vx_core::vx_package->t_is_func;
    if (output == NULL) {
      output = new vx_core::Class_is_func();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_is_func = output;
    }
    return output;
  }

  // (func is-int)
  vx_core::Func_is_int e_is_int() {
    vx_core::Func_is_int output = vx_core::vx_package->e_is_int;
    if (output == NULL) {
      output = new vx_core::Class_is_int();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_is_int = output;
    }
    return output;
  }
  vx_core::Func_is_int t_is_int() {
    vx_core::Func_is_int output = vx_core::vx_package->t_is_int;
    if (output == NULL) {
      output = new vx_core::Class_is_int();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_is_int = output;
    }
    return output;
  }

  // (func is-number)
  vx_core::Func_is_number e_is_number() {
    vx_core::Func_is_number output = vx_core::vx_package->e_is_number;
    if (output == NULL) {
      output = new vx_core::Class_is_number();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_is_number = output;
    }
    return output;
  }
  vx_core::Func_is_number t_is_number() {
    vx_core::Func_is_number output = vx_core::vx_package->t_is_number;
    if (output == NULL) {
      output = new vx_core::Class_is_number();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_is_number = output;
    }
    return output;
  }

  // (func is-pass<-permission)
  vx_core::Func_is_pass_from_permission e_is_pass_from_permission() {
    vx_core::Func_is_pass_from_permission output = vx_core::vx_package->e_is_pass_from_permission;
    if (output == NULL) {
      output = new vx_core::Class_is_pass_from_permission();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_is_pass_from_permission = output;
    }
    return output;
  }
  vx_core::Func_is_pass_from_permission t_is_pass_from_permission() {
    vx_core::Func_is_pass_from_permission output = vx_core::vx_package->t_is_pass_from_permission;
    if (output == NULL) {
      output = new vx_core::Class_is_pass_from_permission();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_is_pass_from_permission = output;
    }
    return output;
  }

  // (func last<-list)
  vx_core::Func_last_from_list e_last_from_list() {
    vx_core::Func_last_from_list output = vx_core::vx_package->e_last_from_list;
    if (output == NULL) {
      output = new vx_core::Class_last_from_list();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_last_from_list = output;
    }
    return output;
  }
  vx_core::Func_last_from_list t_last_from_list() {
    vx_core::Func_last_from_list output = vx_core::vx_package->t_last_from_list;
    if (output == NULL) {
      output = new vx_core::Class_last_from_list();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_last_from_list = output;
    }
    return output;
  }

  // (func list-join<-list)
  vx_core::Func_list_join_from_list e_list_join_from_list() {
    vx_core::Func_list_join_from_list output = vx_core::vx_package->e_list_join_from_list;
    if (output == NULL) {
      output = new vx_core::Class_list_join_from_list();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_list_join_from_list = output;
    }
    return output;
  }
  vx_core::Func_list_join_from_list t_list_join_from_list() {
    vx_core::Func_list_join_from_list output = vx_core::vx_package->t_list_join_from_list;
    if (output == NULL) {
      output = new vx_core::Class_list_join_from_list();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_list_join_from_list = output;
    }
    return output;
  }

  // (func list<-list)
  vx_core::Func_list_from_list e_list_from_list() {
    vx_core::Func_list_from_list output = vx_core::vx_package->e_list_from_list;
    if (output == NULL) {
      output = new vx_core::Class_list_from_list();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_list_from_list = output;
    }
    return output;
  }
  vx_core::Func_list_from_list t_list_from_list() {
    vx_core::Func_list_from_list output = vx_core::vx_package->t_list_from_list;
    if (output == NULL) {
      output = new vx_core::Class_list_from_list();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_list_from_list = output;
    }
    return output;
  }

  // (func list<-list-async)
  vx_core::Func_list_from_list_async e_list_from_list_async() {
    vx_core::Func_list_from_list_async output = vx_core::vx_package->e_list_from_list_async;
    if (output == NULL) {
      output = new vx_core::Class_list_from_list_async();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_list_from_list_async = output;
    }
    return output;
  }
  vx_core::Func_list_from_list_async t_list_from_list_async() {
    vx_core::Func_list_from_list_async output = vx_core::vx_package->t_list_from_list_async;
    if (output == NULL) {
      output = new vx_core::Class_list_from_list_async();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_list_from_list_async = output;
    }
    return output;
  }

  // (func list<-map)
  vx_core::Func_list_from_map e_list_from_map() {
    vx_core::Func_list_from_map output = vx_core::vx_package->e_list_from_map;
    if (output == NULL) {
      output = new vx_core::Class_list_from_map();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_list_from_map = output;
    }
    return output;
  }
  vx_core::Func_list_from_map t_list_from_map() {
    vx_core::Func_list_from_map output = vx_core::vx_package->t_list_from_map;
    if (output == NULL) {
      output = new vx_core::Class_list_from_map();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_list_from_map = output;
    }
    return output;
  }

  // (func list<-map-async)
  vx_core::Func_list_from_map_async e_list_from_map_async() {
    vx_core::Func_list_from_map_async output = vx_core::vx_package->e_list_from_map_async;
    if (output == NULL) {
      output = new vx_core::Class_list_from_map_async();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_list_from_map_async = output;
    }
    return output;
  }
  vx_core::Func_list_from_map_async t_list_from_map_async() {
    vx_core::Func_list_from_map_async output = vx_core::vx_package->t_list_from_map_async;
    if (output == NULL) {
      output = new vx_core::Class_list_from_map_async();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_list_from_map_async = output;
    }
    return output;
  }

  // (func list<-type)
  vx_core::Func_list_from_type e_list_from_type() {
    vx_core::Func_list_from_type output = vx_core::vx_package->e_list_from_type;
    if (output == NULL) {
      output = new vx_core::Class_list_from_type();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_list_from_type = output;
    }
    return output;
  }
  vx_core::Func_list_from_type t_list_from_type() {
    vx_core::Func_list_from_type output = vx_core::vx_package->t_list_from_type;
    if (output == NULL) {
      output = new vx_core::Class_list_from_type();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_list_from_type = output;
    }
    return output;
  }

  // (func log)
  vx_core::Func_log e_log() {
    vx_core::Func_log output = vx_core::vx_package->e_log;
    if (output == NULL) {
      output = new vx_core::Class_log();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_log = output;
    }
    return output;
  }
  vx_core::Func_log t_log() {
    vx_core::Func_log output = vx_core::vx_package->t_log;
    if (output == NULL) {
      output = new vx_core::Class_log();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_log = output;
    }
    return output;
  }

  // (func map<-list)
  vx_core::Func_map_from_list e_map_from_list() {
    vx_core::Func_map_from_list output = vx_core::vx_package->e_map_from_list;
    if (output == NULL) {
      output = new vx_core::Class_map_from_list();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_map_from_list = output;
    }
    return output;
  }
  vx_core::Func_map_from_list t_map_from_list() {
    vx_core::Func_map_from_list output = vx_core::vx_package->t_map_from_list;
    if (output == NULL) {
      output = new vx_core::Class_map_from_list();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_map_from_list = output;
    }
    return output;
  }

  // (func mempool-addref)
  vx_core::Func_mempool_addref e_mempool_addref() {
    vx_core::Func_mempool_addref output = vx_core::vx_package->e_mempool_addref;
    if (output == NULL) {
      output = new vx_core::Class_mempool_addref();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_mempool_addref = output;
    }
    return output;
  }
  vx_core::Func_mempool_addref t_mempool_addref() {
    vx_core::Func_mempool_addref output = vx_core::vx_package->t_mempool_addref;
    if (output == NULL) {
      output = new vx_core::Class_mempool_addref();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_mempool_addref = output;
    }
    return output;
  }

  // (func mempool-release)
  vx_core::Func_mempool_release e_mempool_release() {
    vx_core::Func_mempool_release output = vx_core::vx_package->e_mempool_release;
    if (output == NULL) {
      output = new vx_core::Class_mempool_release();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_mempool_release = output;
    }
    return output;
  }
  vx_core::Func_mempool_release t_mempool_release() {
    vx_core::Func_mempool_release output = vx_core::vx_package->t_mempool_release;
    if (output == NULL) {
      output = new vx_core::Class_mempool_release();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_mempool_release = output;
    }
    return output;
  }

  // (func mempool-removeref)
  vx_core::Func_mempool_removeref e_mempool_removeref() {
    vx_core::Func_mempool_removeref output = vx_core::vx_package->e_mempool_removeref;
    if (output == NULL) {
      output = new vx_core::Class_mempool_removeref();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_mempool_removeref = output;
    }
    return output;
  }
  vx_core::Func_mempool_removeref t_mempool_removeref() {
    vx_core::Func_mempool_removeref output = vx_core::vx_package->t_mempool_removeref;
    if (output == NULL) {
      output = new vx_core::Class_mempool_removeref();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_mempool_removeref = output;
    }
    return output;
  }

  // (func mempool-removerefchildren)
  vx_core::Func_mempool_removerefchildren e_mempool_removerefchildren() {
    vx_core::Func_mempool_removerefchildren output = vx_core::vx_package->e_mempool_removerefchildren;
    if (output == NULL) {
      output = new vx_core::Class_mempool_removerefchildren();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_mempool_removerefchildren = output;
    }
    return output;
  }
  vx_core::Func_mempool_removerefchildren t_mempool_removerefchildren() {
    vx_core::Func_mempool_removerefchildren output = vx_core::vx_package->t_mempool_removerefchildren;
    if (output == NULL) {
      output = new vx_core::Class_mempool_removerefchildren();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_mempool_removerefchildren = output;
    }
    return output;
  }

  // (func mempool-reserve)
  vx_core::Func_mempool_reserve e_mempool_reserve() {
    vx_core::Func_mempool_reserve output = vx_core::vx_package->e_mempool_reserve;
    if (output == NULL) {
      output = new vx_core::Class_mempool_reserve();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_mempool_reserve = output;
    }
    return output;
  }
  vx_core::Func_mempool_reserve t_mempool_reserve() {
    vx_core::Func_mempool_reserve output = vx_core::vx_package->t_mempool_reserve;
    if (output == NULL) {
      output = new vx_core::Class_mempool_reserve();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_mempool_reserve = output;
    }
    return output;
  }

  // (func msg<-error)
  vx_core::Func_msg_from_error e_msg_from_error() {
    vx_core::Func_msg_from_error output = vx_core::vx_package->e_msg_from_error;
    if (output == NULL) {
      output = new vx_core::Class_msg_from_error();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_msg_from_error = output;
    }
    return output;
  }
  vx_core::Func_msg_from_error t_msg_from_error() {
    vx_core::Func_msg_from_error output = vx_core::vx_package->t_msg_from_error;
    if (output == NULL) {
      output = new vx_core::Class_msg_from_error();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_msg_from_error = output;
    }
    return output;
  }

  // (func msgblock<-msgblock-msg)
  vx_core::Func_msgblock_from_msgblock_msg e_msgblock_from_msgblock_msg() {
    vx_core::Func_msgblock_from_msgblock_msg output = vx_core::vx_package->e_msgblock_from_msgblock_msg;
    if (output == NULL) {
      output = new vx_core::Class_msgblock_from_msgblock_msg();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_msgblock_from_msgblock_msg = output;
    }
    return output;
  }
  vx_core::Func_msgblock_from_msgblock_msg t_msgblock_from_msgblock_msg() {
    vx_core::Func_msgblock_from_msgblock_msg output = vx_core::vx_package->t_msgblock_from_msgblock_msg;
    if (output == NULL) {
      output = new vx_core::Class_msgblock_from_msgblock_msg();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_msgblock_from_msgblock_msg = output;
    }
    return output;
  }

  // (func msgblock<-msgblock-msgblock)
  vx_core::Func_msgblock_from_msgblock_msgblock e_msgblock_from_msgblock_msgblock() {
    vx_core::Func_msgblock_from_msgblock_msgblock output = vx_core::vx_package->e_msgblock_from_msgblock_msgblock;
    if (output == NULL) {
      output = new vx_core::Class_msgblock_from_msgblock_msgblock();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_msgblock_from_msgblock_msgblock = output;
    }
    return output;
  }
  vx_core::Func_msgblock_from_msgblock_msgblock t_msgblock_from_msgblock_msgblock() {
    vx_core::Func_msgblock_from_msgblock_msgblock output = vx_core::vx_package->t_msgblock_from_msgblock_msgblock;
    if (output == NULL) {
      output = new vx_core::Class_msgblock_from_msgblock_msgblock();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_msgblock_from_msgblock_msgblock = output;
    }
    return output;
  }

  // (func name<-typedef)
  vx_core::Func_name_from_typedef e_name_from_typedef() {
    vx_core::Func_name_from_typedef output = vx_core::vx_package->e_name_from_typedef;
    if (output == NULL) {
      output = new vx_core::Class_name_from_typedef();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_name_from_typedef = output;
    }
    return output;
  }
  vx_core::Func_name_from_typedef t_name_from_typedef() {
    vx_core::Func_name_from_typedef output = vx_core::vx_package->t_name_from_typedef;
    if (output == NULL) {
      output = new vx_core::Class_name_from_typedef();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_name_from_typedef = output;
    }
    return output;
  }

  // (func native)
  vx_core::Func_native e_native() {
    vx_core::Func_native output = vx_core::vx_package->e_native;
    if (output == NULL) {
      output = new vx_core::Class_native();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_native = output;
    }
    return output;
  }
  vx_core::Func_native t_native() {
    vx_core::Func_native output = vx_core::vx_package->t_native;
    if (output == NULL) {
      output = new vx_core::Class_native();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_native = output;
    }
    return output;
  }

  // (func native<-any)
  vx_core::Func_native_from_any e_native_from_any() {
    vx_core::Func_native_from_any output = vx_core::vx_package->e_native_from_any;
    if (output == NULL) {
      output = new vx_core::Class_native_from_any();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_native_from_any = output;
    }
    return output;
  }
  vx_core::Func_native_from_any t_native_from_any() {
    vx_core::Func_native_from_any output = vx_core::vx_package->t_native_from_any;
    if (output == NULL) {
      output = new vx_core::Class_native_from_any();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_native_from_any = output;
    }
    return output;
  }

  // (func number<-func)
  vx_core::Func_number_from_func e_number_from_func() {
    vx_core::Func_number_from_func output = vx_core::vx_package->e_number_from_func;
    if (output == NULL) {
      output = new vx_core::Class_number_from_func();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_number_from_func = output;
    }
    return output;
  }
  vx_core::Func_number_from_func t_number_from_func() {
    vx_core::Func_number_from_func output = vx_core::vx_package->t_number_from_func;
    if (output == NULL) {
      output = new vx_core::Class_number_from_func();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_number_from_func = output;
    }
    return output;
  }

  // (func packagename<-typedef)
  vx_core::Func_packagename_from_typedef e_packagename_from_typedef() {
    vx_core::Func_packagename_from_typedef output = vx_core::vx_package->e_packagename_from_typedef;
    if (output == NULL) {
      output = new vx_core::Class_packagename_from_typedef();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_packagename_from_typedef = output;
    }
    return output;
  }
  vx_core::Func_packagename_from_typedef t_packagename_from_typedef() {
    vx_core::Func_packagename_from_typedef output = vx_core::vx_package->t_packagename_from_typedef;
    if (output == NULL) {
      output = new vx_core::Class_packagename_from_typedef();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_packagename_from_typedef = output;
    }
    return output;
  }

  // (func path<-context-path)
  vx_core::Func_path_from_context_path e_path_from_context_path() {
    vx_core::Func_path_from_context_path output = vx_core::vx_package->e_path_from_context_path;
    if (output == NULL) {
      output = new vx_core::Class_path_from_context_path();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_path_from_context_path = output;
    }
    return output;
  }
  vx_core::Func_path_from_context_path t_path_from_context_path() {
    vx_core::Func_path_from_context_path output = vx_core::vx_package->t_path_from_context_path;
    if (output == NULL) {
      output = new vx_core::Class_path_from_context_path();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_path_from_context_path = output;
    }
    return output;
  }

  // (func path<-setting-path)
  vx_core::Func_path_from_setting_path e_path_from_setting_path() {
    vx_core::Func_path_from_setting_path output = vx_core::vx_package->e_path_from_setting_path;
    if (output == NULL) {
      output = new vx_core::Class_path_from_setting_path();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_path_from_setting_path = output;
    }
    return output;
  }
  vx_core::Func_path_from_setting_path t_path_from_setting_path() {
    vx_core::Func_path_from_setting_path output = vx_core::vx_package->t_path_from_setting_path;
    if (output == NULL) {
      output = new vx_core::Class_path_from_setting_path();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_path_from_setting_path = output;
    }
    return output;
  }

  // (func permission<-id-context)
  vx_core::Func_permission_from_id_context e_permission_from_id_context() {
    vx_core::Func_permission_from_id_context output = vx_core::vx_package->e_permission_from_id_context;
    if (output == NULL) {
      output = new vx_core::Class_permission_from_id_context();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_permission_from_id_context = output;
    }
    return output;
  }
  vx_core::Func_permission_from_id_context t_permission_from_id_context() {
    vx_core::Func_permission_from_id_context output = vx_core::vx_package->t_permission_from_id_context;
    if (output == NULL) {
      output = new vx_core::Class_permission_from_id_context();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_permission_from_id_context = output;
    }
    return output;
  }

  // (func properties<-typedef)
  vx_core::Func_properties_from_typedef e_properties_from_typedef() {
    vx_core::Func_properties_from_typedef output = vx_core::vx_package->e_properties_from_typedef;
    if (output == NULL) {
      output = new vx_core::Class_properties_from_typedef();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_properties_from_typedef = output;
    }
    return output;
  }
  vx_core::Func_properties_from_typedef t_properties_from_typedef() {
    vx_core::Func_properties_from_typedef output = vx_core::vx_package->t_properties_from_typedef;
    if (output == NULL) {
      output = new vx_core::Class_properties_from_typedef();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_properties_from_typedef = output;
    }
    return output;
  }

  // (func proplast<-typedef)
  vx_core::Func_proplast_from_typedef e_proplast_from_typedef() {
    vx_core::Func_proplast_from_typedef output = vx_core::vx_package->e_proplast_from_typedef;
    if (output == NULL) {
      output = new vx_core::Class_proplast_from_typedef();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_proplast_from_typedef = output;
    }
    return output;
  }
  vx_core::Func_proplast_from_typedef t_proplast_from_typedef() {
    vx_core::Func_proplast_from_typedef output = vx_core::vx_package->t_proplast_from_typedef;
    if (output == NULL) {
      output = new vx_core::Class_proplast_from_typedef();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_proplast_from_typedef = output;
    }
    return output;
  }

  // (func resolve)
  vx_core::Func_resolve e_resolve() {
    vx_core::Func_resolve output = vx_core::vx_package->e_resolve;
    if (output == NULL) {
      output = new vx_core::Class_resolve();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_resolve = output;
    }
    return output;
  }
  vx_core::Func_resolve t_resolve() {
    vx_core::Func_resolve output = vx_core::vx_package->t_resolve;
    if (output == NULL) {
      output = new vx_core::Class_resolve();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_resolve = output;
    }
    return output;
  }

  // (func resolve)
  vx_core::Func_resolve_1 e_resolve_1() {
    vx_core::Func_resolve_1 output = vx_core::vx_package->e_resolve_1;
    if (output == NULL) {
      output = new vx_core::Class_resolve_1();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_resolve_1 = output;
    }
    return output;
  }
  vx_core::Func_resolve_1 t_resolve_1() {
    vx_core::Func_resolve_1 output = vx_core::vx_package->t_resolve_1;
    if (output == NULL) {
      output = new vx_core::Class_resolve_1();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_resolve_1 = output;
    }
    return output;
  }

  // (func resolve-async)
  vx_core::Func_resolve_async e_resolve_async() {
    vx_core::Func_resolve_async output = vx_core::vx_package->e_resolve_async;
    if (output == NULL) {
      output = new vx_core::Class_resolve_async();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_resolve_async = output;
    }
    return output;
  }
  vx_core::Func_resolve_async t_resolve_async() {
    vx_core::Func_resolve_async output = vx_core::vx_package->t_resolve_async;
    if (output == NULL) {
      output = new vx_core::Class_resolve_async();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_resolve_async = output;
    }
    return output;
  }

  // (func resolve-first)
  vx_core::Func_resolve_first e_resolve_first() {
    vx_core::Func_resolve_first output = vx_core::vx_package->e_resolve_first;
    if (output == NULL) {
      output = new vx_core::Class_resolve_first();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_resolve_first = output;
    }
    return output;
  }
  vx_core::Func_resolve_first t_resolve_first() {
    vx_core::Func_resolve_first output = vx_core::vx_package->t_resolve_first;
    if (output == NULL) {
      output = new vx_core::Class_resolve_first();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_resolve_first = output;
    }
    return output;
  }

  // (func resolve-list)
  vx_core::Func_resolve_list e_resolve_list() {
    vx_core::Func_resolve_list output = vx_core::vx_package->e_resolve_list;
    if (output == NULL) {
      output = new vx_core::Class_resolve_list();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_resolve_list = output;
    }
    return output;
  }
  vx_core::Func_resolve_list t_resolve_list() {
    vx_core::Func_resolve_list output = vx_core::vx_package->t_resolve_list;
    if (output == NULL) {
      output = new vx_core::Class_resolve_list();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_resolve_list = output;
    }
    return output;
  }

  // (func session<-context)
  vx_core::Func_session_from_context e_session_from_context() {
    vx_core::Func_session_from_context output = vx_core::vx_package->e_session_from_context;
    if (output == NULL) {
      output = new vx_core::Class_session_from_context();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_session_from_context = output;
    }
    return output;
  }
  vx_core::Func_session_from_context t_session_from_context() {
    vx_core::Func_session_from_context output = vx_core::vx_package->t_session_from_context;
    if (output == NULL) {
      output = new vx_core::Class_session_from_context();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_session_from_context = output;
    }
    return output;
  }

  // (func setting<-context)
  vx_core::Func_setting_from_context e_setting_from_context() {
    vx_core::Func_setting_from_context output = vx_core::vx_package->e_setting_from_context;
    if (output == NULL) {
      output = new vx_core::Class_setting_from_context();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_setting_from_context = output;
    }
    return output;
  }
  vx_core::Func_setting_from_context t_setting_from_context() {
    vx_core::Func_setting_from_context output = vx_core::vx_package->t_setting_from_context;
    if (output == NULL) {
      output = new vx_core::Class_setting_from_context();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_setting_from_context = output;
    }
    return output;
  }

  // (func string-repeat)
  vx_core::Func_string_repeat e_string_repeat() {
    vx_core::Func_string_repeat output = vx_core::vx_package->e_string_repeat;
    if (output == NULL) {
      output = new vx_core::Class_string_repeat();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_string_repeat = output;
    }
    return output;
  }
  vx_core::Func_string_repeat t_string_repeat() {
    vx_core::Func_string_repeat output = vx_core::vx_package->t_string_repeat;
    if (output == NULL) {
      output = new vx_core::Class_string_repeat();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_string_repeat = output;
    }
    return output;
  }

  // (func string<-any)
  vx_core::Func_string_from_any e_string_from_any() {
    vx_core::Func_string_from_any output = vx_core::vx_package->e_string_from_any;
    if (output == NULL) {
      output = new vx_core::Class_string_from_any();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_string_from_any = output;
    }
    return output;
  }
  vx_core::Func_string_from_any t_string_from_any() {
    vx_core::Func_string_from_any output = vx_core::vx_package->t_string_from_any;
    if (output == NULL) {
      output = new vx_core::Class_string_from_any();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_string_from_any = output;
    }
    return output;
  }

  // (func string<-any-indent)
  vx_core::Func_string_from_any_indent e_string_from_any_indent() {
    vx_core::Func_string_from_any_indent output = vx_core::vx_package->e_string_from_any_indent;
    if (output == NULL) {
      output = new vx_core::Class_string_from_any_indent();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_string_from_any_indent = output;
    }
    return output;
  }
  vx_core::Func_string_from_any_indent t_string_from_any_indent() {
    vx_core::Func_string_from_any_indent output = vx_core::vx_package->t_string_from_any_indent;
    if (output == NULL) {
      output = new vx_core::Class_string_from_any_indent();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_string_from_any_indent = output;
    }
    return output;
  }

  // (func string<-func)
  vx_core::Func_string_from_func e_string_from_func() {
    vx_core::Func_string_from_func output = vx_core::vx_package->e_string_from_func;
    if (output == NULL) {
      output = new vx_core::Class_string_from_func();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_string_from_func = output;
    }
    return output;
  }
  vx_core::Func_string_from_func t_string_from_func() {
    vx_core::Func_string_from_func output = vx_core::vx_package->t_string_from_func;
    if (output == NULL) {
      output = new vx_core::Class_string_from_func();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_string_from_func = output;
    }
    return output;
  }

  // (func traits<-typedef)
  vx_core::Func_traits_from_typedef e_traits_from_typedef() {
    vx_core::Func_traits_from_typedef output = vx_core::vx_package->e_traits_from_typedef;
    if (output == NULL) {
      output = new vx_core::Class_traits_from_typedef();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_traits_from_typedef = output;
    }
    return output;
  }
  vx_core::Func_traits_from_typedef t_traits_from_typedef() {
    vx_core::Func_traits_from_typedef output = vx_core::vx_package->t_traits_from_typedef;
    if (output == NULL) {
      output = new vx_core::Class_traits_from_typedef();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_traits_from_typedef = output;
    }
    return output;
  }

  // (func type<-any)
  vx_core::Func_type_from_any e_type_from_any() {
    vx_core::Func_type_from_any output = vx_core::vx_package->e_type_from_any;
    if (output == NULL) {
      output = new vx_core::Class_type_from_any();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_type_from_any = output;
    }
    return output;
  }
  vx_core::Func_type_from_any t_type_from_any() {
    vx_core::Func_type_from_any output = vx_core::vx_package->t_type_from_any;
    if (output == NULL) {
      output = new vx_core::Class_type_from_any();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_type_from_any = output;
    }
    return output;
  }

  // (func typedef<-any)
  vx_core::Func_typedef_from_any e_typedef_from_any() {
    vx_core::Func_typedef_from_any output = vx_core::vx_package->e_typedef_from_any;
    if (output == NULL) {
      output = new vx_core::Class_typedef_from_any();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_typedef_from_any = output;
    }
    return output;
  }
  vx_core::Func_typedef_from_any t_typedef_from_any() {
    vx_core::Func_typedef_from_any output = vx_core::vx_package->t_typedef_from_any;
    if (output == NULL) {
      output = new vx_core::Class_typedef_from_any();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_typedef_from_any = output;
    }
    return output;
  }

  // (func typedef<-type)
  vx_core::Func_typedef_from_type e_typedef_from_type() {
    vx_core::Func_typedef_from_type output = vx_core::vx_package->e_typedef_from_type;
    if (output == NULL) {
      output = new vx_core::Class_typedef_from_type();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_typedef_from_type = output;
    }
    return output;
  }
  vx_core::Func_typedef_from_type t_typedef_from_type() {
    vx_core::Func_typedef_from_type output = vx_core::vx_package->t_typedef_from_type;
    if (output == NULL) {
      output = new vx_core::Class_typedef_from_type();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_typedef_from_type = output;
    }
    return output;
  }

  // (func typename<-any)
  vx_core::Func_typename_from_any e_typename_from_any() {
    vx_core::Func_typename_from_any output = vx_core::vx_package->e_typename_from_any;
    if (output == NULL) {
      output = new vx_core::Class_typename_from_any();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_typename_from_any = output;
    }
    return output;
  }
  vx_core::Func_typename_from_any t_typename_from_any() {
    vx_core::Func_typename_from_any output = vx_core::vx_package->t_typename_from_any;
    if (output == NULL) {
      output = new vx_core::Class_typename_from_any();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_typename_from_any = output;
    }
    return output;
  }

  // (func typename<-type)
  vx_core::Func_typename_from_type e_typename_from_type() {
    vx_core::Func_typename_from_type output = vx_core::vx_package->e_typename_from_type;
    if (output == NULL) {
      output = new vx_core::Class_typename_from_type();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_typename_from_type = output;
    }
    return output;
  }
  vx_core::Func_typename_from_type t_typename_from_type() {
    vx_core::Func_typename_from_type output = vx_core::vx_package->t_typename_from_type;
    if (output == NULL) {
      output = new vx_core::Class_typename_from_type();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_typename_from_type = output;
    }
    return output;
  }

  // (func typename<-typedef)
  vx_core::Func_typename_from_typedef e_typename_from_typedef() {
    vx_core::Func_typename_from_typedef output = vx_core::vx_package->e_typename_from_typedef;
    if (output == NULL) {
      output = new vx_core::Class_typename_from_typedef();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_typename_from_typedef = output;
    }
    return output;
  }
  vx_core::Func_typename_from_typedef t_typename_from_typedef() {
    vx_core::Func_typename_from_typedef output = vx_core::vx_package->t_typename_from_typedef;
    if (output == NULL) {
      output = new vx_core::Class_typename_from_typedef();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_typename_from_typedef = output;
    }
    return output;
  }

  // (func typenames<-typelist)
  vx_core::Func_typenames_from_typelist e_typenames_from_typelist() {
    vx_core::Func_typenames_from_typelist output = vx_core::vx_package->e_typenames_from_typelist;
    if (output == NULL) {
      output = new vx_core::Class_typenames_from_typelist();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_typenames_from_typelist = output;
    }
    return output;
  }
  vx_core::Func_typenames_from_typelist t_typenames_from_typelist() {
    vx_core::Func_typenames_from_typelist output = vx_core::vx_package->t_typenames_from_typelist;
    if (output == NULL) {
      output = new vx_core::Class_typenames_from_typelist();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_typenames_from_typelist = output;
    }
    return output;
  }

  // (func user<-context)
  vx_core::Func_user_from_context e_user_from_context() {
    vx_core::Func_user_from_context output = vx_core::vx_package->e_user_from_context;
    if (output == NULL) {
      output = new vx_core::Class_user_from_context();
      vx_core::vx_reserve_empty(output);
      vx_core::vx_package->e_user_from_context = output;
    }
    return output;
  }
  vx_core::Func_user_from_context t_user_from_context() {
    vx_core::Func_user_from_context output = vx_core::vx_package->t_user_from_context;
    if (output == NULL) {
      output = new vx_core::Class_user_from_context();
      vx_core::vx_reserve_type(output);
      vx_core::vx_package->t_user_from_context = output;
    }
    return output;
  }

}