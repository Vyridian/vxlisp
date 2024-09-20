# vxcompiler

## Purpose

* The golang folder contains the source code for the vxlisp compiler.

## Command line

### Compile a vxlisp project - Choose a folder and commands:

1. go run . %commands% --path %projectfolder%/vxlisp

%projectfolder% - The path of the folder to compile. e.g. ../core/vxlisp
%commands% - One or more of the commands defined in the project.vxlisp file.

#### Default commands

* doc - Creates html documentation
* webserver - Launches a development webserver to server docs and test html.
* srcjs - Generates javascript source
* testjs - Generates javascript test
* srcjava - Generates java source
* testjava - Generates java test suite
* srccpp - Generates C++ source
* testcpp - Generates C++ test
* srccsharp - Generates CSharp source
* testsharp - Generates CSharp test
* srckotlin - Generates Kotlin source
* testkotlin - Generates Kotlin test

## Unit Test - Run one of the following

1. ./runtest
2. go test -v ./...

## Build Distribution Executables - Run the following

1. ./rundist
