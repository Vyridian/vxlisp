#!/bin/bash
currentfolder=$PWD
cd ../golang
go run . srcjava testjava --path $PWD/vxlisp
cd $PWD
