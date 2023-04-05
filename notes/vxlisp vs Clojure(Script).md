# Lisp Variant (VxLisp .vxlisp files)
## What is VXL/Vexel?
* VXL - Variable-Type Cross-Language Lisp
* Vexel is an opinionated general purpose functional language that prefers convention over configuration.
* It is open to be cross compiled into and interoperable with any number of languages and platforms with the hope of being as close to native as possible while maintaining the benefits of functional languages and lisp simplicity.
* It is NOT a platform. Compiling to other languages keeps the use cases of VxLisp as broad as possible. It also allows for progressive improvement in compilation as platforms or compilers are improved without changing source code.

## Why VXL/Vexel?
* VXL seeks to improve (in my opinion) on other language design patterns.
* It's primary goal is to be a simple language with minimal syntax that could theoretically be the only language a person would need to learn.
* It is based on ClojureScript which is in my opinion the most elegant language I have ever encountered, but it is not perfect. It's origin as an offshoot of Clojure which is an offshoot of Java gives it a lot of unnecssary baggage. It also lacks optional typing and is far from a general purpose language.
* It treats documentation, and test cases as first class citizens.
* It treats debugging, asynchronous programming, lamba functions, and error handling as core to the platform instead of after the fact bolt-ons.
* It expands on data types beyond traditional generics. This includes runtime type checks and default values.

## Command Line
vxlisp :run
vxlisp :build
vxlisp :publish
vxlisp :watch
vxlisp :outdated
vxlisp :add
vxlisp :remove
vxlisp :update
vxlisp :doc
vxlisp :test

## Project (project.vxlisp file)
(project myproject
 :version "0.1"
 :client  :react-native // :react|:react-native
 :server  :cljs         // :c|:c++|:clj|:cljs|:go|:java|:js|:rust
 :libs    []            // [:path path :ver version :repo //:npm|:maven|:sbt|:github :alias name :lang //:c|:c++|:clj|:cljs|:go|:java|:js|:rust]
 :doc     "Project Docs"
 :builds  [client [:client :react-native :test :auto :run (core/sample/main) :buildpath :auto]
           server [:server :node :test :auto :run (core/sample/main) :buildpath :auto])

## Keywords
:keyword
Keywords are prefixed with a colon

## Comment
// ignore to end of line
/* ignore block */

## Strings
"" Quotes treat leading whitespace on a line as a single space.
`` Block Quotes keep all whitespace

## Header
(package name
 :alias "alias"
 :libs  [library :path path ...]
 :doc "Package doc")

## Type
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

## Constant
(const name : type
 clauses :...
 :alias      "internal name"
 :private
 :protected
 :mutable
 :unsafe
 :deprecated "Version"
 :doc        "value doc"
 :test       clauses :...)

## Function
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
 :unsafe
 :wrapper
 :messages    // use message handling
 :parallel
 :1-:9        // generic type :1, :1, :2, etc.
 :bigospace     1|logn|n|nlogn|2n|n^2|2^n|n^n
 :bigotime      1|logn|n|nlogn|2n|n^2|2^n|n^n
 :doc         "function doc"
 :debug       clause // adds console debug code which outputs [funcname output params] if clause is true
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

# What does VxLisp attempt to address?
I have been programming for 40+ years, and I still have problems with every language I have encountered.

## Functional Programming
* Composition - Everything is a function, so building and nesting functions is obvious. HTML/XML works this way.
* Immutable Data
* Reduced Side Effects
* Straightforward Test Cases

## Cross Compilation

## Documentation
* Automatically generate documenation including test case data as examples.

## Testing
### Unit Testing
### Coverage Testing

## First Class Types and Functions

## Uniformity and brevity
Each language seems to attempt to solve a different problem, but even the simplest patterns seem to spiral into
extreme complexity. For example, I want to make an html page that displays one number divided by another. Blindly, I would write following:

<html>
  <body>
    <div>divide(4, 3);</div>
  </body>
</html>

Of course this doesn't work. It also has different patterns between html and javascript. I propose something
more unified using lisp syntax:

(html
 (body
  (div
   (/ 4 3)))

This obviously has fewer characters and follows a single design principle where every level is a function. In Javascript, this could be written like so which is roughly the same.

html(
  body(
    div(
      divide(4, 3)
    )
  )
);

## Error handling
Now say I accidentally divide by zero: divide(4, 0). This will throw a Javascript exception, crash, fail to produce a value, and potentially breaking the whole page. I don't like crashes. Every function should produce
legitimate value, along with any errors. The enclosing program can handle the error or not. Eventually the
topmost html function should display the error somewhere. Unfortunately, because error handling is not builtin
to the compiler we would have to write code in every function to catch any errors, return a default value and pass any errors up the chain.

VxLisp seeks to have the compiler handle this for me.

## Asynchronous programming
Now say I want to have each value come from a webservice call. I could write this in VxLisp like this:
(html
 (body
  (div
   (/
    (webservice "a")
    (webservice "b")))))

And in Javascript like this:
html(
  await body(
    div(
      divide(
        await webservice("a"),
        await webservice("b"))
    )
  )
);

Again this won't be so easy. Webservice calls are asynchronous by nature, so certain functions above will
have to be rewritten to be asynchronous too. Not impossible but a lot of boilerplate work.

VxLisp seeks to have the compiler handle this for me.

## Complex Types
As projects and teams grow, type safety becomes more and more useful. Type safe languages are a double-edged sword, however.
* Optional Type Safety - Type safety is a nuisance in smaller projects. It would be better if types could be added as needed, or added as a compiler directive to enforce, optionally enforce, or report on vague types.
* Consistent Typing - Different languages treat type safety differently and this can be a huge barrier to learning a new language or solving problems.
* First Class Types - Many languages have bolted on Generics to their type systems with mixed results and reaability. E.g. Java Generics are not available at runtime without reflection.
* First Class Functions - Function declarations are also types and can be used whereever a type check is needed.
* Composition and Reuse - Complex types are often not nameable and composable. Defining a type and reusing it is much cleaner than typing them again and again. If I have an array where each value can be an int or a string, a good type system should make this trivial.
* Constraints - Types should also include constraints that are automatically checked when a value of that type is created or updated.
* Default - Types should have a default value, so creating them is easy.
* Missing - Values should be able to compare against an missing value which is stil a legitimate value of that type instead of checking for null and risking crashes.
* Instancing - All types can be instanced with (new mytype args :...) or with the syntactic sugar form (mytype args :...) e.g. (new string "Hello") or (string "Hello") (stringlist "a" "b" "c")
* No Null Values - All types have an immutable empty value. All functions return their empty value as a default instead of null. This value can be accessed using (empty mytype) or with the syntactic sugar form (mytype). e.g. (empty string) or (string) (stringlist)

## Functions
* Airity - VxLisp seeks to encourage variable numbers of arguments by making the pattern easier to write. Any argument may be followed by the :... keyword to indicate multiple arguments. Within the function these will be an array.
* Overloading - Most languages do not like having the same function name in the same package or in ambiguous packages. VxList doesn't see a problem with this as long as the signature of the function is different. I.e. the types used are different in some way. The compiler should flag ambiguous functions.
* Native Code
