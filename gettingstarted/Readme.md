# Getting Started

## Installation

1. Create a folder to hold vxlisp projects. (e.g. vxprojects)

2. Copy contents of this gettingstarted folder into it.

## Create your own project

1. Copy the projecttemplate folder and rename it. (e.g. myproject)

## Create a package

1. Rename the packagetemplate folder inside your project (e.g. myproject/mypackage)

## Create a program

1. Rename the programtemplate.vxlisp file in your package (e.g. myproject/mypackage/myprogram.vxlisp)

2. Open the .vxlisp file and rename the package header at the top:
(package mypackage/myprogram
 :doc "This is my program")

3. Now you can add a function:
(func myfunc : int
 [arg1 : int
  arg2 : int]
 (* (+ arg1 arg2) 2)
 :test (test 10 (myfunc 2 3))
 :doc "This function adds two integers and multiplies by 2. It includes documentation and a test case.")

## Compile the code

1. Open a commnd prompt.

2. Change directories to the vxruntime folder.

3. Run the vxlisp executable passing the path and any commands you want to run. The runcomile.bat and rundoc.bat files in the sample folder are examples.
(e.g. "vxlisp_win64.exe srcjs testjs srcjava testjava doc --path ..myproject/vxlisp" will compile source and test code for Javascript and Java and make documentation.)

## Examine your code

1. If you generated documentation, it will be in your project/doc folder. (e.g. myproject/doc)

2. If you generated Javascript, it will be in your project/js folder. (e.g. myproject/js)

3. If you generated Java, it will be in your project/java folder. (e.g. myproject/java)

## View Documentation or Javascript test suite

1. Run the built in Webserver by running the vxlisp executable passing the path and the webserver command. The runwebserver.bat in the sample folder is an example.
(e.g. "vxlisp_win64.exe webserver --path ..myproject/vxlisp")

2. Open http://localhost:8081/html

3. Choose Documentation if you want to see the docs including your project.

4. Choose Test Suite if you want to see the full Javascript test suite including as your project.

5. When you are done, return to the running command prompt and press ctl-c to terminate the webserver.

## Run the Java test suite

* Test - If you want to run test suite:

1. At the command prompt run: ./runtest OR .gradlew test

* Run - If you want run a program set up by vxlisp:

1. Change your application in build.gradle file to:
application {
    // Define the main class for the application.
    mainClass = 'com.vxlisp.vx.App'
}

2. At the command prompt run: ./runapp or .gradlew run
