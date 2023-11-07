# vxlisp vs. Other Languages

## vxlisp

* Cross-platform
* Flexible
* Concise and Readable - vxlisp code is MUCH more concise than any of the conventional languages while still being more readable.
* Plain Vanilla Native Code - vxlisp generates plain vanilla objects. It does no code injection or prototype manipulation.
* Native Performance - vxlisp generates native code in each language with comparable performance. Naturally, because this code has more functionality than custom, purpose-built code it is slightly less than optimal.
* Functional - The logical problem with Object-Oriented programming is always having the possibility of an infinite loop when: a changes b changes c changes a. Function programming leans away from this by avoiding inline changes.
* Future Proof - When the next, greatest programming language/platform appears (or just a cool one), just write a new publisher program. The current compile-js.go is only 1500 lines long.
* Simple Type-safety - JavaScript and most lisps are not type-safe. Finding errors during compile is much faster and safer than during runtime.
* Generics - vxlisp requires generic types to be declared (like clases), so generics are reusable, documentable, testable and uniform with structures. Generic objects use any-1, list-1 notation instead of the weird T extends List U notation.
* Flexible Generics - vxlisp allows lists and maps to contain multiple diverse types or only particular values like enums. E.g.

  (type mylist : map
   :allowtypes [string, int, person])

  (type mylist : list
   :allowvalues ["a", 4, johndoe])

* No Type-erasure - vxlisp retains object definitions, so they can be polled and branched at runtime. This obviously creates a small memory overhead, but simpifies concepts like Reflection.
* Empty Types - Functions always returns a valid datatype. This type may be empty or contain errors, but it is never NULL or invalid.
* White Spaced - Like other lisps, vxlisp allows whitespace to be used for readability instead of a programming requirement.
* Few Reserved Words - Like other lisps, vxlisp reserves very few characters.
* Composable - Because it is a functional language, large blocks of code can easily be separated into helper functions that can suppor their own documentation and test. Imperative code leads to spaghetti code.
* Garbage Collection - The C++ code automatically does full garbage collection. The other languages do garbage collection by default, but they could be enhanced for more agressive garbage collection to keep heap usage down.
* Uniform Constructors - vxlisp uses consistent constructors for all types including lists and maps. E.g. (person :firstname "Jane" :lastname "Doe") (stringlist "a" "b") (stringmap :a "a1" :b "b2")
* Copy/Cloning - vxlisp make extensive use of shallow cloning to maintain immutable objects. E.g. (copy janedoe :firstname "John")
* Serialization - Every object can be serialized. E.g. (string<-any janedoe) becomes (person :firstname "Jane" :lastname "Doe")
* Pointers - Since objects are logically immutable, vxlisp almost exclusively uses and passes pointers to objects to minimize parameter passing overhead.
* First Class Functions - All functions have an object available object wrapper, so they may be passed around freely as arguments and used as properties.
* Consistent Scope - Variables are always isolated within local scope. This is in contrast to other languages where for example an if-then-else statement cannot have the same variable name used in the then and the else.
* Overloading - Functions may be redefined as often as you like. The compiler will choose the first matching function based on import library order.
* Airity - vxLisp seeks to encourage variable numbers of arguments by making the pattern easier to write. Any list argument may be followed by the :... keyword to indicate multiple arguments. Within the function these will be an array.
* Macros/Repl/Scripting
* Exception Bubbling - Instead of traditional exception handling where a function can return a result or an exception, vxlisp always returns an object which may contain a messageblock with the exceptions below it.
* Futures/Async
* Multiple Inheritence - vxlisp uses interface/protocols instead of classes, so objects can cleanly implement any number of interfaces. This is done simply by using the :traits keyword. E.g.
(type mytype : struct
 :traits [person dog spaceshuttle])
* Documentation - vxlisp generates simple html documentation including test cases. The :doc keyword can be used on types, consts, funcs and arguments.
* Test Cases
* Test Coverage
* Test as Examples - In addition to the normal documentation, it is very useful to have known, current working examples right next to your code as well as published to documentation. These cases should be readable by managers and support staff as well to increase team transparency and free developer time from questions.
* Multiline Strings - Double quotes may be multiline without special notation. Indentation on subsequent lines are relative to the position of the opening double quote. Backticks can be used instead when you want to capture exact whitespace.
* :debug - Adding the :debug keyword into a function automatically logs the output of that function for console debugging.
* :unsafe - The :unsafe keyword is used to mark functions that have side effects.
* :bigocomplexity
* :bigotime

## JavaScript

* Flexible - JavaScript can do anything and be written in any way. This can produce wildly different code from different developers.
* Performance - JavaScript can be optimized in any number of ways, but it is not considered to be equal to native performance.
* Imperitive - Imperitive code is always problematic.
* Unsafe - Objects and prototypes have no protection from runtime changes, so they can easily be hacked. This can be a feature, but it does not make an ideal language.
* Overhead - The V8 engine is needed for anything that runs JavaScript. This is unnecessary overhead.
* Weak Typing - Lack of strong type checking makes refactoring harder and leads to unnecessary runtime errors.
* Concise - JavaScript is fairly concise, but vxlisp is 1/4 the size. (textblock.vxlisp 40kb, textblock.js 70kb + textblock_test.js 100kb)

## Typescript

* Based as JavaScript - As a rewrite of JavaScript, Typescript does a fair job of fixing the problems of JavaScript, but it also introduces the fairly rigid Typing of Java/CSharp.
* Object-oriented - For me, OOP is always a negative.
* Rigid Generics - Making generics that allow multiple types is a headache.
* Microsoft - Typescript is subject to Microsoft whims. I have a lot of rugpulls with languages, so I don't know that I would want to fully invest.
* Niche - Typescript is popular, but its libraries are more limited than JavaScript.

## Java

* Object-oriented - For me, OOP is always a negative.
* JVM - Most consider the JVM to be a bloated mess.
* Oracle - Back when Sun ran Java, things were decent, but as Google knows Java is not an open license.
* Aging - 25 years ago, Java was the next great thing. Now, it seems that the only thing keeping Java in the lead is inertia.
* Generics - Java falls on its face for copying C++ type-erasure, but it left out Type aliasing which makes its types somewhat worse than C++.
* Rigid Generics - Making generics that allow multiple types is a headache.
* Futures - Java has been slow to embrace Futures. Kotlin has done this right, so it is obviously not a technical problem. Futures are particularly irritating in Test Suites.
* Verbose - Java is exceptionally wordy. vxlisp is 1/8 the size. (textblock.vxlisp 40kb, textblock.js 158kb + textblock_test.js 139kb)

## CSharp

* Better Than Java - Since Java is so slow to improve, it has been easy for other languages to pass it. In my opinion, this is a low bar.
* Object-oriented - For me, OOP is always a negative.
* Rigid Generics - Making generics that allow multiple types is a headache.
* Microsoft - CSharp is a Microsoft-only platform. Mono is not a realistic option for other platforms.

## C++

Warning: This is my first C++ project, so there are going to be a lot of misconceptions and questionable decisions in my perspective and solution. I don't mind constructive criticism, and I will endeavour to endure unconstructive criticism as well.

* Performance - It has fairly optimal memory and execution performance with only native C and Assembly being superior.
* Ubiquitous - C++ is a well-established language that forms the bedrock of most complex systems such as Operating Systems.
* Native - Strong ability to program close to the 'metal'.
* Arcane Syntax - C++ notation emphasizes brevity over readability. Since C++ is a compiled language, this is completely unnecessary. I could argue that every language that has come after C++ is a direct reaction to C++ awkwardness.
* Object-oriented - For me, OOP is always a negative.
* Pointers - Pointers give you a great deal of power to do what you want though they open up a lot of error possibilities and the syntax is not very readable.
* Aging - C++ prides itself on avoiding code bloat in the standard library and supporting old hardware. Code bloat is instead moved to the Boost library from which the standards committee adopts the best ideas. Based on my observations, this is not working very well. C++ was written in 1985 on top of C which was written in the 1970s. By now, all the cool bells and whistles of modern programming should be available, but my experience is that templates are crude, shared_ptrs lack proper polymorphsim with pointers, futures lack continuations.
* Generics - C++ falls on its face for type-erasure.
* Rigid Generics - Making generics that allow multiple types is a headache.
* Futures - Futures are ugly and primitive. Still no support for continuations.
* Everything is manual - If you don't include the massive Boost library, you have to do everything by hand. For example: Problem I need to add 1 vector to another. Solution: a.insert(std::end(a), std::begin(b), std::end(b)). This is an ugly buggy solution instead of something like a.insertall(b). C++ seems absolutely filled with these oversights. Since vxlisp generates code it is easy to produce consistent results, but I would never want to code this way.
* hpp and cpp files - Wow. What a redundant mess. The order of declaration matters in the header. Template functions need to be in the header not the cpp file. Creating a workable balance between these to files was the biggest problem I had. The compiler should definitely handle hpp file creation for you. You can easily see why Java discarded separate header files when they copied C++.
* Brittle - Null pointer exceptions and memory leaks are the norm not the exception. It is extremely difficult to create any program that does not encounter these regularly.
* Exception Handling - Exception handling technically exists, but C++ programs still can crash past exception handling just by trying to reference a pointer to an object that has been deleted. Java is disgusting and it has far more robust exception handling.
* Learning resources - Being an old language, almost every question has been asked and answered. The problem is that so much time has past and best practices are all over that map. My experience was that almost every straight-forward example ended up being a dead-end that I had to gut and rework later. Very frustrating learning experience.
* Error messaging is vague - Balancing .hpp and .cpp files is complex and the messages produced by compiler are not helpful enough.
* Easy things are hard - Common cases like establishing robust classes, global variables, templates, pointer references are all overly complex.

### vxlisp to C++ conversion

* C vs. C++ - Since vxlisp does its own type validation, C++ objects exist purely to allow those working in C++ to use native C++ objects. I do feel that a simple C solution would be much more efficient, and I question whether C++ is just worse than C.
* Pointer vs. Instance - Referencing and dereferencing pointers is a complexity that I avoid by only using Pointers for everything except vectors and maps. This risks memory leaks but also simplifies code and prevents unnecessay object creation.
* Templates and Typecasting - Templates are similar to Java Generics but seem more rudimentary. They lack support for inheritence, so vector of dog is not polymorphic with vector of animal. This leads to a lot of vector copying.
* Inheritence - To avoid the diamond problem, all pointers refer to Abstract classes. This solves the problem nicely, but adds another layer of indirection and a lot of lines of code. Again a simple C solution would probably avoid this.
* DYI memory vx. Shared_ptr - When I discovered Shared_ptrs, I was ecstatic. All of my memory leak problems were solved. Unfortunately, Shared_ptr is implemented as a generic template, so I immediately run into the problem that a pointer to an dog can be put into a pointer to an animal, but a shared_ptr to a dog cannot be put into a shared_ptr to an animal.
* Futures - Futures and Shared Future seem incomplete because of a lack of continuation support. This confused me until I realized that it wasn't that hard to implement myself. I could have done Futures with generics, but the simple solution using Type_any seemed more robust.
* Header Files - They are unnecessary and an enormous pain, especially because call order matters and templates can only be done in headers.

## C

* Performance - Faster than even C++ since you don't have all the typecasting overhead.
* Imperitive - Imperitive code is always problematic.
* Memory Leaks - The bane of all C programmers.

## Kotlin

* Better Than Java - Since Java is so slow to improve, it has been easy for other languages to pass it. In my opinion, this is a low bar.
* Cross-platform - The new cross-platform features are very promising. I could understand choosing Kotlin as your primary language, especially if you are a Java programmer.
* Futures - Coroutines seem excellent, similar to vxlisp. Chef's kiss.
* Object-oriented - For me, OOP is always a negative.
* JVM - Most consider the JVM to be a bloated mess.
* Google - I doubt Google would abandon Kotlin, but they already dumped Java. Google has a tendency to create and drop languages over and over.
* Niche - Android is the only platform that I know of where it is used.

## Swift

* Apple - Apple is an amazing company, but they don't like to share their toys. Their oppressive practices will limit adoption of Swift to Apple fans or those who have no other choice.
* Windows - The Windows version seems like it is supported by one persion. I expect the Windows version to be a sad copy like Mono is for CSharp. I doubt Linux support will be much better.

## Flutter

* Dart - Dart is a relatively new and niche language with few libraries. Rewriting all of your business logic in Dart seems like a double-edged sword.
* Performance - Based on my limited research, Flutter does not match native performance.
* Google - Google has a tendency to create and drop languages over and over. Dart feels like one of those.
* Kotlin - Kotlin now has cross-platform support too. Both made by Google. What to do?

## React Native

* Design - React Native was supposed to be an extension of React but it is inconsistent with React. It was first designed to be object-oriented and imperitive and then preferred functional, but not always. Kind of a mess.
* Meta - Meta/Facebook created React and React Native. Whether or not they would use it for their own platforms was uncertain for a while.
* Performance - JavaScript engines cannot match native performance, so you will always take a hit.
* Windows/Web - Technically, React Native can create Windows and Web apps, but as far as I know these are not well supported.
* Dependencies - My experience with React Native was that it has a vast stack of dependent libraries that require specific versions to function. That made maintenence complicated and crash-prone.

## Node.js

* Performance - My understanding is that Node applications cannot match native performance on the server.
* JavaScript - This is good or bad depending on your perspective.
* TypeScript - Maybe an improvement, depends who you talk to.

## Golang

* Evolving - When I started writing the compiler, Golang didn't have generics. That's how unfinished it is.
* Easy - I quite enjoy how easy Go is use and deploy. So much nicer than C++.
* Google - Google has a tendency to create and drop languages over and over. Who knows how far Golang will last?
* Libraries
* Niche - Not much written in Golang.

## Rust

* Niche

## Scala

* Great Ideas
* JVM
* Niche

## JSON

* Good Syntax
* Lacks Complex Types

## XML

* Awful Syntax
* CDATA
* Encoding hell
* Attributes are limiting

## Common Lisp

* Performance
* Niche

## Clojure

* Great Syntax - vxlisp syntax is largely an expansion of Clojure.
* Good Performance - Clojure runs in the JVM, so decent performance.
* JVM
* Lacks Type-safety
* Poor Overloading
* Libraries
* Google - Unfortunately, Clojure suffers from the Google abandoned language curse.
* Niche - Never really took off.
