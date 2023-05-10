#pragma once
#include <any>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "../../vx/core.hpp"

namespace vx_data_textblock {

  // forward declarations
  class Type_delimset;
  extern Type_delimset* e_delimset;
  extern Type_delimset* t_delimset;
  class Type_textblock;
  extern Type_textblock* e_textblock;
  extern Type_textblock* t_textblock;
  class Type_textblocklist;
  extern Type_textblocklist* e_textblocklist;
  extern Type_textblocklist* t_textblocklist;
  class Func_parse;
  extern Func_parse* e_parse;
  extern Func_parse* t_parse;
  class Func_stringlist_from_textblocklist;
  extern Func_stringlist_from_textblocklist* e_stringlist_from_textblocklist;
  extern Func_stringlist_from_textblocklist* t_stringlist_from_textblocklist;
  class Func_text_from_textblock;
  extern Func_text_from_textblock* e_text_from_textblock;
  extern Func_text_from_textblock* t_text_from_textblock;
  class Func_textblocks_from_textblock;
  extern Func_textblocks_from_textblock* e_textblocks_from_textblock;
  extern Func_textblocks_from_textblock* t_textblocks_from_textblock;


  // (type delimset)
  class Type_delimset : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_data_textblock::Type_delimset* vx_new(Args*... args);
    template<class... Args> vx_data_textblock::Type_delimset* vx_copy(Args*... args);
    virtual vx_data_textblock::Type_delimset* vx_empty();
    virtual vx_data_textblock::Type_delimset* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // start()
    vx_core::Type_stringlist* vx_p_start;
    virtual vx_core::Type_stringlist* start();
    // end()
    vx_core::Type_stringlist* vx_p_end;
    virtual vx_core::Type_stringlist* end();
    // split()
    vx_core::Type_stringlist* vx_p_split;
    virtual vx_core::Type_stringlist* split();
    // subset()
    vx_data_textblock::Type_delimset* vx_p_subset;
    virtual vx_data_textblock::Type_delimset* subset();
  };

  // (type textblock)
  class Type_textblock : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_data_textblock::Type_textblock* vx_new(Args*... args);
    template<class... Args> vx_data_textblock::Type_textblock* vx_copy(Args*... args);
    virtual vx_data_textblock::Type_textblock* vx_empty();
    virtual vx_data_textblock::Type_textblock* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // name()
    vx_core::Type_string* vx_p_name;
    virtual vx_core::Type_string* name();
    // text()
    vx_core::Type_string* vx_p_text;
    virtual vx_core::Type_string* text();
    // line()
    vx_core::Type_int* vx_p_line;
    virtual vx_core::Type_int* line();
    // column()
    vx_core::Type_int* vx_p_column;
    virtual vx_core::Type_int* column();
    // textblocks()
    vx_data_textblock::Type_textblocklist* vx_p_textblocks;
    virtual vx_data_textblock::Type_textblocklist* textblocks();
  };

  // (type textblocklist)
  class Type_textblocklist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_data_textblock::Type_textblocklist* vx_new(Args*... args);
    template<class... Args> vx_data_textblock::Type_textblocklist* vx_copy(Args*... args);
    virtual vx_data_textblock::Type_textblocklist* vx_empty();
    virtual vx_data_textblock::Type_textblocklist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_data_textblock::Type_textblock*> vx_p_list;

    // vx_listtextblock()
    virtual std::vector<vx_data_textblock::Type_textblock*> vx_listtextblock();
    // vx_textblock(index)
    virtual vx_data_textblock::Type_textblock* vx_textblock(vx_core::Type_int* index);
  };

  // (func parse)
  class Func_parse : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_data_textblock::Func_parse* vx_new(Args*... args);
    template<class... Args> vx_data_textblock::Func_parse* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_data_textblock::Func_parse* vx_empty();
    virtual vx_data_textblock::Func_parse* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_data_textblock::Type_textblock* vx_parse(vx_data_textblock::Type_textblock* block, vx_data_textblock::Type_delimset* delimpairlist);
  };

  // (func stringlist<-textblocklist)
  class Func_stringlist_from_textblocklist : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_data_textblock::Func_stringlist_from_textblocklist* vx_new(Args*... args);
    template<class... Args> vx_data_textblock::Func_stringlist_from_textblocklist* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_data_textblock::Func_stringlist_from_textblocklist* vx_empty();
    virtual vx_data_textblock::Func_stringlist_from_textblocklist* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_stringlist* vx_stringlist_from_textblocklist(vx_data_textblock::Type_textblocklist* textblocks);
  };

  // (func text<-textblock)
  class Func_text_from_textblock : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_data_textblock::Func_text_from_textblock* vx_new(Args*... args);
    template<class... Args> vx_data_textblock::Func_text_from_textblock* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_data_textblock::Func_text_from_textblock* vx_empty();
    virtual vx_data_textblock::Func_text_from_textblock* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Type_string* vx_text_from_textblock(vx_data_textblock::Type_textblock* block);
  };

  // (func textblocks<-textblock)
  class Func_textblocks_from_textblock : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<class... Args> vx_data_textblock::Func_textblocks_from_textblock* vx_new(Args*... args);
    template<class... Args> vx_data_textblock::Func_textblocks_from_textblock* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_data_textblock::Func_textblocks_from_textblock* vx_empty();
    virtual vx_data_textblock::Func_textblocks_from_textblock* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_data_textblock::Type_textblocklist* vx_textblocks_from_textblock(vx_data_textblock::Type_textblock* block);
  };

  // (func parse)
  vx_data_textblock::Type_textblock* f_parse(vx_data_textblock::Type_textblock* block, vx_data_textblock::Type_delimset* delimpairlist);

  // (func stringlist<-textblocklist)
  vx_core::Type_stringlist* f_stringlist_from_textblocklist(vx_data_textblock::Type_textblocklist* textblocks);

  // (func text<-textblock)
  vx_core::Type_string* f_text_from_textblock(vx_data_textblock::Type_textblock* block);

  // (func textblocks<-textblock)
  vx_data_textblock::Type_textblocklist* f_textblocks_from_textblock(vx_data_textblock::Type_textblock* block);

}
