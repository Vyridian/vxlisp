cls
set currentfolder=%cd%
cd ../golang
go run . doc srcjs testjs srcjava testjava --path %currentfolder%/vxlisp
cd %currentfolder%
