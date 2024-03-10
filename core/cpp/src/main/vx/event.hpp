#ifndef VX_EVENT_HPP
#define VX_EVENT_HPP
#include <map>
#include <string>
#include <vector>
#include "../vx/core.hpp"

namespace vx_event {


  // forward declarations
  class Abstract_event;
  typedef Abstract_event* Type_event;
  extern Type_event e_event;
  extern Type_event t_event;
  class Abstract_eventlist;
  typedef Abstract_eventlist* Type_eventlist;
  extern Type_eventlist e_eventlist;
  extern Type_eventlist t_eventlist;
  class Abstract_eventmap;
  typedef Abstract_eventmap* Type_eventmap;
  extern Type_eventmap e_eventmap;
  extern Type_eventmap t_eventmap;
  class Class_event_change;
  typedef Class_event_change* Const_event_change;
  extern Const_event_change c_event_change;
  class Class_event_click;
  typedef Class_event_click* Const_event_click;
  extern Const_event_click c_event_click;
  class Class_event_move;
  typedef Class_event_move* Const_event_move;
  extern Const_event_move c_event_move;
  class Class_event_select;
  typedef Class_event_select* Const_event_select;
  extern Const_event_select c_event_select;
  class Abstract_any_from_from_event;
  typedef Abstract_any_from_from_event* Func_any_from_from_event;
  extern Func_any_from_from_event e_any_from_from_event;
  extern Func_any_from_from_event t_any_from_from_event;
  class Abstract_event_from_event;
  typedef Abstract_event_from_event* Func_event_from_event;
  extern Func_event_from_event e_event_from_event;
  extern Func_event_from_event t_event_from_event;
  class Abstract_event_from_event_async;
  typedef Abstract_event_from_event_async* Func_event_from_event_async;
  extern Func_event_from_event_async e_event_from_event_async;
  extern Func_event_from_event_async t_event_from_event_async;
  class Abstract_eventmap_from_eventlist;
  typedef Abstract_eventmap_from_eventlist* Func_eventmap_from_eventlist;
  extern Func_eventmap_from_eventlist e_eventmap_from_eventlist;
  extern Func_eventmap_from_eventlist t_eventmap_from_eventlist;
  // (func event<-event)
  vx_event::Type_event f_event_from_event(vx_core::Type_context context, vx_event::Type_event event);

  // (func event<-event-async)
  vx_core::vx_Type_async f_event_from_event_async(vx_core::Type_context context, vx_event::Type_event event);

  // (func eventmap<-eventlist)
  vx_event::Type_eventmap f_eventmap_from_eventlist(vx_event::Type_eventlist eventlist);

  // (type event)
  class Abstract_event : public virtual vx_core::Abstract_struct {
  public:
    Abstract_event() {};
    virtual ~Abstract_event() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // from()
    vx_core::Type_string vx_p_from = NULL;
    virtual vx_core::Type_string from() const = 0;
    // to()
    vx_core::Type_string vx_p_to = NULL;
    virtual vx_core::Type_string to() const = 0;
    // datamap()
    vx_core::Type_anymap vx_p_datamap = NULL;
    virtual vx_core::Type_anymap datamap() const = 0;
    // event<-event()
    vx_event::Func_event_from_event vx_p_event_from_event = NULL;
    virtual vx_event::Func_event_from_event event_from_event() const = 0;
    // event<-event-async()
    vx_event::Func_event_from_event_async vx_p_event_from_event_async = NULL;
    virtual vx_event::Func_event_from_event_async event_from_event_async() const = 0;
  };
  class Class_event : public virtual Abstract_event {
  public:
    Class_event();
    virtual ~Class_event() override;
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
    virtual vx_core::Type_string from() const override;
    virtual vx_core::Type_string to() const override;
    virtual vx_core::Type_anymap datamap() const override;
    virtual vx_event::Func_event_from_event event_from_event() const override;
    virtual vx_event::Func_event_from_event_async event_from_event_async() const override;
  };

  // (type eventlist)
  class Abstract_eventlist : public virtual vx_core::Abstract_list {
  public:
    Abstract_eventlist() {};
    virtual ~Abstract_eventlist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_event::Type_event> vx_p_list;
    // vx_listevent()
    virtual std::vector<vx_event::Type_event> vx_listevent() const = 0;
    // vx_get_event(index)
    virtual vx_event::Type_event vx_get_event(vx_core::Type_int index) const = 0;
  };
  class Class_eventlist : public virtual Abstract_eventlist {
  public:
    Class_eventlist();
    virtual ~Class_eventlist() override;
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
    virtual std::vector<vx_event::Type_event> vx_listevent() const override;
    virtual vx_event::Type_event vx_get_event(vx_core::Type_int index) const override;
  };

  // (type eventmap)
  class Abstract_eventmap : public virtual vx_core::Abstract_map {
  public:
    Abstract_eventmap() {};
    virtual ~Abstract_eventmap() = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_new_from_map(T, Map<T>)
    virtual vx_core::Type_any vx_new_from_map(vx_core::vx_Type_mapany mapval) const = 0;
    std::map<std::string, vx_event::Type_event> vx_p_map;
    // vx_mapevent()
    virtual std::map<std::string, vx_event::Type_event> vx_mapevent() const = 0;
    // vx_get_event(key)
    virtual vx_event::Type_event vx_get_event(vx_core::Type_string key) const = 0;
  };
  class Class_eventmap : public virtual Abstract_eventmap {
  public:
    Class_eventmap();
    virtual ~Class_eventmap() override;
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
    virtual std::map<std::string, vx_event::Type_event> vx_mapevent() const override;
    virtual vx_event::Type_event vx_get_event(vx_core::Type_string key) const override;
  };

  // (const event-change)
  class Class_event_change : public vx_event::Class_event {
  public:
    static void vx_const_new(vx_event::Const_event_change output);
  };

  // (const event-click)
  class Class_event_click : public vx_event::Class_event {
  public:
    static void vx_const_new(vx_event::Const_event_click output);
  };

  // (const event-move)
  class Class_event_move : public vx_event::Class_event {
  public:
    static void vx_const_new(vx_event::Const_event_move output);
  };

  // (const event-select)
  class Class_event_select : public vx_event::Class_event {
  public:
    static void vx_const_new(vx_event::Const_event_select output);
  };

  // (func any-from<-event)
  class Abstract_any_from_from_event : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_from_event() {};
    virtual ~Abstract_any_from_from_event() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_from_event : public virtual Abstract_any_from_from_event {
  public:
    Class_any_from_from_event();
    virtual ~Class_any_from_from_event() override;
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

  // (func event<-event)
  class Abstract_event_from_event : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_event_from_event() {};
    virtual ~Abstract_event_from_event() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_event_from_event : public virtual Abstract_event_from_event {
  public:
    Class_event_from_event();
    virtual ~Class_event_from_event() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_context context, vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func event<-event-async)
  class Abstract_event_from_event_async : public vx_core::Abstract_any_from_any_context_async, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_event_from_event_async() {};
    virtual ~Abstract_event_from_event_async() = 0;
    virtual vx_core::Func_any_from_any_context_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context_async::IFn fn) const override = 0;
    virtual vx_core::vx_Type_async vx_any_from_any_context_async(vx_core::Type_any generic_any_1, vx_core::Type_context context, vx_core::Type_any val) const override = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_event_from_event_async : public virtual Abstract_event_from_event_async {
  public:
    Class_event_from_event_async();
    virtual ~Class_event_from_event_async() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_constdef vx_constdef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context_async::IFn fn) const override;
    virtual vx_core::vx_Type_async vx_any_from_any_context_async(vx_core::Type_any generic_any_1, vx_core::Type_context context, vx_core::Type_any val) const override;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func eventmap<-eventlist)
  class Abstract_eventmap_from_eventlist : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_eventmap_from_eventlist() {};
    virtual ~Abstract_eventmap_from_eventlist() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_eventmap_from_eventlist : public virtual Abstract_eventmap_from_eventlist {
  public:
    Class_eventmap_from_eventlist();
    virtual ~Class_eventmap_from_eventlist() override;
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

  // (func any-from<-event)
  template <class T> T* f_any_from_from_event(T* generic_any_1, vx_event::Type_event event) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve(event);
    output = vx_core::f_let(
      generic_any_1,
      vx_core::t_any_from_func->vx_fn_new({event, generic_any_1}, [event, generic_any_1]() {
        vx_core::Type_any value = event->from();
        vx_core::vx_ref_plus(value);
        vx_core::Type_any output_1 = vx_core::f_any_from_any(generic_any_1, value);
        vx_core::vx_release_one_except(value, output_1);
        return output_1;
      })
    );
    vx_core::vx_release_one_except(event, output);
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
