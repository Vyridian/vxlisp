'strict mode'

import nexus_tactics_base from "../../../src/nexus/tactics/base.js"
import vx_core from "../../../src/vx/core.js"
import vx_test from "../../../src/vx/test.js"
import vx_web_html from "../../../src/vx/web/html.js"
import vx_data_textblock from "../../../src/vx/data/textblock.js"
import vx_data_xml from "../../../src/vx/data/xml.js"

export default class nexus_tactics_base_test {

  static test_package(context) {
    const testcaselist = nexus_tactics_base_test.test_cases(context)
    const output = vx_core.f_new(
      vx_test.t_testpackage,
      ":testpkg", "nexus/tactics/base",
      ":caselist", testcaselist,
      ":coveragesummary", nexus_tactics_base_test.test_coveragesummary(),
      ":coveragedetail", nexus_tactics_base_test.test_coveragedetail()
    );
    return output;
  }

  static test_coveragesummary() {
    return vx_core.f_new(
      vx_test.t_testcoveragesummary,
      "testpkg",   "nexus/tactics/base", 
      "constnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 6), 
      "docnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 39), 
      "funcnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigospacenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "bigotimenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 100, ":tests", 0, ":total", 0), 
      "totalnums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 39), 
      "typenums", vx_core.f_new(vx_test.t_testcoveragenums, ":pct", 0, ":tests", 0, ":total", 33)
    )
  }

  static test_coveragedetail() {
    return vx_core.f_new(
      vx_test.t_testcoveragedetail,
      "testpkg", "nexus/tactics/base",
      "typemap",
        vx_core.f_new(
          vx_core.t_intmap,
          "ability", 0,
          "abilitylist", 0,
          "book", 0,
          "booklist", 0,
          "card", 0,
          "cardlist", 0,
          "chapter", 0,
          "chapterlist", 0,
          "deck", 0,
          "decklist", 0,
          "item", 0,
          "itemlist", 0,
          "location", 0,
          "locationlist", 0,
          "playingcard", 0,
          "power", 0,
          "powerlist", 0,
          "rank", 0,
          "rating", 0,
          "rule", 0,
          "rulelist", 0,
          "scenario", 0,
          "scenariolist", 0,
          "section", 0,
          "sectionlist", 0,
          "skill", 0,
          "skilllist", 0,
          "specialty", 0,
          "specialtylist", 0,
          "suit", 0,
          "suitlist", 0,
          "unit", 0,
          "unitlist", 0
        ),
      "constmap",
        vx_core.f_new(
          vx_core.t_intmap,
          "card-ace-spade", 0,
          "rank-ace", 0,
          "suit-club", 0,
          "suit-diamond", 0,
          "suit-heart", 0,
          "suit-spade", 0
        ),
      "funcmap",
        vx_core.f_new(
          vx_core.t_intmap
        )
    )
  }

  static test_cases(context) {
    const output = vx_core.f_new(
      vx_test.t_testcaselist
    )
    return output
  }

}
