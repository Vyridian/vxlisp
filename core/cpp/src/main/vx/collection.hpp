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
  class Abstract_any_from_map_pos;
  typedef Abstract_any_from_map_pos* Func_any_from_map_pos;
  extern Func_any_from_map_pos e_any_from_map_pos;
  extern Func_any_from_map_pos t_any_from_map_pos;
  class Abstract_boolean_write_from_map_removekey;
  typedef Abstract_boolean_write_from_map_removekey* Func_boolean_write_from_map_removekey;
  extern Func_boolean_write_from_map_removekey e_boolean_write_from_map_removekey;
  extern Func_boolean_write_from_map_removekey t_boolean_write_from_map_removekey;
  class Abstract_boolean_write_from_map_removekeys;
  typedef Abstract_boolean_write_from_map_removekeys* Func_boolean_write_from_map_removekeys;
  extern Func_boolean_write_from_map_removekeys e_boolean_write_from_map_removekeys;
  extern Func_boolean_write_from_map_removekeys t_boolean_write_from_map_removekeys;
  class Abstract_int_from_map_key;
  typedef Abstract_int_from_map_key* Func_int_from_map_key;
  extern Func_int_from_map_key e_int_from_map_key;
  extern Func_int_from_map_key t_int_from_map_key;
  class Abstract_int_from_stringlist_find;
  typedef Abstract_int_from_stringlist_find* Func_int_from_stringlist_find;
  extern Func_int_from_stringlist_find e_int_from_stringlist_find;
  extern Func_int_from_stringlist_find t_int_from_stringlist_find;
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
  extern Func_list_from_list_start_end t_list_from_list_start_end;
  class Abstract_map_from_map_end;
  typedef Abstract_map_from_map_end* Func_map_from_map_end;
  extern Func_map_from_map_end e_map_from_map_end;
  extern Func_map_from_map_end t_map_from_map_end;
  class Abstract_map_from_map_keys;
  typedef Abstract_map_from_map_keys* Func_map_from_map_keys;
  extern Func_map_from_map_keys e_map_from_map_keys;
  extern Func_map_from_map_keys t_map_from_map_keys;
  class Abstract_map_from_map_start;
  typedef Abstract_map_from_map_start* Func_map_from_map_start;
  extern Func_map_from_map_start e_map_from_map_start;
  extern Func_map_from_map_start t_map_from_map_start;
  class Abstract_map_from_map_start_end;
  typedef Abstract_map_from_map_start_end* Func_map_from_map_start_end;
  extern Func_map_from_map_start_end e_map_from_map_start_end;
  extern Func_map_from_map_start_end t_map_from_map_start_end;// :headerfirst
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

  // vx_map_from_map_keys(generic_map_1, map, stringlist)
  vx_core::Type_any vx_map_from_map_keys(vx_core::Type_any generic_map_1, vx_core::Type_map valuemap, vx_core::Type_stringlist keys);
	 

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

  // (func map<-map-keys)
  class Abstract_map_from_map_keys : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_map_from_map_keys() {};
    virtual ~Abstract_map_from_map_keys() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_map_from_map_keys : public virtual Abstract_map_from_map_keys {
  public:
    Class_map_from_map_keys();
    virtual ~Class_map_from_map_keys() override;
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

  // (func map<-map-start-end)
  class Abstract_map_from_map_start_end : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_map_from_map_start_end() {};
    virtual ~Abstract_map_from_map_start_end() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_map_from_map_start_end : public virtual Abstract_map_from_map_start_end {
  public:
    Class_map_from_map_start_end();
    virtual ~Class_map_from_map_start_end() override;
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

  // (func boolean-write<-map-removekey)
  vx_core::Type_boolean f_boolean_write_from_map_removekey(vx_core::Type_map valuemap, vx_core::Type_string key);

  // (func boolean-write<-map-removekeys)
  vx_core::Type_boolean f_boolean_write_from_map_removekeys(vx_core::Type_map valuemap, vx_core::Type_stringlist keys);

  // (func int<-map-key)
  vx_core::Type_int f_int_from_map_key(vx_core::Type_map map, vx_core::Type_string key);

  // (func int<-stringlist-find)
  vx_core::Type_int f_int_from_stringlist_find(vx_core::Type_stringlist stringlist, vx_core::Type_string find);

  // (func is-list)
  vx_core::Type_boolean f_is_list(vx_core::Type_any value);

  // (func is-map)
  vx_core::Type_boolean f_is_map(vx_core::Type_any value);

  // (func any<-map-pos)
  class Abstract_any_from_map_pos : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_map_pos() {};
    virtual ~Abstract_any_from_map_pos() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_map_pos : public virtual Abstract_any_from_map_pos {
  public:
    Class_any_from_map_pos();
    virtual ~Class_any_from_map_pos() override;
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

  // (func boolean-write<-map-removekey)
  class Abstract_boolean_write_from_map_removekey : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_boolean_write_from_map_removekey() {};
    virtual ~Abstract_boolean_write_from_map_removekey() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_write_from_map_removekey : public virtual Abstract_boolean_write_from_map_removekey {
  public:
    Class_boolean_write_from_map_removekey();
    virtual ~Class_boolean_write_from_map_removekey() override;
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

  // (func boolean-write<-map-removekeys)
  class Abstract_boolean_write_from_map_removekeys : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_boolean_write_from_map_removekeys() {};
    virtual ~Abstract_boolean_write_from_map_removekeys() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_boolean_write_from_map_removekeys : public virtual Abstract_boolean_write_from_map_removekeys {
  public:
    Class_boolean_write_from_map_removekeys();
    virtual ~Class_boolean_write_from_map_removekeys() override;
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

  // (func int<-map-key)
  class Abstract_int_from_map_key : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_int_from_map_key() {};
    virtual ~Abstract_int_from_map_key() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_int_from_map_key : public virtual Abstract_int_from_map_key {
  public:
    Class_int_from_map_key();
    virtual ~Class_int_from_map_key() override;
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

  // (func int<-stringlist-find)
  class Abstract_int_from_stringlist_find : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_int_from_stringlist_find() {};
    virtual ~Abstract_int_from_stringlist_find() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_int_from_stringlist_find : public virtual Abstract_int_from_stringlist_find {
  public:
    Class_int_from_stringlist_find();
    virtual ~Class_int_from_stringlist_find() override;
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

  // (func map<-map-end)
  class Abstract_map_from_map_end : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_map_from_map_end() {};
    virtual ~Abstract_map_from_map_end() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_map_from_map_end : public virtual Abstract_map_from_map_end {
  public:
    Class_map_from_map_end();
    virtual ~Class_map_from_map_end() override;
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

  // (func map<-map-start)
  class Abstract_map_from_map_start : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_map_from_map_start() {};
    virtual ~Abstract_map_from_map_start() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_map_from_map_start : public virtual Abstract_map_from_map_start {
  public:
    Class_map_from_map_start();
    virtual ~Class_map_from_map_start() override;
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

  // (func map<-map-keys)
  template <class N> N* f_map_from_map_keys(N* generic_map_1, N* valuemap, vx_core::Type_stringlist keys) {
    N* output = vx_core::vx_empty(generic_map_1);
    vx_core::vx_reserve({valuemap, keys});
    vx_core::Type_any result = vx_collection::vx_map_from_map_keys(generic_map_1, valuemap, keys);
    output = vx_core::vx_any_from_any(generic_map_1, result);
    vx_core::vx_release_one_except({valuemap, keys}, output);
    return output;
  }

  // (func map<-map-start-end)
  template <class N> N* f_map_from_map_start_end(N* generic_map_1, N* valuemap, vx_core::Type_int start, vx_core::Type_int end) {
    N* output = vx_core::vx_empty(generic_map_1);
    vx_core::vx_reserve({valuemap, start, end});
    output = vx_core::f_let(
      generic_map_1,
      vx_core::t_any_from_func->vx_fn_new({valuemap, start, end, generic_map_1}, [valuemap, start, end, generic_map_1]() {
        vx_core::Type_stringlist keys1 = vx_core::f_stringlist_from_map(valuemap);
        vx_core::vx_ref_plus(keys1);
        vx_core::Type_stringlist keys2 = vx_collection::f_list_from_list_start_end(vx_core::t_stringlist, keys1, start, end);
        vx_core::vx_ref_plus(keys2);
        vx_core::Type_map output_1 = vx_collection::f_map_from_map_keys(generic_map_1, valuemap, keys2);
        vx_core::vx_release_one_except({keys1, keys2}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({valuemap, start, end}, output);
    return output;
  }

  // (func any<-map-pos)
  template <class T, class N> T* f_any_from_map_pos(T* generic_any_1, N* map, vx_core::Type_int pos) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve({map, pos});
    output = vx_core::f_let(
      generic_any_1,
      vx_core::t_any_from_func->vx_fn_new({map, pos, generic_any_1}, [map, pos, generic_any_1]() {
        vx_core::Type_stringlist keys = vx_core::f_stringlist_from_map(map);
        vx_core::vx_ref_plus(keys);
        vx_core::Type_string key = vx_core::f_any_from_list(vx_core::t_string, keys, pos);
        vx_core::vx_ref_plus(key);
        vx_core::Type_any output_1 = vx_core::f_any_from_map(generic_any_1, map, key);
        vx_core::vx_release_one_except({keys, key}, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except({map, pos}, output);
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
      vx_core::t_any_from_any->vx_fn_new({filtertypes}, [filtertypes](vx_core::Type_any value) {
        vx_core::Type_any output_1 = 
          vx_core::f_if(
            vx_core::t_any,
            vx_type::f_is_type_from_any_typelist(value, filtertypes),
            value
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
      vx_core::f_length_1(values)
    );
    vx_core::vx_release_one_except({values, start}, output);
    return output;
  }

  // (func map<-map-end)
  template <class N> N* f_map_from_map_end(N* generic_map_1, N* valuemap, vx_core::Type_int end) {
    N* output = vx_core::vx_empty(generic_map_1);
    vx_core::vx_reserve({valuemap, end});
    output = vx_collection::f_map_from_map_start_end(generic_map_1, valuemap, vx_core::vx_new_int(1), end);
    vx_core::vx_release_one_except({valuemap, end}, output);
    return output;
  }

  // (func map<-map-start)
  template <class N> N* f_map_from_map_start(N* generic_map_1, N* valuemap, vx_core::Type_int start) {
    N* output = vx_core::vx_empty(generic_map_1);
    vx_core::vx_reserve({valuemap, start});
    output = vx_collection::f_map_from_map_start_end(
      generic_map_1,
      valuemap,
      start,
      vx_core::f_length_2(valuemap)
    );
    vx_core::vx_release_one_except({valuemap, start}, output);
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
