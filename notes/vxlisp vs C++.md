# vxlisp vs C++

Warning: This is my first C++ project, so there are going to be a lot of misconceptions and questionable decisions in my perspective and solution. I don't mind constructive criticism, and I will endeavour to endure unconstructive criticism as well.

## Pros of C++

* Ubiquitous - C++ is a well-established language that forms the bedrock of most complex systems such as Operating Systems.
* Performance - It has fairly optimal memory and execution performance with only native C and Assembly being superior.
* Native - Strong ability to program close to the 'metal'.
* Hard things are easy - Pointers give you a great deal of power to do what you want.

## Cons of C++

Trigger Alert! - Strong opinions incoming.

* Syntax is arcane - C++ notation emphasizes brevity over readability. Since C++ is a compiled language, this is completely unnecessary. I could argue that every language that has come after C++ is a direct reaction to C++ awkwardness.
* Language shows its age - C++ prides itself on avoiding code bloat in the standard library and supporting old hardware. Code bloat is instead moved to the Boost library from which the standards committee adopts the best ideas. Based on my observations, this is not working very well. C++ was written in 1985 on top of C which was written in the 1970s. By now, all the cool bells and whistles of modern programming should be available, but my experience is that templates are crude, shared_ptrs lack proper polymorphsim with pointers, futures lack continuations.
* Everything is manual - If you don't include the massive Boost library, you have to do everything by hand. For example: Problem I need to add 1 vector to another. Solution: a.insert(std::end(a), std::begin(b), std::end(b)). This is an ugly buggy solution instead of something like a.insertall(b). C++ seems absolutely filled with these oversights. Since vxlisp generates code it is easy to produce consistent results, but I would never want to code this way.
* hpp and cpp files - Wow. What a redundant mess. The order of declaration matters in the header. Template functions need to be in the header not the cpp file. Creating a workable balance between these to files was the biggest problem I had. The compiler should definitely handle hpp file creation for you. You can easily see why Java discarded separate header files when they copied C++.
* Brittle - Null pointer exceptions and memory leaks are the norm not the exception. It is extremely difficult to create any program that does not encounter these regularly.
* Exception Handling - Exception handling technically exists, but C++ programs still can crash past exception handling just by trying to reference a pointer to an object that has been deleted. Java is disgusting and it has far more robust exception handling.
* Learning resources - Being an old language, almost every question has been asked and answered. The problem is that so much time has past and best practices are all over that map. My experience was that almost every straight-forward example ended up being a dead-end that I had to gut and rework later. Very frustrating learning experience.
* Error messaging is vague - Balancing .hpp and .cpp files is complex and the messages produced by compiler are not helpful enough.
* Easy things are hard - Common cases like establishing robust classes, global variables, templates, pointer references are all overly complex.

## vxlisp to C++ conversion

* C vs. C++ - Since vxlisp does its own type validation, C++ objects exist purely to allow those working in C++ to use native C++ objects. I do feel that a simple C solution would be much more efficient, and I question whether C++ is just worse than C.
* Pointer vs. Instance - Referencing and dereferencing pointers is a complexity that I avoid by only using Pointers for everything except vectors and maps. This risks memory leaks but also simplifies code and prevents unnecessay object creation.
* Templates and Typecasting - Templates are similar to Java Generics but seem more rudimentary. They lack support for inheritence, so vector of dog is not polymorphic with vector of animal. This leads to a lot of vector copying.
* Inheritence - To avoid the diamond problem, all pointers refer to Abstract classes. This solves the problem nicely, but adds another layer of indirection and a lot of lines of code. Again a simple C solution would probably avoid this.
* DYI memory vx. Shared_ptr - When I discovered Shared_ptrs, I was ecstatic. All of my memory leak problems were solved. Unfortunately, Shared_ptr is implemented as a generic template, so I immediately run into the problem that a pointer to an dog can be put into a pointer to an animal, but a shared_ptr to a dog cannot be put into a shared_ptr to an animal.
* Futures - Futures and Shared Future seem incomplete because of a lack of continuation support. This confused me until I realized that it wasn't that hard to implement myself. I could have done Futures with generics, but the simple solution using Type_any seemed more robust.
