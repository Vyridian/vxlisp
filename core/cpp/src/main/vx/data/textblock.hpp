#ifndef VX_DATA_TEXTBLOCK_HPP
#define VX_DATA_TEXTBLOCK_HPP
#include <vector>
#include "../../vx/core.hpp"

namespace vx_data_textblock {

  // forward declarations
  class Abstract_delimset;
  typedef Abstract_delimset* Type_delimset;
  extern Type_delimset e_delimset();
  extern Type_delimset t_delimset();
  class Abstract_textblock;
  typedef Abstract_textblock* Type_textblock;
  extern Type_textblock e_textblock();
  extern Type_textblock t_textblock();
  class Abstract_textblocklist;
  typedef Abstract_textblocklist* Type_textblocklist;
  extern Type_textblocklist e_textblocklist();
  extern Type_textblocklist t_textblocklist();
  class Abstract_parse;
  typedef Abstract_parse* Func_parse;
  extern Func_parse e_parse();
  extern Func_parse t_parse();
  class Abstract_stringlist_from_textblocklist;
  typedef Abstract_stringlist_from_textblocklist* Func_stringlist_from_textblocklist;
  extern Func_stringlist_from_textblocklist e_stringlist_from_textblocklist();
  extern Func_stringlist_from_textblocklist t_stringlist_from_textblocklist();
  class Abstract_text_from_textblock;
  typedef Abstract_text_from_textblock* Func_text_from_textblock;
  extern Func_text_from_textblock e_text_from_textblock();
  extern Func_text_from_textblock t_text_from_textblock();
  class Abstract_textblocks_from_textblock;
  typedef Abstract_textblocks_from_textblock* Func_textblocks_from_textblock;
  extern Func_textblocks_from_textblock e_textblocks_from_textblock();
  extern Func_textblocks_from_textblock t_textblocks_from_textblock();

  class vx_Class_package {
  public:
    vx_data_textblock::Type_delimset e_delimset;
    vx_data_textblock::Type_delimset t_delimset;
    vx_data_textblock::Type_textblock e_textblock;
    vx_data_textblock::Type_textblock t_textblock;
    vx_data_textblock::Type_textblocklist e_textblocklist;
    vx_data_textblock::Type_textblocklist t_textblocklist;
    vx_data_textblock::Func_parse e_parse;
    vx_data_textblock::Func_parse t_parse;
    vx_data_textblock::Func_stringlist_from_textblocklist e_stringlist_from_textblocklist;
    vx_data_textblock::Func_stringlist_from_textblocklist t_stringlist_from_textblocklist;
    vx_data_textblock::Func_text_from_textblock e_text_from_textblock;
    vx_data_textblock::Func_text_from_textblock t_text_from_textblock;
    vx_data_textblock::Func_textblocks_from_textblock e_textblocks_from_textblock;
    vx_data_textblock::Func_textblocks_from_textblock t_textblocks_from_textblock;
  };


  // (func parse)
  vx_data_textblock::Type_textblock f_parse(vx_data_textblock::Type_textblock block, vx_data_textblock::Type_delimset delimpairlist);

  // (func stringlist<-textblocklist)
  vx_core::Type_stringlist f_stringlist_from_textblocklist(vx_data_textblock::Type_textblocklist textblocks);

  // (func text<-textblock)
  vx_core::Type_string f_text_from_textblock(vx_data_textblock::Type_textblock block);

  // (func textblocks<-textblock)
  vx_data_textblock::Type_textblocklist f_textblocks_from_textblock(vx_data_textblock::Type_textblock block);

  // (type delimset)
  class Abstract_delimset : public virtual vx_core::Abstract_struct {
  public:
    Abstract_delimset() {};
    virtual ~Abstract_delimset() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // start()
    vx_core::Type_stringlist vx_p_start = NULL;
    virtual vx_core::Type_stringlist start() const = 0;
    // end()
    vx_core::Type_stringlist vx_p_end = NULL;
    virtual vx_core::Type_stringlist end() const = 0;
    // split()
    vx_core::Type_stringlist vx_p_split = NULL;
    virtual vx_core::Type_stringlist split() const = 0;
    // subset()
    vx_data_textblock::Type_delimset vx_p_subset = NULL;
    virtual vx_data_textblock::Type_delimset subset() const = 0;
  };
  class Class_delimset : public virtual Abstract_delimset {
  public:
    Class_delimset();
    virtual ~Class_delimset() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_stringlist start() const override;
    virtual vx_core::Type_stringlist end() const override;
    virtual vx_core::Type_stringlist split() const override;
    virtual vx_data_textblock::Type_delimset subset() const override;
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
    // textblocks()
    vx_data_textblock::Type_textblocklist vx_p_textblocks = NULL;
    virtual vx_data_textblock::Type_textblocklist textblocks() const = 0;
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
    virtual vx_data_textblock::Type_textblocklist textblocks() const override;
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

  // (func parse)
  class Abstract_parse : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_parse() {};
    virtual ~Abstract_parse() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_parse : public virtual Abstract_parse {
  public:
    Class_parse();
    virtual ~Class_parse() override;
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

}
#endif
