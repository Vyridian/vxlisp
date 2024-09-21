# Types

(type name
 constraints  ...
 :properties       [] // Allowed key values [name : type :default value :doc "" :alias ""]
 :extends          :map // This type is a collection of another type. :list|:map|:struct
 :allowfuncs       [allowfunc ...] // Allowed Func
 :disallowfuncs    [disallowfunc ...] // Disallow Funcs
 :allowtypes       [allowtype ...] // Allowed Types
 :disallowtypes    [disallowtype ...] // Disallow Types
 :allowvalues      [allowvalue ...] // Allowed Values
 :disallowvalues   [disallowvalue ...] // Disallow Values
 :alias            "internal name"
 :value            clause
 :deprecated       "Version"
 :convert          [[fromtype totype clause] ...]
 :test             clauses ...
 :doc              "Type doc")
