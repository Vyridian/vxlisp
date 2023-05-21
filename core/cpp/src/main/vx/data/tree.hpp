#ifndef vx_data_tree_hpp
#define vx_data_tree_hpp
#include <memory>
#include <set>
#include <string>
#include <vector>
#include "../../vx/core.hpp"

namespace vx_data_tree {

  // forward declarations
  class Class_branch;
  typedef std::shared_ptr<Class_branch> Type_branch;
  extern Type_branch e_branch;
  extern Type_branch t_branch;
  class Class_brancharrow;
  typedef std::shared_ptr<Class_brancharrow> Type_brancharrow;
  extern Type_brancharrow e_brancharrow;
  extern Type_brancharrow t_brancharrow;
  class Class_branchlist;
  typedef std::shared_ptr<Class_branchlist> Type_branchlist;
  extern Type_branchlist e_branchlist;
  extern Type_branchlist t_branchlist;
  class Class_leaf;
  typedef std::shared_ptr<Class_leaf> Type_leaf;
  extern Type_leaf e_leaf;
  extern Type_leaf t_leaf;
  class Class_leaflist;
  typedef std::shared_ptr<Class_leaflist> Type_leaflist;
  extern Type_leaflist e_leaflist;
  extern Type_leaflist t_leaflist;
  class Class_tree;
  typedef std::shared_ptr<Class_tree> Type_tree;
  extern Type_tree e_tree;
  extern Type_tree t_tree;
  class Class_brancharrow_down;
  typedef std::shared_ptr<Class_brancharrow_down> Const_brancharrow_down;
  extern Const_brancharrow_down c_brancharrow_down;
  class Class_brancharrow_up;
  typedef std::shared_ptr<Class_brancharrow_up> Const_brancharrow_up;
  extern Const_brancharrow_up c_brancharrow_up;
  class Class_brancharrow_updown;
  typedef std::shared_ptr<Class_brancharrow_updown> Const_brancharrow_updown;
  extern Const_brancharrow_updown c_brancharrow_updown;


  // (type branch)
  class Class_branch : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key);
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // brancharrow()
    vx_data_tree::Type_brancharrow vx_p_brancharrow;
    virtual vx_data_tree::Type_brancharrow brancharrow();
    // branchlist()
    vx_data_tree::Type_branchlist vx_p_branchlist;
    virtual vx_data_tree::Type_branchlist branchlist();
    // leaflist()
    vx_data_tree::Type_leaflist vx_p_leaflist;
    virtual vx_data_tree::Type_leaflist leaflist();
    // parentbranch()
    vx_data_tree::Type_branch vx_p_parentbranch;
    virtual vx_data_tree::Type_branch parentbranch();
    // tree()
    vx_data_tree::Type_tree vx_p_tree;
    virtual vx_data_tree::Type_tree tree();
  };

  // (type brancharrow)
  class Class_brancharrow : public vx_core::Class_any {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
  };

  // (type branchlist)
  class Class_branchlist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval);
    std::vector<vx_data_tree::Type_branch> vx_p_list;

    // vx_listbranch()
    virtual std::vector<vx_data_tree::Type_branch> vx_listbranch();
    // vx_get_branch(index)
    virtual vx_data_tree::Type_branch vx_get_branch(vx_core::Type_int index);
  };

  // (type leaf)
  class Class_leaf : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key);
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // name()
    vx_core::Type_string vx_p_name;
    virtual vx_core::Type_string name();
    // value()
    vx_core::Type_any vx_p_value;
    virtual vx_core::Type_any value();
  };

  // (type leaflist)
  class Class_leaflist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval);
    std::vector<vx_data_tree::Type_leaf> vx_p_list;

    // vx_listleaf()
    virtual std::vector<vx_data_tree::Type_leaf> vx_listleaf();
    // vx_get_leaf(index)
    virtual vx_data_tree::Type_leaf vx_get_leaf(vx_core::Type_int index);
  };

  // (type tree)
  class Class_tree : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key);
    // id()
    vx_core::Type_string vx_p_id;
    virtual vx_core::Type_string id();
    // name()
    vx_core::Type_string vx_p_name;
    virtual vx_core::Type_string name();
    // branch()
    vx_data_tree::Type_branch vx_p_branch;
    virtual vx_data_tree::Type_branch branch();
  };

  // (const brancharrow-down)
  class Class_brancharrow_down : public vx_data_tree::Class_brancharrow {
  public:
    vx_core::Type_constdef vx_constdef();
    static vx_data_tree::Const_brancharrow_down vx_const_new();
  };

  // (const brancharrow-up)
  class Class_brancharrow_up : public vx_data_tree::Class_brancharrow {
  public:
    vx_core::Type_constdef vx_constdef();
    static vx_data_tree::Const_brancharrow_up vx_const_new();
  };

  // (const brancharrow-updown)
  class Class_brancharrow_updown : public vx_data_tree::Class_brancharrow {
  public:
    vx_core::Type_constdef vx_constdef();
    static vx_data_tree::Const_brancharrow_updown vx_const_new();
  };

}
#endif
