#!/bin/bash
currentfolder=$PWD
cd ../golang
go run . doc srcjs testjs srcjava testjava --path $PWD/vxlisp
cd $PWD
