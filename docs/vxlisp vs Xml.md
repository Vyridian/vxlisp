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
