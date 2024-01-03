#!/bin/bash
currentfolder=$PWD
cd ../golang
go run . doc srcjs testjs srcjava testjava srccpp testcpp --path $PWD/vxlisp
cd $PWD
