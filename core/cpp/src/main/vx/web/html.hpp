#pragma once
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/type.hpp"

namespace vx_web_html {

  // forward declarations
  class Class_body;
  typedef std::shared_ptr<Class_body> Type_body;
  extern Type_body e_body;
  extern Type_body t_body;
  class Class_details;
  typedef std::shared_ptr<Class_details> Type_details;
  extern Type_details e_details;
  extern Type_details t_details;
  class Class_div;
  typedef std::shared_ptr<Class_div> Type_div;
  extern Type_div e_div;
  extern Type_div t_div;
  class Class_divchild;
  typedef std::shared_ptr<Class_divchild> Type_divchild;
  extern Type_divchild e_divchild;
  extern Type_divchild t_divchild;
  class Class_divchildlist;
  typedef std::shared_ptr<Class_divchildlist> Type_divchildlist;
  extern Type_divchildlist e_divchildlist;
  extern Type_divchildlist t_divchildlist;
  class Class_divlist;
  typedef std::shared_ptr<Class_divlist> Type_divlist;
  extern Type_divlist e_divlist;
  extern Type_divlist t_divlist;
  class Class_footer;
  typedef std::shared_ptr<Class_footer> Type_footer;
  extern Type_footer e_footer;
  extern Type_footer t_footer;
  class Class_h1;
  typedef std::shared_ptr<Class_h1> Type_h1;
  extern Type_h1 e_h1;
  extern Type_h1 t_h1;
  class Class_h2;
  typedef std::shared_ptr<Class_h2> Type_h2;
  extern Type_h2 e_h2;
  extern Type_h2 t_h2;
  class Class_h3;
  typedef std::shared_ptr<Class_h3> Type_h3;
  extern Type_h3 e_h3;
  extern Type_h3 t_h3;
  class Class_head;
  typedef std::shared_ptr<Class_head> Type_head;
  extern Type_head e_head;
  extern Type_head t_head;
  class Class_headchild;
  typedef std::shared_ptr<Class_headchild> Type_headchild;
  extern Type_headchild e_headchild;
  extern Type_headchild t_headchild;
  class Class_headchildlist;
  typedef std::shared_ptr<Class_headchildlist> Type_headchildlist;
  extern Type_headchildlist e_headchildlist;
  extern Type_headchildlist t_headchildlist;
  class Class_html;
  typedef std::shared_ptr<Class_html> Type_html;
  extern Type_html e_html;
  extern Type_html t_html;
  class Class_meta;
  typedef std::shared_ptr<Class_meta> Type_meta;
  extern Type_meta e_meta;
  extern Type_meta t_meta;
  class Class_node;
  typedef std::shared_ptr<Class_node> Type_node;
  extern Type_node e_node;
  extern Type_node t_node;
  class Class_nodelist;
  typedef std::shared_ptr<Class_nodelist> Type_nodelist;
  extern Type_nodelist e_nodelist;
  extern Type_nodelist t_nodelist;
  class Class_p;
  typedef std::shared_ptr<Class_p> Type_p;
  extern Type_p e_p;
  extern Type_p t_p;
  class Class_propmap;
  typedef std::shared_ptr<Class_propmap> Type_propmap;
  extern Type_propmap e_propmap;
  extern Type_propmap t_propmap;
  class Class_style;
  typedef std::shared_ptr<Class_style> Type_style;
  extern Type_style e_style;
  extern Type_style t_style;
  class Class_stylelist;
  typedef std::shared_ptr<Class_stylelist> Type_stylelist;
  extern Type_stylelist e_stylelist;
  extern Type_stylelist t_stylelist;
  class Class_stylemap;
  typedef std::shared_ptr<Class_stylemap> Type_stylemap;
  extern Type_stylemap e_stylemap;
  extern Type_stylemap t_stylemap;
  class Class_stylesheet;
  typedef std::shared_ptr<Class_stylesheet> Type_stylesheet;
  extern Type_stylesheet e_stylesheet;
  extern Type_stylesheet t_stylesheet;
  class Class_table;
  typedef std::shared_ptr<Class_table> Type_table;
  extern Type_table e_table;
  extern Type_table t_table;
  class Class_tbody;
  typedef std::shared_ptr<Class_tbody> Type_tbody;
  extern Type_tbody e_tbody;
  extern Type_tbody t_tbody;
  class Class_td;
  typedef std::shared_ptr<Class_td> Type_td;
  extern Type_td e_td;
  extern Type_td t_td;
  class Class_tdlist;
  typedef std::shared_ptr<Class_tdlist> Type_tdlist;
  extern Type_tdlist e_tdlist;
  extern Type_tdlist t_tdlist;
  class Class_thead;
  typedef std::shared_ptr<Class_thead> Type_thead;
  extern Type_thead e_thead;
  extern Type_thead t_thead;
  class Class_title;
  typedef std::shared_ptr<Class_title> Type_title;
  extern Type_title e_title;
  extern Type_title t_title;
  class Class_tr;
  typedef std::shared_ptr<Class_tr> Type_tr;
  extern Type_tr e_tr;
  extern Type_tr t_tr;
  class Class_trlist;
  typedef std::shared_ptr<Class_trlist> Type_trlist;
  extern Type_trlist e_trlist;
  extern Type_trlist t_trlist;
  class Class_boolean_write_from_id_htmltext;
  typedef std::shared_ptr<Class_boolean_write_from_id_htmltext> Func_boolean_write_from_id_htmltext;
  extern Func_boolean_write_from_id_htmltext e_boolean_write_from_id_htmltext;
  extern Func_boolean_write_from_id_htmltext t_boolean_write_from_id_htmltext;
  class Class_boolean_write_from_stylesheet;
  typedef std::shared_ptr<Class_boolean_write_from_stylesheet> Func_boolean_write_from_stylesheet;
  extern Func_boolean_write_from_stylesheet e_boolean_write_from_stylesheet;
  extern Func_boolean_write_from_stylesheet t_boolean_write_from_stylesheet;
  class Class_htmlstring_from_string;
  typedef std::shared_ptr<Class_htmlstring_from_string> Func_htmlstring_from_string;
  extern Func_htmlstring_from_string e_htmlstring_from_string;
  extern Func_htmlstring_from_string t_htmlstring_from_string;
  class Class_string_indent;
  typedef std::shared_ptr<Class_string_indent> Func_string_indent;
  extern Func_string_indent e_string_indent;
  extern Func_string_indent t_string_indent;
  class Class_string_from_body_indent;
  typedef std::shared_ptr<Class_string_from_body_indent> Func_string_from_body_indent;
  extern Func_string_from_body_indent e_string_from_body_indent;
  extern Func_string_from_body_indent t_string_from_body_indent;
  class Class_string_from_details_indent;
  typedef std::shared_ptr<Class_string_from_details_indent> Func_string_from_details_indent;
  extern Func_string_from_details_indent e_string_from_details_indent;
  extern Func_string_from_details_indent t_string_from_details_indent;
  class Class_string_from_div_indent;
  typedef std::shared_ptr<Class_string_from_div_indent> Func_string_from_div_indent;
  extern Func_string_from_div_indent e_string_from_div_indent;
  extern Func_string_from_div_indent t_string_from_div_indent;
  class Class_string_from_footer_indent;
  typedef std::shared_ptr<Class_string_from_footer_indent> Func_string_from_footer_indent;
  extern Func_string_from_footer_indent e_string_from_footer_indent;
  extern Func_string_from_footer_indent t_string_from_footer_indent;
  class Class_string_from_h1_indent;
  typedef std::shared_ptr<Class_string_from_h1_indent> Func_string_from_h1_indent;
  extern Func_string_from_h1_indent e_string_from_h1_indent;
  extern Func_string_from_h1_indent t_string_from_h1_indent;
  class Class_string_from_h2_indent;
  typedef std::shared_ptr<Class_string_from_h2_indent> Func_string_from_h2_indent;
  extern Func_string_from_h2_indent e_string_from_h2_indent;
  extern Func_string_from_h2_indent t_string_from_h2_indent;
  class Class_string_from_h3_indent;
  typedef std::shared_ptr<Class_string_from_h3_indent> Func_string_from_h3_indent;
  extern Func_string_from_h3_indent e_string_from_h3_indent;
  extern Func_string_from_h3_indent t_string_from_h3_indent;
  class Class_string_from_head_indent;
  typedef std::shared_ptr<Class_string_from_head_indent> Func_string_from_head_indent;
  extern Func_string_from_head_indent e_string_from_head_indent;
  extern Func_string_from_head_indent t_string_from_head_indent;
  class Class_string_from_html;
  typedef std::shared_ptr<Class_string_from_html> Func_string_from_html;
  extern Func_string_from_html e_string_from_html;
  extern Func_string_from_html t_string_from_html;
  class Class_string_from_indent;
  typedef std::shared_ptr<Class_string_from_indent> Func_string_from_indent;
  extern Func_string_from_indent e_string_from_indent;
  extern Func_string_from_indent t_string_from_indent;
  class Class_string_from_meta_indent;
  typedef std::shared_ptr<Class_string_from_meta_indent> Func_string_from_meta_indent;
  extern Func_string_from_meta_indent e_string_from_meta_indent;
  extern Func_string_from_meta_indent t_string_from_meta_indent;
  class Class_string_from_node_indent;
  typedef std::shared_ptr<Class_string_from_node_indent> Func_string_from_node_indent;
  extern Func_string_from_node_indent e_string_from_node_indent;
  extern Func_string_from_node_indent t_string_from_node_indent;
  class Class_string_from_nodelist_indent;
  typedef std::shared_ptr<Class_string_from_nodelist_indent> Func_string_from_nodelist_indent;
  extern Func_string_from_nodelist_indent e_string_from_nodelist_indent;
  extern Func_string_from_nodelist_indent t_string_from_nodelist_indent;
  class Class_string_from_nodelist_tag_prop_indent;
  typedef std::shared_ptr<Class_string_from_nodelist_tag_prop_indent> Func_string_from_nodelist_tag_prop_indent;
  extern Func_string_from_nodelist_tag_prop_indent e_string_from_nodelist_tag_prop_indent;
  extern Func_string_from_nodelist_tag_prop_indent t_string_from_nodelist_tag_prop_indent;
  class Class_string_from_p_indent;
  typedef std::shared_ptr<Class_string_from_p_indent> Func_string_from_p_indent;
  extern Func_string_from_p_indent e_string_from_p_indent;
  extern Func_string_from_p_indent t_string_from_p_indent;
  class Class_string_from_propname_val;
  typedef std::shared_ptr<Class_string_from_propname_val> Func_string_from_propname_val;
  extern Func_string_from_propname_val e_string_from_propname_val;
  extern Func_string_from_propname_val t_string_from_propname_val;
  class Class_string_from_propstyle;
  typedef std::shared_ptr<Class_string_from_propstyle> Func_string_from_propstyle;
  extern Func_string_from_propstyle e_string_from_propstyle;
  extern Func_string_from_propstyle t_string_from_propstyle;
  class Class_string_from_style_indent;
  typedef std::shared_ptr<Class_string_from_style_indent> Func_string_from_style_indent;
  extern Func_string_from_style_indent e_string_from_style_indent;
  extern Func_string_from_style_indent t_string_from_style_indent;
  class Class_string_from_stylelist_indent;
  typedef std::shared_ptr<Class_string_from_stylelist_indent> Func_string_from_stylelist_indent;
  extern Func_string_from_stylelist_indent e_string_from_stylelist_indent;
  extern Func_string_from_stylelist_indent t_string_from_stylelist_indent;
  class Class_string_from_stylepropmap_indent;
  typedef std::shared_ptr<Class_string_from_stylepropmap_indent> Func_string_from_stylepropmap_indent;
  extern Func_string_from_stylepropmap_indent e_string_from_stylepropmap_indent;
  extern Func_string_from_stylepropmap_indent t_string_from_stylepropmap_indent;
  class Class_string_from_stylesheet_indent;
  typedef std::shared_ptr<Class_string_from_stylesheet_indent> Func_string_from_stylesheet_indent;
  extern Func_string_from_stylesheet_indent e_string_from_stylesheet_indent;
  extern Func_string_from_stylesheet_indent t_string_from_stylesheet_indent;
  class Class_string_from_table_indent;
  typedef std::shared_ptr<Class_string_from_table_indent> Func_string_from_table_indent;
  extern Func_string_from_table_indent e_string_from_table_indent;
  extern Func_string_from_table_indent t_string_from_table_indent;
  class Class_string_from_tbody_indent;
  typedef std::shared_ptr<Class_string_from_tbody_indent> Func_string_from_tbody_indent;
  extern Func_string_from_tbody_indent e_string_from_tbody_indent;
  extern Func_string_from_tbody_indent t_string_from_tbody_indent;
  class Class_string_from_td_indent;
  typedef std::shared_ptr<Class_string_from_td_indent> Func_string_from_td_indent;
  extern Func_string_from_td_indent e_string_from_td_indent;
  extern Func_string_from_td_indent t_string_from_td_indent;
  class Class_string_from_thead_indent;
  typedef std::shared_ptr<Class_string_from_thead_indent> Func_string_from_thead_indent;
  extern Func_string_from_thead_indent e_string_from_thead_indent;
  extern Func_string_from_thead_indent t_string_from_thead_indent;
  class Class_string_from_title_indent;
  typedef std::shared_ptr<Class_string_from_title_indent> Func_string_from_title_indent;
  extern Func_string_from_title_indent e_string_from_title_indent;
  extern Func_string_from_title_indent t_string_from_title_indent;
  class Class_string_from_tr_indent;
  typedef std::shared_ptr<Class_string_from_tr_indent> Func_string_from_tr_indent;
  extern Func_string_from_tr_indent e_string_from_tr_indent;
  extern Func_string_from_tr_indent t_string_from_tr_indent;
  class Class_string_from_uri;
  typedef std::shared_ptr<Class_string_from_uri> Func_string_from_uri;
  extern Func_string_from_uri e_string_from_uri;
  extern Func_string_from_uri t_string_from_uri;
  class Class_style_from_stylesheet_name;
  typedef std::shared_ptr<Class_style_from_stylesheet_name> Func_style_from_stylesheet_name;
  extern Func_style_from_stylesheet_name e_style_from_stylesheet_name;
  extern Func_style_from_stylesheet_name t_style_from_stylesheet_name;
  class Class_stylemap_from_stylelist;
  typedef std::shared_ptr<Class_stylemap_from_stylelist> Func_stylemap_from_stylelist;
  extern Func_stylemap_from_stylelist e_stylemap_from_stylelist;
  extern Func_stylemap_from_stylelist t_stylemap_from_stylelist;
  class Class_stylemap_from_stylesheet;
  typedef std::shared_ptr<Class_stylemap_from_stylesheet> Func_stylemap_from_stylesheet;
  extern Func_stylemap_from_stylesheet e_stylemap_from_stylesheet;
  extern Func_stylemap_from_stylesheet t_stylemap_from_stylesheet;
  class Class_styles_from_stylesheet;
  typedef std::shared_ptr<Class_styles_from_stylesheet> Func_styles_from_stylesheet;
  extern Func_styles_from_stylesheet e_styles_from_stylesheet;
  extern Func_styles_from_stylesheet t_styles_from_stylesheet;
  class Class_stylesheet_loadmap;
  typedef std::shared_ptr<Class_stylesheet_loadmap> Func_stylesheet_loadmap;
  extern Func_stylesheet_loadmap e_stylesheet_loadmap;
  extern Func_stylesheet_loadmap t_stylesheet_loadmap;
  class Class_uri_from_string;
  typedef std::shared_ptr<Class_uri_from_string> Func_uri_from_string;
  extern Func_uri_from_string e_uri_from_string;
  extern Func_uri_from_string t_uri_from_string;

// :headerfirst

// :header


  // (type node)
  class Class_node : public virtual vx_core::Class_struct {
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
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // style()
    vx_web_html::Type_style vx_p_style;
    virtual vx_web_html::Type_style style();
  };

  // (type divchild)
  class Class_divchild : public virtual vx_core::Class_struct {
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
  };

  // (type body)
  class Class_body : public virtual vx_core::Class_struct {
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
    vx_web_html::Type_divchildlist vx_p_nodes;
    virtual vx_web_html::Type_divchildlist nodes();
  };

  // (type details)
  class Class_details : public virtual vx_core::Class_struct, public virtual vx_web_html::Type_node, public virtual vx_web_html::Type_divchild {
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
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // style()
    vx_web_html::Type_style vx_p_style;
    virtual vx_web_html::Type_style style();
    // summary()
    vx_web_html::Type_divchildlist vx_p_summary;
    virtual vx_web_html::Type_divchildlist summary();
    // nodes()
    vx_web_html::Type_divchildlist vx_p_nodes;
    virtual vx_web_html::Type_divchildlist nodes();
  };

  // (type div)
  class Class_div : public virtual vx_core::Class_struct, public virtual vx_web_html::Type_node, public virtual vx_web_html::Type_divchild {
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
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // style()
    vx_web_html::Type_style vx_p_style;
    virtual vx_web_html::Type_style style();
    // nodes()
    vx_web_html::Type_divchildlist vx_p_nodes;
    virtual vx_web_html::Type_divchildlist nodes();
  };

  // (type divchildlist)
  class Class_divchildlist : public virtual vx_core::Class_list {
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
    std::vector<vx_web_html::Type_divchild> vx_p_list;

    // vx_listdivchild()
    virtual std::vector<vx_web_html::Type_divchild> vx_listdivchild();
    // vx_divchild(index)
    virtual vx_web_html::Type_divchild vx_divchild(vx_core::Type_int index);
  };

  // (type divlist)
  class Class_divlist : public virtual vx_core::Class_list {
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
    std::vector<vx_web_html::Type_div> vx_p_list;

    // vx_listdiv()
    virtual std::vector<vx_web_html::Type_div> vx_listdiv();
    // vx_div(index)
    virtual vx_web_html::Type_div vx_div(vx_core::Type_int index);
  };

  // (type footer)
  class Class_footer : public virtual vx_core::Class_struct {
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
    vx_web_html::Type_divchildlist vx_p_nodes;
    virtual vx_web_html::Type_divchildlist nodes();
  };

  // (type h1)
  class Class_h1 : public virtual vx_core::Class_struct, public virtual vx_web_html::Type_node, public virtual vx_web_html::Type_divchild {
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
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // style()
    vx_web_html::Type_style vx_p_style;
    virtual vx_web_html::Type_style style();
    // text()
    vx_core::Type_string vx_p_text;
    virtual vx_core::Type_string text();
  };

  // (type h2)
  class Class_h2 : public virtual vx_core::Class_struct, public virtual vx_web_html::Type_node, public virtual vx_web_html::Type_divchild {
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
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // style()
    vx_web_html::Type_style vx_p_style;
    virtual vx_web_html::Type_style style();
    // text()
    vx_core::Type_string vx_p_text;
    virtual vx_core::Type_string text();
  };

  // (type h3)
  class Class_h3 : public virtual vx_core::Class_struct, public virtual vx_web_html::Type_node, public virtual vx_web_html::Type_divchild {
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
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // style()
    vx_web_html::Type_style vx_p_style;
    virtual vx_web_html::Type_style style();
    // text()
    vx_core::Type_string vx_p_text;
    virtual vx_core::Type_string text();
  };

  // (type head)
  class Class_head : public virtual vx_core::Class_struct {
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
    vx_web_html::Type_headchildlist vx_p_nodes;
    virtual vx_web_html::Type_headchildlist nodes();
  };

  // (type headchild)
  class Class_headchild : public virtual vx_core::Class_struct {
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
  };

  // (type headchildlist)
  class Class_headchildlist : public virtual vx_core::Class_list {
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
    std::vector<vx_web_html::Type_headchild> vx_p_list;

    // vx_listheadchild()
    virtual std::vector<vx_web_html::Type_headchild> vx_listheadchild();
    // vx_headchild(index)
    virtual vx_web_html::Type_headchild vx_headchild(vx_core::Type_int index);
  };

  // (type html)
  class Class_html : public virtual vx_core::Class_struct {
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
    // lang()
    vx_core::Type_string vx_p_lang;
    virtual vx_core::Type_string lang();
    // head()
    vx_web_html::Type_head vx_p_head;
    virtual vx_web_html::Type_head head();
    // body()
    vx_web_html::Type_body vx_p_body;
    virtual vx_web_html::Type_body body();
    // footer()
    vx_web_html::Type_footer vx_p_footer;
    virtual vx_web_html::Type_footer footer();
  };

  // (type meta)
  class Class_meta : public virtual vx_core::Class_struct, public virtual vx_web_html::Type_node, public virtual vx_web_html::Type_headchild {
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
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // style()
    vx_web_html::Type_style vx_p_style;
    virtual vx_web_html::Type_style style();
    // charset()
    vx_core::Type_string vx_p_charset;
    virtual vx_core::Type_string charset();
  };

  // (type nodelist)
  class Class_nodelist : public virtual vx_core::Class_list {
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
    std::vector<vx_web_html::Type_node> vx_p_list;

    // vx_listnode()
    virtual std::vector<vx_web_html::Type_node> vx_listnode();
    // vx_node(index)
    virtual vx_web_html::Type_node vx_node(vx_core::Type_int index);
  };

  // (type p)
  class Class_p : public virtual vx_core::Class_struct, public virtual vx_web_html::Type_node, public virtual vx_web_html::Type_divchild {
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
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // style()
    vx_web_html::Type_style vx_p_style;
    virtual vx_web_html::Type_style style();
    // text()
    vx_core::Type_string vx_p_text;
    virtual vx_core::Type_string text();
  };

  // (type propmap)
  class Class_propmap : public virtual vx_core::Class_map {
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

  // (type style)
  class Class_style : public virtual vx_core::Class_struct {
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
    // name()
    vx_core::Type_string vx_p_name;
    virtual vx_core::Type_string name();
    // props()
    vx_web_html::Type_propmap vx_p_props;
    virtual vx_web_html::Type_propmap props();
  };

  // (type stylelist)
  class Class_stylelist : public virtual vx_core::Class_list {
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
    std::vector<vx_web_html::Type_style> vx_p_list;

    // vx_liststyle()
    virtual std::vector<vx_web_html::Type_style> vx_liststyle();
    // vx_style(index)
    virtual vx_web_html::Type_style vx_style(vx_core::Type_int index);
  };

  // (type stylemap)
  class Class_stylemap : public virtual vx_core::Class_map {
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
    std::map<std::string, vx_web_html::Type_style> vx_p_map;
    // vx_mapstyle()
    virtual std::map<std::string, vx_web_html::Type_style> vx_mapstyle();
    // vx_style(key)
    virtual vx_web_html::Type_style vx_style(vx_core::Type_string key);
  };

  // (type stylesheet)
  class Class_stylesheet : public virtual vx_core::Class_struct, public virtual vx_web_html::Type_node, public virtual vx_web_html::Type_headchild {
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
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // style()
    vx_web_html::Type_style vx_p_style;
    virtual vx_web_html::Type_style style();
    // name()
    vx_core::Type_string vx_p_name;
    virtual vx_core::Type_string name();
    // styles()
    vx_web_html::Type_stylelist vx_p_styles;
    virtual vx_web_html::Type_stylelist styles();
    // stylemap()
    vx_web_html::Type_stylemap vx_p_stylemap;
    virtual vx_web_html::Type_stylemap stylemap();
  };

  // (type table)
  class Class_table : public virtual vx_core::Class_struct, public virtual vx_web_html::Type_node, public virtual vx_web_html::Type_divchild {
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
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // style()
    vx_web_html::Type_style vx_p_style;
    virtual vx_web_html::Type_style style();
    // tbody()
    vx_web_html::Type_tbody vx_p_tbody;
    virtual vx_web_html::Type_tbody tbody();
    // thead()
    vx_web_html::Type_thead vx_p_thead;
    virtual vx_web_html::Type_thead thead();
  };

  // (type tbody)
  class Class_tbody : public virtual vx_core::Class_struct, public virtual vx_web_html::Type_node {
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
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // style()
    vx_web_html::Type_style vx_p_style;
    virtual vx_web_html::Type_style style();
    // nodes()
    vx_web_html::Type_trlist vx_p_nodes;
    virtual vx_web_html::Type_trlist nodes();
  };

  // (type td)
  class Class_td : public virtual vx_core::Class_struct, public virtual vx_web_html::Type_node {
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
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // style()
    vx_web_html::Type_style vx_p_style;
    virtual vx_web_html::Type_style style();
    // nodes()
    vx_web_html::Type_divchildlist vx_p_nodes;
    virtual vx_web_html::Type_divchildlist nodes();
  };

  // (type tdlist)
  class Class_tdlist : public virtual vx_core::Class_list {
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
    std::vector<vx_web_html::Type_td> vx_p_list;

    // vx_listtd()
    virtual std::vector<vx_web_html::Type_td> vx_listtd();
    // vx_td(index)
    virtual vx_web_html::Type_td vx_td(vx_core::Type_int index);
  };

  // (type thead)
  class Class_thead : public virtual vx_core::Class_struct, public virtual vx_web_html::Type_node {
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
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // style()
    vx_web_html::Type_style vx_p_style;
    virtual vx_web_html::Type_style style();
    // nodes()
    vx_web_html::Type_trlist vx_p_nodes;
    virtual vx_web_html::Type_trlist nodes();
  };

  // (type title)
  class Class_title : public virtual vx_core::Class_struct, public virtual vx_web_html::Type_node, public virtual vx_web_html::Type_headchild {
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
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // style()
    vx_web_html::Type_style vx_p_style;
    virtual vx_web_html::Type_style style();
    // text()
    vx_core::Type_string vx_p_text;
    virtual vx_core::Type_string text();
  };

  // (type tr)
  class Class_tr : public virtual vx_core::Class_struct, public virtual vx_web_html::Type_node {
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
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // style()
    vx_web_html::Type_style vx_p_style;
    virtual vx_web_html::Type_style style();
    // nodes()
    vx_web_html::Type_tdlist vx_p_nodes;
    virtual vx_web_html::Type_tdlist nodes();
  };

  // (type trlist)
  class Class_trlist : public virtual vx_core::Class_list {
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
    std::vector<vx_web_html::Type_tr> vx_p_list;

    // vx_listtr()
    virtual std::vector<vx_web_html::Type_tr> vx_listtr();
    // vx_tr(index)
    virtual vx_web_html::Type_tr vx_tr(vx_core::Type_int index);
  };

  // (func boolean-write<-id-htmltext)
  class Class_boolean_write_from_id_htmltext : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_boolean vx_boolean_write_from_id_htmltext(vx_core::Type_string id, vx_core::Type_string htmltext);
  };

  // (func boolean-write<-stylesheet)
  class Class_boolean_write_from_stylesheet : public vx_core::Class_any_from_any_async, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_async fn_new(vx_core::Class_any_from_any_async::IFn fn);
    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    std::shared_ptr<vx_core::Async<vx_core::Type_boolean>> vx_boolean_write_from_stylesheet(vx_web_html::Type_stylesheet stylesheet);
  };

  // (func htmlstring<-string)
  class Class_htmlstring_from_string : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_string vx_htmlstring_from_string(vx_core::Type_string text);
  };

  // (func string-indent)
  class Class_string_indent : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_string vx_string_indent(vx_core::Type_int indent);
  };

  // (func string<-body-indent)
  class Class_string_from_body_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_body_indent(vx_web_html::Type_body body, vx_core::Type_int indent);
  };

  // (func string<-details-indent)
  class Class_string_from_details_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_details_indent(vx_web_html::Type_details details, vx_core::Type_int indent);
  };

  // (func string<-div-indent)
  class Class_string_from_div_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_div_indent(vx_web_html::Type_div div, vx_core::Type_int indent);
  };

  // (func string<-footer-indent)
  class Class_string_from_footer_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_footer_indent(vx_web_html::Type_footer footer, vx_core::Type_int indent);
  };

  // (func string<-h1-indent)
  class Class_string_from_h1_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_h1_indent(vx_web_html::Type_h1 h1, vx_core::Type_int indent);
  };

  // (func string<-h2-indent)
  class Class_string_from_h2_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_h2_indent(vx_web_html::Type_h2 h2, vx_core::Type_int indent);
  };

  // (func string<-h3-indent)
  class Class_string_from_h3_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_h3_indent(vx_web_html::Type_h3 h3, vx_core::Type_int indent);
  };

  // (func string<-head-indent)
  class Class_string_from_head_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_head_indent(vx_web_html::Type_head head, vx_core::Type_int indent);
  };

  // (func string<-html)
  class Class_string_from_html : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_string vx_string_from_html(vx_web_html::Type_html html);
  };

  // (func string<-indent)
  class Class_string_from_indent : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_string vx_string_from_indent(vx_core::Type_int indent);
  };

  // (func string<-meta-indent)
  class Class_string_from_meta_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_meta_indent(vx_web_html::Type_meta meta, vx_core::Type_int indent);
  };

  // (func string<-node-indent)
  class Class_string_from_node_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_node_indent(vx_core::Type_any node, vx_core::Type_int indent);
  };

  // (func string<-nodelist-indent)
  class Class_string_from_nodelist_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_nodelist_indent(vx_core::Type_list nodelist, vx_core::Type_int indent);
  };

  // (func string<-nodelist-tag-prop-indent)
  class Class_string_from_nodelist_tag_prop_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_nodelist_tag_prop_indent(vx_core::Type_list nodes, vx_core::Type_string tag, vx_core::Type_string prop, vx_core::Type_int indent);
  };

  // (func string<-p-indent)
  class Class_string_from_p_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_p_indent(vx_web_html::Type_p p, vx_core::Type_int indent);
  };

  // (func string<-propname-val)
  class Class_string_from_propname_val : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_propname_val(vx_core::Type_string key, vx_core::Type_string val);
  };

  // (func string<-propstyle)
  class Class_string_from_propstyle : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_string vx_string_from_propstyle(vx_web_html::Type_style style);
  };

  // (func string<-style-indent)
  class Class_string_from_style_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_style_indent(vx_web_html::Type_style style, vx_core::Type_int indent);
  };

  // (func string<-stylelist-indent)
  class Class_string_from_stylelist_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_stylelist_indent(vx_web_html::Type_stylelist stylelist, vx_core::Type_int indent);
  };

  // (func string<-stylepropmap-indent)
  class Class_string_from_stylepropmap_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_stylepropmap_indent(vx_web_html::Type_propmap propmap, vx_core::Type_int indent);
  };

  // (func string<-stylesheet-indent)
  class Class_string_from_stylesheet_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_stylesheet_indent(vx_web_html::Type_stylesheet stylesheet, vx_core::Type_int indent);
  };

  // (func string<-table-indent)
  class Class_string_from_table_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_table_indent(vx_web_html::Type_table table, vx_core::Type_int indent);
  };

  // (func string<-tbody-indent)
  class Class_string_from_tbody_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_tbody_indent(vx_web_html::Type_tbody tbody, vx_core::Type_int indent);
  };

  // (func string<-td-indent)
  class Class_string_from_td_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_td_indent(vx_web_html::Type_td td, vx_core::Type_int indent);
  };

  // (func string<-thead-indent)
  class Class_string_from_thead_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_thead_indent(vx_web_html::Type_thead thead, vx_core::Type_int indent);
  };

  // (func string<-title-indent)
  class Class_string_from_title_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_title_indent(vx_web_html::Type_title title, vx_core::Type_int indent);
  };

  // (func string<-tr-indent)
  class Class_string_from_tr_indent : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_core::Type_string vx_string_from_tr_indent(vx_web_html::Type_tr tr, vx_core::Type_int indent);
  };

  // (func string<-uri)
  class Class_string_from_uri : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_string vx_string_from_uri(vx_core::Type_string uri);
  };

  // (func style<-stylesheet-name)
  class Class_style_from_stylesheet_name : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_web_html::Type_style vx_style_from_stylesheet_name(vx_web_html::Type_stylesheet stylesheet, vx_core::Type_string name);
  };

  // (func stylemap<-stylelist)
  class Class_stylemap_from_stylelist : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_web_html::Type_stylemap vx_stylemap_from_stylelist(vx_web_html::Type_stylelist stylelist);
  };

  // (func stylemap<-stylesheet)
  class Class_stylemap_from_stylesheet : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_web_html::Type_stylemap vx_stylemap_from_stylesheet(vx_web_html::Type_stylesheet stylesheet);
  };

  // (func styles<-stylesheet)
  class Class_styles_from_stylesheet : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_web_html::Type_stylelist vx_styles_from_stylesheet(vx_web_html::Type_stylesheet stylesheet);
  };

  // (func stylesheet-loadmap)
  class Class_stylesheet_loadmap : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_web_html::Type_stylesheet vx_stylesheet_loadmap(vx_web_html::Type_stylesheet stylesheet);
  };

  // (func uri<-string)
  class Class_uri_from_string : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_string vx_uri_from_string(vx_core::Type_string text);
  };

  // (func boolean-write<-id-htmltext)
  vx_core::Type_boolean f_boolean_write_from_id_htmltext(vx_core::Type_string id, vx_core::Type_string htmltext);

  // (func boolean-write<-stylesheet)
  std::shared_ptr<vx_core::Async<vx_core::Type_boolean>> f_boolean_write_from_stylesheet(vx_web_html::Type_stylesheet stylesheet);

  // (func htmlstring<-string)
  vx_core::Type_string f_htmlstring_from_string(vx_core::Type_string text);

  // (func string-indent)
  vx_core::Type_string f_string_indent(vx_core::Type_int indent);

  // (func string<-body-indent)
  vx_core::Type_string f_string_from_body_indent(vx_web_html::Type_body body, vx_core::Type_int indent);

  // (func string<-details-indent)
  vx_core::Type_string f_string_from_details_indent(vx_web_html::Type_details details, vx_core::Type_int indent);

  // (func string<-div-indent)
  vx_core::Type_string f_string_from_div_indent(vx_web_html::Type_div div, vx_core::Type_int indent);

  // (func string<-footer-indent)
  vx_core::Type_string f_string_from_footer_indent(vx_web_html::Type_footer footer, vx_core::Type_int indent);

  // (func string<-h1-indent)
  vx_core::Type_string f_string_from_h1_indent(vx_web_html::Type_h1 h1, vx_core::Type_int indent);

  // (func string<-h2-indent)
  vx_core::Type_string f_string_from_h2_indent(vx_web_html::Type_h2 h2, vx_core::Type_int indent);

  // (func string<-h3-indent)
  vx_core::Type_string f_string_from_h3_indent(vx_web_html::Type_h3 h3, vx_core::Type_int indent);

  // (func string<-head-indent)
  vx_core::Type_string f_string_from_head_indent(vx_web_html::Type_head head, vx_core::Type_int indent);

  // (func string<-html)
  vx_core::Type_string f_string_from_html(vx_web_html::Type_html html);

  // (func string<-indent)
  vx_core::Type_string f_string_from_indent(vx_core::Type_int indent);

  // (func string<-meta-indent)
  vx_core::Type_string f_string_from_meta_indent(vx_web_html::Type_meta meta, vx_core::Type_int indent);

  // (func string<-node-indent)
  vx_core::Type_string f_string_from_node_indent(vx_core::Type_any node, vx_core::Type_int indent);

  // (func string<-nodelist-indent)
  vx_core::Type_string f_string_from_nodelist_indent(vx_core::Type_list nodelist, vx_core::Type_int indent);

  // (func string<-nodelist-tag-prop-indent)
  vx_core::Type_string f_string_from_nodelist_tag_prop_indent(vx_core::Type_list nodes, vx_core::Type_string tag, vx_core::Type_string prop, vx_core::Type_int indent);

  // (func string<-p-indent)
  vx_core::Type_string f_string_from_p_indent(vx_web_html::Type_p p, vx_core::Type_int indent);

  // (func string<-propname-val)
  vx_core::Type_string f_string_from_propname_val(vx_core::Type_string key, vx_core::Type_string val);

  // (func string<-propstyle)
  vx_core::Type_string f_string_from_propstyle(vx_web_html::Type_style style);

  // (func string<-style-indent)
  vx_core::Type_string f_string_from_style_indent(vx_web_html::Type_style style, vx_core::Type_int indent);

  // (func string<-stylelist-indent)
  vx_core::Type_string f_string_from_stylelist_indent(vx_web_html::Type_stylelist stylelist, vx_core::Type_int indent);

  // (func string<-stylepropmap-indent)
  vx_core::Type_string f_string_from_stylepropmap_indent(vx_web_html::Type_propmap propmap, vx_core::Type_int indent);

  // (func string<-stylesheet-indent)
  vx_core::Type_string f_string_from_stylesheet_indent(vx_web_html::Type_stylesheet stylesheet, vx_core::Type_int indent);

  // (func string<-table-indent)
  vx_core::Type_string f_string_from_table_indent(vx_web_html::Type_table table, vx_core::Type_int indent);

  // (func string<-tbody-indent)
  vx_core::Type_string f_string_from_tbody_indent(vx_web_html::Type_tbody tbody, vx_core::Type_int indent);

  // (func string<-td-indent)
  vx_core::Type_string f_string_from_td_indent(vx_web_html::Type_td td, vx_core::Type_int indent);

  // (func string<-thead-indent)
  vx_core::Type_string f_string_from_thead_indent(vx_web_html::Type_thead thead, vx_core::Type_int indent);

  // (func string<-title-indent)
  vx_core::Type_string f_string_from_title_indent(vx_web_html::Type_title title, vx_core::Type_int indent);

  // (func string<-tr-indent)
  vx_core::Type_string f_string_from_tr_indent(vx_web_html::Type_tr tr, vx_core::Type_int indent);

  // (func string<-uri)
  vx_core::Type_string f_string_from_uri(vx_core::Type_string uri);

  // (func style<-stylesheet-name)
  vx_web_html::Type_style f_style_from_stylesheet_name(vx_web_html::Type_stylesheet stylesheet, vx_core::Type_string name);

  // (func stylemap<-stylelist)
  vx_web_html::Type_stylemap f_stylemap_from_stylelist(vx_web_html::Type_stylelist stylelist);

  // (func stylemap<-stylesheet)
  vx_web_html::Type_stylemap f_stylemap_from_stylesheet(vx_web_html::Type_stylesheet stylesheet);

  // (func styles<-stylesheet)
  vx_web_html::Type_stylelist f_styles_from_stylesheet(vx_web_html::Type_stylesheet stylesheet);

  // (func stylesheet-loadmap)
  vx_web_html::Type_stylesheet f_stylesheet_loadmap(vx_web_html::Type_stylesheet stylesheet);

  // (func uri<-string)
  vx_core::Type_string f_uri_from_string(vx_core::Type_string text);

}
