# Writing vxlisp Code

## The Philosophy of vxlisp

* Start with a rough sketch - Make empty types and functions. They still compile.
* Keep it simple - Break up large functions into many tiny functions.
* Move fast and break things - Iterate rapidly. If you can run JavaScript on your project, you can use that to test very quickly by not recompiling over and over.
* Test is your friend - Add test before you write code. Test acts as documentation and keeps you focused.
* Focus on the happy case - Ignore error trapping until later. You probably won't need to refactor.
* Async and Context are your friend - Be aware of functions that may need async or context and add them to your API early to avoid future refactors.
* vxlisp is not supposed to be imperitive or Object Oriented. You can write OOP behaviors, but you shouldn't.
* vxlisp is supposed to be a standalone language. Try to resist adding any external libraries to the core of the language. Each dependency is a separate thing to maintain.
