# Features

## Open Source

It's pretty simple.

* Open Source = Good
* Closed Source = Bad

## Compact consistent syntax

* Parenthesis - Lisps contains each idea in a list. A function foo(1, 2) would be written as (foo 1 2). Note: empty parentheses () are invalid in vxlisp.

Object-oriented code typically has two patterns:

static calls: e.g. String.replace(mytext). vxlisp would be written as (replace mytext)

method calls: e.g. myobject.foo(myval). vxlisp would be written as (foo myobject myval)

vxlisp (and all lisps) always put the verb first.

* Delimiters - vxlisp uses any amount of whitespace as a single delimiter. No comma, no semi-colons. New lines and tabs don't matter. Focus on readability. In my experience, the vast majority of my compile errors in other languages are missing semi-colons and commas.

* Square Brackets - Clojure used [] to separate function arguments from the rest of the function definition. vxlisp copies that behavior and adds type declarations and more. e.g.
    (func myfunc : string
     [arg1 : string
      arg2 : string])

* Keywords : (colon) - Any word starting with : is considered a keyword. 

: - Colon by itself is a type declaration. e.g. (func foo : string)

:= - Colon equal sign is a variable assignment. e.g. (let [a := "Hello"])

:{text} - Any other string is a keyword for a map or a constant. This is similar to JavaScript maps/objects.

    vxlisp: (map :key1 value1 :key2 value2)
    JavaScript: {key1: value1, key2: value2}

* Double Quote "" - Double quotes surround strings. The string maintains linefeeds, but the string matches the indentation to the opening quotation mark. e.g. The following text would have a linefeed but no spaces "line1\nline2".
    "line1
     line2"

* Backtick Quote `` - When needed any string surrounded by backticks will be kept intact including indentation, double quotes and escape characters. e.g. The following text would have a linefeed and a number of spaces "line1\n     line2".
    `line1
     line2`

## Interoperable with native code

vxlisp generates native, readable code, so vxlisp functions can be directly called from other libraries. Also, vxlisp supports a (native) function that will be compiled into the generated code, so native language functionality can be built into vxlisp code.

## Everything is the same data structure

Choice of datastructure for a language is a key decision when dealing with data. Long ago it was csv files, then XML, now JSON. But JSON is only a subset of JavaScript and JavaScript itself has very vague and constantly changing standards. vxlisp chooses LISP as a standard because it is simple. XML is very similar to a LISP but has made many awkward design decisions that make fairly ugly and awkward as a programming language. vxlisp adds strong-typing and simple type constructors to produce a concise datastructure that is also elegant code:

    (person
     :firstname "Mary"
     :lastname  "Jane"
     :gender    :female
     :age       23)

    In Java this would look like:

    Person person = new Person();
    person.firstname = "Mary";
    person.lastname = "Jane";
    person.gender = "female";
    person.age = 23;

## All-in-one: code, test, documentation

vxlisp includes test cases and documentation directly inside function source code. Further, vxlisp produces uniform documentation and test results regardless of platform to enform maximum simplicity and visibility.

## Test cases in documentation

Test cases appear within published html documentation. This allows managers, support reps, test team, and junior developers to learn how a function works and whether particular cases are covered in test. This also pressures to developer to produce readble docs and thourgh tests because people are watching.

## Avoids Code Obsolescence

Languages change all the time and yesterday's tools may be incompatible with new standards. A few examples are modules being introduced to C++ in 2020. This standard eliminates header files and completely rewrites code. Java has a long history of introducing standards filled with problems and later introducing new standards like Date handling or CompletableFutures replaceing Futures in Java8. Apache Foundation practically exists to patch bad Java design. vxlisp allows you to recompile your code to a new standard and pass all of your old tests.

## Type-safety and Generics

vxlisp is strongly-type and supports generics (without erasures).

I have gone back and forth on the importance of type-safety. Type-safety should be a good thing, but if you spend a lot of time on type-safety, you might have been better off making more test cases. My conclusion is that type-safety is good, but many languages (I'm looking at you Java) are so cumbersome that the benefit is unclear. JavaScript and Clojure are not type-safe. Java has a sloppy, incomplete type-erasure system. C# and Typescript are better, but generics are still hard for laymen. Hopefully, you will find vxlisp to be more elegant.

### Mixing Types

Non-Typesafe Languages: For non-typesafe languages mixing types is easy, but there are no checks for type:

    ["a", 1, 2.5, bar]

Typesafe Languages: For typesafe languages a construct like this is not directly possible, so you have to defeat typesafety by using a non-typesafe generic:

    new List<Object>["a", 1, 2.5, bar]

vxlisp: vxlisp enforces typesafety on such constructs by declaring type and allowing substypes.

    (type foo :extends :list :allowtypes [string, int, float, bar])

    (foo "a", 1, 2.5, bar)

### Complex Types

For this example, we want to create a complex structure: a map of lists of integer map.

Non-Typesafe Languages: For non-typesafe languages, creating complex structures is error prone:

    foo = {a: [{b: 4}]}

Typesafe Languages: For typesafe languages, you gain typesafety, but you some force you to redeclare types again and again. Very confusing and irritating.

    Map<string, List<Map<string, int>>> foo = new Map<string, List<Map<string, int>>>{a: new List<Map<string, int>(new Map<string, int>){b: 4}()>}

vxlisp: Types are declared upfront and reused (like C++ typedef).

    (type type1 :extends :map :allowtypes [int])

    (type type2 :extends :list :allowtypes [type1])

    (type type3 :extends :map :allowtypes [type2])

    (let
     [foo := (type3 :a (type2 (type1 :b 4)))])

## Generic Types

Other languages usually define generics using captial letters like T and declares List, Map, etc. using that T. vxlisp uses a suffix number to distinquish and relate generic types. e.g. any-1 and list-1 refer to the same generic.

    Java:
    <T, U> List<U> convertList(List<T> mylist) {
      List<U> output = new List<T>();
      for (T myval : mylist) {
        output.add(foo(myval));
      }
      return output;
    }

    vxlisp:
    (func convert-list : list-1
     [mylist : list-2]
     (list<-list : list-1
      mylist
      (fn : any-1
       [myval : any-2]
       (foo myval))
     )
    )

## Immutability

Everything in vxlisp is logically immutable. Once you have created an object, it cannot be changed. This is the same as String in most languages. e.g. a = "Hello"; b = a.substring(0, 2); // a is unchanged.

There are only 2 functions to make an object in vxlisp: (new) and (copy), so once you make an object it is safe to use and cannot change. All pointers to objects can be freely passed ByRef since subfunctions will not alter them.

Lists and Maps do shallow copies since their children are also immutable. This is obviously not the way Object-Oriented Programmers see the world, but it is simple and the rewards reaped from simplicity are worth the trade-offs. Note: when comparing the cost of shallow copies to other languages, remember that if you are passing a parameter ByVal (aka final in Java), the compiler is already making a copy, sometimes a large and deep one (Golang tends to do this a lot).

## Thread-safety

Since objects are immutable, they are thread-safe. This can never be 100% the answer, but it is close.

## Error Handling

TRIGGER ALERT! In my opinion, try-catch exception handling is a design flaw. It is an all or nothing result where you either get a result or an exception. This is like taking a test with no partial credit even you just put the wrong date at the top.

vxlisp attempts to address this by allowing EVERY object to contain any number of error messages IN ADDITION to their normal result. Some erros may be big, some may be trivial warnings. Each calling program can decide what to do with them (if anything). Erros will automatically be bubbled up to each further result.

    (func foo : string
     [value : string]
     (if
      (then (= value "Dog")
       (string "echo " value
        :msg (msg :severity msg-warning :text "Are you sure you want a dog?")))
      (else (string "echo " arg)))
     :doc "This function echos the original value and also produces a warning if the value is a Dog.")

vxlisp also tries to reduce the number of exceptions generated in the first place. There are a few possible sources of errors:

* Logical errors - If you code something wrong the best way to control it is tightly knit error trapping. vxlisp seeks to bundle test with the original function to address this. It also supports a :debug tag that adds code to a function to log all input and output from that function.
* Type mismatch - vxlisp is strongly typed, so this should be a rare occurrance.
* Thread conflicts - vxlisp focuses on immutables, so thread safety mostly comes out of the box.
* Runtime exceptions - vxlisp cannot prevent runtime exceptions, but it uses the :messages tag to simply enable try-catch exceptions and quietly bubble them up into the return values so function API's need not be changed.
* Null exceptions - vxlisp mostly eliminates null by enforcing the existence of an empty object for every type. Every function is guaranteed to return a legal object of the desired type regardless of the error.
* Infinite Loops - vxlisp does not support while or until loops. Every interator must be finite.
* Heap usage - vxlisp is planned to incorporate a memory pool for object recycling and memory releasing. Immutable values should make mark and sweep garbage collection fairly effective.
* Infinity Recursion - Sorry, no solution to this one yet. vxlisp does not yet support tail-recursion.

## Multiple inheritence

Typesafe languages have a problem with complex inheritence structures. The Deadly Diamond of Death occurs when 2 classes inherit from a common class and then another class inherits from both of them. e.g. Dog extends Animal, Cat extends Animal, Hybrid extends Dog, Cat. Java avoided this by leaning on interfaces, but this still requires a lot of planning and code.

vxlisp handles the problem of multiple inheritence in a similar way to Scala traits and Java interfaces.Instead of defining a separate interface, you simply use the :traits tag to list the types you inherit. vxlisp does the heavy lifting for you.

    (type animal :extends struct)

    (type dog :extends :struct :traits [animal])

    (type cat :extends :struct :traits [animal])

    (type hybrid :extends :struct :traits [dog, cat])

## Constructors

All values are created through the (new {type} {args}) function or just ({type} {args}).

* "ab" is the same as (new string "ab") is the same as (string "ab")
* 4 is the same as (new int 4) or (int 4)
* (new stringlist "a" "b") is the same as (stringlist "a" "b")
* (new stringmap :foo "a" :bar "b") is the same as (stringmap :foo "a" :bar "b")
* (new foobar :foo "a" :bar "b") is the same as (foolbar :foo "a" :bar "b")

## Empty Types

All types have an empty value written as (empty {type}) or just ({type}).

* "" is the same as (empty string) is the same as (string)
* 0 is the same as (empty int) is the same as (int)
* false is the same as (empty boolean) is the same as (boolean)
* (empty stringlist) is the same as (stringlist)
* (empty stringmap) is the same as (stringmap)
* (empty foobar) is the same as (foobar)
* (is-empty {value}) can be used to check for whether a given value is empty.

## Type Metadata

* All types have a metadata value that can be used for type comparisons and type definition information. This can be accessed by (type<-any {value}). The resulting type value can be used in any compare operation such as a switch statement.

    (func foobar : string
     [myval : any]
     (switch (type<-any myval)
      (case string "I'm a string")
      (case int "I'm an int")
      (case foo "I'm a foo")
      (else "What am I?"))
     :doc "Returns a string from any value")

* Free form type casting. Any value can be cast to any type by using (any<-any {value}). This function is guaranteed to return an object of the correct type without exception, but if the cast is unsuccessful the result will be the empty value.

    (func foobar : foo
     [myval : bar]
     (any<-any bar)
     :doc "Returns a bar from a foo.")

## Context management

Most applications require some form of context. vxlisp standardizes this by simply adding :context tag to a function. The function will automatically have a context variable added and a test context will be sent to all test cases.

## Asynchronous code

Asynchronous programming (futures/promises) is extremely common in modern programs using non-blocking http, io, or database traffic. However, most languages struggle with the concept and have multiple failed iterations and generally poor support for async (especially in test). The await command in JavaScript and Dart is the closest to a comfortable programming model. vxlisp seeks to take this a step further. A function simply needs the :async keyword and then operations within will transparently handle the async/sync process. Note: non-async functions cannot call async functions.

    (func httpget1 : string
     "Hello"
     :async
     :doc "Asynchronously return a string from a webservice.")

    (func httpget2 : string
     "World"
     :async
     :doc "Asynchronously return a string from a webservice.")

    (func foobar : string
     (let
      [myvar1 : string := (httpget1)
       myvar2 : string := (httpget2)]
      (string myvar1 " " myvar2))
     :async
     :doc "Asynchronously manipulate the result of an async.")

The equivalent JavaScript or Dart code would be similar but you would have to add awaits. The C++ or Java code would boggle the mind with its complexity. Also, note that most JavaScript examples use old, ugly .then chaining which is also horrible.

Also, all tests in vxlisp transparently handle async functions which is extremely rare in test suites.

## Permissions

## Simplified overloading

Some languages like Clojure have ugly function overloading methodologies, and most languages have many arbitrary limits to overloading. vxlisp takes a simpler approach to overloading: almost every function can be defined any number of times and even with the same parameters. The compiler will link the first function that matches the given return value and arguments. It searches within each package down the library list.

    (func + : foo
     [arg1 : foo
      arg2 : foo]
     :doc "Override + operator for foo.")

## Webserver

## Documentation builder

By executing the doc command (e.g. ./rundoc), a hyperlinked html document is generated displaying type, const, func, project and package data as well as displaying test and source code. No outside tool is needed.

## Test suite

The test suite in vxlisp is designed to transparently run asynchronous and synchronous code as well as context-sensitive code. The test suite is functional in design and execution and display is written in vxlisp, so it can be altered to the user's needs.

## Test coverage

Since test is written in the source, coverage reporting is trivial and requires no outside libraries.

## BigO coverage

Since Big-O (Time/Space Complexity) is written in the source, Big-O coverage reporting is trivial and requires no outside libraries. A separate :bigo-space and :bigo-time are included in each function to document memory hungry and slow functions respectively. Big-O coverage is built into the test suite as well.

## Functions are first class objects

Like JavaScript, functions are first class objects and can be passed around as parameters (especially as lambda functions).

## Simple access to type metadata

Typedef and Funcdef information is available from any object, so you can call (typedef<-any myobject) or get the meta data (reflection) from any object at any time.

## Universal serialization/deserialization

Every object in vxlisp (including user defined ones) have a direct serialization and deserialization path. This is especially useful for debugging, testing, state-management, and client-server transit. (string<-any myobject) will get the string result.

## Memory Pooling

## State Management

## File parsing

## Repl

## Programmatic Html/Xml generation

## Few restricted characters

Because of the simple lisp format, you have great freedom to name things as you please. Restricted characters are ()[]/"`.:

Obviously, don't overload (package), (type), (const), or (func).

## Free use of whitespace

Whitespace is a delimiter in vxlisp, but any amount of whitespace is only 1 delimiter, so you may use whitespace for readability.

## Potential to write code from documentation

With a built in webserver, it would not be difficult to allow code editing directly in the online documentation. This would definitely be a cute feature, but I am unsure of how valuable it would be.

## Potential to easily write code to unusual platforms like Html Canvas or WebAssembly

When the C++ compiler is complete, WebAssembly code should be manageable and it might be worth it to manipulate canvas as well. Hmm...

## Potential to simultaneously write native android and IOS without middleware like flutter or react native

Since vxlisp compiles to JavaScript, it should already support react native integration. If I compile to Dart, flutter could be supported. Alternatively, we could be very agressive and compile native android and IOS Swift code. Hmm...
