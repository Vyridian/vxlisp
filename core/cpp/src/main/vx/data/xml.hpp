#pragma once
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/data/textblock.hpp"

namespace vx_data_xml {

  // forward declarations
  class Class_xml;
  typedef std::shared_ptr<Class_xml> Type_xml;
  extern Type_xml e_xml;
  extern Type_xml t_xml;
  class Class_xmlnode;
  typedef std::shared_ptr<Class_xmlnode> Type_xmlnode;
  extern Type_xmlnode e_xmlnode;
  extern Type_xmlnode t_xmlnode;
  class Class_xmlnodelist;
  typedef std::shared_ptr<Class_xmlnodelist> Type_xmlnodelist;
  extern Type_xmlnodelist e_xmlnodelist;
  extern Type_xmlnodelist t_xmlnodelist;
  class Class_xmlpropmap;
  typedef std::shared_ptr<Class_xmlpropmap> Type_xmlpropmap;
  extern Type_xmlpropmap e_xmlpropmap;
  extern Type_xmlpropmap t_xmlpropmap;
  class Class_xml_from_textblock;
  typedef std::shared_ptr<Class_xml_from_textblock> Func_xml_from_textblock;
  extern Func_xml_from_textblock e_xml_from_textblock;
  extern Func_xml_from_textblock t_xml_from_textblock;


  // (type xml)
  class Class_xml : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // nodes()
    vx_data_xml::Type_xmlnodelist vx_p_nodes;
    virtual vx_data_xml::Type_xmlnodelist nodes();
  };

  // (type xmlnode)
  class Class_xmlnode : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // nodes()
    vx_data_xml::Type_xmlnode vx_p_nodes;
    virtual vx_data_xml::Type_xmlnode nodes();
    // props()
    vx_data_xml::Type_xmlpropmap vx_p_props;
    virtual vx_data_xml::Type_xmlpropmap props();
    // tag()
    vx_core::Type_string vx_p_tag;
    virtual vx_core::Type_string tag();
    // text()
    vx_core::Type_string vx_p_text;
    virtual vx_core::Type_string text();
  };

  // (type xmlnodelist)
  class Class_xmlnodelist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_data_xml::Type_xmlnode> vx_p_list;

    // vx_listxmlnode()
    virtual std::vector<vx_data_xml::Type_xmlnode> vx_listxmlnode();
    // vx_xmlnode(index)
    virtual vx_data_xml::Type_xmlnode vx_xmlnode(vx_core::Type_int index);
  };

  // (type xmlpropmap)
  class Class_xmlpropmap : public virtual vx_core::Class_map {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key) override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() override;
    // vx_new_from_map(T, Map<T>)
    template <class T> std::shared_ptr<T> vx_new_from_map(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_mapany mapval);
    std::map<std::string, vx_core::Type_string> vx_p_map;
    // vx_mapstring()
    virtual std::map<std::string, vx_core::Type_string> vx_mapstring();
    // vx_string(key)
    virtual vx_core::Type_string vx_string(vx_core::Type_string key);
  };

  // (func xml<-textblock)
  class Class_xml_from_textblock : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_data_xml::Type_xml vx_xml_from_textblock(vx_data_textblock::Type_textblock textblock);
  };

  // (func xml<-textblock)
  vx_data_xml::Type_xml f_xml_from_textblock(vx_data_textblock::Type_textblock textblock);

}
