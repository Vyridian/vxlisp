# Project

* project.vxlisp - There can be only one project file and it must be in the root of your project and it must be named project.vxlisp.

* (project) - The project file must have only one (project) type and nothing else.

(project core                      // The name of the project
 :version    "0.5"                 // The version of the project
 :author     ""                    // The author of the project
 :doc        "The vx/core project" // The description of the project for documentation.
 :javadomain "com.vxlisp"          // A special variable for Java project prefixing
 :libs                             // A list of libraries to include when building a language.
  (lib javaniofile
   :path "java.nio.file.*"
   :lang :java)
 :cmds                             // A list of command line options available.
  (cmd srccpp
   :code    :source
   :lang    :cpp
   :path    ../cpp/src/main
   :main    vx/core/main
   :context vx/core/context-main
   :filter  vx/core/myfunc         // For debugging test. Filters test to only a single function.
   :doc     "Build C++ Source Code")
)

## Libraries

## Commands

Commands are command line options when running the vxlisp executable. Any number of commands may be chained into one command line.

Sample:
vxlisp_win64 doc srcjs testjs srcjava testjava --path %currentfolder%/vxlisp

* :main - When you build a project, the main function will be run when the application starts. This setting can be changed to any function you choose. The setting is found in your project file project.vxlisp:

(project
 :cmds
  (cmd
   :main vx/core/main))

## Context

* When you build a project, the context function will be run when the application starts to generate application level context. This setting can be changed to any function you choose. The setting is found in your project file project.vxlisp:

(project
 :cmds
  (cmd
   :context vx/core/context))
