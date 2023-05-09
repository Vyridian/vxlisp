#pragma once
#include <any>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/data/textblock.hpp"

namespace vx_data_xml {

  // (type xml)
  class Type_xml : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_data_xml::Type_xml* vx_new(Args*... args);
    template<typename... Args> vx_data_xml::Type_xml* vx_copy(Args*... args);
    virtual vx_data_xml::Type_xml* vx_empty();
    virtual vx_data_xml::Type_xml* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // nodes()
    vx_data_xml::Type_xmlnodelist* vx_p_nodes;
    virtual vx_data_xml::Type_xmlnodelist* nodes();
  };
  extern vx_data_xml::Type_xml* e_xml;
  extern vx_data_xml::Type_xml* t_xml;

  // (type xmlnode)
  class Type_xmlnode : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_data_xml::Type_xmlnode* vx_new(Args*... args);
    template<typename... Args> vx_data_xml::Type_xmlnode* vx_copy(Args*... args);
    virtual vx_data_xml::Type_xmlnode* vx_empty();
    virtual vx_data_xml::Type_xmlnode* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // nodes()
    vx_data_xml::Type_xmlnode* vx_p_nodes;
    virtual vx_data_xml::Type_xmlnode* nodes();
    // props()
    vx_data_xml::Type_xmlpropmap* vx_p_props;
    virtual vx_data_xml::Type_xmlpropmap* props();
    // tag()
    vx_core::Type_string* vx_p_tag;
    virtual vx_core::Type_string* tag();
    // text()
    vx_core::Type_string* vx_p_text;
    virtual vx_core::Type_string* text();
  };
  extern vx_data_xml::Type_xmlnode* e_xmlnode;
  extern vx_data_xml::Type_xmlnode* t_xmlnode;

  // (type xmlnodelist)
  class Type_xmlnodelist : public virtual vx_core::Type_list {
  public:
    template<typename... Args> vx_data_xml::Type_xmlnodelist* vx_new(Args*... args);
    template<typename... Args> vx_data_xml::Type_xmlnodelist* vx_copy(Args*... args);
    virtual vx_data_xml::Type_xmlnodelist* vx_empty();
    virtual vx_data_xml::Type_xmlnodelist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_data_xml::Type_xmlnode*> vx_p_list;

    // vx_listxmlnode()
    virtual std::vector<vx_data_xml::Type_xmlnode*> vx_listxmlnode();
    // vx_xmlnode(index)
    virtual vx_data_xml::Type_xmlnode* vx_xmlnode(vx_core::Type_int* index);
  };
  extern vx_data_xml::Type_xmlnodelist* e_xmlnodelist;
  extern vx_data_xml::Type_xmlnodelist* t_xmlnodelist;

  // (type xmlpropmap)
  class Type_xmlpropmap : public virtual vx_core::Type_map {
  public:
    template<typename... Args> vx_data_xml::Type_xmlpropmap* vx_new(Args*... args);
    template<typename... Args> vx_data_xml::Type_xmlpropmap* vx_copy(Args*... args);
    virtual vx_data_xml::Type_xmlpropmap* vx_empty();
    virtual vx_data_xml::Type_xmlpropmap* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    std::map<std::string, vx_core::Type_string*> vx_p_map;
    // vx_mapstring()
    virtual std::map<std::string, vx_core::Type_string*> vx_mapstring();
    // vx_string(key)
    virtual vx_core::Type_string* vx_string(vx_core::Type_string* key);
    virtual vx_data_xml::Type_xmlpropmap* vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval);
  };
  extern vx_data_xml::Type_xmlpropmap* e_xmlpropmap;
  extern vx_data_xml::Type_xmlpropmap* t_xmlpropmap;

  // (func xml<-textblock)
  class Func_xml_from_textblock : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_data_xml::Func_xml_from_textblock* vx_new(Args*... args);
    template<typename... Args> vx_data_xml::Func_xml_from_textblock* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_data_xml::Func_xml_from_textblock* vx_empty();
    virtual vx_data_xml::Func_xml_from_textblock* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_data_xml::Type_xml* vx_xml_from_textblock(vx_data_textblock::Type_textblock* textblock);
  };
  extern Func_xml_from_textblock* e_xml_from_textblock;
  extern Func_xml_from_textblock* t_xml_from_textblock;

  // (func xml<-textblock)
  vx_data_xml::Type_xml* f_xml_from_textblock(vx_data_textblock::Type_textblock* textblock);

}
