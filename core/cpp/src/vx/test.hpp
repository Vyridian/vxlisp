#pragma once
#include <any>
#include <exception>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "../vx/core.hpp"
#include "../vx/data/file.hpp"
#include "../vx/web/html.hpp"

namespace vx_test {

  // (type testcase)
  class Type_testcase : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_test::Type_testcase* vx_new(Args*... args);
    template<typename... Args> vx_test::Type_testcase* vx_copy(Args*... args);
    virtual vx_test::Type_testcase* vx_empty();
    virtual vx_test::Type_testcase* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // passfail()
    vx_core::Type_boolean* vx_p_passfail;
    virtual vx_core::Type_boolean* passfail();
    // testpkg()
    vx_core::Type_string* vx_p_testpkg;
    virtual vx_core::Type_string* testpkg();
    // casename()
    vx_core::Type_string* vx_p_casename;
    virtual vx_core::Type_string* casename();
    // describelist()
    vx_test::Type_testdescribelist* vx_p_describelist;
    virtual vx_test::Type_testdescribelist* describelist();
  };
  extern vx_test::Type_testcase* e_testcase;
  extern vx_test::Type_testcase* t_testcase;

  // (type testcaselist)
  class Type_testcaselist : public virtual vx_core::Type_list {
  public:
    template<typename... Args> vx_test::Type_testcaselist* vx_new(Args*... args);
    template<typename... Args> vx_test::Type_testcaselist* vx_copy(Args*... args);
    virtual vx_test::Type_testcaselist* vx_empty();
    virtual vx_test::Type_testcaselist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_test::Type_testcase*> vx_p_list;

    // vx_listtestcase()
    virtual std::vector<vx_test::Type_testcase*> vx_listtestcase();
    // vx_testcase(index)
    virtual vx_test::Type_testcase* vx_testcase(vx_core::Type_int* index);
  };
  extern vx_test::Type_testcaselist* e_testcaselist;
  extern vx_test::Type_testcaselist* t_testcaselist;

  // (type testcoveragedetail)
  class Type_testcoveragedetail : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_test::Type_testcoveragedetail* vx_new(Args*... args);
    template<typename... Args> vx_test::Type_testcoveragedetail* vx_copy(Args*... args);
    virtual vx_test::Type_testcoveragedetail* vx_empty();
    virtual vx_test::Type_testcoveragedetail* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // constmap()
    vx_core::Type_intmap* vx_p_constmap;
    virtual vx_core::Type_intmap* constmap();
    // funcmap()
    vx_core::Type_intmap* vx_p_funcmap;
    virtual vx_core::Type_intmap* funcmap();
    // testpkg()
    vx_core::Type_string* vx_p_testpkg;
    virtual vx_core::Type_string* testpkg();
    // typemap()
    vx_core::Type_intmap* vx_p_typemap;
    virtual vx_core::Type_intmap* typemap();
  };
  extern vx_test::Type_testcoveragedetail* e_testcoveragedetail;
  extern vx_test::Type_testcoveragedetail* t_testcoveragedetail;

  // (type testcoveragenums)
  class Type_testcoveragenums : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_test::Type_testcoveragenums* vx_new(Args*... args);
    template<typename... Args> vx_test::Type_testcoveragenums* vx_copy(Args*... args);
    virtual vx_test::Type_testcoveragenums* vx_empty();
    virtual vx_test::Type_testcoveragenums* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // pct()
    vx_core::Type_int* vx_p_pct;
    virtual vx_core::Type_int* pct();
    // testpkg()
    vx_core::Type_string* vx_p_testpkg;
    virtual vx_core::Type_string* testpkg();
    // tests()
    vx_core::Type_int* vx_p_tests;
    virtual vx_core::Type_int* tests();
    // total()
    vx_core::Type_int* vx_p_total;
    virtual vx_core::Type_int* total();
  };
  extern vx_test::Type_testcoveragenums* e_testcoveragenums;
  extern vx_test::Type_testcoveragenums* t_testcoveragenums;

  // (type testcoveragesummary)
  class Type_testcoveragesummary : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_test::Type_testcoveragesummary* vx_new(Args*... args);
    template<typename... Args> vx_test::Type_testcoveragesummary* vx_copy(Args*... args);
    virtual vx_test::Type_testcoveragesummary* vx_empty();
    virtual vx_test::Type_testcoveragesummary* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // bigospacenums()
    vx_test::Type_testcoveragenums* vx_p_bigospacenums;
    virtual vx_test::Type_testcoveragenums* bigospacenums();
    // bigotimenums()
    vx_test::Type_testcoveragenums* vx_p_bigotimenums;
    virtual vx_test::Type_testcoveragenums* bigotimenums();
    // constnums()
    vx_test::Type_testcoveragenums* vx_p_constnums;
    virtual vx_test::Type_testcoveragenums* constnums();
    // docnums()
    vx_test::Type_testcoveragenums* vx_p_docnums;
    virtual vx_test::Type_testcoveragenums* docnums();
    // funcnums()
    vx_test::Type_testcoveragenums* vx_p_funcnums;
    virtual vx_test::Type_testcoveragenums* funcnums();
    // testpkg()
    vx_core::Type_string* vx_p_testpkg;
    virtual vx_core::Type_string* testpkg();
    // totalnums()
    vx_test::Type_testcoveragenums* vx_p_totalnums;
    virtual vx_test::Type_testcoveragenums* totalnums();
    // typenums()
    vx_test::Type_testcoveragenums* vx_p_typenums;
    virtual vx_test::Type_testcoveragenums* typenums();
  };
  extern vx_test::Type_testcoveragesummary* e_testcoveragesummary;
  extern vx_test::Type_testcoveragesummary* t_testcoveragesummary;

  // (type testdescribe)
  class Type_testdescribe : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_test::Type_testdescribe* vx_new(Args*... args);
    template<typename... Args> vx_test::Type_testdescribe* vx_copy(Args*... args);
    virtual vx_test::Type_testdescribe* vx_empty();
    virtual vx_test::Type_testdescribe* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // describename()
    vx_core::Type_string* vx_p_describename;
    virtual vx_core::Type_string* describename();
    // testpkg()
    vx_core::Type_string* vx_p_testpkg;
    virtual vx_core::Type_string* testpkg();
    // testresult()
    vx_test::Type_testresult* vx_p_testresult;
    virtual vx_test::Type_testresult* testresult();
  };
  extern vx_test::Type_testdescribe* e_testdescribe;
  extern vx_test::Type_testdescribe* t_testdescribe;

  // (type testdescribelist)
  class Type_testdescribelist : public virtual vx_core::Type_list {
  public:
    template<typename... Args> vx_test::Type_testdescribelist* vx_new(Args*... args);
    template<typename... Args> vx_test::Type_testdescribelist* vx_copy(Args*... args);
    virtual vx_test::Type_testdescribelist* vx_empty();
    virtual vx_test::Type_testdescribelist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_test::Type_testdescribe*> vx_p_list;

    // vx_listtestdescribe()
    virtual std::vector<vx_test::Type_testdescribe*> vx_listtestdescribe();
    // vx_testdescribe(index)
    virtual vx_test::Type_testdescribe* vx_testdescribe(vx_core::Type_int* index);
  };
  extern vx_test::Type_testdescribelist* e_testdescribelist;
  extern vx_test::Type_testdescribelist* t_testdescribelist;

  // (type testpackage)
  class Type_testpackage : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_test::Type_testpackage* vx_new(Args*... args);
    template<typename... Args> vx_test::Type_testpackage* vx_copy(Args*... args);
    virtual vx_test::Type_testpackage* vx_empty();
    virtual vx_test::Type_testpackage* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // caselist()
    vx_test::Type_testcaselist* vx_p_caselist;
    virtual vx_test::Type_testcaselist* caselist();
    // coveragedetail()
    vx_test::Type_testcoveragedetail* vx_p_coveragedetail;
    virtual vx_test::Type_testcoveragedetail* coveragedetail();
    // coveragesummary()
    vx_test::Type_testcoveragesummary* vx_p_coveragesummary;
    virtual vx_test::Type_testcoveragesummary* coveragesummary();
    // passfail()
    vx_core::Type_boolean* vx_p_passfail;
    virtual vx_core::Type_boolean* passfail();
    // testpkg()
    vx_core::Type_string* vx_p_testpkg;
    virtual vx_core::Type_string* testpkg();
  };
  extern vx_test::Type_testpackage* e_testpackage;
  extern vx_test::Type_testpackage* t_testpackage;

  // (type testpackagelist)
  class Type_testpackagelist : public virtual vx_core::Type_list {
  public:
    template<typename... Args> vx_test::Type_testpackagelist* vx_new(Args*... args);
    template<typename... Args> vx_test::Type_testpackagelist* vx_copy(Args*... args);
    virtual vx_test::Type_testpackagelist* vx_empty();
    virtual vx_test::Type_testpackagelist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_test::Type_testpackage*> vx_p_list;

    // vx_listtestpackage()
    virtual std::vector<vx_test::Type_testpackage*> vx_listtestpackage();
    // vx_testpackage(index)
    virtual vx_test::Type_testpackage* vx_testpackage(vx_core::Type_int* index);
  };
  extern vx_test::Type_testpackagelist* e_testpackagelist;
  extern vx_test::Type_testpackagelist* t_testpackagelist;

  // (type testresult)
  class Type_testresult : public virtual vx_core::Type_struct {
  public:
    template<typename... Args> vx_test::Type_testresult* vx_new(Args*... args);
    template<typename... Args> vx_test::Type_testresult* vx_copy(Args*... args);
    virtual vx_test::Type_testresult* vx_empty();
    virtual vx_test::Type_testresult* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(key)
    virtual vx_core::Type_any* vx_any(vx_core::Type_string* key);
    // vx_map()
    virtual std::map<std::string, vx_core::Type_any*> vx_map();
    // code()
    vx_core::Type_string* vx_p_code;
    virtual vx_core::Type_string* code();
    // passfail()
    vx_core::Type_boolean* vx_p_passfail;
    virtual vx_core::Type_boolean* passfail();
    // expected()
    vx_core::Type_any* vx_p_expected;
    virtual vx_core::Type_any* expected();
    // actual()
    vx_core::Type_any* vx_p_actual;
    virtual vx_core::Type_any* actual();
    // fn-actual()
    vx_core::Func_any_from_func_async* vx_p_fn_actual;
    virtual vx_core::Func_any_from_func_async* fn_actual();
  };
  extern vx_test::Type_testresult* e_testresult;
  extern vx_test::Type_testresult* t_testresult;

  // (type testresultlist)
  class Type_testresultlist : public virtual vx_core::Type_list {
  public:
    template<typename... Args> vx_test::Type_testresultlist* vx_new(Args*... args);
    template<typename... Args> vx_test::Type_testresultlist* vx_copy(Args*... args);
    virtual vx_test::Type_testresultlist* vx_empty();
    virtual vx_test::Type_testresultlist* vx_type();
    virtual vx_core::Type_typedef* vx_typedef();
    // vx_any(index)
    virtual vx_core::Type_any* vx_any(vx_core::Type_int* index);
    // vx_list()
    virtual std::vector<vx_core::Type_any*> vx_list();
    std::vector<vx_test::Type_testresult*> vx_p_list;

    // vx_listtestresult()
    virtual std::vector<vx_test::Type_testresult*> vx_listtestresult();
    // vx_testresult(index)
    virtual vx_test::Type_testresult* vx_testresult(vx_core::Type_int* index);
  };
  extern vx_test::Type_testresultlist* e_testresultlist;
  extern vx_test::Type_testresultlist* t_testresultlist;

  // (const stylesheet-test)
  class Const_stylesheet_test : public vx_web_html::Type_stylesheet {
  public:
    vx_core::Type_constdef* vx_constdef();
    static Const_stylesheet_test* vx_const_new();
  };
  extern Const_stylesheet_test* c_stylesheet_test;

  // (func div<-testcaselist)
  class Func_div_from_testcaselist : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_div_from_testcaselist* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_div_from_testcaselist* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_div_from_testcaselist* vx_empty();
    virtual vx_test::Func_div_from_testcaselist* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_web_html::Type_div* vx_div_from_testcaselist(vx_test::Type_testcaselist* testcaselist);
  };
  extern Func_div_from_testcaselist* e_div_from_testcaselist;
  extern Func_div_from_testcaselist* t_div_from_testcaselist;

  // (func div<-testpackage)
  class Func_div_from_testpackage : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_div_from_testpackage* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_div_from_testpackage* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_div_from_testpackage* vx_empty();
    virtual vx_test::Func_div_from_testpackage* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_web_html::Type_div* vx_div_from_testpackage(vx_test::Type_testpackage* testpackage);
  };
  extern Func_div_from_testpackage* e_div_from_testpackage;
  extern Func_div_from_testpackage* t_div_from_testpackage;

  // (func div<-testpackagelist)
  class Func_div_from_testpackagelist : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_div_from_testpackagelist* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_div_from_testpackagelist* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_div_from_testpackagelist* vx_empty();
    virtual vx_test::Func_div_from_testpackagelist* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_web_html::Type_div* vx_div_from_testpackagelist(vx_test::Type_testpackagelist* testpackagelist);
  };
  extern Func_div_from_testpackagelist* e_div_from_testpackagelist;
  extern Func_div_from_testpackagelist* t_div_from_testpackagelist;

  // (func divchildlist<-testpackagelist)
  class Func_divchildlist_from_testpackagelist : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_divchildlist_from_testpackagelist* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_divchildlist_from_testpackagelist* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_divchildlist_from_testpackagelist* vx_empty();
    virtual vx_test::Func_divchildlist_from_testpackagelist* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_web_html::Type_divchildlist* vx_divchildlist_from_testpackagelist(vx_test::Type_testpackagelist* testpackagelist);
  };
  extern Func_divchildlist_from_testpackagelist* e_divchildlist_from_testpackagelist;
  extern Func_divchildlist_from_testpackagelist* t_divchildlist_from_testpackagelist;

  // (func file-test)
  class Func_file_test : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_file_test* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_file_test* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_file_test* vx_empty();
    virtual vx_test::Func_file_test* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_data_file::Type_file* vx_file_test();
  };
  extern Func_file_test* e_file_test;
  extern Func_file_test* t_file_test;

  // (func file-testhtml)
  class Func_file_testhtml : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_file_testhtml* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_file_testhtml* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_file_testhtml* vx_empty();
    virtual vx_test::Func_file_testhtml* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_data_file::Type_file* vx_file_testhtml();
  };
  extern Func_file_testhtml* e_file_testhtml;
  extern Func_file_testhtml* t_file_testhtml;

  // (func file-testnode)
  class Func_file_testnode : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_file_testnode* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_file_testnode* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_file_testnode* vx_empty();
    virtual vx_test::Func_file_testnode* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_data_file::Type_file* vx_file_testnode();
  };
  extern Func_file_testnode* e_file_testnode;
  extern Func_file_testnode* t_file_testnode;

  // (func html<-divtest)
  class Func_html_from_divtest : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_html_from_divtest* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_html_from_divtest* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_html_from_divtest* vx_empty();
    virtual vx_test::Func_html_from_divtest* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_web_html::Type_html* vx_html_from_divtest(vx_web_html::Type_div* divtest);
  };
  extern Func_html_from_divtest* e_html_from_divtest;
  extern Func_html_from_divtest* t_html_from_divtest;

  // (func p<-passfail)
  class Func_p_from_passfail : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_p_from_passfail* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_p_from_passfail* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_p_from_passfail* vx_empty();
    virtual vx_test::Func_p_from_passfail* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_web_html::Type_p* vx_p_from_passfail(vx_core::Type_boolean* passfail);
  };
  extern Func_p_from_passfail* e_p_from_passfail;
  extern Func_p_from_passfail* t_p_from_passfail;

  // (func p<-testcoveragenums)
  class Func_p_from_testcoveragenums : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_p_from_testcoveragenums* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_p_from_testcoveragenums* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_p_from_testcoveragenums* vx_empty();
    virtual vx_test::Func_p_from_testcoveragenums* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_web_html::Type_p* vx_p_from_testcoveragenums(vx_test::Type_testcoveragenums* nums);
  };
  extern Func_p_from_testcoveragenums* e_p_from_testcoveragenums;
  extern Func_p_from_testcoveragenums* t_p_from_testcoveragenums;

  // (func resolve-testcase)
  class Func_resolve_testcase : public vx_core::Func_any_from_any_async, public virtual vx_core::Type_replfunc_async {
  public:
    template<typename... Args> vx_test::Func_resolve_testcase* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_resolve_testcase* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_resolve_testcase* vx_empty();
    virtual vx_test::Func_resolve_testcase* vx_type();
    virtual vx_core::Func_any_from_any_async* fn_new(vx_core::Func_any_from_any_async::IFn fn);
    template <class T, class U> vx_core::Async<T*>* f_any_from_any_async(T* generic_any_1, U* value);
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Async<vx_test::Type_testcase*>* vx_resolve_testcase(vx_test::Type_testcase* testcase);
  };
  extern Func_resolve_testcase* e_resolve_testcase;
  extern Func_resolve_testcase* t_resolve_testcase;

  // (func resolve-testcaselist)
  class Func_resolve_testcaselist : public vx_core::Func_any_from_any_async, public virtual vx_core::Type_replfunc_async {
  public:
    template<typename... Args> vx_test::Func_resolve_testcaselist* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_resolve_testcaselist* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_resolve_testcaselist* vx_empty();
    virtual vx_test::Func_resolve_testcaselist* vx_type();
    virtual vx_core::Func_any_from_any_async* fn_new(vx_core::Func_any_from_any_async::IFn fn);
    template <class T, class U> vx_core::Async<T*>* f_any_from_any_async(T* generic_any_1, U* value);
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Async<vx_test::Type_testcaselist*>* vx_resolve_testcaselist(vx_test::Type_testcaselist* testcaselist);
  };
  extern Func_resolve_testcaselist* e_resolve_testcaselist;
  extern Func_resolve_testcaselist* t_resolve_testcaselist;

  // (func resolve-testdescribe)
  class Func_resolve_testdescribe : public vx_core::Func_any_from_any_async, public virtual vx_core::Type_replfunc_async {
  public:
    template<typename... Args> vx_test::Func_resolve_testdescribe* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_resolve_testdescribe* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_resolve_testdescribe* vx_empty();
    virtual vx_test::Func_resolve_testdescribe* vx_type();
    virtual vx_core::Func_any_from_any_async* fn_new(vx_core::Func_any_from_any_async::IFn fn);
    template <class T, class U> vx_core::Async<T*>* f_any_from_any_async(T* generic_any_1, U* value);
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Async<vx_test::Type_testdescribe*>* vx_resolve_testdescribe(vx_test::Type_testdescribe* testdescribe);
  };
  extern Func_resolve_testdescribe* e_resolve_testdescribe;
  extern Func_resolve_testdescribe* t_resolve_testdescribe;

  // (func resolve-testdescribelist)
  class Func_resolve_testdescribelist : public vx_core::Func_any_from_any_async, public virtual vx_core::Type_replfunc_async {
  public:
    template<typename... Args> vx_test::Func_resolve_testdescribelist* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_resolve_testdescribelist* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_resolve_testdescribelist* vx_empty();
    virtual vx_test::Func_resolve_testdescribelist* vx_type();
    virtual vx_core::Func_any_from_any_async* fn_new(vx_core::Func_any_from_any_async::IFn fn);
    template <class T, class U> vx_core::Async<T*>* f_any_from_any_async(T* generic_any_1, U* value);
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Async<vx_test::Type_testdescribelist*>* vx_resolve_testdescribelist(vx_test::Type_testdescribelist* testdescribelist);
  };
  extern Func_resolve_testdescribelist* e_resolve_testdescribelist;
  extern Func_resolve_testdescribelist* t_resolve_testdescribelist;

  // (func resolve-testpackage)
  class Func_resolve_testpackage : public vx_core::Func_any_from_any_async, public virtual vx_core::Type_replfunc_async {
  public:
    template<typename... Args> vx_test::Func_resolve_testpackage* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_resolve_testpackage* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_resolve_testpackage* vx_empty();
    virtual vx_test::Func_resolve_testpackage* vx_type();
    virtual vx_core::Func_any_from_any_async* fn_new(vx_core::Func_any_from_any_async::IFn fn);
    template <class T, class U> vx_core::Async<T*>* f_any_from_any_async(T* generic_any_1, U* value);
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Async<vx_test::Type_testpackage*>* vx_resolve_testpackage(vx_test::Type_testpackage* testpackage);
  };
  extern Func_resolve_testpackage* e_resolve_testpackage;
  extern Func_resolve_testpackage* t_resolve_testpackage;

  // (func resolve-testpackagelist)
  class Func_resolve_testpackagelist : public vx_core::Func_any_from_any_async, public virtual vx_core::Type_replfunc_async {
  public:
    template<typename... Args> vx_test::Func_resolve_testpackagelist* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_resolve_testpackagelist* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_resolve_testpackagelist* vx_empty();
    virtual vx_test::Func_resolve_testpackagelist* vx_type();
    virtual vx_core::Func_any_from_any_async* fn_new(vx_core::Func_any_from_any_async::IFn fn);
    template <class T, class U> vx_core::Async<T*>* f_any_from_any_async(T* generic_any_1, U* value);
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Async<vx_test::Type_testpackagelist*>* vx_resolve_testpackagelist(vx_test::Type_testpackagelist* testpackagelist);
  };
  extern Func_resolve_testpackagelist* e_resolve_testpackagelist;
  extern Func_resolve_testpackagelist* t_resolve_testpackagelist;

  // (func resolve-testresult)
  class Func_resolve_testresult : public vx_core::Func_any_from_any_async, public virtual vx_core::Type_replfunc_async {
  public:
    template<typename... Args> vx_test::Func_resolve_testresult* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_resolve_testresult* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_resolve_testresult* vx_empty();
    virtual vx_test::Func_resolve_testresult* vx_type();
    virtual vx_core::Func_any_from_any_async* fn_new(vx_core::Func_any_from_any_async::IFn fn);
    template <class T, class U> vx_core::Async<T*>* f_any_from_any_async(T* generic_any_1, U* value);
    virtual vx_core::Async<vx_core::Type_any*>* vx_repl(vx_core::Type_anylist* arglist);
    vx_core::Async<vx_test::Type_testresult*>* vx_resolve_testresult(vx_test::Type_testresult* testresult);
  };
  extern Func_resolve_testresult* e_resolve_testresult;
  extern Func_resolve_testresult* t_resolve_testresult;

  // (func test)
  class Func_test : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_test* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_test* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_test* vx_empty();
    virtual vx_test::Func_test* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_test::Type_testresult* vx_test(vx_core::Type_any* expected, vx_core::Type_any* actual, vx_core::Type_context* context);
  };
  extern Func_test* e_test;
  extern Func_test* t_test;

  // (func test)
  class Func_test_1 : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_test_1* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_test_1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_test_1* vx_empty();
    virtual vx_test::Func_test_1* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_test::Type_testresult* vx_test_1(vx_core::Type_any* expected, vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context);
  };
  extern Func_test_1* e_test_1;
  extern Func_test_1* t_test_1;

  // (func test-false)
  class Func_test_false : public vx_core::Func_any_from_any_context, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_test_false* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_test_false* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_test_false* vx_empty();
    virtual vx_test::Func_test_false* vx_type();
    virtual vx_core::Func_any_from_any_context* fn_new(vx_core::Func_any_from_any_context::IFn fn);
    template <class T, class U> T* f_any_from_any_context(T* generic_any_1, U* value, vx_core::Type_context* context);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_test::Type_testresult* vx_test_false(vx_core::Type_any* actual, vx_core::Type_context* context);
  };
  extern Func_test_false* e_test_false;
  extern Func_test_false* t_test_false;

  // (func test-false)
  class Func_test_false_1 : public vx_core::Func_any_from_any_context, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_test_false_1* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_test_false_1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_test_false_1* vx_empty();
    virtual vx_test::Func_test_false_1* vx_type();
    virtual vx_core::Func_any_from_any_context* fn_new(vx_core::Func_any_from_any_context::IFn fn);
    template <class T, class U> T* f_any_from_any_context(T* generic_any_1, U* value, vx_core::Type_context* context);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_test::Type_testresult* vx_test_false_1(vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context);
  };
  extern Func_test_false_1* e_test_false_1;
  extern Func_test_false_1* t_test_false_1;

  // (func test-gt)
  class Func_test_gt : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_test_gt* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_test_gt* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_test_gt* vx_empty();
    virtual vx_test::Func_test_gt* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_test::Type_testresult* vx_test_gt(vx_core::Type_any* expected, vx_core::Type_any* actual, vx_core::Type_context* context);
  };
  extern Func_test_gt* e_test_gt;
  extern Func_test_gt* t_test_gt;

  // (func test-gt)
  class Func_test_gt_1 : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_test_gt_1* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_test_gt_1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_test_gt_1* vx_empty();
    virtual vx_test::Func_test_gt_1* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_test::Type_testresult* vx_test_gt_1(vx_core::Type_any* expected, vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context);
  };
  extern Func_test_gt_1* e_test_gt_1;
  extern Func_test_gt_1* t_test_gt_1;

  // (func test-ne)
  class Func_test_ne : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_test_ne* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_test_ne* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_test_ne* vx_empty();
    virtual vx_test::Func_test_ne* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_test::Type_testresult* vx_test_ne(vx_core::Type_any* expected, vx_core::Type_any* actual, vx_core::Type_context* context);
  };
  extern Func_test_ne* e_test_ne;
  extern Func_test_ne* t_test_ne;

  // (func test-ne)
  class Func_test_ne_1 : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_test_ne_1* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_test_ne_1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_test_ne_1* vx_empty();
    virtual vx_test::Func_test_ne_1* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_test::Type_testresult* vx_test_ne_1(vx_core::Type_any* expected, vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context);
  };
  extern Func_test_ne_1* e_test_ne_1;
  extern Func_test_ne_1* t_test_ne_1;

  // (func test-string)
  class Func_test_string : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_test_string* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_test_string* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_test_string* vx_empty();
    virtual vx_test::Func_test_string* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_test::Type_testresult* vx_test_string(vx_core::Type_any* expected, vx_core::Type_any* actual, vx_core::Type_context* context);
  };
  extern Func_test_string* e_test_string;
  extern Func_test_string* t_test_string;

  // (func test-string)
  class Func_test_string_1 : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_test_string_1* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_test_string_1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_test_string_1* vx_empty();
    virtual vx_test::Func_test_string_1* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_test::Type_testresult* vx_test_string_1(vx_core::Type_any* expected, vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context);
  };
  extern Func_test_string_1* e_test_string_1;
  extern Func_test_string_1* t_test_string_1;

  // (func test-true)
  class Func_test_true : public vx_core::Func_any_from_any_context, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_test_true* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_test_true* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_test_true* vx_empty();
    virtual vx_test::Func_test_true* vx_type();
    virtual vx_core::Func_any_from_any_context* fn_new(vx_core::Func_any_from_any_context::IFn fn);
    template <class T, class U> T* f_any_from_any_context(T* generic_any_1, U* value, vx_core::Type_context* context);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_test::Type_testresult* vx_test_true(vx_core::Type_any* actual, vx_core::Type_context* context);
  };
  extern Func_test_true* e_test_true;
  extern Func_test_true* t_test_true;

  // (func test-true)
  class Func_test_true_1 : public vx_core::Func_any_from_any_context, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_test_true_1* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_test_true_1* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_test_true_1* vx_empty();
    virtual vx_test::Func_test_true_1* vx_type();
    virtual vx_core::Func_any_from_any_context* fn_new(vx_core::Func_any_from_any_context::IFn fn);
    template <class T, class U> T* f_any_from_any_context(T* generic_any_1, U* value, vx_core::Type_context* context);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_test::Type_testresult* vx_test_true_1(vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context);
  };
  extern Func_test_true_1* e_test_true_1;
  extern Func_test_true_1* t_test_true_1;

  // (func tr<-testdescribe-casename)
  class Func_tr_from_testdescribe_casename : public vx_core::Type_func, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_tr_from_testdescribe_casename* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_tr_from_testdescribe_casename* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_tr_from_testdescribe_casename* vx_empty();
    virtual vx_test::Func_tr_from_testdescribe_casename* vx_type();
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_web_html::Type_tr* vx_tr_from_testdescribe_casename(vx_test::Type_testdescribe* testdescribe, vx_core::Type_string* casename);
  };
  extern Func_tr_from_testdescribe_casename* e_tr_from_testdescribe_casename;
  extern Func_tr_from_testdescribe_casename* t_tr_from_testdescribe_casename;

  // (func trlist<-testcase)
  class Func_trlist_from_testcase : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_trlist_from_testcase* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_trlist_from_testcase* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_trlist_from_testcase* vx_empty();
    virtual vx_test::Func_trlist_from_testcase* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_web_html::Type_trlist* vx_trlist_from_testcase(vx_test::Type_testcase* testcase);
  };
  extern Func_trlist_from_testcase* e_trlist_from_testcase;
  extern Func_trlist_from_testcase* t_trlist_from_testcase;

  // (func trlist<-testcaselist)
  class Func_trlist_from_testcaselist : public vx_core::Func_any_from_any, public virtual vx_core::Type_replfunc {
  public:
    template<typename... Args> vx_test::Func_trlist_from_testcaselist* vx_new(Args*... args);
    template<typename... Args> vx_test::Func_trlist_from_testcaselist* vx_copy(Args*... args);
    virtual vx_core::Type_funcdef* vx_funcdef();
    virtual vx_core::Type_typedef* vx_typedef();
    virtual vx_test::Func_trlist_from_testcaselist* vx_empty();
    virtual vx_test::Func_trlist_from_testcaselist* vx_type();
    virtual vx_core::Func_any_from_any* fn_new(vx_core::Func_any_from_any::IFn fn);
    template <class T, class U> T* f_any_from_any(T* generic_any_1, U* value);
    virtual vx_core::Type_any* vx_repl(vx_core::Type_anylist* arglist);
    vx_web_html::Type_trlist* vx_trlist_from_testcaselist(vx_test::Type_testcaselist* testcaselist);
  };
  extern Func_trlist_from_testcaselist* e_trlist_from_testcaselist;
  extern Func_trlist_from_testcaselist* t_trlist_from_testcaselist;

  // (func div<-testcaselist)
  vx_web_html::Type_div* f_div_from_testcaselist(vx_test::Type_testcaselist* testcaselist);

  // (func div<-testpackage)
  vx_web_html::Type_div* f_div_from_testpackage(vx_test::Type_testpackage* testpackage);

  // (func div<-testpackagelist)
  vx_web_html::Type_div* f_div_from_testpackagelist(vx_test::Type_testpackagelist* testpackagelist);

  // (func divchildlist<-testpackagelist)
  vx_web_html::Type_divchildlist* f_divchildlist_from_testpackagelist(vx_test::Type_testpackagelist* testpackagelist);

  // (func file-test)
  vx_data_file::Type_file* f_file_test();

  // (func file-testhtml)
  vx_data_file::Type_file* f_file_testhtml();

  // (func file-testnode)
  vx_data_file::Type_file* f_file_testnode();

  // (func html<-divtest)
  vx_web_html::Type_html* f_html_from_divtest(vx_web_html::Type_div* divtest);

  // (func p<-passfail)
  vx_web_html::Type_p* f_p_from_passfail(vx_core::Type_boolean* passfail);

  // (func p<-testcoveragenums)
  vx_web_html::Type_p* f_p_from_testcoveragenums(vx_test::Type_testcoveragenums* nums);

  // (func resolve-testcase)
  vx_core::Async<vx_test::Type_testcase*>* f_resolve_testcase(vx_test::Type_testcase* testcase);

  // (func resolve-testcaselist)
  vx_core::Async<vx_test::Type_testcaselist*>* f_resolve_testcaselist(vx_test::Type_testcaselist* testcaselist);

  // (func resolve-testdescribe)
  vx_core::Async<vx_test::Type_testdescribe*>* f_resolve_testdescribe(vx_test::Type_testdescribe* testdescribe);

  // (func resolve-testdescribelist)
  vx_core::Async<vx_test::Type_testdescribelist*>* f_resolve_testdescribelist(vx_test::Type_testdescribelist* testdescribelist);

  // (func resolve-testpackage)
  vx_core::Async<vx_test::Type_testpackage*>* f_resolve_testpackage(vx_test::Type_testpackage* testpackage);

  // (func resolve-testpackagelist)
  vx_core::Async<vx_test::Type_testpackagelist*>* f_resolve_testpackagelist(vx_test::Type_testpackagelist* testpackagelist);

  // (func resolve-testresult)
  vx_core::Async<vx_test::Type_testresult*>* f_resolve_testresult(vx_test::Type_testresult* testresult);

  // (func test)
  vx_test::Type_testresult* f_test(vx_core::Type_any* expected, vx_core::Type_any* actual, vx_core::Type_context* context);

  // (func test)
  vx_test::Type_testresult* f_test_1(vx_core::Type_any* expected, vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context);

  // (func test-false)
  vx_test::Type_testresult* f_test_false(vx_core::Type_any* actual, vx_core::Type_context* context);

  // (func test-false)
  vx_test::Type_testresult* f_test_false_1(vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context);

  // (func test-gt)
  vx_test::Type_testresult* f_test_gt(vx_core::Type_any* expected, vx_core::Type_any* actual, vx_core::Type_context* context);

  // (func test-gt)
  vx_test::Type_testresult* f_test_gt_1(vx_core::Type_any* expected, vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context);

  // (func test-ne)
  vx_test::Type_testresult* f_test_ne(vx_core::Type_any* expected, vx_core::Type_any* actual, vx_core::Type_context* context);

  // (func test-ne)
  vx_test::Type_testresult* f_test_ne_1(vx_core::Type_any* expected, vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context);

  // (func test-string)
  vx_test::Type_testresult* f_test_string(vx_core::Type_any* expected, vx_core::Type_any* actual, vx_core::Type_context* context);

  // (func test-string)
  vx_test::Type_testresult* f_test_string_1(vx_core::Type_any* expected, vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context);

  // (func test-true)
  vx_test::Type_testresult* f_test_true(vx_core::Type_any* actual, vx_core::Type_context* context);

  // (func test-true)
  vx_test::Type_testresult* f_test_true_1(vx_core::Func_any_from_func_async* fn_actual, vx_core::Type_context* context);

  // (func tr<-testdescribe-casename)
  vx_web_html::Type_tr* f_tr_from_testdescribe_casename(vx_test::Type_testdescribe* testdescribe, vx_core::Type_string* casename);

  // (func trlist<-testcase)
  vx_web_html::Type_trlist* f_trlist_from_testcase(vx_test::Type_testcase* testcase);

  // (func trlist<-testcaselist)
  vx_web_html::Type_trlist* f_trlist_from_testcaselist(vx_test::Type_testcaselist* testcaselist);

}
