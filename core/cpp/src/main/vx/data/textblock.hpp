#pragma once
#include <memory>
#include <set>
#include <string>
#include <vector>
#include "../../vx/core.hpp"

namespace vx_data_textblock {

  // forward declarations
  class Class_delimset;
  typedef std::shared_ptr<Class_delimset> Type_delimset;
  extern Type_delimset e_delimset;
  extern Type_delimset t_delimset;
  class Class_textblock;
  typedef std::shared_ptr<Class_textblock> Type_textblock;
  extern Type_textblock e_textblock;
  extern Type_textblock t_textblock;
  class Class_textblocklist;
  typedef std::shared_ptr<Class_textblocklist> Type_textblocklist;
  extern Type_textblocklist e_textblocklist;
  extern Type_textblocklist t_textblocklist;
  class Class_parse;
  typedef std::shared_ptr<Class_parse> Func_parse;
  extern Func_parse e_parse;
  extern Func_parse t_parse;
  class Class_stringlist_from_textblocklist;
  typedef std::shared_ptr<Class_stringlist_from_textblocklist> Func_stringlist_from_textblocklist;
  extern Func_stringlist_from_textblocklist e_stringlist_from_textblocklist;
  extern Func_stringlist_from_textblocklist t_stringlist_from_textblocklist;
  class Class_text_from_textblock;
  typedef std::shared_ptr<Class_text_from_textblock> Func_text_from_textblock;
  extern Func_text_from_textblock e_text_from_textblock;
  extern Func_text_from_textblock t_text_from_textblock;
  class Class_textblocks_from_textblock;
  typedef std::shared_ptr<Class_textblocks_from_textblock> Func_textblocks_from_textblock;
  extern Func_textblocks_from_textblock e_textblocks_from_textblock;
  extern Func_textblocks_from_textblock t_textblocks_from_textblock;


  // (type delimset)
  class Class_delimset : public virtual vx_core::Class_struct {
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
    // start()
    vx_core::Type_stringlist vx_p_start;
    virtual vx_core::Type_stringlist start();
    // end()
    vx_core::Type_stringlist vx_p_end;
    virtual vx_core::Type_stringlist end();
    // split()
    vx_core::Type_stringlist vx_p_split;
    virtual vx_core::Type_stringlist split();
    // subset()
    vx_data_textblock::Type_delimset vx_p_subset;
    virtual vx_data_textblock::Type_delimset subset();
  };

  // (type textblock)
  class Class_textblock : public virtual vx_core::Class_struct {
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
    // text()
    vx_core::Type_string vx_p_text;
    virtual vx_core::Type_string text();
    // line()
    vx_core::Type_int vx_p_line;
    virtual vx_core::Type_int line();
    // column()
    vx_core::Type_int vx_p_column;
    virtual vx_core::Type_int column();
    // textblocks()
    vx_data_textblock::Type_textblocklist vx_p_textblocks;
    virtual vx_data_textblock::Type_textblocklist textblocks();
  };

  // (type textblocklist)
  class Class_textblocklist : public virtual vx_core::Class_list {
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
    std::vector<vx_data_textblock::Type_textblock> vx_p_list;

    // vx_listtextblock()
    virtual std::vector<vx_data_textblock::Type_textblock> vx_listtextblock();
    // vx_textblock(index)
    virtual vx_data_textblock::Type_textblock vx_textblock(vx_core::Type_int index);
  };

  // (func parse)
  class Class_parse : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_data_textblock::Type_textblock vx_parse(vx_data_textblock::Type_textblock block, vx_data_textblock::Type_delimset delimpairlist);
  };

  // (func stringlist<-textblocklist)
  class Class_stringlist_from_textblocklist : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_stringlist vx_stringlist_from_textblocklist(vx_data_textblock::Type_textblocklist textblocks);
  };

  // (func text<-textblock)
  class Class_text_from_textblock : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_core::Type_string vx_text_from_textblock(vx_data_textblock::Type_textblock block);
  };

  // (func textblocks<-textblock)
  class Class_textblocks_from_textblock : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
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
    vx_data_textblock::Type_textblocklist vx_textblocks_from_textblock(vx_data_textblock::Type_textblock block);
  };

  // (func parse)
  vx_data_textblock::Type_textblock f_parse(vx_data_textblock::Type_textblock block, vx_data_textblock::Type_delimset delimpairlist);

  // (func stringlist<-textblocklist)
  vx_core::Type_stringlist f_stringlist_from_textblocklist(vx_data_textblock::Type_textblocklist textblocks);

  // (func text<-textblock)
  vx_core::Type_string f_text_from_textblock(vx_data_textblock::Type_textblock block);

  // (func textblocks<-textblock)
  vx_data_textblock::Type_textblocklist f_textblocks_from_textblock(vx_data_textblock::Type_textblock block);

}
