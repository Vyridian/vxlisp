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
* srcjs - Compiles javascript source
* testjs - Compiles javascript test
* srcjava - Compiles java source
* testjava - Compiles java test suite

## Unit Test - Run one of the following

1. ./runtest
2. go test -v ./...

## Build Distribution Executables - Run the following

1. ./rundist
