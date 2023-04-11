# Syntax

## Conventions

* Spaces or Tabs - Spaces because tabs are hidden and formatting in vxlisp is intentional.
* LF, CRLF, or CR - LF (Linefeeds) are used to stick to the open standard of UNIX/Linux.
* UTF-8 or ANSI - UTF-8 is the simple standard that supports localization.
* Whitespace - Any amount of whitespace is a single delimiter except inside "" or ``
* lower-case, CamelCase, camelCase - lower-case because hyphens are more readable and vxlisp does not confuse hyphen with minus sign. camelCase is gross.

## Everything is a List

* Like lisp, everything is a list and a function: ({function} arg1 arg2 etc)
* Unlike lisp, types are also functions. For example: (string "ab" "cd") returns a new string "abcd"

## Keywords

* Like Clojure, keywords in vxlisp are prefixed with a colon ":".
* ":" - A single colon means the following value is a type. e.g. : string
* ":=" - A colon followed by "=" means the following value will be assigned. e.g. myvar : string := "ab"
* ":{name}" - A colon followed by any other name or int means the value is a keyword. These can be used in the following ways:

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

## Async

## Context

## Types

## Constants

## Functions

