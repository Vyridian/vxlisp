#ifndef vx_data_tree_hpp
#define vx_data_tree_hpp
#include <vector>
#include "../../vx/core.hpp"

namespace vx_data_tree {

  // forward declarations
  class Abstract_branch;
  typedef Abstract_branch* Type_branch;
  extern Type_branch e_branch();
  extern Type_branch t_branch();
  class Abstract_brancharrow;
  typedef Abstract_brancharrow* Type_brancharrow;
  extern Type_brancharrow e_brancharrow();
  extern Type_brancharrow t_brancharrow();
  class Abstract_branchlist;
  typedef Abstract_branchlist* Type_branchlist;
  extern Type_branchlist e_branchlist();
  extern Type_branchlist t_branchlist();
  class Abstract_leaf;
  typedef Abstract_leaf* Type_leaf;
  extern Type_leaf e_leaf();
  extern Type_leaf t_leaf();
  class Abstract_leaflist;
  typedef Abstract_leaflist* Type_leaflist;
  extern Type_leaflist e_leaflist();
  extern Type_leaflist t_leaflist();
  class Abstract_tree;
  typedef Abstract_tree* Type_tree;
  extern Type_tree e_tree();
  extern Type_tree t_tree();
  class Class_brancharrow_down;
  typedef Class_brancharrow_down* Const_brancharrow_down;
  extern Const_brancharrow_down c_brancharrow_down();
  class Class_brancharrow_up;
  typedef Class_brancharrow_up* Const_brancharrow_up;
  extern Const_brancharrow_up c_brancharrow_up();
  class Class_brancharrow_updown;
  typedef Class_brancharrow_updown* Const_brancharrow_updown;
  extern Const_brancharrow_updown c_brancharrow_updown();

  class vx_Class_package {
  public:
    vx_data_tree::Type_branch e_branch;
    vx_data_tree::Type_branch t_branch;
    vx_data_tree::Type_brancharrow e_brancharrow;
    vx_data_tree::Type_brancharrow t_brancharrow;
    vx_data_tree::Type_branchlist e_branchlist;
    vx_data_tree::Type_branchlist t_branchlist;
    vx_data_tree::Type_leaf e_leaf;
    vx_data_tree::Type_leaf t_leaf;
    vx_data_tree::Type_leaflist e_leaflist;
    vx_data_tree::Type_leaflist t_leaflist;
    vx_data_tree::Type_tree e_tree;
    vx_data_tree::Type_tree t_tree;
    vx_data_tree::Const_brancharrow_down c_brancharrow_down;
    vx_data_tree::Const_brancharrow_up c_brancharrow_up;
    vx_data_tree::Const_brancharrow_updown c_brancharrow_updown;
  };


  // (type branch)
  class Abstract_branch : public virtual vx_core::Abstract_struct {
  public:
    Abstract_branch() {};
    virtual ~Abstract_branch() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // brancharrow()
    vx_data_tree::Type_brancharrow vx_p_brancharrow = NULL;
    virtual vx_data_tree::Type_brancharrow brancharrow() const = 0;
    // branchlist()
    vx_data_tree::Type_branchlist vx_p_branchlist = NULL;
    virtual vx_data_tree::Type_branchlist branchlist() const = 0;
    // leaflist()
    vx_data_tree::Type_leaflist vx_p_leaflist = NULL;
    virtual vx_data_tree::Type_leaflist leaflist() const = 0;
    // parentbranch()
    vx_data_tree::Type_branch vx_p_parentbranch = NULL;
    virtual vx_data_tree::Type_branch parentbranch() const = 0;
    // tree()
    vx_data_tree::Type_tree vx_p_tree = NULL;
    virtual vx_data_tree::Type_tree tree() const = 0;
  };
  class Class_branch : public virtual Abstract_branch {
  public:
    Class_branch();
    virtual ~Class_branch() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string id() const override;
    virtual vx_data_tree::Type_brancharrow brancharrow() const override;
    virtual vx_data_tree::Type_branchlist branchlist() const override;
    virtual vx_data_tree::Type_leaflist leaflist() const override;
    virtual vx_data_tree::Type_branch parentbranch() const override;
    virtual vx_data_tree::Type_tree tree() const override;
  };

  // (type brancharrow)
  class Abstract_brancharrow : public virtual vx_core::Abstract_any {
  public:
    Abstract_brancharrow() {};
    virtual ~Abstract_brancharrow() = 0;
  };
  class Class_brancharrow : public virtual Abstract_brancharrow {
  public:
    Class_brancharrow();
    virtual ~Class_brancharrow() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type branchlist)
  class Abstract_branchlist : public virtual vx_core::Abstract_list {
  public:
    Abstract_branchlist() {};
    virtual ~Abstract_branchlist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_data_tree::Type_branch> vx_p_list;
    // vx_listbranch()
    virtual std::vector<vx_data_tree::Type_branch> vx_listbranch() const = 0;
    // vx_get_branch(index)
    virtual vx_data_tree::Type_branch vx_get_branch(vx_core::Type_int index) const = 0;
  };
  class Class_branchlist : public virtual Abstract_branchlist {
  public:
    Class_branchlist();
    virtual ~Class_branchlist() override;
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
    virtual std::vector<vx_data_tree::Type_branch> vx_listbranch() const override;
    virtual vx_data_tree::Type_branch vx_get_branch(vx_core::Type_int index) const override;
  };

  // (type leaf)
  class Abstract_leaf : public virtual vx_core::Abstract_struct {
  public:
    Abstract_leaf() {};
    virtual ~Abstract_leaf() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // value()
    vx_core::Type_any vx_p_value = NULL;
    virtual vx_core::Type_any value() const = 0;
  };
  class Class_leaf : public virtual Abstract_leaf {
  public:
    Class_leaf();
    virtual ~Class_leaf() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string id() const override;
    virtual vx_core::Type_string name() const override;
    virtual vx_core::Type_any value() const override;
  };

  // (type leaflist)
  class Abstract_leaflist : public virtual vx_core::Abstract_list {
  public:
    Abstract_leaflist() {};
    virtual ~Abstract_leaflist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_data_tree::Type_leaf> vx_p_list;
    // vx_listleaf()
    virtual std::vector<vx_data_tree::Type_leaf> vx_listleaf() const = 0;
    // vx_get_leaf(index)
    virtual vx_data_tree::Type_leaf vx_get_leaf(vx_core::Type_int index) const = 0;
  };
  class Class_leaflist : public virtual Abstract_leaflist {
  public:
    Class_leaflist();
    virtual ~Class_leaflist() override;
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
    virtual std::vector<vx_data_tree::Type_leaf> vx_listleaf() const override;
    virtual vx_data_tree::Type_leaf vx_get_leaf(vx_core::Type_int index) const override;
  };

  // (type tree)
  class Abstract_tree : public virtual vx_core::Abstract_struct {
  public:
    Abstract_tree() {};
    virtual ~Abstract_tree() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // id()
    vx_core::Type_string vx_p_id = NULL;
    virtual vx_core::Type_string id() const = 0;
    // name()
    vx_core::Type_string vx_p_name = NULL;
    virtual vx_core::Type_string name() const = 0;
    // branch()
    vx_data_tree::Type_branch vx_p_branch = NULL;
    virtual vx_data_tree::Type_branch branch() const = 0;
  };
  class Class_tree : public virtual Abstract_tree {
  public:
    Class_tree();
    virtual ~Class_tree() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string id() const override;
    virtual vx_core::Type_string name() const override;
    virtual vx_data_tree::Type_branch branch() const override;
  };

  // (const brancharrow-down)
  class Class_brancharrow_down : public vx_data_tree::Class_brancharrow {
  public:
    static vx_data_tree::Const_brancharrow_down vx_const_new();
    vx_core::Type_constdef vx_constdef() const;
  };

  // (const brancharrow-up)
  class Class_brancharrow_up : public vx_data_tree::Class_brancharrow {
  public:
    static vx_data_tree::Const_brancharrow_up vx_const_new();
    vx_core::Type_constdef vx_constdef() const;
  };

  // (const brancharrow-updown)
  class Class_brancharrow_updown : public vx_data_tree::Class_brancharrow {
  public:
    static vx_data_tree::Const_brancharrow_updown vx_const_new();
    vx_core::Type_constdef vx_constdef() const;
  };

}
#endif
