#!/bin/bash
currentfolder=$PWD
cd ../golang
go run . srcjs testjs :path $PWD/vxlisp
cd $PWD
