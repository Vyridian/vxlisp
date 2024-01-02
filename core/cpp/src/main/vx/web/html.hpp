#ifndef VX_WEB_HTML_HPP
#define VX_WEB_HTML_HPP
#include <map>
#include <string>
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/type.hpp"

namespace vx_web_html {


  // forward declarations
  class Abstract_body;
  typedef Abstract_body* Type_body;
  extern Type_body e_body;
  extern Type_body t_body;
  class Abstract_details;
  typedef Abstract_details* Type_details;
  extern Type_details e_details;
  extern Type_details t_details;
  class Abstract_div;
  typedef Abstract_div* Type_div;
  extern Type_div e_div;
  extern Type_div t_div;
  class Abstract_divchild;
  typedef Abstract_divchild* Type_divchild;
  extern Type_divchild e_divchild;
  extern Type_divchild t_divchild;
  class Abstract_divchildlist;
  typedef Abstract_divchildlist* Type_divchildlist;
  extern Type_divchildlist e_divchildlist;
  extern Type_divchildlist t_divchildlist;
  class Abstract_divlist;
  typedef Abstract_divlist* Type_divlist;
  extern Type_divlist e_divlist;
  extern Type_divlist t_divlist;
  class Abstract_footer;
  typedef Abstract_footer* Type_footer;
  extern Type_footer e_footer;
  extern Type_footer t_footer;
  class Abstract_h1;
  typedef Abstract_h1* Type_h1;
  extern Type_h1 e_h1;
  extern Type_h1 t_h1;
  class Abstract_h2;
  typedef Abstract_h2* Type_h2;
  extern Type_h2 e_h2;
  extern Type_h2 t_h2;
  class Abstract_h3;
  typedef Abstract_h3* Type_h3;
  extern Type_h3 e_h3;
  extern Type_h3 t_h3;
  class Abstract_head;
  typedef Abstract_head* Type_head;
  extern Type_head e_head;
  extern Type_head t_head;
  class Abstract_headchild;
  typedef Abstract_headchild* Type_headchild;
  extern Type_headchild e_headchild;
  extern Type_headchild t_headchild;
  class Abstract_headchildlist;
  typedef Abstract_headchildlist* Type_headchildlist;
  extern Type_headchildlist e_headchildlist;
  extern Type_headchildlist t_headchildlist;
  class Abstract_html;
  typedef Abstract_html* Type_html;
  extern Type_html e_html;
  extern Type_html t_html;
  class Abstract_meta;
  typedef Abstract_meta* Type_meta;
  extern Type_meta e_meta;
  extern Type_meta t_meta;
  class Abstract_node;
  typedef Abstract_node* Type_node;
  extern Type_node e_node;
  extern Type_node t_node;
  class Abstract_nodelist;
  typedef Abstract_nodelist* Type_nodelist;
  extern Type_nodelist e_nodelist;
  extern Type_nodelist t_nodelist;
  class Abstract_p;
  typedef Abstract_p* Type_p;
  extern Type_p e_p;
  extern Type_p t_p;
  class Abstract_propmap;
  typedef Abstract_propmap* Type_propmap;
  extern Type_propmap e_propmap;
  extern Type_propmap t_propmap;
  class Abstract_style;
  typedef Abstract_style* Type_style;
  extern Type_style e_style;
  extern Type_style t_style;
  class Abstract_stylelist;
  typedef Abstract_stylelist* Type_stylelist;
  extern Type_stylelist e_stylelist;
  extern Type_stylelist t_stylelist;
  class Abstract_stylemap;
  typedef Abstract_stylemap* Type_stylemap;
  extern Type_stylemap e_stylemap;
  extern Type_stylemap t_stylemap;
  class Abstract_stylesheet;
  typedef Abstract_stylesheet* Type_stylesheet;
  extern Type_stylesheet e_stylesheet;
  extern Type_stylesheet t_stylesheet;
  class Abstract_table;
  typedef Abstract_table* Type_table;
  extern Type_table e_table;
  extern Type_table t_table;
  class Abstract_tbody;
  typedef Abstract_tbody* Type_tbody;
  extern Type_tbody e_tbody;
  extern Type_tbody t_tbody;
  class Abstract_td;
  typedef Abstract_td* Type_td;
  extern Type_td e_td;
  extern Type_td t_td;
  class Abstract_tdlist;
  typedef Abstract_tdlist* Type_tdlist;
  extern Type_tdlist e_tdlist;
  extern Type_tdlist t_tdlist;
  class Abstract_thead;
  typedef Abstract_thead* Type_thead;
  extern Type_thead e_thead;
  extern Type_thead t_thead;
  class Abstract_title;
  typedef Abstract_title* Type_title;
  extern Type_title e_title;
  extern Type_title t_title;
  class Abstract_tr;
  typedef Abstract_tr* Type_tr;
  extern Type_tr e_tr;
  extern Type_tr t_tr;
  class Abstract_trlist;
  typedef Abstract_trlist* Type_trlist;
  extern Type_trlist e_trlist;
  extern Type_trlist t_trlist;
  class Abstract_htmlstring_from_string;
  typedef Abstract_htmlstring_from_string* Func_htmlstring_from_string;
  extern Func_htmlstring_from_string e_htmlstring_from_string;
  extern Func_htmlstring_from_string t_htmlstring_from_string;
  class Abstract_string_indent;
  typedef Abstract_string_indent* Func_string_indent;
  extern Func_string_indent e_string_indent;
  extern Func_string_indent t_string_indent;
  class Abstract_string_from_body_indent;
  typedef Abstract_string_from_body_indent* Func_string_from_body_indent;
  extern Func_string_from_body_indent e_string_from_body_indent;
  extern Func_string_from_body_indent t_string_from_body_indent;
  class Abstract_string_from_details_indent;
  typedef Abstract_string_from_details_indent* Func_string_from_details_indent;
  extern Func_string_from_details_indent e_string_from_details_indent;
  extern Func_string_from_details_indent t_string_from_details_indent;
  class Abstract_string_from_div_indent;
  typedef Abstract_string_from_div_indent* Func_string_from_div_indent;
  extern Func_string_from_div_indent e_string_from_div_indent;
  extern Func_string_from_div_indent t_string_from_div_indent;
  class Abstract_string_from_footer_indent;
  typedef Abstract_string_from_footer_indent* Func_string_from_footer_indent;
  extern Func_string_from_footer_indent e_string_from_footer_indent;
  extern Func_string_from_footer_indent t_string_from_footer_indent;
  class Abstract_string_from_h1_indent;
  typedef Abstract_string_from_h1_indent* Func_string_from_h1_indent;
  extern Func_string_from_h1_indent e_string_from_h1_indent;
  extern Func_string_from_h1_indent t_string_from_h1_indent;
  class Abstract_string_from_h2_indent;
  typedef Abstract_string_from_h2_indent* Func_string_from_h2_indent;
  extern Func_string_from_h2_indent e_string_from_h2_indent;
  extern Func_string_from_h2_indent t_string_from_h2_indent;
  class Abstract_string_from_h3_indent;
  typedef Abstract_string_from_h3_indent* Func_string_from_h3_indent;
  extern Func_string_from_h3_indent e_string_from_h3_indent;
  extern Func_string_from_h3_indent t_string_from_h3_indent;
  class Abstract_string_from_head_indent;
  typedef Abstract_string_from_head_indent* Func_string_from_head_indent;
  extern Func_string_from_head_indent e_string_from_head_indent;
  extern Func_string_from_head_indent t_string_from_head_indent;
  class Abstract_string_from_html;
  typedef Abstract_string_from_html* Func_string_from_html;
  extern Func_string_from_html e_string_from_html;
  extern Func_string_from_html t_string_from_html;
  class Abstract_string_from_indent;
  typedef Abstract_string_from_indent* Func_string_from_indent;
  extern Func_string_from_indent e_string_from_indent;
  extern Func_string_from_indent t_string_from_indent;
  class Abstract_string_from_meta_indent;
  typedef Abstract_string_from_meta_indent* Func_string_from_meta_indent;
  extern Func_string_from_meta_indent e_string_from_meta_indent;
  extern Func_string_from_meta_indent t_string_from_meta_indent;
  class Abstract_string_from_node_indent;
  typedef Abstract_string_from_node_indent* Func_string_from_node_indent;
  extern Func_string_from_node_indent e_string_from_node_indent;
  extern Func_string_from_node_indent t_string_from_node_indent;
  class Abstract_string_from_nodelist_indent;
  typedef Abstract_string_from_nodelist_indent* Func_string_from_nodelist_indent;
  extern Func_string_from_nodelist_indent e_string_from_nodelist_indent;
  extern Func_string_from_nodelist_indent t_string_from_nodelist_indent;
  class Abstract_string_from_nodelist_tag_prop_indent;
  typedef Abstract_string_from_nodelist_tag_prop_indent* Func_string_from_nodelist_tag_prop_indent;
  extern Func_string_from_nodelist_tag_prop_indent e_string_from_nodelist_tag_prop_indent;
  extern Func_string_from_nodelist_tag_prop_indent t_string_from_nodelist_tag_prop_indent;
  class Abstract_string_from_p_indent;
  typedef Abstract_string_from_p_indent* Func_string_from_p_indent;
  extern Func_string_from_p_indent e_string_from_p_indent;
  extern Func_string_from_p_indent t_string_from_p_indent;
  class Abstract_string_from_propname_val;
  typedef Abstract_string_from_propname_val* Func_string_from_propname_val;
  extern Func_string_from_propname_val e_string_from_propname_val;
  extern Func_string_from_propname_val t_string_from_propname_val;
  class Abstract_string_from_propstyle;
  typedef Abstract_string_from_propstyle* Func_string_from_propstyle;
  extern Func_string_from_propstyle e_string_from_propstyle;
  extern Func_string_from_propstyle t_string_from_propstyle;
  class Abstract_string_from_style_indent;
  typedef Abstract_string_from_style_indent* Func_string_from_style_indent;
  extern Func_string_from_style_indent e_string_from_style_indent;
  extern Func_string_from_style_indent t_string_from_style_indent;
  class Abstract_string_from_stylelist_indent;
  typedef Abstract_string_from_stylelist_indent* Func_string_from_stylelist_indent;
  extern Func_string_from_stylelist_indent e_string_from_stylelist_indent;
  extern Func_string_from_stylelist_indent t_string_from_stylelist_indent;
  class Abstract_string_from_stylepropmap_indent;
  typedef Abstract_string_from_stylepropmap_indent* Func_string_from_stylepropmap_indent;
  extern Func_string_from_stylepropmap_indent e_string_from_stylepropmap_indent;
  extern Func_string_from_stylepropmap_indent t_string_from_stylepropmap_indent;
  class Abstract_string_from_stylesheet_indent;
  typedef Abstract_string_from_stylesheet_indent* Func_string_from_stylesheet_indent;
  extern Func_string_from_stylesheet_indent e_string_from_stylesheet_indent;
  extern Func_string_from_stylesheet_indent t_string_from_stylesheet_indent;
  class Abstract_string_from_table_indent;
  typedef Abstract_string_from_table_indent* Func_string_from_table_indent;
  extern Func_string_from_table_indent e_string_from_table_indent;
  extern Func_string_from_table_indent t_string_from_table_indent;
  class Abstract_string_from_tbody_indent;
  typedef Abstract_string_from_tbody_indent* Func_string_from_tbody_indent;
  extern Func_string_from_tbody_indent e_string_from_tbody_indent;
  extern Func_string_from_tbody_indent t_string_from_tbody_indent;
  class Abstract_string_from_td_indent;
  typedef Abstract_string_from_td_indent* Func_string_from_td_indent;
  extern Func_string_from_td_indent e_string_from_td_indent;
  extern Func_string_from_td_indent t_string_from_td_indent;
  class Abstract_string_from_thead_indent;
  typedef Abstract_string_from_thead_indent* Func_string_from_thead_indent;
  extern Func_string_from_thead_indent e_string_from_thead_indent;
  extern Func_string_from_thead_indent t_string_from_thead_indent;
  class Abstract_string_from_title_indent;
  typedef Abstract_string_from_title_indent* Func_string_from_title_indent;
  extern Func_string_from_title_indent e_string_from_title_indent;
  extern Func_string_from_title_indent t_string_from_title_indent;
  class Abstract_string_from_tr_indent;
  typedef Abstract_string_from_tr_indent* Func_string_from_tr_indent;
  extern Func_string_from_tr_indent e_string_from_tr_indent;
  extern Func_string_from_tr_indent t_string_from_tr_indent;
  class Abstract_string_from_uri;
  typedef Abstract_string_from_uri* Func_string_from_uri;
  extern Func_string_from_uri e_string_from_uri;
  extern Func_string_from_uri t_string_from_uri;
  class Abstract_style_from_stylesheet_name;
  typedef Abstract_style_from_stylesheet_name* Func_style_from_stylesheet_name;
  extern Func_style_from_stylesheet_name e_style_from_stylesheet_name;
  extern Func_style_from_stylesheet_name t_style_from_stylesheet_name;
  class Abstract_stylemap_from_stylelist;
  typedef Abstract_stylemap_from_stylelist* Func_stylemap_from_stylelist;
  extern Func_stylemap_from_stylelist e_stylemap_from_stylelist;
  extern Func_stylemap_from_stylelist t_stylemap_from_stylelist;
  class Abstract_stylemap_from_stylesheet;
  typedef Abstract_stylemap_from_stylesheet* Func_stylemap_from_stylesheet;
  extern Func_stylemap_from_stylesheet e_stylemap_from_stylesheet;
  extern Func_stylemap_from_stylesheet t_stylemap_from_stylesheet;
  class Abstract_styles_from_stylesheet;
  typedef Abstract_styles_from_stylesheet* Func_styles_from_stylesheet;
  extern Func_styles_from_stylesheet e_styles_from_stylesheet;
  extern Func_styles_from_stylesheet t_styles_from_stylesheet;
  class Abstract_stylesheet_loadmap;
  typedef Abstract_stylesheet_loadmap* Func_stylesheet_loadmap;
  extern Func_stylesheet_loadmap e_stylesheet_loadmap;
  extern Func_stylesheet_loadmap t_stylesheet_loadmap;
  class Abstract_uri_from_string;
  typedef Abstract_uri_from_string* Func_uri_from_string;
  extern Func_uri_from_string e_uri_from_string;
  extern Func_uri_from_string t_uri_from_string;// :headerfirst

// :header


  // (type node)
  class Abstract_node : public virtual vx_core::Abstract_struct {
  public:
    Abstract_node() {};
    virtual ~Abstract_node() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // style()
    vx_web_html::Type_style vx_p_style = NULL;
    virtual vx_web_html::Type_style style() const = 0;
  };
  class Class_node : public virtual Abstract_node {
  public:
    Class_node();
    virtual ~Class_node() override;
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
    virtual vx_core::Type_string id() const override;
    virtual vx_web_html::Type_style style() const override;
  };

  // (type divchild)
  class Abstract_divchild : public virtual vx_core::Abstract_struct {
  public:
    Abstract_divchild() {};
    virtual ~Abstract_divchild() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
  };
  class Class_divchild : public virtual Abstract_divchild {
  public:
    Class_divchild();
    virtual ~Class_divchild() override;
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
  };

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

  // (type body)
  class Abstract_body : public virtual vx_core::Abstract_struct {
  public:
    Abstract_body() {};
    virtual ~Abstract_body() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // nodes()
    vx_web_html::Type_divchildlist vx_p_nodes = NULL;
    virtual vx_web_html::Type_divchildlist nodes() const = 0;
  };
  class Class_body : public virtual Abstract_body {
  public:
    Class_body();
    virtual ~Class_body() override;
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
    virtual vx_web_html::Type_divchildlist nodes() const override;
  };

  // (type details)
  class Abstract_details : public virtual vx_core::Abstract_struct, public virtual vx_web_html::Abstract_node, public virtual vx_web_html::Abstract_divchild {
  public:
    Abstract_details() {};
    virtual ~Abstract_details() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // style()
    vx_web_html::Type_style vx_p_style = NULL;
    virtual vx_web_html::Type_style style() const = 0;
    // summary()
    vx_web_html::Type_divchildlist vx_p_summary = NULL;
    virtual vx_web_html::Type_divchildlist summary() const = 0;
    // nodes()
    vx_web_html::Type_divchildlist vx_p_nodes = NULL;
    virtual vx_web_html::Type_divchildlist nodes() const = 0;
  };
  class Class_details : public virtual Abstract_details {
  public:
    Class_details();
    virtual ~Class_details() override;
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
    virtual vx_core::Type_string id() const override;
    virtual vx_web_html::Type_style style() const override;
    virtual vx_web_html::Type_divchildlist summary() const override;
    virtual vx_web_html::Type_divchildlist nodes() const override;
  };

  // (type div)
  class Abstract_div : public virtual vx_core::Abstract_struct, public virtual vx_web_html::Abstract_node, public virtual vx_web_html::Abstract_divchild {
  public:
    Abstract_div() {};
    virtual ~Abstract_div() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // style()
    vx_web_html::Type_style vx_p_style = NULL;
    virtual vx_web_html::Type_style style() const = 0;
    // nodes()
    vx_web_html::Type_divchildlist vx_p_nodes = NULL;
    virtual vx_web_html::Type_divchildlist nodes() const = 0;
  };
  class Class_div : public virtual Abstract_div {
  public:
    Class_div();
    virtual ~Class_div() override;
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
    virtual vx_core::Type_string id() const override;
    virtual vx_web_html::Type_style style() const override;
    virtual vx_web_html::Type_divchildlist nodes() const override;
  };

  // (type divchildlist)
  class Abstract_divchildlist : public virtual vx_core::Abstract_list {
  public:
    Abstract_divchildlist() {};
    virtual ~Abstract_divchildlist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_web_html::Type_divchild> vx_p_list;
    // vx_listdivchild()
    virtual std::vector<vx_web_html::Type_divchild> vx_listdivchild() const = 0;
    // vx_get_divchild(index)
    virtual vx_web_html::Type_divchild vx_get_divchild(vx_core::Type_int index) const = 0;
  };
  class Class_divchildlist : public virtual Abstract_divchildlist {
  public:
    Class_divchildlist();
    virtual ~Class_divchildlist() override;
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
    virtual std::vector<vx_web_html::Type_divchild> vx_listdivchild() const override;
    virtual vx_web_html::Type_divchild vx_get_divchild(vx_core::Type_int index) const override;
  };

  // (type divlist)
  class Abstract_divlist : public virtual vx_core::Abstract_list {
  public:
    Abstract_divlist() {};
    virtual ~Abstract_divlist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_web_html::Type_div> vx_p_list;
    // vx_listdiv()
    virtual std::vector<vx_web_html::Type_div> vx_listdiv() const = 0;
    // vx_get_div(index)
    virtual vx_web_html::Type_div vx_get_div(vx_core::Type_int index) const = 0;
  };
  class Class_divlist : public virtual Abstract_divlist {
  public:
    Class_divlist();
    virtual ~Class_divlist() override;
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
    virtual std::vector<vx_web_html::Type_div> vx_listdiv() const override;
    virtual vx_web_html::Type_div vx_get_div(vx_core::Type_int index) const override;
  };

  // (type footer)
  class Abstract_footer : public virtual vx_core::Abstract_struct {
  public:
    Abstract_footer() {};
    virtual ~Abstract_footer() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // nodes()
    vx_web_html::Type_divchildlist vx_p_nodes = NULL;
    virtual vx_web_html::Type_divchildlist nodes() const = 0;
  };
  class Class_footer : public virtual Abstract_footer {
  public:
    Class_footer();
    virtual ~Class_footer() override;
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
    virtual vx_web_html::Type_divchildlist nodes() const override;
  };

  // (type h1)
  class Abstract_h1 : public virtual vx_core::Abstract_struct, public virtual vx_web_html::Abstract_node, public virtual vx_web_html::Abstract_divchild {
  public:
    Abstract_h1() {};
    virtual ~Abstract_h1() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // style()
    vx_web_html::Type_style vx_p_style = NULL;
    virtual vx_web_html::Type_style style() const = 0;
    // text()
    vx_core::Type_string vx_p_text = NULL;
    virtual vx_core::Type_string text() const = 0;
  };
  class Class_h1 : public virtual Abstract_h1 {
  public:
    Class_h1();
    virtual ~Class_h1() override;
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
    virtual vx_core::Type_string id() const override;
    virtual vx_web_html::Type_style style() const override;
    virtual vx_core::Type_string text() const override;
  };

  // (type h2)
  class Abstract_h2 : public virtual vx_core::Abstract_struct, public virtual vx_web_html::Abstract_node, public virtual vx_web_html::Abstract_divchild {
  public:
    Abstract_h2() {};
    virtual ~Abstract_h2() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // style()
    vx_web_html::Type_style vx_p_style = NULL;
    virtual vx_web_html::Type_style style() const = 0;
    // text()
    vx_core::Type_string vx_p_text = NULL;
    virtual vx_core::Type_string text() const = 0;
  };
  class Class_h2 : public virtual Abstract_h2 {
  public:
    Class_h2();
    virtual ~Class_h2() override;
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
    virtual vx_core::Type_string id() const override;
    virtual vx_web_html::Type_style style() const override;
    virtual vx_core::Type_string text() const override;
  };

  // (type h3)
  class Abstract_h3 : public virtual vx_core::Abstract_struct, public virtual vx_web_html::Abstract_node, public virtual vx_web_html::Abstract_divchild {
  public:
    Abstract_h3() {};
    virtual ~Abstract_h3() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // style()
    vx_web_html::Type_style vx_p_style = NULL;
    virtual vx_web_html::Type_style style() const = 0;
    // text()
    vx_core::Type_string vx_p_text = NULL;
    virtual vx_core::Type_string text() const = 0;
  };
  class Class_h3 : public virtual Abstract_h3 {
  public:
    Class_h3();
    virtual ~Class_h3() override;
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
    virtual vx_core::Type_string id() const override;
    virtual vx_web_html::Type_style style() const override;
    virtual vx_core::Type_string text() const override;
  };

  // (type head)
  class Abstract_head : public virtual vx_core::Abstract_struct {
  public:
    Abstract_head() {};
    virtual ~Abstract_head() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // nodes()
    vx_web_html::Type_headchildlist vx_p_nodes = NULL;
    virtual vx_web_html::Type_headchildlist nodes() const = 0;
  };
  class Class_head : public virtual Abstract_head {
  public:
    Class_head();
    virtual ~Class_head() override;
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
    virtual vx_web_html::Type_headchildlist nodes() const override;
  };

  // (type headchild)
  class Abstract_headchild : public virtual vx_core::Abstract_struct {
  public:
    Abstract_headchild() {};
    virtual ~Abstract_headchild() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
  };
  class Class_headchild : public virtual Abstract_headchild {
  public:
    Class_headchild();
    virtual ~Class_headchild() override;
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
  };

  // (type headchildlist)
  class Abstract_headchildlist : public virtual vx_core::Abstract_list {
  public:
    Abstract_headchildlist() {};
    virtual ~Abstract_headchildlist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_web_html::Type_headchild> vx_p_list;
    // vx_listheadchild()
    virtual std::vector<vx_web_html::Type_headchild> vx_listheadchild() const = 0;
    // vx_get_headchild(index)
    virtual vx_web_html::Type_headchild vx_get_headchild(vx_core::Type_int index) const = 0;
  };
  class Class_headchildlist : public virtual Abstract_headchildlist {
  public:
    Class_headchildlist();
    virtual ~Class_headchildlist() override;
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
    virtual std::vector<vx_web_html::Type_headchild> vx_listheadchild() const override;
    virtual vx_web_html::Type_headchild vx_get_headchild(vx_core::Type_int index) const override;
  };

  // (type html)
  class Abstract_html : public virtual vx_core::Abstract_struct {
  public:
    Abstract_html() {};
    virtual ~Abstract_html() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // lang()
    vx_core::Type_string vx_p_lang = NULL;
    virtual vx_core::Type_string lang() const = 0;
    // head()
    vx_web_html::Type_head vx_p_head = NULL;
    virtual vx_web_html::Type_head head() const = 0;
    // body()
    vx_web_html::Type_body vx_p_body = NULL;
    virtual vx_web_html::Type_body body() const = 0;
    // footer()
    vx_web_html::Type_footer vx_p_footer = NULL;
    virtual vx_web_html::Type_footer footer() const = 0;
  };
  class Class_html : public virtual Abstract_html {
  public:
    Class_html();
    virtual ~Class_html() override;
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
    virtual vx_core::Type_string lang() const override;
    virtual vx_web_html::Type_head head() const override;
    virtual vx_web_html::Type_body body() const override;
    virtual vx_web_html::Type_footer footer() const override;
  };

  // (type meta)
  class Abstract_meta : public virtual vx_core::Abstract_struct, public virtual vx_web_html::Abstract_node, public virtual vx_web_html::Abstract_headchild {
  public:
    Abstract_meta() {};
    virtual ~Abstract_meta() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // style()
    vx_web_html::Type_style vx_p_style = NULL;
    virtual vx_web_html::Type_style style() const = 0;
    // charset()
    vx_core::Type_string vx_p_charset = NULL;
    virtual vx_core::Type_string charset() const = 0;
  };
  class Class_meta : public virtual Abstract_meta {
  public:
    Class_meta();
    virtual ~Class_meta() override;
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
    virtual vx_core::Type_string id() const override;
    virtual vx_web_html::Type_style style() const override;
    virtual vx_core::Type_string charset() const override;
  };

  // (type nodelist)
  class Abstract_nodelist : public virtual vx_core::Abstract_list {
  public:
    Abstract_nodelist() {};
    virtual ~Abstract_nodelist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_web_html::Type_node> vx_p_list;
    // vx_listnode()
    virtual std::vector<vx_web_html::Type_node> vx_listnode() const = 0;
    // vx_get_node(index)
    virtual vx_web_html::Type_node vx_get_node(vx_core::Type_int index) const = 0;
  };
  class Class_nodelist : public virtual Abstract_nodelist {
  public:
    Class_nodelist();
    virtual ~Class_nodelist() override;
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
    virtual std::vector<vx_web_html::Type_node> vx_listnode() const override;
    virtual vx_web_html::Type_node vx_get_node(vx_core::Type_int index) const override;
  };

  // (type p)
  class Abstract_p : public virtual vx_core::Abstract_struct, public virtual vx_web_html::Abstract_node, public virtual vx_web_html::Abstract_divchild {
  public:
    Abstract_p() {};
    virtual ~Abstract_p() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // style()
    vx_web_html::Type_style vx_p_style = NULL;
    virtual vx_web_html::Type_style style() const = 0;
    // text()
    vx_core::Type_string vx_p_text = NULL;
    virtual vx_core::Type_string text() const = 0;
  };
  class Class_p : public virtual Abstract_p {
  public:
    Class_p();
    virtual ~Class_p() override;
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
    virtual vx_core::Type_string id() const override;
    virtual vx_web_html::Type_style style() const override;
    virtual vx_core::Type_string text() const override;
  };

  // (type propmap)
  class Abstract_propmap : public virtual vx_core::Abstract_map {
  public:
    Abstract_propmap() {};
    virtual ~Abstract_propmap() = 0;
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
  class Class_propmap : public virtual Abstract_propmap {
  public:
    Class_propmap();
    virtual ~Class_propmap() override;
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

  // (type style)
  class Abstract_style : public virtual vx_core::Abstract_struct {
  public:
    Abstract_style() {};
    virtual ~Abstract_style() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // props()
    vx_web_html::Type_propmap vx_p_props = NULL;
    virtual vx_web_html::Type_propmap props() const = 0;
  };
  class Class_style : public virtual Abstract_style {
  public:
    Class_style();
    virtual ~Class_style() override;
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
    virtual vx_core::Type_string name() const override;
    virtual vx_web_html::Type_propmap props() const override;
  };

  // (type stylelist)
  class Abstract_stylelist : public virtual vx_core::Abstract_list {
  public:
    Abstract_stylelist() {};
    virtual ~Abstract_stylelist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_web_html::Type_style> vx_p_list;
    // vx_liststyle()
    virtual std::vector<vx_web_html::Type_style> vx_liststyle() const = 0;
    // vx_get_style(index)
    virtual vx_web_html::Type_style vx_get_style(vx_core::Type_int index) const = 0;
  };
  class Class_stylelist : public virtual Abstract_stylelist {
  public:
    Class_stylelist();
    virtual ~Class_stylelist() override;
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
    virtual std::vector<vx_web_html::Type_style> vx_liststyle() const override;
    virtual vx_web_html::Type_style vx_get_style(vx_core::Type_int index) const override;
  };

  // (type stylemap)
  class Abstract_stylemap : public virtual vx_core::Abstract_map {
  public:
    Abstract_stylemap() {};
    virtual ~Abstract_stylemap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_web_html::Type_style> vx_p_map;
    // vx_mapstyle()
    virtual std::map<std::string, vx_web_html::Type_style> vx_mapstyle() const = 0;
    // vx_get_style(key)
    virtual vx_web_html::Type_style vx_get_style(vx_core::Type_string key) const = 0;
  };
  class Class_stylemap : public virtual Abstract_stylemap {
  public:
    Class_stylemap();
    virtual ~Class_stylemap() override;
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
    virtual std::map<std::string, vx_web_html::Type_style> vx_mapstyle() const override;
    virtual vx_web_html::Type_style vx_get_style(vx_core::Type_string key) const override;
  };

  // (type stylesheet)
  class Abstract_stylesheet : public virtual vx_core::Abstract_struct, public virtual vx_web_html::Abstract_node, public virtual vx_web_html::Abstract_headchild {
  public:
    Abstract_stylesheet() {};
    virtual ~Abstract_stylesheet() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // style()
    vx_web_html::Type_style vx_p_style = NULL;
    virtual vx_web_html::Type_style style() const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // styles()
    vx_web_html::Type_stylelist vx_p_styles = NULL;
    virtual vx_web_html::Type_stylelist styles() const = 0;
    // stylemap()
    vx_web_html::Type_stylemap vx_p_stylemap = NULL;
    virtual vx_web_html::Type_stylemap stylemap() const = 0;
  };
  class Class_stylesheet : public virtual Abstract_stylesheet {
  public:
    Class_stylesheet();
    virtual ~Class_stylesheet() override;
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
    virtual vx_core::Type_string id() const override;
    virtual vx_web_html::Type_style style() const override;
    virtual vx_core::Type_string name() const override;
    virtual vx_web_html::Type_stylelist styles() const override;
    virtual vx_web_html::Type_stylemap stylemap() const override;
  };

  // (type table)
  class Abstract_table : public virtual vx_core::Abstract_struct, public virtual vx_web_html::Abstract_node, public virtual vx_web_html::Abstract_divchild {
  public:
    Abstract_table() {};
    virtual ~Abstract_table() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // style()
    vx_web_html::Type_style vx_p_style = NULL;
    virtual vx_web_html::Type_style style() const = 0;
    // tbody()
    vx_web_html::Type_tbody vx_p_tbody = NULL;
    virtual vx_web_html::Type_tbody tbody() const = 0;
    // thead()
    vx_web_html::Type_thead vx_p_thead = NULL;
    virtual vx_web_html::Type_thead thead() const = 0;
  };
  class Class_table : public virtual Abstract_table {
  public:
    Class_table();
    virtual ~Class_table() override;
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
    virtual vx_core::Type_string id() const override;
    virtual vx_web_html::Type_style style() const override;
    virtual vx_web_html::Type_tbody tbody() const override;
    virtual vx_web_html::Type_thead thead() const override;
  };

  // (type tbody)
  class Abstract_tbody : public virtual vx_core::Abstract_struct, public virtual vx_web_html::Abstract_node {
  public:
    Abstract_tbody() {};
    virtual ~Abstract_tbody() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // style()
    vx_web_html::Type_style vx_p_style = NULL;
    virtual vx_web_html::Type_style style() const = 0;
    // nodes()
    vx_web_html::Type_trlist vx_p_nodes = NULL;
    virtual vx_web_html::Type_trlist nodes() const = 0;
  };
  class Class_tbody : public virtual Abstract_tbody {
  public:
    Class_tbody();
    virtual ~Class_tbody() override;
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
    virtual vx_core::Type_string id() const override;
    virtual vx_web_html::Type_style style() const override;
    virtual vx_web_html::Type_trlist nodes() const override;
  };

  // (type td)
  class Abstract_td : public virtual vx_core::Abstract_struct, public virtual vx_web_html::Abstract_node {
  public:
    Abstract_td() {};
    virtual ~Abstract_td() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // style()
    vx_web_html::Type_style vx_p_style = NULL;
    virtual vx_web_html::Type_style style() const = 0;
    // nodes()
    vx_web_html::Type_divchildlist vx_p_nodes = NULL;
    virtual vx_web_html::Type_divchildlist nodes() const = 0;
  };
  class Class_td : public virtual Abstract_td {
  public:
    Class_td();
    virtual ~Class_td() override;
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
    virtual vx_core::Type_string id() const override;
    virtual vx_web_html::Type_style style() const override;
    virtual vx_web_html::Type_divchildlist nodes() const override;
  };

  // (type tdlist)
  class Abstract_tdlist : public virtual vx_core::Abstract_list {
  public:
    Abstract_tdlist() {};
    virtual ~Abstract_tdlist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_web_html::Type_td> vx_p_list;
    // vx_listtd()
    virtual std::vector<vx_web_html::Type_td> vx_listtd() const = 0;
    // vx_get_td(index)
    virtual vx_web_html::Type_td vx_get_td(vx_core::Type_int index) const = 0;
  };
  class Class_tdlist : public virtual Abstract_tdlist {
  public:
    Class_tdlist();
    virtual ~Class_tdlist() override;
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
    virtual std::vector<vx_web_html::Type_td> vx_listtd() const override;
    virtual vx_web_html::Type_td vx_get_td(vx_core::Type_int index) const override;
  };

  // (type thead)
  class Abstract_thead : public virtual vx_core::Abstract_struct, public virtual vx_web_html::Abstract_node {
  public:
    Abstract_thead() {};
    virtual ~Abstract_thead() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // style()
    vx_web_html::Type_style vx_p_style = NULL;
    virtual vx_web_html::Type_style style() const = 0;
    // nodes()
    vx_web_html::Type_trlist vx_p_nodes = NULL;
    virtual vx_web_html::Type_trlist nodes() const = 0;
  };
  class Class_thead : public virtual Abstract_thead {
  public:
    Class_thead();
    virtual ~Class_thead() override;
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
    virtual vx_core::Type_string id() const override;
    virtual vx_web_html::Type_style style() const override;
    virtual vx_web_html::Type_trlist nodes() const override;
  };

  // (type title)
  class Abstract_title : public virtual vx_core::Abstract_struct, public virtual vx_web_html::Abstract_node, public virtual vx_web_html::Abstract_headchild {
  public:
    Abstract_title() {};
    virtual ~Abstract_title() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // style()
    vx_web_html::Type_style vx_p_style = NULL;
    virtual vx_web_html::Type_style style() const = 0;
    // text()
    vx_core::Type_string vx_p_text = NULL;
    virtual vx_core::Type_string text() const = 0;
  };
  class Class_title : public virtual Abstract_title {
  public:
    Class_title();
    virtual ~Class_title() override;
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
    virtual vx_core::Type_string id() const override;
    virtual vx_web_html::Type_style style() const override;
    virtual vx_core::Type_string text() const override;
  };

  // (type tr)
  class Abstract_tr : public virtual vx_core::Abstract_struct, public virtual vx_web_html::Abstract_node {
  public:
    Abstract_tr() {};
    virtual ~Abstract_tr() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // style()
    vx_web_html::Type_style vx_p_style = NULL;
    virtual vx_web_html::Type_style style() const = 0;
    // nodes()
    vx_web_html::Type_tdlist vx_p_nodes = NULL;
    virtual vx_web_html::Type_tdlist nodes() const = 0;
  };
  class Class_tr : public virtual Abstract_tr {
  public:
    Class_tr();
    virtual ~Class_tr() override;
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
    virtual vx_core::Type_string id() const override;
    virtual vx_web_html::Type_style style() const override;
    virtual vx_web_html::Type_tdlist nodes() const override;
  };

  // (type trlist)
  class Abstract_trlist : public virtual vx_core::Abstract_list {
  public:
    Abstract_trlist() {};
    virtual ~Abstract_trlist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_web_html::Type_tr> vx_p_list;
    // vx_listtr()
    virtual std::vector<vx_web_html::Type_tr> vx_listtr() const = 0;
    // vx_get_tr(index)
    virtual vx_web_html::Type_tr vx_get_tr(vx_core::Type_int index) const = 0;
  };
  class Class_trlist : public virtual Abstract_trlist {
  public:
    Class_trlist();
    virtual ~Class_trlist() override;
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
    virtual std::vector<vx_web_html::Type_tr> vx_listtr() const override;
    virtual vx_web_html::Type_tr vx_get_tr(vx_core::Type_int index) const override;
  };

  // (func htmlstring<-string)
  class Abstract_htmlstring_from_string : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_htmlstring_from_string() {};
    virtual ~Abstract_htmlstring_from_string() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_htmlstring_from_string : public virtual Abstract_htmlstring_from_string {
  public:
    Class_htmlstring_from_string();
    virtual ~Class_htmlstring_from_string() override;
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

  // (func string-indent)
  class Abstract_string_indent : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_indent() {};
    virtual ~Abstract_string_indent() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_indent : public virtual Abstract_string_indent {
  public:
    Class_string_indent();
    virtual ~Class_string_indent() override;
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

  // (func string<-body-indent)
  class Abstract_string_from_body_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_body_indent() {};
    virtual ~Abstract_string_from_body_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_body_indent : public virtual Abstract_string_from_body_indent {
  public:
    Class_string_from_body_indent();
    virtual ~Class_string_from_body_indent() override;
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

  // (func string<-details-indent)
  class Abstract_string_from_details_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_details_indent() {};
    virtual ~Abstract_string_from_details_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_details_indent : public virtual Abstract_string_from_details_indent {
  public:
    Class_string_from_details_indent();
    virtual ~Class_string_from_details_indent() override;
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

  // (func string<-div-indent)
  class Abstract_string_from_div_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_div_indent() {};
    virtual ~Abstract_string_from_div_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_div_indent : public virtual Abstract_string_from_div_indent {
  public:
    Class_string_from_div_indent();
    virtual ~Class_string_from_div_indent() override;
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

  // (func string<-footer-indent)
  class Abstract_string_from_footer_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_footer_indent() {};
    virtual ~Abstract_string_from_footer_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_footer_indent : public virtual Abstract_string_from_footer_indent {
  public:
    Class_string_from_footer_indent();
    virtual ~Class_string_from_footer_indent() override;
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

  // (func string<-h1-indent)
  class Abstract_string_from_h1_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_h1_indent() {};
    virtual ~Abstract_string_from_h1_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_h1_indent : public virtual Abstract_string_from_h1_indent {
  public:
    Class_string_from_h1_indent();
    virtual ~Class_string_from_h1_indent() override;
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

  // (func string<-h2-indent)
  class Abstract_string_from_h2_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_h2_indent() {};
    virtual ~Abstract_string_from_h2_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_h2_indent : public virtual Abstract_string_from_h2_indent {
  public:
    Class_string_from_h2_indent();
    virtual ~Class_string_from_h2_indent() override;
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

  // (func string<-h3-indent)
  class Abstract_string_from_h3_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_h3_indent() {};
    virtual ~Abstract_string_from_h3_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_h3_indent : public virtual Abstract_string_from_h3_indent {
  public:
    Class_string_from_h3_indent();
    virtual ~Class_string_from_h3_indent() override;
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

  // (func string<-head-indent)
  class Abstract_string_from_head_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_head_indent() {};
    virtual ~Abstract_string_from_head_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_head_indent : public virtual Abstract_string_from_head_indent {
  public:
    Class_string_from_head_indent();
    virtual ~Class_string_from_head_indent() override;
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

  // (func string<-html)
  class Abstract_string_from_html : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_html() {};
    virtual ~Abstract_string_from_html() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_html : public virtual Abstract_string_from_html {
  public:
    Class_string_from_html();
    virtual ~Class_string_from_html() override;
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

  // (func string<-indent)
  class Abstract_string_from_indent : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_indent() {};
    virtual ~Abstract_string_from_indent() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_indent : public virtual Abstract_string_from_indent {
  public:
    Class_string_from_indent();
    virtual ~Class_string_from_indent() override;
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

  // (func string<-meta-indent)
  class Abstract_string_from_meta_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_meta_indent() {};
    virtual ~Abstract_string_from_meta_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_meta_indent : public virtual Abstract_string_from_meta_indent {
  public:
    Class_string_from_meta_indent();
    virtual ~Class_string_from_meta_indent() override;
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

  // (func string<-node-indent)
  class Abstract_string_from_node_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_node_indent() {};
    virtual ~Abstract_string_from_node_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_node_indent : public virtual Abstract_string_from_node_indent {
  public:
    Class_string_from_node_indent();
    virtual ~Class_string_from_node_indent() override;
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

  // (func string<-nodelist-indent)
  class Abstract_string_from_nodelist_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_nodelist_indent() {};
    virtual ~Abstract_string_from_nodelist_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_nodelist_indent : public virtual Abstract_string_from_nodelist_indent {
  public:
    Class_string_from_nodelist_indent();
    virtual ~Class_string_from_nodelist_indent() override;
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

  // (func string<-nodelist-tag-prop-indent)
  class Abstract_string_from_nodelist_tag_prop_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_nodelist_tag_prop_indent() {};
    virtual ~Abstract_string_from_nodelist_tag_prop_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_nodelist_tag_prop_indent : public virtual Abstract_string_from_nodelist_tag_prop_indent {
  public:
    Class_string_from_nodelist_tag_prop_indent();
    virtual ~Class_string_from_nodelist_tag_prop_indent() override;
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

  // (func string<-p-indent)
  class Abstract_string_from_p_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_p_indent() {};
    virtual ~Abstract_string_from_p_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_p_indent : public virtual Abstract_string_from_p_indent {
  public:
    Class_string_from_p_indent();
    virtual ~Class_string_from_p_indent() override;
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

  // (func string<-propname-val)
  class Abstract_string_from_propname_val : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_propname_val() {};
    virtual ~Abstract_string_from_propname_val() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_propname_val : public virtual Abstract_string_from_propname_val {
  public:
    Class_string_from_propname_val();
    virtual ~Class_string_from_propname_val() override;
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

  // (func string<-propstyle)
  class Abstract_string_from_propstyle : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_propstyle() {};
    virtual ~Abstract_string_from_propstyle() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_propstyle : public virtual Abstract_string_from_propstyle {
  public:
    Class_string_from_propstyle();
    virtual ~Class_string_from_propstyle() override;
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

  // (func string<-style-indent)
  class Abstract_string_from_style_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_style_indent() {};
    virtual ~Abstract_string_from_style_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_style_indent : public virtual Abstract_string_from_style_indent {
  public:
    Class_string_from_style_indent();
    virtual ~Class_string_from_style_indent() override;
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

  // (func string<-stylelist-indent)
  class Abstract_string_from_stylelist_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_stylelist_indent() {};
    virtual ~Abstract_string_from_stylelist_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_stylelist_indent : public virtual Abstract_string_from_stylelist_indent {
  public:
    Class_string_from_stylelist_indent();
    virtual ~Class_string_from_stylelist_indent() override;
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

  // (func string<-stylepropmap-indent)
  class Abstract_string_from_stylepropmap_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_stylepropmap_indent() {};
    virtual ~Abstract_string_from_stylepropmap_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_stylepropmap_indent : public virtual Abstract_string_from_stylepropmap_indent {
  public:
    Class_string_from_stylepropmap_indent();
    virtual ~Class_string_from_stylepropmap_indent() override;
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

  // (func string<-stylesheet-indent)
  class Abstract_string_from_stylesheet_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_stylesheet_indent() {};
    virtual ~Abstract_string_from_stylesheet_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_stylesheet_indent : public virtual Abstract_string_from_stylesheet_indent {
  public:
    Class_string_from_stylesheet_indent();
    virtual ~Class_string_from_stylesheet_indent() override;
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

  // (func string<-table-indent)
  class Abstract_string_from_table_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_table_indent() {};
    virtual ~Abstract_string_from_table_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_table_indent : public virtual Abstract_string_from_table_indent {
  public:
    Class_string_from_table_indent();
    virtual ~Class_string_from_table_indent() override;
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

  // (func string<-tbody-indent)
  class Abstract_string_from_tbody_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_tbody_indent() {};
    virtual ~Abstract_string_from_tbody_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_tbody_indent : public virtual Abstract_string_from_tbody_indent {
  public:
    Class_string_from_tbody_indent();
    virtual ~Class_string_from_tbody_indent() override;
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

  // (func string<-td-indent)
  class Abstract_string_from_td_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_td_indent() {};
    virtual ~Abstract_string_from_td_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_td_indent : public virtual Abstract_string_from_td_indent {
  public:
    Class_string_from_td_indent();
    virtual ~Class_string_from_td_indent() override;
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

  // (func string<-thead-indent)
  class Abstract_string_from_thead_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_thead_indent() {};
    virtual ~Abstract_string_from_thead_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_thead_indent : public virtual Abstract_string_from_thead_indent {
  public:
    Class_string_from_thead_indent();
    virtual ~Class_string_from_thead_indent() override;
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

  // (func string<-title-indent)
  class Abstract_string_from_title_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_title_indent() {};
    virtual ~Abstract_string_from_title_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_title_indent : public virtual Abstract_string_from_title_indent {
  public:
    Class_string_from_title_indent();
    virtual ~Class_string_from_title_indent() override;
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

  // (func string<-tr-indent)
  class Abstract_string_from_tr_indent : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_tr_indent() {};
    virtual ~Abstract_string_from_tr_indent() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_tr_indent : public virtual Abstract_string_from_tr_indent {
  public:
    Class_string_from_tr_indent();
    virtual ~Class_string_from_tr_indent() override;
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

  // (func string<-uri)
  class Abstract_string_from_uri : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_string_from_uri() {};
    virtual ~Abstract_string_from_uri() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_string_from_uri : public virtual Abstract_string_from_uri {
  public:
    Class_string_from_uri();
    virtual ~Class_string_from_uri() override;
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

  // (func style<-stylesheet-name)
  class Abstract_style_from_stylesheet_name : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_style_from_stylesheet_name() {};
    virtual ~Abstract_style_from_stylesheet_name() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_style_from_stylesheet_name : public virtual Abstract_style_from_stylesheet_name {
  public:
    Class_style_from_stylesheet_name();
    virtual ~Class_style_from_stylesheet_name() override;
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

  // (func stylemap<-stylelist)
  class Abstract_stylemap_from_stylelist : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_stylemap_from_stylelist() {};
    virtual ~Abstract_stylemap_from_stylelist() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_stylemap_from_stylelist : public virtual Abstract_stylemap_from_stylelist {
  public:
    Class_stylemap_from_stylelist();
    virtual ~Class_stylemap_from_stylelist() override;
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

  // (func stylemap<-stylesheet)
  class Abstract_stylemap_from_stylesheet : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_stylemap_from_stylesheet() {};
    virtual ~Abstract_stylemap_from_stylesheet() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_stylemap_from_stylesheet : public virtual Abstract_stylemap_from_stylesheet {
  public:
    Class_stylemap_from_stylesheet();
    virtual ~Class_stylemap_from_stylesheet() override;
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

  // (func styles<-stylesheet)
  class Abstract_styles_from_stylesheet : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_styles_from_stylesheet() {};
    virtual ~Abstract_styles_from_stylesheet() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_styles_from_stylesheet : public virtual Abstract_styles_from_stylesheet {
  public:
    Class_styles_from_stylesheet();
    virtual ~Class_styles_from_stylesheet() override;
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

  // (func stylesheet-loadmap)
  class Abstract_stylesheet_loadmap : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_stylesheet_loadmap() {};
    virtual ~Abstract_stylesheet_loadmap() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_stylesheet_loadmap : public virtual Abstract_stylesheet_loadmap {
  public:
    Class_stylesheet_loadmap();
    virtual ~Class_stylesheet_loadmap() override;
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

  // (func uri<-string)
  class Abstract_uri_from_string : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_uri_from_string() {};
    virtual ~Abstract_uri_from_string() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_uri_from_string : public virtual Abstract_uri_from_string {
  public:
    Class_uri_from_string();
    virtual ~Class_uri_from_string() override;
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
