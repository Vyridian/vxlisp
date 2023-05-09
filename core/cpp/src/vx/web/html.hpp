#pragma once
#include <any>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/type.hpp"

namespace vx_web_html {

  // (type body)
  class Type_body : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_web_html::Type_body* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_body* vx_copy(Args*... args);
    virtual vx_web_html::Type_body* vx_empty();
    virtual vx_web_html::Type_body* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // nodes()
    vx_web_html::Type_divchildlist* vx_p_nodes;
    virtual vx_web_html::Type_divchildlist* nodes();
  };
  extern vx_web_html::Type_body* e_body;
  extern vx_web_html::Type_body* t_body;

  // (type details)
  class Type_details : public virtual vx_core::Type_struct, public virtual vx_web_html::Type_node, public virtual vx_web_html::Type_divchild {
  public:
    template<typename... Args> vx_web_html::Type_details* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_details* vx_copy(Args*... args);
    virtual vx_web_html::Type_details* vx_empty();
    virtual vx_web_html::Type_details* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // style()
    vx_web_html::Type_style* vx_p_style;
    virtual vx_web_html::Type_style* style();
    // summary()
    vx_web_html::Type_divchildlist* vx_p_summary;
    virtual vx_web_html::Type_divchildlist* summary();
    // nodes()
    vx_web_html::Type_divchildlist* vx_p_nodes;
    virtual vx_web_html::Type_divchildlist* nodes();
  };
  extern vx_web_html::Type_details* e_details;
  extern vx_web_html::Type_details* t_details;

  // (type div)
  class Type_div : public virtual vx_core::Type_struct, public virtual vx_web_html::Type_node, public virtual vx_web_html::Type_divchild {
  public:
    template<typename... Args> vx_web_html::Type_div* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_div* vx_copy(Args*... args);
    virtual vx_web_html::Type_div* vx_empty();
    virtual vx_web_html::Type_div* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // style()
    vx_web_html::Type_style* vx_p_style;
    virtual vx_web_html::Type_style* style();
    // nodes()
    vx_web_html::Type_divchildlist* vx_p_nodes;
    virtual vx_web_html::Type_divchildlist* nodes();
  };
  extern vx_web_html::Type_div* e_div;
  extern vx_web_html::Type_div* t_div;

  // (type divchild)
  class Type_divchild : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_web_html::Type_divchild* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_divchild* vx_copy(Args*... args);
    virtual vx_web_html::Type_divchild* vx_empty();
    virtual vx_web_html::Type_divchild* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
  };
  extern vx_web_html::Type_divchild* e_divchild;
  extern vx_web_html::Type_divchild* t_divchild;

  // (type divchildlist)
  class Type_divchildlist : public virtual vx_core::Type_list {
  public:
    template<typename... Args> vx_web_html::Type_divchildlist* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_divchildlist* vx_copy(Args*... args);
    virtual vx_web_html::Type_divchildlist* vx_empty();
    virtual vx_web_html::Type_divchildlist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_web_html::Type_divchild*> vx_p_list;

    // vx_listdivchild()
    virtual std::vector<vx_web_html::Type_divchild*> vx_listdivchild();
    // vx_divchild(index)
    virtual vx_web_html::Type_divchild* vx_divchild(vx_core::Type_int* index);
  };
  extern vx_web_html::Type_divchildlist* e_divchildlist;
  extern vx_web_html::Type_divchildlist* t_divchildlist;

  // (type divlist)
  class Type_divlist : public virtual vx_core::Type_list {
  public:
    template<typename... Args> vx_web_html::Type_divlist* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_divlist* vx_copy(Args*... args);
    virtual vx_web_html::Type_divlist* vx_empty();
    virtual vx_web_html::Type_divlist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_web_html::Type_div*> vx_p_list;

    // vx_listdiv()
    virtual std::vector<vx_web_html::Type_div*> vx_listdiv();
    // vx_div(index)
    virtual vx_web_html::Type_div* vx_div(vx_core::Type_int* index);
  };
  extern vx_web_html::Type_divlist* e_divlist;
  extern vx_web_html::Type_divlist* t_divlist;

  // (type footer)
  class Type_footer : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_web_html::Type_footer* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_footer* vx_copy(Args*... args);
    virtual vx_web_html::Type_footer* vx_empty();
    virtual vx_web_html::Type_footer* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // nodes()
    vx_web_html::Type_divchildlist* vx_p_nodes;
    virtual vx_web_html::Type_divchildlist* nodes();
  };
  extern vx_web_html::Type_footer* e_footer;
  extern vx_web_html::Type_footer* t_footer;

  // (type h1)
  class Type_h1 : public virtual vx_core::Type_struct, public virtual vx_web_html::Type_node, public virtual vx_web_html::Type_divchild {
  public:
    template<typename... Args> vx_web_html::Type_h1* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_h1* vx_copy(Args*... args);
    virtual vx_web_html::Type_h1* vx_empty();
    virtual vx_web_html::Type_h1* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // style()
    vx_web_html::Type_style* vx_p_style;
    virtual vx_web_html::Type_style* style();
    // text()
    vx_core::Type_string* vx_p_text;
    virtual vx_core::Type_string* text();
  };
  extern vx_web_html::Type_h1* e_h1;
  extern vx_web_html::Type_h1* t_h1;

  // (type h2)
  class Type_h2 : public virtual vx_core::Type_struct, public virtual vx_web_html::Type_node, public virtual vx_web_html::Type_divchild {
  public:
    template<typename... Args> vx_web_html::Type_h2* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_h2* vx_copy(Args*... args);
    virtual vx_web_html::Type_h2* vx_empty();
    virtual vx_web_html::Type_h2* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // style()
    vx_web_html::Type_style* vx_p_style;
    virtual vx_web_html::Type_style* style();
    // text()
    vx_core::Type_string* vx_p_text;
    virtual vx_core::Type_string* text();
  };
  extern vx_web_html::Type_h2* e_h2;
  extern vx_web_html::Type_h2* t_h2;

  // (type h3)
  class Type_h3 : public virtual vx_core::Type_struct, public virtual vx_web_html::Type_node, public virtual vx_web_html::Type_divchild {
  public:
    template<typename... Args> vx_web_html::Type_h3* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_h3* vx_copy(Args*... args);
    virtual vx_web_html::Type_h3* vx_empty();
    virtual vx_web_html::Type_h3* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // style()
    vx_web_html::Type_style* vx_p_style;
    virtual vx_web_html::Type_style* style();
    // text()
    vx_core::Type_string* vx_p_text;
    virtual vx_core::Type_string* text();
  };
  extern vx_web_html::Type_h3* e_h3;
  extern vx_web_html::Type_h3* t_h3;

  // (type head)
  class Type_head : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_web_html::Type_head* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_head* vx_copy(Args*... args);
    virtual vx_web_html::Type_head* vx_empty();
    virtual vx_web_html::Type_head* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // nodes()
    vx_web_html::Type_headchildlist* vx_p_nodes;
    virtual vx_web_html::Type_headchildlist* nodes();
  };
  extern vx_web_html::Type_head* e_head;
  extern vx_web_html::Type_head* t_head;

  // (type headchild)
  class Type_headchild : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_web_html::Type_headchild* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_headchild* vx_copy(Args*... args);
    virtual vx_web_html::Type_headchild* vx_empty();
    virtual vx_web_html::Type_headchild* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
  };
  extern vx_web_html::Type_headchild* e_headchild;
  extern vx_web_html::Type_headchild* t_headchild;

  // (type headchildlist)
  class Type_headchildlist : public virtual vx_core::Type_list {
  public:
    template<typename... Args> vx_web_html::Type_headchildlist* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_headchildlist* vx_copy(Args*... args);
    virtual vx_web_html::Type_headchildlist* vx_empty();
    virtual vx_web_html::Type_headchildlist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_web_html::Type_headchild*> vx_p_list;

    // vx_listheadchild()
    virtual std::vector<vx_web_html::Type_headchild*> vx_listheadchild();
    // vx_headchild(index)
    virtual vx_web_html::Type_headchild* vx_headchild(vx_core::Type_int* index);
  };
  extern vx_web_html::Type_headchildlist* e_headchildlist;
  extern vx_web_html::Type_headchildlist* t_headchildlist;

  // (type html)
  class Type_html : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_web_html::Type_html* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_html* vx_copy(Args*... args);
    virtual vx_web_html::Type_html* vx_empty();
    virtual vx_web_html::Type_html* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // lang()
    vx_core::Type_string* vx_p_lang;
    virtual vx_core::Type_string* lang();
    // head()
    vx_web_html::Type_head* vx_p_head;
    virtual vx_web_html::Type_head* head();
    // body()
    vx_web_html::Type_body* vx_p_body;
    virtual vx_web_html::Type_body* body();
    // footer()
    vx_web_html::Type_footer* vx_p_footer;
    virtual vx_web_html::Type_footer* footer();
  };
  extern vx_web_html::Type_html* e_html;
  extern vx_web_html::Type_html* t_html;

  // (type meta)
  class Type_meta : public virtual vx_core::Type_struct, public virtual vx_web_html::Type_node, public virtual vx_web_html::Type_headchild {
  public:
    template<typename... Args> vx_web_html::Type_meta* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_meta* vx_copy(Args*... args);
    virtual vx_web_html::Type_meta* vx_empty();
    virtual vx_web_html::Type_meta* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // style()
    vx_web_html::Type_style* vx_p_style;
    virtual vx_web_html::Type_style* style();
    // charset()
    vx_core::Type_string* vx_p_charset;
    virtual vx_core::Type_string* charset();
  };
  extern vx_web_html::Type_meta* e_meta;
  extern vx_web_html::Type_meta* t_meta;

  // (type node)
  class Type_node : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_web_html::Type_node* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_node* vx_copy(Args*... args);
    virtual vx_web_html::Type_node* vx_empty();
    virtual vx_web_html::Type_node* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // style()
    vx_web_html::Type_style* vx_p_style;
    virtual vx_web_html::Type_style* style();
  };
  extern vx_web_html::Type_node* e_node;
  extern vx_web_html::Type_node* t_node;

  // (type nodelist)
  class Type_nodelist : public virtual vx_core::Type_list {
  public:
    template<typename... Args> vx_web_html::Type_nodelist* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_nodelist* vx_copy(Args*... args);
    virtual vx_web_html::Type_nodelist* vx_empty();
    virtual vx_web_html::Type_nodelist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_web_html::Type_node*> vx_p_list;

    // vx_listnode()
    virtual std::vector<vx_web_html::Type_node*> vx_listnode();
    // vx_node(index)
    virtual vx_web_html::Type_node* vx_node(vx_core::Type_int* index);
  };
  extern vx_web_html::Type_nodelist* e_nodelist;
  extern vx_web_html::Type_nodelist* t_nodelist;

  // (type p)
  class Type_p : public virtual vx_core::Type_struct, public virtual vx_web_html::Type_node, public virtual vx_web_html::Type_divchild {
  public:
    template<typename... Args> vx_web_html::Type_p* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_p* vx_copy(Args*... args);
    virtual vx_web_html::Type_p* vx_empty();
    virtual vx_web_html::Type_p* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // style()
    vx_web_html::Type_style* vx_p_style;
    virtual vx_web_html::Type_style* style();
    // text()
    vx_core::Type_string* vx_p_text;
    virtual vx_core::Type_string* text();
  };
  extern vx_web_html::Type_p* e_p;
  extern vx_web_html::Type_p* t_p;

  // (type propmap)
  class Type_propmap : public virtual vx_core::Type_map {
  public:
    template<typename... Args> vx_web_html::Type_propmap* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_propmap* vx_copy(Args*... args);
    virtual vx_web_html::Type_propmap* vx_empty();
    virtual vx_web_html::Type_propmap* vx_type();
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
    virtual vx_web_html::Type_propmap* vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval);
  };
  extern vx_web_html::Type_propmap* e_propmap;
  extern vx_web_html::Type_propmap* t_propmap;

  // (type style)
  class Type_style : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_web_html::Type_style* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_style* vx_copy(Args*... args);
    virtual vx_web_html::Type_style* vx_empty();
    virtual vx_web_html::Type_style* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // name()
    vx_core::Type_string* vx_p_name;
    virtual vx_core::Type_string* name();
    // props()
    vx_web_html::Type_propmap* vx_p_props;
    virtual vx_web_html::Type_propmap* props();
  };
  extern vx_web_html::Type_style* e_style;
  extern vx_web_html::Type_style* t_style;

  // (type stylelist)
  class Type_stylelist : public virtual vx_core::Type_list {
  public:
    template<typename... Args> vx_web_html::Type_stylelist* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_stylelist* vx_copy(Args*... args);
    virtual vx_web_html::Type_stylelist* vx_empty();
    virtual vx_web_html::Type_stylelist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_web_html::Type_style*> vx_p_list;

    // vx_liststyle()
    virtual std::vector<vx_web_html::Type_style*> vx_liststyle();
    // vx_style(index)
    virtual vx_web_html::Type_style* vx_style(vx_core::Type_int* index);
  };
  extern vx_web_html::Type_stylelist* e_stylelist;
  extern vx_web_html::Type_stylelist* t_stylelist;

  // (type stylemap)
  class Type_stylemap : public virtual vx_core::Type_map {
  public:
    template<typename... Args> vx_web_html::Type_stylemap* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_stylemap* vx_copy(Args*... args);
    virtual vx_web_html::Type_stylemap* vx_empty();
    virtual vx_web_html::Type_stylemap* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    std::map<std::string, vx_web_html::Type_style*> vx_p_map;
    // vx_mapstyle()
    virtual std::map<std::string, vx_web_html::Type_style*> vx_mapstyle();
    // vx_style(key)
    virtual vx_web_html::Type_style* vx_style(vx_core::Type_string* key);
    virtual vx_web_html::Type_stylemap* vx_new_from_map(std::map<std::string, vx_core::Type_any*> mapval);
  };
  extern vx_web_html::Type_stylemap* e_stylemap;
  extern vx_web_html::Type_stylemap* t_stylemap;

  // (type stylesheet)
  class Type_stylesheet : public virtual vx_core::Type_struct, public virtual vx_web_html::Type_node, public virtual vx_web_html::Type_headchild {
  public:
    template<typename... Args> vx_web_html::Type_stylesheet* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_stylesheet* vx_copy(Args*... args);
    virtual vx_web_html::Type_stylesheet* vx_empty();
    virtual vx_web_html::Type_stylesheet* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // style()
    vx_web_html::Type_style* vx_p_style;
    virtual vx_web_html::Type_style* style();
    // name()
    vx_core::Type_string* vx_p_name;
    virtual vx_core::Type_string* name();
    // styles()
    vx_web_html::Type_stylelist* vx_p_styles;
    virtual vx_web_html::Type_stylelist* styles();
    // stylemap()
    vx_web_html::Type_stylemap* vx_p_stylemap;
    virtual vx_web_html::Type_stylemap* stylemap();
  };
  extern vx_web_html::Type_stylesheet* e_stylesheet;
  extern vx_web_html::Type_stylesheet* t_stylesheet;

  // (type table)
  class Type_table : public virtual vx_core::Type_struct, public virtual vx_web_html::Type_node, public virtual vx_web_html::Type_divchild {
  public:
    template<typename... Args> vx_web_html::Type_table* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_table* vx_copy(Args*... args);
    virtual vx_web_html::Type_table* vx_empty();
    virtual vx_web_html::Type_table* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // style()
    vx_web_html::Type_style* vx_p_style;
    virtual vx_web_html::Type_style* style();
    // tbody()
    vx_web_html::Type_tbody* vx_p_tbody;
    virtual vx_web_html::Type_tbody* tbody();
    // thead()
    vx_web_html::Type_thead* vx_p_thead;
    virtual vx_web_html::Type_thead* thead();
  };
  extern vx_web_html::Type_table* e_table;
  extern vx_web_html::Type_table* t_table;

  // (type tbody)
  class Type_tbody : public virtual vx_core::Type_struct, public virtual vx_web_html::Type_node {
  public:
    template<typename... Args> vx_web_html::Type_tbody* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_tbody* vx_copy(Args*... args);
    virtual vx_web_html::Type_tbody* vx_empty();
    virtual vx_web_html::Type_tbody* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // style()
    vx_web_html::Type_style* vx_p_style;
    virtual vx_web_html::Type_style* style();
    // nodes()
    vx_web_html::Type_trlist* vx_p_nodes;
    virtual vx_web_html::Type_trlist* nodes();
  };
  extern vx_web_html::Type_tbody* e_tbody;
  extern vx_web_html::Type_tbody* t_tbody;

  // (type td)
  class Type_td : public virtual vx_core::Type_struct, public virtual vx_web_html::Type_node {
  public:
    template<typename... Args> vx_web_html::Type_td* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_td* vx_copy(Args*... args);
    virtual vx_web_html::Type_td* vx_empty();
    virtual vx_web_html::Type_td* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // style()
    vx_web_html::Type_style* vx_p_style;
    virtual vx_web_html::Type_style* style();
    // nodes()
    vx_web_html::Type_divchildlist* vx_p_nodes;
    virtual vx_web_html::Type_divchildlist* nodes();
  };
  extern vx_web_html::Type_td* e_td;
  extern vx_web_html::Type_td* t_td;

  // (type tdlist)
  class Type_tdlist : public virtual vx_core::Type_list {
  public:
    template<typename... Args> vx_web_html::Type_tdlist* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_tdlist* vx_copy(Args*... args);
    virtual vx_web_html::Type_tdlist* vx_empty();
    virtual vx_web_html::Type_tdlist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_web_html::Type_td*> vx_p_list;

    // vx_listtd()
    virtual std::vector<vx_web_html::Type_td*> vx_listtd();
    // vx_td(index)
    virtual vx_web_html::Type_td* vx_td(vx_core::Type_int* index);
  };
  extern vx_web_html::Type_tdlist* e_tdlist;
  extern vx_web_html::Type_tdlist* t_tdlist;

  // (type thead)
  class Type_thead : public virtual vx_core::Type_struct, public virtual vx_web_html::Type_node {
  public:
    template<typename... Args> vx_web_html::Type_thead* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_thead* vx_copy(Args*... args);
    virtual vx_web_html::Type_thead* vx_empty();
    virtual vx_web_html::Type_thead* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // style()
    vx_web_html::Type_style* vx_p_style;
    virtual vx_web_html::Type_style* style();
    // nodes()
    vx_web_html::Type_trlist* vx_p_nodes;
    virtual vx_web_html::Type_trlist* nodes();
  };
  extern vx_web_html::Type_thead* e_thead;
  extern vx_web_html::Type_thead* t_thead;

  // (type title)
  class Type_title : public virtual vx_core::Type_struct, public virtual vx_web_html::Type_node, public virtual vx_web_html::Type_headchild {
  public:
    template<typename... Args> vx_web_html::Type_title* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_title* vx_copy(Args*... args);
    virtual vx_web_html::Type_title* vx_empty();
    virtual vx_web_html::Type_title* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // style()
    vx_web_html::Type_style* vx_p_style;
    virtual vx_web_html::Type_style* style();
    // text()
    vx_core::Type_string* vx_p_text;
    virtual vx_core::Type_string* text();
  };
  extern vx_web_html::Type_title* e_title;
  extern vx_web_html::Type_title* t_title;

  // (type tr)
  class Type_tr : public virtual vx_core::Type_struct, public virtual vx_web_html::Type_node {
  public:
    template<typename... Args> vx_web_html::Type_tr* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_tr* vx_copy(Args*... args);
    virtual vx_web_html::Type_tr* vx_empty();
    virtual vx_web_html::Type_tr* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // style()
    vx_web_html::Type_style* vx_p_style;
    virtual vx_web_html::Type_style* style();
    // nodes()
    vx_web_html::Type_tdlist* vx_p_nodes;
    virtual vx_web_html::Type_tdlist* nodes();
  };
  extern vx_web_html::Type_tr* e_tr;
  extern vx_web_html::Type_tr* t_tr;

  // (type trlist)
  class Type_trlist : public virtual vx_core::Type_list {
  public:
    template<typename... Args> vx_web_html::Type_trlist* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Type_trlist* vx_copy(Args*... args);
    virtual vx_web_html::Type_trlist* vx_empty();
    virtual vx_web_html::Type_trlist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_web_html::Type_tr*> vx_p_list;

    // vx_listtr()
    virtual std::vector<vx_web_html::Type_tr*> vx_listtr();
    // vx_tr(index)
    virtual vx_web_html::Type_tr* vx_tr(vx_core::Type_int* index);
  };
  extern vx_web_html::Type_trlist* e_trlist;
  extern vx_web_html::Type_trlist* t_trlist;

  // (func boolean-write<-id-htmltext)
  class Func_boolean_write_from_id_htmltext : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_boolean_write_from_id_htmltext* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_boolean_write_from_id_htmltext* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_boolean_write_from_id_htmltext* vx_empty();
    virtual vx_web_html::Func_boolean_write_from_id_htmltext* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_boolean* vx_boolean_write_from_id_htmltext(vx_core::Type_string* id, vx_core::Type_string* htmltext);
  };
  extern Func_boolean_write_from_id_htmltext* e_boolean_write_from_id_htmltext;
  extern Func_boolean_write_from_id_htmltext* t_boolean_write_from_id_htmltext;

  // (func boolean-write<-stylesheet)
  class Func_boolean_write_from_stylesheet : public vx_core::Func_any_from_any_async, public virtual vx_core::Type_replfunc_async {
  public:
    template<typename... Args> vx_web_html::Func_boolean_write_from_stylesheet* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_boolean_write_from_stylesheet* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_boolean_write_from_stylesheet* vx_empty();
    virtual vx_web_html::Func_boolean_write_from_stylesheet* vx_type();
    virtual vx_core::Func_any_from_any_async* fn_new(vx_core::Func_any_from_any_async::IFn fn);
    template <class T, class U> vx_core::Async<T*>* f_any_from_any_async(T* generic_any_1, U* value);
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Async<vx_core::Type_boolean*>* vx_boolean_write_from_stylesheet(vx_web_html::Type_stylesheet* stylesheet);
  };
  extern Func_boolean_write_from_stylesheet* e_boolean_write_from_stylesheet;
  extern Func_boolean_write_from_stylesheet* t_boolean_write_from_stylesheet;

  // (func htmlstring<-string)
  class Func_htmlstring_from_string : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_htmlstring_from_string* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_htmlstring_from_string* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_htmlstring_from_string* vx_empty();
    virtual vx_web_html::Func_htmlstring_from_string* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_htmlstring_from_string(vx_core::Type_string* text);
  };
  extern Func_htmlstring_from_string* e_htmlstring_from_string;
  extern Func_htmlstring_from_string* t_htmlstring_from_string;

  // (func string-indent)
  class Func_string_indent : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_indent* vx_empty();
    virtual vx_web_html::Func_string_indent* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_indent(vx_core::Type_int* indent);
  };
  extern Func_string_indent* e_string_indent;
  extern Func_string_indent* t_string_indent;

  // (func string<-body-indent)
  class Func_string_from_body_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_body_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_body_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_body_indent* vx_empty();
    virtual vx_web_html::Func_string_from_body_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_body_indent(vx_web_html::Type_body* body, vx_core::Type_int* indent);
  };
  extern Func_string_from_body_indent* e_string_from_body_indent;
  extern Func_string_from_body_indent* t_string_from_body_indent;

  // (func string<-details-indent)
  class Func_string_from_details_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_details_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_details_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_details_indent* vx_empty();
    virtual vx_web_html::Func_string_from_details_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_details_indent(vx_web_html::Type_details* details, vx_core::Type_int* indent);
  };
  extern Func_string_from_details_indent* e_string_from_details_indent;
  extern Func_string_from_details_indent* t_string_from_details_indent;

  // (func string<-div-indent)
  class Func_string_from_div_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_div_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_div_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_div_indent* vx_empty();
    virtual vx_web_html::Func_string_from_div_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_div_indent(vx_web_html::Type_div* div, vx_core::Type_int* indent);
  };
  extern Func_string_from_div_indent* e_string_from_div_indent;
  extern Func_string_from_div_indent* t_string_from_div_indent;

  // (func string<-footer-indent)
  class Func_string_from_footer_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_footer_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_footer_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_footer_indent* vx_empty();
    virtual vx_web_html::Func_string_from_footer_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_footer_indent(vx_web_html::Type_footer* footer, vx_core::Type_int* indent);
  };
  extern Func_string_from_footer_indent* e_string_from_footer_indent;
  extern Func_string_from_footer_indent* t_string_from_footer_indent;

  // (func string<-h1-indent)
  class Func_string_from_h1_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_h1_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_h1_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_h1_indent* vx_empty();
    virtual vx_web_html::Func_string_from_h1_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_h1_indent(vx_web_html::Type_h1* h1, vx_core::Type_int* indent);
  };
  extern Func_string_from_h1_indent* e_string_from_h1_indent;
  extern Func_string_from_h1_indent* t_string_from_h1_indent;

  // (func string<-h2-indent)
  class Func_string_from_h2_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_h2_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_h2_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_h2_indent* vx_empty();
    virtual vx_web_html::Func_string_from_h2_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_h2_indent(vx_web_html::Type_h2* h2, vx_core::Type_int* indent);
  };
  extern Func_string_from_h2_indent* e_string_from_h2_indent;
  extern Func_string_from_h2_indent* t_string_from_h2_indent;

  // (func string<-h3-indent)
  class Func_string_from_h3_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_h3_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_h3_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_h3_indent* vx_empty();
    virtual vx_web_html::Func_string_from_h3_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_h3_indent(vx_web_html::Type_h3* h3, vx_core::Type_int* indent);
  };
  extern Func_string_from_h3_indent* e_string_from_h3_indent;
  extern Func_string_from_h3_indent* t_string_from_h3_indent;

  // (func string<-head-indent)
  class Func_string_from_head_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_head_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_head_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_head_indent* vx_empty();
    virtual vx_web_html::Func_string_from_head_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_head_indent(vx_web_html::Type_head* head, vx_core::Type_int* indent);
  };
  extern Func_string_from_head_indent* e_string_from_head_indent;
  extern Func_string_from_head_indent* t_string_from_head_indent;

  // (func string<-html)
  class Func_string_from_html : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_html* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_html* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_html* vx_empty();
    virtual vx_web_html::Func_string_from_html* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_html(vx_web_html::Type_html* html);
  };
  extern Func_string_from_html* e_string_from_html;
  extern Func_string_from_html* t_string_from_html;

  // (func string<-indent)
  class Func_string_from_indent : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_indent* vx_empty();
    virtual vx_web_html::Func_string_from_indent* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_indent(vx_core::Type_int* indent);
  };
  extern Func_string_from_indent* e_string_from_indent;
  extern Func_string_from_indent* t_string_from_indent;

  // (func string<-meta-indent)
  class Func_string_from_meta_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_meta_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_meta_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_meta_indent* vx_empty();
    virtual vx_web_html::Func_string_from_meta_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_meta_indent(vx_web_html::Type_meta* meta, vx_core::Type_int* indent);
  };
  extern Func_string_from_meta_indent* e_string_from_meta_indent;
  extern Func_string_from_meta_indent* t_string_from_meta_indent;

  // (func string<-node-indent)
  class Func_string_from_node_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_node_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_node_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_node_indent* vx_empty();
    virtual vx_web_html::Func_string_from_node_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_node_indent(vx_core::Type_any* node, vx_core::Type_int* indent);
  };
  extern Func_string_from_node_indent* e_string_from_node_indent;
  extern Func_string_from_node_indent* t_string_from_node_indent;

  // (func string<-nodelist-indent)
  class Func_string_from_nodelist_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_nodelist_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_nodelist_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_nodelist_indent* vx_empty();
    virtual vx_web_html::Func_string_from_nodelist_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_nodelist_indent(vx_core::Type_list* nodelist, vx_core::Type_int* indent);
  };
  extern Func_string_from_nodelist_indent* e_string_from_nodelist_indent;
  extern Func_string_from_nodelist_indent* t_string_from_nodelist_indent;

  // (func string<-nodelist-tag-prop-indent)
  class Func_string_from_nodelist_tag_prop_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_nodelist_tag_prop_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_nodelist_tag_prop_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_nodelist_tag_prop_indent* vx_empty();
    virtual vx_web_html::Func_string_from_nodelist_tag_prop_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_nodelist_tag_prop_indent(vx_core::Type_list* nodes, vx_core::Type_string* tag, vx_core::Type_string* prop, vx_core::Type_int* indent);
  };
  extern Func_string_from_nodelist_tag_prop_indent* e_string_from_nodelist_tag_prop_indent;
  extern Func_string_from_nodelist_tag_prop_indent* t_string_from_nodelist_tag_prop_indent;

  // (func string<-p-indent)
  class Func_string_from_p_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_p_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_p_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_p_indent* vx_empty();
    virtual vx_web_html::Func_string_from_p_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_p_indent(vx_web_html::Type_p* p, vx_core::Type_int* indent);
  };
  extern Func_string_from_p_indent* e_string_from_p_indent;
  extern Func_string_from_p_indent* t_string_from_p_indent;

  // (func string<-propname-val)
  class Func_string_from_propname_val : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_propname_val* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_propname_val* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_propname_val* vx_empty();
    virtual vx_web_html::Func_string_from_propname_val* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_propname_val(vx_core::Type_string* key, vx_core::Type_string* val);
  };
  extern Func_string_from_propname_val* e_string_from_propname_val;
  extern Func_string_from_propname_val* t_string_from_propname_val;

  // (func string<-propstyle)
  class Func_string_from_propstyle : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_propstyle* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_propstyle* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_propstyle* vx_empty();
    virtual vx_web_html::Func_string_from_propstyle* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_propstyle(vx_web_html::Type_style* style);
  };
  extern Func_string_from_propstyle* e_string_from_propstyle;
  extern Func_string_from_propstyle* t_string_from_propstyle;

  // (func string<-style-indent)
  class Func_string_from_style_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_style_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_style_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_style_indent* vx_empty();
    virtual vx_web_html::Func_string_from_style_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_style_indent(vx_web_html::Type_style* style, vx_core::Type_int* indent);
  };
  extern Func_string_from_style_indent* e_string_from_style_indent;
  extern Func_string_from_style_indent* t_string_from_style_indent;

  // (func string<-stylelist-indent)
  class Func_string_from_stylelist_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_stylelist_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_stylelist_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_stylelist_indent* vx_empty();
    virtual vx_web_html::Func_string_from_stylelist_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_stylelist_indent(vx_web_html::Type_stylelist* stylelist, vx_core::Type_int* indent);
  };
  extern Func_string_from_stylelist_indent* e_string_from_stylelist_indent;
  extern Func_string_from_stylelist_indent* t_string_from_stylelist_indent;

  // (func string<-stylepropmap-indent)
  class Func_string_from_stylepropmap_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_stylepropmap_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_stylepropmap_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_stylepropmap_indent* vx_empty();
    virtual vx_web_html::Func_string_from_stylepropmap_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_stylepropmap_indent(vx_web_html::Type_propmap* propmap, vx_core::Type_int* indent);
  };
  extern Func_string_from_stylepropmap_indent* e_string_from_stylepropmap_indent;
  extern Func_string_from_stylepropmap_indent* t_string_from_stylepropmap_indent;

  // (func string<-stylesheet-indent)
  class Func_string_from_stylesheet_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_stylesheet_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_stylesheet_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_stylesheet_indent* vx_empty();
    virtual vx_web_html::Func_string_from_stylesheet_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_stylesheet_indent(vx_web_html::Type_stylesheet* stylesheet, vx_core::Type_int* indent);
  };
  extern Func_string_from_stylesheet_indent* e_string_from_stylesheet_indent;
  extern Func_string_from_stylesheet_indent* t_string_from_stylesheet_indent;

  // (func string<-table-indent)
  class Func_string_from_table_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_table_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_table_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_table_indent* vx_empty();
    virtual vx_web_html::Func_string_from_table_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_table_indent(vx_web_html::Type_table* table, vx_core::Type_int* indent);
  };
  extern Func_string_from_table_indent* e_string_from_table_indent;
  extern Func_string_from_table_indent* t_string_from_table_indent;

  // (func string<-tbody-indent)
  class Func_string_from_tbody_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_tbody_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_tbody_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_tbody_indent* vx_empty();
    virtual vx_web_html::Func_string_from_tbody_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_tbody_indent(vx_web_html::Type_tbody* tbody, vx_core::Type_int* indent);
  };
  extern Func_string_from_tbody_indent* e_string_from_tbody_indent;
  extern Func_string_from_tbody_indent* t_string_from_tbody_indent;

  // (func string<-td-indent)
  class Func_string_from_td_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_td_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_td_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_td_indent* vx_empty();
    virtual vx_web_html::Func_string_from_td_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_td_indent(vx_web_html::Type_td* td, vx_core::Type_int* indent);
  };
  extern Func_string_from_td_indent* e_string_from_td_indent;
  extern Func_string_from_td_indent* t_string_from_td_indent;

  // (func string<-thead-indent)
  class Func_string_from_thead_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_thead_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_thead_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_thead_indent* vx_empty();
    virtual vx_web_html::Func_string_from_thead_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_thead_indent(vx_web_html::Type_thead* thead, vx_core::Type_int* indent);
  };
  extern Func_string_from_thead_indent* e_string_from_thead_indent;
  extern Func_string_from_thead_indent* t_string_from_thead_indent;

  // (func string<-title-indent)
  class Func_string_from_title_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_title_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_title_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_title_indent* vx_empty();
    virtual vx_web_html::Func_string_from_title_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_title_indent(vx_web_html::Type_title* title, vx_core::Type_int* indent);
  };
  extern Func_string_from_title_indent* e_string_from_title_indent;
  extern Func_string_from_title_indent* t_string_from_title_indent;

  // (func string<-tr-indent)
  class Func_string_from_tr_indent : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_tr_indent* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_tr_indent* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_tr_indent* vx_empty();
    virtual vx_web_html::Func_string_from_tr_indent* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_tr_indent(vx_web_html::Type_tr* tr, vx_core::Type_int* indent);
  };
  extern Func_string_from_tr_indent* e_string_from_tr_indent;
  extern Func_string_from_tr_indent* t_string_from_tr_indent;

  // (func string<-uri)
  class Func_string_from_uri : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_string_from_uri* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_string_from_uri* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_string_from_uri* vx_empty();
    virtual vx_web_html::Func_string_from_uri* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_string_from_uri(vx_core::Type_string* uri);
  };
  extern Func_string_from_uri* e_string_from_uri;
  extern Func_string_from_uri* t_string_from_uri;

  // (func style<-stylesheet-name)
  class Func_style_from_stylesheet_name : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_style_from_stylesheet_name* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_style_from_stylesheet_name* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_style_from_stylesheet_name* vx_empty();
    virtual vx_web_html::Func_style_from_stylesheet_name* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_web_html::Type_style* vx_style_from_stylesheet_name(vx_web_html::Type_stylesheet* stylesheet, vx_core::Type_string* name);
  };
  extern Func_style_from_stylesheet_name* e_style_from_stylesheet_name;
  extern Func_style_from_stylesheet_name* t_style_from_stylesheet_name;

  // (func stylemap<-stylelist)
  class Func_stylemap_from_stylelist : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_stylemap_from_stylelist* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_stylemap_from_stylelist* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_stylemap_from_stylelist* vx_empty();
    virtual vx_web_html::Func_stylemap_from_stylelist* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_web_html::Type_stylemap* vx_stylemap_from_stylelist(vx_web_html::Type_stylelist* stylelist);
  };
  extern Func_stylemap_from_stylelist* e_stylemap_from_stylelist;
  extern Func_stylemap_from_stylelist* t_stylemap_from_stylelist;

  // (func stylemap<-stylesheet)
  class Func_stylemap_from_stylesheet : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_stylemap_from_stylesheet* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_stylemap_from_stylesheet* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_stylemap_from_stylesheet* vx_empty();
    virtual vx_web_html::Func_stylemap_from_stylesheet* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_web_html::Type_stylemap* vx_stylemap_from_stylesheet(vx_web_html::Type_stylesheet* stylesheet);
  };
  extern Func_stylemap_from_stylesheet* e_stylemap_from_stylesheet;
  extern Func_stylemap_from_stylesheet* t_stylemap_from_stylesheet;

  // (func styles<-stylesheet)
  class Func_styles_from_stylesheet : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_styles_from_stylesheet* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_styles_from_stylesheet* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_styles_from_stylesheet* vx_empty();
    virtual vx_web_html::Func_styles_from_stylesheet* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_web_html::Type_stylelist* vx_styles_from_stylesheet(vx_web_html::Type_stylesheet* stylesheet);
  };
  extern Func_styles_from_stylesheet* e_styles_from_stylesheet;
  extern Func_styles_from_stylesheet* t_styles_from_stylesheet;

  // (func stylesheet-loadmap)
  class Func_stylesheet_loadmap : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_stylesheet_loadmap* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_stylesheet_loadmap* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_stylesheet_loadmap* vx_empty();
    virtual vx_web_html::Func_stylesheet_loadmap* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_web_html::Type_stylesheet* vx_stylesheet_loadmap(vx_web_html::Type_stylesheet* stylesheet);
  };
  extern Func_stylesheet_loadmap* e_stylesheet_loadmap;
  extern Func_stylesheet_loadmap* t_stylesheet_loadmap;

  // (func uri<-string)
  class Func_uri_from_string : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_web_html::Func_uri_from_string* vx_new(Args*... args);
    template<typename... Args> vx_web_html::Func_uri_from_string* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_web_html::Func_uri_from_string* vx_empty();
    virtual vx_web_html::Func_uri_from_string* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_uri_from_string(vx_core::Type_string* text);
  };
  extern Func_uri_from_string* e_uri_from_string;
  extern Func_uri_from_string* t_uri_from_string;

  // (func boolean-write<-id-htmltext)
  vx_core::Type_boolean* f_boolean_write_from_id_htmltext(vx_core::Type_string* id, vx_core::Type_string* htmltext);

  // (func boolean-write<-stylesheet)
  vx_core::Async<vx_core::Type_boolean*>* f_boolean_write_from_stylesheet(vx_web_html::Type_stylesheet* stylesheet);

  // (func htmlstring<-string)
  vx_core::Type_string* f_htmlstring_from_string(vx_core::Type_string* text);

  // (func string-indent)
  vx_core::Type_string* f_string_indent(vx_core::Type_int* indent);

  // (func string<-body-indent)
  vx_core::Type_string* f_string_from_body_indent(vx_web_html::Type_body* body, vx_core::Type_int* indent);

  // (func string<-details-indent)
  vx_core::Type_string* f_string_from_details_indent(vx_web_html::Type_details* details, vx_core::Type_int* indent);

  // (func string<-div-indent)
  vx_core::Type_string* f_string_from_div_indent(vx_web_html::Type_div* div, vx_core::Type_int* indent);

  // (func string<-footer-indent)
  vx_core::Type_string* f_string_from_footer_indent(vx_web_html::Type_footer* footer, vx_core::Type_int* indent);

  // (func string<-h1-indent)
  vx_core::Type_string* f_string_from_h1_indent(vx_web_html::Type_h1* h1, vx_core::Type_int* indent);

  // (func string<-h2-indent)
  vx_core::Type_string* f_string_from_h2_indent(vx_web_html::Type_h2* h2, vx_core::Type_int* indent);

  // (func string<-h3-indent)
  vx_core::Type_string* f_string_from_h3_indent(vx_web_html::Type_h3* h3, vx_core::Type_int* indent);

  // (func string<-head-indent)
  vx_core::Type_string* f_string_from_head_indent(vx_web_html::Type_head* head, vx_core::Type_int* indent);

  // (func string<-html)
  vx_core::Type_string* f_string_from_html(vx_web_html::Type_html* html);

  // (func string<-indent)
  vx_core::Type_string* f_string_from_indent(vx_core::Type_int* indent);

  // (func string<-meta-indent)
  vx_core::Type_string* f_string_from_meta_indent(vx_web_html::Type_meta* meta, vx_core::Type_int* indent);

  // (func string<-node-indent)
  vx_core::Type_string* f_string_from_node_indent(vx_core::Type_any* node, vx_core::Type_int* indent);

  // (func string<-nodelist-indent)
  vx_core::Type_string* f_string_from_nodelist_indent(vx_core::Type_list* nodelist, vx_core::Type_int* indent);

  // (func string<-nodelist-tag-prop-indent)
  vx_core::Type_string* f_string_from_nodelist_tag_prop_indent(vx_core::Type_list* nodes, vx_core::Type_string* tag, vx_core::Type_string* prop, vx_core::Type_int* indent);

  // (func string<-p-indent)
  vx_core::Type_string* f_string_from_p_indent(vx_web_html::Type_p* p, vx_core::Type_int* indent);

  // (func string<-propname-val)
  vx_core::Type_string* f_string_from_propname_val(vx_core::Type_string* key, vx_core::Type_string* val);

  // (func string<-propstyle)
  vx_core::Type_string* f_string_from_propstyle(vx_web_html::Type_style* style);

  // (func string<-style-indent)
  vx_core::Type_string* f_string_from_style_indent(vx_web_html::Type_style* style, vx_core::Type_int* indent);

  // (func string<-stylelist-indent)
  vx_core::Type_string* f_string_from_stylelist_indent(vx_web_html::Type_stylelist* stylelist, vx_core::Type_int* indent);

  // (func string<-stylepropmap-indent)
  vx_core::Type_string* f_string_from_stylepropmap_indent(vx_web_html::Type_propmap* propmap, vx_core::Type_int* indent);

  // (func string<-stylesheet-indent)
  vx_core::Type_string* f_string_from_stylesheet_indent(vx_web_html::Type_stylesheet* stylesheet, vx_core::Type_int* indent);

  // (func string<-table-indent)
  vx_core::Type_string* f_string_from_table_indent(vx_web_html::Type_table* table, vx_core::Type_int* indent);

  // (func string<-tbody-indent)
  vx_core::Type_string* f_string_from_tbody_indent(vx_web_html::Type_tbody* tbody, vx_core::Type_int* indent);

  // (func string<-td-indent)
  vx_core::Type_string* f_string_from_td_indent(vx_web_html::Type_td* td, vx_core::Type_int* indent);

  // (func string<-thead-indent)
  vx_core::Type_string* f_string_from_thead_indent(vx_web_html::Type_thead* thead, vx_core::Type_int* indent);

  // (func string<-title-indent)
  vx_core::Type_string* f_string_from_title_indent(vx_web_html::Type_title* title, vx_core::Type_int* indent);

  // (func string<-tr-indent)
  vx_core::Type_string* f_string_from_tr_indent(vx_web_html::Type_tr* tr, vx_core::Type_int* indent);

  // (func string<-uri)
  vx_core::Type_string* f_string_from_uri(vx_core::Type_string* uri);

  // (func style<-stylesheet-name)
  vx_web_html::Type_style* f_style_from_stylesheet_name(vx_web_html::Type_stylesheet* stylesheet, vx_core::Type_string* name);

  // (func stylemap<-stylelist)
  vx_web_html::Type_stylemap* f_stylemap_from_stylelist(vx_web_html::Type_stylelist* stylelist);

  // (func stylemap<-stylesheet)
  vx_web_html::Type_stylemap* f_stylemap_from_stylesheet(vx_web_html::Type_stylesheet* stylesheet);

  // (func styles<-stylesheet)
  vx_web_html::Type_stylelist* f_styles_from_stylesheet(vx_web_html::Type_stylesheet* stylesheet);

  // (func stylesheet-loadmap)
  vx_web_html::Type_stylesheet* f_stylesheet_loadmap(vx_web_html::Type_stylesheet* stylesheet);

  // (func uri<-string)
  vx_core::Type_string* f_uri_from_string(vx_core::Type_string* text);

}
