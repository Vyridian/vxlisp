cls
set currentfolder=%cd%
cd ../golang
go run . doc srcjava testjava --path %currentfolder%/vxlisp
cd %currentfolder%
