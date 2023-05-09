#pragma once
#include <any>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "../../vx/core.hpp"

namespace vx_data_tree {

  // (type branch)
  class Type_branch : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_data_tree::Type_branch* vx_new(Args*... args);
    template<typename... Args> vx_data_tree::Type_branch* vx_copy(Args*... args);
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
  extern vx_data_tree::Type_branch* e_branch;
  extern vx_data_tree::Type_branch* t_branch;

  // (type brancharrow)
  class Type_brancharrow : public vx_core::Type_any {
  public:
    template<typename... Args> vx_data_tree::Type_brancharrow* vx_new(Args*... args);
    template<typename... Args> vx_data_tree::Type_brancharrow* vx_copy(Args*... args);
    virtual vx_data_tree::Type_brancharrow* vx_empty();
    virtual vx_data_tree::Type_brancharrow* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
  };
  extern vx_data_tree::Type_brancharrow* e_brancharrow;
  extern vx_data_tree::Type_brancharrow* t_brancharrow;

  // (type branchlist)
  class Type_branchlist : public virtual vx_core::Type_list {
  public:
    template<typename... Args> vx_data_tree::Type_branchlist* vx_new(Args*... args);
    template<typename... Args> vx_data_tree::Type_branchlist* vx_copy(Args*... args);
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
  extern vx_data_tree::Type_branchlist* e_branchlist;
  extern vx_data_tree::Type_branchlist* t_branchlist;

  // (type leaf)
  class Type_leaf : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_data_tree::Type_leaf* vx_new(Args*... args);
    template<typename... Args> vx_data_tree::Type_leaf* vx_copy(Args*... args);
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
  extern vx_data_tree::Type_leaf* e_leaf;
  extern vx_data_tree::Type_leaf* t_leaf;

  // (type leaflist)
  class Type_leaflist : public virtual vx_core::Type_list {
  public:
    template<typename... Args> vx_data_tree::Type_leaflist* vx_new(Args*... args);
    template<typename... Args> vx_data_tree::Type_leaflist* vx_copy(Args*... args);
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
  extern vx_data_tree::Type_leaflist* e_leaflist;
  extern vx_data_tree::Type_leaflist* t_leaflist;

  // (type tree)
  class Type_tree : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_data_tree::Type_tree* vx_new(Args*... args);
    template<typename... Args> vx_data_tree::Type_tree* vx_copy(Args*... args);
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
  extern vx_data_tree::Type_tree* e_tree;
  extern vx_data_tree::Type_tree* t_tree;

  // (const brancharrow-down)
  class Const_brancharrow_down : public vx_data_tree::Type_brancharrow {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_brancharrow_down* vx_const_new();
  };
  extern Const_brancharrow_down* c_brancharrow_down;

  // (const brancharrow-up)
  class Const_brancharrow_up : public vx_data_tree::Type_brancharrow {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_brancharrow_up* vx_const_new();
  };
  extern Const_brancharrow_up* c_brancharrow_up;

  // (const brancharrow-updown)
  class Const_brancharrow_updown : public vx_data_tree::Type_brancharrow {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_brancharrow_updown* vx_const_new();
  };
  extern Const_brancharrow_updown* c_brancharrow_updown;

}
