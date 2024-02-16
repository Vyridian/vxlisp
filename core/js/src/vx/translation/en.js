'strict mode'

import vx_core from "../../vx/core.js"
import vx_data_file from "../../vx/data/file.js"
import vx_translate from "../../vx/translate.js"


export default class vx_translation_en {

  /**
   * @function context_en
   * Returns the default context for app main execution. Arguments come from the command line.
   * @param  {anylist} ... args
   * @return {context}
   */
  static t_context_en = {
    vx_type: vx_core.t_type
  }
  static e_context_en = {
    vx_type: vx_translation_en.t_context_en
  }

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
   * @function context_test
   * Returns the default context for test case execution. Arguments come from the command line.
   * @param  {anylist} ... args
   * @return {context}
   */
  static t_context_test = {
    vx_type: vx_core.t_type
  }
  static e_context_test = {
    vx_type: vx_translation_en.t_context_test
  }

  // (func context-test)
  static f_context_test(...args) {
    let output = vx_core.e_context
    args = vx_core.f_new(vx_core.t_anylist, ...args)
    output = vx_core.f_new(
      vx_core.t_context,
      ":session",
      vx_core.f_new(
        vx_core.t_session,
        ":translation",
        vx_translation_en.f_translation_en(),
        ":user",
        vx_core.f_new(
          vx_core.t_user,
          ":security",
          vx_translation_en.f_securitydata_test()
        )
      )
    )
    return output
  }

  /**
   * @function securitydata_test
   * Returns the default security for test case execution. Arguments come from the command line.
   * @return {security}
   */
  static t_securitydata_test = {
    vx_type: vx_core.t_type
  }
  static e_securitydata_test = {
    vx_type: vx_translation_en.t_securitydata_test
  }

  // (func securitydata-test)
  static f_securitydata_test() {
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
   * @function translation_en
   * Returns translation data
   * @return {translation}
   */
  static t_translation_en = {
    vx_type: vx_core.t_type
  }
  static e_translation_en = {
    vx_type: vx_translation_en.t_translation_en
  }

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
  static t_words = {
    vx_type: vx_core.t_type
  }
  static e_words = {
    vx_type: vx_translation_en.t_words
  }

  // (func words)
  static f_words() {
    let output = vx_core.e_stringmap
    output = vx_core.f_new(
      vx_core.t_stringmap,
      "Hello",
      "Hello",
      "World",
      "World",
      "!vx/core/func exception",
      "Exception in Function",
      "!vx/core/func permissiondenied",
      "Permission Denied to Function",
      "!vx/repl/repl/repl<-string-argmap repltypenotfound",
      "Repl Type Not Found"
    )
    return output
  }



  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "context-en": vx_translation_en.e_context_en,
      "context-test": vx_translation_en.e_context_test,
      "securitydata-test": vx_translation_en.e_securitydata_test,
      "translation-en": vx_translation_en.e_translation_en,
      "words": vx_translation_en.e_words
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "context-en": vx_translation_en.t_context_en,
      "context-test": vx_translation_en.t_context_test,
      "securitydata-test": vx_translation_en.t_securitydata_test,
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

    // (func context-test)
    vx_translation_en.t_context_test['vx_value'] = {
      name          : "context-test",
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
      fn            : vx_translation_en.f_context_test
    }

    // (func securitydata-test)
    vx_translation_en.t_securitydata_test['vx_value'] = {
      name          : "securitydata-test",
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
      fn            : vx_translation_en.f_securitydata_test
    }

    // (func translation-en)
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
