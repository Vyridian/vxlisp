# vxlisp

## Overview

* vxlisp (Variable Platform, Cross Language Lisp) is a proposal for a new programming language and data structure that might fullfill the dream of 'write once, run anywhere'. It also tries to address a large number of complaints I have with other languages.

## Sample

(func foo : int           // function foo() returns integer
 [arg1 : int              // arg1
  arg2 : int]             // arg2
 (+ arg1 arg2)            // arg1 + arg2
 :test (test 3 (foo 1 2)) // A Test case {expect: 3, actual: {foo 1 2}}
 :doc  "Foo function returns an integer after adding arg1 and arg2")

## FAQ

* What is vxlisp?

1. vxlisp is a simple data structure similar to JSON, but it is simpler and more consistent while also being able to describe complex objects and functions.

2. vxlisp is a meta language designed to be natively compiled to other languages. It is sort of like Typescript's relationship to Javascript or Kotlin's relationship to Java.

3. vxlisp is a transparency layer so that code can be more easily read, shared, tested, and ported between applications and platforms.

* What is vxlisp not?

1. vxlisp is not a platform.

2. vxlisp is not a replacement for other languages. Instead it is meant to interact with existing platforms and languages.

* Write once, run anywhere is a pipedream. How can it possibly work? - Most new languages try to write a platform along with the language. Instead I want to write a language that can compile to any other language or platform with identical results.

* New languages rarely work. Why write one? - To improve the art. I find most languages to have ugly, confusing syntax and poor manageability. I hope to point out that this need not be true. Vxlisp represents my wishlist of things that I have liked and disliked about other languages. Frankly, I'm pretty pleased with the result.

* What is its best use cases? - I think it might be best suited for collaborative work where support, test team, management AND developers need transparency into a cross platform application. Also, it would be ideal for a developer who wants to work on a platform that requires a language they are uncomfortable with, e.g. WebAssembly, Unreal Engine, or IOS.

* Everyone has a bias. What is yours? - I admit it. I love Functional Programming and Test driven development. I dislike Imperitive programming, and Object-oriented programming. I also dislike vendor lockin, large corporations, and I am horrified by the probable impact of AI.

* Why Functional Programming instead of Object-Oriented? - The best example is the development of SOAP and REST web services. SOAP was the original, Object Oriented web service solution similar to .dll linking. It had sophiticated type binding and state management. REST on the other hand was a very simplistic system similar to web page calls. Soon the practical complexities overwhelmed SOAP and REST grew to replace it. Simplicity makes a better product in the end.

* What are your inspirations? - Obviously, Lisp. I was introduced to it in 1987 and it stuck with me. More recently: Javascript, Typescript, Scala, Clojure, Clojurescript, Elm, and an obscure XML programming language called NuXML.

* What are your first principles? - Simplify, Simplify, Simplify. Manageability > Readability > Functionality > Performance. Simplicity requires the removal of dependencies wherever possible.

* What are the key features of the language? - Open Source. Language is a data structure. Compact consistent syntax. Interoperable with native code. All-in-one: code, test, documentation. Everything is the same data structure. Test cases in documentation. Simplified handling of many of the most ugly coding patterns including generics, exceptions, null, inheritence, asynchronous code, constructors, immutability, thread-safety, overloading, and context.

* Are there any unusual features of the language? - Built in Webserver, Documentation builder, Test suite, Test coverage. BigO coverage. Simplified generic handling. Simplified context management. Functions are first class objects. Simple access to type data. Universal serialization/deserialization. Memory Pooling. State Management. File parsing. Repl. Programmatic Html/Xml generation. Function level permissions. Few restricted characters. Free use of whitespace. Option to write code from documentation. Potential to easily write code to unusual platforms like Html Canvas or WebAssembly. Potential to simultaneously write native android and IOS without middleware like react native.

* Alright, that was a lot of Pros. What are the Cons?

1. Tooling - Since vxlisp compiles to other languages, it relies on thoses languages for runtime debugging besides basic logging. You may find that indirection overwhelms the benefits.

2. Optimal Performance - Though vxlisp compiles to native code, everything (including primitives) is treated as an object, so a certain amount of extra processing and heap usage is added to even low-level operations. Memory pooling may mitigate this cost, but I recommend using optimized native code for operations that require maximum performance.

3. Overkill - vxlisp is focused on making complex cases easier. Conversely, it is possible that simple cases may seem overbuilt with features you don't need, e.g. Helloworld programs.

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

* Overall, how do you feel about vxlisp? - I've been writing code since 1980 and have seen a lot of languages come and go. vxlisp brings together so many concepts that I have struggled with in the past, so it is a pleasure to work with. It feels like my Magnum Opus, and I feel it's muse calling to me. It feels pretty good.
