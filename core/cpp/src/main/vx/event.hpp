#ifndef VX_EVENT_HPP
#define VX_EVENT_HPP
#include "../vx/core.hpp"

namespace vx_event {

  // forward declarations
  class Abstract_event;
  typedef Abstract_event* Type_event;
  extern Type_event e_event;
  extern Type_event t_event;
  class Class_event_click;
  typedef Class_event_click* Const_event_click;
  extern Const_event_click c_event_click;
  class Class_event_move;
  typedef Class_event_move* Const_event_move;
  extern Const_event_move c_event_move;
  class Abstract_any_from_from_to;
  typedef Abstract_any_from_from_to* Func_any_from_from_to;
  extern Func_any_from_from_to e_any_from_from_to;
  extern Func_any_from_from_to t_any_from_from_to;
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
    vx_core::Type_any vx_p_from = NULL;
    virtual vx_core::Type_any from() const = 0;
    // to()
    vx_core::Type_any vx_p_to = NULL;
    virtual vx_core::Type_any to() const = 0;
    // fn-any<-any()
    vx_core::Func_any_from_any vx_p_fn_any_from_any = NULL;
    virtual vx_core::Func_any_from_any fn_any_from_any() const = 0;
    // fn-any<-from-to()
    vx_event::Func_any_from_from_to vx_p_fn_any_from_from_to = NULL;
    virtual vx_event::Func_any_from_from_to fn_any_from_from_to() const = 0;
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
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string name() const override;
    virtual vx_core::Type_any from() const override;
    virtual vx_core::Type_any to() const override;
    virtual vx_core::Func_any_from_any fn_any_from_any() const override;
    virtual vx_event::Func_any_from_from_to fn_any_from_from_to() const override;
  };

  // (const event-click)
  class Class_event_click : public vx_event::Class_event {
  public:
    static void vx_const_new(vx_event::Const_event_click output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (const event-move)
  class Class_event_move : public vx_event::Class_event {
  public:
    static void vx_const_new(vx_event::Const_event_move output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (func any<-from-to)
  class Abstract_any_from_from_to : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_any_from_from_to() {};
    virtual ~Abstract_any_from_from_to() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_any_from_from_to : public virtual Abstract_any_from_from_to {
  public:
    Class_any_from_from_to();
    virtual ~Class_any_from_from_to() override;
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

  // (func any<-from-to)
  template <class T> T* f_any_from_from_to(T* generic_any_1, vx_core::Type_any from, vx_core::Type_any to) {
    T* output = vx_core::vx_empty(generic_any_1);
    vx_core::vx_reserve({from, to});
    vx_core::vx_release_one_except({from, to}, output);
    return output;
  }

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
