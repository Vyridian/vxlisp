#ifndef VX_DATA_XML_HPP
#define VX_DATA_XML_HPP
#include <map>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/data/file.hpp"
#include "../../vx/data/textblock.hpp"
#include "../../vx/type.hpp"

namespace vx_data_xml {


  // forward declarations
  class Abstract_xml;
  typedef Abstract_xml* Type_xml;
  extern Type_xml e_xml;
  extern Type_xml t_xml;
  class Abstract_xmllist;
  typedef Abstract_xmllist* Type_xmllist;
  extern Type_xmllist e_xmllist;
  extern Type_xmllist t_xmllist;
  class Abstract_xmlpropmap;
  typedef Abstract_xmlpropmap* Type_xmlpropmap;
  extern Type_xmlpropmap e_xmlpropmap;
  extern Type_xmlpropmap t_xmlpropmap;
  class Class_delimxml;
  typedef Class_delimxml* Const_delimxml;
  extern Const_delimxml c_delimxml;
  class Class_delimxmlcdata;
  typedef Class_delimxmlcdata* Const_delimxmlcdata;
  extern Const_delimxmlcdata c_delimxmlcdata;
  class Class_delimxmlcomment;
  typedef Class_delimxmlcomment* Const_delimxmlcomment;
  extern Const_delimxmlcomment c_delimxmlcomment;
  class Class_delimxmlequal;
  typedef Class_delimxmlequal* Const_delimxmlequal;
  extern Const_delimxmlequal c_delimxmlequal;
  class Abstract_string_decodexml_from_string;
  typedef Abstract_string_decodexml_from_string* Func_string_decodexml_from_string;
  extern Func_string_decodexml_from_string e_string_decodexml_from_string;
  extern Func_string_decodexml_from_string t_string_decodexml_from_string;
  class Abstract_string_first_from_xml;
  typedef Abstract_string_first_from_xml* Func_string_first_from_xml;
  extern Func_string_first_from_xml e_string_first_from_xml;
  extern Func_string_first_from_xml t_string_first_from_xml;
  class Abstract_textblock_xml_from_string;
  typedef Abstract_textblock_xml_from_string* Func_textblock_xml_from_string;
  extern Func_textblock_xml_from_string e_textblock_xml_from_string;
  extern Func_textblock_xml_from_string t_textblock_xml_from_string;
  class Abstract_xml_angle_from_xml_textblock;
  typedef Abstract_xml_angle_from_xml_textblock* Func_xml_angle_from_xml_textblock;
  extern Func_xml_angle_from_xml_textblock e_xml_angle_from_xml_textblock;
  extern Func_xml_angle_from_xml_textblock t_xml_angle_from_xml_textblock;
  class Abstract_xml_close_from_xml_textblock;
  typedef Abstract_xml_close_from_xml_textblock* Func_xml_close_from_xml_textblock;
  extern Func_xml_close_from_xml_textblock e_xml_close_from_xml_textblock;
  extern Func_xml_close_from_xml_textblock t_xml_close_from_xml_textblock;
  class Abstract_xml_parse_from_xml_textblock;
  typedef Abstract_xml_parse_from_xml_textblock* Func_xml_parse_from_xml_textblock;
  extern Func_xml_parse_from_xml_textblock e_xml_parse_from_xml_textblock;
  extern Func_xml_parse_from_xml_textblock t_xml_parse_from_xml_textblock;
  class Abstract_xml_parse_from_xml_textblocklist;
  typedef Abstract_xml_parse_from_xml_textblocklist* Func_xml_parse_from_xml_textblocklist;
  extern Func_xml_parse_from_xml_textblocklist e_xml_parse_from_xml_textblocklist;
  extern Func_xml_parse_from_xml_textblocklist t_xml_parse_from_xml_textblocklist;
  class Abstract_xml_properties_from_xml_textblocklist;
  typedef Abstract_xml_properties_from_xml_textblocklist* Func_xml_properties_from_xml_textblocklist;
  extern Func_xml_properties_from_xml_textblocklist e_xml_properties_from_xml_textblocklist;
  extern Func_xml_properties_from_xml_textblocklist t_xml_properties_from_xml_textblocklist;
  class Abstract_xml_property_from_xml_textblock;
  typedef Abstract_xml_property_from_xml_textblock* Func_xml_property_from_xml_textblock;
  extern Func_xml_property_from_xml_textblock e_xml_property_from_xml_textblock;
  extern Func_xml_property_from_xml_textblock t_xml_property_from_xml_textblock;
  class Abstract_xml_read_from_file;
  typedef Abstract_xml_read_from_file* Func_xml_read_from_file;
  extern Func_xml_read_from_file e_xml_read_from_file;
  extern Func_xml_read_from_file t_xml_read_from_file;
  class Abstract_xml_text_from_xml_textblock;
  typedef Abstract_xml_text_from_xml_textblock* Func_xml_text_from_xml_textblock;
  extern Func_xml_text_from_xml_textblock e_xml_text_from_xml_textblock;
  extern Func_xml_text_from_xml_textblock t_xml_text_from_xml_textblock;
  class Abstract_xml_from_file;
  typedef Abstract_xml_from_file* Func_xml_from_file;
  extern Func_xml_from_file e_xml_from_file;
  extern Func_xml_from_file t_xml_from_file;
  class Abstract_xml_from_string;
  typedef Abstract_xml_from_string* Func_xml_from_string;
  extern Func_xml_from_string e_xml_from_string;
  extern Func_xml_from_string t_xml_from_string;
  class Abstract_xml_from_textblock;
  typedef Abstract_xml_from_textblock* Func_xml_from_textblock;
  extern Func_xml_from_textblock e_xml_from_textblock;
  extern Func_xml_from_textblock t_xml_from_textblock;
  // (func string-decodexml<-string)
  vx_core::Type_string f_string_decodexml_from_string(vx_core::Type_string text);

  // (func string-first<-xml)
  vx_core::Type_string f_string_first_from_xml(vx_data_xml::Type_xml xml);

  // (func textblock-xml<-string)
  vx_data_textblock::Type_textblock f_textblock_xml_from_string(vx_core::Type_string text);

  // (func xml-angle<-xml-textblock)
  vx_data_xml::Type_xml f_xml_angle_from_xml_textblock(vx_data_xml::Type_xml xmlarg, vx_data_textblock::Type_textblock tb);

  // (func xml-close<-xml-textblock)
  vx_data_xml::Type_xml f_xml_close_from_xml_textblock(vx_data_xml::Type_xml xmlarg, vx_data_textblock::Type_textblock tb);

  // (func xml-parse<-xml-textblock)
  vx_data_xml::Type_xml f_xml_parse_from_xml_textblock(vx_data_xml::Type_xml xmlarg, vx_data_textblock::Type_textblock tb);

  // (func xml-parse<-xml-textblocklist)
  vx_data_xml::Type_xml f_xml_parse_from_xml_textblocklist(vx_data_xml::Type_xml xmlarg, vx_data_textblock::Type_textblocklist textblocklist);

  // (func xml-properties<-xml-textblocklist)
  vx_data_xml::Type_xml f_xml_properties_from_xml_textblocklist(vx_data_xml::Type_xml xmlarg, vx_data_textblock::Type_textblocklist textblocklist);

  // (func xml-property<-xml-textblock)
  vx_data_xml::Type_xml f_xml_property_from_xml_textblock(vx_data_xml::Type_xml xmlarg, vx_data_textblock::Type_textblock tbarg);

  // (func xml-read<-file)
  vx_data_xml::Type_xml f_xml_read_from_file(vx_core::Type_context context, vx_data_file::Type_file file);

  // (func xml-text<-xml-textblock)
  vx_data_xml::Type_xml f_xml_text_from_xml_textblock(vx_data_xml::Type_xml xmlarg, vx_data_textblock::Type_textblock tb);

  // (func xml<-file)
  vx_data_xml::Type_xml f_xml_from_file(vx_data_file::Type_file file);

  // (func xml<-string)
  vx_data_xml::Type_xml f_xml_from_string(vx_core::Type_string text);

  // (func xml<-textblock)
  vx_data_xml::Type_xml f_xml_from_textblock(vx_data_textblock::Type_textblock textblock);

  // (type xml)
  class Abstract_xml : public virtual vx_core::Abstract_struct {
  public:
    Abstract_xml() {};
    virtual ~Abstract_xml() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // tag()
    vx_core::Type_string vx_p_tag = NULL;
    virtual vx_core::Type_string tag() const = 0;
    // text()
    vx_core::Type_string vx_p_text = NULL;
    virtual vx_core::Type_string text() const = 0;
    // prop()
    vx_core::Type_string vx_p_prop = NULL;
    virtual vx_core::Type_string prop() const = 0;
    // propmap()
    vx_core::Type_stringmap vx_p_propmap = NULL;
    virtual vx_core::Type_stringmap propmap() const = 0;
    // children()
    vx_data_xml::Type_xmllist vx_p_children = NULL;
    virtual vx_data_xml::Type_xmllist children() const = 0;
    // parent()
    vx_data_xml::Type_xml vx_p_parent = NULL;
    virtual vx_data_xml::Type_xml parent() const = 0;
  };
  class Class_xml : public virtual Abstract_xml {
  public:
    Class_xml();
    virtual ~Class_xml() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string tag() const override;
    virtual vx_core::Type_string text() const override;
    virtual vx_core::Type_string prop() const override;
    virtual vx_core::Type_stringmap propmap() const override;
    virtual vx_data_xml::Type_xmllist children() const override;
    virtual vx_data_xml::Type_xml parent() const override;
  };

  // (type xmllist)
  class Abstract_xmllist : public virtual vx_core::Abstract_list {
  public:
    Abstract_xmllist() {};
    virtual ~Abstract_xmllist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_data_xml::Type_xml> vx_p_list;
    // vx_listxml()
    virtual std::vector<vx_data_xml::Type_xml> vx_listxml() const = 0;
    // vx_get_xml(index)
    virtual vx_data_xml::Type_xml vx_get_xml(vx_core::Type_int index) const = 0;
  };
  class Class_xmllist : public virtual Abstract_xmllist {
  public:
    Class_xmllist();
    virtual ~Class_xmllist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_data_xml::Type_xml> vx_listxml() const override;
    virtual vx_data_xml::Type_xml vx_get_xml(vx_core::Type_int index) const override;
  };

  // (type xmlpropmap)
  class Abstract_xmlpropmap : public virtual vx_core::Abstract_map {
  public:
    Abstract_xmlpropmap() {};
    virtual ~Abstract_xmlpropmap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_set(name, value)
    virtual vx_core::Type_boolean vx_set(vx_core::Type_string name, vx_core::Type_any value) = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_core::Type_string> vx_p_map;
    // vx_mapstring()
    virtual std::map<std::string, vx_core::Type_string> vx_mapstring() const = 0;
    // vx_get_string(key)
    virtual vx_core::Type_string vx_get_string(vx_core::Type_string key) const = 0;
  };
  class Class_xmlpropmap : public virtual Abstract_xmlpropmap {
  public:
    Class_xmlpropmap();
    virtual ~Class_xmlpropmap() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_boolean vx_set(vx_core::Type_string name, vx_core::Type_any value) override;
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const override;
    virtual std::map<std::string, vx_core::Type_string> vx_mapstring() const override;
    virtual vx_core::Type_string vx_get_string(vx_core::Type_string key) const override;
  };

  // (const delimxml)
  class Class_delimxml : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_data_xml::Const_delimxml output);
  };

  // (const delimxmlcdata)
  class Class_delimxmlcdata : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_data_xml::Const_delimxmlcdata output);
  };

  // (const delimxmlcomment)
  class Class_delimxmlcomment : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_data_xml::Const_delimxmlcomment output);
  };

  // (const delimxmlequal)
  class Class_delimxmlequal : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_data_xml::Const_delimxmlequal output);
  };

  // (func string-decodexml<-string)
  class Abstract_string_decodexml_from_string : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_decodexml_from_string() {};
    virtual ~Abstract_string_decodexml_from_string() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_decodexml_from_string : public virtual Abstract_string_decodexml_from_string {
  public:
    Class_string_decodexml_from_string();
    virtual ~Class_string_decodexml_from_string() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func string-first<-xml)
  class Abstract_string_first_from_xml : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_first_from_xml() {};
    virtual ~Abstract_string_first_from_xml() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_first_from_xml : public virtual Abstract_string_first_from_xml {
  public:
    Class_string_first_from_xml();
    virtual ~Class_string_first_from_xml() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func textblock-xml<-string)
  class Abstract_textblock_xml_from_string : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_textblock_xml_from_string() {};
    virtual ~Abstract_textblock_xml_from_string() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_textblock_xml_from_string : public virtual Abstract_textblock_xml_from_string {
  public:
    Class_textblock_xml_from_string();
    virtual ~Class_textblock_xml_from_string() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func xml-angle<-xml-textblock)
  class Abstract_xml_angle_from_xml_textblock : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_xml_angle_from_xml_textblock() {};
    virtual ~Abstract_xml_angle_from_xml_textblock() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_xml_angle_from_xml_textblock : public virtual Abstract_xml_angle_from_xml_textblock {
  public:
    Class_xml_angle_from_xml_textblock();
    virtual ~Class_xml_angle_from_xml_textblock() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func xml-close<-xml-textblock)
  class Abstract_xml_close_from_xml_textblock : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_xml_close_from_xml_textblock() {};
    virtual ~Abstract_xml_close_from_xml_textblock() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_xml_close_from_xml_textblock : public virtual Abstract_xml_close_from_xml_textblock {
  public:
    Class_xml_close_from_xml_textblock();
    virtual ~Class_xml_close_from_xml_textblock() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func xml-parse<-xml-textblock)
  class Abstract_xml_parse_from_xml_textblock : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_xml_parse_from_xml_textblock() {};
    virtual ~Abstract_xml_parse_from_xml_textblock() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_xml_parse_from_xml_textblock : public virtual Abstract_xml_parse_from_xml_textblock {
  public:
    Class_xml_parse_from_xml_textblock();
    virtual ~Class_xml_parse_from_xml_textblock() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func xml-parse<-xml-textblocklist)
  class Abstract_xml_parse_from_xml_textblocklist : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_xml_parse_from_xml_textblocklist() {};
    virtual ~Abstract_xml_parse_from_xml_textblocklist() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_xml_parse_from_xml_textblocklist : public virtual Abstract_xml_parse_from_xml_textblocklist {
  public:
    Class_xml_parse_from_xml_textblocklist();
    virtual ~Class_xml_parse_from_xml_textblocklist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func xml-properties<-xml-textblocklist)
  class Abstract_xml_properties_from_xml_textblocklist : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_xml_properties_from_xml_textblocklist() {};
    virtual ~Abstract_xml_properties_from_xml_textblocklist() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_xml_properties_from_xml_textblocklist : public virtual Abstract_xml_properties_from_xml_textblocklist {
  public:
    Class_xml_properties_from_xml_textblocklist();
    virtual ~Class_xml_properties_from_xml_textblocklist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func xml-property<-xml-textblock)
  class Abstract_xml_property_from_xml_textblock : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_xml_property_from_xml_textblock() {};
    virtual ~Abstract_xml_property_from_xml_textblock() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_xml_property_from_xml_textblock : public virtual Abstract_xml_property_from_xml_textblock {
  public:
    Class_xml_property_from_xml_textblock();
    virtual ~Class_xml_property_from_xml_textblock() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func xml-read<-file)
  class Abstract_xml_read_from_file : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_xml_read_from_file() {};
    virtual ~Abstract_xml_read_from_file() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_xml_read_from_file : public virtual Abstract_xml_read_from_file {
  public:
    Class_xml_read_from_file();
    virtual ~Class_xml_read_from_file() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func xml-text<-xml-textblock)
  class Abstract_xml_text_from_xml_textblock : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_xml_text_from_xml_textblock() {};
    virtual ~Abstract_xml_text_from_xml_textblock() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_xml_text_from_xml_textblock : public virtual Abstract_xml_text_from_xml_textblock {
  public:
    Class_xml_text_from_xml_textblock();
    virtual ~Class_xml_text_from_xml_textblock() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func xml<-file)
  class Abstract_xml_from_file : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_xml_from_file() {};
    virtual ~Abstract_xml_from_file() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_xml_from_file : public virtual Abstract_xml_from_file {
  public:
    Class_xml_from_file();
    virtual ~Class_xml_from_file() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func xml<-string)
  class Abstract_xml_from_string : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_xml_from_string() {};
    virtual ~Abstract_xml_from_string() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_xml_from_string : public virtual Abstract_xml_from_string {
  public:
    Class_xml_from_string();
    virtual ~Class_xml_from_string() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func xml<-textblock)
  class Abstract_xml_from_textblock : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_xml_from_textblock() {};
    virtual ~Abstract_xml_from_textblock() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_xml_from_textblock : public virtual Abstract_xml_from_textblock {
  public:
    Class_xml_from_textblock();
    virtual ~Class_xml_from_textblock() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  class vx_Class_package {
  public:
    vx_Class_package();
    void init();
  };
  inline vx_Class_package const vx_package;

}

#endif
