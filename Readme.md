# vxlisp

## Overview

* vxlisp is a proposal for a new programming language/data structure that might fullfill the dream of 'write once, run anywhere'. It also tries to address a large number of complaints I have with other languages.

## Sample

(func foo : int
 [arg1 : int
  arg2 : int]
 (+ arg1 arg2)
 :test (test 3 (foo 1 2))
 :doc  "Returns the result of adding to numbers")

## FAQ

* Write once, run anywhere is a pipedream. How can it possibly work? - Most new languages try to write a platform along with the language. Instead I want to write a language that can compile to any other language or platform with identical results.

* New languages rarely work. Why write one? - To improve the art. I find most languages to have ugly, confusing syntax and poor manageability. I hope to point out that this need not be true. Vxlisp represents my wishlist of things that I have liked and disliked about other languages. Frankly, I'm pretty pleased with the result.

* Everyone has a bias. What is yours? - I admit it. I love Functional Programming and Test driven development. I dislike Imperitive programming, and Object-oriented programming. I also dislike large corporations and am terrified by the impact of AI.

* What are your inspirations? - Obviously, Lisp. I was introduced to it in 1987 and it stuck with me. More recently: Javascript, Typescript, Scala, Clojure, Clojurescript, Elm, and an obscure XML programming language called NuXML.

* What are your first principles? - Simplify, Simplify, Simplify. Manageability > Readability > Functionality > Performance. Simplicity requires the removal of dependencies wherever possible.

* What are the key features of the language? - Open Source. Compact consistent syntax. Interoperable with native code. All-in-one: code, test, documentation. Everything is the same data structure. Test cases in documentation. Simplified handling of many of the most ugly coding patterns including generics, exceptions, null, inheritence, asynchronous code, constructors, immutability, thread-safety, overloading, and context.

* Are there any unusual features of the language? - Built in Webserver, Documentation builder, Test suite, Test coverage. BigO coverage. Simplified generic handling. Simplified context management. Functions are first class objects. Simple access to type data. Universal serialization/deserialization. Memory Pooling. State Management. File parsing. Repl. Programmatic Html/Xml generation. Function level permissions. Few restricted characters. Free use of whitespace. Option to write code from documentation. Potential to easily write code to unusual platforms like Html Canvas or WebAssembly. Potential to simultaneously write native android and IOS without middleware like react native.

* Alright, that was a lot of Pros. What are the Cons?

1. Tooling - Since vxlisp compiles to other languages, it relies on thoses languages for runtime debugging besides basic logging. You may find that indirection overwhelms the benefits.
2. Optimal Performance - Though vxlisp compiles to native code, everything (including primitives) is treated as an object, so a certain amount of extra processing and heap usage is added to even low-level operations. Therefore, I recommend using optimized native code for operations that require maximum performance.

* What does a function that returns Hello World look like? -
 (func foo : string
  "Hello World")

* What does a function that adds 2 integers look like? -
 (func foo : int
  [arg1 : int
  arg2 : int]
 (+ arg1 arg2))

* What does type declaration look like? -
 (type personlist
  :extends    :list
 :allowtypes [person]
 :doc "This is a list of person")

 (type personmap
  :extends    :map
 :allowtypes [person]
 :doc "This is a hash map of person")

 (type person
  :extends    :struct
  :properties [name    : string     :doc "The person's name"
               age     : number     :doc "The person's age"
               kidlist : personlist :doc "List of kids"
               kidmap  : personmap  :doc "Map of kids"]
 :doc "This is a person structure")

* How do a make a new people? -
 (const jack : person
  (person :name "Jack" :age 10))

 (const jill : person
  (person :name "Jack" :age 8))

 (const kidlist : personlist
  (personlist jack jill))

 (const kidmap : personmap
  (personmap
  "Jack" jack
  "Jill" jill))

 (const mary : person
  (person
  :name "Mary"
  :age  "30"
  :kidlist kidlist
  :kidmap  kidmap))

 Alternatively, you can use the longhand (new person) instead of (person)

* How do I access properties from types? -
 (:0 kidlist)   // Get the first value of kidlist aka jack
 (:Jack kidmap) // Get jack from kidmap
 (:name mary)   // Get Mary's name

 Alternatively, you can use the longhand versions:
 (any<-list   kidlist 0)
 (any<-map    kidmap "Jack")
 (any<-struct person "name")
