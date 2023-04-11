#!/bin/bash
currentfolder=$PWD
cd ../golang
go run . webserver --path $PWD/vxlisp
cd $PWD
