# Features

## Open Source

Open Source = Good
Closed Source = Bad

## Compact consistent syntax

* Parenthesis - Lisps contains each idea in a list. A function foo(1, 2) would be written as (foo 1 2). Note: empty parentheses () are invalid in vxlisp.
* Delimiters - vxlisp uses any amount of whitespace as a single delimiter. No comma, no semi-colons. New lines and tabs don't matter. Focus on readability.
* Square Brackets - Clojure used [] to separate function arguments from the rest of the function definition. e.g.
    (func myfunc : string
     [arg1 : string
      arg2 : string])
* Keywords
* Double Quote "" - Double quotes surround strings. The string maintains linefeeds, but the string matches the indentation to the opening quotation mark. e.g. The following text would have a linefeed but no spaces "line1\nline2".
    "line1
     line2"
* Backtick Quote `` - When needed any string surrounded by backticks will be kept intact including indentation, double quotes and escape characters. e.g. The following text would have a linefeed and a number of spaces "line1\n     line2".
    `line1
     line2`

## Interoperable with native code

## Everything is the same data structure

## All-in-one: code, test, documentation

## Test cases in documentation

## Immutability

## Thread-safety

## Generics

## Error Handling

There are a few possible sources of errors:

* Logical errors - If you code something wrong the best way to control it is tightly knit error trapping. vxlisp seeks to bundle test with the original function to address this. It also supports a :debug tag that adds code to a function to log all input and output from that function.
* Type mismatch - vxlisp is strongly typed, so this should be a rare occurrance.
* Thread conflicts - vxlisp focuses on immutables, so thread safety mostly comes out of the box.
* Runtime exceptions - vxlisp cannot prevent runtime exceptions, but it uses the :messages tag to simply enable try-catch exceptions and quietly bubble them up into the return values so function API's need not be changed.
* Null exceptions - vxlisp mostly eliminates null by enforcing the existence of an empty object for every type. Every function is guaranteed to return a legal object of the desired type regardless of the error.
* Infinite Loops - vxlisp does not support while or until loops. Every interator must be finite.
* Heap usage - vxlisp is planned to incorporate a memory pool for object recycling and memory releasing. Immutable values should make mark and sweep garbage collection fairly effective.
* Infinity Recursion - Sorry, no solution to this one yet. vxlisp does not yet support tail-recursion.

## Multiple inheritence

vxlisp handles the problem of multiple inheritence in a similar way to Scala traits and Java interfaces.Instead of defining a separate interface, you simply use the :traits tag to list the types you inherit. vxlisp does the rest.

## Constructors

All values are created through the (new {type} {args}) function or just ({type} {args}).

* "ab" is the same as (new string "ab") is the same as (string "ab")
* 4 is the same as (new int 4) or (int 4)
* (new stringlist "a" "b") is the same as (stringlist "a" "b")
* (new stringmap :foo "a" :bar "b") is the same as (stringmap :foo "a" :bar "b")
* (new foobar :foo "a" :bar "b") is the same as (foolbar :foo "a" :bar "b")

## Empty Types

All types have an empty value written as (empty {type}) or just ({type})

* "" is the same as (empty string) is the same as (string)
* 0 is the same as (empty int) is the same as (int)
* false is the same as (empty boolean) is the same as (boolean)
* (empty stringlist) is the same as (stringlist)
* (empty stringmap) is the same as (stringmap)
* (empty foobar) is the same as (foobar)
* (is-empty {value}) can be used to check for whether a given value is empty.

## Context management

Most applications require some form of context. vxlisp standardizes this by simply adding :context tag to a function. The function will automatically have a context variable added and a test context will be sent to all test cases.

## Asynchronous code

## Permissions

## Simplified overloading

## Webserver

## Documentation builder

By executing the doc command (e.g. ./rundoc), a hyperlinked html document is generated displaying type, const, func, project and package data as well as displaying test and source code. No outside tool is needed.

## Test suite

The test suite in vxlisp is designed to transparently run asynchronous and synchronous code as well as context-sensitive code. The test suite is functional in design and execution and display is written in vxlisp, so it can be altered to the user's needs.

## Test coverage

Since test is written in the source, coverage reporting is trivial and requires no outside libraries.

## BigO coverage

Since Big-O is written in the source, Big-O coverage reporting is trivial and requires no outside libraries. A separate :bigo-space and :bigo-time are included to differentiate memory hungry vs. slow functions.

## Functions are first class objects

## Simple access to type metadata

## Universal serialization/deserialization

## Memory Pooling

## State Management

## File parsing

## Repl

## Programmatic Html/Xml generation

## Few restricted characters

## Free use of whitespace

## Potential to write code from documentation

## Potential to easily write code to unusual platforms like Html Canvas or WebAssembly

## Potential to simultaneously write native android and IOS without middleware like react native
