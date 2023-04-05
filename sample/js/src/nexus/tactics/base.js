'strict mode'

import vx_core from "../../vx/core.js"
import vx_web_html from "../../vx/web/html.js"
import vx_data_textblock from "../../vx/data/textblock.js"
import vx_data_xml from "../../vx/data/xml.js"

export default class nexus_tactics_base {

  /**
   * type: ability
   */
  static t_ability = {}

  /**
   * type: abilitylist
   */
  static t_abilitylist = {}

  /**
   * type: book
   */
  static t_book = {}

  /**
   * type: booklist
   */
  static t_booklist = {}

  /**
   * type: card
   */
  static t_card = {}

  /**
   * type: cardlist
   */
  static t_cardlist = {}

  /**
   * type: chapter
   */
  static t_chapter = {}

  /**
   * type: chapterlist
   */
  static t_chapterlist = {}

  /**
   * type: deck
   */
  static t_deck = {}

  /**
   * type: decklist
   */
  static t_decklist = {}

  /**
   * type: item
   */
  static t_item = {}

  /**
   * type: itemlist
   */
  static t_itemlist = {}

  /**
   * type: location
   */
  static t_location = {}

  /**
   * type: locationlist
   */
  static t_locationlist = {}

  /**
   * type: playingcard
   */
  static t_playingcard = {}

  /**
   * type: power
   */
  static t_power = {}

  /**
   * type: powerlist
   */
  static t_powerlist = {}

  /**
   * type: rank
   */
  static t_rank = {}

  /**
   * type: rating
   */
  static t_rating = {}

  /**
   * type: rule
   */
  static t_rule = {}

  /**
   * type: rulelist
   */
  static t_rulelist = {}

  /**
   * type: scenario
   */
  static t_scenario = {}

  /**
   * type: scenariolist
   */
  static t_scenariolist = {}

  /**
   * type: section
   */
  static t_section = {}

  /**
   * type: sectionlist
   */
  static t_sectionlist = {}

  /**
   * type: skill
   */
  static t_skill = {}

  /**
   * type: skilllist
   */
  static t_skilllist = {}

  /**
   * type: specialty
   */
  static t_specialty = {}

  /**
   * type: specialtylist
   */
  static t_specialtylist = {}

  /**
   * type: suit
   */
  static t_suit = {}

  /**
   * type: suitlist
   */
  static t_suitlist = {}

  /**
   * type: unit
   */
  static t_unit = {}

  /**
   * type: unitlist
   */
  static t_unitlist = {}
  /**
   * Constant: card-ace-spade
   * {playingcard}
   */
  static c_card_ace_spade = {vx_type: nexus_tactics_base.t_playingcard}

  /**
   * Constant: rank-ace
   * {rank}
   */
  static c_rank_ace = {vx_type: nexus_tactics_base.t_rank}

  /**
   * Constant: suit-club
   * {suit}
   */
  static c_suit_club = {vx_type: nexus_tactics_base.t_suit}

  /**
   * Constant: suit-diamond
   * {suit}
   */
  static c_suit_diamond = {vx_type: nexus_tactics_base.t_suit}

  /**
   * Constant: suit-heart
   * {suit}
   */
  static c_suit_heart = {vx_type: nexus_tactics_base.t_suit}

  /**
   * Constant: suit-spade
   * {suit}
   */
  static c_suit_spade = {vx_type: nexus_tactics_base.t_suit}

  // empty types
  static e_ability = {}
  static e_abilitylist = []
  static e_book = {}
  static e_booklist = []
  static e_card = {}
  static e_cardlist = []
  static e_chapter = {}
  static e_chapterlist = []
  static e_deck = {}
  static e_decklist = []
  static e_item = {}
  static e_itemlist = []
  static e_location = {}
  static e_locationlist = []
  static e_playingcard = {}
  static e_power = {}
  static e_powerlist = []
  static e_rank = {}
  static e_rating = {}
  static e_rule = {}
  static e_rulelist = []
  static e_scenario = {}
  static e_scenariolist = []
  static e_section = {}
  static e_sectionlist = []
  static e_skill = {}
  static e_skilllist = []
  static e_specialty = {}
  static e_specialtylist = []
  static e_suit = {}
  static e_suitlist = []
  static e_unit = {}
  static e_unitlist = []

  static c_empty = {
    "ability": nexus_tactics_base.e_ability,
    "abilitylist": nexus_tactics_base.e_abilitylist,
    "book": nexus_tactics_base.e_book,
    "booklist": nexus_tactics_base.e_booklist,
    "card": nexus_tactics_base.e_card,
    "cardlist": nexus_tactics_base.e_cardlist,
    "chapter": nexus_tactics_base.e_chapter,
    "chapterlist": nexus_tactics_base.e_chapterlist,
    "deck": nexus_tactics_base.e_deck,
    "decklist": nexus_tactics_base.e_decklist,
    "item": nexus_tactics_base.e_item,
    "itemlist": nexus_tactics_base.e_itemlist,
    "location": nexus_tactics_base.e_location,
    "locationlist": nexus_tactics_base.e_locationlist,
    "playingcard": nexus_tactics_base.e_playingcard,
    "power": nexus_tactics_base.e_power,
    "powerlist": nexus_tactics_base.e_powerlist,
    "rank": nexus_tactics_base.e_rank,
    "rating": nexus_tactics_base.e_rating,
    "rule": nexus_tactics_base.e_rule,
    "rulelist": nexus_tactics_base.e_rulelist,
    "scenario": nexus_tactics_base.e_scenario,
    "scenariolist": nexus_tactics_base.e_scenariolist,
    "section": nexus_tactics_base.e_section,
    "sectionlist": nexus_tactics_base.e_sectionlist,
    "skill": nexus_tactics_base.e_skill,
    "skilllist": nexus_tactics_base.e_skilllist,
    "specialty": nexus_tactics_base.e_specialty,
    "specialtylist": nexus_tactics_base.e_specialtylist,
    "suit": nexus_tactics_base.e_suit,
    "suitlist": nexus_tactics_base.e_suitlist,
    "unit": nexus_tactics_base.e_unit,
    "unitlist": nexus_tactics_base.e_unitlist
  }


  static {
    vx_core.f_global_package_set("nexus/tactics/base", nexus_tactics_base)

    // (type ability)
    nexus_tactics_base.t_ability['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_ability['vx_value'] = {
      name          : "ability",
      pkgname       : "nexus/tactics/base",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [nexus_tactics_base.t_card],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "titles": {
          "name" : "titles",
          "type" : vx_core.t_string,
          "multi": false
        },
        "references": {
          "name" : "references",
          "type" : vx_core.t_string,
          "multi": false
        },
        "summary": {
          "name" : "summary",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "summary",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    nexus_tactics_base.e_ability['vx_type'] = nexus_tactics_base.t_ability
    nexus_tactics_base.e_ability['vx_value'] = {}

    // (type abilitylist)
    nexus_tactics_base.t_abilitylist['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_abilitylist['vx_value'] = {
      name          : "abilitylist",
      pkgname       : "nexus/tactics/base",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [nexus_tactics_base.t_ability],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    nexus_tactics_base.e_abilitylist['vx_type'] = nexus_tactics_base.t_abilitylist

    // (type book)
    nexus_tactics_base.t_book['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_book['vx_value'] = {
      name          : "book",
      pkgname       : "nexus/tactics/base",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [nexus_tactics_base.t_card],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "titles": {
          "name" : "titles",
          "type" : vx_core.t_string,
          "multi": false
        },
        "references": {
          "name" : "references",
          "type" : vx_core.t_string,
          "multi": false
        },
        "summary": {
          "name" : "summary",
          "type" : vx_core.t_string,
          "multi": false
        },
        "chapterlist": {
          "name" : "chapterlist",
          "type" : nexus_tactics_base.t_chapterlist,
          "multi": false
        }
      },
      proplast      : {
        "name" : "chapterlist",
        "type" : nexus_tactics_base.t_chapterlist,
        "multi": false
      }
    }
    nexus_tactics_base.e_book['vx_type'] = nexus_tactics_base.t_book
    nexus_tactics_base.e_book['vx_value'] = {}

    // (type booklist)
    nexus_tactics_base.t_booklist['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_booklist['vx_value'] = {
      name          : "booklist",
      pkgname       : "nexus/tactics/base",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [nexus_tactics_base.t_book],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    nexus_tactics_base.e_booklist['vx_type'] = nexus_tactics_base.t_booklist

    // (type card)
    nexus_tactics_base.t_card['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_card['vx_value'] = {
      name          : "card",
      pkgname       : "nexus/tactics/base",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "titles": {
          "name" : "titles",
          "type" : vx_core.t_string,
          "multi": false
        },
        "references": {
          "name" : "references",
          "type" : vx_core.t_string,
          "multi": false
        },
        "summary": {
          "name" : "summary",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "summary",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    nexus_tactics_base.e_card['vx_type'] = nexus_tactics_base.t_card
    nexus_tactics_base.e_card['vx_value'] = {}

    // (type cardlist)
    nexus_tactics_base.t_cardlist['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_cardlist['vx_value'] = {
      name          : "cardlist",
      pkgname       : "nexus/tactics/base",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [nexus_tactics_base.t_card],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    nexus_tactics_base.e_cardlist['vx_type'] = nexus_tactics_base.t_cardlist

    // (type chapter)
    nexus_tactics_base.t_chapter['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_chapter['vx_value'] = {
      name          : "chapter",
      pkgname       : "nexus/tactics/base",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [nexus_tactics_base.t_card],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "titles": {
          "name" : "titles",
          "type" : vx_core.t_string,
          "multi": false
        },
        "references": {
          "name" : "references",
          "type" : vx_core.t_string,
          "multi": false
        },
        "summary": {
          "name" : "summary",
          "type" : vx_core.t_string,
          "multi": false
        },
        "sectionlist": {
          "name" : "sectionlist",
          "type" : nexus_tactics_base.t_sectionlist,
          "multi": false
        }
      },
      proplast      : {
        "name" : "sectionlist",
        "type" : nexus_tactics_base.t_sectionlist,
        "multi": false
      }
    }
    nexus_tactics_base.e_chapter['vx_type'] = nexus_tactics_base.t_chapter
    nexus_tactics_base.e_chapter['vx_value'] = {}

    // (type chapterlist)
    nexus_tactics_base.t_chapterlist['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_chapterlist['vx_value'] = {
      name          : "chapterlist",
      pkgname       : "nexus/tactics/base",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [nexus_tactics_base.t_chapter],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    nexus_tactics_base.e_chapterlist['vx_type'] = nexus_tactics_base.t_chapterlist

    // (type deck)
    nexus_tactics_base.t_deck['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_deck['vx_value'] = {
      name          : "deck",
      pkgname       : "nexus/tactics/base",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [nexus_tactics_base.t_card],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "titles": {
          "name" : "titles",
          "type" : vx_core.t_string,
          "multi": false
        },
        "references": {
          "name" : "references",
          "type" : vx_core.t_string,
          "multi": false
        },
        "summary": {
          "name" : "summary",
          "type" : vx_core.t_string,
          "multi": false
        },
        "cardlist": {
          "name" : "cardlist",
          "type" : nexus_tactics_base.t_cardlist,
          "multi": false
        }
      },
      proplast      : {
        "name" : "cardlist",
        "type" : nexus_tactics_base.t_cardlist,
        "multi": false
      }
    }
    nexus_tactics_base.e_deck['vx_type'] = nexus_tactics_base.t_deck
    nexus_tactics_base.e_deck['vx_value'] = {}

    // (type decklist)
    nexus_tactics_base.t_decklist['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_decklist['vx_value'] = {
      name          : "decklist",
      pkgname       : "nexus/tactics/base",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [nexus_tactics_base.t_deck],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [nexus_tactics_base.t_card],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "titles": {
          "name" : "titles",
          "type" : vx_core.t_string,
          "multi": false
        },
        "references": {
          "name" : "references",
          "type" : vx_core.t_string,
          "multi": false
        },
        "summary": {
          "name" : "summary",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "summary",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    nexus_tactics_base.e_decklist['vx_type'] = nexus_tactics_base.t_decklist

    // (type item)
    nexus_tactics_base.t_item['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_item['vx_value'] = {
      name          : "item",
      pkgname       : "nexus/tactics/base",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [nexus_tactics_base.t_card],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "titles": {
          "name" : "titles",
          "type" : vx_core.t_string,
          "multi": false
        },
        "references": {
          "name" : "references",
          "type" : vx_core.t_string,
          "multi": false
        },
        "summary": {
          "name" : "summary",
          "type" : vx_core.t_string,
          "multi": false
        },
        "mass": {
          "name" : "mass",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "mass",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    nexus_tactics_base.e_item['vx_type'] = nexus_tactics_base.t_item
    nexus_tactics_base.e_item['vx_value'] = {}

    // (type itemlist)
    nexus_tactics_base.t_itemlist['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_itemlist['vx_value'] = {
      name          : "itemlist",
      pkgname       : "nexus/tactics/base",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [nexus_tactics_base.t_item],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    nexus_tactics_base.e_itemlist['vx_type'] = nexus_tactics_base.t_itemlist

    // (type location)
    nexus_tactics_base.t_location['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_location['vx_value'] = {
      name          : "location",
      pkgname       : "nexus/tactics/base",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [nexus_tactics_base.t_card],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "titles": {
          "name" : "titles",
          "type" : vx_core.t_string,
          "multi": false
        },
        "references": {
          "name" : "references",
          "type" : vx_core.t_string,
          "multi": false
        },
        "summary": {
          "name" : "summary",
          "type" : vx_core.t_string,
          "multi": false
        },
        "locationlist": {
          "name" : "locationlist",
          "type" : nexus_tactics_base.t_locationlist,
          "multi": false
        },
        "unitlist": {
          "name" : "unitlist",
          "type" : nexus_tactics_base.t_unitlist,
          "multi": false
        }
      },
      proplast      : {
        "name" : "unitlist",
        "type" : nexus_tactics_base.t_unitlist,
        "multi": false
      }
    }
    nexus_tactics_base.e_location['vx_type'] = nexus_tactics_base.t_location
    nexus_tactics_base.e_location['vx_value'] = {}

    // (type locationlist)
    nexus_tactics_base.t_locationlist['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_locationlist['vx_value'] = {
      name          : "locationlist",
      pkgname       : "nexus/tactics/base",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [nexus_tactics_base.t_location],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    nexus_tactics_base.e_locationlist['vx_type'] = nexus_tactics_base.t_locationlist

    // (type playingcard)
    nexus_tactics_base.t_playingcard['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_playingcard['vx_value'] = {
      name          : "playingcard",
      pkgname       : "nexus/tactics/base",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [nexus_tactics_base.t_card],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "titles": {
          "name" : "titles",
          "type" : vx_core.t_string,
          "multi": false
        },
        "references": {
          "name" : "references",
          "type" : vx_core.t_string,
          "multi": false
        },
        "summary": {
          "name" : "summary",
          "type" : vx_core.t_string,
          "multi": false
        },
        "rank": {
          "name" : "rank",
          "type" : nexus_tactics_base.t_rank,
          "multi": false
        },
        "suit": {
          "name" : "suit",
          "type" : nexus_tactics_base.t_suit,
          "multi": false
        }
      },
      proplast      : {
        "name" : "suit",
        "type" : nexus_tactics_base.t_suit,
        "multi": false
      }
    }
    nexus_tactics_base.e_playingcard['vx_type'] = nexus_tactics_base.t_playingcard
    nexus_tactics_base.e_playingcard['vx_value'] = {}

    // (type power)
    nexus_tactics_base.t_power['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_power['vx_value'] = {
      name          : "power",
      pkgname       : "nexus/tactics/base",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [nexus_tactics_base.t_card],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "titles": {
          "name" : "titles",
          "type" : vx_core.t_string,
          "multi": false
        },
        "references": {
          "name" : "references",
          "type" : vx_core.t_string,
          "multi": false
        },
        "summary": {
          "name" : "summary",
          "type" : vx_core.t_string,
          "multi": false
        },
        "rating": {
          "name" : "rating",
          "type" : nexus_tactics_base.t_rating,
          "multi": false
        },
        "abilitylist": {
          "name" : "abilitylist",
          "type" : nexus_tactics_base.t_abilitylist,
          "multi": false
        },
        "specialtylist": {
          "name" : "specialtylist",
          "type" : nexus_tactics_base.t_specialtylist,
          "multi": false
        }
      },
      proplast      : {
        "name" : "specialtylist",
        "type" : nexus_tactics_base.t_specialtylist,
        "multi": false
      }
    }
    nexus_tactics_base.e_power['vx_type'] = nexus_tactics_base.t_power
    nexus_tactics_base.e_power['vx_value'] = {}

    // (type powerlist)
    nexus_tactics_base.t_powerlist['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_powerlist['vx_value'] = {
      name          : "powerlist",
      pkgname       : "nexus/tactics/base",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [nexus_tactics_base.t_power],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    nexus_tactics_base.e_powerlist['vx_type'] = nexus_tactics_base.t_powerlist

    // (type rank)
    nexus_tactics_base.t_rank['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_rank['vx_value'] = {
      name          : "rank",
      pkgname       : "nexus/tactics/base",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [nexus_tactics_base.t_card],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "titles": {
          "name" : "titles",
          "type" : vx_core.t_string,
          "multi": false
        },
        "references": {
          "name" : "references",
          "type" : vx_core.t_string,
          "multi": false
        },
        "summary": {
          "name" : "summary",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "summary",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    nexus_tactics_base.e_rank['vx_type'] = nexus_tactics_base.t_rank
    nexus_tactics_base.e_rank['vx_value'] = {}

    // (type rating)
    nexus_tactics_base.t_rating['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_rating['vx_value'] = {
      name          : "rating",
      pkgname       : "nexus/tactics/base",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [nexus_tactics_base.t_card],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "titles": {
          "name" : "titles",
          "type" : vx_core.t_string,
          "multi": false
        },
        "references": {
          "name" : "references",
          "type" : vx_core.t_string,
          "multi": false
        },
        "summary": {
          "name" : "summary",
          "type" : vx_core.t_string,
          "multi": false
        },
        "level": {
          "name" : "level",
          "type" : vx_core.t_int,
          "multi": false
        },
        "scale": {
          "name" : "scale",
          "type" : vx_core.t_int,
          "multi": false
        }
      },
      proplast      : {
        "name" : "scale",
        "type" : vx_core.t_int,
        "multi": false
      }
    }
    nexus_tactics_base.e_rating['vx_type'] = nexus_tactics_base.t_rating
    nexus_tactics_base.e_rating['vx_value'] = {}

    // (type rule)
    nexus_tactics_base.t_rule['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_rule['vx_value'] = {
      name          : "rule",
      pkgname       : "nexus/tactics/base",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [nexus_tactics_base.t_card],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "titles": {
          "name" : "titles",
          "type" : vx_core.t_string,
          "multi": false
        },
        "references": {
          "name" : "references",
          "type" : vx_core.t_string,
          "multi": false
        },
        "summary": {
          "name" : "summary",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "summary",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    nexus_tactics_base.e_rule['vx_type'] = nexus_tactics_base.t_rule
    nexus_tactics_base.e_rule['vx_value'] = {}

    // (type rulelist)
    nexus_tactics_base.t_rulelist['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_rulelist['vx_value'] = {
      name          : "rulelist",
      pkgname       : "nexus/tactics/base",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [nexus_tactics_base.t_rule],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    nexus_tactics_base.e_rulelist['vx_type'] = nexus_tactics_base.t_rulelist

    // (type scenario)
    nexus_tactics_base.t_scenario['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_scenario['vx_value'] = {
      name          : "scenario",
      pkgname       : "nexus/tactics/base",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [nexus_tactics_base.t_card],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "titles": {
          "name" : "titles",
          "type" : vx_core.t_string,
          "multi": false
        },
        "references": {
          "name" : "references",
          "type" : vx_core.t_string,
          "multi": false
        },
        "summary": {
          "name" : "summary",
          "type" : vx_core.t_string,
          "multi": false
        },
        "unitlist": {
          "name" : "unitlist",
          "type" : nexus_tactics_base.t_unitlist,
          "multi": false
        }
      },
      proplast      : {
        "name" : "unitlist",
        "type" : nexus_tactics_base.t_unitlist,
        "multi": false
      }
    }
    nexus_tactics_base.e_scenario['vx_type'] = nexus_tactics_base.t_scenario
    nexus_tactics_base.e_scenario['vx_value'] = {}

    // (type scenariolist)
    nexus_tactics_base.t_scenariolist['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_scenariolist['vx_value'] = {
      name          : "scenariolist",
      pkgname       : "nexus/tactics/base",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [nexus_tactics_base.t_scenario],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    nexus_tactics_base.e_scenariolist['vx_type'] = nexus_tactics_base.t_scenariolist

    // (type section)
    nexus_tactics_base.t_section['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_section['vx_value'] = {
      name          : "section",
      pkgname       : "nexus/tactics/base",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [nexus_tactics_base.t_card],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "titles": {
          "name" : "titles",
          "type" : vx_core.t_string,
          "multi": false
        },
        "references": {
          "name" : "references",
          "type" : vx_core.t_string,
          "multi": false
        },
        "summary": {
          "name" : "summary",
          "type" : vx_core.t_string,
          "multi": false
        },
        "decklist": {
          "name" : "decklist",
          "type" : nexus_tactics_base.t_decklist,
          "multi": false
        },
        "itemlist": {
          "name" : "itemlist",
          "type" : nexus_tactics_base.t_itemlist,
          "multi": false
        },
        "locationlist": {
          "name" : "locationlist",
          "type" : nexus_tactics_base.t_locationlist,
          "multi": false
        },
        "powerlist": {
          "name" : "powerlist",
          "type" : nexus_tactics_base.t_powerlist,
          "multi": false
        },
        "rulelist": {
          "name" : "rulelist",
          "type" : nexus_tactics_base.t_rulelist,
          "multi": false
        },
        "scenariolist": {
          "name" : "scenariolist",
          "type" : nexus_tactics_base.t_scenariolist,
          "multi": false
        },
        "sectionlist": {
          "name" : "sectionlist",
          "type" : nexus_tactics_base.t_sectionlist,
          "multi": false
        },
        "skilllist": {
          "name" : "skilllist",
          "type" : nexus_tactics_base.t_skilllist,
          "multi": false
        },
        "suitlist": {
          "name" : "suitlist",
          "type" : nexus_tactics_base.t_suitlist,
          "multi": false
        },
        "unitlist": {
          "name" : "unitlist",
          "type" : nexus_tactics_base.t_unitlist,
          "multi": false
        }
      },
      proplast      : {
        "name" : "unitlist",
        "type" : nexus_tactics_base.t_unitlist,
        "multi": false
      }
    }
    nexus_tactics_base.e_section['vx_type'] = nexus_tactics_base.t_section
    nexus_tactics_base.e_section['vx_value'] = {}

    // (type sectionlist)
    nexus_tactics_base.t_sectionlist['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_sectionlist['vx_value'] = {
      name          : "sectionlist",
      pkgname       : "nexus/tactics/base",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [nexus_tactics_base.t_section],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    nexus_tactics_base.e_sectionlist['vx_type'] = nexus_tactics_base.t_sectionlist

    // (type skill)
    nexus_tactics_base.t_skill['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_skill['vx_value'] = {
      name          : "skill",
      pkgname       : "nexus/tactics/base",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [nexus_tactics_base.t_card],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "titles": {
          "name" : "titles",
          "type" : vx_core.t_string,
          "multi": false
        },
        "references": {
          "name" : "references",
          "type" : vx_core.t_string,
          "multi": false
        },
        "summary": {
          "name" : "summary",
          "type" : vx_core.t_string,
          "multi": false
        },
        "rating": {
          "name" : "rating",
          "type" : nexus_tactics_base.t_rating,
          "multi": false
        },
        "abilitylist": {
          "name" : "abilitylist",
          "type" : nexus_tactics_base.t_abilitylist,
          "multi": false
        },
        "specialtylist": {
          "name" : "specialtylist",
          "type" : nexus_tactics_base.t_specialtylist,
          "multi": false
        }
      },
      proplast      : {
        "name" : "specialtylist",
        "type" : nexus_tactics_base.t_specialtylist,
        "multi": false
      }
    }
    nexus_tactics_base.e_skill['vx_type'] = nexus_tactics_base.t_skill
    nexus_tactics_base.e_skill['vx_value'] = {}

    // (type skilllist)
    nexus_tactics_base.t_skilllist['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_skilllist['vx_value'] = {
      name          : "skilllist",
      pkgname       : "nexus/tactics/base",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [nexus_tactics_base.t_skill],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    nexus_tactics_base.e_skilllist['vx_type'] = nexus_tactics_base.t_skilllist

    // (type specialty)
    nexus_tactics_base.t_specialty['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_specialty['vx_value'] = {
      name          : "specialty",
      pkgname       : "nexus/tactics/base",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [nexus_tactics_base.t_card],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "titles": {
          "name" : "titles",
          "type" : vx_core.t_string,
          "multi": false
        },
        "references": {
          "name" : "references",
          "type" : vx_core.t_string,
          "multi": false
        },
        "summary": {
          "name" : "summary",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "summary",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    nexus_tactics_base.e_specialty['vx_type'] = nexus_tactics_base.t_specialty
    nexus_tactics_base.e_specialty['vx_value'] = {}

    // (type specialtylist)
    nexus_tactics_base.t_specialtylist['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_specialtylist['vx_value'] = {
      name          : "specialtylist",
      pkgname       : "nexus/tactics/base",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [nexus_tactics_base.t_specialty],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [nexus_tactics_base.t_card],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "titles": {
          "name" : "titles",
          "type" : vx_core.t_string,
          "multi": false
        },
        "references": {
          "name" : "references",
          "type" : vx_core.t_string,
          "multi": false
        },
        "summary": {
          "name" : "summary",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "summary",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    nexus_tactics_base.e_specialtylist['vx_type'] = nexus_tactics_base.t_specialtylist

    // (type suit)
    nexus_tactics_base.t_suit['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_suit['vx_value'] = {
      name          : "suit",
      pkgname       : "nexus/tactics/base",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [nexus_tactics_base.t_card],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "titles": {
          "name" : "titles",
          "type" : vx_core.t_string,
          "multi": false
        },
        "references": {
          "name" : "references",
          "type" : vx_core.t_string,
          "multi": false
        },
        "summary": {
          "name" : "summary",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "summary",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    nexus_tactics_base.e_suit['vx_type'] = nexus_tactics_base.t_suit
    nexus_tactics_base.e_suit['vx_value'] = {}

    // (type suitlist)
    nexus_tactics_base.t_suitlist['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_suitlist['vx_value'] = {
      name          : "suitlist",
      pkgname       : "nexus/tactics/base",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [nexus_tactics_base.t_suit],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [nexus_tactics_base.t_card],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "titles": {
          "name" : "titles",
          "type" : vx_core.t_string,
          "multi": false
        },
        "references": {
          "name" : "references",
          "type" : vx_core.t_string,
          "multi": false
        },
        "summary": {
          "name" : "summary",
          "type" : vx_core.t_string,
          "multi": false
        }
      },
      proplast      : {
        "name" : "summary",
        "type" : vx_core.t_string,
        "multi": false
      }
    }
    nexus_tactics_base.e_suitlist['vx_type'] = nexus_tactics_base.t_suitlist

    // (type unit)
    nexus_tactics_base.t_unit['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_unit['vx_value'] = {
      name          : "unit",
      pkgname       : "nexus/tactics/base",
      extends       : ":struct",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [nexus_tactics_base.t_card],
      properties    : {
        "name": {
          "name" : "name",
          "type" : vx_core.t_string,
          "multi": false
        },
        "titles": {
          "name" : "titles",
          "type" : vx_core.t_string,
          "multi": false
        },
        "references": {
          "name" : "references",
          "type" : vx_core.t_string,
          "multi": false
        },
        "summary": {
          "name" : "summary",
          "type" : vx_core.t_string,
          "multi": false
        },
        "body": {
          "name" : "body",
          "type" : nexus_tactics_base.t_rating,
          "multi": false
        },
        "mind": {
          "name" : "mind",
          "type" : nexus_tactics_base.t_rating,
          "multi": false
        },
        "will": {
          "name" : "will",
          "type" : nexus_tactics_base.t_rating,
          "multi": false
        },
        "move": {
          "name" : "move",
          "type" : nexus_tactics_base.t_rating,
          "multi": false
        },
        "mass": {
          "name" : "mass",
          "type" : vx_core.t_string,
          "multi": false
        },
        "skills": {
          "name" : "skills",
          "type" : nexus_tactics_base.t_skilllist,
          "multi": false
        },
        "powers": {
          "name" : "powers",
          "type" : nexus_tactics_base.t_powerlist,
          "multi": false
        }
      },
      proplast      : {
        "name" : "powers",
        "type" : nexus_tactics_base.t_powerlist,
        "multi": false
      }
    }
    nexus_tactics_base.e_unit['vx_type'] = nexus_tactics_base.t_unit
    nexus_tactics_base.e_unit['vx_value'] = {}

    // (type unitlist)
    nexus_tactics_base.t_unitlist['vx_type'] = vx_core.t_type
    nexus_tactics_base.t_unitlist['vx_value'] = {
      name          : "unitlist",
      pkgname       : "nexus/tactics/base",
      extends       : ":list",
      allowfuncs    : [],
      disallowfuncs : [],
      allowtypes    : [nexus_tactics_base.t_unit],
      disallowtypes : [],
      allowvalues   : [],
      disallowvalues: [],
      traits        : [],
      properties    : {},
      proplast      : {}
    }
    nexus_tactics_base.e_unitlist['vx_type'] = nexus_tactics_base.t_unitlist

    // (const card-ace-spade)
    Object.assign(nexus_tactics_base.c_card_ace_spade, vx_core.f_new(
      nexus_tactics_base.t_playingcard,
      ":rank",
      nexus_tactics_base.c_rank_ace,
      ":suit",
      nexus_tactics_base.c_suit_spade
    ))

    // (const rank-ace)
    Object.assign(nexus_tactics_base.c_rank_ace, {
      "name": "",
      "titles": "",
      "references": "",
      "summary": "",
    })

    // (const suit-club)
    Object.assign(nexus_tactics_base.c_suit_club, {
      "name": "",
      "titles": "",
      "references": "",
      "summary": "",
    })

    // (const suit-diamond)
    Object.assign(nexus_tactics_base.c_suit_diamond, {
      "name": "",
      "titles": "",
      "references": "",
      "summary": "",
    })

    // (const suit-heart)
    Object.assign(nexus_tactics_base.c_suit_heart, {
      "name": "",
      "titles": "",
      "references": "",
      "summary": "",
    })

    // (const suit-spade)
    Object.assign(nexus_tactics_base.c_suit_spade, {
      "name": "",
      "titles": "",
      "references": "",
      "summary": "",
    })

  }
}
