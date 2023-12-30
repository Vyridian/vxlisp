#include <map>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/collection.hpp"
#include "../../vx/data/file.hpp"
#include "../../vx/data/textblock.hpp"
#include "../../vx/type.hpp"
#include "csv.hpp"

namespace vx_data_csv {


  // (type csv)
  // class Class_csv {
    Abstract_csv::~Abstract_csv() {}

    Class_csv::Class_csv() : Abstract_csv::Abstract_csv() {
      vx_core::refcount += 1;
    }

    Class_csv::~Class_csv() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      vx_core::vx_release_one({
        this->vx_p_headers,
        this->vx_p_rows
      });
    }

    // headers()
    vx_core::Type_stringlist Class_csv::headers() const {
      vx_core::Type_stringlist output = this->vx_p_headers;
      if (!output) {
        output = vx_core::e_stringlist;
      }
      return output;
    }

    // rows()
    vx_data_csv::Type_csvrows Class_csv::rows() const {
      vx_data_csv::Type_csvrows output = this->vx_p_rows;
      if (!output) {
        output = vx_data_csv::e_csvrows;
      }
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_csv::vx_get_any(vx_core::Type_string key) const {
      vx_core::Type_any output = vx_core::e_any;
      std::string skey = key->vx_string();
      if (false) {
      } else if (skey == ":headers") {
        output = this->headers();
      } else if (skey == ":rows") {
        output = this->rows();
      }
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_csv::vx_map() const {
      vx_core::vx_Type_mapany output;
      output[":headers"] = this->headers();
      output[":rows"] = this->rows();
      return output;
    }

    vx_core::Type_any Class_csv::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_csv::e_csv, vals);
    }

    vx_core::Type_any Class_csv::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_csv::Type_csv output = vx_data_csv::e_csv;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_csv::Type_csv val = vx_core::vx_any_from_any(vx_data_csv::t_csv, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      vx_core::Type_stringlist vx_p_headers = val->headers();
      vx_data_csv::Type_csvrows vx_p_rows = val->rows();
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
          } else if (testkey == ":headers") {
            key = testkey;
          } else if (testkey == ":rows") {
            key = testkey;
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new csv) - Invalid Key Type: " + vx_core::vx_string_from_any(valsub));
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
        } else {
          if (false) {
          } else if (key == ":headers") {
            if (vx_p_headers == valsub) {
            } else if (valsubtype == vx_core::t_stringlist) {
              ischanged = true;
              vx_p_headers = vx_core::vx_any_from_any(vx_core::t_stringlist, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new csv :headers " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else if (key == ":rows") {
            if (vx_p_rows == valsub) {
            } else if (valsubtype == vx_data_csv::t_csvrows) {
              ischanged = true;
              vx_p_rows = vx_core::vx_any_from_any(vx_data_csv::t_csvrows, valsub);
            } else {
              vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new csv :rows " + vx_core::vx_string_from_any(valsub) + ") - Invalid Value");
              msgblock = vx_core::vx_copy(msgblock, {msg});
            }
          } else {
            vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new csv) - Invalid Key: " + key);
            msgblock = vx_core::vx_copy(msgblock, {msg});
          }
          key = "";
        }
      }
      if (ischanged || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_csv::Class_csv();
        if (output->vx_p_headers != vx_p_headers) {
          if (output->vx_p_headers) {
            vx_core::vx_release_one(output->vx_p_headers);
          }
          output->vx_p_headers = vx_p_headers;
          vx_core::vx_reserve(vx_p_headers);
        }
        if (output->vx_p_rows != vx_p_rows) {
          if (output->vx_p_rows) {
            vx_core::vx_release_one(output->vx_p_rows);
          }
          output->vx_p_rows = vx_p_rows;
          vx_core::vx_reserve(vx_p_rows);
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

    vx_core::Type_msgblock Class_csv::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_csv::Class_csv::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_csv::vx_empty() const {return vx_data_csv::e_csv;}
    vx_core::Type_any Class_csv::vx_type() const {return vx_data_csv::t_csv;}

    vx_core::Type_typedef Class_csv::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/csv", // pkgname
        "csv", // name
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
            "headers", // name
            vx_core::t_stringlist // type
          ),
          vx_core::vx_new_arg(
            "rows", // name
            vx_data_csv::t_csvrows // type
          )
        }) // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_csv::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type csvrowmap)
  // class Class_csvrowmap {
    Abstract_csvrowmap::~Abstract_csvrowmap() {}

    Class_csvrowmap::Class_csvrowmap() : Abstract_csvrowmap::Abstract_csvrowmap() {
      vx_core::refcount += 1;
    }

    Class_csvrowmap::~Class_csvrowmap() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (auto const& [key, val] : this->vx_p_map) {
        vx_core::vx_release_one(val);
      }
    }

    // vx_map()
    vx_core::vx_Type_mapany Class_csvrowmap::vx_map() const {
      vx_core::vx_Type_mapany output = vx_core::vx_map_from_map(vx_core::t_any, this->vx_p_map);
      return output;
    }

    // vx_get_stringlist(key)
    vx_core::Type_stringlist Class_csvrowmap::vx_get_stringlist(vx_core::Type_string key) const {
      vx_core::Type_stringlist output = vx_core::e_stringlist;
      const vx_data_csv::Class_csvrowmap* map = this;
      std::string skey = key->vx_string();
      if (vx_core::vx_boolean_from_string_starts(skey, ":")) {
        skey = vx_core::vx_string_from_string_start(skey, 2);
      }
      std::map<std::string, vx_core::Type_stringlist> mapval = map->vx_p_map;
      output = vx_core::vx_any_from_map(mapval, skey, vx_core::e_stringlist);
      vx_core::vx_release_except(key, output);
      return output;
    }

    // vx_get_any(key)
    vx_core::Type_any Class_csvrowmap::vx_get_any(vx_core::Type_string key) const {
      return this->vx_get_stringlist(key);
    }

    // vx_mapstringlist()
    std::map<std::string, vx_core::Type_stringlist> Class_csvrowmap::vx_mapstringlist() const {return this->vx_p_map;}

    // vx_new_from_map(mapval)
    vx_core::Type_any Class_csvrowmap::vx_new_from_map(vx_core::vx_Type_mapany mapval) const {
      vx_data_csv::Type_csvrowmap output = vx_data_csv::e_csvrowmap;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::map<std::string, vx_core::Type_stringlist> map;
      for (auto const& iter : mapval) {
        std::string key = iter.first;
        vx_core::Type_any val = iter.second;
        vx_core::Type_any valtype = val->vx_type();
        if (valtype == vx_core::t_stringlist) {
          vx_core::Type_stringlist castval = vx_core::vx_any_from_any(vx_core::t_stringlist, val);
          map[key] = castval;
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(csvrowmap) Invalid Value: " + vx_core::vx_string_from_any(val) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((map.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_csv::Class_csvrowmap();
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

    vx_core::Type_any Class_csvrowmap::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_csv::e_csvrowmap, vals);
    }

    vx_core::Type_any Class_csvrowmap::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_csv::Type_csvrowmap output = vx_data_csv::e_csvrowmap;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_csv::Type_csvrowmap valmap = vx_core::vx_any_from_any(vx_data_csv::t_csvrowmap, copyval);
      output = valmap;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(valmap->vx_msgblock(), vals);
      std::map<std::string, vx_core::Type_stringlist> mapval = valmap->vx_mapstringlist();
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
          vx_core::Type_stringlist valany = NULL;
          if (valsubtype == vx_core::t_stringlist) {
            valany = vx_core::vx_any_from_any(vx_core::t_stringlist, valsub);
          } else if (valsubtype == vx_core::t_stringlist) {
            valany = vx_core::vx_any_from_any(vx_core::t_stringlist, valsub);
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
        output = new vx_data_csv::Class_csvrowmap();
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

    vx_core::Type_msgblock Class_csvrowmap::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_csv::Class_csvrowmap::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_csvrowmap::vx_empty() const {return vx_data_csv::e_csvrowmap;}
    vx_core::Type_any Class_csvrowmap::vx_type() const {return vx_data_csv::t_csvrowmap;}

    vx_core::Type_typedef Class_csvrowmap::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/csv", // pkgname
        "csvrowmap", // name
        ":map", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_core::t_stringlist}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_csvrowmap::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (type csvrows)
  // class Class_csvrows {
    Abstract_csvrows::~Abstract_csvrows() {}

    Class_csvrows::Class_csvrows() : Abstract_csvrows::Abstract_csvrows() {
      vx_core::refcount += 1;
    }

    Class_csvrows::~Class_csvrows() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
      for (vx_core::Type_any any : this->vx_p_list) {
        vx_core::vx_release_one(any);
      }
    }

    // vx_list()
    vx_core::vx_Type_listany Class_csvrows::vx_list() const {
      return vx_core::vx_list_from_list(vx_core::t_any, this->vx_p_list);
    }

    vx_core::Type_stringlist Class_csvrows::vx_get_stringlist(vx_core::Type_int index) const {
      vx_core::Type_stringlist output = vx_core::e_stringlist;
      long iindex = index->vx_int();
      std::vector<vx_core::Type_stringlist> listval = this->vx_p_list;
      if ((unsigned long long)iindex < listval.size()) {
        output = listval[iindex];
      }
      vx_core::vx_release_except(index, output);
      return output;
    }

    std::vector<vx_core::Type_stringlist> Class_csvrows::vx_liststringlist() const {return vx_p_list;}

    vx_core::Type_any vx_data_csv::Class_csvrows::vx_get_any(vx_core::Type_int index) const {
      return this->vx_get_stringlist(index);
    }

    // vx_new_from_list(listval)
    vx_core::Type_any Class_csvrows::vx_new_from_list(vx_core::vx_Type_listany listval) const {
      vx_data_csv::Type_csvrows output = vx_data_csv::e_csvrows;
      vx_core::Type_msgblock msgblock = vx_core::e_msgblock;
      std::vector<vx_core::Type_stringlist> list;
      for (auto const& valsub : listval) {
        vx_core::Type_any valtype = valsub->vx_type();
        if (valtype == vx_core::t_stringlist) {
          vx_core::Type_stringlist castval = vx_core::vx_any_from_any(vx_core::t_stringlist, valsub);
          list.push_back(castval);
        } else if (vx_core::vx_boolean_from_type_trait(valtype, vx_core::t_stringlist)) {
          vx_core::Type_stringlist castval = vx_core::vx_any_from_any(vx_core::t_stringlist, valsub);
          list.push_back(castval);
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(csvrows) Invalid Value: " + vx_core::vx_string_from_any(valsub) + "");
          msgblock = vx_core::vx_copy(msgblock, {msgblock, msg});
        }
      }
      if ((list.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_csv::Class_csvrows();
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

    vx_core::Type_any Class_csvrows::vx_new(vx_core::vx_Type_listany vals) const {
      return this->vx_copy(vx_data_csv::e_csvrows, vals);
    }

    vx_core::Type_any Class_csvrows::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_csv::Type_csvrows output = vx_data_csv::e_csvrows;
      bool ischanged = false;
      if (copyval->vx_p_constdef != NULL) {
        ischanged = true;
      }
      vx_data_csv::Type_csvrows val = vx_core::vx_any_from_any(vx_data_csv::t_csvrows, copyval);
      output = val;
      vx_core::Type_msgblock msgblock = vx_core::vx_msgblock_from_copy_listval(val->vx_msgblock(), vals);
      std::vector<vx_core::Type_stringlist> listval = val->vx_liststringlist();
      for (vx_core::Type_any valsub : vals) {
        vx_core::Type_any valsubtype = valsub->vx_type();
        if (valsubtype == vx_core::t_msgblock) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_msg) {
          msgblock = vx_core::vx_copy(msgblock, {valsub});
        } else if (valsubtype == vx_core::t_stringlist) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_stringlist, valsub));
        } else if (vx_core::vx_boolean_from_type_trait(valsubtype, vx_core::t_stringlist)) {
          ischanged = true;
          listval.push_back(vx_core::vx_any_from_any(vx_core::t_stringlist, valsub));
        } else if (valsubtype == vx_data_csv::t_csvrows) {
          ischanged = true;
          vx_data_csv::Type_csvrows multi = vx_core::vx_any_from_any(vx_data_csv::t_csvrows, valsub);
          listval = vx_core::vx_listaddall(listval, multi->vx_liststringlist());
        } else {
          vx_core::Type_msg msg = vx_core::vx_msg_from_errortext("(new csvrows) - Invalid Type: " + vx_core::vx_string_from_any(valsub));
          msgblock = vx_core::vx_copy(msgblock, {msg});
        }
      }
      if (ischanged || (listval.size() > 0) || (msgblock != vx_core::e_msgblock)) {
        output = new vx_data_csv::Class_csvrows();
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

    vx_core::Type_msgblock Class_csvrows::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany vx_data_csv::Class_csvrows::vx_dispose() {return vx_core::emptylistany;}
    vx_core::Type_any Class_csvrows::vx_empty() const {return vx_data_csv::e_csvrows;}
    vx_core::Type_any Class_csvrows::vx_type() const {return vx_data_csv::t_csvrows;}

    vx_core::Type_typedef Class_csvrows::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/csv", // pkgname
        "csvrows", // name
        ":list", // extends
        vx_core::e_typelist, // traits
        vx_core::vx_typelist_from_listany({vx_core::t_stringlist}), // allowtypes
        vx_core::e_typelist, // disallowtypes
        vx_core::e_funclist, // allowfuncs
        vx_core::e_funclist, // disallowfuncs
        vx_core::e_anylist, // allowvalues
        vx_core::e_anylist, // disallowvalues
        vx_core::e_argmap // properties
      );
      return output;
    }

    vx_core::Type_constdef Class_csvrows::vx_constdef() const {return this->vx_p_constdef;}


  //}

  // (const delimcsv)
  // class Class_delimcsv {
    // vx_const_new()
    void vx_data_csv::Class_delimcsv::vx_const_new(vx_data_csv::Const_delimcsv output) {
      output->vx_p_constdef = vx_core::vx_constdef_new("vx/data/csv", "delimcsv");
      long irefcount = vx_core::refcount;
      vx_data_textblock::Type_delim val = vx_core::f_new(
        vx_data_textblock::t_delim,
        vx_core::vx_new(vx_core::t_anylist, {
          vx_core::vx_new_string(":name"),
          vx_core::vx_new_string("delimcsv"),
          vx_core::vx_new_string(":delimlist"),
          vx_core::f_new(
            vx_data_textblock::t_delimlist,
            vx_core::vx_new(vx_core::t_anylist, {
              vx_data_textblock::c_delimline,
              vx_data_textblock::c_delimquote,
              vx_data_textblock::c_delimcomma
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

  // (func csv-read<-file)
  vx_data_csv::Type_csv f_csv_read_from_file(vx_core::Type_context context, vx_data_file::Type_file file) {
    vx_data_csv::Type_csv output = vx_data_csv::e_csv;
    vx_core::vx_reserve(file);
    output = vx_core::f_let(
      vx_data_csv::t_csv,
      vx_core::t_any_from_func->vx_fn_new({context, file}, [context, file]() {
        vx_data_file::Type_file loaded = vx_data_file::f_file_read_from_file(context, file);
        vx_core::vx_ref_plus(loaded);
        vx_data_csv::Type_csv output_1 = vx_data_csv::f_csv_from_file(loaded);
        vx_core::vx_release_one_except(loaded, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(file, output);
    return output;
  }

  // (func csv-read<-file)
  // class Class_csv_read_from_file {
    Abstract_csv_read_from_file::~Abstract_csv_read_from_file() {}

    Class_csv_read_from_file::Class_csv_read_from_file() : Abstract_csv_read_from_file::Abstract_csv_read_from_file() {
      vx_core::refcount += 1;
    }

    Class_csv_read_from_file::~Class_csv_read_from_file() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_csv_read_from_file::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_csv::Func_csv_read_from_file output = vx_data_csv::e_csv_read_from_file;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_csv_read_from_file::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_csv::Func_csv_read_from_file output = vx_data_csv::e_csv_read_from_file;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_csv_read_from_file::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/csv", // pkgname
        "csv-read<-file", // name
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

    vx_core::Type_constdef Class_csv_read_from_file::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_csv_read_from_file::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/csv", // pkgname
        "csv-read<-file", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_csv_read_from_file::vx_empty() const {return vx_data_csv::e_csv_read_from_file;}
    vx_core::Type_any Class_csv_read_from_file::vx_type() const {return vx_data_csv::t_csv_read_from_file;}
    vx_core::Type_msgblock Class_csv_read_from_file::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_csv_read_from_file::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any_context Class_csv_read_from_file::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const {
      return vx_core::e_any_from_any_context;
    }

    vx_core::Type_any Class_csv_read_from_file::vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file inputval = vx_core::vx_any_from_any(vx_data_file::t_file, val);
      output = vx_data_csv::f_csv_read_from_file(context, inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_csv_read_from_file::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_context context = vx_core::vx_any_from_any(vx_core::t_context, arglist->vx_get_any(vx_core::vx_new_int(0)));
      vx_data_file::Type_file file = vx_core::vx_any_from_any(vx_data_file::t_file, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_csv::f_csv_read_from_file(context, file);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func csv<-file)
  vx_data_csv::Type_csv f_csv_from_file(vx_data_file::Type_file file) {
    vx_data_csv::Type_csv output = vx_data_csv::e_csv;
    vx_core::vx_reserve(file);
    output = vx_core::f_let(
      vx_data_csv::t_csv,
      vx_core::t_any_from_func->vx_fn_new({file}, [file]() {
        vx_core::Type_string text = file->text();
        vx_core::vx_ref_plus(text);
        vx_data_csv::Type_csv output_1 = vx_data_csv::f_csv_from_string(text);
        vx_core::vx_release_one_except(text, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(file, output);
    return output;
  }

  // (func csv<-file)
  // class Class_csv_from_file {
    Abstract_csv_from_file::~Abstract_csv_from_file() {}

    Class_csv_from_file::Class_csv_from_file() : Abstract_csv_from_file::Abstract_csv_from_file() {
      vx_core::refcount += 1;
    }

    Class_csv_from_file::~Class_csv_from_file() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_csv_from_file::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_csv::Func_csv_from_file output = vx_data_csv::e_csv_from_file;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_csv_from_file::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_csv::Func_csv_from_file output = vx_data_csv::e_csv_from_file;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_csv_from_file::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/csv", // pkgname
        "csv<-file", // name
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

    vx_core::Type_constdef Class_csv_from_file::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_csv_from_file::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/csv", // pkgname
        "csv<-file", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_csv_from_file::vx_empty() const {return vx_data_csv::e_csv_from_file;}
    vx_core::Type_any Class_csv_from_file::vx_type() const {return vx_data_csv::t_csv_from_file;}
    vx_core::Type_msgblock Class_csv_from_file::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_csv_from_file::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_csv_from_file::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_csv_from_file::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file inputval = vx_core::vx_any_from_any(vx_data_file::t_file, val);
      output = vx_data_csv::f_csv_from_file(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_csv_from_file::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_file::Type_file file = vx_core::vx_any_from_any(vx_data_file::t_file, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_csv::f_csv_from_file(file);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func csv<-string)
  vx_data_csv::Type_csv f_csv_from_string(vx_core::Type_string text) {
    vx_data_csv::Type_csv output = vx_data_csv::e_csv;
    vx_core::vx_reserve(text);
    output = vx_data_csv::f_csv_from_textblock(
      vx_data_textblock::f_textblock_parse_from_string_delim(
        text,
        vx_data_csv::c_delimcsv
      )
    );
    vx_core::vx_release_one_except(text, output);
    return output;
  }

  // (func csv<-string)
  // class Class_csv_from_string {
    Abstract_csv_from_string::~Abstract_csv_from_string() {}

    Class_csv_from_string::Class_csv_from_string() : Abstract_csv_from_string::Abstract_csv_from_string() {
      vx_core::refcount += 1;
    }

    Class_csv_from_string::~Class_csv_from_string() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_csv_from_string::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_csv::Func_csv_from_string output = vx_data_csv::e_csv_from_string;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_csv_from_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_csv::Func_csv_from_string output = vx_data_csv::e_csv_from_string;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_csv_from_string::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/csv", // pkgname
        "csv<-string", // name
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

    vx_core::Type_constdef Class_csv_from_string::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_csv_from_string::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/csv", // pkgname
        "csv<-string", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_csv_from_string::vx_empty() const {return vx_data_csv::e_csv_from_string;}
    vx_core::Type_any Class_csv_from_string::vx_type() const {return vx_data_csv::t_csv_from_string;}
    vx_core::Type_msgblock Class_csv_from_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_csv_from_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_csv_from_string::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_csv_from_string::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_data_csv::f_csv_from_string(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_csv_from_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_csv::f_csv_from_string(text);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func csv<-textblock)
  vx_data_csv::Type_csv f_csv_from_textblock(vx_data_textblock::Type_textblock textblock) {
    vx_data_csv::Type_csv output = vx_data_csv::e_csv;
    vx_core::vx_reserve(textblock);
    output = vx_core::f_let(
      vx_data_csv::t_csv,
      vx_core::t_any_from_func->vx_fn_new({textblock}, [textblock]() {
        vx_data_csv::Type_csvrows allrows = vx_data_csv::f_csvrows_from_textblock(textblock);
        vx_core::vx_ref_plus(allrows);
        vx_core::Type_stringlist headers = vx_core::f_any_from_list(vx_core::t_stringlist, allrows, vx_core::vx_new_int(1));
        vx_core::vx_ref_plus(headers);
        vx_data_csv::Type_csvrows rows = vx_collection::f_list_from_list_end(vx_data_csv::t_csvrows, allrows, vx_core::vx_new_int(2));
        vx_core::vx_ref_plus(rows);
        vx_data_csv::Type_csv output_1 = vx_core::f_new(
          vx_data_csv::t_csv,
          vx_core::vx_new(vx_core::t_anylist, {
            vx_core::vx_new_string(":headers"),
            headers,
            vx_core::vx_new_string(":rows"),
            rows
          })
        );
        vx_core::vx_release_one_except({allrows, headers, rows}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(textblock, output);
    return output;
  }

  // (func csv<-textblock)
  // class Class_csv_from_textblock {
    Abstract_csv_from_textblock::~Abstract_csv_from_textblock() {}

    Class_csv_from_textblock::Class_csv_from_textblock() : Abstract_csv_from_textblock::Abstract_csv_from_textblock() {
      vx_core::refcount += 1;
    }

    Class_csv_from_textblock::~Class_csv_from_textblock() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_csv_from_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_csv::Func_csv_from_textblock output = vx_data_csv::e_csv_from_textblock;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_csv_from_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_csv::Func_csv_from_textblock output = vx_data_csv::e_csv_from_textblock;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_csv_from_textblock::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/csv", // pkgname
        "csv<-textblock", // name
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

    vx_core::Type_constdef Class_csv_from_textblock::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_csv_from_textblock::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/csv", // pkgname
        "csv<-textblock", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_csv_from_textblock::vx_empty() const {return vx_data_csv::e_csv_from_textblock;}
    vx_core::Type_any Class_csv_from_textblock::vx_type() const {return vx_data_csv::t_csv_from_textblock;}
    vx_core::Type_msgblock Class_csv_from_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_csv_from_textblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_csv_from_textblock::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_csv_from_textblock::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock inputval = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, val);
      output = vx_data_csv::f_csv_from_textblock(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_csv_from_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblock = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_csv::f_csv_from_textblock(textblock);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func csvrows<-textblock)
  vx_data_csv::Type_csvrows f_csvrows_from_textblock(vx_data_textblock::Type_textblock textblock) {
    vx_data_csv::Type_csvrows output = vx_data_csv::e_csvrows;
    vx_core::vx_reserve(textblock);
    output = vx_core::f_let(
      vx_data_csv::t_csvrows,
      vx_core::t_any_from_func->vx_fn_new({textblock}, [textblock]() {
        vx_data_textblock::Type_textblock parsedtb = vx_data_textblock::f_textblock_from_textblock_delim(
          textblock,
          vx_data_csv::c_delimcsv
        );
        vx_core::vx_ref_plus(parsedtb);
        vx_data_textblock::Type_textblocklist children = vx_data_textblock::f_children_from_textblock(parsedtb);
        vx_core::vx_ref_plus(children);
        vx_core::Type_stringlist strings = vx_data_textblock::f_stringlist_from_textblocklist(children);
        vx_core::vx_ref_plus(strings);
        vx_data_csv::Type_csvrows output_1 = vx_core::f_new(
          vx_data_csv::t_csvrows,
          vx_core::vx_new(vx_core::t_anylist, {
            strings
          })
        );
        vx_core::vx_release_one_except({parsedtb, children, strings}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(textblock, output);
    return output;
  }

  // (func csvrows<-textblock)
  // class Class_csvrows_from_textblock {
    Abstract_csvrows_from_textblock::~Abstract_csvrows_from_textblock() {}

    Class_csvrows_from_textblock::Class_csvrows_from_textblock() : Abstract_csvrows_from_textblock::Abstract_csvrows_from_textblock() {
      vx_core::refcount += 1;
    }

    Class_csvrows_from_textblock::~Class_csvrows_from_textblock() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_csvrows_from_textblock::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_csv::Func_csvrows_from_textblock output = vx_data_csv::e_csvrows_from_textblock;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_csvrows_from_textblock::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_csv::Func_csvrows_from_textblock output = vx_data_csv::e_csvrows_from_textblock;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_csvrows_from_textblock::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/csv", // pkgname
        "csvrows<-textblock", // name
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

    vx_core::Type_constdef Class_csvrows_from_textblock::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_csvrows_from_textblock::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/csv", // pkgname
        "csvrows<-textblock", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_csvrows_from_textblock::vx_empty() const {return vx_data_csv::e_csvrows_from_textblock;}
    vx_core::Type_any Class_csvrows_from_textblock::vx_type() const {return vx_data_csv::t_csvrows_from_textblock;}
    vx_core::Type_msgblock Class_csvrows_from_textblock::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_csvrows_from_textblock::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_csvrows_from_textblock::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_csvrows_from_textblock::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock inputval = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, val);
      output = vx_data_csv::f_csvrows_from_textblock(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_csvrows_from_textblock::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_textblock::Type_textblock textblock = vx_core::vx_any_from_any(vx_data_textblock::t_textblock, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_csv::f_csvrows_from_textblock(textblock);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func stringmap<-csv)
  vx_core::Type_stringmap f_stringmap_from_csv(vx_data_csv::Type_csv csv) {
    vx_core::Type_stringmap output = vx_core::e_stringmap;
    vx_core::vx_reserve(csv);
    output = vx_core::f_let(
      vx_core::t_stringmap,
      vx_core::t_any_from_func->vx_fn_new({csv}, [csv]() {
        vx_data_csv::Type_csvrows rows = csv->rows();
        vx_core::vx_ref_plus(rows);
        vx_data_csv::Type_csvrowmap rowmap = vx_core::f_map_from_list(
          vx_data_csv::t_csvrowmap,
          rows,
          vx_core::t_any_from_any->vx_fn_new({}, [](vx_core::Type_any textlist_any) {
            vx_core::Type_stringlist textlist = vx_core::vx_any_from_any(vx_core::t_stringlist, textlist_any);
            vx_core::Type_any output_1 = 
              vx_core::f_any_from_list(vx_core::t_string, textlist, vx_core::vx_new_int(1));
            return output_1;
          })
        );
        vx_core::vx_ref_plus(rowmap);
        vx_core::Type_stringmap output_1 = vx_core::f_map_from_map(
          vx_core::t_stringmap,
          rowmap,
          vx_core::t_any_from_key_value->vx_fn_new({}, [](vx_core::Type_any key_any, vx_core::Type_any val_any) {
            vx_core::Type_string key = vx_core::vx_any_from_any(vx_core::t_string, key_any);
            vx_core::Type_stringlist val = vx_core::vx_any_from_any(vx_core::t_stringlist, val_any);
            vx_core::Type_any output_1 = 
              vx_core::f_any_from_list(vx_core::t_string, val, vx_core::vx_new_int(2));
            return output_1;
          })
        );
        vx_core::vx_release_one_except({rows, rowmap}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(csv, output);
    return output;
  }

  // (func stringmap<-csv)
  // class Class_stringmap_from_csv {
    Abstract_stringmap_from_csv::~Abstract_stringmap_from_csv() {}

    Class_stringmap_from_csv::Class_stringmap_from_csv() : Abstract_stringmap_from_csv::Abstract_stringmap_from_csv() {
      vx_core::refcount += 1;
    }

    Class_stringmap_from_csv::~Class_stringmap_from_csv() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_stringmap_from_csv::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_csv::Func_stringmap_from_csv output = vx_data_csv::e_stringmap_from_csv;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_stringmap_from_csv::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_csv::Func_stringmap_from_csv output = vx_data_csv::e_stringmap_from_csv;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_stringmap_from_csv::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/csv", // pkgname
        "stringmap<-csv", // name
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

    vx_core::Type_constdef Class_stringmap_from_csv::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_stringmap_from_csv::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/csv", // pkgname
        "stringmap<-csv", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_stringmap_from_csv::vx_empty() const {return vx_data_csv::e_stringmap_from_csv;}
    vx_core::Type_any Class_stringmap_from_csv::vx_type() const {return vx_data_csv::t_stringmap_from_csv;}
    vx_core::Type_msgblock Class_stringmap_from_csv::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_stringmap_from_csv::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_stringmap_from_csv::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_stringmap_from_csv::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_csv::Type_csv inputval = vx_core::vx_any_from_any(vx_data_csv::t_csv, val);
      output = vx_data_csv::f_stringmap_from_csv(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_stringmap_from_csv::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_data_csv::Type_csv csv = vx_core::vx_any_from_any(vx_data_csv::t_csv, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_csv::f_stringmap_from_csv(csv);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  // (func textblock-csv<-string)
  vx_data_textblock::Type_textblock f_textblock_csv_from_string(vx_core::Type_string text) {
    vx_data_textblock::Type_textblock output = vx_data_textblock::e_textblock;
    vx_core::vx_reserve(text);
    output = vx_data_textblock::f_textblock_parse_from_string_delim(
      text,
      vx_data_csv::c_delimcsv
    );
    vx_core::vx_release_one_except(text, output);
    return output;
  }

  // (func textblock-csv<-string)
  // class Class_textblock_csv_from_string {
    Abstract_textblock_csv_from_string::~Abstract_textblock_csv_from_string() {}

    Class_textblock_csv_from_string::Class_textblock_csv_from_string() : Abstract_textblock_csv_from_string::Abstract_textblock_csv_from_string() {
      vx_core::refcount += 1;
    }

    Class_textblock_csv_from_string::~Class_textblock_csv_from_string() {
      vx_core::refcount -= 1;
      if (this->vx_p_msgblock) {
        vx_core::vx_release_one(this->vx_p_msgblock);
      }
    }

    vx_core::Type_any Class_textblock_csv_from_string::vx_new(vx_core::vx_Type_listany vals) const {
      vx_data_csv::Func_textblock_csv_from_string output = vx_data_csv::e_textblock_csv_from_string;
      vx_core::vx_release(vals);
      return output;
    }

    vx_core::Type_any Class_textblock_csv_from_string::vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const {
      vx_data_csv::Func_textblock_csv_from_string output = vx_data_csv::e_textblock_csv_from_string;
      vx_core::vx_release_except(copyval, output);
      vx_core::vx_release_except(vals, output);
      return output;
    }

    vx_core::Type_typedef Class_textblock_csv_from_string::vx_typedef() const {
      vx_core::Type_typedef output = vx_core::Class_typedef::vx_typedef_new(
        "vx/data/csv", // pkgname
        "textblock-csv<-string", // name
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

    vx_core::Type_constdef Class_textblock_csv_from_string::vx_constdef() const {return this->vx_p_constdef;}

    vx_core::Type_funcdef Class_textblock_csv_from_string::vx_funcdef() const {
      vx_core::Type_funcdef output = vx_core::Class_funcdef::vx_funcdef_new(
        "vx/data/csv", // pkgname
        "textblock-csv<-string", // name
        0, // idx
        false, // async
        this->vx_typedef() // typedef
      );
      return output;
    }

    vx_core::Type_any Class_textblock_csv_from_string::vx_empty() const {return vx_data_csv::e_textblock_csv_from_string;}
    vx_core::Type_any Class_textblock_csv_from_string::vx_type() const {return vx_data_csv::t_textblock_csv_from_string;}
    vx_core::Type_msgblock Class_textblock_csv_from_string::vx_msgblock() const {return this->vx_p_msgblock;}
    vx_core::vx_Type_listany Class_textblock_csv_from_string::vx_dispose() {return vx_core::emptylistany;}

    vx_core::Func_any_from_any Class_textblock_csv_from_string::vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const {
      return vx_core::e_any_from_any;
    }

    vx_core::Type_any Class_textblock_csv_from_string::vx_any_from_any(vx_core::Type_any val) const {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string inputval = vx_core::vx_any_from_any(vx_core::t_string, val);
      output = vx_data_csv::f_textblock_csv_from_string(inputval);
      vx_core::vx_release_except(val, output);
      return output;
    }

    vx_core::Type_any Class_textblock_csv_from_string::vx_repl(vx_core::Type_anylist arglist) {
      vx_core::Type_any output = vx_core::e_any;
      vx_core::Type_string text = vx_core::vx_any_from_any(vx_core::t_string, arglist->vx_get_any(vx_core::vx_new_int(0)));
      output = vx_data_csv::f_textblock_csv_from_string(text);
      vx_core::vx_release_except(arglist, output);
      return output;
    }

  //}

  vx_data_csv::Type_csv e_csv = NULL;
  vx_data_csv::Type_csv t_csv = NULL;
  vx_data_csv::Type_csvrowmap e_csvrowmap = NULL;
  vx_data_csv::Type_csvrowmap t_csvrowmap = NULL;
  vx_data_csv::Type_csvrows e_csvrows = NULL;
  vx_data_csv::Type_csvrows t_csvrows = NULL;
  vx_data_csv::Const_delimcsv c_delimcsv = NULL;
  vx_data_csv::Func_csv_read_from_file e_csv_read_from_file = NULL;
  vx_data_csv::Func_csv_read_from_file t_csv_read_from_file = NULL;
  vx_data_csv::Func_csv_from_file e_csv_from_file = NULL;
  vx_data_csv::Func_csv_from_file t_csv_from_file = NULL;
  vx_data_csv::Func_csv_from_string e_csv_from_string = NULL;
  vx_data_csv::Func_csv_from_string t_csv_from_string = NULL;
  vx_data_csv::Func_csv_from_textblock e_csv_from_textblock = NULL;
  vx_data_csv::Func_csv_from_textblock t_csv_from_textblock = NULL;
  vx_data_csv::Func_csvrows_from_textblock e_csvrows_from_textblock = NULL;
  vx_data_csv::Func_csvrows_from_textblock t_csvrows_from_textblock = NULL;
  vx_data_csv::Func_stringmap_from_csv e_stringmap_from_csv = NULL;
  vx_data_csv::Func_stringmap_from_csv t_stringmap_from_csv = NULL;
  vx_data_csv::Func_textblock_csv_from_string e_textblock_csv_from_string = NULL;
  vx_data_csv::Func_textblock_csv_from_string t_textblock_csv_from_string = NULL;

  // class vx_Class_package {
    vx_Class_package::vx_Class_package() {
      init();
    }
    void vx_Class_package::init() {
      vx_data_csv::c_delimcsv = new vx_data_csv::Class_delimcsv();
      vx_data_csv::e_csv = new Class_csv();
      vx_core::vx_reserve_empty(vx_data_csv::e_csv);
      vx_data_csv::t_csv = new Class_csv();
      vx_core::vx_reserve_type(vx_data_csv::t_csv);
      vx_data_csv::e_csvrowmap = new Class_csvrowmap();
      vx_core::vx_reserve_empty(vx_data_csv::e_csvrowmap);
      vx_data_csv::t_csvrowmap = new Class_csvrowmap();
      vx_core::vx_reserve_type(vx_data_csv::t_csvrowmap);
      vx_data_csv::e_csvrows = new Class_csvrows();
      vx_core::vx_reserve_empty(vx_data_csv::e_csvrows);
      vx_data_csv::t_csvrows = new Class_csvrows();
      vx_core::vx_reserve_type(vx_data_csv::t_csvrows);
      vx_data_csv::e_csv_read_from_file = new vx_data_csv::Class_csv_read_from_file();
      vx_core::vx_reserve_empty(vx_data_csv::e_csv_read_from_file);
      vx_data_csv::t_csv_read_from_file = new vx_data_csv::Class_csv_read_from_file();
      vx_core::vx_reserve_type(vx_data_csv::t_csv_read_from_file);
      vx_data_csv::e_csv_from_file = new vx_data_csv::Class_csv_from_file();
      vx_core::vx_reserve_empty(vx_data_csv::e_csv_from_file);
      vx_data_csv::t_csv_from_file = new vx_data_csv::Class_csv_from_file();
      vx_core::vx_reserve_type(vx_data_csv::t_csv_from_file);
      vx_data_csv::e_csv_from_string = new vx_data_csv::Class_csv_from_string();
      vx_core::vx_reserve_empty(vx_data_csv::e_csv_from_string);
      vx_data_csv::t_csv_from_string = new vx_data_csv::Class_csv_from_string();
      vx_core::vx_reserve_type(vx_data_csv::t_csv_from_string);
      vx_data_csv::e_csv_from_textblock = new vx_data_csv::Class_csv_from_textblock();
      vx_core::vx_reserve_empty(vx_data_csv::e_csv_from_textblock);
      vx_data_csv::t_csv_from_textblock = new vx_data_csv::Class_csv_from_textblock();
      vx_core::vx_reserve_type(vx_data_csv::t_csv_from_textblock);
      vx_data_csv::e_csvrows_from_textblock = new vx_data_csv::Class_csvrows_from_textblock();
      vx_core::vx_reserve_empty(vx_data_csv::e_csvrows_from_textblock);
      vx_data_csv::t_csvrows_from_textblock = new vx_data_csv::Class_csvrows_from_textblock();
      vx_core::vx_reserve_type(vx_data_csv::t_csvrows_from_textblock);
      vx_data_csv::e_stringmap_from_csv = new vx_data_csv::Class_stringmap_from_csv();
      vx_core::vx_reserve_empty(vx_data_csv::e_stringmap_from_csv);
      vx_data_csv::t_stringmap_from_csv = new vx_data_csv::Class_stringmap_from_csv();
      vx_core::vx_reserve_type(vx_data_csv::t_stringmap_from_csv);
      vx_data_csv::e_textblock_csv_from_string = new vx_data_csv::Class_textblock_csv_from_string();
      vx_core::vx_reserve_empty(vx_data_csv::e_textblock_csv_from_string);
      vx_data_csv::t_textblock_csv_from_string = new vx_data_csv::Class_textblock_csv_from_string();
      vx_core::vx_reserve_type(vx_data_csv::t_textblock_csv_from_string);
      vx_data_csv::Class_delimcsv::vx_const_new(vx_data_csv::c_delimcsv);
      vx_core::vx_Type_mapany maptype;
      vx_core::vx_Type_mapany mapconst;
      vx_core::vx_Type_mapfunc mapfunc;
      vx_core::vx_Type_mapany mapempty;
      maptype["csv"] = vx_data_csv::t_csv;
      maptype["csvrowmap"] = vx_data_csv::t_csvrowmap;
      maptype["csvrows"] = vx_data_csv::t_csvrows;
      mapconst["delimcsv"] = vx_data_csv::c_delimcsv;
      mapfunc["csv-read<-file"] = vx_data_csv::t_csv_read_from_file;
      mapfunc["csv<-file"] = vx_data_csv::t_csv_from_file;
      mapfunc["csv<-string"] = vx_data_csv::t_csv_from_string;
      mapfunc["csv<-textblock"] = vx_data_csv::t_csv_from_textblock;
      mapfunc["csvrows<-textblock"] = vx_data_csv::t_csvrows_from_textblock;
      mapfunc["stringmap<-csv"] = vx_data_csv::t_stringmap_from_csv;
      mapfunc["textblock-csv<-string"] = vx_data_csv::t_textblock_csv_from_string;
      vx_core::vx_global_package_set("vx/data/csv", maptype, mapconst, mapfunc);
	   }
  // }

}
