# How To: Add a New Language

vxlisp should be able to transpile into any modern language. This is a guide to adding your favorite.

## Considerations

* OOP or Duck-typing - Decide if you want to make an object-oriented design (e.g. Java/C++) or a structure based design (e.g. JavaScript/C). OOP typing generates a lot more code and type castings, but will be much more natural in an OOP language.
* Function Pointers - If your language doesn't function pointers, then they have to be simulated with objects or the compiler.
* Immutables - vxlisp is immutable by design, but your implementation does not need to use immutables if you wish.
* Memory Management - If your language does not support Garbage Collection, you will have to manage it yourself. I used reference counting in the C++ code.
* Async (e.g. Future/Promise/Thread/Coroutine) - If your language does not support Futures, you will have to add it. I did this for C++ because it was easier for me.
* External Libraries - vxlisp is intended to have minimal dependencies (keep it simple). Avoid dependencies wherever possible.
* folder requirements - Each language has particular source and test folder conventions.
* Native Compiler - You will obviously need a native compiler configured to run the generated code. This includes dependency management.
* Sample source and test files - Make a sample app, library, and test file and compile and run them. These will be your working models. For consistency create runcompile, runapp, and runtest scripts.

Steps:

1. Language Code - Choose a code for the language. For this example we will use the code "python".

2. Lang Constructor - In vxlisp project, open LangNative.go and add a new var LangPython and a constructor. Copy the constructor from its most similar language.

var langpython = NewLangPython()

func NewLangPython() *vxlang {
	output := new(vxlang)
	output.name = "python"
	output.sourcename = "core"
	output.sourcefile = ".py"
	output.pkgpath = "vx_core"
	output.pkgname = "vx_core"
	output.pkgref = "."
	output.future = "CompletableFuture"
	output.indent = "  "
	output.lineend = ";"
	output.itfext = "extends"
	output.classext = "extends"
	output.typeref = "."
	return output
}

3. New Commands - In vxlisp-vxcore, open the project.vxlisp file and create new commands for source and test.

  (cmd srcpython
   :code    :source
   :lang    :python
   :path    ../build/python/src/main
   :main    vx/core/main
   :context vx/translation/en/context-en
   :doc     "Build Python Source Code")
  (cmd testpython
   :code    :test
   :lang    :python
   :path    ../build/python/src/test
   :context vx/translation/en/context-test
   :doc     "Build Python Test Code")

4. Create Scripts - In vxlisp-vxcore, create new script files to run and compile. Copy buildjava.bat and .sh and name them buildpython.bat and buildpython.sh. In those files, replace java with python.

5. Generate Code - Run the script. If everything went to plan, you will have new folders for source and test in their proper places.

6. Code Behind - Now you will need to add a code-behind to vxlisp files that need native code. Create a text file in src/vx folder named core_python.txt. The contents of this file will be injected into the generated code. Define any common routines here. See other languages for examples. Note: C++ has special syntax for header files and compile ordering.

7. External libararies - If you need external libraries, add them to the project.vxlisp.

(project
 :libs
  (lib javaniofile
   :path "java.nio.file.*"
   :lang :java)
 ...)

You can then reference it in a package:

(package vx/data/file
 :libs (lib tb  :path vx/data/textblock)
       (lib typ :path vx/type)
       (lib javaniofile)
 :doc "File handler")

8. Syntax differences - From here, you must add new switch statements to the different functions in LangNative.go to support your language.

func LangNativeAppMainOpenClose(
	lang *vxlang) (string, string) {
	mainopen := ""
	mainclose := ""
	indent1 := LangIndent(lang, 1, true)
	switch lang {
	case langcsharp:
		mainopen = indent1 + "static void Main(string[] args) {"
		mainclose = indent1 + "}\n"
	case langjava:
		mainopen = indent1 + "public static void main(String[] args) {"
		mainclose = indent1 + "}\n"
	case langkotlin:
		mainopen = indent1 + "fun main(args : Array<String>) {"
		mainclose = indent1 + "}\n"
 case langpython:
  mainopen = ????
  mainclose = ????
	}
	return mainopen, mainclose
}

9. :create and :destroy - Some objects need private variables to function. The :create and :destroy keywords contain code that will be injected for constructing and destructing objects.

10. Main Function - Once you can a compile to work, the next step is getting the main() function to work. Look at src/vx/core.vxlisp and find the (native) functions. You will need to add your language tag and either a string of native code or the keyword :auto.

(func string-repeat : string
 [text   : string
  repeat : int]
 (native
  :cpp
   "std::string stringtext = vx_core::vx_string_from_string_repeat(text->vx_string(), repeat->vx_int());
    output = vx_core::vx_new_string(stringtext);"
  :csharp :auto
  ...))
 
 The :auto tag will assume the existence of an identically named function in the code-behind file with a vx_ prefix.

// In src/vx/core_csharp.txt
  public static string vx_string_repeat(
    string text,
    int repeat) {
    System.Text.StringBuilder sb = new System.Text.StringBuilder(
      text.Length * repeat);
    sb.Insert(0, text, repeat);
    string output = sb.ToString();
    return output;
  }

11. Test Suite - Once the main function works, work on the testsuite. You can either work toward an integrated Test library like JUnit or just write another command line function to do test. I used existing libraries for Java, CSharp, and Kotlin. I used a command line function for C++. And I used an HTML page for JavaScript. There are 2 important things to pay attention to: The test_basics test and the resources folder.

Test_basics are functions required for general tests to run.

  @Test
  void test_basics() {
    TestLib.test_helloworld();
    TestLib.test_async_new_from_value();
    TestLib.test_async_from_async_fn();
    TestLib.test_list_from_list_async();
    TestLib.test_pathfull_from_file();
    TestLib.test_read_file();
    TestLib.test_write_file();
  }

The test/resources folder holder 3 important generated files, generated in order from each other:

* testsuite.vxlisp - The raw output of the testsuite in vxlisp format.
* testsuitenode.vxlisp - The testsuite formatted as logical html, though still in vxlisp.
* testsuite.html - The testsuite fully formatted as html. Open this in a browser to see test results.

Use git (or other version control) to watch for changes to these files.

12. Test individual functions - Use the :filter tag to generate individual tests. The following :filter only creates test for (func is-error) in vx/core.

  (cmd testpython
   :code    :test
   :lang    :python
   :path    ../build/python/src/test
   :context vx/translation/en/context-test
   :filter  vx/core/is-error
   :doc     "Build Python Test Code")

13. Finishing Up vx/core - Once the test suite works, only debugging and maybe memory leaks remain.

14. Other projects - Now that you've finished vx/core, you may need native code in other projects as well.
