#pragma once
#include <any>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "../../vx/core.hpp"

namespace vx_data_tree {

  // forward declarations
  class Type_branch;
  extern Type_branch* e_branch;
  extern Type_branch* t_branch;
  class Type_brancharrow;
  extern Type_brancharrow* e_brancharrow;
  extern Type_brancharrow* t_brancharrow;
  class Type_branchlist;
  extern Type_branchlist* e_branchlist;
  extern Type_branchlist* t_branchlist;
  class Type_leaf;
  extern Type_leaf* e_leaf;
  extern Type_leaf* t_leaf;
  class Type_leaflist;
  extern Type_leaflist* e_leaflist;
  extern Type_leaflist* t_leaflist;
  class Type_tree;
  extern Type_tree* e_tree;
  extern Type_tree* t_tree;
  class Const_brancharrow_down;
  extern Const_brancharrow_down* c_brancharrow_down;
  class Const_brancharrow_up;
  extern Const_brancharrow_up* c_brancharrow_up;
  class Const_brancharrow_updown;
  extern Const_brancharrow_updown* c_brancharrow_updown;


  // (type branch)
  class Type_branch : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_data_tree::Type_branch* vx_new(Args*... args);
    template<class... Args> vx_data_tree::Type_branch* vx_copy(Args*... args);
    virtual vx_data_tree::Type_branch* vx_empty();
    virtual vx_data_tree::Type_branch* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // brancharrow()
    vx_data_tree::Type_brancharrow* vx_p_brancharrow;
    virtual vx_data_tree::Type_brancharrow* brancharrow();
    // branchlist()
    vx_data_tree::Type_branchlist* vx_p_branchlist;
    virtual vx_data_tree::Type_branchlist* branchlist();
    // leaflist()
    vx_data_tree::Type_leaflist* vx_p_leaflist;
    virtual vx_data_tree::Type_leaflist* leaflist();
    // parentbranch()
    vx_data_tree::Type_branch* vx_p_parentbranch;
    virtual vx_data_tree::Type_branch* parentbranch();
    // tree()
    vx_data_tree::Type_tree* vx_p_tree;
    virtual vx_data_tree::Type_tree* tree();
  };

  // (type brancharrow)
  class Type_brancharrow : public vx_core::Type_any {
  public:
    template<class... Args> vx_data_tree::Type_brancharrow* vx_new(Args*... args);
    template<class... Args> vx_data_tree::Type_brancharrow* vx_copy(Args*... args);
    virtual vx_data_tree::Type_brancharrow* vx_empty();
    virtual vx_data_tree::Type_brancharrow* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
  };

  // (type branchlist)
  class Type_branchlist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_data_tree::Type_branchlist* vx_new(Args*... args);
    template<class... Args> vx_data_tree::Type_branchlist* vx_copy(Args*... args);
    virtual vx_data_tree::Type_branchlist* vx_empty();
    virtual vx_data_tree::Type_branchlist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_data_tree::Type_branch*> vx_p_list;

    // vx_listbranch()
    virtual std::vector<vx_data_tree::Type_branch*> vx_listbranch();
    // vx_branch(index)
    virtual vx_data_tree::Type_branch* vx_branch(vx_core::Type_int* index);
  };

  // (type leaf)
  class Type_leaf : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_data_tree::Type_leaf* vx_new(Args*... args);
    template<class... Args> vx_data_tree::Type_leaf* vx_copy(Args*... args);
    virtual vx_data_tree::Type_leaf* vx_empty();
    virtual vx_data_tree::Type_leaf* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // name()
    vx_core::Type_string* vx_p_name;
    virtual vx_core::Type_string* name();
    // value()
    vx_core::Type_any* vx_p_value;
    virtual vx_core::Type_any* value();
  };

  // (type leaflist)
  class Type_leaflist : public virtual vx_core::Type_list {
  public:
    template<class... Args> vx_data_tree::Type_leaflist* vx_new(Args*... args);
    template<class... Args> vx_data_tree::Type_leaflist* vx_copy(Args*... args);
    virtual vx_data_tree::Type_leaflist* vx_empty();
    virtual vx_data_tree::Type_leaflist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_data_tree::Type_leaf*> vx_p_list;

    // vx_listleaf()
    virtual std::vector<vx_data_tree::Type_leaf*> vx_listleaf();
    // vx_leaf(index)
    virtual vx_data_tree::Type_leaf* vx_leaf(vx_core::Type_int* index);
  };

  // (type tree)
  class Type_tree : public virtual vx_core::Type_struct {
  public:
    template<class... Args> vx_data_tree::Type_tree* vx_new(Args*... args);
    template<class... Args> vx_data_tree::Type_tree* vx_copy(Args*... args);
    virtual vx_data_tree::Type_tree* vx_empty();
    virtual vx_data_tree::Type_tree* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // id()
    vx_core::Type_string* vx_p_id;
    virtual vx_core::Type_string* id();
    // name()
    vx_core::Type_string* vx_p_name;
    virtual vx_core::Type_string* name();
    // branch()
    vx_data_tree::Type_branch* vx_p_branch;
    virtual vx_data_tree::Type_branch* branch();
  };

  // (const brancharrow-down)
  class Const_brancharrow_down : public vx_data_tree::Type_brancharrow {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_brancharrow_down* vx_const_new();
  };

  // (const brancharrow-up)
  class Const_brancharrow_up : public vx_data_tree::Type_brancharrow {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_brancharrow_up* vx_const_new();
  };

  // (const brancharrow-updown)
  class Const_brancharrow_updown : public vx_data_tree::Type_brancharrow {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_brancharrow_updown* vx_const_new();
  };

}
