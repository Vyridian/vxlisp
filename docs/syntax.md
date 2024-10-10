# Syntax

## Top Level Functions

* (project) - This function must be the only function in the project.vxlisp file and is undefined anywhere else. See [projects.md](https://github.com/Vyridian/vxlisp/blob/main/docs/projects.md) for more detail.

* (package) - This function must be the top function in the a source {mypackage}.vxlisp file and is undefined anywhere else. See [packages.md](https://github.com/Vyridian/vxlisp/blob/main/docs/packages.md) for more detail.

* (type) - This function defines a new data type and may be used in any source {mypackage}.vxlisp file. See [types.md](https://github.com/Vyridian/vxlisp/blob/main/docs/types.md) for more detail.

* (const) - This function defines a new constant and may be used in any source {mypackage}.vxlisp file. See [constants.md](https://github.com/Vyridian/vxlisp/blob/main/docs/constants.md) for more detail.

* (func) - This function defines a new function and may be used in any source {mypackage}.vxlisp file. See [functions.md](https://github.com/Vyridian/vxlisp/blob/main/docs/functions.md) for more detail.

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

* (new : {type} {args}) or ({type} {args})

* (copy {any} {args})

* These constructors are very flexible and will automatically concatenate where possible. E.g. (int 2 3), (string "a" "b"), (stringlist "a" (stringlist "c" "d"))

* You may also construct an (anylist) and pass that as varargs. E.g. (string (anylist "a" "b"))

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
 [url : string]
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
