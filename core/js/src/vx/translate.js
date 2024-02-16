'strict mode'

import vx_core from "../vx/core.js"
import vx_data_csv from "../vx/data/csv.js"
import vx_data_file from "../vx/data/file.js"


export default class vx_translate {

  /**
   * @function session_from_session_name
   * Returns an updated session with a translationmap and a translation name.
   * @param  {session} session
   * @param  {string} name
   * @return {session}
   */
  static t_session_from_session_name = {
    vx_type: vx_core.t_type
  }
  static e_session_from_session_name = {
    vx_type: vx_translate.t_session_from_session_name
  }

  // (func session<-session-name)
  static f_session_from_session_name(session, name) {
    let output = vx_core.e_session
    output = vx_core.f_copy(
      session,
      ":translation",
      vx_translate.f_translation_from_session_name(session, name)
    )
    return output
  }

  /**
   * @function session_from_session_translation
   * Returns an updated session with a translation.
   * @param  {session} session
   * @param  {translation} translation
   * @return {session}
   */
  static t_session_from_session_translation = {
    vx_type: vx_core.t_type
  }
  static e_session_from_session_translation = {
    vx_type: vx_translate.t_session_from_session_translation
  }

  // (func session<-session-translation)
  static f_session_from_session_translation(session, translation) {
    let output = vx_core.e_session
    output = vx_core.f_copy(session, ":translation", translation)
    return output
  }

  /**
   * @function session_from_session_translationmap_name
   * Returns an updated session with a translationmap and a translation name.
   * @param  {session} session
   * @param  {translationmap} translationmap
   * @param  {string} name
   * @return {session}
   */
  static t_session_from_session_translationmap_name = {
    vx_type: vx_core.t_type
  }
  static e_session_from_session_translationmap_name = {
    vx_type: vx_translate.t_session_from_session_translationmap_name
  }

  // (func session<-session-translationmap-name)
  static f_session_from_session_translationmap_name(session, translationmap, name) {
    let output = vx_core.e_session
    output = vx_core.f_copy(
      session,
      ":translation",
      vx_core.f_any_from_map({"any-1": vx_core.t_translation, "map-1": vx_core.t_translationmap}, translationmap, name),
      ":translationmap",
      translationmap
    )
    return output
  }

  /**
   * @function translate
   * Returns a translated string from current context.
   * @param  {string} text
   * @return {string}
   */
  static t_translate = {
    vx_type: vx_core.t_type
  }
  static e_translate = {
    vx_type: vx_translate.t_translate
  }

  // (func translate)
  static f_translate(context, text) {
    let output = vx_core.e_string
    output = vx_translate.f_translate_from_translation_string(
      vx_translate.f_translation_from_context(context),
      text
    )
    return output
  }

  /**
   * @function translate
   * Returns a translated string from a msg.
   * @param  {msg} msg
   * @return {string}
   */
  static t_translate_1 = {
    vx_type: vx_core.t_type
  }
  static e_translate_1 = {
    vx_type: vx_translate.t_translate_1
  }

  // (func translate)
  static f_translate_1(context, msg) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const path = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_core.t_msg}, msg, ":path")
        const code = vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_core.t_msg}, msg, ":code")
        const text = vx_core.f_new(
          vx_core.t_string,
          "!",
          path,
          " ",
          code
        )
        return vx_translate.f_translate(context, text)
      })
    )
    return output
  }

  /**
   * @function translate_from_translation_string
   * Returns a translated string from a translation or the original text if not found.
   * @param  {translation} translation
   * @param  {string} text
   * @return {string}
   */
  static t_translate_from_translation_string = {
    vx_type: vx_core.t_type
  }
  static e_translate_from_translation_string = {
    vx_type: vx_translate.t_translate_from_translation_string
  }

  // (func translate<-translation-string)
  static f_translate_from_translation_string(translation, text) {
    let output = vx_core.e_string
    output = vx_core.f_if_1(
      {"any-1": vx_core.t_string},
      vx_core.f_is_empty_1(translation),
      text,
      vx_core.f_let(
        {"any-1": vx_core.t_string},
        [],
        vx_core.f_new(vx_core.t_any_from_func, () => {
          const wordmap = vx_core.f_any_from_struct({"any-1": vx_core.t_stringmap, "struct-2": vx_core.t_translation}, translation, ":wordmap")
          const xlate = vx_core.f_any_from_map({"any-1": vx_core.t_string, "map-1": vx_core.t_stringmap}, wordmap, text)
          return vx_core.f_if_1(
            {"any-1": vx_core.t_string},
            vx_core.f_is_empty(xlate),
            text,
            xlate
          )
        })
      )
    )
    return output
  }

  /**
   * @function translate_from_translationmap_name_string
   * Returns a translated string from a translation map given a translation name and text.
   * @param  {translationmap} translationmap
   * @param  {string} name
   * @param  {string} text
   * @return {string}
   */
  static t_translate_from_translationmap_name_string = {
    vx_type: vx_core.t_type
  }
  static e_translate_from_translationmap_name_string = {
    vx_type: vx_translate.t_translate_from_translationmap_name_string
  }

  // (func translate<-translationmap-name-string)
  static f_translate_from_translationmap_name_string(translationmap, name, text) {
    let output = vx_core.e_string
    output = vx_core.f_let(
      {"any-1": vx_core.t_string},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const translation = vx_core.f_any_from_map({"any-1": vx_core.t_translation, "map-1": vx_core.t_translationmap}, translationmap, name)
        return vx_translate.f_translate_from_translation_string(translation, text)
      })
    )
    return output
  }

  /**
   * @function translation_load_session
   * Returns a translation from the translation folder.
   * @param  {translation} translation
   * @return {translation}
   */
  static t_translation_load_session = {
    vx_type: vx_core.t_type
  }
  static e_translation_load_session = {
    vx_type: vx_translate.t_translation_load_session
  }

  // (func translation-load-session)
  static f_translation_load_session(context, translation) {
    let output = vx_core.e_translation
    return output
  }

  /**
   * @function translation_from_context
   * Returns a translated string from current context.
   * @return {translation}
   */
  static t_translation_from_context = {
    vx_type: vx_core.t_type
  }
  static e_translation_from_context = {
    vx_type: vx_translate.t_translation_from_context
  }

  // (func translation<-context)
  static f_translation_from_context(context) {
    let output = vx_core.e_translation
    output = vx_core.f_any_from_struct(
      {"any-1": vx_core.t_translation, "struct-2": vx_core.t_session},
      vx_core.f_session_from_context(context),
      ":translation"
    )
    return output
  }

  /**
   * @function translation_from_session_name
   * Returns a translation from a session by name.
   * @param  {session} session
   * @param  {string} name
   * @return {translation}
   */
  static t_translation_from_session_name = {
    vx_type: vx_core.t_type
  }
  static e_translation_from_session_name = {
    vx_type: vx_translate.t_translation_from_session_name
  }

  // (func translation<-session-name)
  static f_translation_from_session_name(session, name) {
    let output = vx_core.e_translation
    output = vx_core.f_let(
      {"any-1": vx_core.t_translation, "map-1": vx_core.t_translationmap},
      [],
      vx_core.f_new(vx_core.t_any_from_func, () => {
        const translationmap = vx_core.f_any_from_struct({"any-1": vx_core.t_translationmap, "struct-2": vx_core.t_session}, session, ":translationmap")
        return vx_core.f_any_from_map({"any-1": vx_core.t_translation, "map-1": vx_core.t_translationmap}, translationmap, name)
      })
    )
    return output
  }

  /**
   * @function translationmap_from_translations
   * Returns a translationmap from one or more translations.
   * @param  {translationlist} ... translations
   * @return {translationmap}
   */
  static t_translationmap_from_translations = {
    vx_type: vx_core.t_type
  }
  static e_translationmap_from_translations = {
    vx_type: vx_translate.t_translationmap_from_translations
  }

  // (func translationmap<-translations)
  static f_translationmap_from_translations(...translations) {
    let output = vx_core.e_translationmap
    translations = vx_core.f_new(vx_core.t_translationlist, ...translations)
    output = vx_core.f_map_from_list(
      {"any-1": vx_core.t_translation, "any-2": vx_core.t_translation, "list-2": vx_core.t_translationlist, "map-1": vx_core.t_translationmap, "struct-2": vx_core.t_translation},
      translations,
      vx_core.f_new(vx_core.t_any_from_any, (translation) => 
        vx_core.f_any_from_struct({"any-1": vx_core.t_string, "struct-2": vx_core.t_translation}, translation, ":name"))
    )
    return output
  }



  static {
    const constmap = vx_core.vx_new_map(vx_core.t_constmap, {
      
    })
    const emptymap = vx_core.vx_new_map(vx_core.t_map, {
      "session<-session-name": vx_translate.e_session_from_session_name,
      "session<-session-translation": vx_translate.e_session_from_session_translation,
      "session<-session-translationmap-name": vx_translate.e_session_from_session_translationmap_name,
      "translate": vx_translate.e_translate,
      "translate_1": vx_translate.e_translate_1,
      "translate<-translation-string": vx_translate.e_translate_from_translation_string,
      "translate<-translationmap-name-string": vx_translate.e_translate_from_translationmap_name_string,
      "translation-load-session": vx_translate.e_translation_load_session,
      "translation<-context": vx_translate.e_translation_from_context,
      "translation<-session-name": vx_translate.e_translation_from_session_name,
      "translationmap<-translations": vx_translate.e_translationmap_from_translations
    })
    const funcmap = vx_core.vx_new_map(vx_core.t_funcmap, {
      "session<-session-name": vx_translate.t_session_from_session_name,
      "session<-session-translation": vx_translate.t_session_from_session_translation,
      "session<-session-translationmap-name": vx_translate.t_session_from_session_translationmap_name,
      "translate": vx_translate.t_translate,
      "translate_1": vx_translate.t_translate_1,
      "translate<-translation-string": vx_translate.t_translate_from_translation_string,
      "translate<-translationmap-name-string": vx_translate.t_translate_from_translationmap_name_string,
      "translation-load-session": vx_translate.t_translation_load_session,
      "translation<-context": vx_translate.t_translation_from_context,
      "translation<-session-name": vx_translate.t_translation_from_session_name,
      "translationmap<-translations": vx_translate.t_translationmap_from_translations
    })
    const typemap = vx_core.vx_new_map(vx_core.t_typemap, {
      
    })
    const pkg = vx_core.vx_new_struct(vx_core.t_package, {
      "name": "vx/translate",
      "constmap": constmap,
      "emptymap": emptymap,
      "funcmap": funcmap,
      "typemap": typemap
    })
    vx_core.vx_global_package_set(pkg)

    // (func session<-session-name)
    vx_translate.t_session_from_session_name['vx_value'] = {
      name          : "session<-session-name",
      pkgname       : "vx/translate",
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
      fn            : vx_translate.f_session_from_session_name
    }

    // (func session<-session-translation)
    vx_translate.t_session_from_session_translation['vx_value'] = {
      name          : "session<-session-translation",
      pkgname       : "vx/translate",
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
      fn            : vx_translate.f_session_from_session_translation
    }

    // (func session<-session-translationmap-name)
    vx_translate.t_session_from_session_translationmap_name['vx_value'] = {
      name          : "session<-session-translationmap-name",
      pkgname       : "vx/translate",
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
      fn            : vx_translate.f_session_from_session_translationmap_name
    }

    // (func translate)
    vx_translate.t_translate['vx_value'] = {
      name          : "translate",
      pkgname       : "vx/translate",
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
      fn            : vx_translate.f_translate
    }

    // (func translate)
    vx_translate.t_translate_1['vx_value'] = {
      name          : "translate",
      pkgname       : "vx/translate",
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
      fn            : vx_translate.f_translate_1
    }

    // (func translate<-translation-string)
    vx_translate.t_translate_from_translation_string['vx_value'] = {
      name          : "translate<-translation-string",
      pkgname       : "vx/translate",
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
      fn            : vx_translate.f_translate_from_translation_string
    }

    // (func translate<-translationmap-name-string)
    vx_translate.t_translate_from_translationmap_name_string['vx_value'] = {
      name          : "translate<-translationmap-name-string",
      pkgname       : "vx/translate",
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
      fn            : vx_translate.f_translate_from_translationmap_name_string
    }

    // (func translation-load-session)
    vx_translate.t_translation_load_session['vx_value'] = {
      name          : "translation-load-session",
      pkgname       : "vx/translate",
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
      fn            : vx_translate.f_translation_load_session
    }

    // (func translation<-context)
    vx_translate.t_translation_from_context['vx_value'] = {
      name          : "translation<-context",
      pkgname       : "vx/translate",
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
      fn            : vx_translate.f_translation_from_context
    }

    // (func translation<-session-name)
    vx_translate.t_translation_from_session_name['vx_value'] = {
      name          : "translation<-session-name",
      pkgname       : "vx/translate",
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
      fn            : vx_translate.f_translation_from_session_name
    }

    // (func translationmap<-translations)
    vx_translate.t_translationmap_from_translations['vx_value'] = {
      name          : "translationmap<-translations",
      pkgname       : "vx/translate",
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
      fn            : vx_translate.f_translationmap_from_translations
    }

  }
}
