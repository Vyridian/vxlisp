'strict mode'

import vx_core from "../../vx/core.js"
import vx_translate from "../../vx/translate.js"

export default class vx_translation_en {
  /**
   * @function context_en
   * Returns the default context for app main execution. Arguments come from the command line.
   * @param  {anylist} ... args
   * @return {context}
   */
  static t_context_en = {}
  static e_context_en = {vx_type: vx_translation_en.t_context_en}

  // (func context-en)
  static f_context_en(...args) {
    let output = vx_core.e_context
    args = vx_core.f_new(vx_core.t_anylist, ...args)
    output = vx_core.f_new(
      vx_core.t_context,
      ":session",
      vx_core.f_new(
        vx_core.t_session,
        ":translation",
        vx_translation_en.f_translation_en()
      )
    )
    return output
  }

  /**
   * @function translation_en
   * Returns translation data
   * @return {translation}
   */
  static t_translation_en = {}
  static e_translation_en = {vx_type: vx_translation_en.t_translation_en}

  // (func translation-en)
  static f_translation_en() {
    let output = vx_core.e_translation
    output = vx_core.f_new(
      vx_core.t_translation,
      ":name",
      "en",
      ":wordmap",
      vx_translation_en.f_words()
    )
    return output
  }

  /**
   * @function words
   * Word Translation
   * @return {stringmap}
   */
  static t_words = {}
  static e_words = {vx_type: vx_translation_en.t_words}

  // (func words)
  static f_words() {
    let output = vx_core.e_stringmap
    output = vx_core.f_new(
      vx_core.t_stringmap,
      "Hello",
      "Hello",
      "World",
      "World"
    )
    return output
  }

  // empty types


  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "context-en": vx_translation_en.e_context_en,
      "translation-en": vx_translation_en.e_translation_en,
      "words": vx_translation_en.e_words
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "context-en": vx_translation_en.t_context_en,
      "translation-en": vx_translation_en.t_translation_en,
      "words": vx_translation_en.t_words
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/translation/en",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

    // (func context-en)
    vx_translation_en.t_context_en['vx_type'] = vx_core.t_type
    vx_translation_en.t_context_en['vx_value'] = {
      name          : "context-en",
      pkgname       : "vx/translation/en",
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
      fn            : vx_translation_en.f_context_en
    }

    // (func translation-en)
    vx_translation_en.t_translation_en['vx_type'] = vx_core.t_type
    vx_translation_en.t_translation_en['vx_value'] = {
      name          : "translation-en",
      pkgname       : "vx/translation/en",
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
      fn            : vx_translation_en.f_translation_en
    }

    // (func words)
    vx_translation_en.t_words['vx_type'] = vx_core.t_type
    vx_translation_en.t_words['vx_value'] = {
      name          : "words",
      pkgname       : "vx/translation/en",
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
      fn            : vx_translation_en.f_words
    }

  }
}
