'strict mode'

import vx_core from "../../vx/core.js"
import vx_translate from "../../vx/translate.js"

export default class vx_translation_es {
  /**
   * @function translation_es
   * Returns translation data
   * @return {translation}
   */
  static t_translation_es = {}
  static e_translation_es = {vx_type: vx_translation_es.t_translation_es}

  // (func translation-es)
  static f_translation_es() {
    let output = vx_core.e_translation
    output = vx_core.f_new(
      vx_core.t_translation,
      ":name",
      "es",
      ":wordmap",
      vx_translation_es.f_words()
    )
    return output
  }

  /**
   * @function words
   * Word Translation
   * @return {stringmap}
   */
  static t_words = {}
  static e_words = {vx_type: vx_translation_es.t_words}

  // (func words)
  static f_words() {
    let output = vx_core.e_stringmap
    output = vx_core.f_new(
      vx_core.t_stringmap,
      "Hello",
      "Hola",
      "World",
      "Mundo"
    )
    return output
  }

  // empty types


  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "translation-es": vx_translation_es.e_translation_es,
      "words": vx_translation_es.e_words
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "translation-es": vx_translation_es.t_translation_es,
      "words": vx_translation_es.t_words
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/translation/es",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

    // (func translation-es)
    vx_translation_es.t_translation_es['vx_type'] = vx_core.t_type
    vx_translation_es.t_translation_es['vx_value'] = {
      name          : "translation-es",
      pkgname       : "vx/translation/es",
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
      fn            : vx_translation_es.f_translation_es
    }

    // (func words)
    vx_translation_es.t_words['vx_type'] = vx_core.t_type
    vx_translation_es.t_words['vx_value'] = {
      name          : "words",
      pkgname       : "vx/translation/es",
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
      fn            : vx_translation_es.f_words
    }

  }
}
