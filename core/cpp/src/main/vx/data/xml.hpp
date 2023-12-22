#ifndef VX_DATA_XML_HPP
#define VX_DATA_XML_HPP
#include <map>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/data/file.hpp"
#include "../../vx/data/textblock.hpp"

namespace vx_data_xml {

  // forward declarations
  class Abstract_xml;
  typedef Abstract_xml* Type_xml;
  extern Type_xml e_xml;
  extern Type_xml t_xml;
  class Abstract_xmlnode;
  typedef Abstract_xmlnode* Type_xmlnode;
  extern Type_xmlnode e_xmlnode;
  extern Type_xmlnode t_xmlnode;
  class Abstract_xmlnodelist;
  typedef Abstract_xmlnodelist* Type_xmlnodelist;
  extern Type_xmlnodelist e_xmlnodelist;
  extern Type_xmlnodelist t_xmlnodelist;
  class Abstract_xmlpropmap;
  typedef Abstract_xmlpropmap* Type_xmlpropmap;
  extern Type_xmlpropmap e_xmlpropmap;
  extern Type_xmlpropmap t_xmlpropmap;
  class Class_delimxml;
  typedef Class_delimxml* Const_delimxml;
  extern Const_delimxml c_delimxml;
  class Class_delimxmlequal;
  typedef Class_delimxmlequal* Const_delimxmlequal;
  extern Const_delimxmlequal c_delimxmlequal;
  class Abstract_xml_read_from_file;
  typedef Abstract_xml_read_from_file* Func_xml_read_from_file;
  extern Func_xml_read_from_file e_xml_read_from_file;
  extern Func_xml_read_from_file t_xml_read_from_file;
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
  // (func xml-read<-file)
  vx_data_xml::Type_xml f_xml_read_from_file(vx_core::Type_context context, vx_data_file::Type_file file);

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
    // nodes()
    vx_data_xml::Type_xmlnodelist vx_p_nodes = NULL;
    virtual vx_data_xml::Type_xmlnodelist nodes() const = 0;
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
    virtual vx_data_xml::Type_xmlnodelist nodes() const override;
  };

  // (type xmlnode)
  class Abstract_xmlnode : public virtual vx_core::Abstract_struct {
  public:
    Abstract_xmlnode() {};
    virtual ~Abstract_xmlnode() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // nodes()
    vx_data_xml::Type_xmlnode vx_p_nodes = NULL;
    virtual vx_data_xml::Type_xmlnode nodes() const = 0;
    // props()
    vx_data_xml::Type_xmlpropmap vx_p_props = NULL;
    virtual vx_data_xml::Type_xmlpropmap props() const = 0;
    // tag()
    vx_core::Type_string vx_p_tag = NULL;
    virtual vx_core::Type_string tag() const = 0;
    // text()
    vx_core::Type_string vx_p_text = NULL;
    virtual vx_core::Type_string text() const = 0;
  };
  class Class_xmlnode : public virtual Abstract_xmlnode {
  public:
    Class_xmlnode();
    virtual ~Class_xmlnode() override;
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
    virtual vx_data_xml::Type_xmlnode nodes() const override;
    virtual vx_data_xml::Type_xmlpropmap props() const override;
    virtual vx_core::Type_string tag() const override;
    virtual vx_core::Type_string text() const override;
  };

  // (type xmlnodelist)
  class Abstract_xmlnodelist : public virtual vx_core::Abstract_list {
  public:
    Abstract_xmlnodelist() {};
    virtual ~Abstract_xmlnodelist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_data_xml::Type_xmlnode> vx_p_list;
    // vx_listxmlnode()
    virtual std::vector<vx_data_xml::Type_xmlnode> vx_listxmlnode() const = 0;
    // vx_get_xmlnode(index)
    virtual vx_data_xml::Type_xmlnode vx_get_xmlnode(vx_core::Type_int index) const = 0;
  };
  class Class_xmlnodelist : public virtual Abstract_xmlnodelist {
  public:
    Class_xmlnodelist();
    virtual ~Class_xmlnodelist() override;
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
    virtual std::vector<vx_data_xml::Type_xmlnode> vx_listxmlnode() const override;
    virtual vx_data_xml::Type_xmlnode vx_get_xmlnode(vx_core::Type_int index) const override;
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
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const override;
    virtual std::map<std::string, vx_core::Type_string> vx_mapstring() const override;
    virtual vx_core::Type_string vx_get_string(vx_core::Type_string key) const override;
  };

  // (const delimxml)
  class Class_delimxml : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_data_xml::Const_delimxml output);
  };

  // (const delimxmlequal)
  class Class_delimxmlequal : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_data_xml::Const_delimxmlequal output);
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
