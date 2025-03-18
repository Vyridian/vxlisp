# Functions

```lisp
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
 :sideeffects // denotes function with hidden sideeffects
 :wrapper
 :messages    // use message handling
 :parallel
 :bigospace   // :1 :logn :n :nlogn :2n :n^2 :2^n :n^n
 :bigotime    // :1 :logn :n :nlogn :2n :n^2 :2^n :n^n
 :doc         "function doc"
 :debug       // adds console debug code which outputs [funcname output params] if clause is true
 :test        clauses ...
 :deprecated  "version")
```

## Function Overloading

* Simply define the function multiple times with the same name. The compiler will use the first matching signature.

## Lamba Function

```lisp
(fn : type
 [arg : type :doc "arg doc" ...]
 clauses ...
 :async
 :doc "function doc"
 :test clauses ...)
```

## Generic Functions

Generic functions are defined by adding a dash and a number from 1-9 to the end of any, list or map types. The matching number indicate matching types.

```lisp
    (func myfunc : any-1
     [myvar  : any-2
      mymap  : map-1
      mylist : list-2])
```

The above function would be represented like this in Java:

```java
    public static <T extends Core.Type_any, U extends Core.Type_any> T myfunc(
      U myvar,
      Map<String, T> mymap,
      List<U> mylist) {}
```

## Native Code

```lisp
(native :lang :cpp|:csharp|:java|:js|:kotlin|:swift clauses|:auto ...)
```

* The `:auto` keyword automatically creates a native stub that should be implemented in code behind.

* Code Behind - A native text file (e.g. mypackage_java.txt) can be placed in the same folder as the mypackage.vxlisp file and it will be compiled into the generated code.
