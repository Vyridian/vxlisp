# Syntax

## Conventions

* Spaces or Tabs? - Only 1 space is normally used for indentation, so spaces are more logical. Besides that tabs are hidden and formatting in vxlisp is intended to be used for consistent readability.
* LF, CRLF, or CR - LF (Linefeeds) are used to stick to the open standard of UNIX/Linux instead of Windows or Apple.
* UTF-8 or ANSI - UTF-8 is the simple standard that supports localization.
* Whitespace - Any amount of whitespace is a single delimiter except inside "" or ``
* lower-case, CamelCase, camelCase - lower-case because hyphens are more readable and vxlisp does not confuse hyphen with minus sign. camelCase is gross.

## Everything is a List

* Like lisp, everything is a list and a function: ({function} arg1 arg2 etc)
* Unlike lisp, types are also functions. For example: (string "ab" "cd") returns a new string "abcd"

## Keywords

* Like Clojure, keywords in vxlisp are prefixed with a colon ":".
* : - A single colon means the following value is a type. e.g. : string
* := - A colon followed by "=" means the following value will be assigned. e.g. myvar : string := "ab"
* :{name} - A colon followed by any other name or int means the value is a keyword. These can be used in the following ways:

1. (:2 mylist) - For a given list is the same as mylist[2].
2. (:mykey mymap) - For a given map is the same as mymap[mykey].
3. (:myprop mystruct) - For a given struct is the same as mystruc.myprop
4. (mymap :mykey1 myval1 :mykey2 myval2) - Will create a new map of type mymap with the new key value pairs.

## Reserved words or terms

* "vx_" is used as a prefix for internal variables of and methods.
* (project), (package), (func), (type), (const), (fn), (new), (copy), (empty) are reserved functions and should not be overloaded.

## Primitives

* boolean
* int
* float
* decimal
* number
* string
* list
* map
* struct
* async

## New and Copy

* (new {type} {args})

* (copy {any} {args})

## Overloading

* Functions may be redefined as often as you like. The compiler will choose the first match it find based on package include order and top-down within a package.

## Async

* Asynchronous functions in vxlisp are easier than any other language I've encountered. The state of the art in async is the async/await pattern. vxlisp is effectively the same lets you ignore the async completely. It automatically detects the use of async function and creating continuation future chains for you. The only requirement is that any function that uses an async must also be async.

Sample JavaScript:

async function httpget(url) {
...
  return promise; // promise of string
}

let text = await httpget("http:..");

Sample vxlisp:

(func httpget : string
 [url :string]
 ...
 (string)
:async)

(let
 [text : string := (httpget "http:..")])

## Comment

// ignore to end of line
/* ignore block */

## Strings

"" Quotes treat leading whitespace on a line as a single space.
`` Block Quotes keep all whitespace

## Project

* project.vxlisp - There can be only one project file and it must be in the root of your project and it must be named project.vxlisp.

* (project) - The project file must have only one (project) type and nothing else.

(project core                      // The name of the project
 :version    "0.5"                 // The version of the project
 :author     ""                    // The author of the project
 :doc        "The vx/core project" // The description of the project for documentation.
 :javadomain "com.vxlisp"          // A special variable for Java project prefixing
 :libs                             // A list of libraries to include when building a language.
  (lib javaniofile
   :path "java.nio.file.*"
   :lang :java)
 :cmds                             // A list of command line options available.
  (cmd srccpp
   :code    :source
   :lang    :cpp
   :path    ../cpp/src/main
   :main    vx/core/main
   :context vx/core/context-main
   :filter  vx/core/myfunc         // For debugging test. Filters test to only a single function.
   :doc     "Build C++ Source Code")
)

### Libraries

### Commands

Commands are command line options when running the vxlisp executable. Any number of commands may be chained into one command line.

Sample:
vxlisp_win64 doc srcjs testjs srcjava testjava --path %currentfolder%/vxlisp

* :main - When you build a project, the main function will be run when the application starts. This setting can be changed to any function you choose. The setting is found in your project file project.vxlisp:

(project
 :cmds
  (cmd
   :main vx/core/main))

### Context

* When you build a project, the context function will be run when the application starts to generate application level context. This setting can be changed to any function you choose. The setting is found in your project file project.vxlisp:

(project
 :cmds
  (cmd
   :context vx/core/context))

## Packages

(package name
 :alias "alias"
 :libs  [library :path path ...]
 :doc "Package doc")

## Types

(type name
 constraints  ...
 :properties       [] // Allowed key values [name : type :default value :doc "" :alias ""]
 :extends          :map // This type is a collection of another type. :list|:map|:struct
 :allowfuncs     [allowfunc ...] // Allowed Func
 :disallowfuncs  [disallowfunc ...] // Disallow Funcs
 :allowtypes     [allowtype ...] // Allowed Types
 :disallowtypes  [disallowtype ...] // Disallow Types
 :allowvalues    [allowvalue ...] // Allowed Values
 :disallowvalues [disallowvalue ...] // Disallow Values
 :alias            "internal name"
 :value            clause
 :deprecated       "Version"
 :convert          [[fromtype totype clause] ...]
 :doc              "Type doc"
 :test             clauses ...)

## Constants

(const name : type
 clauses :...
 :alias      "internal name"
 :private
 :protected
 :mutable
 :deprecated "Version"
 :doc        "value doc"
 :test       clauses :...)

## Functions

(func name : type // explicit type or array of types []. Types may be :1 to :9 representing named generics.
 [arg : type // explict type or array of generics [] e.g. :1 :2
  :alias      ""
  :value      // A value for this argument. This is a default value in regular functions
  :doc        "arg doc"
  :fn         // pass as function reference
  :...]
 clauses ...
 :alias       "internal name"
 :async       // asynchronous function
 :private
 :protected
 :sideeffects // denotes function with hidden sideeffects
 :wrapper
 :messages    // use message handling
 :parallel
 :bigospace   // :1 :logn :n :nlogn :2n :n^2 :2^n :n^n
 :bigotime    // :1 :logn :n :nlogn :2n :n^2 :2^n :n^n
 :doc         "function doc"
 :debug       // adds console debug code which outputs [funcname output params] if clause is true
 :test        clauses ...
 :deprecated  "version")

## Function Overloading

* Simply define the function multiple times with the same name. The compiler will use the first matching signature.

## Lamba Function

(fn : type
 [arg : type :doc "arg doc" ...]
 clauses ...
 :async
 :doc "function doc"
 :test clauses ...)

## Native Code

(native :lang :c|:c++|:clj|:cljs|:go|:java|:js|:rust clauses ...)
