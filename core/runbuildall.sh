#!/bin/bash
currentfolder=$PWD
cd ../golang
go run . doc srccpp testcpp srccsharp testcsharp srcjava testjava srcjs testjs :path $PWD/vxlisp
cd $PWD
