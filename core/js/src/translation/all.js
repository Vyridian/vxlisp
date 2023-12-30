'strict mode'

import vx_core from "../vx/core.js"
import vx_translate from "../vx/translate.js"
import vx_translation_es from "../vx/translation/es.js"

export default class translation_all {
  /**
   * @function translationmap_all
   * Returns a translationmap with all translations.
   * @return {translationmap}
   */
  static t_translationmap_all = {}
  static e_translationmap_all = {vx_type: translation_all.t_translationmap_all}

  // (func translationmap-all)
  static f_translationmap_all() {
    let output = vx_core.e_translationmap
    output = vx_translate.f_translationmap_from_translations(
      vx_translation_es.f_translationdata()
    )
    return output
  }

  // empty types


  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "translationmap-all": translation_all.e_translationmap_all
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "translationmap-all": translation_all.t_translationmap_all
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "translation/all",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

    // (func translationmap-all)
    translation_all.t_translationmap_all['vx_type'] = vx_core.t_type
    translation_all.t_translationmap_all['vx_value'] = {
      name          : "translationmap-all",
      pkgname       : "translation/all",
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
      fn            : translation_all.f_translationmap_all
    }

  }
}
