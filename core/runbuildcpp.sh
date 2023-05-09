#!/bin/bash
currentfolder=$PWD
cd ../golang
go run . doc srccpp testcpp --path $PWD/vxlisp
cd $PWD
