cls
set currentfolder=%cd%
cd ../golang
go run . srcjs testjs srcjava testjava --path %currentfolder%/vxlisp
cd %currentfolder%
