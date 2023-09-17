#ifndef VX_DATA_TEXTBLOCK_HPP
#define VX_DATA_TEXTBLOCK_HPP
#include <vector>
#include "../../vx/core.hpp"
#include "../../vx/type.hpp"

namespace vx_data_textblock {

  // forward declarations
  class Abstract_delim;
  typedef Abstract_delim* Type_delim;
  extern Type_delim e_delim;
  extern Type_delim t_delim;
  class Abstract_delimlist;
  typedef Abstract_delimlist* Type_delimlist;
  extern Type_delimlist e_delimlist;
  extern Type_delimlist t_delimlist;
  class Abstract_textblock;
  typedef Abstract_textblock* Type_textblock;
  extern Type_textblock e_textblock;
  extern Type_textblock t_textblock;
  class Abstract_textblocklist;
  typedef Abstract_textblocklist* Type_textblocklist;
  extern Type_textblocklist e_textblocklist;
  extern Type_textblocklist t_textblocklist;
  class Class_delimbracketcurly;
  typedef Class_delimbracketcurly* Const_delimbracketcurly;
  extern Const_delimbracketcurly c_delimbracketcurly;
  class Class_delimbracketsquare;
  typedef Class_delimbracketsquare* Const_delimbracketsquare;
  extern Const_delimbracketsquare c_delimbracketsquare;
  class Class_delimclose;
  typedef Class_delimclose* Const_delimclose;
  extern Const_delimclose c_delimclose;
  class Class_delimcomma;
  typedef Class_delimcomma* Const_delimcomma;
  extern Const_delimcomma c_delimcomma;
  class Class_delimcomment;
  typedef Class_delimcomment* Const_delimcomment;
  extern Const_delimcomment c_delimcomment;
  class Class_delimcommentblock;
  typedef Class_delimcommentblock* Const_delimcommentblock;
  extern Const_delimcommentblock c_delimcommentblock;
  class Class_delimline;
  typedef Class_delimline* Const_delimline;
  extern Const_delimline c_delimline;
  class Class_delimnonwhitespace;
  typedef Class_delimnonwhitespace* Const_delimnonwhitespace;
  extern Const_delimnonwhitespace c_delimnonwhitespace;
  class Class_delimparen;
  typedef Class_delimparen* Const_delimparen;
  extern Const_delimparen c_delimparen;
  class Class_delimparenline;
  typedef Class_delimparenline* Const_delimparenline;
  extern Const_delimparenline c_delimparenline;
  class Class_delimquote;
  typedef Class_delimquote* Const_delimquote;
  extern Const_delimquote c_delimquote;
  class Class_delimquoteblock;
  typedef Class_delimquoteblock* Const_delimquoteblock;
  extern Const_delimquoteblock c_delimquoteblock;
  class Class_delimspace;
  typedef Class_delimspace* Const_delimspace;
  extern Const_delimspace c_delimspace;
  class Class_delimtext;
  typedef Class_delimtext* Const_delimtext;
  extern Const_delimtext c_delimtext;
  class Class_delimwhitespace;
  typedef Class_delimwhitespace* Const_delimwhitespace;
  extern Const_delimwhitespace c_delimwhitespace;
  class Abstract_delim_first_from_delim_delim;
  typedef Abstract_delim_first_from_delim_delim* Func_delim_first_from_delim_delim;
  extern Func_delim_first_from_delim_delim e_delim_first_from_delim_delim;
  extern Func_delim_first_from_delim_delim t_delim_first_from_delim_delim;
  class Abstract_delim_first_from_string_delimlist;
  typedef Abstract_delim_first_from_string_delimlist* Func_delim_first_from_string_delimlist;
  extern Func_delim_first_from_string_delimlist e_delim_first_from_string_delimlist;
  extern Func_delim_first_from_string_delimlist t_delim_first_from_string_delimlist;
  class Abstract_delim_startpos_from_string_delim;
  typedef Abstract_delim_startpos_from_string_delim* Func_delim_startpos_from_string_delim;
  extern Func_delim_startpos_from_string_delim e_delim_startpos_from_string_delim;
  extern Func_delim_startpos_from_string_delim t_delim_startpos_from_string_delim;
  class Abstract_delimlist_startpos_from_string_delimlist;
  typedef Abstract_delimlist_startpos_from_string_delimlist* Func_delimlist_startpos_from_string_delimlist;
  extern Func_delimlist_startpos_from_string_delimlist e_delimlist_startpos_from_string_delimlist;
  extern Func_delimlist_startpos_from_string_delimlist t_delimlist_startpos_from_string_delimlist;
  class Abstract_stringlist_from_textblocklist;
  typedef Abstract_stringlist_from_textblocklist* Func_stringlist_from_textblocklist;
  extern Func_stringlist_from_textblocklist e_stringlist_from_textblocklist;
  extern Func_stringlist_from_textblocklist t_stringlist_from_textblocklist;
  class Abstract_text_from_textblock;
  typedef Abstract_text_from_textblock* Func_text_from_textblock;
  extern Func_text_from_textblock e_text_from_textblock;
  extern Func_text_from_textblock t_text_from_textblock;
  class Abstract_textblock_firstdelim_from_textblock_delimlist;
  typedef Abstract_textblock_firstdelim_from_textblock_delimlist* Func_textblock_firstdelim_from_textblock_delimlist;
  extern Func_textblock_firstdelim_from_textblock_delimlist e_textblock_firstdelim_from_textblock_delimlist;
  extern Func_textblock_firstdelim_from_textblock_delimlist t_textblock_firstdelim_from_textblock_delimlist;
  class Abstract_textblock_startafter_from_string_delim;
  typedef Abstract_textblock_startafter_from_string_delim* Func_textblock_startafter_from_string_delim;
  extern Func_textblock_startafter_from_string_delim e_textblock_startafter_from_string_delim;
  extern Func_textblock_startafter_from_string_delim t_textblock_startafter_from_string_delim;
  class Abstract_textblock_startbefore_from_string_delim;
  typedef Abstract_textblock_startbefore_from_string_delim* Func_textblock_startbefore_from_string_delim;
  extern Func_textblock_startbefore_from_string_delim e_textblock_startbefore_from_string_delim;
  extern Func_textblock_startbefore_from_string_delim t_textblock_startbefore_from_string_delim;
  class Abstract_textblock_from_textblock_delim;
  typedef Abstract_textblock_from_textblock_delim* Func_textblock_from_textblock_delim;
  extern Func_textblock_from_textblock_delim e_textblock_from_textblock_delim;
  extern Func_textblock_from_textblock_delim t_textblock_from_textblock_delim;
  class Abstract_textblocks_from_textblock;
  typedef Abstract_textblocks_from_textblock* Func_textblocks_from_textblock;
  extern Func_textblocks_from_textblock e_textblocks_from_textblock;
  extern Func_textblocks_from_textblock t_textblocks_from_textblock;
  // (func delim-first<-delim-delim)
  vx_data_textblock::Type_delim f_delim_first_from_delim_delim(vx_data_textblock::Type_delim delim1, vx_data_textblock::Type_delim delim2);

  // (func delim-first<-string-delimlist)
  vx_data_textblock::Type_delim f_delim_first_from_string_delimlist(vx_core::Type_string text, vx_data_textblock::Type_delimlist delimlist);

  // (func delim-startpos<-string-delim)
  vx_data_textblock::Type_delim f_delim_startpos_from_string_delim(vx_core::Type_string text, vx_data_textblock::Type_delim delim);

  // (func delimlist-startpos<-string-delimlist)
  vx_data_textblock::Type_delimlist f_delimlist_startpos_from_string_delimlist(vx_core::Type_string text, vx_data_textblock::Type_delimlist delimlist);

  // (func stringlist<-textblocklist)
  vx_core::Type_stringlist f_stringlist_from_textblocklist(vx_data_textblock::Type_textblocklist textblocks);

  // (func text<-textblock)
  vx_core::Type_string f_text_from_textblock(vx_data_textblock::Type_textblock block);

  // (func textblock-firstdelim<-textblock-delimlist)
  vx_data_textblock::Type_textblock f_textblock_firstdelim_from_textblock_delimlist(vx_data_textblock::Type_textblock textblock, vx_data_textblock::Type_delimlist delimlist);

  // (func textblock-startafter<-string-delim)
  vx_data_textblock::Type_textblock f_textblock_startafter_from_string_delim(vx_core::Type_string text, vx_data_textblock::Type_delim delim);

  // (func textblock-startbefore<-string-delim)
  vx_data_textblock::Type_textblock f_textblock_startbefore_from_string_delim(vx_core::Type_string text, vx_data_textblock::Type_delim delim);

  // (func textblock<-textblock-delim)
  vx_data_textblock::Type_textblock f_textblock_from_textblock_delim(vx_data_textblock::Type_textblock textblock, vx_data_textblock::Type_delim delim);

  // (func textblocks<-textblock)
  vx_data_textblock::Type_textblocklist f_textblocks_from_textblock(vx_data_textblock::Type_textblock block);

  // (type delim)
  class Abstract_delim : public virtual vx_core::Abstract_struct {
  public:
    Abstract_delim() {};
    virtual ~Abstract_delim() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // starttext()
    vx_core::Type_string vx_p_starttext = NULL;
    virtual vx_core::Type_string starttext() const = 0;
    // endtext()
    vx_core::Type_string vx_p_endtext = NULL;
    virtual vx_core::Type_string endtext() const = 0;
    // startpos()
    vx_core::Type_int vx_p_startpos = NULL;
    virtual vx_core::Type_int startpos() const = 0;
    // endpos()
    vx_core::Type_int vx_p_endpos = NULL;
    virtual vx_core::Type_int endpos() const = 0;
    // delimlist()
    vx_data_textblock::Type_delimlist vx_p_delimlist = NULL;
    virtual vx_data_textblock::Type_delimlist delimlist() const = 0;
  };
  class Class_delim : public virtual Abstract_delim {
  public:
    Class_delim();
    virtual ~Class_delim() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string name() const override;
    virtual vx_core::Type_string starttext() const override;
    virtual vx_core::Type_string endtext() const override;
    virtual vx_core::Type_int startpos() const override;
    virtual vx_core::Type_int endpos() const override;
    virtual vx_data_textblock::Type_delimlist delimlist() const override;
  };

  // (type delimlist)
  class Abstract_delimlist : public virtual vx_core::Abstract_list {
  public:
    Abstract_delimlist() {};
    virtual ~Abstract_delimlist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_data_textblock::Type_delim> vx_p_list;
    // vx_listdelim()
    virtual std::vector<vx_data_textblock::Type_delim> vx_listdelim() const = 0;
    // vx_get_delim(index)
    virtual vx_data_textblock::Type_delim vx_get_delim(vx_core::Type_int index) const = 0;
  };
  class Class_delimlist : public virtual Abstract_delimlist {
  public:
    Class_delimlist();
    virtual ~Class_delimlist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_data_textblock::Type_delim> vx_listdelim() const override;
    virtual vx_data_textblock::Type_delim vx_get_delim(vx_core::Type_int index) const override;
  };

  // (type textblock)
  class Abstract_textblock : public virtual vx_core::Abstract_struct {
  public:
    Abstract_textblock() {};
    virtual ~Abstract_textblock() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // text()
    vx_core::Type_string vx_p_text = NULL;
    virtual vx_core::Type_string text() const = 0;
    // line()
    vx_core::Type_int vx_p_line = NULL;
    virtual vx_core::Type_int line() const = 0;
    // column()
    vx_core::Type_int vx_p_column = NULL;
    virtual vx_core::Type_int column() const = 0;
    // delim()
    vx_data_textblock::Type_delim vx_p_delim = NULL;
    virtual vx_data_textblock::Type_delim delim() const = 0;
    // textblocks()
    vx_data_textblock::Type_textblocklist vx_p_textblocks = NULL;
    virtual vx_data_textblock::Type_textblocklist textblocks() const = 0;
    // parent()
    vx_data_textblock::Type_textblock vx_p_parent = NULL;
    virtual vx_data_textblock::Type_textblock parent() const = 0;
  };
  class Class_textblock : public virtual Abstract_textblock {
  public:
    Class_textblock();
    virtual ~Class_textblock() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string name() const override;
    virtual vx_core::Type_string text() const override;
    virtual vx_core::Type_int line() const override;
    virtual vx_core::Type_int column() const override;
    virtual vx_data_textblock::Type_delim delim() const override;
    virtual vx_data_textblock::Type_textblocklist textblocks() const override;
    virtual vx_data_textblock::Type_textblock parent() const override;
  };

  // (type textblocklist)
  class Abstract_textblocklist : public virtual vx_core::Abstract_list {
  public:
    Abstract_textblocklist() {};
    virtual ~Abstract_textblocklist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_data_textblock::Type_textblock> vx_p_list;
    // vx_listtextblock()
    virtual std::vector<vx_data_textblock::Type_textblock> vx_listtextblock() const = 0;
    // vx_get_textblock(index)
    virtual vx_data_textblock::Type_textblock vx_get_textblock(vx_core::Type_int index) const = 0;
  };
  class Class_textblocklist : public virtual Abstract_textblocklist {
  public:
    Class_textblocklist();
    virtual ~Class_textblocklist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const override;
    virtual vx_core::vx_Type_listany vx_list() const override;
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const override;
    virtual std::vector<vx_data_textblock::Type_textblock> vx_listtextblock() const override;
    virtual vx_data_textblock::Type_textblock vx_get_textblock(vx_core::Type_int index) const override;
  };

  // (const delimbracketcurly)
  class Class_delimbracketcurly : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_data_textblock::Const_delimbracketcurly output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (const delimbracketsquare)
  class Class_delimbracketsquare : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_data_textblock::Const_delimbracketsquare output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (const delimclose)
  class Class_delimclose : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_data_textblock::Const_delimclose output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (const delimcomma)
  class Class_delimcomma : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_data_textblock::Const_delimcomma output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (const delimcomment)
  class Class_delimcomment : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_data_textblock::Const_delimcomment output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (const delimcommentblock)
  class Class_delimcommentblock : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_data_textblock::Const_delimcommentblock output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (const delimline)
  class Class_delimline : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_data_textblock::Const_delimline output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (const delimnonwhitespace)
  class Class_delimnonwhitespace : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_data_textblock::Const_delimnonwhitespace output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (const delimparen)
  class Class_delimparen : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_data_textblock::Const_delimparen output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (const delimparenline)
  class Class_delimparenline : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_data_textblock::Const_delimparenline output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (const delimquote)
  class Class_delimquote : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_data_textblock::Const_delimquote output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (const delimquoteblock)
  class Class_delimquoteblock : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_data_textblock::Const_delimquoteblock output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (const delimspace)
  class Class_delimspace : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_data_textblock::Const_delimspace output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (const delimtext)
  class Class_delimtext : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_data_textblock::Const_delimtext output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (const delimwhitespace)
  class Class_delimwhitespace : public vx_data_textblock::Class_delim {
  public:
    static void vx_const_new(vx_data_textblock::Const_delimwhitespace output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (func delim-first<-delim-delim)
  class Abstract_delim_first_from_delim_delim : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_delim_first_from_delim_delim() {};
    virtual ~Abstract_delim_first_from_delim_delim() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_delim_first_from_delim_delim : public virtual Abstract_delim_first_from_delim_delim {
  public:
    Class_delim_first_from_delim_delim();
    virtual ~Class_delim_first_from_delim_delim() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func delim-first<-string-delimlist)
  class Abstract_delim_first_from_string_delimlist : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_delim_first_from_string_delimlist() {};
    virtual ~Abstract_delim_first_from_string_delimlist() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_delim_first_from_string_delimlist : public virtual Abstract_delim_first_from_string_delimlist {
  public:
    Class_delim_first_from_string_delimlist();
    virtual ~Class_delim_first_from_string_delimlist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func delim-startpos<-string-delim)
  class Abstract_delim_startpos_from_string_delim : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_delim_startpos_from_string_delim() {};
    virtual ~Abstract_delim_startpos_from_string_delim() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_delim_startpos_from_string_delim : public virtual Abstract_delim_startpos_from_string_delim {
  public:
    Class_delim_startpos_from_string_delim();
    virtual ~Class_delim_startpos_from_string_delim() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func delimlist-startpos<-string-delimlist)
  class Abstract_delimlist_startpos_from_string_delimlist : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_delimlist_startpos_from_string_delimlist() {};
    virtual ~Abstract_delimlist_startpos_from_string_delimlist() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_delimlist_startpos_from_string_delimlist : public virtual Abstract_delimlist_startpos_from_string_delimlist {
  public:
    Class_delimlist_startpos_from_string_delimlist();
    virtual ~Class_delimlist_startpos_from_string_delimlist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func stringlist<-textblocklist)
  class Abstract_stringlist_from_textblocklist : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_stringlist_from_textblocklist() {};
    virtual ~Abstract_stringlist_from_textblocklist() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_stringlist_from_textblocklist : public virtual Abstract_stringlist_from_textblocklist {
  public:
    Class_stringlist_from_textblocklist();
    virtual ~Class_stringlist_from_textblocklist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func text<-textblock)
  class Abstract_text_from_textblock : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_text_from_textblock() {};
    virtual ~Abstract_text_from_textblock() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_text_from_textblock : public virtual Abstract_text_from_textblock {
  public:
    Class_text_from_textblock();
    virtual ~Class_text_from_textblock() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func textblock-firstdelim<-textblock-delimlist)
  class Abstract_textblock_firstdelim_from_textblock_delimlist : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_textblock_firstdelim_from_textblock_delimlist() {};
    virtual ~Abstract_textblock_firstdelim_from_textblock_delimlist() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_textblock_firstdelim_from_textblock_delimlist : public virtual Abstract_textblock_firstdelim_from_textblock_delimlist {
  public:
    Class_textblock_firstdelim_from_textblock_delimlist();
    virtual ~Class_textblock_firstdelim_from_textblock_delimlist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func textblock-startafter<-string-delim)
  class Abstract_textblock_startafter_from_string_delim : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_textblock_startafter_from_string_delim() {};
    virtual ~Abstract_textblock_startafter_from_string_delim() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_textblock_startafter_from_string_delim : public virtual Abstract_textblock_startafter_from_string_delim {
  public:
    Class_textblock_startafter_from_string_delim();
    virtual ~Class_textblock_startafter_from_string_delim() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func textblock-startbefore<-string-delim)
  class Abstract_textblock_startbefore_from_string_delim : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_textblock_startbefore_from_string_delim() {};
    virtual ~Abstract_textblock_startbefore_from_string_delim() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_textblock_startbefore_from_string_delim : public virtual Abstract_textblock_startbefore_from_string_delim {
  public:
    Class_textblock_startbefore_from_string_delim();
    virtual ~Class_textblock_startbefore_from_string_delim() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func textblock<-textblock-delim)
  class Abstract_textblock_from_textblock_delim : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_textblock_from_textblock_delim() {};
    virtual ~Abstract_textblock_from_textblock_delim() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_textblock_from_textblock_delim : public virtual Abstract_textblock_from_textblock_delim {
  public:
    Class_textblock_from_textblock_delim();
    virtual ~Class_textblock_from_textblock_delim() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func textblocks<-textblock)
  class Abstract_textblocks_from_textblock : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_textblocks_from_textblock() {};
    virtual ~Abstract_textblocks_from_textblock() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_textblocks_from_textblock : public virtual Abstract_textblocks_from_textblock {
  public:
    Class_textblocks_from_textblock();
    virtual ~Class_textblocks_from_textblock() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  class vx_Class_package : vx_core::vx_Abstract_package {
  public:
    vx_Class_package();
    void init();
    vx_core::vx_Type_mapany maptype();
    vx_core::vx_Type_mapany mapconst();
    vx_core::vx_Type_mapfunc mapfunc();
  };
  inline vx_Class_package const vx_package;

}
#endif
