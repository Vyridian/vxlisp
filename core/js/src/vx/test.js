'strict mode'

import vx_core from "../vx/core.js"
import vx_data_file from "../vx/data/file.js"
import vx_web_html from "../vx/web/html.js"

export default class vx_test {

  /**
   * type: testcase
   * Structure to describe a test case
   */
  static t_testcase = {}

  /**
   * type: testcaselist
   * List of test cases
   */
  static t_testcaselist = {}

  /**
   * type: testcoveragedetail
   * Structure to describe a test coverage detail
   */
  static t_testcoveragedetail = {}

  /**
   * type: testcoveragenums
   * Structure to describe a test coverage summary
   */
  static t_testcoveragenums = {}

  /**
   * type: testcoveragesummary
   * Structure to describe a test coverage summary
   */
  static t_testcoveragesummary = {}

  /**
   * type: testdescribe
   * Structure to describe test results
   */
  static t_testdescribe = {}

  /**
   * type: testdescribelist
   * List of testdescribe
   */
  static t_testdescribelist = {}

  /**
   * type: testpackage
   * Structure to hold all tests for a package
   */
  static t_testpackage = {}

  /**
   * type: testpackagelist
   * List of testpackage
   */
  static t_testpackagelist = {}

  /**
   * type: testresult
   * Structure to hold test results
   */
  static t_testresult = {}

  /**
   * type: testresultlist
   * List of test results
   */
  static t_testresultlist = {}
  /**
   * Constant: stylesheet-test
   * The default Test Stylesheet
   * {stylesheet}
   */
  static c_stylesheet_test = {vx_type: vx_web_html.t_stylesheet, vx_constdef: {pkgname: 'vx/test', name: 'stylesheet-test'}}

  /**
   * @function context_test
   * Returns the default context for test case execution. Arguments come from the command line.
   * @param  {anylist} ... args
   * @return {context}
   */
  static t_context_test = {}
  static e_context_test = {vx_type: vx_test.t_context_test}

  // (func context-test)
  static f_context_test(...args) {
    let output = vx_core.e_context
    args = vx_core.f_new(vx_core.t_anylist, ...args)
    output = vx_core.f_new(
      vx_core.t_context,
      ":session",
      vx_core.f_new(
        vx_core.t_session,
        ":user",
        vx_core.f_new(
          vx_core.t_user,
          ":security",
          vx_test.f_security_test()
        )
      )
    )
    return output
  }

  /**
   * @function div_from_testcaselist
   * @param  {testcaselist} testcaselist
   * @return {div}
   */
  static t_div_from_testcaselist = {}
  static e_div_from_testcaselist = {vx_type: vx_test.t_div_from_testcaselist}

  // (func div<-testcaselist)
  static f_div_from_testcaselist(testcaselist) {
    let output = vx_web_html.e_div
    output = vx_core.f_new(
      vx_web_html.t_div,
      vx_core.f_new(
        vx_web_html.t_table,
        ":thead",
        vx_core.f_new(
          vx_web_html.t_thead,
          vx_core.f_new(
            vx_web_html.t_tr,
            vx_core.f_new(
              vx_web_html.t_td,
              vx_core.f_new(
                vx_web_html.t_p,
                ":text",
                "Pass?"
              )
            ),
            vx_core.f_new(
              vx_web_html.t_td,
              vx_core.f_new(
                vx_web_html.t_p,
                ":text",
                "Name"
              )
            ),
            vx_core.f_new(
              vx_web_html.t_td,
              vx_core.f_new(
                vx_web_html.t_p,
                ":text",
                "Test"
              )
            ),
            vx_core.f_new(
              vx_web_html.t_td,
              vx_core.f_new(
                vx_web_html.t_p,
                ":text",
                "Expected"
              )
            ),
            vx_core.f_new(
              vx_web_html.t_td,
              vx_core.f_new(
                vx_web_html.t_p,
                ":text",
                "Actual"
              )
            )
          )
        ),
        ":tbody",
        vx_core.f_new(
          vx_web_html.t_tbody,
          vx_test.f_trlist_from_testcaselist(testcaselist)
        )
      )
    )
    return output
  }

  /**
   * @function div_from_testpackage
   * Retuns a div from a test package
   * @param  {testpackage} testpackage
   * @return {div}
   */
  static t_div_from_testpackage = {}
  static e_div_from_testpackage = {vx_type: vx_test.t_div_from_testpackage}

  // (func div<-testpackage)
  static f_div_from_testpackage(testpackage) {
    let output = vx_web_html.e_div
    output = vx_core.f_let(
      {"any-1": vx_web_html.t_div},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const testcoveragesummary = vx_core.f_any_from_struct({"any-1": vx_test.t_testcoveragesummary, "struct-2": vx_test.t_testpackage}, testpackage, ":coveragesummary")
        const pkgname = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_test.t_testpackage}, testpackage, ":testpkg")
        const caselist = vx_core.f_any_from_struct({"any-1": vx_test.t_testcaselist, "struct-2": vx_test.t_testpackage}, testpackage, ":caselist")
        const passfail = vx_core.f_any_from_struct({"any-1": vx_core.t_boolean, "struct-2": vx_test.t_testpackage}, testpackage, ":passfail")
        const pkgnamestyle = vx_web_html.f_style_from_stylesheet_name(
          vx_test.c_stylesheet_test,
          ".pkgname"
        )
        const node = vx_test.f_div_from_testcaselist(caselist)
        const nodes = vx_core.f_new(
          vx_web_html.t_divchildlist,
          node
        )
        const p_passfail = vx_test.f_p_from_passfail(passfail)
        const p_pkgname = vx_core.f_new(
          vx_web_html.t_p,
          ":style",
          pkgnamestyle,
          ":text",
          pkgname
        )
        const p_totalnums = vx_test.f_p_from_testcoveragenums(
          vx_core.f_any_from_struct({"any-1": vx_test.t_testcoveragenums, "struct-2": vx_test.t_testcoveragesummary}, testcoveragesummary, ":totalnums")
        )
        const p_coveragenums = vx_test.f_p_from_testcoveragenums(
          vx_core.f_any_from_struct({"any-1": vx_test.t_testcoveragenums, "struct-2": vx_test.t_testcoveragesummary}, testcoveragesummary, ":typenums")
        )
        const p_constnums = vx_test.f_p_from_testcoveragenums(
          vx_core.f_any_from_struct({"any-1": vx_test.t_testcoveragenums, "struct-2": vx_test.t_testcoveragesummary}, testcoveragesummary, ":constnums")
        )
        const p_funcnums = vx_test.f_p_from_testcoveragenums(
          vx_core.f_any_from_struct({"any-1": vx_test.t_testcoveragenums, "struct-2": vx_test.t_testcoveragesummary}, testcoveragesummary, ":funcnums")
        )
        const p_docnums = vx_test.f_p_from_testcoveragenums(
          vx_core.f_any_from_struct({"any-1": vx_test.t_testcoveragenums, "struct-2": vx_test.t_testcoveragesummary}, testcoveragesummary, ":docnums")
        )
        const p_bigospacenums = vx_test.f_p_from_testcoveragenums(
          vx_core.f_any_from_struct({"any-1": vx_test.t_testcoveragenums, "struct-2": vx_test.t_testcoveragesummary}, testcoveragesummary, ":bigospacenums")
        )
        const p_bigotimenums = vx_test.f_p_from_testcoveragenums(
          vx_core.f_any_from_struct({"any-1": vx_test.t_testcoveragenums, "struct-2": vx_test.t_testcoveragesummary}, testcoveragesummary, ":bigotimenums")
        )
        const summary = vx_core.f_new(
          vx_web_html.t_divchildlist,
          p_passfail,
          p_pkgname,
          p_totalnums,
          p_coveragenums,
          p_constnums,
          p_funcnums,
          p_docnums,
          p_bigospacenums,
          p_bigotimenums
        )
        const details = vx_core.f_new(
          vx_web_html.t_details,
          ":summary",
          summary,
          ":nodes",
          nodes
        )
        return vx_core.f_new(
          vx_web_html.t_div,
          details
        )
      })
    )
    return output
  }

  /**
   * @function div_from_testpackagelist
   * @param  {testpackagelist} testpackagelist
   * @return {div}
   */
  static t_div_from_testpackagelist = {}
  static e_div_from_testpackagelist = {vx_type: vx_test.t_div_from_testpackagelist}

  // (func div<-testpackagelist)
  static f_div_from_testpackagelist(testpackagelist) {
    let output = vx_web_html.e_div
    output = vx_core.f_let(
      {"any-1": vx_web_html.t_div},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const stylepassfail = vx_web_html.f_style_from_stylesheet_name(
          vx_test.c_stylesheet_test,
          ".passfail"
        )
        const stylepkgname = vx_web_html.f_style_from_stylesheet_name(
          vx_test.c_stylesheet_test,
          ".pkgname"
        )
        const stylepkgheader = vx_web_html.f_style_from_stylesheet_name(
          vx_test.c_stylesheet_test,
          ".pkgheader"
        )
        const stylecoveragenum = vx_web_html.f_style_from_stylesheet_name(
          vx_test.c_stylesheet_test,
          ".coveragenums"
        )
        return vx_core.f_new(
          vx_web_html.t_div,
          vx_core.f_new(
            vx_web_html.t_div,
            ":style",
            stylepkgheader,
            vx_core.f_new(
              vx_web_html.t_p,
              ":style",
              stylepassfail,
              ":text",
              "Pass?"
            ),
            vx_core.f_new(
              vx_web_html.t_p,
              ":style",
              stylepkgname,
              ":text",
              "Package Name"
            ),
            vx_core.f_new(
              vx_web_html.t_p,
              ":style",
              stylecoveragenum,
              ":text",
              "Coverage"
            ),
            vx_core.f_new(
              vx_web_html.t_p,
              ":style",
              stylecoveragenum,
              ":text",
              "(type)"
            ),
            vx_core.f_new(
              vx_web_html.t_p,
              ":style",
              stylecoveragenum,
              ":text",
              "(const)"
            ),
            vx_core.f_new(
              vx_web_html.t_p,
              ":style",
              stylecoveragenum,
              ":text",
              "(func)"
            ),
            vx_core.f_new(
              vx_web_html.t_p,
              ":style",
              stylecoveragenum,
              ":text",
              ":doc"
            ),
            vx_core.f_new(
              vx_web_html.t_p,
              ":style",
              stylecoveragenum,
              ":text",
              ":bigospace"
            ),
            vx_core.f_new(
              vx_web_html.t_p,
              ":style",
              stylecoveragenum,
              ":text",
              ":bigotime"
            )
          ),
          vx_core.f_new(
            vx_web_html.t_div,
            vx_test.f_divchildlist_from_testpackagelist(testpackagelist)
          )
        )
      })
    )
    return output
  }

  /**
   * @function divchildlist_from_testpackagelist
   * Returns a divlist from a testpackagelist.
   * @param  {testpackagelist} testpackagelist
   * @return {divchildlist}
   */
  static t_divchildlist_from_testpackagelist = {}
  static e_divchildlist_from_testpackagelist = {vx_type: vx_test.t_divchildlist_from_testpackagelist}

  // (func divchildlist<-testpackagelist)
  static f_divchildlist_from_testpackagelist(testpackagelist) {
    let output = vx_web_html.e_divchildlist
    output = vx_core.f_list_from_list(
      {"any-1": vx_web_html.t_divchild, "any-2": vx_test.t_testpackage, "list-1": vx_web_html.t_divchildlist, "list-2": vx_test.t_testpackagelist},
      testpackagelist,
      vx_core.f_new(vx_core.t_any_from_any, vx_test.t_div_from_testpackage)
    )
    return output
  }

  /**
   * @function html_from_divtest
   * Returns html from test div
   * @param  {div} divtest
   * @return {html}
   */
  static t_html_from_divtest = {}
  static e_html_from_divtest = {vx_type: vx_test.t_html_from_divtest}

  // (func html<-divtest)
  static f_html_from_divtest(divtest) {
    let output = vx_web_html.e_html
    output = vx_core.f_new(
      vx_web_html.t_html,
      ":lang",
      "en",
      ":head",
      vx_core.f_new(
        vx_web_html.t_head,
        vx_core.f_new(
          vx_web_html.t_meta,
          ":charset",
          "utf-8"
        ),
        vx_core.f_new(
          vx_web_html.t_title,
          ":text",
          "Test Suite"
        ),
        vx_test.c_stylesheet_test
      ),
      ":body",
      vx_core.f_new(
        vx_web_html.t_body,
        vx_core.f_new(
          vx_web_html.t_div,
          vx_core.f_new(
            vx_web_html.t_h1,
            "Test Suite"
          )
        ),
        divtest
      )
    )
    return output
  }

  /**
   * @function p_from_passfail
   * Returns a <p> tag from a passfail boolean value
   * @param  {boolean} passfail
   * @return {p}
   */
  static t_p_from_passfail = {}
  static e_p_from_passfail = {vx_type: vx_test.t_p_from_passfail}

  // (func p<-passfail)
  static f_p_from_passfail(passfail) {
    let output = vx_web_html.e_p
    output = vx_core.f_let(
      {"any-1": vx_web_html.t_p},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const text = vx_core.f_if_1({"any-1": vx_core.t_string}, passfail, "Pass", "Fail")
        const stylename = vx_core.f_if_1({"any-1": vx_core.t_string}, passfail, ".passflag", ".failflag")
        const style = vx_web_html.f_style_from_stylesheet_name(
          vx_test.c_stylesheet_test,
          stylename
        )
        return vx_core.f_new(
          vx_web_html.t_p,
          ":style",
          style,
          ":text",
          text
        )
      })
    )
    return output
  }

  /**
   * @function p_from_testcoveragenums
   * Returns <p>tests / total (pct%)</p> from testcoveragenums
   * @param  {testcoveragenums} nums
   * @return {p}
   */
  static t_p_from_testcoveragenums = {}
  static e_p_from_testcoveragenums = {vx_type: vx_test.t_p_from_testcoveragenums}

  // (func p<-testcoveragenums)
  static f_p_from_testcoveragenums(nums) {
    let output = vx_web_html.e_p
    output = vx_core.f_new(
      vx_web_html.t_p,
      ":style",
      vx_web_html.f_style_from_stylesheet_name(
        vx_test.c_stylesheet_test,
        ".coveragenums"
      ),
      ":text",
      vx_core.f_new(
        vx_core.t_string,
        vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_test.t_testcoveragenums}, nums, ":pct"),
        "% ",
        vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_test.t_testcoveragenums}, nums, ":tests"),
        "/",
        vx_core.f_any_from_struct({"any-1": vx_core.t_int, "struct-2": vx_test.t_testcoveragenums}, nums, ":total")
      )
    )
    return output
  }

  /**
   * 
   * @async @function resolve_testcase
   * Resolves a testcase
   * @param  {testcase} testcase
   * @return {testcase}
   */
  static t_resolve_testcase = {}
  static e_resolve_testcase = {vx_type: vx_test.t_resolve_testcase}

  // (func resolve-testcase)
  static async f_resolve_testcase(testcase) {
    let output = Promise.resolve(vx_test.e_testcase)
    output = await vx_core.f_let_async(
      {"any-1": vx_test.t_testcase},
      [],
      vx_core.f_new(vx_core.t_any_from_func, async () => {
        const describelist = vx_core.f_any_from_struct({"any-1": vx_test.t_testdescribelist, "struct-2": vx_test.t_testcase}, testcase, ":describelist")
        const resolvedlist = await vx_test.f_resolve_testdescribelist(describelist)
        const passfaillist = vx_core.f_list_from_list(
          {"any-1": vx_core.t_boolean, "any-2": vx_test.t_testdescribe, "list-1": vx_core.t_booleanlist, "list-2": vx_test.t_testdescribelist, "struct-2": vx_test.t_testresult},
          resolvedlist,
          vx_core.f_new(vx_core.t_any_from_any, (testdescribe) => 
            vx_core.f_let(
              {"any-1": vx_core.t_boolean, "struct-2": vx_test.t_testresult},
              [],
              vx_core.f_new(vx_core.t_any_from_func, () => {
                const testresult = vx_core.f_any_from_struct({"any-1": vx_test.t_testresult, "struct-2": vx_test.t_testdescribe}, testdescribe, ":testresult")
                return vx_core.f_any_from_struct({"any-1": vx_core.t_boolean, "struct-2": vx_test.t_testresult}, testresult, ":passfail")
              })
            ))
        )
        const passfail = vx_core.f_and_1(passfaillist)
        return vx_core.f_copy(testcase, ":passfail", passfail, ":describelist", resolvedlist)
      })
    )
    return output
  }

  /**
   * 
   * @async @function resolve_testcaselist
   * Resolves a testcaselist
   * @param  {testcaselist} testcaselist
   * @return {testcaselist}
   */
  static t_resolve_testcaselist = {}
  static e_resolve_testcaselist = {vx_type: vx_test.t_resolve_testcaselist}

  // (func resolve-testcaselist)
  static async f_resolve_testcaselist(testcaselist) {
    let output = Promise.resolve(vx_test.e_testcaselist)
    output = await vx_core.f_list_from_list_async(
      {"any-1": vx_test.t_testcase, "any-2": vx_test.t_testcase, "list-1": vx_test.t_testcaselist, "list-2": vx_test.t_testcaselist},
      testcaselist,
      vx_core.f_new(vx_core.t_any_from_any_async, vx_test.t_resolve_testcase)
    )
    return output
  }

  /**
   * 
   * @async @function resolve_testdescribe
   * Resolves a testdescribe
   * @param  {testdescribe} testdescribe
   * @return {testdescribe}
   */
  static t_resolve_testdescribe = {}
  static e_resolve_testdescribe = {vx_type: vx_test.t_resolve_testdescribe}

  // (func resolve-testdescribe)
  static async f_resolve_testdescribe(testdescribe) {
    let output = Promise.resolve(vx_test.e_testdescribe)
    output = await vx_core.f_let_async(
      {"any-1": vx_test.t_testdescribe},
      [],
      vx_core.f_new(vx_core.t_any_from_func, async () => {
        const testresult = vx_core.f_any_from_struct({"any-1": vx_test.t_testresult, "struct-2": vx_test.t_testdescribe}, testdescribe, ":testresult")
        const resolved = await vx_test.f_resolve_testresult(testresult)
        return vx_core.f_copy(testdescribe, ":testresult", resolved)
      })
    )
    return output
  }

  /**
   * 
   * @async @function resolve_testdescribelist
   * Resolves a testdescribelist
   * @param  {testdescribelist} testdescribelist
   * @return {testdescribelist}
   */
  static t_resolve_testdescribelist = {}
  static e_resolve_testdescribelist = {vx_type: vx_test.t_resolve_testdescribelist}

  // (func resolve-testdescribelist)
  static async f_resolve_testdescribelist(testdescribelist) {
    let output = Promise.resolve(vx_test.e_testdescribelist)
    output = await vx_core.f_list_from_list_async(
      {"any-1": vx_test.t_testdescribe, "any-2": vx_test.t_testdescribe, "list-1": vx_test.t_testdescribelist, "list-2": vx_test.t_testdescribelist},
      testdescribelist,
      vx_core.f_new(vx_core.t_any_from_any_async, vx_test.t_resolve_testdescribe)
    )
    return output
  }

  /**
   * 
   * @async @function resolve_testpackage
   * Resolves a testpackage
   * @param  {testpackage} testpackage
   * @return {testpackage}
   */
  static t_resolve_testpackage = {}
  static e_resolve_testpackage = {vx_type: vx_test.t_resolve_testpackage}

  // (func resolve-testpackage)
  static async f_resolve_testpackage(testpackage) {
    let output = Promise.resolve(vx_test.e_testpackage)
    output = await vx_core.f_let_async(
      {"any-1": vx_test.t_testpackage},
      [],
      vx_core.f_new(vx_core.t_any_from_func, async () => {
        const testcaselist = vx_core.f_any_from_struct({"any-1": vx_test.t_testcaselist, "struct-2": vx_test.t_testpackage}, testpackage, ":caselist")
        const resolvedlist = await vx_test.f_resolve_testcaselist(testcaselist)
        const passfaillist = vx_core.f_list_from_list(
          {"any-1": vx_core.t_boolean, "any-2": vx_test.t_testcase, "list-1": vx_core.t_booleanlist, "list-2": vx_test.t_testcaselist, "struct-2": vx_test.t_testcase},
          resolvedlist,
          vx_core.f_new(vx_core.t_any_from_any, (testcase) => 
            vx_core.f_any_from_struct({"any-1": vx_core.t_boolean, "struct-2": vx_test.t_testcase}, testcase, ":passfail"))
        )
        const passfail = vx_core.f_and_1(passfaillist)
        return vx_core.f_copy(testpackage, ":passfail", passfail, ":caselist", resolvedlist)
      })
    )
    return output
  }

  /**
   * 
   * @async @function resolve_testpackagelist
   * Resolves a testpackagelist
   * @param  {testpackagelist} testpackagelist
   * @return {testpackagelist}
   */
  static t_resolve_testpackagelist = {}
  static e_resolve_testpackagelist = {vx_type: vx_test.t_resolve_testpackagelist}

  // (func resolve-testpackagelist)
  static async f_resolve_testpackagelist(testpackagelist) {
    let output = Promise.resolve(vx_test.e_testpackagelist)
    output = await vx_core.f_list_from_list_async(
      {"any-1": vx_test.t_testpackage, "any-2": vx_test.t_testpackage, "list-1": vx_test.t_testpackagelist, "list-2": vx_test.t_testpackagelist},
      testpackagelist,
      vx_core.f_new(vx_core.t_any_from_any_async, vx_test.t_resolve_testpackage)
    )
    return output
  }

  /**
   * 
   * @async @function resolve_testresult
   * Resolves a testresult
   * @param  {testresult} testresult
   * @return {testresult}
   */
  static t_resolve_testresult = {}
  static e_resolve_testresult = {vx_type: vx_test.t_resolve_testresult}

  // (func resolve-testresult)
  static async f_resolve_testresult(testresult) {
    let output = Promise.resolve(vx_test.e_testresult)
    output = await vx_core.f_let_async(
      {"any-1": vx_test.t_testresult, "struct-2": vx_test.t_testresult},
      [],
      vx_core.f_new(vx_core.t_any_from_func, async () => {
        const fn_actual = vx_core.f_any_from_struct({"any-1": vx_core.t_any_from_func_async, "struct-2": vx_test.t_testresult}, testresult, ":fn-actual")
        const expected = vx_core.f_any_from_struct({"any-1": vx_core.t_any, "struct-2": vx_test.t_testresult}, testresult, ":expected")
        const actual = await vx_core.f_resolve_async({"any-1": vx_core.t_any}, fn_actual)
        return vx_core.f_if_2(
          {"any-1": vx_test.t_testresult},
          vx_core.f_then(
            vx_core.f_new(vx_core.t_boolean_from_func, () => {return vx_core.f_is_empty_1(fn_actual)}),
            vx_core.f_new(vx_core.t_any_from_func, () => {return testresult})
          ),
          vx_core.f_else(
            vx_core.f_new(vx_core.t_any_from_func, () => {return vx_core.f_let(
              {"any-1": vx_test.t_testresult},
              [],
              vx_core.f_new(vx_core.t_any_from_func, () => {
                const passfail = vx_core.f_eq(expected, actual)
                return vx_core.f_copy(testresult, ":passfail", passfail, ":actual", actual)
              })
            )})
          )
        )
      })
    )
    return output
  }

  /**
   * @function security_test
   * Returns the default security for test case execution. Arguments come from the command line.
   * @return {security}
   */
  static t_security_test = {}
  static e_security_test = {vx_type: vx_test.t_security_test}

  // (func security-test)
  static f_security_test() {
    let output = vx_core.e_security
    output = vx_core.f_new(
      vx_core.t_security,
      ":allowfuncs",
      vx_core.f_new(
        vx_core.t_funclist,
        vx_data_file.t_boolean_write_from_file_any,
        vx_data_file.t_boolean_write_from_file_string,
        vx_data_file.t_file_read_from_file,
        vx_data_file.t_string_read_from_file
      )
    )
    return output
  }

  /**
   * @function test
   * Test expected equal actual
   * @param  {any} expected
   * @param  {any} actual
   * @return {testresult}
   */
  static t_test = {}
  static e_test = {vx_type: vx_test.t_test}

  // (func test)
  static f_test(context, expected, actual) {
    let output = vx_test.e_testresult
    try {
    output = vx_core.f_new(
        vx_test.t_testresult,
        ":code",
        ":eq",
        ":passfail",
        vx_core.f_eq(expected, actual),
        ":expected",
        expected,
        ":actual",
        actual
      )
    } catch (err) {
      console.log(err)
    }
    return output
  }

  /**
   * @function test
   * Async Test expected equal actual
   * @param  {any} expected
   * @param  {any_from_func_async} fn_actual
   * @return {testresult}
   */
  static t_test_1 = {}
  static e_test_1 = {vx_type: vx_test.t_test_1}

  // (func test)
  static f_test_1(context, expected, fn_actual) {
    let output = vx_test.e_testresult
    try {
    output = vx_core.f_new(
        vx_test.t_testresult,
        ":code",
        ":eq",
        ":expected",
        expected,
        ":fn-actual",
        fn_actual
      )
    } catch (err) {
      console.log(err)
    }
    return output
  }

  /**
   * @function test_false
   * Test expected to be false
   * @param  {any} actual
   * @return {testresult}
   */
  static t_test_false = {}
  static e_test_false = {vx_type: vx_test.t_test_false}

  // (func test-false)
  static f_test_false(context, actual) {
    let output = vx_test.e_testresult
    try {
    output = vx_core.f_new(
        vx_test.t_testresult,
        ":code",
        ":false",
        ":passfail",
        vx_core.f_eq(
          false,
          actual
        ),
        ":expected",
        false,
        ":actual",
        actual
      )
    } catch (err) {
      console.log(err)
    }
    return output
  }

  /**
   * @function test_false
   * Async Test expected to be false
   * @param  {any_from_func_async} fn_actual
   * @return {testresult}
   */
  static t_test_false_1 = {}
  static e_test_false_1 = {vx_type: vx_test.t_test_false_1}

  // (func test-false)
  static f_test_false_1(context, fn_actual) {
    let output = vx_test.e_testresult
    try {
    output = vx_core.f_new(
        vx_test.t_testresult,
        ":code",
        ":false",
        ":expected",
        false,
        ":fn-actual",
        fn_actual
      )
    } catch (err) {
      console.log(err)
    }
    return output
  }

  /**
   * @function test_gt
   * Test expected greater than actual
   * @param  {any} expected
   * @param  {any} actual
   * @return {testresult}
   */
  static t_test_gt = {}
  static e_test_gt = {vx_type: vx_test.t_test_gt}

  // (func test-gt)
  static f_test_gt(context, expected, actual) {
    let output = vx_test.e_testresult
    try {
    output = vx_core.f_new(
        vx_test.t_testresult,
        ":code",
        ":gt",
        ":passfail",
        vx_core.f_gt(expected, actual),
        ":expected",
        expected,
        ":actual",
        actual
      )
    } catch (err) {
      console.log(err)
    }
    return output
  }

  /**
   * @function test_gt
   * Async Test expected greater than actual
   * @param  {any} expected
   * @param  {any_from_func_async} fn_actual
   * @return {testresult}
   */
  static t_test_gt_1 = {}
  static e_test_gt_1 = {vx_type: vx_test.t_test_gt_1}

  // (func test-gt)
  static f_test_gt_1(context, expected, fn_actual) {
    let output = vx_test.e_testresult
    try {
    output = vx_core.f_new(
        vx_test.t_testresult,
        ":code",
        ":gt",
        ":expected",
        expected,
        ":fn-actual",
        fn_actual
      )
    } catch (err) {
      console.log(err)
    }
    return output
  }

  /**
   * @function test_ne
   * Test expected not equal actual
   * @param  {any} expected
   * @param  {any} actual
   * @return {testresult}
   */
  static t_test_ne = {}
  static e_test_ne = {vx_type: vx_test.t_test_ne}

  // (func test-ne)
  static f_test_ne(context, expected, actual) {
    let output = vx_test.e_testresult
    try {
    output = vx_core.f_new(
        vx_test.t_testresult,
        ":code",
        ":ne",
        ":passfail",
        vx_core.f_ne(expected, actual),
        ":expected",
        expected,
        ":actual",
        actual
      )
    } catch (err) {
      console.log(err)
    }
    return output
  }

  /**
   * @function test_ne
   * Async Test expected not equal actual
   * @param  {any} expected
   * @param  {any_from_func_async} fn_actual
   * @return {testresult}
   */
  static t_test_ne_1 = {}
  static e_test_ne_1 = {vx_type: vx_test.t_test_ne_1}

  // (func test-ne)
  static f_test_ne_1(context, expected, fn_actual) {
    let output = vx_test.e_testresult
    try {
    output = vx_core.f_new(
        vx_test.t_testresult,
        ":code",
        ":ne",
        ":expected",
        expected,
        ":fn-actual",
        fn_actual
      )
    } catch (err) {
      console.log(err)
    }
    return output
  }

  /**
   * @function test_string
   * Test that the string version of expected equal actual
   * @param  {any} expected
   * @param  {any} actual
   * @return {testresult}
   */
  static t_test_string = {}
  static e_test_string = {vx_type: vx_test.t_test_string}

  // (func test-string)
  static f_test_string(context, expected, actual) {
    let output = vx_test.e_testresult
    try {
    output = vx_core.f_new(
        vx_test.t_testresult,
        ":passfail",
        vx_core.f_eq(
          vx_core.f_string_from_any(expected),
          vx_core.f_string_from_any(actual)
        ),
        ":expected",
        expected,
        ":actual",
        actual
      )
    } catch (err) {
      console.log(err)
    }
    return output
  }

  /**
   * @function test_string
   * Async Test that the string version of expected equal actual
   * @param  {any} expected
   * @param  {any_from_func_async} fn_actual
   * @return {testresult}
   */
  static t_test_string_1 = {}
  static e_test_string_1 = {vx_type: vx_test.t_test_string_1}

  // (func test-string)
  static f_test_string_1(context, expected, fn_actual) {
    let output = vx_test.e_testresult
    try {
    output = vx_core.f_new(
        vx_test.t_testresult,
        ":code",
        ":string",
        ":expected",
        expected,
        ":fn-actual",
        fn_actual
      )
    } catch (err) {
      console.log(err)
    }
    return output
  }

  /**
   * @function test_true
   * Test expected to be true
   * @param  {any} actual
   * @return {testresult}
   */
  static t_test_true = {}
  static e_test_true = {vx_type: vx_test.t_test_true}

  // (func test-true)
  static f_test_true(context, actual) {
    let output = vx_test.e_testresult
    try {
    output = vx_core.f_new(
        vx_test.t_testresult,
        ":code",
        ":true",
        ":passfail",
        vx_core.f_eq(
          true,
          actual
        ),
        ":expected",
        true,
        ":actual",
        actual
      )
    } catch (err) {
      console.log(err)
    }
    return output
  }

  /**
   * @function test_true
   * Async Test expected to be true
   * @param  {any_from_func_async} fn_actual
   * @return {testresult}
   */
  static t_test_true_1 = {}
  static e_test_true_1 = {vx_type: vx_test.t_test_true_1}

  // (func test-true)
  static f_test_true_1(context, fn_actual) {
    let output = vx_test.e_testresult
    try {
    output = vx_core.f_new(
        vx_test.t_testresult,
        ":code",
        ":true",
        ":expected",
        true,
        ":fn-actual",
        fn_actual
      )
    } catch (err) {
      console.log(err)
    }
    return output
  }

  /**
   * @function tr_from_testdescribe_casename
   * Returns tr from a testdescribe
   * @param  {testdescribe} testdescribe
   * @param  {string} casename
   * @return {tr}
   */
  static t_tr_from_testdescribe_casename = {}
  static e_tr_from_testdescribe_casename = {vx_type: vx_test.t_tr_from_testdescribe_casename}

  // (func tr<-testdescribe-casename)
  static f_tr_from_testdescribe_casename(testdescribe, casename) {
    let output = vx_web_html.e_tr
    output = vx_core.f_let(
      {"any-1": vx_web_html.t_tr},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const describename = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_test.t_testdescribe}, testdescribe, ":describename")
        const result = vx_core.f_any_from_struct({"any-1": vx_test.t_testresult, "struct-2": vx_test.t_testdescribe}, testdescribe, ":testresult")
        const passfail = vx_core.f_any_from_struct({"any-1": vx_core.t_boolean, "struct-2": vx_test.t_testresult}, result, ":passfail")
        const expected = vx_core.f_string_from_any(
          vx_core.f_any_from_struct({"any-1": vx_core.t_any, "struct-2": vx_test.t_testresult}, result, ":expected")
        )
        const actual = vx_core.f_string_from_any(
          vx_core.f_any_from_struct({"any-1": vx_core.t_any, "struct-2": vx_test.t_testresult}, result, ":actual")
        )
        const prestyle = vx_web_html.f_style_from_stylesheet_name(
          vx_test.c_stylesheet_test,
          ".preformatted"
        )
        return vx_core.f_new(
          vx_web_html.t_tr,
          vx_core.f_new(
            vx_web_html.t_td,
            vx_test.f_p_from_passfail(passfail)
          ),
          vx_core.f_new(
            vx_web_html.t_td,
            vx_core.f_new(
              vx_web_html.t_p,
              ":style",
              prestyle,
              ":text",
              casename
            )
          ),
          vx_core.f_new(
            vx_web_html.t_td,
            vx_core.f_new(
              vx_web_html.t_p,
              ":style",
              prestyle,
              ":text",
              describename
            )
          ),
          vx_core.f_new(
            vx_web_html.t_td,
            vx_core.f_new(
              vx_web_html.t_p,
              ":style",
              prestyle,
              ":text",
              expected
            )
          ),
          vx_core.f_new(
            vx_web_html.t_td,
            vx_core.f_new(
              vx_web_html.t_p,
              ":style",
              prestyle,
              ":text",
              actual
            )
          )
        )
      })
    )
    return output
  }

  /**
   * @function trlist_from_testcase
   * @param  {testcase} testcase
   * @return {trlist}
   */
  static t_trlist_from_testcase = {}
  static e_trlist_from_testcase = {vx_type: vx_test.t_trlist_from_testcase}

  // (func trlist<-testcase)
  static f_trlist_from_testcase(testcase) {
    let output = vx_web_html.e_trlist
    output = vx_core.f_let(
      {"any-1": vx_web_html.t_trlist, "any-2": vx_test.t_testdescribe, "list-1": vx_web_html.t_trlist, "list-2": vx_test.t_testdescribelist},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const describelist = vx_core.f_any_from_struct({"any-1": vx_test.t_testdescribelist, "struct-2": vx_test.t_testcase}, testcase, ":describelist")
        const casename = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_test.t_testcase}, testcase, ":casename")
        return vx_core.f_list_from_list(
          {"any-1": vx_web_html.t_tr, "any-2": vx_test.t_testdescribe, "list-1": vx_web_html.t_trlist, "list-2": vx_test.t_testdescribelist},
          describelist,
          vx_core.f_new(vx_core.t_any_from_any, (testdescribe) => 
            vx_test.f_tr_from_testdescribe_casename(testdescribe, casename))
        )
      })
    )
    return output
  }

  /**
   * @function trlist_from_testcaselist
   * Returns a trlist from a testcaselist.
   * @param  {testcaselist} testcaselist
   * @return {trlist}
   */
  static t_trlist_from_testcaselist = {}
  static e_trlist_from_testcaselist = {vx_type: vx_test.t_trlist_from_testcaselist}

  // (func trlist<-testcaselist)
  static f_trlist_from_testcaselist(testcaselist) {
    let output = vx_web_html.e_trlist
    output = vx_core.f_list_join_from_list(
      {"any-1": vx_web_html.t_tr, "any-2": vx_test.t_testcase, "list-1": vx_web_html.t_trlist, "list-2": vx_test.t_testcaselist},
      testcaselist,
      vx_core.f_new(vx_core.t_any_from_any, vx_test.t_trlist_from_testcase)
    )
    return output
  }

  // empty types
  static e_testcase = {}
  static e_testcaselist = []
  static e_testcoveragedetail = {}
  static e_testcoveragenums = {}
  static e_testcoveragesummary = {}
  static e_testdescribe = {}
  static e_testdescribelist = []
  static e_testpackage = {}
  static e_testpackagelist = []
  static e_testresult = {}
  static e_testresultlist = []


  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      "stylesheet-test": vx_test.c_stylesheet_test
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "testcase": vx_test.e_testcase,
      "testcaselist": vx_test.e_testcaselist,
      "testcoveragedetail": vx_test.e_testcoveragedetail,
      "testcoveragenums": vx_test.e_testcoveragenums,
      "testcoveragesummary": vx_test.e_testcoveragesummary,
      "testdescribe": vx_test.e_testdescribe,
      "testdescribelist": vx_test.e_testdescribelist,
      "testpackage": vx_test.e_testpackage,
      "testpackagelist": vx_test.e_testpackagelist,
      "testresult": vx_test.e_testresult,
      "testresultlist": vx_test.e_testresultlist,
      "context-test": vx_test.e_context_test,
      "div<-testcaselist": vx_test.e_div_from_testcaselist,
      "div<-testpackage": vx_test.e_div_from_testpackage,
      "div<-testpackagelist": vx_test.e_div_from_testpackagelist,
      "divchildlist<-testpackagelist": vx_test.e_divchildlist_from_testpackagelist,
      "file-test": vx_test.e_file_test,
      "file-testhtml": vx_test.e_file_testhtml,
      "file-testnode": vx_test.e_file_testnode,
      "html<-divtest": vx_test.e_html_from_divtest,
      "p<-passfail": vx_test.e_p_from_passfail,
      "p<-testcoveragenums": vx_test.e_p_from_testcoveragenums,
      "resolve-testcase": vx_test.e_resolve_testcase,
      "resolve-testcaselist": vx_test.e_resolve_testcaselist,
      "resolve-testdescribe": vx_test.e_resolve_testdescribe,
      "resolve-testdescribelist": vx_test.e_resolve_testdescribelist,
      "resolve-testpackage": vx_test.e_resolve_testpackage,
      "resolve-testpackagelist": vx_test.e_resolve_testpackagelist,
      "resolve-testresult": vx_test.e_resolve_testresult,
      "security-test": vx_test.e_security_test,
      "test": vx_test.e_test,
      "test_1": vx_test.e_test_1,
      "test-false": vx_test.e_test_false,
      "test-false_1": vx_test.e_test_false_1,
      "test-gt": vx_test.e_test_gt,
      "test-gt_1": vx_test.e_test_gt_1,
      "test-ne": vx_test.e_test_ne,
      "test-ne_1": vx_test.e_test_ne_1,
      "test-string": vx_test.e_test_string,
      "test-string_1": vx_test.e_test_string_1,
      "test-true": vx_test.e_test_true,
      "test-true_1": vx_test.e_test_true_1,
      "tr<-testdescribe-casename": vx_test.e_tr_from_testdescribe_casename,
      "trlist<-testcase": vx_test.e_trlist_from_testcase,
      "trlist<-testcaselist": vx_test.e_trlist_from_testcaselist
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "context-test": vx_test.t_context_test,
      "div<-testcaselist": vx_test.t_div_from_testcaselist,
      "div<-testpackage": vx_test.t_div_from_testpackage,
      "div<-testpackagelist": vx_test.t_div_from_testpackagelist,
      "divchildlist<-testpackagelist": vx_test.t_divchildlist_from_testpackagelist,
      "file-test": vx_test.t_file_test,
      "file-testhtml": vx_test.t_file_testhtml,
      "file-testnode": vx_test.t_file_testnode,
      "html<-divtest": vx_test.t_html_from_divtest,
      "p<-passfail": vx_test.t_p_from_passfail,
      "p<-testcoveragenums": vx_test.t_p_from_testcoveragenums,
      "resolve-testcase": vx_test.t_resolve_testcase,
      "resolve-testcaselist": vx_test.t_resolve_testcaselist,
      "resolve-testdescribe": vx_test.t_resolve_testdescribe,
      "resolve-testdescribelist": vx_test.t_resolve_testdescribelist,
      "resolve-testpackage": vx_test.t_resolve_testpackage,
      "resolve-testpackagelist": vx_test.t_resolve_testpackagelist,
      "resolve-testresult": vx_test.t_resolve_testresult,
      "security-test": vx_test.t_security_test,
      "test": vx_test.t_test,
      "test_1": vx_test.t_test_1,
      "test-false": vx_test.t_test_false,
      "test-false_1": vx_test.t_test_false_1,
      "test-gt": vx_test.t_test_gt,
      "test-gt_1": vx_test.t_test_gt_1,
      "test-ne": vx_test.t_test_ne,
      "test-ne_1": vx_test.t_test_ne_1,
      "test-string": vx_test.t_test_string,
      "test-string_1": vx_test.t_test_string_1,
      "test-true": vx_test.t_test_true,
      "test-true_1": vx_test.t_test_true_1,
      "tr<-testdescribe-casename": vx_test.t_tr_from_testdescribe_casename,
      "trlist<-testcase": vx_test.t_trlist_from_testcase,
      "trlist<-testcaselist": vx_test.t_trlist_from_testcaselist
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      "testcase": vx_test.t_testcase,
      "testcaselist": vx_test.t_testcaselist,
      "testcoveragedetail": vx_test.t_testcoveragedetail,
      "testcoveragenums": vx_test.t_testcoveragenums,
      "testcoveragesummary": vx_test.t_testcoveragesummary,
      "testdescribe": vx_test.t_testdescribe,
      "testdescribelist": vx_test.t_testdescribelist,
      "testpackage": vx_test.t_testpackage,
      "testpackagelist": vx_test.t_testpackagelist,
      "testresult": vx_test.t_testresult,
      "testresultlist": vx_test.t_testresultlist
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/test",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

    // (type testcase)
    vx_test.t_testcase['vx_type'] = vx_core.t_type
    vx_test.t_testcase['vx_value'] = {
      name          : "testcase",
      pkgname       : "vx/test",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "passfail": {
          "name" : "passfail",
          "type" : vx_core.t_boolean,
          "multi": false
        },
        "testpkg": {
          "name" : "testpkg",
          "type" : vx_core.t_string,
          "multi": false
        },
        "casename": {
          "name" : "casename",
          "type" : vx_core.t_string,
          "multi": false
        },
        "describelist": {
          "name" : "describelist",
          "type" : vx_test.t_testdescribelist,
          "multi": false
        }
      },
      proplast      : {
        "name" : "describelist",
        "type" : vx_test.t_testdescribelist,
        "multi": false
      }
    }
    vx_test.e_testcase['vx_type'] = vx_test.t_testcase
    vx_test.e_testcase['vx_value'] = {}

    // (type testcaselist)
    vx_test.t_testcaselist['vx_type'] = vx_core.t_type
    vx_test.t_testcaselist['vx_value'] = {
      name          : "testcaselist",
      pkgname       : "vx/test",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_test.t_testcase],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_test.e_testcaselist['vx_type'] = vx_test.t_testcaselist

    // (type testcoveragedetail)
    vx_test.t_testcoveragedetail['vx_type'] = vx_core.t_type
    vx_test.t_testcoveragedetail['vx_value'] = {
      name          : "testcoveragedetail",
      pkgname       : "vx/test",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "constmap": {
          "name" : "constmap",
          "type" : vx_core.t_intmap,
          "multi": false
        },
        "funcmap": {
          "name" : "funcmap",
          "type" : vx_core.t_intmap,
          "multi": false
        },
        "testpkg": {
          "name" : "testpkg",
          "type" : vx_core.t_string,
          "multi": false
        },
        "typemap": {
          "name" : "typemap",
          "type" : vx_core.t_intmap,
          "multi": false
        }
      },
      proplast      : {
        "name" : "typemap",
        "type" : vx_core.t_intmap,
        "multi": false
      }
    }
    vx_test.e_testcoveragedetail['vx_type'] = vx_test.t_testcoveragedetail
    vx_test.e_testcoveragedetail['vx_value'] = {}

    // (type testcoveragenums)
    vx_test.t_testcoveragenums['vx_type'] = vx_core.t_type
    vx_test.t_testcoveragenums['vx_value'] = {
      name          : "testcoveragenums",
      pkgname       : "vx/test",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "pct": {
          "name" : "pct",
          "type" : vx_core.t_int,
          "multi": false
        },
        "testpkg": {
          "name" : "testpkg",
          "type" : vx_core.t_string,
          "multi": false
        },
        "tests": {
          "name" : "tests",
          "type" : vx_core.t_int,
          "multi": false
        },
        "total": {
          "name" : "total",
          "type" : vx_core.t_int,
          "multi": false
        }
      },
      proplast      : {
        "name" : "total",
        "type" : vx_core.t_int,
        "multi": false
      }
    }
    vx_test.e_testcoveragenums['vx_type'] = vx_test.t_testcoveragenums
    vx_test.e_testcoveragenums['vx_value'] = {}

    // (type testcoveragesummary)
    vx_test.t_testcoveragesummary['vx_type'] = vx_core.t_type
    vx_test.t_testcoveragesummary['vx_value'] = {
      name          : "testcoveragesummary",
      pkgname       : "vx/test",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "bigospacenums": {
          "name" : "bigospacenums",
          "type" : vx_test.t_testcoveragenums,
          "multi": false
        },
        "bigotimenums": {
          "name" : "bigotimenums",
          "type" : vx_test.t_testcoveragenums,
          "multi": false
        },
        "constnums": {
          "name" : "constnums",
          "type" : vx_test.t_testcoveragenums,
          "multi": false
        },
        "docnums": {
          "name" : "docnums",
          "type" : vx_test.t_testcoveragenums,
          "multi": false
        },
        "funcnums": {
          "name" : "funcnums",
          "type" : vx_test.t_testcoveragenums,
          "multi": false
        },
        "testpkg": {
          "name" : "testpkg",
          "type" : vx_core.t_string,
          "multi": false
        },
        "totalnums": {
          "name" : "totalnums",
          "type" : vx_test.t_testcoveragenums,
          "multi": false
        },
        "typenums": {
          "name" : "typenums",
          "type" : vx_test.t_testcoveragenums,
          "multi": false
        }
      },
      proplast      : {
        "name" : "typenums",
        "type" : vx_test.t_testcoveragenums,
        "multi": false
      }
    }
    vx_test.e_testcoveragesummary['vx_type'] = vx_test.t_testcoveragesummary
    vx_test.e_testcoveragesummary['vx_value'] = {}

    // (type testdescribe)
    vx_test.t_testdescribe['vx_type'] = vx_core.t_type
    vx_test.t_testdescribe['vx_value'] = {
      name          : "testdescribe",
      pkgname       : "vx/test",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "describename": {
          "name" : "describename",
          "type" : vx_core.t_string,
          "multi": false
        },
        "testpkg": {
          "name" : "testpkg",
          "type" : vx_core.t_string,
          "multi": false
        },
        "testresult": {
          "name" : "testresult",
          "type" : vx_test.t_testresult,
          "multi": false
        }
      },
      proplast      : {
        "name" : "testresult",
        "type" : vx_test.t_testresult,
        "multi": false
      }
    }
    vx_test.e_testdescribe['vx_type'] = vx_test.t_testdescribe
    vx_test.e_testdescribe['vx_value'] = {}

    // (type testdescribelist)
    vx_test.t_testdescribelist['vx_type'] = vx_core.t_type
    vx_test.t_testdescribelist['vx_value'] = {
      name          : "testdescribelist",
      pkgname       : "vx/test",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_test.t_testdescribe],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_test.e_testdescribelist['vx_type'] = vx_test.t_testdescribelist

    // (type testpackage)
    vx_test.t_testpackage['vx_type'] = vx_core.t_type
    vx_test.t_testpackage['vx_value'] = {
      name          : "testpackage",
      pkgname       : "vx/test",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "caselist": {
          "name" : "caselist",
          "type" : vx_test.t_testcaselist,
          "multi": false
        },
        "coveragedetail": {
          "name" : "coveragedetail",
          "type" : vx_test.t_testcoveragedetail,
          "multi": false
        },
        "coveragesummary": {
          "name" : "coveragesummary",
          "type" : vx_test.t_testcoveragesummary,
          "multi": false
        },
        "passfail": {
          "name" : "passfail",
          "type" : vx_core.t_boolean,
          "multi": false
        },
        "testpkg": {
          "name" : "testpkg",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "testpkg",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    vx_test.e_testpackage['vx_type'] = vx_test.t_testpackage
    vx_test.e_testpackage['vx_value'] = {}

    // (type testpackagelist)
    vx_test.t_testpackagelist['vx_type'] = vx_core.t_type
    vx_test.t_testpackagelist['vx_value'] = {
      name          : "testpackagelist",
      pkgname       : "vx/test",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_test.t_testpackage],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_test.e_testpackagelist['vx_type'] = vx_test.t_testpackagelist

    // (type testresult)
    vx_test.t_testresult['vx_type'] = vx_core.t_type
    vx_test.t_testresult['vx_value'] = {
      name          : "testresult",
      pkgname       : "vx/test",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "code": {
          "name" : "code",
          "type" : vx_core.t_string,
          "multi": false
        },
        "passfail": {
          "name" : "passfail",
          "type" : vx_core.t_boolean,
          "multi": false
        },
        "expected": {
          "name" : "expected",
          "type" : vx_core.t_any,
          "multi": false
        },
        "actual": {
          "name" : "actual",
          "type" : vx_core.t_any,
          "multi": false
        },
        "fn-actual": {
          "name" : "fn-actual",
          "type" : vx_core.t_any_from_func_async,
          "multi": false
        }
      },
      proplast      : {
        "name" : "fn-actual",
        "type" : vx_core.t_any_from_func_async,
        "multi": false
      }
    }
    vx_test.e_testresult['vx_type'] = vx_test.t_testresult
    vx_test.e_testresult['vx_value'] = {}

    // (type testresultlist)
    vx_test.t_testresultlist['vx_type'] = vx_core.t_type
    vx_test.t_testresultlist['vx_value'] = {
      name          : "testresultlist",
      pkgname       : "vx/test",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [vx_test.t_testresult],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    vx_test.e_testresultlist['vx_type'] = vx_test.t_testresultlist

    // (const stylesheet-test)
    Object.assign(vx_test.c_stylesheet_test, vx_web_html.f_stylesheet_loadmap(
      vx_core.f_new(
        vx_web_html.t_stylesheet,
        ":name",
        "Test Suite",
        ":styles",
        vx_core.f_new(
          vx_web_html.t_stylelist,
          vx_core.f_new(
            vx_web_html.t_style,
            ":name",
            "body",
            ":props",
            vx_core.f_new(
              vx_web_html.t_propmap,
              "font-size",
              "0.9em",
              "font-family",
              "sans-serif"
            )
          ),
          vx_core.f_new(
            vx_web_html.t_style,
            ":name",
            "details summary",
            ":props",
            vx_core.f_new(
              vx_web_html.t_propmap,
              "cursor",
              "pointer",
              "display",
              "inline-flex",
              "gap",
              "10px"
            )
          ),
          vx_core.f_new(
            vx_web_html.t_style,
            ":name",
            "table",
            ":props",
            vx_core.f_new(
              vx_web_html.t_propmap,
              "vertical-align",
              "top",
              "border-collapse",
              "collapse",
              "margin",
              "25px 0",
              "min-width",
              "400px",
              "box-shadow",
              "0 0 20px rgba(0, 0, 0, 0.15)"
            )
          ),
          vx_core.f_new(
            vx_web_html.t_style,
            ":name",
            "thead tr",
            ":props",
            vx_core.f_new(
              vx_web_html.t_propmap,
              "background-color",
              "#009879",
              "color",
              "#ffffff",
              "text-align",
              "left"
            )
          ),
          vx_core.f_new(
            vx_web_html.t_style,
            ":name",
            "td",
            ":props",
            vx_core.f_new(
              vx_web_html.t_propmap,
              "padding",
              "10px 10px",
              "vertical-align",
              "top"
            )
          ),
          vx_core.f_new(
            vx_web_html.t_style,
            ":name",
            "tbody tr",
            ":props",
            vx_core.f_new(
              vx_web_html.t_propmap,
              "border-bottom",
              "1px solid #dddddd"
            )
          ),
          vx_core.f_new(
            vx_web_html.t_style,
            ":name",
            "tbody tr:nth-of-type(even)",
            ":props",
            vx_core.f_new(
              vx_web_html.t_propmap,
              "background-color",
              "#f3f3f3"
            )
          ),
          vx_core.f_new(
            vx_web_html.t_style,
            ":name",
            "tbody tr:last-of-type",
            ":props",
            vx_core.f_new(
              vx_web_html.t_propmap,
              "border-bottom",
              "2px solid #009879"
            )
          ),
          vx_core.f_new(
            vx_web_html.t_style,
            ":name",
            "tbody tr.active-row",
            ":props",
            vx_core.f_new(
              vx_web_html.t_propmap,
              "font-weight",
              "bold",
              "color",
              "#009879"
            )
          ),
          vx_core.f_new(
            vx_web_html.t_style,
            ":name",
            ".failflag",
            ":props",
            vx_core.f_new(
              vx_web_html.t_propmap,
              "background-color",
              "red",
              "color",
              "white",
              "padding-left",
              "4px",
              "padding-right",
              "4px",
              "padding-top",
              "1px",
              "padding-bottom",
              "1px"
            )
          ),
          vx_core.f_new(
            vx_web_html.t_style,
            ":name",
            ".passflag",
            ":props",
            vx_core.f_new(
              vx_web_html.t_propmap,
              "background-color",
              "green",
              "color",
              "white",
              "padding-left",
              "4px",
              "padding-right",
              "4px",
              "padding-top",
              "1px",
              "padding-bottom",
              "1px"
            )
          ),
          vx_core.f_new(
            vx_web_html.t_style,
            ":name",
            ".coveragenums",
            ":props",
            vx_core.f_new(
              vx_web_html.t_propmap,
              "width",
              "90px"
            )
          ),
          vx_core.f_new(
            vx_web_html.t_style,
            ":name",
            ".coveragepct",
            ":props",
            vx_core.f_new(
              vx_web_html.t_propmap,
              "text-align",
              "right"
            )
          ),
          vx_core.f_new(
            vx_web_html.t_style,
            ":name",
            ".coveragepctgreen",
            ":props",
            vx_core.f_new(
              vx_web_html.t_propmap,
              "background-color",
              "green",
              "color",
              "white",
              "text-align",
              "right"
            )
          ),
          vx_core.f_new(
            vx_web_html.t_style,
            ":name",
            ".coveragepctred",
            ":props",
            vx_core.f_new(
              vx_web_html.t_propmap,
              "background-color",
              "red",
              "color",
              "white",
              "text-align",
              "right"
            )
          ),
          vx_core.f_new(
            vx_web_html.t_style,
            ":name",
            ".pkgheader",
            ":props",
            vx_core.f_new(
              vx_web_html.t_propmap,
              "display",
              "inline-flex",
              "gap",
              "10px"
            )
          ),
          vx_core.f_new(
            vx_web_html.t_style,
            ":name",
            ".pkgname",
            ":props",
            vx_core.f_new(
              vx_web_html.t_propmap,
              "font-weight",
              "bold",
              "width",
              "180px"
            )
          ),
          vx_core.f_new(
            vx_web_html.t_style,
            ":name",
            ".preformatted",
            ":props",
            vx_core.f_new(
              vx_web_html.t_propmap,
              "display",
              "block",
              "unicode-bidi",
              "embed",
              "font-family",
              "monospace",
              "white-space",
              "pre"
            )
          )
        )
      )
    ))

    // (func context-test)
    vx_test.t_context_test['vx_type'] = vx_core.t_type
    vx_test.t_context_test['vx_value'] = {
      name          : "context-test",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_context_test
    }

    // (func div<-testcaselist)
    vx_test.t_div_from_testcaselist['vx_type'] = vx_core.t_type
    vx_test.t_div_from_testcaselist['vx_value'] = {
      name          : "div<-testcaselist",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_div_from_testcaselist
    }

    // (func div<-testpackage)
    vx_test.t_div_from_testpackage['vx_type'] = vx_core.t_type
    vx_test.t_div_from_testpackage['vx_value'] = {
      name          : "div<-testpackage",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_div_from_testpackage
    }

    // (func div<-testpackagelist)
    vx_test.t_div_from_testpackagelist['vx_type'] = vx_core.t_type
    vx_test.t_div_from_testpackagelist['vx_value'] = {
      name          : "div<-testpackagelist",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_div_from_testpackagelist
    }

    // (func divchildlist<-testpackagelist)
    vx_test.t_divchildlist_from_testpackagelist['vx_type'] = vx_core.t_type
    vx_test.t_divchildlist_from_testpackagelist['vx_value'] = {
      name          : "divchildlist<-testpackagelist",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_divchildlist_from_testpackagelist
    }

    // (func html<-divtest)
    vx_test.t_html_from_divtest['vx_type'] = vx_core.t_type
    vx_test.t_html_from_divtest['vx_value'] = {
      name          : "html<-divtest",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_html_from_divtest
    }

    // (func p<-passfail)
    vx_test.t_p_from_passfail['vx_type'] = vx_core.t_type
    vx_test.t_p_from_passfail['vx_value'] = {
      name          : "p<-passfail",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_p_from_passfail
    }

    // (func p<-testcoveragenums)
    vx_test.t_p_from_testcoveragenums['vx_type'] = vx_core.t_type
    vx_test.t_p_from_testcoveragenums['vx_value'] = {
      name          : "p<-testcoveragenums",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_p_from_testcoveragenums
    }

    // (func resolve-testcase)
    vx_test.t_resolve_testcase['vx_type'] = vx_core.t_type
    vx_test.t_resolve_testcase['vx_value'] = {
      name          : "resolve-testcase",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_resolve_testcase
    }

    // (func resolve-testcaselist)
    vx_test.t_resolve_testcaselist['vx_type'] = vx_core.t_type
    vx_test.t_resolve_testcaselist['vx_value'] = {
      name          : "resolve-testcaselist",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_resolve_testcaselist
    }

    // (func resolve-testdescribe)
    vx_test.t_resolve_testdescribe['vx_type'] = vx_core.t_type
    vx_test.t_resolve_testdescribe['vx_value'] = {
      name          : "resolve-testdescribe",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_resolve_testdescribe
    }

    // (func resolve-testdescribelist)
    vx_test.t_resolve_testdescribelist['vx_type'] = vx_core.t_type
    vx_test.t_resolve_testdescribelist['vx_value'] = {
      name          : "resolve-testdescribelist",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_resolve_testdescribelist
    }

    // (func resolve-testpackage)
    vx_test.t_resolve_testpackage['vx_type'] = vx_core.t_type
    vx_test.t_resolve_testpackage['vx_value'] = {
      name          : "resolve-testpackage",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_resolve_testpackage
    }

    // (func resolve-testpackagelist)
    vx_test.t_resolve_testpackagelist['vx_type'] = vx_core.t_type
    vx_test.t_resolve_testpackagelist['vx_value'] = {
      name          : "resolve-testpackagelist",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_resolve_testpackagelist
    }

    // (func resolve-testresult)
    vx_test.t_resolve_testresult['vx_type'] = vx_core.t_type
    vx_test.t_resolve_testresult['vx_value'] = {
      name          : "resolve-testresult",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_resolve_testresult
    }

    // (func security-test)
    vx_test.t_security_test['vx_type'] = vx_core.t_type
    vx_test.t_security_test['vx_value'] = {
      name          : "security-test",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_security_test
    }

    // (func test)
    vx_test.t_test['vx_type'] = vx_core.t_type
    vx_test.t_test['vx_value'] = {
      name          : "test",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_test
    }

    // (func test)
    vx_test.t_test_1['vx_type'] = vx_core.t_type
    vx_test.t_test_1['vx_value'] = {
      name          : "test",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 1,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_test_1
    }

    // (func test-false)
    vx_test.t_test_false['vx_type'] = vx_core.t_type
    vx_test.t_test_false['vx_value'] = {
      name          : "test-false",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_test_false
    }

    // (func test-false)
    vx_test.t_test_false_1['vx_type'] = vx_core.t_type
    vx_test.t_test_false_1['vx_value'] = {
      name          : "test-false",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 1,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_test_false_1
    }

    // (func test-gt)
    vx_test.t_test_gt['vx_type'] = vx_core.t_type
    vx_test.t_test_gt['vx_value'] = {
      name          : "test-gt",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_test_gt
    }

    // (func test-gt)
    vx_test.t_test_gt_1['vx_type'] = vx_core.t_type
    vx_test.t_test_gt_1['vx_value'] = {
      name          : "test-gt",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 1,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_test_gt_1
    }

    // (func test-ne)
    vx_test.t_test_ne['vx_type'] = vx_core.t_type
    vx_test.t_test_ne['vx_value'] = {
      name          : "test-ne",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_test_ne
    }

    // (func test-ne)
    vx_test.t_test_ne_1['vx_type'] = vx_core.t_type
    vx_test.t_test_ne_1['vx_value'] = {
      name          : "test-ne",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 1,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_test_ne_1
    }

    // (func test-string)
    vx_test.t_test_string['vx_type'] = vx_core.t_type
    vx_test.t_test_string['vx_value'] = {
      name          : "test-string",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_test_string
    }

    // (func test-string)
    vx_test.t_test_string_1['vx_type'] = vx_core.t_type
    vx_test.t_test_string_1['vx_value'] = {
      name          : "test-string",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 1,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_test_string_1
    }

    // (func test-true)
    vx_test.t_test_true['vx_type'] = vx_core.t_type
    vx_test.t_test_true['vx_value'] = {
      name          : "test-true",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_test_true
    }

    // (func test-true)
    vx_test.t_test_true_1['vx_type'] = vx_core.t_type
    vx_test.t_test_true_1['vx_value'] = {
      name          : "test-true",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 1,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_test_true_1
    }

    // (func tr<-testdescribe-casename)
    vx_test.t_tr_from_testdescribe_casename['vx_type'] = vx_core.t_type
    vx_test.t_tr_from_testdescribe_casename['vx_value'] = {
      name          : "tr<-testdescribe-casename",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_tr_from_testdescribe_casename
    }

    // (func trlist<-testcase)
    vx_test.t_trlist_from_testcase['vx_type'] = vx_core.t_type
    vx_test.t_trlist_from_testcase['vx_value'] = {
      name          : "trlist<-testcase",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_trlist_from_testcase
    }

    // (func trlist<-testcaselist)
    vx_test.t_trlist_from_testcaselist['vx_type'] = vx_core.t_type
    vx_test.t_trlist_from_testcaselist['vx_value'] = {
      name          : "trlist<-testcaselist",
      pkgname       : "vx/test",
      extends       : ":func",
      idx           : 0,
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : [],
      proplast      : {},
      fn            : vx_test.f_trlist_from_testcaselist
    }

  }
}
