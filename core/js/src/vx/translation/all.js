'strict mode'

import vx_core from "../../vx/core.js"
import vx_translate from "../../vx/translate.js"
import vx_translation_en from "../../vx/translation/en.js"
import vx_translation_es from "../../vx/translation/es.js"

export default class vx_translation_all {
  /**
   * @function context_all
   * Returns the default context for app main execution. Arguments come from the command line.
   * @param  {anylist} ... args
   * @return {context}
   */
  static t_context_all = {}
  static e_context_all = {vx_type: vx_translation_all.t_context_all}

  // (func context-all)
  static f_context_all(...args) {
    let output = vx_core.e_context
    args = vx_core.f_new(vx_core.t_anylist, ...args)
    output = vx_core.f_new(
      vx_core.t_context,
      ":session",
      vx_core.f_new(
        vx_core.t_session,
        ":translation",
        vx_translation_en.f_translation_en(),
        ":translationmap",
        vx_translation_all.f_translationmap_all()
      )
    )
    return output
  }

  /**
   * @function translationmap_all
   * Returns a translationmap with all translations.
   * @return {translationmap}
   */
  static t_translationmap_all = {}
  static e_translationmap_all = {vx_type: vx_translation_all.t_translationmap_all}

  // (func translationmap-all)
  static f_translationmap_all() {
    let output = vx_core.e_translationmap
    output = vx_translate.f_translationmap_from_translations(
      vx_translation_en.f_translation_en(),
      vx_translation_es.f_translation_es()
    )
    return output
  }

  // empty types


  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "context-all": vx_translation_all.e_context_all,
      "translationmap-all": vx_translation_all.e_translationmap_all
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "context-all": vx_translation_all.t_context_all,
      "translationmap-all": vx_translation_all.t_translationmap_all
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/translation/all",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

    // (func context-all)
    vx_translation_all.t_context_all['vx_type'] = vx_core.t_type
    vx_translation_all.t_context_all['vx_value'] = {
      name          : "context-all",
      pkgname       : "vx/translation/all",
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
      fn            : vx_translation_all.f_context_all
    }

    // (func translationmap-all)
    vx_translation_all.t_translationmap_all['vx_type'] = vx_core.t_type
    vx_translation_all.t_translationmap_all['vx_value'] = {
      name          : "translationmap-all",
      pkgname       : "vx/translation/all",
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
      fn            : vx_translation_all.f_translationmap_all
    }

  }
}
