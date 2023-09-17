#ifndef VX_TEST_HPP
#define VX_TEST_HPP
#include <vector>
#include "../vx/core.hpp"
#include "../vx/data/file.hpp"
#include "../vx/web/html.hpp"

namespace vx_test {

  // forward declarations
  class Abstract_testcase;
  typedef Abstract_testcase* Type_testcase;
  extern Type_testcase e_testcase;
  extern Type_testcase t_testcase;
  class Abstract_testcaselist;
  typedef Abstract_testcaselist* Type_testcaselist;
  extern Type_testcaselist e_testcaselist;
  extern Type_testcaselist t_testcaselist;
  class Abstract_testcoveragedetail;
  typedef Abstract_testcoveragedetail* Type_testcoveragedetail;
  extern Type_testcoveragedetail e_testcoveragedetail;
  extern Type_testcoveragedetail t_testcoveragedetail;
  class Abstract_testcoveragenums;
  typedef Abstract_testcoveragenums* Type_testcoveragenums;
  extern Type_testcoveragenums e_testcoveragenums;
  extern Type_testcoveragenums t_testcoveragenums;
  class Abstract_testcoveragesummary;
  typedef Abstract_testcoveragesummary* Type_testcoveragesummary;
  extern Type_testcoveragesummary e_testcoveragesummary;
  extern Type_testcoveragesummary t_testcoveragesummary;
  class Abstract_testdescribe;
  typedef Abstract_testdescribe* Type_testdescribe;
  extern Type_testdescribe e_testdescribe;
  extern Type_testdescribe t_testdescribe;
  class Abstract_testdescribelist;
  typedef Abstract_testdescribelist* Type_testdescribelist;
  extern Type_testdescribelist e_testdescribelist;
  extern Type_testdescribelist t_testdescribelist;
  class Abstract_testpackage;
  typedef Abstract_testpackage* Type_testpackage;
  extern Type_testpackage e_testpackage;
  extern Type_testpackage t_testpackage;
  class Abstract_testpackagelist;
  typedef Abstract_testpackagelist* Type_testpackagelist;
  extern Type_testpackagelist e_testpackagelist;
  extern Type_testpackagelist t_testpackagelist;
  class Abstract_testresult;
  typedef Abstract_testresult* Type_testresult;
  extern Type_testresult e_testresult;
  extern Type_testresult t_testresult;
  class Abstract_testresultlist;
  typedef Abstract_testresultlist* Type_testresultlist;
  extern Type_testresultlist e_testresultlist;
  extern Type_testresultlist t_testresultlist;
  class Class_stylesheet_test;
  typedef Class_stylesheet_test* Const_stylesheet_test;
  extern Const_stylesheet_test c_stylesheet_test;
  class Abstract_div_from_testcaselist;
  typedef Abstract_div_from_testcaselist* Func_div_from_testcaselist;
  extern Func_div_from_testcaselist e_div_from_testcaselist;
  extern Func_div_from_testcaselist t_div_from_testcaselist;
  class Abstract_div_from_testpackage;
  typedef Abstract_div_from_testpackage* Func_div_from_testpackage;
  extern Func_div_from_testpackage e_div_from_testpackage;
  extern Func_div_from_testpackage t_div_from_testpackage;
  class Abstract_div_from_testpackagelist;
  typedef Abstract_div_from_testpackagelist* Func_div_from_testpackagelist;
  extern Func_div_from_testpackagelist e_div_from_testpackagelist;
  extern Func_div_from_testpackagelist t_div_from_testpackagelist;
  class Abstract_divchildlist_from_testpackagelist;
  typedef Abstract_divchildlist_from_testpackagelist* Func_divchildlist_from_testpackagelist;
  extern Func_divchildlist_from_testpackagelist e_divchildlist_from_testpackagelist;
  extern Func_divchildlist_from_testpackagelist t_divchildlist_from_testpackagelist;
  class Abstract_file_test;
  typedef Abstract_file_test* Func_file_test;
  extern Func_file_test e_file_test;
  extern Func_file_test t_file_test;
  class Abstract_file_testhtml;
  typedef Abstract_file_testhtml* Func_file_testhtml;
  extern Func_file_testhtml e_file_testhtml;
  extern Func_file_testhtml t_file_testhtml;
  class Abstract_file_testnode;
  typedef Abstract_file_testnode* Func_file_testnode;
  extern Func_file_testnode e_file_testnode;
  extern Func_file_testnode t_file_testnode;
  class Abstract_html_from_divtest;
  typedef Abstract_html_from_divtest* Func_html_from_divtest;
  extern Func_html_from_divtest e_html_from_divtest;
  extern Func_html_from_divtest t_html_from_divtest;
  class Abstract_p_from_passfail;
  typedef Abstract_p_from_passfail* Func_p_from_passfail;
  extern Func_p_from_passfail e_p_from_passfail;
  extern Func_p_from_passfail t_p_from_passfail;
  class Abstract_p_from_testcoveragenums;
  typedef Abstract_p_from_testcoveragenums* Func_p_from_testcoveragenums;
  extern Func_p_from_testcoveragenums e_p_from_testcoveragenums;
  extern Func_p_from_testcoveragenums t_p_from_testcoveragenums;
  class Abstract_resolve_testcase;
  typedef Abstract_resolve_testcase* Func_resolve_testcase;
  extern Func_resolve_testcase e_resolve_testcase;
  extern Func_resolve_testcase t_resolve_testcase;
  class Abstract_resolve_testcaselist;
  typedef Abstract_resolve_testcaselist* Func_resolve_testcaselist;
  extern Func_resolve_testcaselist e_resolve_testcaselist;
  extern Func_resolve_testcaselist t_resolve_testcaselist;
  class Abstract_resolve_testdescribe;
  typedef Abstract_resolve_testdescribe* Func_resolve_testdescribe;
  extern Func_resolve_testdescribe e_resolve_testdescribe;
  extern Func_resolve_testdescribe t_resolve_testdescribe;
  class Abstract_resolve_testdescribelist;
  typedef Abstract_resolve_testdescribelist* Func_resolve_testdescribelist;
  extern Func_resolve_testdescribelist e_resolve_testdescribelist;
  extern Func_resolve_testdescribelist t_resolve_testdescribelist;
  class Abstract_resolve_testpackage;
  typedef Abstract_resolve_testpackage* Func_resolve_testpackage;
  extern Func_resolve_testpackage e_resolve_testpackage;
  extern Func_resolve_testpackage t_resolve_testpackage;
  class Abstract_resolve_testpackagelist;
  typedef Abstract_resolve_testpackagelist* Func_resolve_testpackagelist;
  extern Func_resolve_testpackagelist e_resolve_testpackagelist;
  extern Func_resolve_testpackagelist t_resolve_testpackagelist;
  class Abstract_resolve_testresult;
  typedef Abstract_resolve_testresult* Func_resolve_testresult;
  extern Func_resolve_testresult e_resolve_testresult;
  extern Func_resolve_testresult t_resolve_testresult;
  class Abstract_test;
  typedef Abstract_test* Func_test;
  extern Func_test e_test;
  extern Func_test t_test;
  class Abstract_test_1;
  typedef Abstract_test_1* Func_test_1;
  extern Func_test_1 e_test_1;
  extern Func_test_1 t_test_1;
  class Abstract_test_false;
  typedef Abstract_test_false* Func_test_false;
  extern Func_test_false e_test_false;
  extern Func_test_false t_test_false;
  class Abstract_test_false_1;
  typedef Abstract_test_false_1* Func_test_false_1;
  extern Func_test_false_1 e_test_false_1;
  extern Func_test_false_1 t_test_false_1;
  class Abstract_test_gt;
  typedef Abstract_test_gt* Func_test_gt;
  extern Func_test_gt e_test_gt;
  extern Func_test_gt t_test_gt;
  class Abstract_test_gt_1;
  typedef Abstract_test_gt_1* Func_test_gt_1;
  extern Func_test_gt_1 e_test_gt_1;
  extern Func_test_gt_1 t_test_gt_1;
  class Abstract_test_ne;
  typedef Abstract_test_ne* Func_test_ne;
  extern Func_test_ne e_test_ne;
  extern Func_test_ne t_test_ne;
  class Abstract_test_ne_1;
  typedef Abstract_test_ne_1* Func_test_ne_1;
  extern Func_test_ne_1 e_test_ne_1;
  extern Func_test_ne_1 t_test_ne_1;
  class Abstract_test_string;
  typedef Abstract_test_string* Func_test_string;
  extern Func_test_string e_test_string;
  extern Func_test_string t_test_string;
  class Abstract_test_string_1;
  typedef Abstract_test_string_1* Func_test_string_1;
  extern Func_test_string_1 e_test_string_1;
  extern Func_test_string_1 t_test_string_1;
  class Abstract_test_true;
  typedef Abstract_test_true* Func_test_true;
  extern Func_test_true e_test_true;
  extern Func_test_true t_test_true;
  class Abstract_test_true_1;
  typedef Abstract_test_true_1* Func_test_true_1;
  extern Func_test_true_1 e_test_true_1;
  extern Func_test_true_1 t_test_true_1;
  class Abstract_tr_from_testdescribe_casename;
  typedef Abstract_tr_from_testdescribe_casename* Func_tr_from_testdescribe_casename;
  extern Func_tr_from_testdescribe_casename e_tr_from_testdescribe_casename;
  extern Func_tr_from_testdescribe_casename t_tr_from_testdescribe_casename;
  class Abstract_trlist_from_testcase;
  typedef Abstract_trlist_from_testcase* Func_trlist_from_testcase;
  extern Func_trlist_from_testcase e_trlist_from_testcase;
  extern Func_trlist_from_testcase t_trlist_from_testcase;
  class Abstract_trlist_from_testcaselist;
  typedef Abstract_trlist_from_testcaselist* Func_trlist_from_testcaselist;
  extern Func_trlist_from_testcaselist e_trlist_from_testcaselist;
  extern Func_trlist_from_testcaselist t_trlist_from_testcaselist;
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
  vx_core::vx_Type_async f_resolve_testcase(vx_test::Type_testcase testcase);

  // (func resolve-testcaselist)
  vx_core::vx_Type_async f_resolve_testcaselist(vx_test::Type_testcaselist testcaselist);

  // (func resolve-testdescribe)
  vx_core::vx_Type_async f_resolve_testdescribe(vx_test::Type_testdescribe testdescribe);

  // (func resolve-testdescribelist)
  vx_core::vx_Type_async f_resolve_testdescribelist(vx_test::Type_testdescribelist testdescribelist);

  // (func resolve-testpackage)
  vx_core::vx_Type_async f_resolve_testpackage(vx_test::Type_testpackage testpackage);

  // (func resolve-testpackagelist)
  vx_core::vx_Type_async f_resolve_testpackagelist(vx_test::Type_testpackagelist testpackagelist);

  // (func resolve-testresult)
  vx_core::vx_Type_async f_resolve_testresult(vx_test::Type_testresult testresult);

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

  // (type testcase)
  class Abstract_testcase : public virtual vx_core::Abstract_struct {
  public:
    Abstract_testcase() {};
    virtual ~Abstract_testcase() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // passfail()
    vx_core::Type_boolean vx_p_passfail = NULL;
    virtual vx_core::Type_boolean passfail() const = 0;
    // testpkg()
    vx_core::Type_string vx_p_testpkg = NULL;
    virtual vx_core::Type_string testpkg() const = 0;
    // casename()
    vx_core::Type_string vx_p_casename = NULL;
    virtual vx_core::Type_string casename() const = 0;
    // describelist()
    vx_test::Type_testdescribelist vx_p_describelist = NULL;
    virtual vx_test::Type_testdescribelist describelist() const = 0;
  };
  class Class_testcase : public virtual Abstract_testcase {
  public:
    Class_testcase();
    virtual ~Class_testcase() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_boolean passfail() const override;
    virtual vx_core::Type_string testpkg() const override;
    virtual vx_core::Type_string casename() const override;
    virtual vx_test::Type_testdescribelist describelist() const override;
  };

  // (type testcaselist)
  class Abstract_testcaselist : public virtual vx_core::Abstract_list {
  public:
    Abstract_testcaselist() {};
    virtual ~Abstract_testcaselist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_test::Type_testcase> vx_p_list;
    // vx_listtestcase()
    virtual std::vector<vx_test::Type_testcase> vx_listtestcase() const = 0;
    // vx_get_testcase(index)
    virtual vx_test::Type_testcase vx_get_testcase(vx_core::Type_int index) const = 0;
  };
  class Class_testcaselist : public virtual Abstract_testcaselist {
  public:
    Class_testcaselist();
    virtual ~Class_testcaselist() override;
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
    virtual std::vector<vx_test::Type_testcase> vx_listtestcase() const override;
    virtual vx_test::Type_testcase vx_get_testcase(vx_core::Type_int index) const override;
  };

  // (type testcoveragedetail)
  class Abstract_testcoveragedetail : public virtual vx_core::Abstract_struct {
  public:
    Abstract_testcoveragedetail() {};
    virtual ~Abstract_testcoveragedetail() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // constmap()
    vx_core::Type_intmap vx_p_constmap = NULL;
    virtual vx_core::Type_intmap constmap() const = 0;
    // funcmap()
    vx_core::Type_intmap vx_p_funcmap = NULL;
    virtual vx_core::Type_intmap funcmap() const = 0;
    // testpkg()
    vx_core::Type_string vx_p_testpkg = NULL;
    virtual vx_core::Type_string testpkg() const = 0;
    // typemap()
    vx_core::Type_intmap vx_p_typemap = NULL;
    virtual vx_core::Type_intmap typemap() const = 0;
  };
  class Class_testcoveragedetail : public virtual Abstract_testcoveragedetail {
  public:
    Class_testcoveragedetail();
    virtual ~Class_testcoveragedetail() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_intmap constmap() const override;
    virtual vx_core::Type_intmap funcmap() const override;
    virtual vx_core::Type_string testpkg() const override;
    virtual vx_core::Type_intmap typemap() const override;
  };

  // (type testcoveragenums)
  class Abstract_testcoveragenums : public virtual vx_core::Abstract_struct {
  public:
    Abstract_testcoveragenums() {};
    virtual ~Abstract_testcoveragenums() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // pct()
    vx_core::Type_int vx_p_pct = NULL;
    virtual vx_core::Type_int pct() const = 0;
    // testpkg()
    vx_core::Type_string vx_p_testpkg = NULL;
    virtual vx_core::Type_string testpkg() const = 0;
    // tests()
    vx_core::Type_int vx_p_tests = NULL;
    virtual vx_core::Type_int tests() const = 0;
    // total()
    vx_core::Type_int vx_p_total = NULL;
    virtual vx_core::Type_int total() const = 0;
  };
  class Class_testcoveragenums : public virtual Abstract_testcoveragenums {
  public:
    Class_testcoveragenums();
    virtual ~Class_testcoveragenums() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_int pct() const override;
    virtual vx_core::Type_string testpkg() const override;
    virtual vx_core::Type_int tests() const override;
    virtual vx_core::Type_int total() const override;
  };

  // (type testcoveragesummary)
  class Abstract_testcoveragesummary : public virtual vx_core::Abstract_struct {
  public:
    Abstract_testcoveragesummary() {};
    virtual ~Abstract_testcoveragesummary() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // bigospacenums()
    vx_test::Type_testcoveragenums vx_p_bigospacenums = NULL;
    virtual vx_test::Type_testcoveragenums bigospacenums() const = 0;
    // bigotimenums()
    vx_test::Type_testcoveragenums vx_p_bigotimenums = NULL;
    virtual vx_test::Type_testcoveragenums bigotimenums() const = 0;
    // constnums()
    vx_test::Type_testcoveragenums vx_p_constnums = NULL;
    virtual vx_test::Type_testcoveragenums constnums() const = 0;
    // docnums()
    vx_test::Type_testcoveragenums vx_p_docnums = NULL;
    virtual vx_test::Type_testcoveragenums docnums() const = 0;
    // funcnums()
    vx_test::Type_testcoveragenums vx_p_funcnums = NULL;
    virtual vx_test::Type_testcoveragenums funcnums() const = 0;
    // testpkg()
    vx_core::Type_string vx_p_testpkg = NULL;
    virtual vx_core::Type_string testpkg() const = 0;
    // totalnums()
    vx_test::Type_testcoveragenums vx_p_totalnums = NULL;
    virtual vx_test::Type_testcoveragenums totalnums() const = 0;
    // typenums()
    vx_test::Type_testcoveragenums vx_p_typenums = NULL;
    virtual vx_test::Type_testcoveragenums typenums() const = 0;
  };
  class Class_testcoveragesummary : public virtual Abstract_testcoveragesummary {
  public:
    Class_testcoveragesummary();
    virtual ~Class_testcoveragesummary() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_test::Type_testcoveragenums bigospacenums() const override;
    virtual vx_test::Type_testcoveragenums bigotimenums() const override;
    virtual vx_test::Type_testcoveragenums constnums() const override;
    virtual vx_test::Type_testcoveragenums docnums() const override;
    virtual vx_test::Type_testcoveragenums funcnums() const override;
    virtual vx_core::Type_string testpkg() const override;
    virtual vx_test::Type_testcoveragenums totalnums() const override;
    virtual vx_test::Type_testcoveragenums typenums() const override;
  };

  // (type testdescribe)
  class Abstract_testdescribe : public virtual vx_core::Abstract_struct {
  public:
    Abstract_testdescribe() {};
    virtual ~Abstract_testdescribe() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // describename()
    vx_core::Type_string vx_p_describename = NULL;
    virtual vx_core::Type_string describename() const = 0;
    // testpkg()
    vx_core::Type_string vx_p_testpkg = NULL;
    virtual vx_core::Type_string testpkg() const = 0;
    // testresult()
    vx_test::Type_testresult vx_p_testresult = NULL;
    virtual vx_test::Type_testresult testresult() const = 0;
  };
  class Class_testdescribe : public virtual Abstract_testdescribe {
  public:
    Class_testdescribe();
    virtual ~Class_testdescribe() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string describename() const override;
    virtual vx_core::Type_string testpkg() const override;
    virtual vx_test::Type_testresult testresult() const override;
  };

  // (type testdescribelist)
  class Abstract_testdescribelist : public virtual vx_core::Abstract_list {
  public:
    Abstract_testdescribelist() {};
    virtual ~Abstract_testdescribelist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_test::Type_testdescribe> vx_p_list;
    // vx_listtestdescribe()
    virtual std::vector<vx_test::Type_testdescribe> vx_listtestdescribe() const = 0;
    // vx_get_testdescribe(index)
    virtual vx_test::Type_testdescribe vx_get_testdescribe(vx_core::Type_int index) const = 0;
  };
  class Class_testdescribelist : public virtual Abstract_testdescribelist {
  public:
    Class_testdescribelist();
    virtual ~Class_testdescribelist() override;
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
    virtual std::vector<vx_test::Type_testdescribe> vx_listtestdescribe() const override;
    virtual vx_test::Type_testdescribe vx_get_testdescribe(vx_core::Type_int index) const override;
  };

  // (type testpackage)
  class Abstract_testpackage : public virtual vx_core::Abstract_struct {
  public:
    Abstract_testpackage() {};
    virtual ~Abstract_testpackage() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // caselist()
    vx_test::Type_testcaselist vx_p_caselist = NULL;
    virtual vx_test::Type_testcaselist caselist() const = 0;
    // coveragedetail()
    vx_test::Type_testcoveragedetail vx_p_coveragedetail = NULL;
    virtual vx_test::Type_testcoveragedetail coveragedetail() const = 0;
    // coveragesummary()
    vx_test::Type_testcoveragesummary vx_p_coveragesummary = NULL;
    virtual vx_test::Type_testcoveragesummary coveragesummary() const = 0;
    // passfail()
    vx_core::Type_boolean vx_p_passfail = NULL;
    virtual vx_core::Type_boolean passfail() const = 0;
    // testpkg()
    vx_core::Type_string vx_p_testpkg = NULL;
    virtual vx_core::Type_string testpkg() const = 0;
  };
  class Class_testpackage : public virtual Abstract_testpackage {
  public:
    Class_testpackage();
    virtual ~Class_testpackage() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_test::Type_testcaselist caselist() const override;
    virtual vx_test::Type_testcoveragedetail coveragedetail() const override;
    virtual vx_test::Type_testcoveragesummary coveragesummary() const override;
    virtual vx_core::Type_boolean passfail() const override;
    virtual vx_core::Type_string testpkg() const override;
  };

  // (type testpackagelist)
  class Abstract_testpackagelist : public virtual vx_core::Abstract_list {
  public:
    Abstract_testpackagelist() {};
    virtual ~Abstract_testpackagelist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_test::Type_testpackage> vx_p_list;
    // vx_listtestpackage()
    virtual std::vector<vx_test::Type_testpackage> vx_listtestpackage() const = 0;
    // vx_get_testpackage(index)
    virtual vx_test::Type_testpackage vx_get_testpackage(vx_core::Type_int index) const = 0;
  };
  class Class_testpackagelist : public virtual Abstract_testpackagelist {
  public:
    Class_testpackagelist();
    virtual ~Class_testpackagelist() override;
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
    virtual std::vector<vx_test::Type_testpackage> vx_listtestpackage() const override;
    virtual vx_test::Type_testpackage vx_get_testpackage(vx_core::Type_int index) const override;
  };

  // (type testresult)
  class Abstract_testresult : public virtual vx_core::Abstract_struct {
  public:
    Abstract_testresult() {};
    virtual ~Abstract_testresult() = 0;
    // vx_map()
    virtual vx_core::vx_Type_mapany vx_map() const = 0;
    // vx_get_any(key)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const = 0;
    // code()
    vx_core::Type_string vx_p_code = NULL;
    virtual vx_core::Type_string code() const = 0;
    // passfail()
    vx_core::Type_boolean vx_p_passfail = NULL;
    virtual vx_core::Type_boolean passfail() const = 0;
    // expected()
    vx_core::Type_any vx_p_expected = NULL;
    virtual vx_core::Type_any expected() const = 0;
    // actual()
    vx_core::Type_any vx_p_actual = NULL;
    virtual vx_core::Type_any actual() const = 0;
    // fn-actual()
    vx_core::Func_any_from_func_async vx_p_fn_actual = NULL;
    virtual vx_core::Func_any_from_func_async fn_actual() const = 0;
  };
  class Class_testresult : public virtual Abstract_testresult {
  public:
    Class_testresult();
    virtual ~Class_testresult() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::vx_Type_mapany vx_map() const override;
    virtual vx_core::Type_any vx_get_any(vx_core::Type_string key) const override;
    virtual vx_core::Type_string code() const override;
    virtual vx_core::Type_boolean passfail() const override;
    virtual vx_core::Type_any expected() const override;
    virtual vx_core::Type_any actual() const override;
    virtual vx_core::Func_any_from_func_async fn_actual() const override;
  };

  // (type testresultlist)
  class Abstract_testresultlist : public virtual vx_core::Abstract_list {
  public:
    Abstract_testresultlist() {};
    virtual ~Abstract_testresultlist() = 0;
    // vx_get_any(index)
    virtual vx_core::Type_any vx_get_any(vx_core::Type_int index) const = 0;
    // vx_list()
    virtual vx_core::vx_Type_listany vx_list() const = 0;
    // vx_new_from_list(T, List<T>)
    virtual vx_core::Type_any vx_new_from_list(vx_core::vx_Type_listany listval) const = 0;
    std::vector<vx_test::Type_testresult> vx_p_list;
    // vx_listtestresult()
    virtual std::vector<vx_test::Type_testresult> vx_listtestresult() const = 0;
    // vx_get_testresult(index)
    virtual vx_test::Type_testresult vx_get_testresult(vx_core::Type_int index) const = 0;
  };
  class Class_testresultlist : public virtual Abstract_testresultlist {
  public:
    Class_testresultlist();
    virtual ~Class_testresultlist() override;
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
    virtual std::vector<vx_test::Type_testresult> vx_listtestresult() const override;
    virtual vx_test::Type_testresult vx_get_testresult(vx_core::Type_int index) const override;
  };

  // (const stylesheet-test)
  class Class_stylesheet_test : public vx_web_html::Class_stylesheet {
  public:
    static void vx_const_new(vx_test::Const_stylesheet_test output);
    vx_core::Type_constdef vx_constdef() const;
  };

  // (func div<-testcaselist)
  class Abstract_div_from_testcaselist : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_div_from_testcaselist() {};
    virtual ~Abstract_div_from_testcaselist() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_div_from_testcaselist : public virtual Abstract_div_from_testcaselist {
  public:
    Class_div_from_testcaselist();
    virtual ~Class_div_from_testcaselist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func div<-testpackage)
  class Abstract_div_from_testpackage : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_div_from_testpackage() {};
    virtual ~Abstract_div_from_testpackage() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_div_from_testpackage : public virtual Abstract_div_from_testpackage {
  public:
    Class_div_from_testpackage();
    virtual ~Class_div_from_testpackage() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func div<-testpackagelist)
  class Abstract_div_from_testpackagelist : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_div_from_testpackagelist() {};
    virtual ~Abstract_div_from_testpackagelist() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_div_from_testpackagelist : public virtual Abstract_div_from_testpackagelist {
  public:
    Class_div_from_testpackagelist();
    virtual ~Class_div_from_testpackagelist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func divchildlist<-testpackagelist)
  class Abstract_divchildlist_from_testpackagelist : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_divchildlist_from_testpackagelist() {};
    virtual ~Abstract_divchildlist_from_testpackagelist() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_divchildlist_from_testpackagelist : public virtual Abstract_divchildlist_from_testpackagelist {
  public:
    Class_divchildlist_from_testpackagelist();
    virtual ~Class_divchildlist_from_testpackagelist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func file-test)
  class Abstract_file_test : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_file_test() {};
    virtual ~Abstract_file_test() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_file_test : public virtual Abstract_file_test {
  public:
    Class_file_test();
    virtual ~Class_file_test() override;
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

  // (func file-testhtml)
  class Abstract_file_testhtml : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_file_testhtml() {};
    virtual ~Abstract_file_testhtml() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_file_testhtml : public virtual Abstract_file_testhtml {
  public:
    Class_file_testhtml();
    virtual ~Class_file_testhtml() override;
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

  // (func file-testnode)
  class Abstract_file_testnode : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_file_testnode() {};
    virtual ~Abstract_file_testnode() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_file_testnode : public virtual Abstract_file_testnode {
  public:
    Class_file_testnode();
    virtual ~Class_file_testnode() override;
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

  // (func html<-divtest)
  class Abstract_html_from_divtest : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_html_from_divtest() {};
    virtual ~Abstract_html_from_divtest() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_html_from_divtest : public virtual Abstract_html_from_divtest {
  public:
    Class_html_from_divtest();
    virtual ~Class_html_from_divtest() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func p<-passfail)
  class Abstract_p_from_passfail : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_p_from_passfail() {};
    virtual ~Abstract_p_from_passfail() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_p_from_passfail : public virtual Abstract_p_from_passfail {
  public:
    Class_p_from_passfail();
    virtual ~Class_p_from_passfail() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func p<-testcoveragenums)
  class Abstract_p_from_testcoveragenums : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_p_from_testcoveragenums() {};
    virtual ~Abstract_p_from_testcoveragenums() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_p_from_testcoveragenums : public virtual Abstract_p_from_testcoveragenums {
  public:
    Class_p_from_testcoveragenums();
    virtual ~Class_p_from_testcoveragenums() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func resolve-testcase)
  class Abstract_resolve_testcase : public vx_core::Abstract_any_from_any_async, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_resolve_testcase() {};
    virtual ~Abstract_resolve_testcase() = 0;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override = 0;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_resolve_testcase : public virtual Abstract_resolve_testcase {
  public:
    Class_resolve_testcase();
    virtual ~Class_resolve_testcase() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func resolve-testcaselist)
  class Abstract_resolve_testcaselist : public vx_core::Abstract_any_from_any_async, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_resolve_testcaselist() {};
    virtual ~Abstract_resolve_testcaselist() = 0;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override = 0;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_resolve_testcaselist : public virtual Abstract_resolve_testcaselist {
  public:
    Class_resolve_testcaselist();
    virtual ~Class_resolve_testcaselist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func resolve-testdescribe)
  class Abstract_resolve_testdescribe : public vx_core::Abstract_any_from_any_async, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_resolve_testdescribe() {};
    virtual ~Abstract_resolve_testdescribe() = 0;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override = 0;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_resolve_testdescribe : public virtual Abstract_resolve_testdescribe {
  public:
    Class_resolve_testdescribe();
    virtual ~Class_resolve_testdescribe() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func resolve-testdescribelist)
  class Abstract_resolve_testdescribelist : public vx_core::Abstract_any_from_any_async, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_resolve_testdescribelist() {};
    virtual ~Abstract_resolve_testdescribelist() = 0;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override = 0;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_resolve_testdescribelist : public virtual Abstract_resolve_testdescribelist {
  public:
    Class_resolve_testdescribelist();
    virtual ~Class_resolve_testdescribelist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func resolve-testpackage)
  class Abstract_resolve_testpackage : public vx_core::Abstract_any_from_any_async, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_resolve_testpackage() {};
    virtual ~Abstract_resolve_testpackage() = 0;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override = 0;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_resolve_testpackage : public virtual Abstract_resolve_testpackage {
  public:
    Class_resolve_testpackage();
    virtual ~Class_resolve_testpackage() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func resolve-testpackagelist)
  class Abstract_resolve_testpackagelist : public vx_core::Abstract_any_from_any_async, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_resolve_testpackagelist() {};
    virtual ~Abstract_resolve_testpackagelist() = 0;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override = 0;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_resolve_testpackagelist : public virtual Abstract_resolve_testpackagelist {
  public:
    Class_resolve_testpackagelist();
    virtual ~Class_resolve_testpackagelist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func resolve-testresult)
  class Abstract_resolve_testresult : public vx_core::Abstract_any_from_any_async, public virtual vx_core::Abstract_replfunc_async {
  public:
    Abstract_resolve_testresult() {};
    virtual ~Abstract_resolve_testresult() = 0;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override = 0;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override = 0;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_resolve_testresult : public virtual Abstract_resolve_testresult {
  public:
    Class_resolve_testresult();
    virtual ~Class_resolve_testresult() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_async vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_async::IFn fn) const override;
    virtual vx_core::vx_Type_async vx_any_from_any_async(vx_core::Type_any generic_any_1, vx_core::Type_any val) const override;
    virtual vx_core::vx_Type_async vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func test)
  class Abstract_test : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_test() {};
    virtual ~Abstract_test() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_test : public virtual Abstract_test {
  public:
    Class_test();
    virtual ~Class_test() override;
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

  // (func test)
  class Abstract_test_1 : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_test_1() {};
    virtual ~Abstract_test_1() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_test_1 : public virtual Abstract_test_1 {
  public:
    Class_test_1();
    virtual ~Class_test_1() override;
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

  // (func test-false)
  class Abstract_test_false : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_test_false() {};
    virtual ~Abstract_test_false() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_test_false : public virtual Abstract_test_false {
  public:
    Class_test_false();
    virtual ~Class_test_false() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func test-false)
  class Abstract_test_false_1 : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_test_false_1() {};
    virtual ~Abstract_test_false_1() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_test_false_1 : public virtual Abstract_test_false_1 {
  public:
    Class_test_false_1();
    virtual ~Class_test_false_1() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func test-gt)
  class Abstract_test_gt : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_test_gt() {};
    virtual ~Abstract_test_gt() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_test_gt : public virtual Abstract_test_gt {
  public:
    Class_test_gt();
    virtual ~Class_test_gt() override;
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

  // (func test-gt)
  class Abstract_test_gt_1 : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_test_gt_1() {};
    virtual ~Abstract_test_gt_1() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_test_gt_1 : public virtual Abstract_test_gt_1 {
  public:
    Class_test_gt_1();
    virtual ~Class_test_gt_1() override;
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

  // (func test-ne)
  class Abstract_test_ne : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_test_ne() {};
    virtual ~Abstract_test_ne() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_test_ne : public virtual Abstract_test_ne {
  public:
    Class_test_ne();
    virtual ~Class_test_ne() override;
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

  // (func test-ne)
  class Abstract_test_ne_1 : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_test_ne_1() {};
    virtual ~Abstract_test_ne_1() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_test_ne_1 : public virtual Abstract_test_ne_1 {
  public:
    Class_test_ne_1();
    virtual ~Class_test_ne_1() override;
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

  // (func test-string)
  class Abstract_test_string : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_test_string() {};
    virtual ~Abstract_test_string() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_test_string : public virtual Abstract_test_string {
  public:
    Class_test_string();
    virtual ~Class_test_string() override;
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

  // (func test-string)
  class Abstract_test_string_1 : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_test_string_1() {};
    virtual ~Abstract_test_string_1() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_test_string_1 : public virtual Abstract_test_string_1 {
  public:
    Class_test_string_1();
    virtual ~Class_test_string_1() override;
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

  // (func test-true)
  class Abstract_test_true : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_test_true() {};
    virtual ~Abstract_test_true() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_test_true : public virtual Abstract_test_true {
  public:
    Class_test_true();
    virtual ~Class_test_true() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func test-true)
  class Abstract_test_true_1 : public vx_core::Abstract_any_from_any_context, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_test_true_1() {};
    virtual ~Abstract_test_true_1() = 0;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_test_true_1 : public virtual Abstract_test_true_1 {
  public:
    Class_test_true_1();
    virtual ~Class_test_true_1() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any_context vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any_context::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any_context(vx_core::Type_any value, vx_core::Type_context context) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func tr<-testdescribe-casename)
  class Abstract_tr_from_testdescribe_casename : public vx_core::Abstract_func, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_tr_from_testdescribe_casename() {};
    virtual ~Abstract_tr_from_testdescribe_casename() = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_tr_from_testdescribe_casename : public virtual Abstract_tr_from_testdescribe_casename {
  public:
    Class_tr_from_testdescribe_casename();
    virtual ~Class_tr_from_testdescribe_casename() override;
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

  // (func trlist<-testcase)
  class Abstract_trlist_from_testcase : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_trlist_from_testcase() {};
    virtual ~Abstract_trlist_from_testcase() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_trlist_from_testcase : public virtual Abstract_trlist_from_testcase {
  public:
    Class_trlist_from_testcase();
    virtual ~Class_trlist_from_testcase() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

  // (func trlist<-testcaselist)
  class Abstract_trlist_from_testcaselist : public vx_core::Abstract_any_from_any, public virtual vx_core::Abstract_replfunc {
  public:
    Abstract_trlist_from_testcaselist() {};
    virtual ~Abstract_trlist_from_testcaselist() = 0;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override = 0;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override = 0;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override = 0;
  };
  class Class_trlist_from_testcaselist : public virtual Abstract_trlist_from_testcaselist {
  public:
    Class_trlist_from_testcaselist();
    virtual ~Class_trlist_from_testcaselist() override;
    virtual vx_core::Type_any vx_new(vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_any vx_copy(vx_core::Type_any copyval, vx_core::vx_Type_listany vals) const override;
    virtual vx_core::Type_funcdef vx_funcdef() const override;
    virtual vx_core::Type_typedef vx_typedef() const override;
    virtual vx_core::Type_msgblock vx_msgblock() const override;
    virtual vx_core::vx_Type_listany vx_dispose() override;
    virtual vx_core::Type_any vx_empty() const override;
    virtual vx_core::Type_any vx_type() const override;
    virtual vx_core::Func_any_from_any vx_fn_new(vx_core::vx_Type_listany lambdavars, vx_core::Abstract_any_from_any::IFn fn) const override;
    virtual vx_core::Type_any vx_any_from_any(vx_core::Type_any value) const override;
    virtual vx_core::Type_any vx_repl(vx_core::Type_anylist arglist) override;
  };

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
