#ifndef VX_COLLECTION_HPP
#define VX_COLLECTION_HPP
#include "../vx/core.hpp"
#include "../vx/type.hpp"

namespace vx_collection {


  // forward declarations
  class Abstract_any_from_for_until_loop;
  typedef Abstract_any_from_for_until_loop* Func_any_from_for_until_loop;
  extern Func_any_from_for_until_loop e_any_from_for_until_loop;
  extern Func_any_from_for_until_loop t_any_from_for_until_loop;
  class Abstract_any_from_for_until_loop_max;
  typedef Abstract_any_from_for_until_loop_max* Func_any_from_for_until_loop_max;
  extern Func_any_from_for_until_loop_max e_any_from_for_until_loop_max;
  extern Func_any_from_for_until_loop_max t_any_from_for_until_loop_max;
  class Abstract_any_from_for_while_loop;
  typedef Abstract_any_from_for_while_loop* Func_any_from_for_while_loop;
  extern Func_any_from_for_while_loop e_any_from_for_while_loop;
  extern Func_any_from_for_while_loop t_any_from_for_while_loop;
  class Abstract_any_from_for_while_loop_max;
  typedef Abstract_any_from_for_while_loop_max* Func_any_from_for_while_loop_max;
  extern Func_any_from_for_while_loop_max e_any_from_for_while_loop_max;
  extern Func_any_from_for_while_loop_max t_any_from_for_while_loop_max;
  class Abstract_is_list;
  typedef Abstract_is_list* Func_is_list;
  extern Func_is_list e_is_list;
  extern Func_is_list t_is_list;
  class Abstract_is_map;
  typedef Abstract_is_map* Func_is_map;
  extern Func_is_map e_is_map;
  extern Func_is_map t_is_map;
  class Abstract_list_from_for_end_loop;
  typedef Abstract_list_from_for_end_loop* Func_list_from_for_end_loop;
  extern Func_list_from_for_end_loop e_list_from_for_end_loop;
  extern Func_list_from_for_end_loop t_list_from_for_end_loop;
  class Abstract_list_from_for_while_loop;
  typedef Abstract_list_from_for_while_loop* Func_list_from_for_while_loop;
  extern Func_list_from_for_while_loop e_list_from_for_while_loop;
  extern Func_list_from_for_while_loop t_list_from_for_while_loop;
  class Abstract_list_from_for_while_loop_max;
  typedef Abstract_list_from_for_while_loop_max* Func_list_from_for_while_loop_max;
  extern Func_list_from_for_while_loop_max e_list_from_for_while_loop_max;
  extern Func_list_from_for_while_loop_max t_list_from_for_while_loop_max;
  class Abstract_list_from_list_end;
  typedef Abstract_list_from_list_end* Func_list_from_list_end;
  extern Func_list_from_list_end e_list_from_list_end;
  extern Func_list_from_list_end t_list_from_list_end;
  class Abstract_list_from_list_filter;
  typedef Abstract_list_from_list_filter* Func_list_from_list_filter;
  extern Func_list_from_list_filter e_list_from_list_filter;
  extern Func_list_from_list_filter t_list_from_list_filter;
  class Abstract_list_from_list_filtertypes;
  typedef Abstract_list_from_list_filtertypes* Func_list_from_list_filtertypes;
  extern Func_list_from_list_filtertypes e_list_from_list_filtertypes;
  extern Func_list_from_list_filtertypes t_list_from_list_filtertypes;
  class Abstract_list_from_list_start;
  typedef Abstract_list_from_list_start* Func_list_from_list_start;
  extern Func_list_from_list_start e_list_from_list_start;
  extern Func_list_from_list_start t_list_from_list_start;
  class Abstract_list_from_list_start_end;
  typedef Abstract_list_from_list_start_end* Func_list_from_list_start_end;
  extern Func_list_from_list_start_end e_list_from_list_start_end;
  extern Func_list_from_list_start_end t_list_from_list_start_end;// :headerfirst
// :header

  // vx_any_from_for_until_loop_max(generic_any_1, start, fn-until, fn-loop, max)
  vx_core::Type_any vx_any_from_for_until_loop_max(vx_core::Type_any generic_any_1, vx_core::Type_any start, vx_core::Func_boolean_from_any fn_until, vx_core::Func_any_from_any fn_loop, vx_core::Type_int max);

  // vx_any_from_for_while_loop_max(generic_any_1, start, fn-while, fn-loop, max)
  vx_core::Type_any vx_any_from_for_while_loop_max(vx_core::Type_any generic_any_1, vx_core::Type_any start, vx_core::Func_boolean_from_any fn_while, vx_core::Func_any_from_any fn_loop, vx_core::Type_int max);

  // vx_list_from_for_end_loop(generic_list_1, start, end, fn-loop)
  vx_core::Type_any vx_list_from_for_end_loop(vx_core::Type_any generic_list_1, vx_core::Type_int start, vx_core::Type_int end, vx_core::Func_any_from_int fn_loop);

  // vx_list_from_for_while_loop_max(generic_list_1, start, fn-while, fn-loop, max)
  vx_core::Type_any vx_list_from_for_while_loop_max(vx_core::Type_any generic_list_1, vx_core::Type_any start, vx_core::Func_boolean_from_any fn_while, vx_core::Func_any_from_any fn_loop, vx_core::Type_int max);

  // vx_list_from_list_filter(generic_list_1, list, fn-any<-any)
  vx_core::Type_any vx_list_from_list_filter(vx_core::Type_any generic_list_1, vx_core::Type_list vallist, vx_core::Func_any_from_any fn_filter);

  // vx_list_from_list_start_end(generic_list_1, list, int, int)
  vx_core::Type_any vx_list_from_list_start_end(vx_core::Type_any generic_list_1, vx_core::Type_list values, vx_core::Type_int start, vx_core::Type_int end);


  // (func any<-for-until-loop-max)
  class Abstract_any_from_for_until_loop_max : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_for_until_loop_max() {};
    virtual ~Abstract_any_from_for_until_loop_max() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_for_until_loop_max : public virtual Abstract_any_from_for_until_loop_max {
  public:
    Class_any_from_for_until_loop_max();
    virtual ~Class_any_from_for_until_loop_max() override;
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

  // (func any<-for-until-loop)
  class Abstract_any_from_for_until_loop : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_for_until_loop() {};
    virtual ~Abstract_any_from_for_until_loop() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_for_until_loop : public virtual Abstract_any_from_for_until_loop {
  public:
    Class_any_from_for_until_loop();
    virtual ~Class_any_from_for_until_loop() override;
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

  // (func any<-for-while-loop-max)
  class Abstract_any_from_for_while_loop_max : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_for_while_loop_max() {};
    virtual ~Abstract_any_from_for_while_loop_max() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_for_while_loop_max : public virtual Abstract_any_from_for_while_loop_max {
  public:
    Class_any_from_for_while_loop_max();
    virtual ~Class_any_from_for_while_loop_max() override;
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

  // (func any<-for-while-loop)
  class Abstract_any_from_for_while_loop : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_for_while_loop() {};
    virtual ~Abstract_any_from_for_while_loop() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_for_while_loop : public virtual Abstract_any_from_for_while_loop {
  public:
    Class_any_from_for_while_loop();
    virtual ~Class_any_from_for_while_loop() override;
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

  // (func list<-for-while-loop-max)
  class Abstract_list_from_for_while_loop_max : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_list_from_for_while_loop_max() {};
    virtual ~Abstract_list_from_for_while_loop_max() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_list_from_for_while_loop_max : public virtual Abstract_list_from_for_while_loop_max {
  public:
    Class_list_from_for_while_loop_max();
    virtual ~Class_list_from_for_while_loop_max() override;
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

  // (func list<-for-while-loop)
  class Abstract_list_from_for_while_loop : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_list_from_for_while_loop() {};
    virtual ~Abstract_list_from_for_while_loop() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_list_from_for_while_loop : public virtual Abstract_list_from_for_while_loop {
  public:
    Class_list_from_for_while_loop();
    virtual ~Class_list_from_for_while_loop() override;
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

  // (func list<-list-filter)
  class Abstract_list_from_list_filter : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_list_from_list_filter() {};
    virtual ~Abstract_list_from_list_filter() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_list_from_list_filter : public virtual Abstract_list_from_list_filter {
  public:
    Class_list_from_list_filter();
    virtual ~Class_list_from_list_filter() override;
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

  // (func list<-list-start-end)
  class Abstract_list_from_list_start_end : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_list_from_list_start_end() {};
    virtual ~Abstract_list_from_list_start_end() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_list_from_list_start_end : public virtual Abstract_list_from_list_start_end {
  public:
    Class_list_from_list_start_end();
    virtual ~Class_list_from_list_start_end() override;
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

  // (func is-list)
  vx_core::Type_boolean f_is_list(vx_core::Type_any val);

  // (func is-map)
  vx_core::Type_boolean f_is_map(vx_core::Type_any val);

  // (func is-list)
  class Abstract_is_list : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_is_list() {};
    virtual ~Abstract_is_list() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_is_list : public virtual Abstract_is_list {
  public:
    Class_is_list();
    virtual ~Class_is_list() override;
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

  // (func is-map)
  class Abstract_is_map : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_is_map() {};
    virtual ~Abstract_is_map() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_is_map : public virtual Abstract_is_map {
  public:
    Class_is_map();
    virtual ~Class_is_map() override;
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

  // (func list<-for-end-loop)
  class Abstract_list_from_for_end_loop : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_list_from_for_end_loop() {};
    virtual ~Abstract_list_from_for_end_loop() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_list_from_for_end_loop : public virtual Abstract_list_from_for_end_loop {
  public:
    Class_list_from_for_end_loop();
    virtual ~Class_list_from_for_end_loop() override;
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

  // (func list<-list-end)
  class Abstract_list_from_list_end : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_list_from_list_end() {};
    virtual ~Abstract_list_from_list_end() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_list_from_list_end : public virtual Abstract_list_from_list_end {
  public:
    Class_list_from_list_end();
    virtual ~Class_list_from_list_end() override;
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

  // (func list<-list-filtertypes)
  class Abstract_list_from_list_filtertypes : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_list_from_list_filtertypes() {};
    virtual ~Abstract_list_from_list_filtertypes() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_list_from_list_filtertypes : public virtual Abstract_list_from_list_filtertypes {
  public:
    Class_list_from_list_filtertypes();
    virtual ~Class_list_from_list_filtertypes() override;
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

  // (func list<-list-start)
  class Abstract_list_from_list_start : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_list_from_list_start() {};
    virtual ~Abstract_list_from_list_start() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_list_from_list_start : public virtual Abstract_list_from_list_start {
  public:
    Class_list_from_list_start();
    virtual ~Class_list_from_list_start() override;
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

  // (func any<-for-until-loop-max)
  template <class T> T* f_any_from_for_until_loop_max(T* generic_any_1, T* start, vx_core::Func_boolean_from_any fn_until, vx_core::Func_any_from_any fn_loop, vx_core::Type_int max) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve({start, fn_until, fn_loop, max});
    vx_core::Type_any any = vx_collection::vx_any_from_for_until_loop_max(generic_any_1, start, fn_until, fn_loop, max);
    output = vx_core::vx_any_from_any(generic_any_1, any);
    vx_core::vx_release_one_except({start, fn_until, fn_loop, max}, output);
    return output;
  }

  // (func any<-for-until-loop)
  template <class T> T* f_any_from_for_until_loop(T* generic_any_1, T* start, vx_core::Func_boolean_from_any fn_until, vx_core::Func_any_from_any fn_loop) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve({start, fn_until, fn_loop});
    output = vx_collection::f_any_from_for_until_loop_max(generic_any_1, start, fn_until, fn_loop, vx_core::vx_new_int(10000));
    vx_core::vx_release_one_except({start, fn_until, fn_loop}, output);
    return output;
  }

  // (func any<-for-while-loop-max)
  template <class T> T* f_any_from_for_while_loop_max(T* generic_any_1, T* start, vx_core::Func_boolean_from_any fn_while, vx_core::Func_any_from_any fn_loop, vx_core::Type_int max) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve({start, fn_while, fn_loop, max});
    vx_core::Type_any any = vx_collection::vx_any_from_for_while_loop_max(generic_any_1, start, fn_while, fn_loop, max);
    output = vx_core::vx_any_from_any(generic_any_1, any);
    vx_core::vx_release_one_except({start, fn_while, fn_loop, max}, output);
    return output;
  }

  // (func any<-for-while-loop)
  template <class T> T* f_any_from_for_while_loop(T* generic_any_1, T* start, vx_core::Func_boolean_from_any fn_while, vx_core::Func_any_from_any fn_loop) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve({start, fn_while, fn_loop});
    output = vx_collection::f_any_from_for_while_loop_max(generic_any_1, start, fn_while, fn_loop, vx_core::vx_new_int(1000));
    vx_core::vx_release_one_except({start, fn_while, fn_loop}, output);
    return output;
  }

  // (func list<-for-while-loop-max)
  template <class T, class X> X* f_list_from_for_while_loop_max(X* generic_list_1, T* start, vx_core::Func_boolean_from_any fn_while, vx_core::Func_any_from_any fn_loop, vx_core::Type_int max) {
    X* output = vx_core::vx_empty(generic_list_1);
    vx_core::vx_reserve({start, fn_while, fn_loop, max});
    vx_core::Type_any list = vx_collection::vx_list_from_for_while_loop_max(generic_list_1, start, fn_while, fn_loop, max);
    output = vx_core::vx_any_from_any(generic_list_1, list);
    vx_core::vx_release_one_except({start, fn_while, fn_loop, max}, output);
    return output;
  }

  // (func list<-for-while-loop)
  template <class T, class X> X* f_list_from_for_while_loop(X* generic_list_1, T* start, vx_core::Func_boolean_from_any fn_while, vx_core::Func_any_from_any fn_loop) {
    X* output = vx_core::vx_empty(generic_list_1);
    vx_core::vx_reserve({start, fn_while, fn_loop});
    output = vx_collection::f_list_from_for_while_loop_max(generic_list_1, start, fn_while, fn_loop, vx_core::vx_new_int(1000));
    vx_core::vx_release_one_except({start, fn_while, fn_loop}, output);
    return output;
  }

  // (func list<-list-filter)
  template <class X, class Y> X* f_list_from_list_filter(X* generic_list_1, Y* vallist, vx_core::Func_any_from_any fn_filter) {
    X* output = vx_core::vx_empty(generic_list_1);
    vx_core::vx_reserve({vallist, fn_filter});
    vx_core::Type_any list = vx_collection::vx_list_from_list_filter(generic_list_1, vallist, fn_filter);
    output = vx_core::vx_any_from_any(generic_list_1, list);
    vx_core::vx_release_one_except({vallist, fn_filter}, output);
    return output;
  }

  // (func list<-list-start-end)
  template <class X> X* f_list_from_list_start_end(X* generic_list_1, X* values, vx_core::Type_int start, vx_core::Type_int end) {
    X* output = vx_core::vx_empty(generic_list_1);
    vx_core::vx_reserve({values, start, end});
    vx_core::Type_any any = vx_collection::vx_list_from_list_start_end(generic_list_1, values, start, end);
    output = vx_core::vx_any_from_any(generic_list_1, any);
    vx_core::vx_release_one_except({values, start, end}, output);
    return output;
  }

  // (func list<-for-end-loop)
  template <class X> X* f_list_from_for_end_loop(X* generic_list_1, vx_core::Type_int start, vx_core::Type_int end, vx_core::Func_any_from_int fn_loop) {
    X* output = vx_core::vx_empty(generic_list_1);
    vx_core::vx_reserve({start, end, fn_loop});
    vx_core::Type_any list = vx_collection::vx_list_from_for_end_loop(generic_list_1, start, end, fn_loop);
    output = vx_core::vx_any_from_any(generic_list_1, list);
    vx_core::vx_release_one_except({start, end, fn_loop}, output);
    return output;
  }

  // (func list<-list-end)
  template <class X> X* f_list_from_list_end(X* generic_list_1, X* values, vx_core::Type_int end) {
    X* output = vx_core::vx_empty(generic_list_1);
    vx_core::vx_reserve({values, end});
    output = vx_collection::f_list_from_list_start_end(generic_list_1, values, vx_core::vx_new_int(1), end);
    vx_core::vx_release_one_except({values, end}, output);
    return output;
  }

  // (func list<-list-filtertypes)
  template <class X, class Y> X* f_list_from_list_filtertypes(X* generic_list_1, Y* vallist, vx_core::Type_typelist filtertypes) {
    X* output = vx_core::vx_empty(generic_list_1);
    vx_core::vx_reserve({vallist, filtertypes});
    output = vx_collection::f_list_from_list_filter(
      generic_list_1,
      vallist,
      vx_core::t_any_from_any->vx_fn_new({filtertypes}, [filtertypes](vx_core::Type_any val) {
        vx_core::Type_any output_1 = 
          vx_core::f_if(
            vx_core::t_any,
            vx_type::f_is_type_from_any_typelist(val, filtertypes),
            val
          );
        return output_1;
      })
    );
    vx_core::vx_release_one_except({vallist, filtertypes}, output);
    return output;
  }

  // (func list<-list-start)
  template <class X> X* f_list_from_list_start(X* generic_list_1, X* values, vx_core::Type_int start) {
    X* output = vx_core::vx_empty(generic_list_1);
    vx_core::vx_reserve({values, start});
    output = vx_collection::f_list_from_list_start_end(
      generic_list_1,
      values,
      start,
      vx_core::f_length_from_list(values)
    );
    vx_core::vx_release_one_except({values, start}, output);
    return output;
  }

  class vx_Class_package {
  public:
    vx_Class_package();
    void init();
  };
  inline vx_Class_package const vx_package;

}

#endif
