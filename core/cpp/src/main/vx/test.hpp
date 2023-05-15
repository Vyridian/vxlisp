#pragma once
#include <exception>
#include <memory>
#include <set>
#include <string>
#include <vector>
#include "../vx/core.hpp"
#include "../vx/data/file.hpp"
#include "../vx/web/html.hpp"

namespace vx_test {

  // forward declarations
  class Class_testcase;
  typedef std::shared_ptr<Class_testcase> Type_testcase;
  extern Type_testcase e_testcase;
  extern Type_testcase t_testcase;
  class Class_testcaselist;
  typedef std::shared_ptr<Class_testcaselist> Type_testcaselist;
  extern Type_testcaselist e_testcaselist;
  extern Type_testcaselist t_testcaselist;
  class Class_testcoveragedetail;
  typedef std::shared_ptr<Class_testcoveragedetail> Type_testcoveragedetail;
  extern Type_testcoveragedetail e_testcoveragedetail;
  extern Type_testcoveragedetail t_testcoveragedetail;
  class Class_testcoveragenums;
  typedef std::shared_ptr<Class_testcoveragenums> Type_testcoveragenums;
  extern Type_testcoveragenums e_testcoveragenums;
  extern Type_testcoveragenums t_testcoveragenums;
  class Class_testcoveragesummary;
  typedef std::shared_ptr<Class_testcoveragesummary> Type_testcoveragesummary;
  extern Type_testcoveragesummary e_testcoveragesummary;
  extern Type_testcoveragesummary t_testcoveragesummary;
  class Class_testdescribe;
  typedef std::shared_ptr<Class_testdescribe> Type_testdescribe;
  extern Type_testdescribe e_testdescribe;
  extern Type_testdescribe t_testdescribe;
  class Class_testdescribelist;
  typedef std::shared_ptr<Class_testdescribelist> Type_testdescribelist;
  extern Type_testdescribelist e_testdescribelist;
  extern Type_testdescribelist t_testdescribelist;
  class Class_testpackage;
  typedef std::shared_ptr<Class_testpackage> Type_testpackage;
  extern Type_testpackage e_testpackage;
  extern Type_testpackage t_testpackage;
  class Class_testpackagelist;
  typedef std::shared_ptr<Class_testpackagelist> Type_testpackagelist;
  extern Type_testpackagelist e_testpackagelist;
  extern Type_testpackagelist t_testpackagelist;
  class Class_testresult;
  typedef std::shared_ptr<Class_testresult> Type_testresult;
  extern Type_testresult e_testresult;
  extern Type_testresult t_testresult;
  class Class_testresultlist;
  typedef std::shared_ptr<Class_testresultlist> Type_testresultlist;
  extern Type_testresultlist e_testresultlist;
  extern Type_testresultlist t_testresultlist;
  class Class_stylesheet_test;
  typedef std::shared_ptr<Class_stylesheet_test> Const_stylesheet_test;
  extern Const_stylesheet_test c_stylesheet_test;
  class Class_div_from_testcaselist;
  typedef std::shared_ptr<Class_div_from_testcaselist> Func_div_from_testcaselist;
  extern Func_div_from_testcaselist e_div_from_testcaselist;
  extern Func_div_from_testcaselist t_div_from_testcaselist;
  class Class_div_from_testpackage;
  typedef std::shared_ptr<Class_div_from_testpackage> Func_div_from_testpackage;
  extern Func_div_from_testpackage e_div_from_testpackage;
  extern Func_div_from_testpackage t_div_from_testpackage;
  class Class_div_from_testpackagelist;
  typedef std::shared_ptr<Class_div_from_testpackagelist> Func_div_from_testpackagelist;
  extern Func_div_from_testpackagelist e_div_from_testpackagelist;
  extern Func_div_from_testpackagelist t_div_from_testpackagelist;
  class Class_divchildlist_from_testpackagelist;
  typedef std::shared_ptr<Class_divchildlist_from_testpackagelist> Func_divchildlist_from_testpackagelist;
  extern Func_divchildlist_from_testpackagelist e_divchildlist_from_testpackagelist;
  extern Func_divchildlist_from_testpackagelist t_divchildlist_from_testpackagelist;
  class Class_file_test;
  typedef std::shared_ptr<Class_file_test> Func_file_test;
  extern Func_file_test e_file_test;
  extern Func_file_test t_file_test;
  class Class_file_testhtml;
  typedef std::shared_ptr<Class_file_testhtml> Func_file_testhtml;
  extern Func_file_testhtml e_file_testhtml;
  extern Func_file_testhtml t_file_testhtml;
  class Class_file_testnode;
  typedef std::shared_ptr<Class_file_testnode> Func_file_testnode;
  extern Func_file_testnode e_file_testnode;
  extern Func_file_testnode t_file_testnode;
  class Class_html_from_divtest;
  typedef std::shared_ptr<Class_html_from_divtest> Func_html_from_divtest;
  extern Func_html_from_divtest e_html_from_divtest;
  extern Func_html_from_divtest t_html_from_divtest;
  class Class_p_from_passfail;
  typedef std::shared_ptr<Class_p_from_passfail> Func_p_from_passfail;
  extern Func_p_from_passfail e_p_from_passfail;
  extern Func_p_from_passfail t_p_from_passfail;
  class Class_p_from_testcoveragenums;
  typedef std::shared_ptr<Class_p_from_testcoveragenums> Func_p_from_testcoveragenums;
  extern Func_p_from_testcoveragenums e_p_from_testcoveragenums;
  extern Func_p_from_testcoveragenums t_p_from_testcoveragenums;
  class Class_resolve_testcase;
  typedef std::shared_ptr<Class_resolve_testcase> Func_resolve_testcase;
  extern Func_resolve_testcase e_resolve_testcase;
  extern Func_resolve_testcase t_resolve_testcase;
  class Class_resolve_testcaselist;
  typedef std::shared_ptr<Class_resolve_testcaselist> Func_resolve_testcaselist;
  extern Func_resolve_testcaselist e_resolve_testcaselist;
  extern Func_resolve_testcaselist t_resolve_testcaselist;
  class Class_resolve_testdescribe;
  typedef std::shared_ptr<Class_resolve_testdescribe> Func_resolve_testdescribe;
  extern Func_resolve_testdescribe e_resolve_testdescribe;
  extern Func_resolve_testdescribe t_resolve_testdescribe;
  class Class_resolve_testdescribelist;
  typedef std::shared_ptr<Class_resolve_testdescribelist> Func_resolve_testdescribelist;
  extern Func_resolve_testdescribelist e_resolve_testdescribelist;
  extern Func_resolve_testdescribelist t_resolve_testdescribelist;
  class Class_resolve_testpackage;
  typedef std::shared_ptr<Class_resolve_testpackage> Func_resolve_testpackage;
  extern Func_resolve_testpackage e_resolve_testpackage;
  extern Func_resolve_testpackage t_resolve_testpackage;
  class Class_resolve_testpackagelist;
  typedef std::shared_ptr<Class_resolve_testpackagelist> Func_resolve_testpackagelist;
  extern Func_resolve_testpackagelist e_resolve_testpackagelist;
  extern Func_resolve_testpackagelist t_resolve_testpackagelist;
  class Class_resolve_testresult;
  typedef std::shared_ptr<Class_resolve_testresult> Func_resolve_testresult;
  extern Func_resolve_testresult e_resolve_testresult;
  extern Func_resolve_testresult t_resolve_testresult;
  class Class_test;
  typedef std::shared_ptr<Class_test> Func_test;
  extern Func_test e_test;
  extern Func_test t_test;
  class Class_test_1;
  typedef std::shared_ptr<Class_test_1> Func_test_1;
  extern Func_test_1 e_test_1;
  extern Func_test_1 t_test_1;
  class Class_test_false;
  typedef std::shared_ptr<Class_test_false> Func_test_false;
  extern Func_test_false e_test_false;
  extern Func_test_false t_test_false;
  class Class_test_false_1;
  typedef std::shared_ptr<Class_test_false_1> Func_test_false_1;
  extern Func_test_false_1 e_test_false_1;
  extern Func_test_false_1 t_test_false_1;
  class Class_test_gt;
  typedef std::shared_ptr<Class_test_gt> Func_test_gt;
  extern Func_test_gt e_test_gt;
  extern Func_test_gt t_test_gt;
  class Class_test_gt_1;
  typedef std::shared_ptr<Class_test_gt_1> Func_test_gt_1;
  extern Func_test_gt_1 e_test_gt_1;
  extern Func_test_gt_1 t_test_gt_1;
  class Class_test_ne;
  typedef std::shared_ptr<Class_test_ne> Func_test_ne;
  extern Func_test_ne e_test_ne;
  extern Func_test_ne t_test_ne;
  class Class_test_ne_1;
  typedef std::shared_ptr<Class_test_ne_1> Func_test_ne_1;
  extern Func_test_ne_1 e_test_ne_1;
  extern Func_test_ne_1 t_test_ne_1;
  class Class_test_string;
  typedef std::shared_ptr<Class_test_string> Func_test_string;
  extern Func_test_string e_test_string;
  extern Func_test_string t_test_string;
  class Class_test_string_1;
  typedef std::shared_ptr<Class_test_string_1> Func_test_string_1;
  extern Func_test_string_1 e_test_string_1;
  extern Func_test_string_1 t_test_string_1;
  class Class_test_true;
  typedef std::shared_ptr<Class_test_true> Func_test_true;
  extern Func_test_true e_test_true;
  extern Func_test_true t_test_true;
  class Class_test_true_1;
  typedef std::shared_ptr<Class_test_true_1> Func_test_true_1;
  extern Func_test_true_1 e_test_true_1;
  extern Func_test_true_1 t_test_true_1;
  class Class_tr_from_testdescribe_casename;
  typedef std::shared_ptr<Class_tr_from_testdescribe_casename> Func_tr_from_testdescribe_casename;
  extern Func_tr_from_testdescribe_casename e_tr_from_testdescribe_casename;
  extern Func_tr_from_testdescribe_casename t_tr_from_testdescribe_casename;
  class Class_trlist_from_testcase;
  typedef std::shared_ptr<Class_trlist_from_testcase> Func_trlist_from_testcase;
  extern Func_trlist_from_testcase e_trlist_from_testcase;
  extern Func_trlist_from_testcase t_trlist_from_testcase;
  class Class_trlist_from_testcaselist;
  typedef std::shared_ptr<Class_trlist_from_testcaselist> Func_trlist_from_testcaselist;
  extern Func_trlist_from_testcaselist e_trlist_from_testcaselist;
  extern Func_trlist_from_testcaselist t_trlist_from_testcaselist;


  // (type testcase)
  class Class_testcase : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // passfail()
    vx_core::Type_boolean vx_p_passfail;
    virtual vx_core::Type_boolean passfail();
    // testpkg()
    vx_core::Type_string vx_p_testpkg;
    virtual vx_core::Type_string testpkg();
    // casename()
    vx_core::Type_string vx_p_casename;
    virtual vx_core::Type_string casename();
    // describelist()
    vx_test::Type_testdescribelist vx_p_describelist;
    virtual vx_test::Type_testdescribelist describelist();
  };

  // (type testcaselist)
  class Class_testcaselist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_test::Type_testcase> vx_p_list;

    // vx_listtestcase()
    virtual std::vector<vx_test::Type_testcase> vx_listtestcase();
    // vx_testcase(index)
    virtual vx_test::Type_testcase vx_testcase(vx_core::Type_int index);
  };

  // (type testcoveragedetail)
  class Class_testcoveragedetail : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // constmap()
    vx_core::Type_intmap vx_p_constmap;
    virtual vx_core::Type_intmap constmap();
    // funcmap()
    vx_core::Type_intmap vx_p_funcmap;
    virtual vx_core::Type_intmap funcmap();
    // testpkg()
    vx_core::Type_string vx_p_testpkg;
    virtual vx_core::Type_string testpkg();
    // typemap()
    vx_core::Type_intmap vx_p_typemap;
    virtual vx_core::Type_intmap typemap();
  };

  // (type testcoveragenums)
  class Class_testcoveragenums : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // pct()
    vx_core::Type_int vx_p_pct;
    virtual vx_core::Type_int pct();
    // testpkg()
    vx_core::Type_string vx_p_testpkg;
    virtual vx_core::Type_string testpkg();
    // tests()
    vx_core::Type_int vx_p_tests;
    virtual vx_core::Type_int tests();
    // total()
    vx_core::Type_int vx_p_total;
    virtual vx_core::Type_int total();
  };

  // (type testcoveragesummary)
  class Class_testcoveragesummary : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // bigospacenums()
    vx_test::Type_testcoveragenums vx_p_bigospacenums;
    virtual vx_test::Type_testcoveragenums bigospacenums();
    // bigotimenums()
    vx_test::Type_testcoveragenums vx_p_bigotimenums;
    virtual vx_test::Type_testcoveragenums bigotimenums();
    // constnums()
    vx_test::Type_testcoveragenums vx_p_constnums;
    virtual vx_test::Type_testcoveragenums constnums();
    // docnums()
    vx_test::Type_testcoveragenums vx_p_docnums;
    virtual vx_test::Type_testcoveragenums docnums();
    // funcnums()
    vx_test::Type_testcoveragenums vx_p_funcnums;
    virtual vx_test::Type_testcoveragenums funcnums();
    // testpkg()
    vx_core::Type_string vx_p_testpkg;
    virtual vx_core::Type_string testpkg();
    // totalnums()
    vx_test::Type_testcoveragenums vx_p_totalnums;
    virtual vx_test::Type_testcoveragenums totalnums();
    // typenums()
    vx_test::Type_testcoveragenums vx_p_typenums;
    virtual vx_test::Type_testcoveragenums typenums();
  };

  // (type testdescribe)
  class Class_testdescribe : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // describename()
    vx_core::Type_string vx_p_describename;
    virtual vx_core::Type_string describename();
    // testpkg()
    vx_core::Type_string vx_p_testpkg;
    virtual vx_core::Type_string testpkg();
    // testresult()
    vx_test::Type_testresult vx_p_testresult;
    virtual vx_test::Type_testresult testresult();
  };

  // (type testdescribelist)
  class Class_testdescribelist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_test::Type_testdescribe> vx_p_list;

    // vx_listtestdescribe()
    virtual std::vector<vx_test::Type_testdescribe> vx_listtestdescribe();
    // vx_testdescribe(index)
    virtual vx_test::Type_testdescribe vx_testdescribe(vx_core::Type_int index);
  };

  // (type testpackage)
  class Class_testpackage : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // caselist()
    vx_test::Type_testcaselist vx_p_caselist;
    virtual vx_test::Type_testcaselist caselist();
    // coveragedetail()
    vx_test::Type_testcoveragedetail vx_p_coveragedetail;
    virtual vx_test::Type_testcoveragedetail coveragedetail();
    // coveragesummary()
    vx_test::Type_testcoveragesummary vx_p_coveragesummary;
    virtual vx_test::Type_testcoveragesummary coveragesummary();
    // passfail()
    vx_core::Type_boolean vx_p_passfail;
    virtual vx_core::Type_boolean passfail();
    // testpkg()
    vx_core::Type_string vx_p_testpkg;
    virtual vx_core::Type_string testpkg();
  };

  // (type testpackagelist)
  class Class_testpackagelist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_test::Type_testpackage> vx_p_list;

    // vx_listtestpackage()
    virtual std::vector<vx_test::Type_testpackage> vx_listtestpackage();
    // vx_testpackage(index)
    virtual vx_test::Type_testpackage vx_testpackage(vx_core::Type_int index);
  };

  // (type testresult)
  class Class_testresult : public virtual vx_core::Class_struct {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map();
    // vx_any(key)
    virtual vx_core::Type_any vx_any(vx_core::Type_string key);
    // code()
    vx_core::Type_string vx_p_code;
    virtual vx_core::Type_string code();
    // passfail()
    vx_core::Type_boolean vx_p_passfail;
    virtual vx_core::Type_boolean passfail();
    // expected()
    vx_core::Type_any vx_p_expected;
    virtual vx_core::Type_any expected();
    // actual()
    vx_core::Type_any vx_p_actual;
    virtual vx_core::Type_any actual();
    // fn-actual()
    vx_core::Func_any_from_func_async vx_p_fn_actual;
    virtual vx_core::Func_any_from_func_async fn_actual();
  };

  // (type testresultlist)
  class Class_testresultlist : public virtual vx_core::Class_list {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_typedef vx_typedef() override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    // vx_any(index)
    virtual vx_core::Type_any vx_any(vx_core::Type_int index) override;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() override;
    // vx_new_from_list(T, List<T>)
    template <class T> std::shared_ptr<T> vx_new_from_list(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listany listval) override;
    std::vector<vx_test::Type_testresult> vx_p_list;

    // vx_listtestresult()
    virtual std::vector<vx_test::Type_testresult> vx_listtestresult();
    // vx_testresult(index)
    virtual vx_test::Type_testresult vx_testresult(vx_core::Type_int index);
  };

  // (const stylesheet-test)
  class Class_stylesheet_test : public vx_web_html::Class_stylesheet {
  public:
    vx_core::Type_constdef vx_constdef();
    static vx_test::Const_stylesheet_test vx_const_new();
  };

  // (func div<-testcaselist)
  class Class_div_from_testcaselist : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_web_html::Type_div vx_div_from_testcaselist(vx_test::Type_testcaselist testcaselist);
  };

  // (func div<-testpackage)
  class Class_div_from_testpackage : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_web_html::Type_div vx_div_from_testpackage(vx_test::Type_testpackage testpackage);
  };

  // (func div<-testpackagelist)
  class Class_div_from_testpackagelist : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_web_html::Type_div vx_div_from_testpackagelist(vx_test::Type_testpackagelist testpackagelist);
  };

  // (func divchildlist<-testpackagelist)
  class Class_divchildlist_from_testpackagelist : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_web_html::Type_divchildlist vx_divchildlist_from_testpackagelist(vx_test::Type_testpackagelist testpackagelist);
  };

  // (func file-test)
  class Class_file_test : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_data_file::Type_file vx_file_test();
  };

  // (func file-testhtml)
  class Class_file_testhtml : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_data_file::Type_file vx_file_testhtml();
  };

  // (func file-testnode)
  class Class_file_testnode : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_data_file::Type_file vx_file_testnode();
  };

  // (func html<-divtest)
  class Class_html_from_divtest : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_web_html::Type_html vx_html_from_divtest(vx_web_html::Type_div divtest);
  };

  // (func p<-passfail)
  class Class_p_from_passfail : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_web_html::Type_p vx_p_from_passfail(vx_core::Type_boolean passfail);
  };

  // (func p<-testcoveragenums)
  class Class_p_from_testcoveragenums : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_web_html::Type_p vx_p_from_testcoveragenums(vx_test::Type_testcoveragenums nums);
  };

  // (func resolve-testcase)
  class Class_resolve_testcase : public vx_core::Class_any_from_any_async, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_async fn_new(vx_core::Class_any_from_any_async::IFn fn);
    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    std::shared_ptr<vx_core::Async<vx_test::Type_testcase>> vx_resolve_testcase(vx_test::Type_testcase testcase);
  };

  // (func resolve-testcaselist)
  class Class_resolve_testcaselist : public vx_core::Class_any_from_any_async, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_async fn_new(vx_core::Class_any_from_any_async::IFn fn);
    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    std::shared_ptr<vx_core::Async<vx_test::Type_testcaselist>> vx_resolve_testcaselist(vx_test::Type_testcaselist testcaselist);
  };

  // (func resolve-testdescribe)
  class Class_resolve_testdescribe : public vx_core::Class_any_from_any_async, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_async fn_new(vx_core::Class_any_from_any_async::IFn fn);
    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    std::shared_ptr<vx_core::Async<vx_test::Type_testdescribe>> vx_resolve_testdescribe(vx_test::Type_testdescribe testdescribe);
  };

  // (func resolve-testdescribelist)
  class Class_resolve_testdescribelist : public vx_core::Class_any_from_any_async, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_async fn_new(vx_core::Class_any_from_any_async::IFn fn);
    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    std::shared_ptr<vx_core::Async<vx_test::Type_testdescribelist>> vx_resolve_testdescribelist(vx_test::Type_testdescribelist testdescribelist);
  };

  // (func resolve-testpackage)
  class Class_resolve_testpackage : public vx_core::Class_any_from_any_async, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_async fn_new(vx_core::Class_any_from_any_async::IFn fn);
    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    std::shared_ptr<vx_core::Async<vx_test::Type_testpackage>> vx_resolve_testpackage(vx_test::Type_testpackage testpackage);
  };

  // (func resolve-testpackagelist)
  class Class_resolve_testpackagelist : public vx_core::Class_any_from_any_async, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_async fn_new(vx_core::Class_any_from_any_async::IFn fn);
    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    std::shared_ptr<vx_core::Async<vx_test::Type_testpackagelist>> vx_resolve_testpackagelist(vx_test::Type_testpackagelist testpackagelist);
  };

  // (func resolve-testresult)
  class Class_resolve_testresult : public vx_core::Class_any_from_any_async, public virtual vx_core::Class_replfunc_async {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_async fn_new(vx_core::Class_any_from_any_async::IFn fn);
    template <class T, class U> std::shared_ptr<vx_core::Async<std::shared_ptr<T>>> f_any_from_any_async(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual std::shared_ptr<vx_core::Async<vx_core::Type_any>> vx_repl(vx_core::Type_anylist arglist);
    std::shared_ptr<vx_core::Async<vx_test::Type_testresult>> vx_resolve_testresult(vx_test::Type_testresult testresult);
  };

  // (func test)
  class Class_test : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_test::Type_testresult vx_test(vx_core::Type_any expected, vx_core::Type_any actual, vx_core::Type_context context);
  };

  // (func test)
  class Class_test_1 : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_test::Type_testresult vx_test_1(vx_core::Type_any expected, vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context);
  };

  // (func test-false)
  class Class_test_false : public vx_core::Class_any_from_any_context, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_context fn_new(vx_core::Class_any_from_any_context::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any_context(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_test::Type_testresult vx_test_false(vx_core::Type_any actual, vx_core::Type_context context);
  };

  // (func test-false)
  class Class_test_false_1 : public vx_core::Class_any_from_any_context, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_context fn_new(vx_core::Class_any_from_any_context::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any_context(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_test::Type_testresult vx_test_false_1(vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context);
  };

  // (func test-gt)
  class Class_test_gt : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_test::Type_testresult vx_test_gt(vx_core::Type_any expected, vx_core::Type_any actual, vx_core::Type_context context);
  };

  // (func test-gt)
  class Class_test_gt_1 : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_test::Type_testresult vx_test_gt_1(vx_core::Type_any expected, vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context);
  };

  // (func test-ne)
  class Class_test_ne : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_test::Type_testresult vx_test_ne(vx_core::Type_any expected, vx_core::Type_any actual, vx_core::Type_context context);
  };

  // (func test-ne)
  class Class_test_ne_1 : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_test::Type_testresult vx_test_ne_1(vx_core::Type_any expected, vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context);
  };

  // (func test-string)
  class Class_test_string : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_test::Type_testresult vx_test_string(vx_core::Type_any expected, vx_core::Type_any actual, vx_core::Type_context context);
  };

  // (func test-string)
  class Class_test_string_1 : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_test::Type_testresult vx_test_string_1(vx_core::Type_any expected, vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context);
  };

  // (func test-true)
  class Class_test_true : public vx_core::Class_any_from_any_context, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_context fn_new(vx_core::Class_any_from_any_context::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any_context(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_test::Type_testresult vx_test_true(vx_core::Type_any actual, vx_core::Type_context context);
  };

  // (func test-true)
  class Class_test_true_1 : public vx_core::Class_any_from_any_context, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any_context fn_new(vx_core::Class_any_from_any_context::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any_context(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value, vx_core::Type_context context);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_test::Type_testresult vx_test_true_1(vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context);
  };

  // (func tr<-testdescribe-casename)
  class Class_tr_from_testdescribe_casename : public vx_core::Class_func, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_web_html::Type_tr vx_tr_from_testdescribe_casename(vx_test::Type_testdescribe testdescribe, vx_core::Type_string casename);
  };

  // (func trlist<-testcase)
  class Class_trlist_from_testcase : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_web_html::Type_trlist vx_trlist_from_testcase(vx_test::Type_testcase testcase);
  };

  // (func trlist<-testcaselist)
  class Class_trlist_from_testcaselist : public vx_core::Class_any_from_any, public virtual vx_core::Class_replfunc {
  public:
    template <class T> std::shared_ptr<T> vx_new(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    template <class T> std::shared_ptr<T> vx_copy(std::shared_ptr<T> generic_any_1, vx_core::vx_Type_listarg vals);
    virtual vx_core::Type_funcdef vx_funcdef();
    virtual vx_core::Type_typedef vx_typedef() override;
    template <class T> std::shared_ptr<T> vx_empty(std::shared_ptr<T> val);
    template <class T> std::shared_ptr<T> vx_type(std::shared_ptr<T> val);
    virtual vx_core::Func_any_from_any fn_new(vx_core::Class_any_from_any::IFn fn);
    template <class T, class U> std::shared_ptr<T> f_any_from_any(std::shared_ptr<T> generic_any_1, std::shared_ptr<U> value);
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist);
    vx_web_html::Type_trlist vx_trlist_from_testcaselist(vx_test::Type_testcaselist testcaselist);
  };

  // (func div<-testcaselist)
  vx_web_html::Type_div f_div_from_testcaselist(vx_test::Type_testcaselist testcaselist);

  // (func div<-testpackage)
  vx_web_html::Type_div f_div_from_testpackage(vx_test::Type_testpackage testpackage);

  // (func div<-testpackagelist)
  vx_web_html::Type_div f_div_from_testpackagelist(vx_test::Type_testpackagelist testpackagelist);

  // (func divchildlist<-testpackagelist)
  vx_web_html::Type_divchildlist f_divchildlist_from_testpackagelist(vx_test::Type_testpackagelist testpackagelist);

  // (func file-test)
  vx_data_file::Type_file f_file_test();

  // (func file-testhtml)
  vx_data_file::Type_file f_file_testhtml();

  // (func file-testnode)
  vx_data_file::Type_file f_file_testnode();

  // (func html<-divtest)
  vx_web_html::Type_html f_html_from_divtest(vx_web_html::Type_div divtest);

  // (func p<-passfail)
  vx_web_html::Type_p f_p_from_passfail(vx_core::Type_boolean passfail);

  // (func p<-testcoveragenums)
  vx_web_html::Type_p f_p_from_testcoveragenums(vx_test::Type_testcoveragenums nums);

  // (func resolve-testcase)
  std::shared_ptr<vx_core::Async<vx_test::Type_testcase>> f_resolve_testcase(vx_test::Type_testcase testcase);

  // (func resolve-testcaselist)
  std::shared_ptr<vx_core::Async<vx_test::Type_testcaselist>> f_resolve_testcaselist(vx_test::Type_testcaselist testcaselist);

  // (func resolve-testdescribe)
  std::shared_ptr<vx_core::Async<vx_test::Type_testdescribe>> f_resolve_testdescribe(vx_test::Type_testdescribe testdescribe);

  // (func resolve-testdescribelist)
  std::shared_ptr<vx_core::Async<vx_test::Type_testdescribelist>> f_resolve_testdescribelist(vx_test::Type_testdescribelist testdescribelist);

  // (func resolve-testpackage)
  std::shared_ptr<vx_core::Async<vx_test::Type_testpackage>> f_resolve_testpackage(vx_test::Type_testpackage testpackage);

  // (func resolve-testpackagelist)
  std::shared_ptr<vx_core::Async<vx_test::Type_testpackagelist>> f_resolve_testpackagelist(vx_test::Type_testpackagelist testpackagelist);

  // (func resolve-testresult)
  std::shared_ptr<vx_core::Async<vx_test::Type_testresult>> f_resolve_testresult(vx_test::Type_testresult testresult);

  // (func test)
  vx_test::Type_testresult f_test(vx_core::Type_any expected, vx_core::Type_any actual, vx_core::Type_context context);

  // (func test)
  vx_test::Type_testresult f_test_1(vx_core::Type_any expected, vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context);

  // (func test-false)
  vx_test::Type_testresult f_test_false(vx_core::Type_any actual, vx_core::Type_context context);

  // (func test-false)
  vx_test::Type_testresult f_test_false_1(vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context);

  // (func test-gt)
  vx_test::Type_testresult f_test_gt(vx_core::Type_any expected, vx_core::Type_any actual, vx_core::Type_context context);

  // (func test-gt)
  vx_test::Type_testresult f_test_gt_1(vx_core::Type_any expected, vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context);

  // (func test-ne)
  vx_test::Type_testresult f_test_ne(vx_core::Type_any expected, vx_core::Type_any actual, vx_core::Type_context context);

  // (func test-ne)
  vx_test::Type_testresult f_test_ne_1(vx_core::Type_any expected, vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context);

  // (func test-string)
  vx_test::Type_testresult f_test_string(vx_core::Type_any expected, vx_core::Type_any actual, vx_core::Type_context context);

  // (func test-string)
  vx_test::Type_testresult f_test_string_1(vx_core::Type_any expected, vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context);

  // (func test-true)
  vx_test::Type_testresult f_test_true(vx_core::Type_any actual, vx_core::Type_context context);

  // (func test-true)
  vx_test::Type_testresult f_test_true_1(vx_core::Func_any_from_func_async fn_actual, vx_core::Type_context context);

  // (func tr<-testdescribe-casename)
  vx_web_html::Type_tr f_tr_from_testdescribe_casename(vx_test::Type_testdescribe testdescribe, vx_core::Type_string casename);

  // (func trlist<-testcase)
  vx_web_html::Type_trlist f_trlist_from_testcase(vx_test::Type_testcase testcase);

  // (func trlist<-testcaselist)
  vx_web_html::Type_trlist f_trlist_from_testcaselist(vx_test::Type_testcaselist testcaselist);

}
