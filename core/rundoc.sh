#!/bin/bash
currentfolder=$PWD
cd ../golang
go run . doc :path $PWD/vxlisp
cd $PWD
