# vxlisp

## Links
* [Compiler Web Site](https://vyridian.github.io/vxlisp)
* [Compiler Repository](https://github.com/Vyridian/vxlisp)
* [Docs](https://github.com/Vyridian/vxlisp/tree/main/docs)
* [Core Library](https://vyridian.github.io/vxlisp-vxcore)
* [Core API](https://vyridian.github.io/vxlisp-vxcore/build/doc/doc.html)
* [Hello World Library](https://github.com/Vyridian/vxlisp-helloworld)
* [VSCode Extension](https://github.com/Vyridian/vscode-vxlisp)

## Test Suites:
* [JavaScript](https://vyridian.github.io/vxlisp-vxcore/public/testjs.html)
* [Java](https://vyridian.github.io/vxlisp-vxcore/build/java/src/test/resources/testsuite.html)
* [C++](https://vyridian.github.io/vxlisp-vxcore/build/cpp/src/test/resources/testsuite.html)
* [CSharp](https://vyridian.github.io/vxlisp-vxcore/build/csharp/test/resources/testsuite.html)
* [Kotlin](https://vyridian.github.io/vxlisp-vxcore/build/kotlin/app/src/test/kotlin/resources/testsuite.html)

## Overview

* What is vxlisp?

1. vxlisp (Variable Language, Cross Platform Lisp) is a proposal for a new programming language and data structure that might fullfill the dream of 'write once, run anywhere' by writing in one language and publishing to any other one. It also tries to address a large number of complaints I have with other languages. It liberally takes concepts from many other languages like Lisp, Clojure, Scala and JavaScript.

2. vxlisp is easy to learn with simple, concise, consistent, readable syntax. It seeks to make programming more feature-rich, modular, and reliable by standardizing like Lego pieces and plugging holes in other languages. If focuses on making the most common programming cases easier and more robust including documentation and test.

3. vxlisp is easy to setup. Copy the folder, write some code, run the executable file, and you are up and running with JavaScript. The built-in webserver even serves up your code and testscripts. Other languages require their respective compilers an projects to be installed as well.

4. vxlisp is a full featured language including documentation, test cases, meta tags, type-safety, data structures, generic types, multiple-inheritance, asynchronous/futures, first class functions, lambda expressions, memory management, state management, debugging tools, and a scripting/read-execute-print-loop. All of these should be noticably easier to code in vxlisp than their original languages.

5. vxlisp is a simple data structure similar to JSON or XML, but it is simpler and more consistent while also being able to describe complex typesafe objects and functions.

6. vxlisp is a meta language designed to be natively compiled to other languages. It is sort of like Typescript's relationship to Javascript or Kotlin's relationship to Java. However, since it generates plain old native code, it can be mixed with native code in any amount you might prefer.

7. vxlisp is a transparency layer so that code can be more easily read, shared, tested, and ported between applications and platforms. It can evolve directly from a specification requirement to production/test code.

8. vxlisp is a mass-production tool allowing the quick and concise creation of many complex interconnected objects while maintaining readability.

9. vxlisp is a future-proofing tool allowing code to be recompiled in the future when new languages or features appear.

10. vxlisp is a very compact, readable language. The equivalent native code vxlisp generates is 10x-20x as large as the original including test suite and documenation.

* What vxlisp is not?

1. vxlisp is not a platform. vxlisp produces plain old (JavaScript/Java/C++/CSharp/Kotlin) for any purpose. vxlisp does not require outside libraries (except Java/Kotlin:JUnit, CSharp:XUnit for test support)

2. vxlisp does not replace other languages. Instead it is meant to interact with existing platforms and languages. vxlisp generates plain old native objects that are written into your existing native project. Write as much native code as you like inside or outside vxlisp (though native code is not cross-platform).

* Write once, run anywhere is a pipedream. How can it possibly work?

Most new languages try to write a platform along with the language. Instead I want to write a language that can compile to any other language or platform with identical results.

* New languages rarely work. Why write one?

To improve the art. I find most languages to have ugly, confusing syntax, and poor manageability. I hope to point out that this need not be true. vxlisp represents my wishlist of things that I have liked and disliked about other languages. Frankly, I'm very pleased with the result.

* What are its best use cases?

1. Collaboration - It should be suited for collaborative work where outsourcers, support, test team, management AND developers need transparency into a cross platform application. In my mind, this is every project of any scale.

2. Cross-platform - Obviously, write-once, run-anywhere is good for cross-platform work. Why is anyone writing applications that are not cross-platform?

3. Learning Language - I learned programming using BASIC on an Apple II. In college I learned PASCAL. These are considered learning languages but they are still fairly complex. vxlisp is consistent and readable. It promotes small code snippets, documentation and test cases. It is well suited to the classroom.

4. Difficult Languages - It could be helpful for developers who wants to work on platforms that require languages they are uncomfortable with, e.g. WebAssembly, Unreal Engine, Unity, or IOS.

## Sample

    (type person : struct
     :properties
      [firstname : string
       lastname  : string
       nicknames : stringlist
       childmap  : personmap]
     :doc "A type/template/class/structure representing a person.")

    (type personmap : map
     :allowtypes [person]
     :doc "A map of person")

    (const johndoe : person
     (person
      :firstname "John"
      :lastname  "Doe"
      :nicknames
       (stringlist "JD" "J Doe")
      :childmap
       (personmap
        :julie
         (person :firstname "Julie" :lastname "Doe")))
     :doc "A constant representing a particular person.")

    (func fullname : string
     [person : person]
     (string
      (:firstname person)
      " "
      (:lastname  person))
     :test (test                // A Test case
            "John Doe"          // expect "John Doe"
            (fullname johndoe)) // actual
     :doc  "Returns fullname from any person type.")

## Folder Structure

1. dist - The runtime version of vxlisp with core libraries.
2. src - The vxcompiler development code written in golang.
3. batches - Batch files for compiling the compiler.
4. docs -Markdown files of various instructions and notes.

## FAQ

* Aren't there already too many languages? - I agree completely. The ubiquity of beutiful, niche languages is exactly the inspiration for this one. vxlisp is a model for a new language that can break the hamster-wheel of shifting languages by allowing you to publish in any language while only learning one.

1. Choosing a Language - The first problem with existing languages is you need to choose one for your task. You could choose the most used languages to be safe (e.g. JavaScript, Java, C++, CSharp, Kotlin), or you could choose a more niche language that might fit your coding style or the project requirements (e.g. Typescript, Scala, Clojure, Rust, Dart, Go). My answer: Don't Choose. Write in one language and publish to any other language.

2. Language Limitiations - Now you are working through your project and realize that a key feature you need is not available in your language or is extremely convoluted (e.g. futures) or has poor performance for your use case (e.g. distributed systems). Too bad. You are committed to the language. Changing now is not realistic, or... you start from scratch, or... just publish to a new language.

3. Platform Lockin - You have mastered a language and finished your project, but one day your vendor changes his licensing or goes out of business (e.g. Java Applet, Adobe Flash, Unity Runtime, D&D OGL, Cloud Service Providers). Too bad. You are committed to the language. Changing now is not realistic, or... you start from scratch, or... just publish to a new language.

4. Language Obsolesence - You have mastered a language and finished your project, but one day your language is no longer the 'It' language, you need a job in another language, or worse is fading in usage and support (e.g. Elm, Ruby, VisualBasic, Scala, Perl, Haskell, Erlang). Too bad. You are committed to the language. Changing now is not realistic, or... you start from scratch, or... just publish to a new language.

5. Library Obsolesence - You have mastered a language and finished your project, but one day you start a new project and for whatever reason it would be best in another language/platform. All of your perfectly working and tested libraries are useless. Too bad. You are committed to the new language. Porting your existing work would be very painful, or... you start from scratch, or... just publish to a new language.

* Everyone has a bias. What is yours?

I admit it. I love Functional Programming and Test driven development. I dislike Imperitive programming, and Object-Oriented programming. I also dislike vendor lockin, large corporations, and I am horrified by the probable impact of AI.

* Why Functional Programming instead of Object-Oriented?

The best example is the development of SOAP and REST web services. SOAP was the original, Object-Oriented, web service solution similar to .dll linking. It had sophiticated type binding and state management. REST on the other hand was a very simplistic system similar to web page calls. Soon the practical complexities overwhelmed SOAP and REST grew to replace it. Simplicity makes a better product in the end.

* What are your inspirations?

Obviously, Lisp. I was introduced to it in 1987 (in AI programming of all things) and it stuck with me. More recently: JavaScript, Typescript, Scala, Clojure, Clojurescript, Elm, and an obscure XML programming language called NuXML.

* What are your first principles?

1. Simplify, Simplify, Simplify. Simplicity requires the removal of dependencies wherever possible. The best part is no part. Mass production and reliability can only be maintained through simpilfication.

2. Manageability > Readability > Functionality > Performance. 

* What are the key features of the language?

Open Source. Language is a data structure. Compact consistent syntax. Interoperable with native code. All-in-one: code, test, documentation. Everything is the same data structure. Test cases in documentation. Simplified handling of many of the most ugly coding patterns including generics, exceptions, null, inheritence, asynchronous code, constructors, immutability, thread-safety, overloading, and context. Few dependencies and Plain old native objects.

* Are there any unusual features of the language?

Built in Webserver, Documentation builder, Test suite, Test coverage. BigO coverage. Simplified generic handling. Simplified context management. Functions are first class objects. Simple access to type data. Universal serialization/deserialization. Memory Pooling (in development). State Management (in development). File parsing. Repl. Macros. Programmatic Html/Xml generation. Built in debugging tools. Function level permissions. Few restricted characters. Free use of whitespace. Option to write code from documentation. Potential to easily write code to unusual platforms like Html Canvas or WebAssembly. Potential to simultaneously write native android and IOS without middleware like react native.

* Alright, that was a lot of Pros. What are the Cons?

1. Tooling - Since vxlisp compiles to other languages, it relies on thoses languages for runtime debugging besides basic logging. You may find that indirection overwhelms the benefits.

2. Optimal Performance - Though vxlisp compiles to native code, everything (including primitives) is treated as an object, so a certain amount of extra processing and heap usage is added to even low-level operations. Memory pooling may mitigate this cost, but I recommend using optimized native libraries for operations that require maximum performance.

3. Overkill - vxlisp is focused on making complex cases easier. Conversely, it is possible that simple cases may seem overbuilt with features you don't need, e.g. Helloworld programs.

* What does a function that returns Hello World look like?
     (func foo : string
      "Hello World")

* What does a function that adds 2 integers look like?

     (func foo : int
      [arg1 : int
       arg2 : int]
      (+ arg1 arg2))

* What does type declaration look like?

    (type personlist : list
     :allowtypes [person]
     :doc "This is a list of person")

    (type personmap : map
     :allowtypes [person]
     :doc "This is a hash map of person")

    (type person : struct
     :properties [name    : string     :doc "The person's name"
                  age     : number     :doc "The person's age"
                  kidlist : personlist :doc "List of kids"
                  kidmap  : personmap  :doc "Map of kids"]
     :doc "This is a person structure")

* How do I make new people?

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

 Alternatively, you can use the longhand (new : person) instead of (person)

* How do I access properties from types?

    (:1 kidlist)   // Get the first value of kidlist aka jack
    (:Jack kidmap) // Get jack from kidmap
    (:name mary)   // Get Mary's name

 Alternatively, you can use the longhand versions:
    (any<-list   kidlist 1)
    (any<-map    kidmap "Jack")
    (any<-struct person "name")

* Why did you choose unusual naming conventions?

My goal was to write a language targetting beginner programmers with no particular bias toward an existing language. Generally, when searching for a function you already know the return type, so I place return type first to make it easy for type ahead or other sorting to find the return type I seek.

* Overall, how do you feel about vxlisp?

I've been writing code since 1980 and have seen a lot of languages come and go. vxlisp brings together so many concepts that I have struggled with in the past, so it is a pleasure to work with. It feels like my Magnum Opus, and I feel it's muse calling to me. It feels damn good.
